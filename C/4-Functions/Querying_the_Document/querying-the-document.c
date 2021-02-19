// https://www.hackerrank.com/challenges/querying-the-document/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char *kth_word_in_mth_sentence_of_nth_paragraph(char ****document, int k, int m, int n) {
  return document[n-1][m-1][k-1];
}

char **kth_sentence_in_mth_paragraph(char ****document, int k, int m) {
  return document[m-1][k-1];
}

char ***kth_paragraph(char ****document, int k) {
  return document[k-1];
}

char ****get_document(char *text) {
  // count the number of paragraphs
  // the last paragraph does not end with a new line
  int num_paragraphs = 1;
  for (int i = 0; text[i] != '\0'; ++i) {
    if (text[i] == '\n') {
      ++num_paragraphs;
    }
  }

  // count the number of sentences per paragraph
  // all sentences end with a period, so we don't need to initialize to 1
  int *num_sentences = (int *) calloc(num_paragraphs, sizeof(int));
  {
    int par = 0;
    for (int i = 0; text[i] != '\0'; ++i) {
      if (text[i] == '\n') {
        ++par;
      } else if (text[i] == '.') {
        ++num_sentences[par];
      } else {
        continue;
      }
    }
  }

  int **num_words = (int **) malloc(num_paragraphs * sizeof(int *));
  for (int par = 0; par < num_paragraphs; ++par) {
    num_words[par] = (int *) malloc(num_sentences[par] * sizeof(int));
    for (int sent = 0; sent < num_sentences[par]; ++sent) {
      num_words[par][sent] = 1;
    }
  }
  // count the number of words per sentence per paragraph
  {
    int par = 0;
    int sent = 0;
    for (int i = 0; text[i] != '\0'; ++i) {
      if (text[i] == '\n') {
        ++par;
        sent = 0;
      } else if (text[i] == '.') {
        ++sent;
      } else if (text[i] == ' ') {
        ++num_words[par][sent];
      } else {
        continue;
      }
    }
  }

  // create the document
  char *s = strtok(text, " .\n");
  char ****document = (char ****) malloc(num_paragraphs * sizeof(char ***));
  for (int par = 0; par < num_paragraphs; ++par) {
    document[par] = (char ***) malloc(num_sentences[par] * sizeof(char **));
    for (int sent = 0; sent < num_sentences[par]; ++sent) {
      document[par][sent] = (char **) malloc(num_words[par][sent] * sizeof(char *));
      for (int word = 0; word < num_words[par][sent]; ++word) {
        size_t len = strlen(s);
        document[par][sent][word] = (char *) malloc((len + 1) * sizeof(char));
        strcpy(document[par][sent][word], s);
        s = strtok(NULL, " .\n");
      }
    }
  }

  // free allocated memory
  for (int par = 0; par < num_paragraphs; ++par) {
    free(num_words[par]);
  }
  free(num_words);
  free(num_sentences);

  return document;
}

char *get_input_text() {
  int paragraph_count;
  scanf("%d", &paragraph_count);

  char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
  memset(doc, 0, sizeof(doc));
  getchar();
  for (int i = 0; i < paragraph_count; i++) {
    scanf("%[^\n]%*c", p[i]);
    strcat(doc, p[i]);
    if (i != paragraph_count - 1)
      strcat(doc, "\n");
  }

  char *returnDoc = (char *)malloc((strlen(doc) + 1) * (sizeof(char)));
  strcpy(returnDoc, doc);
  return returnDoc;
}

void print_word(char *word) {
  printf("%s", word);
}

void print_sentence(char **sentence) {
  int word_count;
  scanf("%d", &word_count);
  for (int i = 0; i < word_count; i++) {
    printf("%s", sentence[i]);
    if (i != word_count - 1)
      printf(" ");
  }
}

void print_paragraph(char ***paragraph) {
  int sentence_count;
  scanf("%d", &sentence_count);
  for (int i = 0; i < sentence_count; i++) {
    print_sentence(*(paragraph + i));
    printf(".");
  }
}

int main() {
  char *text = get_input_text();
  char ****document = get_document(text);

  int q;
  scanf("%d", &q);

  while (q--) {
    int type;
    scanf("%d", &type);

    if (type == 3) {
      int k, m, n;
      scanf("%d %d %d", &k, &m, &n);
      char *word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
      print_word(word);
    }

    else if (type == 2) {
      int k, m;
      scanf("%d %d", &k, &m);
      char **sentence = kth_sentence_in_mth_paragraph(document, k, m);
      print_sentence(sentence);
    }

    else {
      int k;
      scanf("%d", &k);
      char ***paragraph = kth_paragraph(document, k);
      print_paragraph(paragraph);
    }
    printf("\n");
  }
}
