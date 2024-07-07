#include <iostream>
using namespace std;

void RecurFunction(int count)
{
    if (count == 0) return; // 종료 조건

    RecurFunction(count - 1); // 실행 위치 변경

    cout << count << endl;

    // RecurFunction(count - 1);
}

int main()
{
    RecurFunction(5);
    return 0;
}