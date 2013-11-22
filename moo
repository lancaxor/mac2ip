#define FUN_EXIT 100500
if(strcmp(*(argv+1),"moo")==0){
	printf("B этой программе нет пасхальных яиц.\n	");
	return FUN_EXIT;}
else if(strcmp(*(argv+1),"mooo")==0){
	printf("В этой программе точно нет пасхальных яиц. Честное слово.\n	");
	return FUN_EXIT;}
else if(strcmp(*(argv+1),"moooo")==0){
	printf("Да говорю же вам, что нету!\n	");
	return FUN_EXIT;}
else if(strcmp(*(argv+1),"mooooo")==0){
	printf("Прекратите.\n	");
	return FUN_EXIT;}
else if(strcmp(*(argv+1),"moooooo")==0){
	printf("Я попрошу вас остановиться, и не делать так больше.\n	");
	return FUN_EXIT;}
else if(strcmp(*(argv+1),"mooooooo")==0){
	printf("Ну хорошо, если я покажу вам пасхальное яйцо, вы отстанете?\n	");
	return FUN_EXIT;}
else if(strcmp(*(argv+1),"moooooooo")==0){
	printf("\n               /^,_\n ,___,--~~~~--' /'~\n `~--~\ )___,)/'\n     (/\\_  (/\\_            \nДиску Ц: пришел писеЦ.\n");
	return FUN_EXIT;}
#undef FUN_EXIT