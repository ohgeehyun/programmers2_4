// 프로그래머스 행렬의 곱셈
/*
    arr1.size()만큼 (m)
    arr1[n].size()(n)에 arr2[n].size() (k) 만큼 하면 된다.
    O(m*n*k) 시간 소요
    
    결국 재귀를 안하고 3중for문으로 해도되긴한데 작성자는 for가 3개이상이면 읽히지가 않아 차라리 재귀로 하였다.. 간단한 재귀로 for를  하나 빼는게 더 보기 좋은거같아서..
*/


#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> answer;

void resolve(int index,vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    if (index < 0) return;

    vector<int> vec;

    resolve(index - 1, arr1, arr2);

    //이 과정 한번에 arr1[]의 요소 하나의 계산이 끝. arr1[][]의 size와 arr2[]의 사이즈는 같다. 
    for (int i = 0; i < arr2[0].size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < arr2.size(); j++)
        {
            sum += arr1[index][j] * arr2[j][i];
        }
        vec.push_back(sum);
    }
    
    answer.push_back(vec);
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int length = arr1.size();

    resolve(length-1, arr1, arr2);

    return answer;
}


int main()
{
    vector<vector<int>> arr1 = { {1, 2, 3}, {4, 5, 6} };
    vector<vector<int>> arr2 = { {7, 8}, {9, 10}, {11, 12} };

    vector<vector<int>> result = solution(arr1, arr2);

    // 결과 출력
    for (auto row : result) {
        for (auto elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    system("pause");
}

