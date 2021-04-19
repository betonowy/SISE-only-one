//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_BOARD_H
#define SISE_BOARD_H

#include <vector>
#include <cstdint>
#include <siseException.h>
#include <siseExtension.h>

namespace sise {

    enum moveDirection {
        MOVE_UP,
        MOVE_RIGHT,
        MOVE_DOWN,
        MOVE_LEFT
    };

    class board {
    public:
        board(size_t sizeX, size_t sizeY, bool autoSolve);

        explicit board(const std::string &path);

        bool operator==(const board &other) const;

        static inline bool FastComp16(const board &a, const board &b) {
            auto dataA = (const int128 *) a.flatMatrix.data();
            auto dataB = (const int128 *) b.flatMatrix.data();
            return dataA[0] == dataB[0];
        }

        [[nodiscard]] inline size_t FastHash16() const {
            auto dataA = (const uint64_t *) &flatMatrix[0];
            auto dataB = (const uint64_t *) &flatMatrix[8];
            return *dataA ^ *dataB;
        }

        [[nodiscard]] inline bool FastComparable() const { return flatMatrix.size() == 16; };

        // getting values and indexes

        [[nodiscard]] inline const uint8_t &get(const std::pair<uint8_t, uint8_t> &coords) const {
            return get(coords.first, coords.second);
        }

        inline uint8_t &get(const std::pair<uint8_t, uint8_t> &coords) {
            return get(coords.first, coords.second);
        }

        [[nodiscard]] const uint8_t &get(size_t x, size_t y) const;

        uint8_t &get(size_t x, size_t y);

        [[nodiscard]] std::pair<uint8_t, uint8_t> flatToDim(uint8_t index) const;

        std::pair<uint8_t, uint8_t> getIndexOf(uint8_t cellValue);

        [[nodiscard]] inline std::pair<size_t, size_t> size() const { return {boardSizeX, boardSizeY}; }

        inline size_t maxNumber() { return flatMatrix.size() - 1; }

        // synchronising between two representations

        void sync();

        // moving (playing)

        bool canMove(moveDirection dir);

        void move(moveDirection dir);

        // serialize to string

        const std::string &toString();

        std::string movesToString();

        // dirty flag

        inline void makeDirty() { dirty = dirtyString = true; }

        // save to file

        [[nodiscard]] inline size_t getMoves() const { return moves; }

        [[nodiscard]] bool isSolved() const;

        // move converter

        static char moveToChar(moveDirection move);

        static moveDirection charToMove(char character);

        void printBoard();

        static void printPossibilities(const std::vector<moveDirection> &directions);

    private:

        void fillAsSolved();

        void init();

        void countMove(moveDirection move);

        size_t moves = 0;
        std::vector<moveDirection> moveSequence;

        size_t boardSizeX = 0, boardSizeY = 0;

        std::vector<uint8_t> flatMatrix;
        std::vector<std::pair<uint8_t, uint8_t>> indices;
        bool dirty = true;

        std::string serialized;
        bool dirtyString = true;
    };

}

#endif //SISE_BOARD_H
