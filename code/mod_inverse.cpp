//computes b such that ab = 1(mod n), returns - 1 on failure
int mod_inverse(int a, int n)
{
  int x, y;
  int g = extended_euclid(a, n, x, y);
  if (g > 1) return -1;
  return (x+n)%n;
}
