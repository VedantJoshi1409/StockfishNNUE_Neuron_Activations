#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <cstdint>

namespace Stockfish {
    namespace Visualization {
        void init(const char*, const char*);

        int getNeurons(const char *fen);

        struct Buffer {
            std::int32_t fc_0[32];
            std::uint8_t ac_sqr_0[32];
            std::uint8_t ac_0[32];
            std::int32_t fc_1[32];
            std::uint8_t ac_1[32];
            std::int32_t fc_2[32];
            int smallNet;
            int bucket;
        };

        inline Buffer buffer;
    }
}

#endif //VISUALIZATION_H
