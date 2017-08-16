int distance(const char* a, const char* b, unsigned long length_a, unsigned long length_b) {
  unsigned int d = 0;

  if (length_a != length_b) {
    return -1;
  }
  goto *((*a == '\0') ? &&result : &&loop);

loop:
  if (*a++ != *b++) {
    d++;
  }
  goto *(--length_a ? &&loop : &&result);

result:
  return d;
}
