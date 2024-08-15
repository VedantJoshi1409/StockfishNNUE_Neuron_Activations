/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2024 The Stockfish developers (see AUTHORS file)

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>

#include "visualization.h"

using namespace Stockfish::Visualization;

int main() {
    init("nn-b1a57edbea57.nnue", "nn-baff1ede1f90.nnue");

    // getNeurons("pnbpkbnp/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    getNeurons("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");


    std::cout << "fc_0: ";
    for (int i = 0; i < 32; ++i) {
        std::cout << buffer.fc_0[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "ac_sqr_0: ";
    for (int i = 0; i < 32; ++i) {
        std::cout << static_cast<int>(buffer.ac_sqr_0[i]) << " ";
    }
    std::cout << std::endl;

    std::cout << "ac_0: ";
    for (int i = 0; i < 32; ++i) {
        std::cout << static_cast<int>(buffer.ac_0[i]) << " ";
    }
    std::cout << std::endl;

    std::cout << "fc_1: ";
    for (int i = 0; i < 32; ++i) {
        std::cout << buffer.fc_1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "ac_1: ";
    for (int i = 0; i < 32; ++i) {
        std::cout << static_cast<int>(buffer.ac_1[i]) << " ";
    }
    std::cout << std::endl;

    std::cout << "fc_2: ";
    for (int i = 0; i < 32; ++i) {
        std::cout << buffer.fc_2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "smallNet: " << buffer.smallNet << std::endl;
    std::cout << "bucket: " << buffer.bucket << std::endl;

    /*std::cout<<"\n"<<std::endl;

    std::cout<<Probe::eval("pnbpkbnp/1pppppp1/8/8/8/8/1PPPPPP1/RNBQKBNR w KQkq - 0 1")<<std::endl;
    std::cout<<Probe::eval("rnbqkbnr/1pppppp1/8/8/8/8/1PPPPPP1/RNBQKBNR w KQkq - 0 1")<<std::endl;
    std::cout<<"\n"<<std::endl;

    std::cout<<Probe::eval("pnbpkbnp/2pppp2/8/8/8/8/2PPPP2/RNBQKBNR w KQkq - 0 1")<<std::endl;
    std::cout<<Probe::eval("rnbqkbnr/2pppp2/8/8/8/8/2PPPP2/RNBQKBNR w KQkq - 0 1")<<std::endl;
    std::cout<<"\n"<<std::endl;

    std::cout<<Probe::eval("pnbpkbnp/3pp3/8/8/8/8/3PP3/RNBQKBNR w KQkq - 0 1")<<std::endl;
    std::cout<<Probe::eval("rnbqkbnr/3pp3/8/8/8/8/3PP3/RNBQKBNR w KQkq - 0 1")<<std::endl;
    std::cout<<"\n"<<std::endl;

    std::cout<<Probe::eval("pnbpkbnp/8/8/8/8/8/8/RNBQKBNR w KQkq - 0 1")<<std::endl;
    std::cout<<Probe::eval("rnbqkbnr/8/8/8/8/8/8/RNBQKBNR w KQkq - 0 1")<<std::endl;
    std::cout<<"\n"<<std::endl;

    std::cout<<Probe::eval("1nbpkbn1/8/8/8/8/8/8/1NBQKBN1 w KQkq - 0 1")<<std::endl;
    std::cout<<Probe::eval("1nbqkbn1/8/8/8/8/8/8/1NBQKBN1 w KQkq - 0 1")<<std::endl;
    std::cout<<"\n"<<std::endl;

    std::cout<<Probe::eval("2bpkb2/8/8/8/8/8/8/2BQKB2 w KQkq - 0 1")<<std::endl;
    std::cout<<Probe::eval("2bqkb2/8/8/8/8/8/8/2BQKB2 w KQkq - 0 1")<<std::endl;
    std::cout<<"\n"<<std::endl;

    std::cout<<Probe::eval("3pk3/8/8/8/8/8/8/3QK3 w KQkq - 0 1")<<std::endl;
    std::cout<<Probe::eval("3qk3/8/8/8/8/8/8/3QK3 w KQkq - 0 1")<<std::endl;*/

    std::cin.get();
    return 0;
}
