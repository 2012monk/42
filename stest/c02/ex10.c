#include <stdio.h>
#include <string.h>
unsigned int ft_strlcpy(char *dst, char *src, unsigned int size);
int main(int argc, char const *argv[])
{
	char msg[] = "1234567890123456789";
	char comp[100] = "original";
	char orig[100] = "original";

	printf("%lu %s origin\n", strlcpy(orig, msg, 10), orig);

	printf("%u %s compare\n", ft_strlcpy(comp, msg, 10), comp);
	
	char text1[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char text1_[100];
	char text1_r[100];
	printf("%d %s\n", ft_strlcpy(text1_, text1, 100), text1_);
	printf("%lu %s\n", strlcpy(text1_r, text1, 100), text1_r);

	printf("\n");

    char text2[] = "a wOR23d 3is a STRin3G of ++aLphanuEeric .cHarac3ters.";
	char text2_[100];
	char text2_r[100];
	printf("%d %s\n", ft_strlcpy(text2_, text2, 11), text2_);
	printf("%lu %s\n", strlcpy(text2_r, text2, 11), text2_r);

	char test3[] = "15VHlyBEjGSLzdqKOrpRxO^?";
	char res3[100];
	char res3_comp[100];
	printf("%d %s\n", ft_strlcpy(res3, test3, 25), res3);
	printf("%lu %s\n", strlcpy(res3_comp, test3, 25), res3_comp);
    
	
	char test4[] = "yvPLRwLHHQa <=> 11 <=> 9lHOUKtQfaaktEYS <=> 15VHlyBEjGSLzdqKOrpRxO^? <=> 20dejqkO <=> 9gKepsmaemFXZsnqB <=> 16DPyPvAOpS <=> 9WNQOEaUg <=> 8aRMHmKuzYOkTAUxX <=> 19Z <=> 1 <=> 12VtmrfTGMJHpwkISpPawK <=> 20xPTJSGDJcA <=> 10OgzOZTxPSyvXucmi <=> 19ZZrMywMU <=> 12mgPFsyBAXDqcPk <=> 19 <=> 4Np <=> 2iNg <=> 3mpmUbyiRooBPjbg <=> 15 <=> 7PwsXAsh <=> 7pnvr <=> 20NamsbcblBkdG <=> 12Ak <=> 2suMZkhJmZ <=> 16cgQlolrocwWioMhGyEwK <=> 18PY <=> 11KiHR <=> 4YTtDREJRlbqdqWEg <=> 16CmmmG <=> 5cYNNhxp <=> 7nj <=> 2ZEvzOsNtmWOOivD <=> 15Sc <=> 2KaaqhrPvT <=> 17nIwbuIKiSlte <=> 12QrywSloJPNdKJ <=> 19LrgPKZRgZ <=> 9SfFywZRgZ <=> 5ggpUABNoac <=> 10VDdzVEe <=> 7cgRlNLQxy <=> 9LlLlxOx <=> 7nTHKmqLL <=> 8cfUcgrjFzQM <=> 11IZHmPAGeMaZW <=> 17HpnbqJMmcxVvDHV <=> 15nHRX <=> 4Lllx <=> 4JpkUs <=> 8OnOVse <=> 6UJqVnKpufOdPe <=> 13YkKMu <=> 5zUXjIbhx <=> 8LligqDcpqrSCTJRpIij <=> 19MGinnVIdKknp <=> 12RGbxShJ <=> 7nKMwVNCgHZE <=> 11wpjRuBYwNyeeOmEr <=> 20PGuzMwjVkUonTyO <=> 15i <=> 1DVzBRKJr <=> 8AU <=> 2vOZjeQiTcZonTyO  <=> 10NDcqAXxLrNTQvjnuWlGF <=> 20oNEGV <=> 5QczbRgOzWneKqVKjXR <=> 18kmNZnTmWpaV <=> 11YeDecStK <=> 8 <=> 10sZ <=> 2AUxdPybB <=> 19liQWLMEZwqy <=> 11QBcmNPHvUVX <=> 11ESDpeHZcnUSp <=> 12cdVI <=> 4ifaN <=> 6RG <=> 18LvozZA <=> 18BCgIIRS <=> 7csgQgyaN <=> 8JtwrJiXXbbfhNK <=> 14 <=> 19geQxIDewSHbsLJiPO <=> 17lumvskFXiIQHq <=> 13htXdnWOdHYXsGFz <=> 15LBuyhW <=> 6mWHoSYpXa <=> 9GmUrcXPGf <=> 9kj <=> 2dNcWO <=> 9VuQrMqTodjcakSsXX <=> 17iPUjTNfe <=> 19jsJ <=> 3aWwblNFukg <=> 10 <=> 17y <=> 1ZEouZaMmYtGvmWqxY <=> 17012345678 <=> 10abcdefgh <=> 10;[]'/.,_-)GvmWqxY <=> 10;[]'/.,_-)GvmWqxY <=> 0 <=> 10";
	char res4[2000];
	char res4_comp[2000];

	printf("%d \n%s\n", ft_strlcpy(res4, test4, sizeof(test4)), res4);
	printf("%lu \n%s\n", strlcpy(res4_comp, test4, sizeof(test4)), res4_comp);
	
	
	return 0;


}
