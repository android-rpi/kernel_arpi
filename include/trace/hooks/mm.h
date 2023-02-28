/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM mm

#define TRACE_INCLUDE_PATH trace/hooks

#if !defined(_TRACE_HOOK_MM_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_MM_H

#include <trace/hooks/vendor_hooks.h>

struct oom_control;
struct slabinfo;
struct cma;
struct compact_control;

DECLARE_RESTRICTED_HOOK(android_rvh_set_skip_swapcache_flags,
			TP_PROTO(gfp_t *flags),
			TP_ARGS(flags), 1);
DECLARE_RESTRICTED_HOOK(android_rvh_set_gfp_zone_flags,
			TP_PROTO(gfp_t *flags),
			TP_ARGS(flags), 1);
DECLARE_RESTRICTED_HOOK(android_rvh_set_readahead_gfp_mask,
			TP_PROTO(gfp_t *flags),
			TP_ARGS(flags), 1);
DECLARE_HOOK(android_vh_cma_alloc_start,
	TP_PROTO(s64 *ts),
	TP_ARGS(ts));
DECLARE_HOOK(android_vh_cma_alloc_finish,
	TP_PROTO(struct cma *cma, struct page *page, unsigned long count,
		 unsigned int align, gfp_t gfp_mask, s64 ts),
	TP_ARGS(cma, page, count, align, gfp_mask, ts));
DECLARE_HOOK(android_vh_meminfo_proc_show,
	TP_PROTO(struct seq_file *m),
	TP_ARGS(m));
DECLARE_HOOK(android_vh_exit_mm,
	TP_PROTO(struct mm_struct *mm),
	TP_ARGS(mm));
DECLARE_HOOK(android_vh_show_mem,
	TP_PROTO(unsigned int filter, nodemask_t *nodemask),
	TP_ARGS(filter, nodemask));
DECLARE_HOOK(android_vh_alloc_pages_slowpath,
	TP_PROTO(gfp_t gfp_mask, unsigned int order, unsigned long delta),
	TP_ARGS(gfp_mask, order, delta));
DECLARE_HOOK(android_vh_cma_alloc_adjust,
	TP_PROTO(struct zone *zone, bool *is_cma_alloc),
	TP_ARGS(zone, is_cma_alloc));
DECLARE_HOOK(android_vh_print_slabinfo_header,
	TP_PROTO(struct seq_file *m),
	TP_ARGS(m));
DECLARE_HOOK(android_vh_cache_show,
	TP_PROTO(struct seq_file *m, struct slabinfo *sinfo, struct kmem_cache *s),
	TP_ARGS(m, sinfo, s));
DECLARE_HOOK(android_vh_oom_check_panic,
	TP_PROTO(struct oom_control *oc, int *ret),
	TP_ARGS(oc, ret));
DECLARE_HOOK(android_vh_drain_all_pages_bypass,
	TP_PROTO(gfp_t gfp_mask, unsigned int order, unsigned long alloc_flags,
		int migratetype, unsigned long did_some_progress,
		bool *bypass),
	TP_ARGS(gfp_mask, order, alloc_flags, migratetype, did_some_progress, bypass));
DECLARE_HOOK(android_vh_cma_drain_all_pages_bypass,
	TP_PROTO(unsigned int migratetype, bool *bypass),
	TP_ARGS(migratetype, bypass));
DECLARE_HOOK(android_vh_pcplist_add_cma_pages_bypass,
	TP_PROTO(int migratetype, bool *bypass),
	TP_ARGS(migratetype, bypass));
DECLARE_HOOK(android_vh_mmap_region,
	TP_PROTO(struct vm_area_struct *vma, unsigned long addr),
	TP_ARGS(vma, addr));
DECLARE_HOOK(android_vh_try_to_unmap_one,
	TP_PROTO(struct vm_area_struct *vma, struct page *page, unsigned long addr, bool ret),
	TP_ARGS(vma, page, addr, ret));
DECLARE_HOOK(android_vh_mm_compaction_begin,
	TP_PROTO(struct compact_control *cc, long *vendor_ret),
	TP_ARGS(cc, vendor_ret));
DECLARE_HOOK(android_vh_mm_compaction_end,
	TP_PROTO(struct compact_control *cc, long vendor_ret),
	TP_ARGS(cc, vendor_ret));
DECLARE_HOOK(android_vh_pagevec_drain,
	TP_PROTO(struct page *page, bool *ret),
	TP_ARGS(page, ret));
DECLARE_HOOK(android_vh_zap_pte_range_tlb_start,
	TP_PROTO(void *ret),
	TP_ARGS(ret));
DECLARE_HOOK(android_vh_zap_pte_range_tlb_force_flush,
	TP_PROTO(struct page *page, bool *flush),
	TP_ARGS(page, flush));
DECLARE_HOOK(android_vh_zap_pte_range_tlb_end,
	TP_PROTO(void *ret),
	TP_ARGS(ret));
DECLARE_HOOK(android_vh_skip_lru_disable,
	TP_PROTO(bool *skip),
	TP_ARGS(skip));
DECLARE_HOOK(android_vh_do_madvise_blk_plug,
	TP_PROTO(int behavior, bool *do_plug),
	TP_ARGS(behavior, do_plug));
DECLARE_HOOK(android_vh_shrink_inactive_list_blk_plug,
	TP_PROTO(bool *do_plug),
	TP_ARGS(do_plug));
DECLARE_HOOK(android_vh_shrink_lruvec_blk_plug,
	TP_PROTO(bool *do_plug),
	TP_ARGS(do_plug));
DECLARE_HOOK(android_vh_reclaim_pages_plug,
	TP_PROTO(bool *do_plug),
	TP_ARGS(do_plug));
struct mem_cgroup;
DECLARE_HOOK(android_vh_mem_cgroup_alloc,
	TP_PROTO(struct mem_cgroup *memcg),
	TP_ARGS(memcg));
DECLARE_HOOK(android_vh_mem_cgroup_free,
	TP_PROTO(struct mem_cgroup *memcg),
	TP_ARGS(memcg));
DECLARE_HOOK(android_vh_mem_cgroup_id_remove,
	TP_PROTO(struct mem_cgroup *memcg),
	TP_ARGS(memcg));
struct cgroup_subsys_state;
DECLARE_HOOK(android_vh_mem_cgroup_css_online,
	TP_PROTO(struct cgroup_subsys_state *css, struct mem_cgroup *memcg),
	TP_ARGS(css, memcg));
DECLARE_HOOK(android_vh_mem_cgroup_css_offline,
	TP_PROTO(struct cgroup_subsys_state *css, struct mem_cgroup *memcg),
	TP_ARGS(css, memcg));
#endif /* _TRACE_HOOK_MM_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
