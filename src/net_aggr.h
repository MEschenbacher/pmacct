/*
    pmacct (Promiscuous mode IP Accounting package)
    pmacct is Copyright (C) 2003-2014 by Paolo Lucente
*/

/*
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

/* defines */
#define NETWORKS_CACHE_ENTRIES 99991
#define NETWORKS6_CACHE_ENTRIES 32771
#define RETURN_NET 0
#define RETURN_AS 1
#define NET_FUNCS_N 32

/* structures */
struct networks_cache_entry {
	u_int32_t key;
	struct networks_table_entry *result;
};

struct networks_cache {
	struct networks_cache_entry *cache;
	unsigned int num;
#if defined ENABLE_IPV6
	struct networks6_cache_entry *cache6;
	unsigned int num6;
#endif
};

struct networks_table {
	struct networks_table_entry *table;
	unsigned int num;
#if defined ENABLE_IPV6
	struct networks6_table_entry *table6;
	unsigned int num6;
#endif
	u_int32_t maskbits[4];
	time_t timestamp;
};

struct networks_table_entry {
	u_int32_t net;
	u_int32_t mask;
	u_int8_t masknum;
	as_t peer_as;
	as_t as;
	struct host_addr nh;
#if defined ENABLE_PLABEL
	u_char plabel[PREFIX_LABEL_LEN];
#endif
	struct networks_table childs_table;
};

#if defined ENABLE_IPV6
struct networks6_cache_entry {
	u_int32_t key[4];
	struct networks6_table_entry *result;
};

struct networks6_table_entry {
	u_int32_t net[4];
	u_int32_t mask[4];
	u_int8_t masknum;
	as_t peer_as;
	as_t as;
	struct host_addr nh;
#if defined ENABLE_PLABEL
	u_char plabel[PREFIX_LABEL_LEN];
#endif
	struct networks_table childs_table;
};
#endif

struct networks_table_metadata {
	u_int8_t level;
	u_int32_t childs;
};

struct networks_file_data {
	u_int8_t zero_src_nmask;
	u_int8_t zero_dst_nmask;
	u_int8_t family;
	u_char *entry;
};

typedef void (*net_func) (struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);

/* prototypes */
#if (!defined __NET_AGGR_C)
#else
#endif
net_func net_funcs[NET_FUNCS_N];
void set_net_funcs();
void init_net_funcs(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void mask_src_ipaddr(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void mask_dst_ipaddr(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void mask_static_src_ipaddr(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void mask_static_dst_ipaddr(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void copy_src_mask(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void copy_dst_mask(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void search_src_ip(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void search_dst_ip(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void search_src_host(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void search_dst_host(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
#if defined ENABLE_PLABEL
void search_src_host_label(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void search_dst_host_label(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
#endif
void search_src_nmask(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void search_dst_nmask(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void search_src_as(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void search_dst_as(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void search_peer_src_as(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void search_peer_dst_as(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void search_peer_dst_ip(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void clear_src_host(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void clear_dst_host(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void clear_src_net(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void clear_dst_net(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void clear_src_nmask(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
void clear_dst_nmask(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
as_t search_pretag_src_as(struct networks_table *, struct networks_cache *, struct packet_ptrs *);
as_t search_pretag_dst_as(struct networks_table *, struct networks_cache *, struct packet_ptrs *);

void load_networks(char *, struct networks_table *, struct networks_cache *); /* wrapper */
void load_networks4(char *, struct networks_table *, struct networks_cache *);
void merge_sort(char *, struct networks_table_entry *, int, int);
void merge(char *, struct networks_table_entry *, int, int, int);
struct networks_table_entry *binsearch(struct networks_table *, struct networks_cache *, struct host_addr *);
void networks_cache_insert(struct networks_cache *, u_int32_t *, struct networks_table_entry *);
struct networks_table_entry *networks_cache_search(struct networks_cache *, u_int32_t *);

#if defined ENABLE_IPV6
void load_networks6(char *, struct networks_table *, struct networks_cache *);
void merge_sort6(char *, struct networks6_table_entry *, int, int);
void merge6(char *, struct networks6_table_entry *, int, int, int);
struct networks6_table_entry *binsearch6(struct networks_table *, struct networks_cache *, struct host_addr *);
void networks_cache_insert6(struct networks_cache *, void *, struct networks6_table_entry *);
struct networks6_table_entry *networks_cache_search6(struct networks_cache *, void *);
unsigned int networks_cache_hash6(void *);
#endif

/* global vars */
#if (!defined __NET_AGGR_C)
#else
#endif
struct networks_table nt;
struct networks_cache nc;
struct networks_table_entry dummy_entry;
int default_route_in_networks4_table;

#if defined ENABLE_IPV6
struct networks6_table_entry dummy_entry6;
int default_route_in_networks6_table;
#endif
