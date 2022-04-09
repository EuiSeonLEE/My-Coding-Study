#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer, buffer;
    for(int a = 0; a < commands.size(); a++){
        for(int b = commands[a][0] - 1; b < commands[a][1]; b++){
            answer.push_back(array[b]);
            sort(answer.begin(), answer.end());
        }
        buffer.push_back(answer[commands[a][2] - 1]);
        answer.clear();
        answer.shrink_to_fit();
    }
    return buffer;
}