#include <stdint.h>

void *copy_elements(void *ele_src[], int ele_cnt, size_t ele_size)
{
    uint64_t required_size = ele_cnt * (uint64_t)ele_size;
    size_t request_size = (size_t)required_size;

    if (required_size != request_size)
        return NULL;

    void *result = malloc(request_size);

    if (result == NULL)
        return NULL;
}