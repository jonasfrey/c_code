int f_b_nth_bit_is_set(int n_num, int n_nth_bit){

   return (n_num & 1<<(n_nth_bit-1));

}
void print_as_binary(unsigned n)
{
    unsigned i;
    printf("\n");
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}
