#include "visualization.h"
#include "bitboard.h"
#include "position.h"
#include "evaluate.h"
#include "nnue/nnue_architecture.h"

namespace Stockfish {

    namespace Visualization {

        void init( const char *bigNetFile, const char *smallNetFile) {
            Bitboards::init();

            std::unordered_map<Eval::NNUE::NetSize, Eval::EvalFile> evalFiles = {
                {Eval::NNUE::Big,   {"EvalFile",      bigNetFile,   "None", ""}},
                {Eval::NNUE::Small, {"EvalFileSmall", smallNetFile, "None", ""}}
            };

            evalFiles = Eval::NNUE::load_networks("", evalFiles);

            for (auto &[netSize, evalFile]: evalFiles) {
                std::cout << "Option: " << evalFile.optionName << std::endl; // Print other members similarly
                std::cout << "Name: " << evalFile.defaultName << std::endl;
                std::cout << std::endl;
            }
        }

        int getNeurons(const char *fen) {
            Position pos;
            StateListPtr states(new std::deque<StateInfo>(1));

            pos.set(fen, &states->back());
            return Eval::evaluate(pos);
        }
    }
}