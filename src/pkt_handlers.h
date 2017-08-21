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
    along with this program; if no, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#if (defined __PKT_HANDLERS_C)
extern struct channels_list_entry channels_list[MAX_N_PLUGINS]; /* communication channels: core <-> plugins */
#endif

#if (!defined __PKT_HANDLERS_C)
#else
#endif
pkt_handler phandler[N_PRIMITIVES];

#if (!defined __PKT_HANDLERS_C)
#else
#endif
void evaluate_packet_handlers();
void src_mac_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void dst_mac_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void vlan_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void cos_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void etype_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void mpls_label_top_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void mpls_label_bottom_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void mpls_stack_depth_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void src_host_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void dst_host_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void src_port_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void dst_port_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void ip_tos_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void ip_proto_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void tcp_flags_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void counters_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void counters_renormalize_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void post_tag_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void post_tag2_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void flows_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void class_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void in_iface_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void out_iface_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void sampling_rate_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void timestamp_start_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void timestamp_arrival_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void custom_primitives_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void sfprobe_payload_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void nfprobe_extras_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void mpls_vpn_rd_frommap_handler(struct channels_list_entry *, struct packet_ptrs *, char **);

void NF_src_mac_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_dst_mac_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_vlan_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_cos_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_etype_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_src_host_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_dst_host_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_src_nmask_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_dst_nmask_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_src_port_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_dst_port_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_src_as_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_dst_as_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_peer_src_as_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_peer_dst_as_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_peer_src_ip_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_peer_dst_ip_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_ip_tos_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_ip_proto_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_tcp_flags_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_counters_msecs_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_counters_secs_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_counters_new_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_flows_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_class_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_in_iface_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_out_iface_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_sampling_rate_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_post_nat_src_host_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_post_nat_dst_host_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_post_nat_src_port_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_post_nat_dst_port_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_nat_event_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_mpls_label_top_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_mpls_label_bottom_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_mpls_stack_depth_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_mpls_vpn_id_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_timestamp_start_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_timestamp_end_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_timestamp_arrival_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_sequence_number_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_version_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_custom_primitives_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_counters_renormalize_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_counters_map_renormalize_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_cust_tag_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_cust_tag2_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_cust_label_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void NF_tee_payload_handler(struct channels_list_entry *, struct packet_ptrs *, char **);

void bgp_ext_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void nfprobe_bgp_ext_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void sfprobe_bgp_ext_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void bgp_peer_src_as_frommap_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void bgp_src_local_pref_frommap_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void bgp_src_med_frommap_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void bgp_src_nmask_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void bgp_dst_nmask_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void bgp_peer_dst_ip_handler(struct channels_list_entry *, struct packet_ptrs *, char **);

void igp_src_nmask_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void igp_dst_nmask_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void igp_peer_dst_ip_handler(struct channels_list_entry *, struct packet_ptrs *, char **);

void SF_src_mac_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_dst_mac_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_vlan_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_cos_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_etype_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_src_host_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_dst_host_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_src_nmask_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_dst_nmask_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_src_port_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_dst_port_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_src_as_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_dst_as_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_peer_src_ip_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_peer_dst_ip_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_ip_tos_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_ip_proto_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_tcp_flags_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_counters_new_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_counters_renormalize_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_counters_map_renormalize_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_tag_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_tag2_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_class_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_in_iface_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_out_iface_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_sampling_rate_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_sampling_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_timestamp_start_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_timestamp_arrival_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_sequence_number_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_version_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_bgp_peer_src_as_fromext_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_bgp_peer_src_as_fromstd_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_as_path_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_peer_src_as_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_peer_dst_as_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_local_pref_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_std_comms_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_tunnel_src_host_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_tunnel_dst_host_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_tunnel_ip_proto_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_tunnel_ip_tos_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_tee_payload_handler(struct channels_list_entry *, struct packet_ptrs *, char **);

void pre_tag_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void pre_tag2_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void pre_tag_label_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void sampling_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void sfprobe_sampling_handler(struct channels_list_entry *, struct packet_ptrs *, char **);

#if defined (WITH_GEOIP)
void pm_geoip_init();
void src_host_country_geoip_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void dst_host_country_geoip_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
#endif

#if defined (WITH_GEOIPV2)
void pm_geoipv2_init();
void pm_geoipv2_close();
void src_host_geoipv2_lookup_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void dst_host_geoipv2_lookup_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void src_host_country_geoipv2_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void dst_host_country_geoipv2_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void src_host_pocode_geoipv2_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void dst_host_pocode_geoipv2_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
#endif

#if defined (WITH_NDPI)
void ndpi_class_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
void SF_ndpi_class_handler(struct channels_list_entry *, struct packet_ptrs *, char **);
#endif

int evaluate_lm_method(struct packet_ptrs *, u_int8_t, u_int32_t, u_int32_t);
char *lookup_tpl_ext_db(void *, u_int32_t, u_int16_t);
