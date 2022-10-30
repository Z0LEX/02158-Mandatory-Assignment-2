#define rand	pan_rand
#if defined(HAS_CODE) && defined(VERBOSE)
	cpu_printf("Pr: %d Tr: %d\n", II, t->forw);
#endif
	switch (t->forw) {
	default: Uerror("bad forward move");
	case 0:	/* if without executable clauses */
		continue;
	case 1: /* generic 'goto' or 'skip' */
		IfNotBlocked
		_m = 3; goto P999;
	case 2: /* generic 'else' */
		IfNotBlocked
		if (trpt->o_pm&1) continue;
		_m = 3; goto P999;

		 /* PROC Check */
	case 3: /* STATE 1 - Man2Safe.pml:84 - [(!(!(((up>0)&&(down>0)))))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][1] = 1;
		if (!( !( !(((now.up>0)&&(now.down>0))))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 4: /* STATE 2 - Man2Safe.pml:84 - [assert(!(((up>0)&&(down>0))))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][2] = 1;
		spin_assert( !(((now.up>0)&&(now.down>0))), " !(((up>0)&&(down>0)))", II, tt, t);
		_m = 3; goto P999; /* 0 */
	case 5: /* STATE 3 - Man2Safe.pml:85 - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][3] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC Car */
	case 6: /* STATE 1 - Man2Safe.pml:18 - [((_pid==0))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][1] = 1;
		if (!((((int)((P0 *)this)->_pid)==0)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 7: /* STATE 3 - Man2Safe.pml:19 - [((_pid>0))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][3] = 1;
		if (!((((int)((P0 *)this)->_pid)>0)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 8: /* STATE 5 - Man2Safe.pml:24 - [((_pid<5))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][5] = 1;
		if (!((((int)((P0 *)this)->_pid)<5)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 9: /* STATE 7 - Man2Safe.pml:27 - [((inDownSem>0))] (28:0:1 - 1) */
		IfNotBlocked
		reached[0][7] = 1;
		if (!((now.inDownSem>0)))
			continue;
		/* merge: inDownSem = (inDownSem-1)(0, 8, 28) */
		reached[0][8] = 1;
		(trpt+1)->bup.oval = now.inDownSem;
		now.inDownSem = (now.inDownSem-1);
#ifdef VAR_RANGES
		logval("inDownSem", now.inDownSem);
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 10: /* STATE 10 - Man2Safe.pml:29 - [((turn==-(1)))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][10] = 1;
		if (!((now.turn== -(1))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 11: /* STATE 11 - Man2Safe.pml:29 - [((turnSem>0))] (22:0:1 - 1) */
		IfNotBlocked
		reached[0][11] = 1;
		if (!((now.turnSem>0)))
			continue;
		/* merge: turnSem = (turnSem-1)(0, 12, 22) */
		reached[0][12] = 1;
		(trpt+1)->bup.oval = now.turnSem;
		now.turnSem = (now.turnSem-1);
#ifdef VAR_RANGES
		logval("turnSem", now.turnSem);
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 12: /* STATE 14 - Man2Safe.pml:31 - [((turn==-(1)))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][14] = 1;
		if (!((now.turn== -(1))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 13: /* STATE 15 - Man2Safe.pml:31 - [turn = 0] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][15] = 1;
		(trpt+1)->bup.oval = now.turn;
		now.turn = 0;
#ifdef VAR_RANGES
		logval("turn", now.turn);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 14: /* STATE 16 - Man2Safe.pml:31 - [turnSem = (turnSem+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][16] = 1;
		(trpt+1)->bup.oval = now.turnSem;
		now.turnSem = (now.turnSem+1);
#ifdef VAR_RANGES
		logval("turnSem", now.turnSem);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 15: /* STATE 20 - Man2Safe.pml:32 - [turnSem = (turnSem+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][20] = 1;
		(trpt+1)->bup.oval = now.turnSem;
		now.turnSem = (now.turnSem+1);
#ifdef VAR_RANGES
		logval("turnSem", now.turnSem);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 16: /* STATE 24 - Man2Safe.pml:34 - [((turn==0))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][24] = 1;
		if (!((now.turn==0)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 17: /* STATE 26 - Man2Safe.pml:35 - [((turn==1))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][26] = 1;
		if (!((now.turn==1)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 18: /* STATE 30 - Man2Safe.pml:37 - [inDownSem = (inDownSem+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][30] = 1;
		(trpt+1)->bup.oval = now.inDownSem;
		now.inDownSem = (now.inDownSem+1);
#ifdef VAR_RANGES
		logval("inDownSem", now.inDownSem);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 19: /* STATE 35 - Man2Safe.pml:40 - [down = (down+1)] (0:0:1 - 5) */
		IfNotBlocked
		reached[0][35] = 1;
		(trpt+1)->bup.oval = now.down;
		now.down = (now.down+1);
#ifdef VAR_RANGES
		logval("down", now.down);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 20: /* STATE 36 - Man2Safe.pml:41 - [inDownSem = (inDownSem+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][36] = 1;
		(trpt+1)->bup.oval = now.inDownSem;
		now.inDownSem = (now.inDownSem+1);
#ifdef VAR_RANGES
		logval("inDownSem", now.inDownSem);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 21: /* STATE 40 - Man2Safe.pml:46 - [((inUpSem>0))] (61:0:1 - 1) */
		IfNotBlocked
		reached[0][40] = 1;
		if (!((now.inUpSem>0)))
			continue;
		/* merge: inUpSem = (inUpSem-1)(0, 41, 61) */
		reached[0][41] = 1;
		(trpt+1)->bup.oval = now.inUpSem;
		now.inUpSem = (now.inUpSem-1);
#ifdef VAR_RANGES
		logval("inUpSem", now.inUpSem);
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 22: /* STATE 43 - Man2Safe.pml:48 - [((turn==-(1)))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][43] = 1;
		if (!((now.turn== -(1))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 23: /* STATE 44 - Man2Safe.pml:48 - [((turnSem>0))] (55:0:1 - 1) */
		IfNotBlocked
		reached[0][44] = 1;
		if (!((now.turnSem>0)))
			continue;
		/* merge: turnSem = (turnSem-1)(0, 45, 55) */
		reached[0][45] = 1;
		(trpt+1)->bup.oval = now.turnSem;
		now.turnSem = (now.turnSem-1);
#ifdef VAR_RANGES
		logval("turnSem", now.turnSem);
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 24: /* STATE 47 - Man2Safe.pml:50 - [((turn==-(1)))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][47] = 1;
		if (!((now.turn== -(1))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 25: /* STATE 48 - Man2Safe.pml:50 - [turn = 1] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][48] = 1;
		(trpt+1)->bup.oval = now.turn;
		now.turn = 1;
#ifdef VAR_RANGES
		logval("turn", now.turn);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 26: /* STATE 49 - Man2Safe.pml:50 - [turnSem = (turnSem+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][49] = 1;
		(trpt+1)->bup.oval = now.turnSem;
		now.turnSem = (now.turnSem+1);
#ifdef VAR_RANGES
		logval("turnSem", now.turnSem);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 27: /* STATE 53 - Man2Safe.pml:51 - [turnSem = (turnSem+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][53] = 1;
		(trpt+1)->bup.oval = now.turnSem;
		now.turnSem = (now.turnSem+1);
#ifdef VAR_RANGES
		logval("turnSem", now.turnSem);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 28: /* STATE 57 - Man2Safe.pml:53 - [((turn==0))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][57] = 1;
		if (!((now.turn==0)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 29: /* STATE 59 - Man2Safe.pml:54 - [((turn==1))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][59] = 1;
		if (!((now.turn==1)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 30: /* STATE 63 - Man2Safe.pml:56 - [inUpSem = (inUpSem+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][63] = 1;
		(trpt+1)->bup.oval = now.inUpSem;
		now.inUpSem = (now.inUpSem+1);
#ifdef VAR_RANGES
		logval("inUpSem", now.inUpSem);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 31: /* STATE 68 - Man2Safe.pml:59 - [up = (up+1)] (0:0:1 - 5) */
		IfNotBlocked
		reached[0][68] = 1;
		(trpt+1)->bup.oval = now.up;
		now.up = (now.up+1);
#ifdef VAR_RANGES
		logval("up", now.up);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 32: /* STATE 69 - Man2Safe.pml:60 - [inUpSem = (inUpSem+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][69] = 1;
		(trpt+1)->bup.oval = now.inUpSem;
		now.inUpSem = (now.inUpSem+1);
#ifdef VAR_RANGES
		logval("inUpSem", now.inUpSem);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 33: /* STATE 73 - Man2Safe.pml:65 - [((_pid<5))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][73] = 1;
		if (!((((int)((P0 *)this)->_pid)<5)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 34: /* STATE 74 - Man2Safe.pml:65 - [((inDownSem>0))] (77:0:1 - 1) */
		IfNotBlocked
		reached[0][74] = 1;
		if (!((now.inDownSem>0)))
			continue;
		/* merge: inDownSem = (inDownSem-1)(0, 75, 77) */
		reached[0][75] = 1;
		(trpt+1)->bup.oval = now.inDownSem;
		now.inDownSem = (now.inDownSem-1);
#ifdef VAR_RANGES
		logval("inDownSem", now.inDownSem);
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 35: /* STATE 77 - Man2Safe.pml:66 - [down = (down-1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][77] = 1;
		(trpt+1)->bup.oval = now.down;
		now.down = (now.down-1);
#ifdef VAR_RANGES
		logval("down", now.down);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 36: /* STATE 78 - Man2Safe.pml:68 - [((down==0))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][78] = 1;
		if (!((now.down==0)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 37: /* STATE 79 - Man2Safe.pml:68 - [turn = -(1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][79] = 1;
		(trpt+1)->bup.oval = now.turn;
		now.turn =  -(1);
#ifdef VAR_RANGES
		logval("turn", now.turn);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 38: /* STATE 84 - Man2Safe.pml:71 - [inDownSem = (inDownSem+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][84] = 1;
		(trpt+1)->bup.oval = now.inDownSem;
		now.inDownSem = (now.inDownSem+1);
#ifdef VAR_RANGES
		logval("inDownSem", now.inDownSem);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 39: /* STATE 87 - Man2Safe.pml:72 - [((inUpSem>0))] (90:0:1 - 1) */
		IfNotBlocked
		reached[0][87] = 1;
		if (!((now.inUpSem>0)))
			continue;
		/* merge: inUpSem = (inUpSem-1)(0, 88, 90) */
		reached[0][88] = 1;
		(trpt+1)->bup.oval = now.inUpSem;
		now.inUpSem = (now.inUpSem-1);
#ifdef VAR_RANGES
		logval("inUpSem", now.inUpSem);
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 40: /* STATE 90 - Man2Safe.pml:73 - [up = (up-1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][90] = 1;
		(trpt+1)->bup.oval = now.up;
		now.up = (now.up-1);
#ifdef VAR_RANGES
		logval("up", now.up);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 41: /* STATE 91 - Man2Safe.pml:75 - [((up==0))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][91] = 1;
		if (!((now.up==0)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 42: /* STATE 92 - Man2Safe.pml:75 - [turn = -(1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][92] = 1;
		(trpt+1)->bup.oval = now.turn;
		now.turn =  -(1);
#ifdef VAR_RANGES
		logval("turn", now.turn);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 43: /* STATE 97 - Man2Safe.pml:78 - [inUpSem = (inUpSem+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][97] = 1;
		(trpt+1)->bup.oval = now.inUpSem;
		now.inUpSem = (now.inUpSem+1);
#ifdef VAR_RANGES
		logval("inUpSem", now.inUpSem);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 44: /* STATE 104 - Man2Safe.pml:81 - [-end-] (0:0:0 - 3) */
		IfNotBlocked
		reached[0][104] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */
	case  _T5:	/* np_ */
		if (!((!(trpt->o_pm&4) && !(trpt->tau&128))))
			continue;
		/* else fall through */
	case  _T2:	/* true */
		_m = 3; goto P999;
#undef rand
	}

