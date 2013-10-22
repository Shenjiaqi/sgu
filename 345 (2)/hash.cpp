/* An entry in a hash table.  */
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

class hash_entry {
public:
  /* Next entry for this hash code.  */
  class hash_entry *next;
  /* String being hashed.  */
  const char *string;
  /* Hash code.  This is the full hash code, not the index into the
     table.  */
  unsigned long hash;
  /* Pointer being stored in the hash table.  */
  int data;	/*[void *data;]*/
};

/* A hash table.  */

class hash_control {
private:

/* The default number of entries to use when creating a hash table.
TODO  Note this value can be reduced to 4051 by using the command line
   switch --reduce-memory-overheads, or set to other values by using
   the --hash-size=<NUMBER> switch.  */


  /* The hash array.  */
  class hash_entry **table;
  /* The number of slots in the hash table.  */
  unsigned int size;

#ifdef HASH_STATISTICS
  /* Statistics.  */
  unsigned long lookups;
  unsigned long hash_compares;
  unsigned long string_compares;
  unsigned long insertions;
  unsigned long replacements;
  unsigned long deletions;
#endif /* HASH_STATISTICS */
	class hash_entry *loopup (const char *key, size_t len,
	     class hash_entry ***plist, unsigned long *phash);
	unsigned int get_size ();
	void set_size (unsigned long size);
	void init ();
public:
	hash_control(unsigned int table_size=65537);
	~hash_control();
	const char *insert (const char *key, int val /*[void *val]*/);
	int find (const char *key);
	int replace (const char *key, int value);
	int erase (const char *key);
};

hash_control::~hash_control()
{
	/*TODO*/
}

hash_control::hash_control(unsigned int table_size)
{
	size=table_size;
	init();
}

/* Look up a string in a hash table.  This returns a pointer to the
   hash_entry, or NULL if the string is not in the table.  If PLIST is
   not NULL, this sets *PLIST to point to the start of the list which
   would hold this hash entry.  If PHASH is not NULL, this sets *PHASH
   to the hash code for KEY.

   Each time we look up a string, we move it to the start of the list
   for its hash code, to take advantage of referential locality.  */

class hash_entry *hash_control::
loopup (const char *key, size_t len,
	     class hash_entry ***plist, unsigned long *phash)
{
  unsigned long hash;
  size_t n;
  unsigned int c;
  unsigned int hindex;
  class hash_entry **list;
  class hash_entry *p;
  class hash_entry *prev;

#ifdef HASH_STATISTICS
  ++lookups;
#endif

  hash = 0;
  for (n = 0; n < len; n++)
    {
      c = key[n];
      hash += c + (c << 17);
      hash ^= hash >> 2;
    }
  hash += len + (len << 17);
  hash ^= hash >> 2;

  if (phash != NULL)
    *phash = hash;

  hindex = hash % size;
  list = table + hindex;

  if (plist != NULL)
    *plist = list;

  prev = NULL;
  for (p = *list; p != NULL; p = p->next)
    {
#ifdef HASH_STATISTICS
      ++hash_compares;
#endif

      if (p->hash == hash)
	{
#ifdef HASH_STATISTICS
	  ++string_compares;
#endif

	  if (strncmp (p->string, key, len) == 0 && p->string[len] == '\0')
	    {
	      if (prev != NULL)
		{
		  prev->next = p->next;/*lur*/
		  p->next = *list;
		  *list = p;
		}

	      return p;
	    }
	}

      prev = p;
    }

  return NULL;
}

unsigned int hash_control::
get_size (void)
{
  /* Extend this prime list if you want more granularity of hash table size.  */
  static const unsigned int hash_size_primes[] =
    {
      1021, 4051, 8599, 16699, 65537
    };

  /* Work out the best prime number near the hash_size.
     FIXME: This could be a more sophisticated algorithm,
     but is it really worth implementing it ?   */
	unsigned int hindex = 0;
  for (; hindex < sizeof(hash_size_primes)/sizeof(hash_size_primes[0]) - 1; ++ hindex)
    if (size <= hash_size_primes[hindex])
      break;

  return hash_size_primes[hindex];
}

/* Create a hash table.  This return a control block.  */

void hash_control::init ()
{
  size = get_size ();

  if( NULL == ( table = new class hash_entry * [size]) )
  {
  	perror("hash_control:");
  	exit(1);
  }
  memset ( table, 0, size*sizeof(table[0]) );

#ifdef HASH_STATISTICS
  lookups = 0;
  hash_compares = 0;
  string_compares = 0;
  insertions = 0;
  replacements = 0;
  deletions = 0;
#endif
}

/* Insert an entry into a hash table.  This returns NULL on success.
   On error, it returns a printable string indicating the error.  It
   is considered to be an error if the entry already exists in the
   hash table.  */

const char * hash_control::insert (const char *key, int val /*[void *val]*/)
{
  class hash_entry *p;
  class hash_entry **list;
  unsigned long hash;

  p = loopup (key, strlen (key), &list, &hash);
  if (p != NULL)
    return "exists";

#ifdef HASH_STATISTICS
  ++insertions;
#endif

  p = new class hash_entry;
  p->string = key;
  p->hash = hash;
  p->data = val;

  p->next = *list;
  *list = p;

  return NULL;
}


/* Find an entry in a hash table, returning its value.  Returns NULL
   if the entry is not found.  */

int hash_control::find (const char *key)
{
  class hash_entry *p;

  p = loopup (key, strlen (key), NULL, NULL);
  if (p == NULL)
    return 0;

  return p->data;
}

/* Replace an existing entry in a hash table.  This returns the old
   value stored for the entry.  If the entry is not found in the hash
   table, this does nothing and returns NULL.  */

int hash_control::replace (const char *key, int value
 /*[void *value]*/)
{
  class hash_entry *p;
  int ret;/*[void *ret;]*/

  p = loopup ( key, strlen (key), NULL, NULL);
  if (p == 0)
    return 0;

#ifdef HASH_STATISTICS
  ++replacements;
#endif

  ret = p->data;

  p->data = value;

  return ret;
}

/* Delete an entry from a hash table.  This returns the value stored
   for that entry, or NULL if there is no such entry.*/  

int hash_control::erase (const char *key)
{
  class hash_entry *p;
  class hash_entry **list;

  p = loopup (key, strlen (key), &list, NULL);
  if (p == 0)
    return 0;

  if (p != *list)
    abort ();

#ifdef HASH_STATISTICS
  ++deletions;
#endif

  *list = p->next;
  int tmp=p->data;
	delete p;
  return tmp;
}
