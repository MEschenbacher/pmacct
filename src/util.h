/*
    pmacct (Promiscuous mode IP Accounting package)
    pmacct is Copyright (C) 2003-2017 by Paolo Lucente
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
#define ADD 0
#define SUB 1

#ifdef WITH_AVRO
#define check_i(call) \
  do { \
    if ((call) != 0) { \
      Log(LOG_ERR, "Error: %s\n", avro_strerror()); \
      exit_plugin(1); \
    } \
} while (0)
#endif

/* prototypes */
#if (!defined __UTIL_C)
#else
#endif
void setnonblocking(int);
void setblocking(int);
int daemonize();
char *copy_argv(register char **);
char *extract_token(char **, int);
char *extract_plugin_name(char **);
void trim_spaces(char *);
void trim_all_spaces(char *);
void strip_quotes(char *);
void string_add_newline(char *);
int isblankline(char *);
int iscomment(char *);
int check_not_valid_char(char *, char *, int);
time_t roundoff_time(time_t, char *);
time_t calc_monthly_timeslot(time_t, int, int);
void write_pid_file(char *);
void write_pid_file_plugin(char *, char *, char *);
void remove_pid_file(char *);
int sanitize_buf_net(char *, char *, int);
int sanitize_buf(char *);
void mark_columns(char *);
int Setsocksize(int, int, int, void *, int);
void *map_shared(void *, size_t, int, int, int, off_t);
void lower_string(char *);
void evaluate_sums(u_int64_t *, u_int64_t *, char *, char *);
void stop_all_childs();
int file_lock(int);
int file_unlock(int);
void strftime_same(char *, int, char *, const time_t *);
int read_SQLquery_from_file(char *, char *, int);
void stick_bosbit(u_char *);
int check_bosbit(u_char *);
u_int32_t decode_mpls_label(char *);
int timeval_cmp(struct timeval *, struct timeval *);
void exit_all(int);
void exit_plugin(int);
void reset_tag_label_status(struct packet_ptrs_vector *);
void reset_net_status(struct packet_ptrs *);
void reset_net_status_v(struct packet_ptrs_vector *);
void reset_shadow_status(struct packet_ptrs_vector *);
void reset_fallback_status(struct packet_ptrs *);
void set_sampling_table(struct packet_ptrs_vector *, u_char *);
void set_shadow_status(struct packet_ptrs *);
void set_default_preferences(struct configuration *);
FILE *open_output_file(char *, char *, int);
void link_latest_output_file(char *, char *);
void close_output_file(FILE *);
void handle_dynname_internal_strings(char *, int, char *, struct primitives_ptrs *);
void handle_dynname_internal_strings_same(char *, int, char *, struct primitives_ptrs *);
void escape_ip_uscores(char *);
int sql_history_to_secs(int, int);
void *pm_malloc(size_t);
void load_allow_file(char *, struct hosts_table *);
int check_allow(struct hosts_table *, struct sockaddr *);
int BTA_find_id(struct id_table *, struct packet_ptrs *, pm_id_t *, pm_id_t *);
void calc_refresh_timeout(time_t, time_t, int *);
void calc_refresh_timeout_sec(time_t, time_t, int *);
int load_tags(char *, struct pretag_filter *, char *);
int load_labels(char *, struct pretag_label_filter *, char *);
int evaluate_tags(struct pretag_filter *, pm_id_t);
int evaluate_labels(struct pretag_label_filter *, pt_label_t *);
void load_pkt_len_distrib_bins();
void evaluate_pkt_len_distrib(struct pkt_data *);
char *write_sep(char *, int *);
void version_daemon(char *);
void set_truefalse_nonzero(int *);

char *compose_json_str(void *);
void write_and_free_json(FILE *, void *);
int write_and_free_json_amqp(void *, void *);
void add_writer_name_and_pid_json(void *, char *, pid_t);

#ifdef WITH_AVRO
void write_avro_schema_to_file(char *, avro_schema_t);
char *compose_avro_purge_schema(avro_schema_t, char *);
#endif

void compose_timestamp(char *, int, struct timeval *, int, int);

void print_primitives(int, char *);
int mkdir_multilevel(const char *, int, uid_t, gid_t);
char bin_to_hex(int);
int print_hex(const u_char *, u_char *, int);

primptrs_func primptrs_funcs[PRIMPTRS_FUNCS_N];
void set_primptrs_funcs(struct extra_primitives *);
void primptrs_set_bgp(u_char *, struct extra_primitives *, struct primitives_ptrs *);
void primptrs_set_lbgp(u_char *, struct extra_primitives *, struct primitives_ptrs *);
void primptrs_set_nat(u_char *, struct extra_primitives *, struct primitives_ptrs *);
void primptrs_set_mpls(u_char *, struct extra_primitives *, struct primitives_ptrs *);
void primptrs_set_tun(u_char *, struct extra_primitives *, struct primitives_ptrs *);
void primptrs_set_custom(u_char *, struct extra_primitives *, struct primitives_ptrs *);
void primptrs_set_extras(u_char *, struct extra_primitives *, struct primitives_ptrs *);
void primptrs_set_vlen_hdr(u_char *, struct extra_primitives *, struct primitives_ptrs *);

int custom_primitives_vlen(struct custom_primitives_ptrs *);
void custom_primitives_reconcile(struct custom_primitives_ptrs *, struct custom_primitives *);
void custom_primitive_header_print(char *, int, struct custom_primitive_ptrs *, int);
void custom_primitive_value_print(char *, int, char *, struct custom_primitive_ptrs *, int);

unsigned char *vlen_prims_copy(struct pkt_vlen_hdr_primitives *);
void vlen_prims_init(struct pkt_vlen_hdr_primitives *, int);
void vlen_prims_free(struct pkt_vlen_hdr_primitives *);
int vlen_prims_cmp(struct pkt_vlen_hdr_primitives *, struct pkt_vlen_hdr_primitives *);
void vlen_prims_get(struct pkt_vlen_hdr_primitives *, pm_cfgreg_t, char **);
void vlen_prims_debug(struct pkt_vlen_hdr_primitives *);
void vlen_prims_insert(struct pkt_vlen_hdr_primitives *, pm_cfgreg_t, int, char *, int);
int vlen_prims_delete(struct pkt_vlen_hdr_primitives *, pm_cfgreg_t);

void hash_init_key(pm_hash_key_t *);
int hash_init_serial(pm_hash_serial_t *, u_int16_t);
int hash_alloc_key(pm_hash_key_t *, u_int16_t);
int hash_dup_key(pm_hash_key_t *, pm_hash_key_t *);
void hash_destroy_key(pm_hash_key_t *);
void hash_destroy_serial(pm_hash_serial_t *);
void hash_serial_set_off(pm_hash_serial_t *, u_int16_t);
void hash_serial_append(pm_hash_serial_t *, char *, u_int16_t, int);
pm_hash_key_t *hash_serial_get_key(pm_hash_serial_t *);
u_int16_t hash_serial_get_off(pm_hash_serial_t *);
u_int16_t hash_key_get_len(pm_hash_key_t *);
char *hash_key_get_val(pm_hash_key_t *);
int hash_key_cmp(pm_hash_key_t *, pm_hash_key_t *);
char *hash_key_get_val(pm_hash_key_t *);

void dump_writers_init();
void dump_writers_count();
u_int32_t dump_writers_get_flags();
u_int16_t dump_writers_get_active();
u_int16_t dump_writers_get_max();
int dump_writers_add(pid_t);

int pm_scandir(const char *, struct dirent ***, int (*select)(const struct dirent *), int (*compar)(const void *, const void *));
void pm_scandir_free(struct dirent ***, int);
int pm_alphasort(const void *, const void *);

void *pm_tsearch(const void *, void **, int (*compar)(const void *, const void *), size_t);
void pm_tdestroy(void **, void (*free_node)(void *));

void replace_string(char *, int, char *, char *);
int delete_line_from_file(int, char *);

void generate_random_string(char *, const int);
