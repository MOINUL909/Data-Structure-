
#include<stdio.h>
#include<string.h>
struct books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};
int main()
{
    struct books book1;
    struct books book2;
    //book 1 specition
    strcpy(book1.title, "C programming.");
    strcpy(book1.author, "MOINUL islam");
    strcpy(book1.subject, "C programming tutorial");
    book1.book_id=445511;
    //book 2 specition
    strcpy(book2.title, "C++ programming.");
    strcpy(book2.author, "MOINUL islam(MI)");
    strcpy(book2.subject, "C++ programming tutorial");
    book2.book_id=88779955;
    //printing book1 info.
    printf("BOOK 1 Tittle:%s\n",book1.title);
    printf("BOOK 1 Author:%s\n",book1.author);
    printf("BOOK 1 Subject:%s\n",book1.subject);
    printf("BOOK 1 book_id:%d\n",book1.book_id);
     //printing book2 info.
    printf("BOOK 2 Tittle:%s\n",book2.title);
    printf("BOOK 2 Author:%s\n",book2.author);
    printf("BOOK 2 Subject:%s\n",book2.subject);
    printf("BOOK 2 book_id:%d\n",book2.book_id);



}
