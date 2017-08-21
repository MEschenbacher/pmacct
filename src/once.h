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

#ifndef _ONCE_H_
#define _ONCE_H_

#if defined __PMACCTD_C || defined __NFACCTD_C || defined __SFACCTD_C || defined __UACCTD_C || defined __PMACCT_CLIENT_C || defined __PMTELEMETRYD_C || defined __PMBGPD_C || defined __PMBMPD_C
#else
#endif

#define PdataSz (sizeof(struct pkt_data))
#define PpayloadSz (sizeof(struct pkt_payload))
#define PmsgSz (sizeof(struct pkt_msg))
#define ChBufHdrSz (sizeof(struct ch_buf_hdr))
#define PextrasSz (sizeof(struct pkt_extras))
#define PbgpSz (sizeof(struct pkt_bgp_primitives))
#define PlbgpSz (sizeof(struct pkt_legacy_bgp_primitives))
#define PnatSz (sizeof(struct pkt_nat_primitives))
#define PmplsSz (sizeof(struct pkt_mpls_primitives))
#define PtunSz (sizeof(struct pkt_tunnel_primitives))
#define PvhdrSz (sizeof(struct pkt_vlen_hdr_primitives))
#define PmLabelTSz (sizeof(pm_label_t))
#define CharPtrSz (sizeof(char *))
#define NfHdrV1Sz (sizeof(struct struct_header_v1))
#define NfHdrV5Sz (sizeof(struct struct_header_v5))
#define NfHdrV7Sz (sizeof(struct struct_header_v7))
#define NfHdrV8Sz (sizeof(struct struct_header_v8))
#define NfHdrV9Sz (sizeof(struct struct_header_v9))
#define NfDataHdrV9Sz (sizeof(struct data_hdr_v9))
#define NfTplHdrV9Sz (sizeof(struct template_hdr_v9))
#define NfTplFieldV9Sz (sizeof(struct template_field_v9))
#define NfOptTplHdrV9Sz (sizeof(struct options_template_hdr_v9))
#define NfDataV1Sz (sizeof(struct struct_export_v1))
#define NfDataV5Sz (sizeof(struct struct_export_v5))
#define NfDataV7Sz (sizeof(struct struct_export_v7))
#define IP4HdrSz (sizeof(struct pm_iphdr))
#define IP4TlSz (sizeof(struct pm_iphdr)+sizeof(struct pm_tlhdr))
#define CSSz (sizeof(struct class_st))
#define HostAddrSz (sizeof(struct host_addr))
#define UDPHdrSz (sizeof(struct pm_udphdr))
#define IpFixHdrSz (sizeof(struct struct_header_ipfix))
#define SFSampleSz (sizeof(SFSample))

u_int32_t IP6HdrSz, IP6AddrSz, IP6TlSz;
u_int32_t MyTLHdrSz, TCPFlagOff;
u_int32_t SFrenormEntrySz;
u_int32_t MyTCPHdrSz, IpFlowCmnSz;


#endif /* _ONCE_H_ */
