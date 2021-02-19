// https://www.hackerrank.com/challenges/structuring-the-document

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
  char *data;
};

void free_word(struct word *w) {
  free(w->data);
}

struct sentence {
  struct word *data;
  int word_count; // denotes number of words in a sentence
};

void free_sentence(struct sentence *s) {
  for (int i = 0; i < s->word_count; ++i) {
    free_word(&s->data[i]);
  }
  free(s->data);
}

struct paragraph {
  struct sentence *data;
  int sentence_count; // denotes number of sentences in a paragraph
};

void free_paragraph(struct paragraph *p) {
  for (int i = 0; i < p->sentence_count; ++i) {
    free_sentence(&p->data[i]);
  }
  free(p->data);
}

struct document {
  struct paragraph *data;
  int paragraph_count; // denotes number of paragraphs in a document
};

void free_document(struct document *d) {
  for (int i = 0; i < d->paragraph_count; ++i) {
    free_paragraph(&d->data[i]);
  }
  free(d->data);
}

struct document get_document(char *text) {
  struct document doc;
  // count the number of paragraphs
  // the last paragraph does not end with a new line
  doc.paragraph_count = 1;
  for (int i = 0; text[i] != '\0'; ++i) {
    if (text[i] == '\n') {
      doc.paragraph_count++;
    }
  }
  doc.data = malloc(doc.paragraph_count * sizeof(struct paragraph));
  for (int par = 0; par < doc.paragraph_count; ++par) {
    doc.data[par].sentence_count = 0;
  }

  // count the number of sentences per paragraph
  // all sentences end with a period, so we don't need to initialize to 1
  for (int i = 0, par = 0; text[i] != '\0'; ++i) {
    if (text[i] == '\n') {
      par++;
    } else if (text[i] == '.') {
      doc.data[par].sentence_count++;
    } else {
      continue;
    }
  }
  for (int par = 0; par < doc.paragraph_count; ++par) {
    doc.data[par].data = malloc(doc.data[par].sentence_count * sizeof(struct sentence));
    for (int sent = 0; sent < doc.data[par].sentence_count; ++sent) {
      doc.data[par].data[sent].word_count = 1;
    }
  }

  // count the number of words per sentence per paragraph
  for (int i = 0, par = 0, sent = 0; text[i] != '\0'; ++i) {
    if (text[i] == '\n') {
      par++;
      sent = 0;
    } else if (text[i] == '.') {
      sent++;
    } else if (text[i] == ' ') {
      doc.data[par].data[sent].word_count++;
    } else {
      continue;
    }
  }

  // create the document
  char *s = strtok(text, " .\n");
  for (int par = 0; par < doc.paragraph_count; ++par) {
    for (int sent = 0; sent < doc.data[par].sentence_count; ++sent) {
      doc.data[par].data[sent].data = (struct word *) malloc(doc.data[par].data[sent].word_count * sizeof(struct word));
      for (int wi = 0; wi < doc.data[par].data[sent].word_count; ++wi) {
        size_t len = strlen(s);
        doc.data[par].data[sent].data[wi].data = (char *) malloc((len + 1) * sizeof(char));
        strcpy(doc.data[par].data[sent].data[wi].data, s);
        s = strtok(NULL, " .\n");
      }
    }
  }

  return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
  return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
  return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
  return Doc.data[k-1];
}

void print_word(struct word w) {
  printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
  for (int i = 0; i < sen.word_count; i++) {
    print_word(sen.data[i]);
    if (i != sen.word_count - 1) {
      printf(" ");
    }
  }
}

void print_paragraph(struct paragraph para) {
  for (int i = 0; i < para.sentence_count; i++) {
    print_sentence(para.data[i]);
    printf(".");
  }
}

void print_document(struct document doc) {
  for (int i = 0; i < doc.paragraph_count; i++) {
    print_paragraph(doc.data[i]);
    if (i != doc.paragraph_count - 1)
      printf("\n");
  }
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

int main() {
  char *text = get_input_text();
  struct document Doc = get_document(text);
  free(text);

  int q;
  scanf("%d", &q);

  while (q--) {
    int type;
    scanf("%d", &type);

    if (type == 3) {
      int k, m, n;
      scanf("%d %d %d", &k, &m, &n);
      struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
      print_word(w);
    } else if (type == 2) {
      int k, m;
      scanf("%d %d", &k, &m);
      struct sentence sen = kth_sentence_in_mth_paragraph(Doc, k, m);
      print_sentence(sen);
    } else {
      int k;
      scanf("%d", &k);
      struct paragraph para = kth_paragraph(Doc, k);
      print_paragraph(para);
    }
    printf("\n");
  }

  free_document(&Doc);

  return 0;
}
