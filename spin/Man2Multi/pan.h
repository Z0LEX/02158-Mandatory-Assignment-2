#define SpinVersion	"Spin Version 6.1.0 -- 4 May 2011"
#define PanSource	"Man2Safe-fair.pml"

#define G_long	8
#define G_int	4
#ifdef WIN64
	#define ONE_L	((unsigned long) 1)
	#define long	long long
#else
	#define ONE_L	(1L)
#endif
char *TrailFile = PanSource; /* default */
char *trailfilename;
#if defined(BFS)
	#ifndef SAFETY
		#define SAFETY
	#endif
	#ifndef XUSAFE
		#define XUSAFE
	#endif
#endif
#ifndef uchar
	#define uchar	unsigned char
#endif
#ifndef uint
	#define uint	unsigned int
#endif
#if !defined(HASH32) && !defined(HASH64)
	#define HASH64
#endif
#define DELTA	500
#ifdef MA
	#if NCORE>1 && !defined(SEP_STATE)
	#define SEP_STATE
	#endif
#if MA==1
	#undef MA
	#define MA	100
#endif
#endif
#ifdef W_XPT
	#if W_XPT==1
		#undef W_XPT
		#define W_XPT 1000000
	#endif
#endif
#ifndef NFAIR
	#define NFAIR	2	/* must be >= 2 */
#endif
#define REM_REFS	6
#define HAS_CODE
#if defined(RANDSTORE) && !defined(RANDSTOR)
	#define RANDSTOR	RANDSTORE
#endif
#define MERGED	1
#if !defined(HAS_LAST) && defined(BCS)
	#define HAS_LAST	1 /* use it, but */
	#ifndef STORE_LAST
		#define NO_LAST	1 /* dont store it */
	#endif
#endif
#if defined(BCS) && defined(BITSTATE)
	#ifndef NO_CTX
		#define STORE_CTX	1
	#endif
#endif
#ifdef NP
	#define HAS_NP	2
	#define VERI	2	/* np_ */
#endif
#ifndef NOCLAIM
	#define NCLAIMS	1
	#ifndef NP
		#define VERI	1
	#endif
#endif
typedef struct S_F_MAP {
	char *fnm; int from; int upto;
} S_F_MAP;

#define nstates1	17	/* fejl */
#define endstate1	16
short src_ln1 [] = {
	  0,   3,   3,   4,   4,   5,   5,   2, 
	  7,   9,   9,  10,  10,   8,  12,  13, 
	 14,   0, };
S_F_MAP src_file1 [] = {
	{ "-", 0, 0 },
	{ "_spin_nvr.tmp", 1, 16 },
	{ "-", 17, 18 }
};
short *src_claim;
uchar reached1 [] = {
	  0,   1,   1,   1,   1,   1,   1,   0, 
	  1,   1,   1,   1,   1,   0,   1,   1, 
	  0,   0, };
uchar *loopstate1;

#define nstates0	83	/* Car */
#define endstate0	82
short src_ln0 [] = {
	  0,  20,  20,  21,  21,  25,  25,  25, 
	 25,  27,  27,  27,  30,  30,  30,  30, 
	 30,  31,  31,  31,  29,  33,  34,  34, 
	 36,  36,  37,  37,  37,  37,  39,  39, 
	 39,  42,  42,  42,  42,  42,  43,  43, 
	 43,  41,  45,  46,  46,  48,  48,  24, 
	 51,  53,  53,  55,  55,  55,  58,  58, 
	 58,  59,  59,  57,  61,  62,  62,  63, 
	 65,  65,  65,  66,  68,  68,  68,  69, 
	 69,  67,  71,  71,  71,  52,  73,  19, 
	 74,  19,  74,   0, };
S_F_MAP src_file0 [] = {
	{ "-", 0, 0 },
	{ "Man2Safe-fair.pml", 1, 82 },
	{ "-", 83, 84 }
};
uchar reached0 [] = {
	  0,   1,   0,   1,   1,   1,   1,   0, 
	  0,   1,   0,   0,   1,   1,   0,   0, 
	  0,   1,   0,   1,   0,   1,   1,   0, 
	  1,   0,   1,   1,   0,   0,   1,   0, 
	  0,   1,   1,   0,   0,   0,   1,   0, 
	  1,   0,   1,   1,   0,   1,   0,   0, 
	  1,   1,   1,   1,   0,   0,   1,   1, 
	  0,   1,   1,   0,   1,   1,   0,   1, 
	  1,   0,   0,   0,   1,   1,   0,   1, 
	  1,   0,   1,   1,   0,   0,   1,   0, 
	  1,   1,   0,   0, };
uchar *loopstate0;
struct {
	int tp; short *src;
} src_all[] = {
	{ 1, &src_ln1[0] },
	{ 0, &src_ln0[0] },
	{ 0, (short *) 0 }
};
S_F_MAP *flref[] = {
	src_file1,
	src_file0 
};
struct {
	char *c; char *t;
} code_lookup[] = {
	{ (char *) 0, "" }
};
#define _T5	38
#define _T2	39
#define T_ID	unsigned char
#define WS		8 /* word size in bytes */
#define SYNC	0
#define ASYNC	0

#ifndef NCORE
	#ifdef DUAL_CORE
		#define NCORE	2
	#elif QUAD_CORE
		#define NCORE	4
	#else
		#define NCORE	1
	#endif
#endif
char *procname[] = {
   "Car",
   "fejl",
   ":np_:",
};

enum btypes { NONE=0, N_CLAIM=1, I_PROC=2, A_PROC=3, P_PROC=4, E_TRACE=5, N_TRACE=6 };
int Btypes[] = {
   3,	/* Car */
   1,	/* fejl */
   0	/* :np_: */
};

typedef struct P1 { /* fejl */
	unsigned _pid : 8;  /* 0..255 */
	unsigned _t   : 3; /* proctype */
	unsigned _p   : 8; /* state    */
} P1;
#define Air1	(sizeof(P1) - 3)
#define PCar	((P0 *)this)
typedef struct P0 { /* Car */
	unsigned _pid : 8;  /* 0..255 */
	unsigned _t   : 3; /* proctype */
	unsigned _p   : 8; /* state    */
	int _1_temp;
} P0;
#define Air0	(sizeof(P0) - Offsetof(P0, _1_temp) - 1*sizeof(int))
typedef struct P2 { /* np_ */
	unsigned _pid : 8;  /* 0..255 */
	unsigned _t   : 3; /* proctype */
	unsigned _p   : 8; /* state    */
} P2;
#define Air2	(sizeof(P2) - 3)

#define Pclaim	P0
#ifndef NCLAIMS
	#define NCLAIMS 1
#endif
uchar spin_c_typ[NCLAIMS]; /* claim-types */
#if defined(BFS) && defined(REACH)
	#undef REACH
#endif
#ifdef VERI
	#define BASE	1
#else
	#define BASE	0
#endif
typedef struct Trans {
	short atom;	/* if &2 = atomic trans; if &8 local */
#ifdef HAS_UNLESS
	short escp[HAS_UNLESS];	/* lists the escape states */
	short e_trans;	/* if set, this is an escp-trans */
#endif
	short tpe[2];	/* class of operation (for reduction) */
	short qu[6];	/* for conditional selections: qid's  */
	uchar ty[6];	/* ditto: type's */
#ifdef NIBIS
	short om;	/* completion status of preselects */
#endif
	char *tp;	/* src txt of statement */
	int st;		/* the nextstate */
	int t_id;	/* transition id, unique within proc */
	int forw;	/* index forward transition */
	int back;	/* index return  transition */
	struct Trans *nxt;
} Trans;

#ifdef TRIX
	#define qptr(x)	(channels[x]->body)
	#define pptr(x)	(processes[x]->body)
#else
	#define qptr(x)	(((uchar *)&now)+(int)q_offset[x])
	#define pptr(x)	(((uchar *)&now)+(int)proc_offset[x])
#endif
extern uchar *Pptr(int);
extern uchar *Qptr(int);
#define q_sz(x)	(((Q0 *)qptr(x))->Qlen)

#ifdef TRIX
	#ifdef VECTORSZ
		#undef VECTORSZ
	#endif
	#if WS==4
		#define VECTORSZ	2056	/* ((MAXPROC+MAXQ+4)*sizeof(uchar *)) */
	#else
		#define VECTORSZ	4112	/* the formula causes probs in preprocessing */
	#endif
#else
	#ifndef VECTORSZ
		#define VECTORSZ	1024	/* sv size in bytes */
	#endif
#endif

#ifdef VERBOSE
	#ifndef CHECK
		#define CHECK
	#endif
	#ifndef DEBUG
		#define DEBUG
	#endif
#endif
#ifdef SAFETY
	#ifndef NOFAIR
		#define NOFAIR
	#endif
#endif
#ifdef NOREDUCE
	#ifndef XUSAFE
		#define XUSAFE
	#endif
	#if !defined(SAFETY) && !defined(MA)
		#define FULLSTACK
	#endif
#else
	#ifdef BITSTATE
		#if defined(SAFETY) && !defined(HASH64)
			#define CNTRSTACK
		#else
			#define FULLSTACK
		#endif
	#else
		#define FULLSTACK
	#endif
#endif
#ifdef BITSTATE
	#ifndef NOCOMP
		#define NOCOMP
	#endif
	#if !defined(LC) && defined(SC)
		#define LC
	#endif
#endif
#if defined(COLLAPSE2) || defined(COLLAPSE3) || defined(COLLAPSE4)
	/* accept the above for backward compatibility */
	#define COLLAPSE
#endif
#ifdef HC
	#undef HC
	#define HC4
#endif
#ifdef HC0
	#define HC	0
#endif
#ifdef HC1
	#define HC	1
#endif
#ifdef HC2
	#define HC	2
#endif
#ifdef HC3
	#define HC	3
#endif
#ifdef HC4
	#define HC	4
#endif
#ifdef COLLAPSE
	#if NCORE>1 && !defined(SEP_STATE)
		unsigned long *ncomps;	/* in shared memory */
	#else
		unsigned long ncomps[256+2];
	#endif
#endif
#define MAXQ   	255
#define MAXPROC	255

typedef struct _Stack  {	 /* for queues and processes */
#if VECTORSZ>32000
	int o_delta;
	#ifndef TRIX
		int o_offset;
		int o_skip;
	#endif
	int o_delqs;
#else
	short o_delta;
	#ifndef TRIX
		short o_offset;
		short o_skip;
	#endif
	short o_delqs;
#endif
	short o_boq;
#ifdef TRIX
	short parent;
	char *b_ptr;
#else
	char *body;
#endif
#ifndef XUSAFE
	char *o_name;
#endif
	struct _Stack *nxt;
	struct _Stack *lst;
} _Stack;

typedef struct Svtack { /* for complete state vector */
#if VECTORSZ>32000
	int o_delta;
	int m_delta;
#else
	short o_delta;	 /* current size of frame */
	short m_delta;	 /* maximum size of frame */
#endif
#if SYNC
	short o_boq;
#endif
#define StackSize	(WS)
	char *body;
	struct Svtack *nxt;
	struct Svtack *lst;
} Svtack;

Trans ***trans;	/* 1 ptr per state per proctype */

struct H_el *Lstate;
int depthfound = -1;	/* loop detection */
#ifndef TRIX
	#if VECTORSZ>32000
		int proc_offset[MAXPROC];
		int q_offset[MAXQ];
	#else
		short proc_offset[MAXPROC];
		short q_offset[MAXQ];
	#endif
	uchar proc_skip[MAXPROC];
	uchar q_skip[MAXQ];
#endif
unsigned long  vsize;	/* vector size in bytes */
#ifdef SVDUMP
	int vprefix=0, svfd;	/* runtime option -pN */
#endif
char *tprefix = "trail";	/* runtime option -tsuffix */
short boq = -1;		/* blocked_on_queue status */
typedef struct State {
	uchar _nr_pr;
	uchar _nr_qs;
	uchar   _a_t;	/* cycle detection */
#ifndef NOFAIR
	uchar   _cnt[NFAIR];	/* counters, weak fairness */
#endif
#ifndef NOVSZ
#if VECTORSZ<65536
	unsigned short _vsz;
#else
	unsigned long  _vsz;
#endif
#endif
#ifdef HAS_LAST
	uchar  _last;	/* pid executed in last step */
#endif
#if defined(BITSTATE) && defined(BCS) && defined(STORE_CTX)
	uchar  _ctx;	/* nr of context switches so far */
#endif
#ifdef EVENT_TRACE
	#if nstates_event<256
		uchar _event;
	#else
		unsigned short _event;
	#endif
#endif
	int upSem;
	int downSem;
	int up;
	int down;
	int inDownSem;
	int inUpSem;
#ifdef TRIX
	/* room for 512 proc+chan ptrs, + safety margin */
	char *_ids_[MAXPROC+MAXQ+4];
#else
	uchar sv[VECTORSZ];
#endif
} State;

#ifdef TRIX
typedef struct TRIX_v6 {
	uchar *body; /* aligned */
#ifndef BFS
	short modified;
#endif
	short psize;
	short parent_pid;
	struct TRIX_v6 *nxt;
} TRIX_v6;
TRIX_v6 *freebodies;
TRIX_v6 *processes[MAXPROC+1];
TRIX_v6 *channels[MAXQ+1]; 
long _p_count[MAXPROC];
long _c_count[MAXPROC];
#endif

#define HAS_TRACK	0
int _; /* a predefined write-only variable */

#define FORWARD_MOVES	"pan.m"
#define REVERSE_MOVES	"pan.b"
#define TRANSITIONS	"pan.t"
#define _NP_	2
uchar reached2[3];  /* np_ */
uchar *loopstate2;  /* np_ */
#define nstates2	3 /* np_ */
#define endstate2	2 /* np_ */

#define start2	0 /* np_ */
#define start1	7
#define start0	79
#ifdef NP
	#define ACCEPT_LAB	1 /* at least 1 in np_ */
#else
	#define ACCEPT_LAB	1 /* user-defined accept labels */
#endif
#ifdef MEMCNT
	#ifdef MEMLIM
		#warning -DMEMLIM takes precedence over -DMEMCNT
		#undef MEMCNT
	#else
		#if MEMCNT<20
			#warning using minimal value -DMEMCNT=20 (=1MB)
			#define MEMLIM	(1)
			#undef MEMCNT
		#else
			#if MEMCNT==20
				#define MEMLIM	(1)
				#undef MEMCNT
			#else
			 #if MEMCNT>=50
				#error excessive value for MEMCNT
			 #else
				#define MEMLIM	(1<<(MEMCNT-20))
			 #endif
			#endif
		#endif
	#endif
#endif
#if NCORE>1 && !defined(MEMLIM)
	#define MEMLIM	(2048)	/* need a default, using 2 GB */
#endif
#define PROG_LAB	0 /* progress labels */
uchar *accpstate[3];
uchar *progstate[3];
uchar *loopstate[3];
uchar *reached[3];
uchar *stopstate[3];
uchar *visstate[3];
short *mapstate[3];
#ifdef HAS_CODE
	int NrStates[3];
#endif
#define NQS	0
short q_flds[1];
short q_max[1];
typedef struct Q0 {	/* generic q */
	uchar Qlen;	/* q_size */
	uchar _t;
} Q0;

/** function prototypes **/
char *emalloc(unsigned long);
char *Malloc(unsigned long);
int Boundcheck(int, int, int, int, Trans *);
int addqueue(int, int, int);
/* int atoi(char *); */
/* int abort(void); */
int close(int);
int delproc(int, int);
int endstate(void);
int hstore(char *, int);
#ifdef MA
int gstore(char *, int, uchar);
#endif
int q_cond(short, Trans *);
int q_full(int);
int q_len(int);
int q_zero(int);
int qrecv(int, int, int, int);
int unsend(int);
/* void *sbrk(int); */
void Uerror(char *);
void spin_assert(int, char *, int, int, Trans *);
void c_chandump(int);
void c_globals(void);
void c_locals(int, int);
void checkcycles(void);
void crack(int, int, Trans *, short *);
void d_sfh(const char *, int);
void sfh(const char *, int);
void d_hash(uchar *, int);
void s_hash(uchar *, int);
void r_hash(uchar *, int);
void delq(int);
void dot_crack(int, int, Trans *);
void do_reach(void);
void pan_exit(int);
void exit(int);
void hinit(void);
void imed(Trans *, int, int, int);
void new_state(void);
void p_restor(int);
void putpeg(int, int);
void putrail(void);
void q_restor(void);
void retrans(int, int, int, short *, uchar *, uchar *);
void settable(void);
void setq_claim(int, int, char *, int, char *);
void sv_restor(void);
void sv_save(void);
void tagtable(int, int, int, short *, uchar *);
void do_dfs(int, int, int, short *, uchar *, uchar *);
void uerror(char *);
void unrecv(int, int, int, int, int);
void usage(FILE *);
void wrap_stats(void);
#if defined(FULLSTACK) && defined(BITSTATE)
	int  onstack_now(void);
	void onstack_init(void);
	void onstack_put(void);
	void onstack_zap(void);
#endif
#ifndef XUSAFE
	int q_S_check(int, int);
	int q_R_check(int, int);
	uchar q_claim[MAXQ+1];
	char *q_name[MAXQ+1];
	char *p_name[MAXPROC+1];
#endif
void qsend(int, int, int);
#define Addproc(x)	addproc(256, x)
#define LOCAL	1
#define Q_FULL_F	2
#define Q_EMPT_F	3
#define Q_EMPT_T	4
#define Q_FULL_T	5
#define TIMEOUT_F	6
#define GLOBAL	7
#define BAD	8
#define ALPHA_F	9
#define NTRANS	40
#ifdef PEG
	long peg[NTRANS];
#endif
void select_claim(int);
