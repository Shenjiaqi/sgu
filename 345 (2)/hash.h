#ifndef HASH_H
#define HASH_H 1
#include <cstdlib>

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


/* Traverse a hash table.  Call the function on every entry in the
   hash table.  

extern void hash_traverse (struct hash_control *,
			   void (*pfn) (const char *key, void *value));*/

/* Print hash table statistics on the specified file.  NAME is the
   name of the hash table, used for printing a header.  

extern void hash_print_statistics (FILE *, const char *name,
				   struct hash_control *);*/


#endif /* HASH_H */
