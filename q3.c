#include <stdio.h>
#include <stdlib.h>

int manager_id = (('['-'Z') << ('='-'8')) + ((':'-'9') << ('q'-112));
int check_user(int user_id, int key) {
  char username[1024];
  int special_key[1];
  special_key[0] = ((('k'-'5') << ('L'-74)) + (('`'-'9') << ('q'-112)));
  
  printf("&manager_id = %p\n",&manager_id);

  printf("Enter your username:\n");
  fgets(username,sizeof(username),stdin);
  
  printf("Hello ");
  printf(username);     // * here <---------------------------------------------

  return user_id == manager_id && key==special_key[0];
}

int main(int argc, char** argv) {
  if (argc != 3) {
    printf("Usage: %s <Your ID> <Your KEY>\n",argv[0]);
    return 1;
  }
  // * Convert string to integer
  int id = atoi(argv[1]);
  int key = atoi(argv[2]);

  if (check_user(id, key)) {
    puts("Access granted");
    // Modify salaries , ...
  } else{
    puts("Access denied");
    // Can't change salaries
  }

  return 0;
}
