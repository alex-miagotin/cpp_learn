
struct alignas(4) Ammo
{
  bool taken;
  bool empty;
  bool forHuman;
  char padding1[1];
  int bullets;
};
static_assert(sizeof(Ammo) == 8, "Ammo size is not 8 bytes.");
static_assert(alignof(Ammo) == 4, "Ammo size is not 8 bytes.");

// #pragma optimize("", off)

inline int max(int a, int b)
{
  return a > b ? a : b;
}

int main(int argc, char** argv)
{
  int result = max(11, 23);
  int result2 = max(11, 23);
  int result3 = max(11, 23);

  return result + result2 + result3;
}