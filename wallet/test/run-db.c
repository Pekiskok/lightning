#include "config.h"
#include <lightningd/log.h>

static void db_log_(struct logger *log UNUSED, enum log_level level UNUSED, const struct node_id *node_id UNUSED, bool call_notifier UNUSED, const char *fmt UNUSED, ...)
{
}
#define log_ db_log_

#include "db/bindings.c"
#include "db/db_sqlite3.c"
#include "db/exec.c"
#include "db/utils.c"
#include "wallet/db.c"
#include "wallet/wallet.c"

#include "test_utils.h"

#include <common/setup.h>
#include <common/utils.h>
#include <lightningd/channel.h>
#include <stdio.h>
#include <unistd.h>

/* AUTOGENERATED MOCKS START */
/* Generated stub for bip32_pubkey */
void bip32_pubkey(struct lightningd *ld UNNEEDED, struct pubkey *pubkey UNNEEDED, u32 index UNNEEDED)
{ fprintf(stderr, "bip32_pubkey called!\n"); abort(); }
/* Generated stub for bitcoind_getrawblockbyheight_ */
void bitcoind_getrawblockbyheight_(const tal_t *ctx UNNEEDED,
				   struct bitcoind *bitcoind UNNEEDED,
				   u32 height UNNEEDED,
				   void (*cb)(struct bitcoind *bitcoind_ UNNEEDED,
					      u32 height_ UNNEEDED,
					      struct bitcoin_blkid *blkid UNNEEDED,
					      struct bitcoin_block *blk UNNEEDED,
					      void *arg) UNNEEDED,
				   void *arg UNNEEDED)
{ fprintf(stderr, "bitcoind_getrawblockbyheight_ called!\n"); abort(); }
/* Generated stub for channel_gossip_get_remote_update */
const struct peer_update *channel_gossip_get_remote_update(const struct channel *channel UNNEEDED)
{ fprintf(stderr, "channel_gossip_get_remote_update called!\n"); abort(); }
/* Generated stub for channel_gossip_update */
void channel_gossip_update(struct channel *channel UNNEEDED)
{ fprintf(stderr, "channel_gossip_update called!\n"); abort(); }
/* Generated stub for channel_scid_or_local_alias */
struct short_channel_id channel_scid_or_local_alias(const struct channel *chan UNNEEDED)
{ fprintf(stderr, "channel_scid_or_local_alias called!\n"); abort(); }
/* Generated stub for channel_state_name */
const char *channel_state_name(const struct channel *channel UNNEEDED)
{ fprintf(stderr, "channel_state_name called!\n"); abort(); }
/* Generated stub for connect_htlc_in */
void connect_htlc_in(struct htlc_in_map *map UNNEEDED, struct htlc_in *hin UNNEEDED)
{ fprintf(stderr, "connect_htlc_in called!\n"); abort(); }
/* Generated stub for connect_htlc_out */
void connect_htlc_out(struct htlc_out_map *map UNNEEDED, struct htlc_out *hout UNNEEDED)
{ fprintf(stderr, "connect_htlc_out called!\n"); abort(); }
/* Generated stub for create_onionreply */
struct onionreply *create_onionreply(const tal_t *ctx UNNEEDED,
				     const struct secret *shared_secret UNNEEDED,
				     const u8 *failure_msg UNNEEDED)
{ fprintf(stderr, "create_onionreply called!\n"); abort(); }
/* Generated stub for derive_channel_id */
void derive_channel_id(struct channel_id *channel_id UNNEEDED,
		       const struct bitcoin_outpoint *outpoint UNNEEDED)
{ fprintf(stderr, "derive_channel_id called!\n"); abort(); }
/* Generated stub for fatal */
void   fatal(const char *fmt UNNEEDED, ...)
{ fprintf(stderr, "fatal called!\n"); abort(); }
/* Generated stub for fatal_vfmt */
void  fatal_vfmt(const char *fmt UNNEEDED, va_list ap UNNEEDED)
{ fprintf(stderr, "fatal_vfmt called!\n"); abort(); }
/* Generated stub for find_peer_by_dbid */
struct peer *find_peer_by_dbid(struct lightningd *ld UNNEEDED, u64 dbid UNNEEDED)
{ fprintf(stderr, "find_peer_by_dbid called!\n"); abort(); }
/* Generated stub for fmt_channel_id */
char *fmt_channel_id(const tal_t *ctx UNNEEDED, const struct channel_id *channel_id UNNEEDED)
{ fprintf(stderr, "fmt_channel_id called!\n"); abort(); }
/* Generated stub for forward_index_created */
u64 forward_index_created(struct lightningd *ld UNNEEDED,
			  enum forward_status status UNNEEDED,
			  struct short_channel_id in_channel UNNEEDED,
			  u64 in_htlc_id UNNEEDED,
			  struct amount_msat in_amount UNNEEDED,
			  const struct short_channel_id *out_channel UNNEEDED)
{ fprintf(stderr, "forward_index_created called!\n"); abort(); }
/* Generated stub for forward_index_deleted */
void forward_index_deleted(struct lightningd *ld UNNEEDED,
			   enum forward_status status UNNEEDED,
			   struct short_channel_id in_channel UNNEEDED,
			   u64 in_htlc_id UNNEEDED,
			   const struct amount_msat *in_amount UNNEEDED,
			   const struct short_channel_id *out_channel UNNEEDED)
{ fprintf(stderr, "forward_index_deleted called!\n"); abort(); }
/* Generated stub for forward_index_update_status */
u64 forward_index_update_status(struct lightningd *ld UNNEEDED,
				enum forward_status status UNNEEDED,
				struct short_channel_id in_channel UNNEEDED,
				u64 in_htlc_id UNNEEDED,
				struct amount_msat in_amount UNNEEDED,
				const struct short_channel_id *out_channel UNNEEDED)
{ fprintf(stderr, "forward_index_update_status called!\n"); abort(); }
/* Generated stub for fromwire_hsmd_get_channel_basepoints_reply */
bool fromwire_hsmd_get_channel_basepoints_reply(const void *p UNNEEDED, struct basepoints *basepoints UNNEEDED, struct pubkey *funding_pubkey UNNEEDED)
{ fprintf(stderr, "fromwire_hsmd_get_channel_basepoints_reply called!\n"); abort(); }
/* Generated stub for fromwire_hsmd_get_output_scriptpubkey_reply */
bool fromwire_hsmd_get_output_scriptpubkey_reply(const tal_t *ctx UNNEEDED, const void *p UNNEEDED, u8 **script UNNEEDED)
{ fprintf(stderr, "fromwire_hsmd_get_output_scriptpubkey_reply called!\n"); abort(); }
/* Generated stub for get_channel_basepoints */
void get_channel_basepoints(struct lightningd *ld UNNEEDED,
			    const struct node_id *peer_id UNNEEDED,
			    const u64 dbid UNNEEDED,
			    struct basepoints *local_basepoints UNNEEDED,
			    struct pubkey *local_funding_pubkey UNNEEDED)
{ fprintf(stderr, "get_channel_basepoints called!\n"); abort(); }
/* Generated stub for hash_cid */
size_t hash_cid(const struct channel_id *cid UNNEEDED)
{ fprintf(stderr, "hash_cid called!\n"); abort(); }
/* Generated stub for htlc_in_check */
struct htlc_in *htlc_in_check(const struct htlc_in *hin UNNEEDED, const char *abortstr UNNEEDED)
{ fprintf(stderr, "htlc_in_check called!\n"); abort(); }
/* Generated stub for htlc_out_connect_htlc_in */
void htlc_out_connect_htlc_in(struct htlc_out *hout UNNEEDED, struct htlc_in *hin UNNEEDED)
{ fprintf(stderr, "htlc_out_connect_htlc_in called!\n"); abort(); }
/* Generated stub for htlcs_index_created */
u64 htlcs_index_created(struct lightningd *ld UNNEEDED,
			u64 htlc_id UNNEEDED,
			const struct channel *channel UNNEEDED,
			const struct sha256 *payment_hash UNNEEDED,
			enum side owner UNNEEDED,
			u32 expiry UNNEEDED,
			struct amount_msat amount UNNEEDED,
			enum htlc_state hstate UNNEEDED)
{ fprintf(stderr, "htlcs_index_created called!\n"); abort(); }
/* Generated stub for htlcs_index_deleted */
void htlcs_index_deleted(struct lightningd *ld UNNEEDED,
			 const struct channel *channel UNNEEDED,
			 u64 num_deleted UNNEEDED)
{ fprintf(stderr, "htlcs_index_deleted called!\n"); abort(); }
/* Generated stub for htlcs_index_update_status */
u64 htlcs_index_update_status(struct lightningd *ld UNNEEDED,
			      u64 htlc_id UNNEEDED,
			      const struct channel *channel UNNEEDED,
			      const struct sha256 *payment_hash UNNEEDED,
			      enum side owner UNNEEDED,
			      u32 expiry UNNEEDED,
			      struct amount_msat amount UNNEEDED,
			      enum htlc_state hstate UNNEEDED)
{ fprintf(stderr, "htlcs_index_update_status called!\n"); abort(); }
/* Generated stub for inflight_set_last_tx */
void inflight_set_last_tx(struct channel_inflight *inflight UNNEEDED,
		          struct bitcoin_tx *last_tx STEALS UNNEEDED,
		          const struct bitcoin_signature last_sig UNNEEDED)
{ fprintf(stderr, "inflight_set_last_tx called!\n"); abort(); }
/* Generated stub for invoices_new */
struct invoices *invoices_new(const tal_t *ctx UNNEEDED,
			      struct wallet *wallet UNNEEDED,
			      struct timers *timers UNNEEDED)
{ fprintf(stderr, "invoices_new called!\n"); abort(); }
/* Generated stub for logv */
void logv(struct logger *logger UNNEEDED, enum log_level level UNNEEDED, const struct node_id *node_id UNNEEDED,
	  bool call_notifier UNNEEDED, const char *fmt UNNEEDED, va_list ap UNNEEDED)
{ fprintf(stderr, "logv called!\n"); abort(); }
/* Generated stub for memleak_scan_outpointfilter */
void memleak_scan_outpointfilter(struct htable *memtable UNNEEDED,
				 const struct outpointfilter *opf UNNEEDED)
{ fprintf(stderr, "memleak_scan_outpointfilter called!\n"); abort(); }
/* Generated stub for new_channel */
struct channel *new_channel(struct peer *peer UNNEEDED, u64 dbid UNNEEDED,
			    /* NULL or stolen */
			    struct wallet_shachain *their_shachain STEALS UNNEEDED,
			    enum channel_state state UNNEEDED,
			    enum side opener UNNEEDED,
			    /* NULL or stolen */
			    struct logger *log STEALS UNNEEDED,
			    const char *transient_billboard TAKES UNNEEDED,
			    u8 channel_flags UNNEEDED,
			    bool req_confirmed_ins_local UNNEEDED,
			    bool req_confirmed_ins_remote UNNEEDED,
			    const struct channel_config *our_config UNNEEDED,
			    u32 minimum_depth UNNEEDED,
			    u64 next_index_local UNNEEDED,
			    u64 next_index_remote UNNEEDED,
			    u64 next_htlc_id UNNEEDED,
			    const struct bitcoin_outpoint *funding UNNEEDED,
			    struct amount_sat funding_sats UNNEEDED,
			    struct amount_msat push UNNEEDED,
			    struct amount_sat our_funds UNNEEDED,
			    bool remote_channel_ready UNNEEDED,
			    /* NULL or stolen */
			    struct short_channel_id *scid STEALS UNNEEDED,
			    struct short_channel_id *alias_local STEALS UNNEEDED,
			    struct short_channel_id *alias_remote STEALS UNNEEDED,
			    struct channel_id *cid UNNEEDED,
			    struct amount_msat our_msatoshi UNNEEDED,
			    struct amount_msat msatoshi_to_us_min UNNEEDED,
			    struct amount_msat msatoshi_to_us_max UNNEEDED,
			    struct bitcoin_tx *last_tx STEALS UNNEEDED,
			    const struct bitcoin_signature *last_sig UNNEEDED,
			    /* NULL or stolen */
			    const struct bitcoin_signature *last_htlc_sigs STEALS UNNEEDED,
			    const struct channel_info *channel_info UNNEEDED,
			    const struct fee_states *fee_states TAKES UNNEEDED,
			    /* NULL or stolen */
			    u8 *remote_shutdown_scriptpubkey STEALS UNNEEDED,
			    const u8 *local_shutdown_scriptpubkey UNNEEDED,
			    u64 final_key_idx UNNEEDED,
			    bool last_was_revoke UNNEEDED,
			    /* NULL or stolen */
			    struct changed_htlc *last_sent_commit STEALS UNNEEDED,
			    u32 first_blocknum UNNEEDED,
			    u32 min_possible_feerate UNNEEDED,
			    u32 max_possible_feerate UNNEEDED,
			    const struct basepoints *local_basepoints UNNEEDED,
			    const struct pubkey *local_funding_pubkey UNNEEDED,
			    bool has_future_per_commitment_point UNNEEDED,
			    u32 feerate_base UNNEEDED,
			    u32 feerate_ppm UNNEEDED,
			    /* NULL or stolen */
			    const u8 *remote_upfront_shutdown_script STEALS UNNEEDED,
			    u64 local_static_remotekey_start UNNEEDED,
			    u64 remote_static_remotekey_start UNNEEDED,
			    const struct channel_type *type STEALS UNNEEDED,
			    enum side closer UNNEEDED,
			    u32 close_attempt_height UNNEEDED,
			    enum state_change reason UNNEEDED,
			    /* NULL or stolen */
			    const struct bitcoin_outpoint *shutdown_wrong_funding STEALS UNNEEDED,
			    const struct height_states *height_states TAKES UNNEEDED,
			    u32 lease_expiry UNNEEDED,
			    secp256k1_ecdsa_signature *lease_commit_sig STEALS UNNEEDED,
			    u32 lease_chan_max_msat UNNEEDED,
			    u16 lease_chan_max_ppt UNNEEDED,
			    struct amount_msat htlc_minimum_msat UNNEEDED,
			    struct amount_msat htlc_maximum_msat UNNEEDED,
			    bool ignore_fee_limits UNNEEDED,
			    /* NULL or stolen */
			    struct peer_update *peer_update STEALS UNNEEDED,
			    u64 last_stable_connection UNNEEDED,
			    const struct channel_stats *stats UNNEEDED,
			    struct channel_state_change **state_changes STEALS UNNEEDED)
{ fprintf(stderr, "new_channel called!\n"); abort(); }
/* Generated stub for new_channel_state_change */
struct channel_state_change *new_channel_state_change(const tal_t *ctx UNNEEDED,
						      struct timeabs timestamp UNNEEDED,
						      enum channel_state old_state UNNEEDED,
						      enum channel_state new_state UNNEEDED,
						      enum state_change cause UNNEEDED,
						      const char *message TAKES UNNEEDED)
{ fprintf(stderr, "new_channel_state_change called!\n"); abort(); }
/* Generated stub for new_coin_wallet_deposit */
struct chain_coin_mvt *new_coin_wallet_deposit(const tal_t *ctx UNNEEDED,
					       const struct bitcoin_outpoint *outpoint UNNEEDED,
					       u32 blockheight UNNEEDED,
					       struct amount_sat amount UNNEEDED,
					       enum mvt_tag tag)

{ fprintf(stderr, "new_coin_wallet_deposit called!\n"); abort(); }
/* Generated stub for new_inflight */
struct channel_inflight *new_inflight(struct channel *channel UNNEEDED,
	     struct pubkey *remote_funding STEALS UNNEEDED,
	     const struct bitcoin_outpoint *funding_outpoint UNNEEDED,
	     u32 funding_feerate UNNEEDED,
	     struct amount_sat funding_sat UNNEEDED,
	     struct amount_sat our_funds UNNEEDED,
	     struct wally_psbt *funding_psbt STEALS UNNEEDED,
	     const u32 lease_expiry UNNEEDED,
	     const secp256k1_ecdsa_signature *lease_commit_sig UNNEEDED,
	     const u32 lease_chan_max_msat UNNEEDED,
	     const u16 lease_chan_max_ppt UNNEEDED,
	     const u32 lease_blockheight_start UNNEEDED,
	     const struct amount_msat lease_fee UNNEEDED,
	     const struct amount_sat lease_amt UNNEEDED,
	     s64 splice_amnt UNNEEDED,
	     bool i_am_initiator UNNEEDED,
	     bool force_sign_first UNNEEDED)
{ fprintf(stderr, "new_inflight called!\n"); abort(); }
/* Generated stub for new_logger */
struct logger *new_logger(const tal_t *ctx UNNEEDED, struct log_book *record UNNEEDED,
			  const struct node_id *default_node_id UNNEEDED,
			  const char *fmt UNNEEDED, ...)
{ fprintf(stderr, "new_logger called!\n"); abort(); }
/* Generated stub for new_peer */
struct peer *new_peer(struct lightningd *ld UNNEEDED, u64 dbid UNNEEDED,
		      const struct node_id *id UNNEEDED,
		      const struct wireaddr_internal *addr UNNEEDED,
		      const struct wireaddr *last_known_addr UNNEEDED,
		      const u8 *their_features TAKES UNNEEDED,
		      bool connected_incoming UNNEEDED)
{ fprintf(stderr, "new_peer called!\n"); abort(); }
/* Generated stub for notify_chain_mvt */
void notify_chain_mvt(struct lightningd *ld UNNEEDED, const struct chain_coin_mvt *mvt UNNEEDED)
{ fprintf(stderr, "notify_chain_mvt called!\n"); abort(); }
/* Generated stub for notify_forward_event */
void notify_forward_event(struct lightningd *ld UNNEEDED,
			  const struct htlc_in *in UNNEEDED,
			  /* May be NULL if we don't know. */
			  const struct short_channel_id *scid_out UNNEEDED,
			  /* May be NULL. */
			  const struct amount_msat *amount_out UNNEEDED,
			  enum forward_status state UNNEEDED,
			  enum onion_wire failcode UNNEEDED,
			  struct timeabs *resolved_time UNNEEDED,
			  enum forward_style forward_style UNNEEDED,
			  u64 created_index UNNEEDED,
			  u64 updated_index UNNEEDED)
{ fprintf(stderr, "notify_forward_event called!\n"); abort(); }
/* Generated stub for onion_wire_name */
const char *onion_wire_name(int e UNNEEDED)
{ fprintf(stderr, "onion_wire_name called!\n"); abort(); }
/* Generated stub for outpointfilter_add */
void outpointfilter_add(struct outpointfilter *of UNNEEDED,
			const struct bitcoin_outpoint *outpoint UNNEEDED)
{ fprintf(stderr, "outpointfilter_add called!\n"); abort(); }
/* Generated stub for outpointfilter_matches */
bool outpointfilter_matches(struct outpointfilter *of UNNEEDED,
			    const struct bitcoin_outpoint *outpoint UNNEEDED)
{ fprintf(stderr, "outpointfilter_matches called!\n"); abort(); }
/* Generated stub for outpointfilter_new */
struct outpointfilter *outpointfilter_new(tal_t *ctx UNNEEDED)
{ fprintf(stderr, "outpointfilter_new called!\n"); abort(); }
/* Generated stub for outpointfilter_remove */
void outpointfilter_remove(struct outpointfilter *of UNNEEDED,
			   const struct bitcoin_outpoint *outpoint UNNEEDED)
{ fprintf(stderr, "outpointfilter_remove called!\n"); abort(); }
/* Generated stub for peer_set_dbid */
void peer_set_dbid(struct peer *peer UNNEEDED, u64 dbid UNNEEDED)
{ fprintf(stderr, "peer_set_dbid called!\n"); abort(); }
/* Generated stub for psbt_fixup */
const u8 *psbt_fixup(const tal_t *ctx UNNEEDED, const u8 *psbtblob UNNEEDED)
{ fprintf(stderr, "psbt_fixup called!\n"); abort(); }
/* Generated stub for remove_htlc_in_by_dbid */
struct htlc_in *remove_htlc_in_by_dbid(struct htlc_in_map *remaining_htlcs_in UNNEEDED,
				       u64 dbid UNNEEDED)
{ fprintf(stderr, "remove_htlc_in_by_dbid called!\n"); abort(); }
/* Generated stub for rune_unique_id */
u64 rune_unique_id(const struct rune *rune UNNEEDED)
{ fprintf(stderr, "rune_unique_id called!\n"); abort(); }
/* Generated stub for sendpay_index_created */
u64 sendpay_index_created(struct lightningd *ld UNNEEDED,
			  const struct sha256 *payment_hash UNNEEDED,
			  u64 partid UNNEEDED,
			  u64 groupid UNNEEDED,
			  enum payment_status status UNNEEDED)
{ fprintf(stderr, "sendpay_index_created called!\n"); abort(); }
/* Generated stub for sendpay_index_deleted */
void sendpay_index_deleted(struct lightningd *ld UNNEEDED,
			   const struct sha256 *payment_hash UNNEEDED,
			   u64 partid UNNEEDED,
			   u64 groupid UNNEEDED,
			   enum payment_status status UNNEEDED)
{ fprintf(stderr, "sendpay_index_deleted called!\n"); abort(); }
/* Generated stub for sendpay_index_update_status */
u64 sendpay_index_update_status(struct lightningd *ld UNNEEDED,
				const struct sha256 *payment_hash UNNEEDED,
				u64 partid UNNEEDED,
				u64 groupid UNNEEDED,
				enum payment_status status UNNEEDED)
{ fprintf(stderr, "sendpay_index_update_status called!\n"); abort(); }
/* Generated stub for to_canonical_invstr */
const char *to_canonical_invstr(const tal_t *ctx UNNEEDED, const char *invstring UNNEEDED)
{ fprintf(stderr, "to_canonical_invstr called!\n"); abort(); }
/* Generated stub for towire_hsmd_get_channel_basepoints */
u8 *towire_hsmd_get_channel_basepoints(const tal_t *ctx UNNEEDED, const struct node_id *peerid UNNEEDED, u64 dbid UNNEEDED)
{ fprintf(stderr, "towire_hsmd_get_channel_basepoints called!\n"); abort(); }
/* Generated stub for towire_hsmd_get_output_scriptpubkey */
u8 *towire_hsmd_get_output_scriptpubkey(const tal_t *ctx UNNEEDED, u64 channel_id UNNEEDED, const struct node_id *peer_id UNNEEDED, const struct pubkey *commitment_point UNNEEDED)
{ fprintf(stderr, "towire_hsmd_get_output_scriptpubkey called!\n"); abort(); }
/* Generated stub for towire_temporary_node_failure */
u8 *towire_temporary_node_failure(const tal_t *ctx UNNEEDED)
{ fprintf(stderr, "towire_temporary_node_failure called!\n"); abort(); }
/* Generated stub for txfilter_add_scriptpubkey */
void txfilter_add_scriptpubkey(struct txfilter *filter UNNEEDED, const u8 *script TAKES UNNEEDED)
{ fprintf(stderr, "txfilter_add_scriptpubkey called!\n"); abort(); }
/* Generated stub for wait_index_name */
const char *wait_index_name(enum wait_index index UNNEEDED)
{ fprintf(stderr, "wait_index_name called!\n"); abort(); }
/* Generated stub for wait_subsystem_name */
const char *wait_subsystem_name(enum wait_subsystem subsystem UNNEEDED)
{ fprintf(stderr, "wait_subsystem_name called!\n"); abort(); }
/* Generated stub for wire_sync_read */
u8 *wire_sync_read(const tal_t *ctx UNNEEDED, int fd UNNEEDED)
{ fprintf(stderr, "wire_sync_read called!\n"); abort(); }
/* Generated stub for wire_sync_write */
bool wire_sync_write(int fd UNNEEDED, const void *msg TAKES UNNEEDED)
{ fprintf(stderr, "wire_sync_write called!\n"); abort(); }
/* AUTOGENERATED MOCKS END */

void plugin_hook_db_sync(struct db *db UNNEEDED)
{
}

static struct db *create_test_db(void)
{
	struct db *db;
	char *dsn, *filename;

	int fd = tmpdir_mkstemp(tmpctx, "ldb-XXXXXX", &filename);
	if (fd == -1)
		return NULL;
	close(fd);

	dsn = tal_fmt(NULL, "sqlite3://%s", filename);
	tal_free(filename);
	db = db_open(NULL, dsn, true, db_error, (struct lightningd *)NULL);
	db->data_version = 0;
	db->report_changes_fn = NULL;

	tal_free(dsn);
	return db;
}

static bool test_empty_db_migrate(struct lightningd *ld)
{
	struct db *db = create_test_db();
	const struct ext_key *bip32_base = NULL;
	CHECK(db);
	db_begin_transaction(db);
	CHECK(db_get_version(db) == -1);
	db_migrate(ld, db, bip32_base);
	db_commit_transaction(db);

	db_begin_transaction(db);
	CHECK(db_get_version(db) == ARRAY_SIZE(dbmigrations) - 1);
	db_commit_transaction(db);

	tal_free(db);
	return true;
}

static bool test_primitives(void)
{
	struct db_stmt *stmt;
	struct db *db = create_test_db();

	db_begin_transaction(db);
	CHECK(db->in_transaction);
	db_commit_transaction(db);
	CHECK(!db->in_transaction);
	db_begin_transaction(db);
	db_commit_transaction(db);

	db_begin_transaction(db);
	stmt = db_prepare_v2(db, SQL("SELECT name FROM sqlite_master WHERE type='table';"));
	db_exec_prepared_v2(stmt);
	tal_free(stmt);

	/* We didn't migrate the DB, so don't have the vars table. Pretend we
	 * didn't change anything so we don't bump the data_version. */
	db->dirty = false;
	db_commit_transaction(db);
	CHECK(!db->in_transaction);
	tal_free(db);

	return true;
}

static bool test_vars(struct lightningd *ld)
{
	struct db *db = create_test_db();
	char *varname = "testvar";
	const struct ext_key *bip32_base = NULL;
	CHECK(db);

	db_begin_transaction(db);
	db_migrate(ld, db, bip32_base);
	/* Check default behavior */
	CHECK(db_get_intvar(db, varname, 42) == 42);

	/* Check setting and getting */
	db_set_intvar(db, varname, 1);
	CHECK(db_get_intvar(db, varname, 42) == 1);

	/* Check updating */
	db_set_intvar(db, varname, 2);
	CHECK(db_get_intvar(db, varname, 42) == 2);
	db_commit_transaction(db);

	tal_free(db);
	return true;
}

static bool test_manip_columns(void)
{
	struct db_stmt *stmt;
	struct db *db = create_test_db();
	const char *field1 = "field1";

	db_begin_transaction(db);
	/* tablea refers to tableb */
	stmt = db_prepare_v2(db, SQL("CREATE TABLE tablea ("
				     "  id BIGSERIAL"
				     ", field1 INTEGER"
				     ", PRIMARY KEY (id))"));
	db_exec_prepared_v2(stmt);
	tal_free(stmt);

	stmt = db_prepare_v2(db, SQL("INSERT INTO tablea (id, field1) VALUES (0, 1);"));
	db_exec_prepared_v2(stmt);
	tal_free(stmt);

	stmt = db_prepare_v2(db, SQL("CREATE TABLE tableb ("
				     "   id REFERENCES tablea(id) ON DELETE CASCADE"
				     ",  field1 INTEGER"
				     ",  field2 INTEGER);"));
	db_exec_prepared_v2(stmt);
	tal_free(stmt);

	stmt = db_prepare_v2(db, SQL("INSERT INTO tableb (id, field1, field2) VALUES (0, 1, 2);"));
	db_exec_prepared_v2(stmt);
	tal_free(stmt);

	/* Needs vars table, since this changes db. */
	stmt = db_prepare_v2(db, SQL("CREATE TABLE vars (name VARCHAR(32), intval);"));
	db_exec_prepared_v2(stmt);
	tal_free(stmt);
	stmt = db_prepare_v2(db, SQL("INSERT INTO vars VALUES ('data_version', 0);"));
	db_exec_prepared_v2(stmt);
	tal_free(stmt);

	/* Rename tablea.field1 -> table1.field1a. */
	CHECK(db->config->rename_column(db, "tablea", "field1", "field1a"));
	/* Remove tableb.field1. */
	CHECK(db->config->delete_columns(db, "tableb", &field1, 1));

	stmt = db_prepare_v2(db, SQL("SELECT id, field1a FROM tablea;"));
	CHECK_MSG(db_query_prepared_canfail(stmt), "db_query_prepared must succeed");
	CHECK(db_step(stmt));
	CHECK(db_col_u64(stmt, "id") == 0);
	CHECK(db_col_u64(stmt, "field1a") == 1);
	CHECK(!db_step(stmt));
	tal_free(stmt);

	stmt = db_prepare_v2(db, SQL("SELECT id, field2 FROM tableb;"));
	CHECK_MSG(db_query_prepared_canfail(stmt), "db_query_prepared must succeed");
	CHECK(db_step(stmt));
	CHECK(db_col_u64(stmt, "id") == 0);
	CHECK(db_col_u64(stmt, "field2") == 2);
	CHECK(!db_step(stmt));
	tal_free(stmt);
	db->dirty = false;
	db->changes = tal_arr(db, const char *, 0);
	db_commit_transaction(db);

	db_begin_transaction(db);
	/* This will actually fail */
	stmt = db_prepare_v2(db, SQL("SELECT field1 FROM tablea;"));
	CHECK_MSG(!db_query_prepared_canfail(stmt), "db_query_prepared must fail");
	db->dirty = false;
	db->changes = tal_arr(db, const char *, 0);
	db_commit_transaction(db);

	db_begin_transaction(db);
	/* This will actually fail */
	stmt = db_prepare_v2(db, SQL("SELECT field1 FROM tableb;"));
	CHECK_MSG(!db_query_prepared_canfail(stmt), "db_query_prepared must fail");
	db->dirty = false;
	db->changes = tal_arr(db, const char *, 0);
	db_commit_transaction(db);

	tal_free(db);
	return true;
}

int main(int argc, char *argv[])
{
	bool ok = true;
	/* Dummy for migration hooks */
	struct lightningd *ld = tal(NULL, struct lightningd);

	common_setup(argv[0]);
	ld->config = test_config;

	/* We do a runtime test here, so we still check compile! */
	if (HAVE_SQLITE3) {
		ok &= test_empty_db_migrate(ld);
		ok &= test_vars(ld);
		ok &= test_primitives();
		ok &= test_manip_columns();
	}

	tal_free(ld);
	common_shutdown();
	trace_cleanup();
	return !ok;
}
