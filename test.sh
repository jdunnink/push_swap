#======COLORS======#

EOC="\033[0m";
GREEN="\033[32m";
YELLOW="\033[33m"
HIGH="\033[1m";

#===PRELIMINARIES==#

make fclean

echo "${HIGH}\n\nAUTHOR:${EOC}"
cat -e author

sleep 2s

echo "${HIGH}\n\nNORMINETTE:${EOC}"
norminette . *.c *.h

sleep 2s

make

#======CHECKER=====#

echo "${HIGH}\n\nCHECKER TESTS${EOC}"

echo "${GREEN}\nError Management\n${EOC}"

echo "${YELLOW}VAL='1 2147483649' \tCMD=''\t\t('Error' expected):${EOC}"
VAL="1 2147483649";
CMD="";
echo $CMD | ./checker $VAL

echo "${YELLOW}VAL='1 -2147483649' \tCMD=''\t\t('Error' expected):${EOC}"
VAL="1 -2147483649";
CMD="";
echo $CMD | ./checker $VAL

echo "${YELLOW}VAL='1 two 3' \t\tCMD='sa pb'\t('Error' expected):${EOC}"
VAL="1 two 3";
CMD="sa\npb";
echo $CMD | ./checker $VAL

echo "${YELLOW}VAL='1 1 3' \t\tCMD='sa pb'\t('Error' expected):${EOC}"
VAL="1 1 3";
CMD="sa\npb";
echo $CMD | ./checker $VAL

echo "${YELLOW}VAL='1 2 3' \t\tCMD='   sa   pb   pa'\t('Error' expected):${EOC}"
VAL="1 2 3";
CMD="sa \n pb \n pa";
echo $CMD | ./checker $VAL

echo "${GREEN}\nFalse Tests\n${EOC}"

echo "${YELLOW}VAL='-10 0 -8' \t\tCMD='sa pa'\t('KO' expected):${EOC}"
VAL="-10 0 -8";
CMD="sa\npa";
echo $CMD | ./checker $VAL

echo "${YELLOW}VAL='1 0' \t\tCMD=''\t\t('KO' expected):${EOC}"
VAL="1 0";
CMD="";
echo $CMD | ./checker $VAL

echo "${GREEN}\nRight Tests\n${EOC}"

echo "${YELLOW}VAL='' \t\t\tCMD=''\t\t('' expected):\n${EOC}"
VAL="";
CMD="";
echo $CMD | ./checker $VAL

echo "${YELLOW}VAL='0' \t\tCMD=''\t\t('OK' expected):${EOC}"
VAL="0";
CMD="";
echo $CMD | ./checker $VAL

echo "${YELLOW}VAL='1' \t\tCMD=''\t\t('OK' expected):${EOC}"
VAL="1";
CMD="";
echo $CMD | ./checker $VAL

echo "${YELLOW}VAL='0 1 2' \t\tCMD=''\t\t('OK' expected):${EOC}"
VAL="0 1 2";
CMD="";
echo $CMD | ./checker $VAL

echo "${YELLOW}VAL='1 0' \t\tCMD='sa'\t('OK' expected):${EOC}"
VAL="1 0";
CMD="sa";
echo $CMD | ./checker $VAL

echo "${YELLOW}VAL='0 9 1 8 2' \tCMD='pb ra pb ra sa ra pa pa'\t('OK' expected):${EOC}"
VAL="0 9 1 8 2";
CMD="pb\nra\npb\nra\nsa\nra\npa\npa";
echo $CMD | ./checker $VAL

#======PUSH_SWAP======#

echo "${HIGH}\n\nPUSH_SWAP TESTS${EOC}"

echo "${GREEN}\nBasic Test\n${EOC}"

echo "${YELLOW}VAL='' \t\t\t('' expected):\n${EOC}"
VAL="";
echo $VAL | ./push_swap $VAL

echo "${YELLOW}VAL='0 1 2 3' \t\t('' expected):\n${EOC}"
VAL="0 1 2 3";
echo $VAL | ./push_swap $VAL

echo "${YELLOW}VAL='0 1 2 3 4 5 6 7 8 9' ('' expected):\n${EOC}"
VAL="0 1 2 3 4 5 6 7 8 9";
echo $VAL | ./push_swap $VAL

echo "${GREEN}\nSimple Test - 3 Numbers (3 or less instructions expected)\n${EOC}"

echo "${YELLOW}VAL='1 2 3' \t\t:${EOC}"
VAL="1 2 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 1 3' \t\t:${EOC}"
VAL="2 1 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 1 2' \t\t:${EOC}"
VAL="3 1 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 3 2' \t\t:${EOC}"
VAL="1 3 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 3 1' \t\t:${EOC}"
VAL="2 3 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 2 1' \t\t:${EOC}"
VAL="3 2 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${GREEN}\nSimple Test - 5 Numbers (12 or less instructions expected)\n${EOC}"

echo "${YELLOW}VAL='1 2 3 4 5' \t:${EOC}"
VAL="1 2 3 4 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 1 3 4 5' \t:${EOC}"
VAL="2 1 3 4 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 1 2 4 5' \t:${EOC}"
VAL="3 1 2 4 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 3 2 4 5' \t:${EOC}"
VAL="1 3 2 4 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 3 1 4 5' \t:${EOC}"
VAL="2 3 1 4 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 2 1 4 5' \t:${EOC}"
VAL="3 2 1 4 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 2 4 1 5' \t:${EOC}"
VAL="3 2 4 1 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 3 4 1 5' \t:${EOC}"
VAL="2 3 4 1 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 3 2 1 5' \t:${EOC}"
VAL="4 3 2 1 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 4 2 1 5' \t:${EOC}"
VAL="3 4 2 1 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 4 3 1 5' \t:${EOC}"
VAL="2 4 3 1 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 2 3 1 5' \t:${EOC}"
VAL="4 2 3 1 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 1 3 2 5' \t:${EOC}"
VAL="4 1 3 2 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 4 3 2 5' \t:${EOC}"
VAL="1 4 3 2 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 4 1 2 5' \t:${EOC}"
VAL="3 4 1 2 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 3 1 2 5' \t:${EOC}"
VAL="4 3 1 2 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 3 4 2 5' \t:${EOC}"
VAL="1 3 4 2 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 1 4 2 5' \t:${EOC}"
VAL="3 1 4 2 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 1 4 3 5' \t:${EOC}"
VAL="2 1 4 3 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 2 4 3 5' \t:${EOC}"
VAL="1 2 4 3 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 2 1 3 5' \t:${EOC}"
VAL="4 2 1 3 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 4 1 3 5' \t:${EOC}"
VAL="2 4 1 3 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 4 2 3 5' \t:${EOC}"
VAL="1 4 2 3 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 1 2 3 5' \t:${EOC}"
VAL="4 1 2 3 5";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 1 2 3 4' \t:${EOC}"
VAL="5 1 2 3 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 5 2 3 4' \t:${EOC}"
VAL="1 5 2 3 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 5 1 3 4' \t:${EOC}"
VAL="2 5 1 3 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 2 1 3 4' \t:${EOC}"
VAL="5 2 1 3 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 2 5 3 4' \t:${EOC}"
VAL="1 2 5 3 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 1 5 3 4' \t:${EOC}"
VAL="2 1 5 3 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 1 3 5 4' \t:${EOC}"
VAL="2 1 3 5 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 2 3 5 4' \t:${EOC}"
VAL="1 2 3 5 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 2 1 5 4' \t:${EOC}"
VAL="3 2 1 5 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 3 1 5 4' \t:${EOC}"
VAL="2 3 1 5 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 3 2 5 4' \t:${EOC}"
VAL="1 3 2 5 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 1 2 5 4' \t:${EOC}"
VAL="3 1 2 5 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 5 2 1 4' \t:${EOC}"
VAL="3 5 2 1 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 3 2 1 4' \t:${EOC}"
VAL="5 3 2 1 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 3 5 1 4' \t:${EOC}"
VAL="2 3 5 1 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 2 5 1 4' \t:${EOC}"
VAL="3 2 5 1 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 2 3 1 4' \t:${EOC}"
VAL="5 2 3 1 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 5 3 1 4' \t:${EOC}"
VAL="2 5 3 1 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 5 3 2 4' \t:${EOC}"
VAL="1 5 3 2 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 1 3 2 4' \t:${EOC}"
VAL="5 1 3 2 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 1 5 2 4' \t:${EOC}"
VAL="3 1 5 2 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 3 5 2 4' \t:${EOC}"
VAL="1 3 5 2 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 3 1 2 4' \t:${EOC}"
VAL="5 3 1 2 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 5 1 2 4' \t:${EOC}"
VAL="3 5 1 2 4";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 5 1 2 3' \t:${EOC}"
VAL="4 5 1 2 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 4 1 2 3' \t:${EOC}"
VAL="5 4 1 2 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 4 5 2 3' \t:${EOC}"
VAL="1 4 5 2 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 1 5 2 3' \t:${EOC}"
VAL="4 1 5 2 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 1 4 2 3' \t:${EOC}"
VAL="5 1 4 2 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 5 4 2 3' \t:${EOC}"
VAL="1 5 4 2 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 5 2 4 3' \t:${EOC}"
VAL="1 5 2 4 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 1 2 4 3' \t:${EOC}"
VAL="5 1 2 4 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 1 5 4 3' \t:${EOC}"
VAL="2 1 5 4 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 2 5 4 3' \t:${EOC}"
VAL="1 2 5 4 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 2 1 4 3' \t:${EOC}"
VAL="5 2 1 4 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 5 1 4 3' \t:${EOC}"
VAL="2 5 1 4 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 4 1 5 3' \t:${EOC}"
VAL="2 4 1 5 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 2 1 5 3' \t:${EOC}"
VAL="4 2 1 5 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 2 4 5 3' \t:${EOC}"
VAL="1 2 4 5 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 1 4 5 3' \t:${EOC}"
VAL="2 1 4 5 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 1 2 5 3' \t:${EOC}"
VAL="4 1 2 5 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 4 2 5 3' \t:${EOC}"
VAL="1 4 2 5 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 4 2 1 3' \t:${EOC}"
VAL="5 4 2 1 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 5 2 1 3' \t:${EOC}"
VAL="4 5 2 1 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 5 4 1 3' \t:${EOC}"
VAL="2 5 4 1 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 2 4 1 3' \t:${EOC}"
VAL="5 2 4 1 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 2 5 1 3' \t:${EOC}"
VAL="4 2 5 1 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 4 5 1 3' \t:${EOC}"
VAL="2 4 5 1 3";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 4 5 1 2' \t:${EOC}"
VAL="3 4 5 1 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 3 5 1 2' \t:${EOC}"
VAL="4 3 5 1 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 3 4 1 2' \t:${EOC}"
VAL="5 3 4 1 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 5 4 1 2' \t:${EOC}"
VAL="3 5 4 1 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 5 3 1 2' \t:${EOC}"
VAL="4 5 3 1 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 4 3 1 2' \t:${EOC}"
VAL="5 4 3 1 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 4 1 3 2' \t:${EOC}"
VAL="5 4 1 3 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 5 1 3 2' \t:${EOC}"
VAL="4 5 1 3 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 5 4 3 2' \t:${EOC}"
VAL="1 5 4 3 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 1 4 3 2' \t:${EOC}"
VAL="5 1 4 3 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 1 5 3 2' \t:${EOC}"
VAL="4 1 5 3 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 4 5 3 2' \t:${EOC}"
VAL="1 4 5 3 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 3 5 4 2' \t:${EOC}"
VAL="1 3 5 4 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 1 5 4 2' \t:${EOC}"
VAL="3 1 5 4 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 1 3 4 2' \t:${EOC}"
VAL="5 1 3 4 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 5 3 4 2' \t:${EOC}"
VAL="1 5 3 4 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 5 1 4 2' \t:${EOC}"
VAL="3 5 1 4 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 3 1 4 2' \t:${EOC}"
VAL="5 3 1 4 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 3 1 5 2' \t:${EOC}"
VAL="4 3 1 5 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 4 1 5 2' \t:${EOC}"
VAL="3 4 1 5 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 4 3 5 2' \t:${EOC}"
VAL="1 4 3 5 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 1 3 5 2' \t:${EOC}"
VAL="4 1 3 5 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 1 4 5 2' \t:${EOC}"
VAL="3 1 4 5 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='1 3 4 5 2' \t:${EOC}"
VAL="1 3 4 5 2";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 3 4 5 1' \t:${EOC}"
VAL="2 3 4 5 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 2 4 5 1' \t:${EOC}"
VAL="3 2 4 5 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 2 3 5 1' \t:${EOC}"
VAL="4 2 3 5 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 4 3 5 1' \t:${EOC}"
VAL="2 4 3 5 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 4 2 5 1' \t:${EOC}"
VAL="3 4 2 5 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 3 2 5 1' \t:${EOC}"
VAL="4 3 2 5 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 3 5 2 1' \t:${EOC}"
VAL="4 3 5 2 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 4 5 2 1' \t:${EOC}"
VAL="3 4 5 2 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 4 3 2 1' \t:${EOC}"
VAL="5 4 3 2 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 5 3 2 1' \t:${EOC}"
VAL="4 5 3 2 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 5 4 2 1' \t:${EOC}"
VAL="3 5 4 2 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 3 4 2 1' \t:${EOC}"
VAL="5 3 4 2 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 2 4 3 1' \t:${EOC}"
VAL="5 2 4 3 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 5 4 3 1' \t:${EOC}"
VAL="2 5 4 3 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 5 2 3 1' \t:${EOC}"
VAL="4 5 2 3 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 4 2 3 1' \t:${EOC}"
VAL="5 4 2 3 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 4 5 3 1' \t:${EOC}"
VAL="2 4 5 3 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='4 2 5 3 1' \t:${EOC}"
VAL="4 2 5 3 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 2 5 4 1' \t:${EOC}"
VAL="3 2 5 4 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 3 5 4 1' \t:${EOC}"
VAL="2 3 5 4 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='5 3 2 4 1' \t:${EOC}"
VAL="5 3 2 4 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 5 2 4 1' \t:${EOC}"
VAL="3 5 2 4 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='3 5 2 4 1' \t:${EOC}"
VAL="3 5 2 4 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL='2 5 3 4 1' \t:${EOC}"
VAL="2 5 3 4 1";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

#====MEDIUM TESTS====#

echo "${GREEN}\nMedium Test - 100 Numbers (1500 or less instructions expected)\n${EOC}"

echo "${YELLOW}VAL - random 100 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(100) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 100 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(100) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 100 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(100) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 100 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(100) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 100 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(100) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 100 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(100) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 100 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(100) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 100 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(100) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 100 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(100) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 100 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(100) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

#====ADVANCED TESTS====#

echo "${GREEN}\nAdvanced Test - 500 Numbers (11500 or less instructions expected)\n${EOC}"

echo "${YELLOW}VAL - random 500 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(500) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 500 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(500) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 500 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(500) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 500 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(500) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 500 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(500) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 500 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(500) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 500 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(500) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 500 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(500) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 500 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(500) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL

echo "${YELLOW}VAL - random 500 \t:${EOC}"
VAL="`ruby -e 'printf Array.new(500) { rand(-999999...999999) }.uniq.map { |i| i.to_s}.join(" ")'`";
echo $VAL | ./push_swap $VAL | wc -l
./push_swap $VAL | ./checker $VAL
