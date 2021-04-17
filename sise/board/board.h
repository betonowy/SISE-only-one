//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_BOARD_H
#define SISE_BOARD_H

#include <vector>
#include <cstdint>
#include <siseException.h>


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

        // getting values and indexes

        inline uint8_t &get(const std::pair<uint8_t, uint8_t> &coords) { return get(coords.first, coords.second); }

        uint8_t &get(size_t x, size_t y);

        [[nodiscard]] std::pair<uint8_t, uint8_t> flatToDim(uint8_t index) const;

        std::pair<uint8_t, uint8_t> getIndexOf(uint8_t cellValue);

        inline std::pair<size_t, size_t> size() { return {boardSizeX, boardSizeY}; }

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

        bool isSolved();

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
