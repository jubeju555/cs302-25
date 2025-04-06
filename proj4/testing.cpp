// used stack, and google for timing and stuff,
// also originally wanted to try it in python but figured c++ would be cool to try 
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
    ofstream writeto(filename);
    mt19937 rng(random_device{}());

    
    writeto << TILES.size() << "\n";

    // random cost to tiles
    for (char tile : TILES) {
        uniform_int_distribution<int> cost_dist(1, 9);
        int cost = cost_dist(rng);
        writeto << tile << " " << cost << "\n";
    }

    //  map dimensions
    writeto << N << " " << N << "\n";

    // print map
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            writeto << get_random_tile(rng);
            if (j < N - 1) writeto << " ";
        }
        writeto << "\n";
    }

    // start and end
    writeto << "0 0\n" << (N - 1) << " " << (N - 1) << "\n";
    writeto.close();
}

int main() {
    vector<int> sizes = {10, 20, 50, 100, 200, 500, 1000};

    cout << "| N    | Elapsed Time (s) |" << endl;
    cout << "|------|------------------|" << endl;

    for (int N : sizes) {
        double total_time = 0.0;

        for (int i = 0; i < NUM_TRIALS; ++i) {
            string input_file = "input_temp.txt";
            generate_map(N, input_file);

            chrono::time_point<chrono::high_resolution_clock> start = chrono::high_resolution_clock::now();


            string cmd = EXECUTABLE + " < " + input_file + " > output_temp.txt";
            int result = system(cmd.c_str());

            chrono::time_point<chrono::high_resolution_clock> end = chrono::high_resolution_clock::now();

            // time in seconds 
            chrono::duration<double> elapsed = end - start; 

            total_time += elapsed.count();
        }

        double avg_time = total_time / NUM_TRIALS;
        cout << "| " << N << "   | " << avg_time << "        |" << endl;
    }

    return 0;
}
