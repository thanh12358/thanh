#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    char strNotification[1024] = "You've just entered:\n";

    // Nhập các giá trị từ người dùng
    printf("Please input a: ");
    scanf("%lf", &a);
    sprintf(strNotification + strlen(strNotification), "a = %.2lf\n", a);

    printf("Please input b: ");
    scanf("%lf", &b);
    sprintf(strNotification + strlen(strNotification), "b = %.2lf\n", b);

    printf("Please input c: ");
    scanf("%lf", &c);
    sprintf(strNotification + strlen(strNotification), "c = %.2lf\n", c);

    // Tính toán nghiệm của phương trình bậc hai
    char result[256] = "";
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                sprintf(result, "The equation has infinitely many solutions.");
            } else {
                sprintf(result, "The equation has no solutions.");
            }
        } else {
            double x = -c / b;
            sprintf(result, "The equation has a unique solution: x = %.2lf", x);
        }
    } else {
        double D = b * b - 4 * a * c;
        if (D > 0) {
            double x1 = (-b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D)) / (2 * a);
            sprintf(result, "The equation has two different solutions: x1 = %.2lf, x2 = %.2lf", x1, x2);
        } else if (D == 0) {
            double x = -b / (2 * a);
            sprintf(result, "The equation has a double root: x1 = x2 = %.2lf", x);
        } else {
            sprintf(result, "The equation has no solutions.");
        }
    }
    printf("Your equation: \n");
    printf("%lfx^2 + %lfx + %lf = 0\n");
    // In ra kết quả
    printf("%s\n%s\n", strNotification, result);

    return 0;
}