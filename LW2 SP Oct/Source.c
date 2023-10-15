#include <stdio.h>
#include <locale.h>

int isAccepted(char* w0, char* w1) {
	int currentState = 0;

	wprintf(L"Початок перевірки:\n");

	for (int i = 0; w1[i] != '\0'; ++i) {
		switch (currentState) {
		case 0:
			if (w1[i] == 'a') {
				currentState = 1;
				wprintf(L"Перехід зі стану 0 в стан 1 (a)\n");
			}
			else {
				wprintf(L"Немає переходу зі стану 0 за символом %c\n", w1[i]);
				return 0;
			}
			break;
		case 1:
			if (w1[i] == 'a') {
				currentState = 2;
				wprintf(L"Перехід зі стану 1 в стан 2 (a)\n");
			}
			else if (w1[i] == 'b') {
				currentState = 3;
				wprintf(L"Перехід зі стану 1 в стан 3 (b)\n");
			}
			else {
				wprintf(L"Немає переходу зі стану 1 за символом %c\n", w1[i]);
				return 0;
			}
			break;
		case 2:
			if (w1[i] == 'b') {
				currentState = 1;
				wprintf(L"Перехід зі стану 2 в стан 1 (b)\n");
			}
			else {
				wprintf(L"Немає переходу зі стану 2 за символом %c\n", w1[i]);
				return 0;
			}
			break;
		case 3:
			if (w1[i] == 'a') {
				currentState = 1;
				wprintf(L"Перехід зі стану 3 в стан 1 (a)\n");
			}
			else {
				wprintf(L"Немає переходу зі стану 3 за символом %c\n", w1[i]);
				return 0;
			}
			break;
		}
	}

	if (currentState == 2 && w0[0] == '2' && w0[1] == '4' && w0[2] == '\0') {
		wprintf(L"Слово w1w0 допускається\n");
		return 1;
	}

	wprintf(L"Слово w1w0 не допускається\n");

	return 0;
}

int main() {
	// Встановлення локалі для підтримки кирилиці
	setlocale(LC_ALL, "");

	char w0[] = "24";
	char w1[] = "ababaa";

	isAccepted(w0, w1);

	return 0;
}
