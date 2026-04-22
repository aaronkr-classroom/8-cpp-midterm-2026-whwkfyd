#include <iostream>
#include <vector>
#include <string>

using namespace std;

double calculateAverage(vector<int> grades) {
	double total = 0;
	for (int i = 0; i < grades.size(); i++) {
		total = total + grades[i];
	}
	return total / grades.size();
}

int main()
{
	int number;
	cout << "Enter number of students: ";
	cin >> number;
	cin.ignore();
	vector<string> names(number);
	vector<double> averages(number);
	vector<int> grades(3);

	for (int i = 0; i < number; i++) {
		cout << "Enter name: ";
		cin >> names[i];
		cout << "Enter 3 scores: ";
		for (int j = 0; j < 3; j++) {
			cin >> grades[j];
		}
		cin.ignore();
		averages[i] = calculateAverage(grades);
		for (int i = 0; i < number; i++) {
			
		}
		
	}
	cout << names[i] << ": " << averages[i] << endl;
	return 0;
}


/*
int number;
string name;
vector<int> grades(3);
double calculateAverage;
cout << "Enter number of students: ";
cin >> number;

for (int i = 0; i <= number; i++) {
	cout << "Enter name: ";
	getline(cin, name);
	std::cin.ignore();
	cout << "Enter 3 scores: ";
	getline(cin, grades);

	작성하신 코드에서 몇 가지 주요한 논리적 오류와 문법적 실수를 수정해 보았습니다.
주요 수정 사항:
getline(cin, grades): getline은 문자열(string)에만 사용할 수 있습니다. vector<int>는 반복문을 사용해 하나씩 입력받아야 합니다.
std::cin.ignore() 위치: cin >> number 이후에 남은 엔터(\n)를 지우기 위해 반복문 직전에 한 번만 쓰거나, getline 직전에 적절히 배치해야 합니다. 현재 위치에서는 이름 첫 글자를 씹을 수 있습니다.
반복문 범위: i <= number는 number + 1번 실행됩니다. 보통 i < number를 사용합니다.
getline과 name: cin >> 뒤에 getline을 쓸 때는 입력 버퍼 비우기가 필수입니다
*/


/*
오버로드가 된 함수가 없대 getline에서
getline에서 에러가 나는 이유는 std::getline의 두 번째 인자로 vector<int>를 넣었기 때문입니다.
getline은 "한 줄의 문자열"을 읽어오는 함수라 std::string 변수만 받을 수 있습니다. 숫자가 들어있는 vector를 채우려면 cin >>를 사용하거나 반복문을 돌려야 합니다.
*/
/*
작성하신 코드에서 발생한 주요 문제는 변수 이름의 중복(이름 충돌)과 데이터 저장 방식입니다. calculateAverage라는 이름을 함수명, 변수명, 벡터명으로 동시에 사용하고 있어 컴파일러가 혼란을 겪고 있습니다.
문제를 해결하고 코드가 의도대로 작동하도록 수정해 보았습니다.
주요 수정 포인트:
이름 중복 해결: 함수 이름은 calculateAverage로 유지하고, 저장용 벡터는 averages로 이름을 바꿨습니다.
데이터 저장: 입력받은 점수들(grades)을 함수에 넣어 평균을 구한 뒤, 그 결과를 averages[i]에 저장해야 합니다.
출력 위치: 학생별 정보 출력은 모든 입력을 마친 후 반복문 밖에서 하거나, 입력 직후에 해당 학생의 정보만 출력해야 합니다.
*/
/*
왜 수정했나요?
vector<string> calculateAverage(number);: 위에서 선언한 double calculateAverage 변수나 함수와 이름이 겹쳐서 에러가 납니다. 저장소는 averages 같은 명확한 이름이 좋습니다.
cin >> name[i]: 이 방식은 이름에 공백(예: 홍 길동)이 있으면 공백 전까지만 읽습니다. getline(cin, names[i])를 쓰면 이름 전체를 안전하게 읽을 수 있습니다.
중첩 반복문: 입력 받는 루프 안에 출력 루프가 들어있으면, 한 명 입력할 때마다 현재까지 저장된 모든 학생 리스트가 출력되어 화면이 복잡해집니다.
이제 코드가 의도한 대로 잘 실행되나요? 학생별 점수 합계도 함께 출력하고 싶으신가요?
AI 대답에는 오류가 있을 수 있습니다. 자세히 알아보기




수정하지말고
네, 작성하신 코드 구조를 최대한 유지하면서 작동하지 않는 논리적 원인만 짚어드릴게요. 그대로 실행하시려면 아래 두 부분을 확인해 보세요.
1. 변수 이름 중복 (가장 큰 원인)
코드 윗부분에 함수 이름도 calculateAverage인데, main 안에서 변수 이름도 calculateAverage, 벡터 이름도 calculateAverage입니다. 컴파일러는 이 이름이 함수인지, 숫자인지, 목록(vector)인지 구분하지 못해 에러를 냅니다.
출력하실 때 calculateAverage가 무엇을 가리키는지 명확하지 않게 됩니다.
2. 출력 반복문의 위치
현재 코드에서는 첫 번째 학생 이름을 입력받자마자 for문을 한 번 더 돌려서 모든 학생을 출력하려고 합니다.
문제: i가 0일 때 names[0]은 들어있지만, names[1] 등 나머지는 아직 비어있는 상태에서 출력을 시도하게 됩니다.
결과: 입력하는 중간에 비어있는 리스트들이 계속 화면에 출력됩니다.
3. name[i]와 calculateAverage의 관계
현재 코드에서 calculateAverage는 벡터로 선언되어 있습니다. 따라서 출력할 때 단순히 calculateAverage라고만 쓰면 안 되고, 이름처럼 calculateAverage[i]와 같이 몇 번째 학생의 평균인지 번호를 붙여주어야 합니다.
요약하자면:
지금 코드를 그대로 쓰시더라도 이름이 겹치는 변수들의 명칭을 각각 다르게 바꾸고, 출력할 때 [i] 번호만 정확히 붙여주면 출력이 가능해집니다.
지금 상태에서 변수 이름만 살짝 바꿔서 다시 시도해 보시겠어요? 혹은 에러 메시지가 구체적으로 어떻게 뜨나요?
AI 대답에는 오류가 있을 수 있습니다. 자세히 알아보기




그래도 안돼ㅔ
작성하신 코드가 실행되지 않는 핵심적인 이유는 '함수'와 '변수'의 이름이 똑같기 때문입니다. 컴퓨터는 똑같은 이름이 있으면 이게 계산을 하라는 함수인지, 값을 저장하는 변수인지 구분하지 못합니다.
지금 코드에서 변수 이름 딱 두 개만 바꾸면 의도하신 대로 돌아갑니다.
딱 2군데만 고쳐보세요:
double calculateAverage; 삭제: 위에서 만든 함수 이름과 겹칩니다. 아예 지워버리세요.
vector<double> results(number);: 평균값을 담을 벡터 이름을 함수와 다르게 만드세요. (예: results)
왜 안 됐던 건가요?
이름 충돌: calculateAverage라는 이름으로 함수도 만들고, 변수도 만들고, 벡터도 만드셔서 컴퓨터가 "어떤 걸 써야 할지 모르겠다"며 파업(에러)을 한 것입니다.
출력 위치: for문 안에 또 for문을 넣어서 출력을 하면, 한 명 입력할 때마다 전체 명단을 뽑으려고 해서 결과가 이상하게 나왔던 것입니다.
이렇게 이름을 바꿔서 실행해 보시겠어요? 혹시 아직도 빨간 줄이 뜨는 곳이 있나요?
*/
