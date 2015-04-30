#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char valid;
    unsigned int tag;
    unsigned int timestamp;
} cache_line_t;

typedef struct {
    cache_line_t *lines;
} cache_set_t;

typedef struct {
    int num_sets;
    int associativity;
    int block_size;
    cache_set_t *sets;
} cache_t;

cache_t *make_cache(int lines, int associativity, int blocks);

int lookup_cache(long addr_reg, cache_t *cache);

void free_cache(cache_t *cache);

int main (int argc, char *argv[]) {
    int num_lines = atoi(argv[1]),
        associativity = atoi(argv[2]),
        blocks = atoi(argv[3]),
        found=0,
        req=0;
    double rate;

    char line[80];
   
    long addr_req;
 
    cache_t *cache= make_cache(num_lines, associativity, blocks);

    while (fgets(line, 80, stdin)) {
        addr_req = strtol(line, NULL, 0);
        if(lookup_cache(addr_req, cache)){
            found++;
        }
        req++;
    }
    rate=(found / (double)req)*100.0;

    printf("Hit Rate: %0.2f%% | Miss Rate: %0.2f%%\n", rate, 100-rate);
    free_cache(cache);
    return 0;
}

cache_t *make_cache(int lines, int associativity, int blocks){
    cache_t *cache= calloc(1, sizeof(cache_t));
    cache->num_sets=lines/associativity;
    cache->associativity=associativity;
    cache->block_size=blocks;
    cache->sets=calloc(cache->num_sets, sizeof(cache_set_t));
    int i;
    for(i=0; i < cache->num_sets; i++){
        cache->sets[i].lines=calloc(associativity, sizeof(cache_line_t));
    }
    return cache;
}

int lookup_cache(long addr_reg, cache_t *cache){
    static unsigned int timestamp=0;
    int set_idx=(addr_reg / cache->block_size) % cache->num_sets,
        tag = addr_reg / (cache->block_size * cache->num_sets),
        i,
        j= -1,
        k,
        hit =0;
    cache_set_t *set=cache->sets +set_idx;
    for(i=0; i<cache->associativity; i++){
        if(set->lines[i].valid == '1' && set->lines[i].tag == tag){
            hit = 1;
            break;
        }
    }

    if(hit){
        set->lines[i].timestamp= ++timestamp;
        return 1;
    }else{
        /*  for(i=0; i < cache->associativity; i++){
            if(set->lines[i].valid=='0'){
                set->lines[i].valid = '1';
                set->lines[i].tag = tag;
                set->lines[i].timestamp=++timestamp;
                return 0;
            }
        }
        */
        for(i=0; i < cache->associativity; i++){
            if (set->lines[i].timestamp <= j ){
                j=set->lines[i].timestamp;
                k=i;
            }
        }

        set->lines[k].valid='1';
        set->lines[k].tag = tag;
        set->lines[k].timestamp=++timestamp;
        return 0;
    }
}

void free_cache(cache_t *cache){
    int i;
    for(i=cache->num_sets; i>=0; i--)
        free(cache->sets[i].lines);
    free(cache->sets);
    free(cache);
}

