#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <cstdlib>
#include <sstream>

using namespace std;

vector<char> TILES = {'f', 'g', 'G', 'h', 'm', 'r'};
int NUM_TRIALS = 5;
string EXECUTABLE = "./src/dijkstras";

char get_random_tile(mt19937& rng) {
    uniform_int_distribution<int> dist(0, TILES.size() - 1);
    return TILES[dist(rng)];
}

void generate_map(int N, const string& filename) {
    ofstream out(filename);
    out << N << " " << N << "\n";
    mt19937 rng(random_device{}());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            out << get_random_tile(rng);
            if (j < N - 1) out << " ";
        }
        out << "\n";
    }
    out << "0 0\n" << (N - 1) << " " << (N - 1) << "\n";
    out.close();
}

int main() {
    vector<int> sizes;
    sizes.push_back(10);
    sizes.push_back(20);
    sizes.push_back(50);
    sizes.push_back(100);
    sizes.push_back(200);
    sizes.push_back(500);
    sizes.push_back(1000);

    cout << "| N    | Elapsed Time (s) | Memory Used (MB) |" << endl;
    cout << "|------|------------------|------------------|" << endl;

    for (int sizeIndex = 0; sizeIndex < sizes.size(); ++sizeIndex) {
        int N = sizes[sizeIndex];
        double total_time = 0.0;
        int total_memory = 0;

        for (int trial = 0; trial < NUM_TRIALS; ++trial) {
            string input_file = "input_temp.txt";
            generate_map(N, input_file);

            chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

            string cmd = "/usr/bin/time -v " + EXECUTABLE + " < " + input_file + " > output_temp.txt 2> mem_temp.txt";
            int result = system(cmd.c_str());

            chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> elapsed = chrono::duration_cast<chrono::duration<double, milli>>(end - start);
            total_time += elapsed.count();

            // Parse memory usage
            ifstream memfile("mem_temp.txt");
            string line;
            int mem = -1;

            while (getline(memfile, line)) {
                if (line.find("Maximum resident set size") != string::npos) {
                    istringstream iss(line);
                    string word;
                    while (iss >> word) {
                        if (isdigit(word[0])) {
                            mem = stoi(word);
                            break;
                        }
                    }
                    break;
                }
            }
            memfile.close();

            if (mem != -1) {
                total_memory += mem;
            }
        }

        double avg_time_sec = (total_time / NUM_TRIALS) / 1000.0; 
        double avg_mem_mb = total_memory / (double)NUM_TRIALS / 1024.0; 

        cout << "| " << N << "   | " << avg_time_sec << "           | " << avg_mem_mb << "            |" << endl;
    }

    return 0;
}
