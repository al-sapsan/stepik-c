#include <stdint.h>
#include <inttypes.h>
#include <iostream>
#include <iomanip>
using namespace std;

typedef int8_t i8_t;
typedef uint8_t u8_t;

void *create_array(size_t n_size, i8_t rand_seed)
{

    i8_t *array_i8 = new i8_t[n_size];
    srand(rand_seed);
    for (size_t i = 0; i < n_size; i++)
    {
        array_i8[i] = rand(rand_seed) % 11 - 5;
    }
    return array_i8;
}

void print_array(const i8_t *array_i8, size_t n_size)
{
    for (size_t i = 0; i < n_size; i++)
    {
        printf("% " PRIi8, array_i8[i]);
    }
    printf("\n");
}

void delete_zero(i8_t *&array_i8, size_t &n_size)
{
    u8_t l_notzero_counter_u8;
    for (size_t i = 0; i < n_size; i++)
    {
        if (array[i] > 0)
        {
            l_notzero_counter_u8++;
        }
    }
    u8_t *notzero_array_u8 = new u8_t[l_notzero_counter_u8];
    size_t j = 0;
    for (size_t i = 0; i < n_size; i++)
    {
        if (array_i8[i] > 0)
        {
            notzero_array_u8[j] = array_i8[i];
            j++;
        }
    }
    delete[] array_i8;
    array_i8 = notzero_array_u8;
    n_size = l_notzero_counter_u8;
}

int main()
{
    size_t l_num_elem;
    i8_t l_rand_seed;

    if (scanf("%zu %" PRIi8, &l_num_elem, &l_rand_seed) != 2)
    {
        puts("Input error");
        return 0;
    }

    i8_t *array_i8 = create_array(l_num_elem, l_rand_seed);
    print_array(array_i8, l_num_elem);
    delete_zero(array_i8, l_num_elem);
    print_array(array_i8, l_num_elem);
    delete[] array_i8;
    return 0;
}