#define MAX_BUFFER 1024
struct buffer_type
{
    unsigned char *head;
    unsigned char *tail;
    unsigned char *buffer;
};
void init_buffer(struct buffer_type *b, unsigned char *buffer);
void empty_buffer(struct buffer_type *b);
unsigned int get_buffer_status(struct buffer_type b, int *err);
int add_char_to_buffer(struct buffer_type *b, unsigned char c, int *err);
unsigned char get_char_from_buffer(struct buffer_type *b, int *err);
int print_buffer(struct buffer_type *b, int *err);
int add_string_to_buffer(struct buffer_type *b, unsigned char *s, int *err);
int  get_string_from_buffer(struct buffer_type *b, unsigned char *dest, int len, int *err);