int main() {
  // char a[] = { 'a', 'b', 'c',  '\0' }; here is mutable
  char *a = "abc"; // Stored in ROM, implicit const char *
  char *p = a;
  char c = (*p)++; // Modify ROM will segfault
}
