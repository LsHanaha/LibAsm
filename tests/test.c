
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>


size_t  ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strcpy(char *dest, char *src);
ssize_t ft_write(int __fd, const void *__buf, size_t __n);
ssize_t ft_read(int __fd, void *__buf, size_t __count);
char    *ft_strdup(const char *s);

int main(void) {

    printf("\nstrlen:\n");
    printf("string 'qwerty'\t\t%s\n", strlen("qwerty") == ft_strlen("qwerty") ? "equal" : "DIFF!");
    printf("string empty\t\t%s\n", strlen("") == ft_strlen("") ? "equal" : "DIFF!");
    printf("string numbers\t\t%s\n\n", strlen("1234567892") == ft_strlen("1234567892") ? "equal" : "DIFF!");


    printf("#############################################################################################\n");
    printf("strcpy:\n");

    char *first = (char *)malloc(100);
    char *second = (char *)malloc(100);

    printf("res string 'qwerty'\t%s\n", strcmp(strcpy(first, "qwerty"), ft_strcpy(second, "qwerty")) ? "DIFF!" : "equal");
    printf("res string empty\t%s\n", strcmp(strcpy(first, ""), ft_strcpy(second, "")) ? "DIFF!" : "equal");
    printf("res string long\t\t%s\n", strcmp(strcpy(first, "oifhrspiughewihfisdbvjbwqiugfiewubfiuewbfioewnvoinewopffwiehnfuiwebfuiewbfuibewifnewoiufh"),
                              ft_strcpy(second, "oifhrspiughewihfisdbvjbwqiugfiewubfiuewbfioewnvoinewopffwiehnfuiwebfuiewbfuibewifnewoiufh")) ? "DIFF!" : "equal");



    printf("#############################################################################################\n");
    printf("\nstrcmp:\n");
    printf("original =\t%d:%d\t= custom\n", strcmp("", ""), ft_strcmp("", ""));
    printf("original =\t%d:%d\t= custom\n", strcmp("qwerty", "qwerty"), ft_strcmp("qwerty", "qwerty"));
    printf("original =\t%d:%d\t= custom\n", strcmp("1234567892", "1234567892"), ft_strcmp("1234567892", "1234567892"));

    printf("original =\t%d:%d\t= custom\n", strcmp("1234567890", "1234567891"), ft_strcmp("1234567890", "1234567891"));
    printf("original =\t%d:%d\t= custom\n", strcmp("12", "1234567891"), ft_strcmp("12", "1234567891"));
    printf("original =\t%d:%d\t= custom\n", strcmp("1234567892", "1234567891"), ft_strcmp("1234567892", "1234567891"));
    printf("original =\t%d:%d\t= custom\n", strcmp("1234567892", "12"), ft_strcmp("1234567892", "12"));
    printf("original =\t%d:%d\t= custom\n", strcmp("1234567892", "1224567892"), ft_strcmp("1234567892", "1224567892"));
    printf("original =\t%d:%d\t= custom\n", strcmp("1234567892", "3"), ft_strcmp("1234567892", "3"));


    printf("#############################################################################################\n");
    printf("\nft_write:\n");

    int len_custom, len_default;
    printf("print to std:\n");
    len_custom = ft_write(1, "stdout ", 7);
    len_default = write(1, "stdout\n", 7);
    printf("simple\toriginal =\t%d:%d\t= custom\n\n", len_default, len_custom);

    len_custom = ft_write(1, "stdoutstdout ", 7);
    len_default = write(1, "stdoutstdout\n", 7);
    printf("\nshort\toriginal =\t%d:%d\t= custom\n\n", len_default, len_custom);

    len_custom = ft_write(1, "stdout ", 0);
    len_default = write(1, "stdout\n", 0);
    printf("zero\toriginal =\t%d:%d\t= custom\n\n", len_default, len_custom);

    len_custom = ft_write(1, "", 10);
    len_default = write(1, "", 10);
    printf("\nempty\toriginal =\t%d:%d\t= custom\n\n", len_default, len_custom);

    char string1[10] = {0};
    char string2[10] = {0};
    memmove(string1, "test ", 5);
    memmove(string2, "test\n", 5);
    len_custom = ft_write(1, string1, 10);
    len_default = write(1, string2, 10);
    printf("init\toriginal =\t%d:%d\t= custom\n\n", len_default, len_custom);

    len_custom = ft_write(2, "error ", 6);
    len_default = write(2, "error\n", 6);
    printf("stderr\toriginal =\t%d:%d\t= custom\n\n", len_default, len_custom);


    int file = open("tests/test.txt", O_RDWR);

    printf("file:\n");
    len_custom = ft_write(file, "FILE ", 5);
    len_default = write(file, "FILE\n", 5);
    printf("file\toriginal =\t%d:%d\t= custom\n\n", len_default, len_custom);


    printf("Errors:\n");

    len_custom = ft_write(1, "qwerty\n", -6);
    printf("custom %s, %d\n", strerror(errno), errno);
    len_default = write(1, "qwerty\n", -6);
    printf("default %s, %d\n", strerror(errno), errno);
    printf("count < 0\toriginal =\t%d:%d\t= custom\n\n", len_default, len_custom);

    len_custom = ft_write(1, NULL, 6);
    printf("custom %s, %d\n", strerror(errno), errno);
    len_default = write(1, NULL, 6);
    printf("default %s, %d\n", strerror(errno), errno);
    printf("NULL str\toriginal =\t%d:%d\t= custom\n\n", len_default, len_custom);

    len_custom = ft_write(-1, "qwerty\n", 6);
    printf("custom %s, %d\n", strerror(errno), errno);
    len_default = write(-1, "qwerty\n", 6);
    printf("default %s, %d\n", strerror(errno), errno);
    printf("wrong fd\toriginal =\t%d:%d\t= custom\n\n", len_default, len_custom);
    close(file);

    file = open("tests/test.txt", O_RDONLY);
    len_custom = ft_write(file, "qwerty\n", 6);
    printf("custom %s, %d\n", strerror(errno), errno);
    len_default = write(file, "qwerty\n", 6);
    printf("default %s, %d\n", strerror(errno), errno);
    printf("read only\toriginal =\t%d:%d\t= custom\n\n", len_default, len_custom);
    close(file);


    printf("#############################################################################################\n");
    printf("ft_read:\n");

    char *str1 = (char *)malloc(20);
    char *str2 = (char *)malloc(20);
    memset(str1, '\0', sizeof str1);
    memset(str2, '\0', sizeof str2);

    printf("read from std:\n");
    len_default = read(0, str2, 5);
    printf("next:\n");
    len_custom = ft_read(0, str1, 5);
    printf("custom = '%s'\t%d = %d\t'%s' = default\n", str1, len_custom, len_default, str2);


    printf("read from file:\n");

    memset(str1, '\0', sizeof str1);
    memset(str2, '\0', sizeof str2);
    file = open("tests/test.txt", O_RDONLY);
    len_default = read(file, str2, 5);
    printf("next:\n");
    lseek(file, 0, SEEK_SET);
    len_custom = ft_read(file, str1, 5);
    printf("custom = '%s'\t%d = %d\t'%s' = default\n", str1, len_custom, len_default, str2);
    close(file);

    printf("ERRORS:\n");
    memset(str1, '\0', sizeof str1);
    memset(str2, '\0', sizeof str2);
    len_custom = ft_read(-1, str1, 5);
    printf("custom %s, %d\n", strerror(errno), errno);
    len_default = read(-1, str2, 5);
    printf("default %s, %d\n", strerror(errno), errno);
    printf("custom = '%s'\t%d = %d\t'%s' = default\n", str1, len_custom, len_default, str2);


    len_custom = ft_read(0, NULL, 5);
    printf("custom %s, %d\n", strerror(errno), errno);
    len_default = read(0, NULL, 5);
    printf("default %s, %d\n", strerror(errno), errno);
    printf("custom = '%s'\t%d = %d\t'%s' = default\n", str1, len_custom, len_default, str2);

    len_custom = ft_read(0, str1, 0);
    printf("custom %s, %d\n", strerror(errno), errno);
    len_default = read(0, str2, 0);
    printf("default %s, %d\n", strerror(errno), errno);
    printf("custom = '%s'\t%d = %d\t'%s' = default\n", str1, len_custom, len_default, str2);


    printf("#############################################################################################\n");
    printf("ft_strdup:\n");
    printf("custom\t'%s' = '%s'\tdefault\n", ft_strdup("qwerty"), strdup("qwerty"));
    printf("custom\t'%s' = '%s'\tdefault\n", ft_strdup(""), strdup(""));
    printf("custom\t'%s' = '%s'\tdefault\n", ft_strdup(" 123 "), strdup(" 123 "));
    free(ft_strdup("qwe"));

    return (0);
}
