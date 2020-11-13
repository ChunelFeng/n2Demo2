// Copyright 2017 Kakao Corp. <http://www.kakaocorp.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "include/n2/hnsw.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include <time.h>

using namespace std;

int search_by_id() {
    n2::Hnsw index2;
    index2.LoadModel("72000test.n2");
    int search_id = 1, k = 5;
    vector<pair<int, float>> result;
    clock_t start, end;
    start = clock();

    cout << "start" << endl;
    int num = 1000;
    for (int i = 0; i < num; i++) {
        index2.SearchById(search_id, k, -1, result);
    }

    end = clock();
    cout << num << " times cost " << (end - start) / 100 << "ms" << endl;

    cout << "[SearchById]: K-NN for " << search_id << " ";
    for(auto ret : result){
        cout << "(" << ret.first << "," << ret.second << ") ";
    }
    cout << endl;

    return 0;
}

int main(int argc, char** argv)
{
    const int data_size = 72900;    // 数据个数
    const int F = 768;    // 维度
//    random_device rd;
//    mt19937 mt(rd());
    //normal_distribution<double> dist(0.0, 1.0);

    //n2::Hnsw index(F, "L2");
//    for(int i=0; i < data_size; ++i){
//        vector<float> v(F);
//        generate(v.begin(), v.end(), [&mt, &dist] { return dist(mt); });
//        index.AddData(v);
//    }
    //vector<pair<string, string>>
            //configs = {{"M", "64"}, {"MaxM0", "100000"}, {"NumThread", "4"}};
    //index.SetConfigs(configs);
    //index.Fit();
    //index.SaveModel("72000test.n2");

    search_by_id();

//    vector<float> v(F);
//    generate(v.begin(), v.end(), [&mt, &dist] { return dist(mt); });
//    index2.SearchByVector(v, k, -1, result);
//    cout << "[SearchByVector]: K-NN for [";
//    for(auto e : v){
//        cout << e << ",";
//    }
//    cout << "] ";
//    for(auto ret : result){
//        cout << "(" << ret.first << "," << ret.second << ") ";
//    }
//    cout << endl;

    return 0;
}
