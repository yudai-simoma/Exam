/*
 * 1文字をint(10進数)で受け取り8ビットの文字列(2進数)へ格納する関数
 * ビット演算で2進数へ変換
 * 変換方法
 * 	1は2進数で、00000001
 * 	1を基準に、桁を一つずつずらし、AND演算で0,1を格納している
 */
static void	ft_conversion_bit_2(int a_num, char a_bit_str[9])
{
	int	i;
	int	j;
	int	r_base_1;

	i = 0;
	j = 7;
	while (j >= 0)
	{
		r_base_1 = 1 << i;
		r_base_1 = a_num & r_base_1;
		a_bit_str[j] = (r_base_1 >> i) + '0';
		i++;
		j--;
	}
}
