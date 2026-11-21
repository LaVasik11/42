#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> // change this to <stdlib.h>
#include "argo.h"

static int parse_value(json *dst, FILE *stream);
static int parse_string(json *dst, FILE *stream);
static int parse_int(json *dst, FILE *stream);
static int parse_map(json *dst, FILE *stream);

int argo(json *dst, FILE *stream)
{
 return parse_value(dst, stream);
}

static int parse_string(json *dst, FILE *stream)
{
 if (!accept(stream, '"'))
 {
  unexpected(stream);
  return -1;
 }
 dst->type = STRING;
 dst->string = malloc(1);
 if (!dst->string)
  return -1;
 size_t len = 0;
 int c;
 while ((c = getc(stream)) != EOF)
 {
  if (c == '"')
  {
   dst->string[len] = '\0';
   return 1;
  }
  if (c == '\\')
  {
   int next = getc(stream);
   if (next == EOF)
   {
    unexpected(stream);
    return -1;
   }
   if (next != '\\' && next != '"')
   {
    unexpected(stream);
    return -1;
   }
   c = next;
  }
  char *tmp = realloc(dst->string, len + 2);
  if (!tmp)
   return -1;
  dst->string = tmp;
  dst->string[len++] = c;
 }
 unexpected(stream);
 return -1;
}

static int parse_int(json *dst, FILE *stream)
{
 int c = peek(stream);
 if (!isdigit(c))
 {
  unexpected(stream);
  return -1;
 }
 int value;
 if (fscanf(stream, "%d", &value) != 1)
  return -1;
 dst->type = INTEGER;
 dst->integer = value;
 return 1;
}

static int parse_map(json *dst, FILE *stream)
{
 if (!accept(stream, '{'))
 {
  unexpected(stream);
  return -1;
 }
 dst->type = MAP;
 dst->map.data = NULL;
 dst->map.size = 0;

 if (accept(stream, '}'))
  return 1;

 while (1)
 {
  json key_json;
  if (parse_string(&key_json, stream) != 1)
   return -1;

  if (!expect(stream, ':'))
  {
   free(key_json.string);
   return -1;
  }

  json value_json;
  if (parse_value(&value_json, stream) != 1)
  {
   free(key_json.string);
   return -1;
  }

  pair *tmp = realloc(dst->map.data, sizeof(pair) * (dst->map.size + 1));
  if (!tmp)
   return -1;
  dst->map.data = tmp;
  dst->map.data[dst->map.size].key = key_json.string;
  dst->map.data[dst->map.size].value = value_json;
  dst->map.size++;

  if (accept(stream, '}'))
   return 1;

  if (!expect(stream, ','))
   return -1;
 }
}

static int parse_value(json *dst, FILE *stream)
{
 int c = peek(stream);
 if (c == EOF)
 {
  unexpected(stream);
  return -1;
 }
 if (isdigit(c))
  return parse_int(dst, stream);
 if (c == '"')
  return parse_string(dst, stream);
 if (c == '{')
  return parse_map(dst, stream);
 unexpected(stream);
 return -1;

}
//  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _
// /+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\/+\ //
// \_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/ //

int	peek(FILE *stream)
{
	int	c = getc(stream);
	ungetc(c, stream);
	return c;
}

void	unexpected(FILE *stream)
{
	if (peek(stream) != EOF)
		printf("unexpected token '%c'\n", peek(stream));
	else
		printf("unexpected end of input\n");
}

int	accept(FILE *stream, char c)
{
	if (peek(stream) == c)
	{
		(void)getc(stream);
		return 1;
	}
	return 0;
}

int	expect(FILE *stream, char c)
{
	if (accept(stream, c))
		return 1;
	unexpected(stream);
	return 0;
}

void	free_json(json j)
{
	switch (j.type)
	{
		case MAP:
			for (size_t i = 0; i < j.map.size; i++)
			{
				free(j.map.data[i].key);
				free_json(j.map.data[i].value);
			}
			free(j.map.data);
			break ;
		case STRING:
			free(j.string);
			break ;
		default:
			break ;
	}
}

void	serialize(json j)
{
	switch (j.type)
	{
		case INTEGER:
			printf("%d", j.integer);
			break ;
		case STRING:
			putchar('"');
			for (int i = 0; j.string[i]; i++)
			{
				if (j.string[i] == '\\' || j.string[i] == '"')
					putchar('\\');
				putchar(j.string[i]);
			}
			putchar('"');
			break ;
		case MAP:
			putchar('{');
			for (size_t i = 0; i < j.map.size; i++)
			{
				if (i != 0)
					putchar(',');
				serialize((json){.type = STRING, .string = j.map.data[i].key});
				putchar(':');
				serialize(j.map.data[i].value);
			}
			putchar('}');
			break ;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char *filename = argv[1];
	FILE *stream = fopen(filename, "r");
	json	file;
	if (argo (&file, stream) != 1)
	{
		free_json(file);
		return 1;
	}
	serialize(file);
	printf("\n");
}
