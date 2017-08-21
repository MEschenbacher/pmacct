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

u_int32_t CharPtrSz, HostAddrSz;
u_int32_t PextrasSz, PvhdrSz, PtLabelTSz;
u_int32_t PmLabelTSz;
u_int32_t NfHdrV5Sz, NfHdrV1Sz, NfHdrV7Sz, NfHdrV8Sz, NfHdrV9Sz;
u_int32_t IpFixHdrSz;
u_int32_t NfDataHdrV9Sz, NfTplHdrV9Sz, NfOptTplHdrV9Sz;
u_int32_t NfTplFieldV9Sz;
u_int32_t NfDataV1Sz, NfDataV5Sz, NfDataV7Sz;
u_int32_t IP4HdrSz, IP4TlSz, IP6HdrSz, IP6AddrSz, IP6TlSz;
u_int32_t MyTLHdrSz, TCPFlagOff;
u_int32_t SFSampleSz, SFLAddressSz, SFrenormEntrySz;
u_int32_t PptrsSz, UDPHdrSz, CSSz, MyTCPHdrSz, IpFlowCmnSz;
u_int16_t PbgpSz, PlbgpSz, PnatSz, PmplsSz, PtunSz;


#endif /* _ONCE_H_ */
