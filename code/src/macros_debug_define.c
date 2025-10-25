/* 
Жаль, что Сергей не привёл примеров разумного использования шарпов (# и ##) в конце. 
Но имхо всё равно это интересные инструменты. Н-р, с помощью # можно преобразовывать любые 
идентификаторы в строки для того, чтобы их выводить на консоль (или в файл). 
Ну, в лом вам, например, открывать отладочные окна с переменными или у вас нет вообще отладки 
(н-р, пользуете g++ без всего), а хочется отслеживать значения переменных, в т. ч. с длинными именами, 
и работу функций (процедур). Хотите изменить имена переменных и функций - без проблем, компилятор вам 
подчеркнёт ошибки в вызовах макрофункций.
*/
#include <iostream>
#define PRINT(VAR) std::cout << #VAR " = " << VAR << std::endl

#define P_CALL(FUN, ARG) std::cout << "\"" #FUN "\" changed \"" #ARG "\" from " << ARG;	\
FUN(ARG);	\
std::cout << " to " <<	ARG;						

void function_whith_long_name(int & arg) {
	arg -= 5;
}

int main(void)
{
	int quantity = 1050;
	double ratio = 1.32;
	int * pointer = &quantity;
	const char * word = "doggy";
	// ...
	PRINT(quantity);
	PRINT(ratio);
	PRINT(pointer);
	PRINT(word);

	int varible = 10;
	P_CALL(function_whith_long_name, varible)
	return 0;
}
/* 
P. S.: cout здорово упрощает жизнь при выводе значений различных типов данных, если использовать 
только printf, то придётся создавать отдельные макрофункции PRINT_INT, PRINT_FLT, PRINT_PTR, PRINT_STR 
и т. д. из-за различных спецификаторов преобразования;
*/ 