#include "../include/lib.h"

int periodic_boundary_conditions(int i, int limit, int add)
{
  return (i + limit + add) % limit;
}