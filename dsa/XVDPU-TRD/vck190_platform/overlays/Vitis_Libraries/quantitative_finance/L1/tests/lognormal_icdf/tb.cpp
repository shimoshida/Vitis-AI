/*
 * Copyright 2019 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <math.h>
#include <iostream>
#define DT double

DT dut(DT average, DT sigma, DT x);

int main() {
    int nerr = 0;
    DT err = 1e-12;
    DT golden_icdf[2][4] = {{0.0, 1.0, 0.1, -1.281551564140156}, {1.6, 2.6, 0.51, 1.665179161543257}};
    for (int i = 0; i < 2; i++) {
        DT icdf = std::log(dut(golden_icdf[i][0], golden_icdf[i][1], golden_icdf[i][2]));
        if (std::abs(icdf - golden_icdf[i][3]) > err) {
            std::cout << "average=" << golden_icdf[i][0] << ",sigma=" << golden_icdf[i][1] << ",x=" << golden_icdf[i][2]
                      << ",icdf=" << icdf << ",err=" << std::abs(icdf - golden_icdf[i][3]) << std::endl;
            nerr++;
        }
    }
    return nerr;
}
