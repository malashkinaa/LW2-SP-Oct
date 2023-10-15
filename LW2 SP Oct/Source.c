#include <stdio.h>
#include <locale.h>

int isAccepted(char* w0, char* w1) {
	int currentState = 0;

	wprintf(L"������� ��������:\n");

	for (int i = 0; w1[i] != '\0'; ++i) {
		switch (currentState) {
		case 0:
			if (w1[i] == 'a') {
				currentState = 1;
				wprintf(L"������� � ����� 0 � ���� 1 (a)\n");
			}
			else {
				wprintf(L"���� �������� � ����� 0 �� �������� %c\n", w1[i]);
				return 0;
			}
			break;
		case 1:
			if (w1[i] == 'a') {
				currentState = 2;
				wprintf(L"������� � ����� 1 � ���� 2 (a)\n");
			}
			else if (w1[i] == 'b') {
				currentState = 3;
				wprintf(L"������� � ����� 1 � ���� 3 (b)\n");
			}
			else {
				wprintf(L"���� �������� � ����� 1 �� �������� %c\n", w1[i]);
				return 0;
			}
			break;
		case 2:
			if (w1[i] == 'b') {
				currentState = 1;
				wprintf(L"������� � ����� 2 � ���� 1 (b)\n");
			}
			else {
				wprintf(L"���� �������� � ����� 2 �� �������� %c\n", w1[i]);
				return 0;
			}
			break;
		case 3:
			if (w1[i] == 'a') {
				currentState = 1;
				wprintf(L"������� � ����� 3 � ���� 1 (a)\n");
			}
			else {
				wprintf(L"���� �������� � ����� 3 �� �������� %c\n", w1[i]);
				return 0;
			}
			break;
		}
	}

	if (currentState == 2 && w0[0] == '2' && w0[1] == '4' && w0[2] == '\0') {
		wprintf(L"����� w1w0 �����������\n");
		return 1;
	}

	wprintf(L"����� w1w0 �� �����������\n");

	return 0;
}

int main() {
	// ������������ ����� ��� �������� ��������
	setlocale(LC_ALL, "");

	char w0[] = "24";
	char w1[] = "ababaa";

	isAccepted(w0, w1);

	return 0;
}
