//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "board.h"
#include <headerConfig.h>
#include <siseException.h>
#include <util/fileIn.h>
#include <iomanip>
#include <iostream>

namespace sise {

    board::board(size_t sizeX, size_t sizeY, bool autoSolve) : boardSizeX(sizeX), boardSizeY(sizeY) {
        init();
        if (autoSolve) fillAsSolved();
    }

    board::board(const std::string &path) {
        fileIn file(path);

        boardSizeX = file.getInt();
        boardSizeY = file.getInt();

        init();

        for (auto &cell : flatMatrix) cell = file.getInt();
    }

    uint8_t &board::get(size_t x, size_t y) {
#ifdef SISE_FAILSAFE
        if (x > boardSizeX || y > boardSizeY) {
            throw sise::exception(
                    "invalid indexes: [" + std::to_string(x) + ", " + std::to_string(y) + "], board size is: [" +
                    std::to_string(boardSizeX) + ", " + std::to_string(boardSizeY) + "]");
        }
#endif

        return flatMatrix[x + y * boardSizeY];
    }

    std::pair<uint8_t, uint8_t> board::flatToDim(uint8_t index) const {
        return {index % boardSizeX, index / boardSizeX};
    }

    std::pair<uint8_t, uint8_t> board::getIndexOf(uint8_t cellValue) {
        if (dirty) {
            sync();
            dirty = false;
        }

        return indices[cellValue];
    }

    void board::sync() {
        for (size_t i = 0; i < flatMatrix.size(); i++)
            indices[flatMatrix[i]] = flatToDim(i);
    }

    const std::string &board::toString() {
        if (dirtyString) {
            serialized.clear();

            for (auto &cell : flatMatrix) {
                serialized.push_back(cell);
            }

            dirtyString = false;
        }

        return serialized;
    }

    bool board::canMove(moveDirection dir) {
        auto cellToMove = getIndexOf(0);

        switch (dir) {
            case MOVE_UP:
                if (cellToMove.second == 0) return false;
                break;
            case MOVE_RIGHT:
                if (cellToMove.first == boardSizeX - 1) return false;
                break;
            case MOVE_DOWN:
                if (cellToMove.second == boardSizeY - 1) return false;
                break;
            case MOVE_LEFT:
                if (cellToMove.first == 0) return false;
                break;
        }

        return true;
    }

    void board::fillAsSolved() {
        for (size_t i = 0; i < flatMatrix.size() - 1; i++) {
            flatMatrix[i] = i + 1;
        }

        flatMatrix.back() = 0;
    }

    void board::init() {
        size_t arraySize = boardSizeX * boardSizeY;

        if (arraySize == 0 || arraySize > sise::cfg::maxBoardSize)
            throw sise::exception("Invalid array size: " + std::to_string(arraySize));

        flatMatrix.resize(arraySize);
        indices.resize(arraySize);
    }

    void board::move(moveDirection dir) {
#ifdef SISE_FAILSAFE
        if (!canMove(dir)) throw exception("Can't move in that direction... dummy!");
#endif

        auto cellToMove = getIndexOf(0);
        auto cellToSwapWith = cellToMove;

        switch (dir) {
            case MOVE_UP:
                cellToSwapWith.second -= 1;
                break;
            case MOVE_RIGHT:
                cellToSwapWith.first += 1;
                break;
            case MOVE_DOWN:
                cellToSwapWith.second += 1;
                break;
            case MOVE_LEFT:
                cellToSwapWith.first -= 1;
                break;
        }

        std::swap(get(cellToMove), get(cellToSwapWith));
        makeDirty();
        countMove();
    }

    bool board::isSolved() {
        for (size_t i = 0; i < flatMatrix.size() - 1; i++)
            if (flatMatrix[i] != i + 1) return false;

        if (flatMatrix.back() != 0) return false;

        return true;
    }

    std::string board::movesToString() {
        std::string serializedMoves;

        for (auto &move : moveSequence)
            serializedMoves.push_back(moveToChar(move));

        return serializedMoves;
    }

    char board::moveToChar(moveDirection move) {
        switch (move) {
            case MOVE_UP:
                return 'U';
            case MOVE_RIGHT:
                return 'R';
            case MOVE_DOWN:
                return 'D';
            case MOVE_LEFT:
                return 'L';
        }
        throw exception("Bad moveDirection enum value");
    }

    moveDirection board::charToMove(char character) {
        switch (character) {
            case 'U':
                return MOVE_UP;
            case 'R':
                return MOVE_RIGHT;
            case 'D':
                return MOVE_DOWN;
            case 'L':
                return MOVE_LEFT;
            default:
                throw exception("This char cannot be converted to moveDirection enum");
        }
    }

    void board::printBoard() {
        for (size_t y = 0; y < boardSizeY; y++) {
            for (size_t x = 0; x < boardSizeX; x++) {
                std::cout << std::setw(5) << (int) get(x, y);
            }
            std::cout << std::endl;
        }
    }

    void board::printPossibilities(const std::vector<moveDirection> &directions) {
        for (auto &dir : directions) {
            std::cout << "possible: ";
            switch (dir) {
                case MOVE_UP:
                    std::cout << "up";
                    break;
                case MOVE_RIGHT:
                    std::cout << "right";
                    break;
                case MOVE_DOWN:
                    std::cout << "down";
                    break;
                case MOVE_LEFT:
                    std::cout << "left";
                    break;
            }
            std::cout << std::endl;
        }
    }

}