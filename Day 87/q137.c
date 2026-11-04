//Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.
#include <stdio.h>

enum Role {
    ADMIN,
    USER,
    GUEST
};

int main(void)
{
    enum Role roles[] = { ADMIN, USER, GUEST };
    int i;
    int n = sizeof(roles) / sizeof(roles[0]);

    for (i = 0; i < n; i++) {
        switch (roles[i]) {
            case ADMIN:
                printf("ADMIN: Full access granted. You can manage users and settings.\n");
                break;
            case USER:
                printf("USER: Limited access granted. You can view and edit your own data.\n");
                break;
            case GUEST:
                printf("GUEST: Read-only access. You can view public content only.\n");
                break;
            default:
                printf("Unknown role.\n");
                break;
        }
    }

    return 0;
}
