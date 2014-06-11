    v367 = 0;
    switch ( a2 )
    {
      case 0:
        v23 = sub_1401EC0(&Dst, (int)&v248, "hit.wav");
        v24 = *(_DWORD *)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 1;
        v25 = (*(int (__stdcall **)(int))(*(_DWORD *)v24 + 28))(v23);
        v26 = &Dst;
        goto LABEL_104;
      case 1:
        v27 = sub_1401EC0(&v316, (int)&v248, "blade1.wav");
        v28 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 2;
        v25 = (*(int (__stdcall **)(int))(v28 + 28))(v27);
        v26 = &v316;
        goto LABEL_104;
      case 2:
        v29 = sub_1401EC0(&v268, (int)&v248, "blade2.wav");
        v30 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 3;
        v25 = (*(int (__stdcall **)(int))(v30 + 28))(v29);
        v26 = &v268;
        goto LABEL_104;
      case 9:
        v31 = sub_1401EC0(&v362, (int)&v248, "hit-arrow.wav");
        v32 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 4;
        v25 = (*(int (__stdcall **)(int))(v32 + 28))(v31);
        v26 = &v362;
        goto LABEL_104;
      case 10:
        v33 = sub_1401EC0(&v270, (int)&v248, "hit-arrow-critical.wav");
        v34 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 5;
        v25 = (*(int (__stdcall **)(int))(v34 + 28))(v33);
        v26 = &v270;
        goto LABEL_104;
      case 3:
        v35 = sub_1401EC0(&v318, (int)&v248, "long-blade1.wav");
        v36 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 6;
        v25 = (*(int (__stdcall **)(int))(v36 + 28))(v35);
        v26 = &v318;
        goto LABEL_104;
      case 4:
        v37 = sub_1401EC0(&v272, (int)&v248, "long-blade2.wav");
        v38 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 7;
        v25 = (*(int (__stdcall **)(int))(v38 + 28))(v37);
        v26 = &v272;
        goto LABEL_104;
      case 11:
        v39 = sub_1401EC0(&v342, (int)&v248, "smash1.wav");
        v40 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 8;
        v25 = (*(int (__stdcall **)(int))(v40 + 28))(v39);
        v26 = &v342;
        goto LABEL_104;
      case 5:
        v41 = sub_1401EC0(&v274, (int)&v248, "hit1.wav");
        v42 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 9;
        v25 = (*(int (__stdcall **)(int))(v42 + 28))(v41);
        v26 = &v274;
        goto LABEL_104;
      case 6:
        v43 = sub_1401EC0(&v320, (int)&v248, "hit2.wav");
        v44 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 10;
        v25 = (*(int (__stdcall **)(int))(v44 + 28))(v43);
        v26 = &v320;
        goto LABEL_104;
      case 7:
        v45 = sub_1401EC0(&v276, (int)&v248, "punch1.wav");
        v46 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 11;
        v25 = (*(int (__stdcall **)(int))(v46 + 28))(v45);
        v26 = &v276;
        goto LABEL_104;
      case 8:
        v47 = sub_1401EC0(&v354, (int)&v248, "punch2.wav");
        v48 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 12;
        v25 = (*(int (__stdcall **)(int))(v48 + 28))(v47);
        v26 = &v354;
        goto LABEL_104;
      case 82:
        v49 = sub_1401EC0(&v278, (int)&v248, "punch2.wav");
        v50 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 13;
        v25 = (*(int (__stdcall **)(int))(v50 + 28))(v49);
        v26 = &v278;
        goto LABEL_104;
      case 12:
        v51 = sub_1401EC0(&v322, (int)&v248, "slam-ground.wav");
        v52 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 14;
        v25 = (*(int (__stdcall **)(int))(v52 + 28))(v51);
        v26 = &v322;
        goto LABEL_104;
      case 13:
        v53 = sub_1401EC0(&v280, (int)&v248, "smash-hit2.wav");
        v54 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 15;
        v25 = (*(int (__stdcall **)(int))(v54 + 28))(v53);
        v26 = &v280;
        goto LABEL_104;
      case 14:
        v55 = sub_1401EC0(&v344, (int)&v248, "smash-jump.wav");
        v56 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 16;
        v25 = (*(int (__stdcall **)(int))(v56 + 28))(v55);
        v26 = &v344;
        goto LABEL_104;
      case 23:
        v57 = sub_1401EC0(&v282, (int)&v248, "sword-hit03.wav");
        v58 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 17;
        v25 = (*(int (__stdcall **)(int))(v58 + 28))(v57);
        v26 = &v282;
        goto LABEL_104;
      case 24:
        v59 = sub_1401EC0(&v324, (int)&v248, "block.wav");
        v60 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 18;
        v25 = (*(int (__stdcall **)(int))(v60 + 28))(v59);
        v26 = &v324;
        goto LABEL_104;
      case 25:
        v61 = sub_1401EC0(&v284, (int)&v248, "shield-slam.wav");
        v62 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 19;
        v25 = (*(int (__stdcall **)(int))(v62 + 28))(v61);
        v26 = &v284;
        goto LABEL_104;
      case 15:
        v63 = sub_1401EC0(&v360, (int)&v248, "swing.wav");
        v64 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 20;
        v25 = (*(int (__stdcall **)(int))(v64 + 28))(v63);
        v26 = &v360;
        goto LABEL_104;
      case 16:
        v65 = sub_1401EC0(&v286, (int)&v248, "shield-swing.wav");
        v66 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 21;
        v25 = (*(int (__stdcall **)(int))(v66 + 28))(v65);
        v26 = &v286;
        goto LABEL_104;
      case 17:
        v67 = sub_1401EC0(&v326, (int)&v248, "swing-slow.wav");
        v68 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 22;
        v25 = (*(int (__stdcall **)(int))(v68 + 28))(v67);
        v26 = &v326;
        goto LABEL_104;
      case 18:
        v69 = sub_1401EC0(&v288, (int)&v248, "swing-slow2.wav");
        v70 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 23;
        v25 = (*(int (__stdcall **)(int))(v70 + 28))(v69);
        v26 = &v288;
        goto LABEL_104;
      case 48:
        v71 = sub_1401EC0(&v346, (int)&v248, "swirl.wav");
        v72 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 24;
        v25 = (*(int (__stdcall **)(int))(v72 + 28))(v71);
        v26 = &v346;
        goto LABEL_104;
      case 22:
        v73 = sub_1401EC0(&v290, (int)&v248, "salvo2.wav");
        v74 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 25;
        v25 = (*(int (__stdcall **)(int))(v74 + 28))(v73);
        v26 = &v290;
        goto LABEL_104;
      case 26:
        v75 = sub_1401EC0(&v328, (int)&v248, "roll.wav");
        v76 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 26;
        v25 = (*(int (__stdcall **)(int))(v76 + 28))(v75);
        v26 = &v328;
        goto LABEL_104;
      case 27:
        v77 = sub_1401EC0(&v292, (int)&v248, "destroy2.wav");
        v78 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 27;
        v25 = (*(int (__stdcall **)(int))(v78 + 28))(v77);
        v26 = &v292;
        goto LABEL_104;
      case 19:
        v79 = sub_1401EC0(&v356, (int)&v248, "arrow-destroy.wav");
        v80 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 28;
        v25 = (*(int (__stdcall **)(int))(v80 + 28))(v79);
        v26 = &v356;
        goto LABEL_104;
      case 20:
        v81 = sub_1401EC0(&v294, (int)&v248, "blade1.wav");
        v82 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 29;
        v25 = (*(int (__stdcall **)(int))(v82 + 28))(v81);
        v26 = &v294;
        goto LABEL_104;
      case 21:
        v83 = sub_1401EC0(&v330, (int)&v248, "punch2.wav");
        v84 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 30;
        v25 = (*(int (__stdcall **)(int))(v84 + 28))(v83);
        v26 = &v330;
        goto LABEL_104;
      case 28:
        v85 = sub_1401EC0(&v296, (int)&v248, "cry.wav");
        v86 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 31;
        v25 = (*(int (__stdcall **)(int))(v86 + 28))(v85);
        v26 = &v296;
        goto LABEL_104;
      case 29:
        v87 = sub_1401EC0(&v348, (int)&v248, "levelup2.wav");
        v88 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 32;
        v25 = (*(int (__stdcall **)(int))(v88 + 28))(v87);
        v26 = &v348;
        goto LABEL_104;
      case 30:
        v89 = sub_1401EC0(&v298, (int)&v248, "missioncomplete.wav");
        v90 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 33;
        v25 = (*(int (__stdcall **)(int))(v90 + 28))(v89);
        v26 = &v298;
        goto LABEL_104;
      case 31:
        v91 = sub_1401EC0(&v332, (int)&v248, "water-splash01.wav");
        v92 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 34;
        v25 = (*(int (__stdcall **)(int))(v92 + 28))(v91);
        v26 = &v332;
        goto LABEL_104;
      case 32:
        v93 = sub_1401EC0(&v300, (int)&v248, "step2.wav");
        v94 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 35;
        v25 = (*(int (__stdcall **)(int))(v94 + 28))(v93);
        v26 = &v300;
        goto LABEL_104;
      case 33:
        v95 = sub_1401EC0(&v364, (int)&v248, "step-water.wav");
        v96 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 36;
        v25 = (*(int (__stdcall **)(int))(v96 + 28))(v95);
        v26 = &v364;
        goto LABEL_104;
      case 34:
        v97 = sub_1401EC0(&v302, (int)&v248, "step-water2.wav");
        v98 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 37;
        v25 = (*(int (__stdcall **)(int))(v98 + 28))(v97);
        v26 = &v302;
        goto LABEL_104;
      case 35:
        v99 = sub_1401EC0(&v334, (int)&v248, "step-water3.wav");
        v100 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 38;
        v25 = (*(int (__stdcall **)(int))(v100 + 28))(v99);
        v26 = &v334;
        goto LABEL_104;
      case 36:
        v101 = sub_1401EC0(&v304, (int)&v248, "channel2.wav");
        v102 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 39;
        v25 = (*(int (__stdcall **)(int))(v102 + 28))(v101);
        v26 = &v304;
        goto LABEL_104;
      case 37:
        v103 = sub_1401EC0(&v350, (int)&v248, "channel-hit.wav");
        v104 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 40;
        v25 = (*(int (__stdcall **)(int))(v104 + 28))(v103);
        v26 = &v350;
        goto LABEL_104;
      case 38:
        v105 = sub_1401EC0(&v306, (int)&v248, "fireball.wav");
        v106 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 41;
        v25 = (*(int (__stdcall **)(int))(v106 + 28))(v105);
        v26 = &v306;
        goto LABEL_104;
      case 39:
        v107 = sub_1401EC0(&v265, (int)&v248, "fire-hit.wav");
        v108 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 42;
        v25 = (*(int (__stdcall **)(int))(v108 + 28))(v107);
        v26 = &v265;
        goto LABEL_104;
      case 91:
        v109 = sub_1401EC0(&v308, (int)&v248, "absorb.wav");
        v110 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 43;
        v25 = (*(int (__stdcall **)(int))(v110 + 28))(v109);
        v26 = &v308;
        goto LABEL_104;
      case 92:
        v111 = sub_1401EC0(&v358, (int)&v248, "manashield.wav");
        v112 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 44;
        v25 = (*(int (__stdcall **)(int))(v112 + 28))(v111);
        v26 = &v358;
        goto LABEL_104;
      case 93:
        v113 = sub_1401EC0(&v310, (int)&v248, "bulwark.wav");
        v114 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 45;
        v25 = (*(int (__stdcall **)(int))(v114 + 28))(v113);
        v26 = &v310;
        goto LABEL_104;
      case 40:
        v115 = sub_1401EC0(&v338, (int)&v248, "magic02.wav");
        v116 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 46;
        v25 = (*(int (__stdcall **)(int))(v116 + 28))(v115);
        v26 = &v338;
        goto LABEL_104;
      case 41:
        v117 = sub_1401EC0(&v312, (int)&v248, "watersplash.wav");
        v118 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 47;
        v25 = (*(int (__stdcall **)(int))(v118 + 28))(v117);
        v26 = &v312;
        goto LABEL_104;
      case 42:
        v119 = sub_1401EC0(&v352, (int)&v248, "watersplash-hit.wav");
        v120 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 48;
        v25 = (*(int (__stdcall **)(int))(v120 + 28))(v119);
        v26 = &v352;
        goto LABEL_104;
      case 81:
        v121 = sub_1401EC0(&v314, (int)&v248, "Explosion.wav");
        v122 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 49;
        v25 = (*(int (__stdcall **)(int))(v122 + 28))(v121);
        v26 = &v314;
        goto LABEL_104;
      case 43:
        v123 = sub_1401EC0(&v340, (int)&v248, "lich-scream.wav");
        v124 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 50;
        v25 = (*(int (__stdcall **)(int))(v124 + 28))(v123);
        v26 = &v340;
        goto LABEL_104;
      case 44:
        v125 = sub_1401EC0(&v266, (int)&v248, "drink2.wav");
        v126 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 51;
        v25 = (*(int (__stdcall **)(int))(v126 + 28))(v125);
        v26 = &v266;
        goto LABEL_104;
      case 45:
        v127 = sub_1401EC0(&v267, (int)&v248, "pickup.wav");
        v128 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 52;
        v25 = (*(int (__stdcall **)(int))(v128 + 28))(v127);
        v26 = &v267;
        goto LABEL_104;
      case 46:
        v129 = sub_1401EC0(&v269, (int)&v248, "disenchant2.wav");
        v130 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 53;
        v25 = (*(int (__stdcall **)(int))(v130 + 28))(v129);
        v26 = &v269;
        goto LABEL_104;
      case 47:
        v131 = sub_1401EC0(&v271, (int)&v248, "upgrade2.wav");
        v132 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 54;
        v25 = (*(int (__stdcall **)(int))(v132 + 28))(v131);
        v26 = &v271;
        goto LABEL_104;
      case 49:
        v133 = sub_1401EC0(&v273, (int)&v248, "human-voice01.wav");
        v134 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 55;
        v25 = (*(int (__stdcall **)(int))(v134 + 28))(v133);
        v26 = &v273;
        goto LABEL_104;
      case 50:
        v135 = sub_1401EC0(&v275, (int)&v248, "human-voice02.wav");
        v136 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 56;
        v25 = (*(int (__stdcall **)(int))(v136 + 28))(v135);
        v26 = &v275;
        goto LABEL_104;
      case 51:
        v137 = sub_1401EC0(&v277, (int)&v248, "gate.wav");
        v138 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 57;
        v25 = (*(int (__stdcall **)(int))(v138 + 28))(v137);
        v26 = &v277;
        goto LABEL_104;
      case 54:
        v139 = sub_1401EC0(&v279, (int)&v248, "lever.wav");
        v140 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 58;
        v25 = (*(int (__stdcall **)(int))(v140 + 28))(v139);
        v26 = &v279;
        goto LABEL_104;
      case 52:
        v141 = sub_1401EC0(&v281, (int)&v248, "spike-trap.wav");
        v142 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 59;
        v25 = (*(int (__stdcall **)(int))(v142 + 28))(v141);
        v26 = &v281;
        goto LABEL_104;
      case 53:
        v143 = sub_1401EC0(&v283, (int)&v248, "fire-trap.wav");
        v144 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 60;
        v25 = (*(int (__stdcall **)(int))(v144 + 28))(v143);
        v26 = &v283;
        goto LABEL_104;
      case 56:
        v145 = sub_1401EC0(&v285, (int)&v248, "magic02.wav");
        v146 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 61;
        v25 = (*(int (__stdcall **)(int))(v146 + 28))(v145);
        v26 = &v285;
        goto LABEL_104;
      case 55:
        v147 = sub_1401EC0(&v287, (int)&v248, "charge2.wav");
        v148 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 62;
        v25 = (*(int (__stdcall **)(int))(v148 + 28))(v147);
        v26 = &v287;
        goto LABEL_104;
      case 57:
        v149 = sub_1401EC0(&v289, (int)&v248, "drop.wav");
        v150 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 63;
        v25 = (*(int (__stdcall **)(int))(v150 + 28))(v149);
        v26 = &v289;
        goto LABEL_104;
      case 58:
        v151 = sub_1401EC0(&v291, (int)&v248, "drop-coin.wav");
        v152 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 64;
        v25 = (*(int (__stdcall **)(int))(v152 + 28))(v151);
        v26 = &v291;
        goto LABEL_104;
      case 59:
        v153 = sub_1401EC0(&v293, (int)&v248, "drop-item.wav");
        v154 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 65;
        v25 = (*(int (__stdcall **)(int))(v154 + 28))(v153);
        v26 = &v293;
        goto LABEL_104;
      case 60:
        v155 = sub_1401EC0(&v295, (int)&v248, "male-groan.wav");
        v156 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 66;
        v25 = (*(int (__stdcall **)(int))(v156 + 28))(v155);
        v26 = &v295;
        goto LABEL_104;
      case 61:
        v157 = sub_1401EC0(&v297, (int)&v248, "female-groan.wav");
        v158 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 67;
        v25 = (*(int (__stdcall **)(int))(v158 + 28))(v157);
        v26 = &v297;
        goto LABEL_104;
      case 62:
        v159 = sub_1401EC0(&v299, (int)&v248, "male-groan.wav");
        v160 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 68;
        v25 = (*(int (__stdcall **)(int))(v160 + 28))(v159);
        v26 = &v299;
        goto LABEL_104;
      case 63:
        v161 = sub_1401EC0(&v301, (int)&v248, "female-groan.wav");
        v162 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 69;
        v25 = (*(int (__stdcall **)(int))(v162 + 28))(v161);
        v26 = &v301;
        goto LABEL_104;
      case 64:
        v163 = sub_1401EC0(&v303, (int)&v248, "goblin-male-groan.wav");
        v164 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 70;
        v25 = (*(int (__stdcall **)(int))(v164 + 28))(v163);
        v26 = &v303;
        goto LABEL_104;
      case 65:
        v165 = sub_1401EC0(&v305, (int)&v248, "goblin-female-groan.wav");
        v166 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 71;
        v25 = (*(int (__stdcall **)(int))(v166 + 28))(v165);
        v26 = &v305;
        goto LABEL_104;
      case 66:
        v167 = sub_1401EC0(&v307, (int)&v248, "lizard-male-groan.wav");
        v168 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 72;
        v25 = (*(int (__stdcall **)(int))(v168 + 28))(v167);
        v26 = &v307;
        goto LABEL_104;
      case 67:
        v169 = sub_1401EC0(&v309, (int)&v248, "lizard-female-groan.wav");
        v170 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 73;
        v25 = (*(int (__stdcall **)(int))(v170 + 28))(v169);
        v26 = &v309;
        goto LABEL_104;
      case 68:
        v171 = sub_1401EC0(&v311, (int)&v248, "dwarf-male-groan.wav");
        v172 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 74;
        v25 = (*(int (__stdcall **)(int))(v172 + 28))(v171);
        v26 = &v311;
        goto LABEL_104;
      case 69:
        v173 = sub_1401EC0(&v313, (int)&v248, "dwarf-female-groan.wav");
        v174 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 75;
        v25 = (*(int (__stdcall **)(int))(v174 + 28))(v173);
        v26 = &v313;
        goto LABEL_104;
      case 70:
        v175 = sub_1401EC0(&v315, (int)&v248, "orc-male-groan.wav");
        v176 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 76;
        v25 = (*(int (__stdcall **)(int))(v176 + 28))(v175);
        v26 = &v315;
        goto LABEL_104;
      case 71:
        v177 = sub_1401EC0(&v317, (int)&v248, "orc-female-groan.wav");
        v178 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 77;
        v25 = (*(int (__stdcall **)(int))(v178 + 28))(v177);
        v26 = &v317;
        goto LABEL_104;
      case 72:
        v179 = sub_1401EC0(&v319, (int)&v248, "undead-male-groan.wav");
        v180 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 78;
        v25 = (*(int (__stdcall **)(int))(v180 + 28))(v179);
        v26 = &v319;
        goto LABEL_104;
      case 73:
        v181 = sub_1401EC0(&v321, (int)&v248, "undead-female-groan.wav");
        v182 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 79;
        v25 = (*(int (__stdcall **)(int))(v182 + 28))(v181);
        v26 = &v321;
        goto LABEL_104;
      case 74:
        v183 = sub_1401EC0(&v323, (int)&v248, "frogman-male-groan.wav");
        v184 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 80;
        v25 = (*(int (__stdcall **)(int))(v184 + 28))(v183);
        v26 = &v323;
        goto LABEL_104;
      case 75:
        v185 = sub_1401EC0(&v325, (int)&v248, "frogman-female-groan.wav");
        v186 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 81;
        v25 = (*(int (__stdcall **)(int))(v186 + 28))(v185);
        v26 = &v325;
        goto LABEL_104;
      case 76:
        v187 = sub_1401EC0(&v327, (int)&v248, "monster-groan.wav");
        v188 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 82;
        v25 = (*(int (__stdcall **)(int))(v188 + 28))(v187);
        v26 = &v327;
        goto LABEL_104;
      case 77:
        v189 = sub_1401EC0(&v329, (int)&v248, "troll-groan.wav");
        v190 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 83;
        v25 = (*(int (__stdcall **)(int))(v190 + 28))(v189);
        v26 = &v329;
        goto LABEL_104;
      case 80:
        v191 = sub_1401EC0(&v331, (int)&v248, "zombie-groan.wav");
        v192 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 84;
        v25 = (*(int (__stdcall **)(int))(v192 + 28))(v191);
        v26 = &v331;
        goto LABEL_104;
      case 79:
        v193 = sub_1401EC0(&v333, (int)&v248, "slime-groan.wav");
        v194 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 85;
        v25 = (*(int (__stdcall **)(int))(v194 + 28))(v193);
        v26 = &v333;
        goto LABEL_104;
      case 78:
        v195 = sub_1401EC0(&v335, (int)&v248, "mole-groan.wav");
        v196 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 86;
        v25 = (*(int (__stdcall **)(int))(v196 + 28))(v195);
        v26 = &v335;
        goto LABEL_104;
      case 83:
        v197 = sub_1401EC0(&v337, (int)&v248, "menu-open2.wav");
        v198 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 87;
        v25 = (*(int (__stdcall **)(int))(v198 + 28))(v197);
        v26 = &v337;
        goto LABEL_104;
      case 84:
        v199 = sub_1401EC0(&v339, (int)&v248, "menu-close2.wav");
        v200 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 88;
        v25 = (*(int (__stdcall **)(int))(v200 + 28))(v199);
        v26 = &v339;
        goto LABEL_104;
      case 85:
        v201 = sub_1401EC0(&v341, (int)&v248, "menu-select.wav");
        v202 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 89;
        v25 = (*(int (__stdcall **)(int))(v202 + 28))(v201);
        v26 = &v341;
        goto LABEL_104;
      case 86:
        v203 = sub_1401EC0(&v343, (int)&v248, "menu-tab.wav");
        v204 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 90;
        v25 = (*(int (__stdcall **)(int))(v204 + 28))(v203);
        v26 = &v343;
        goto LABEL_104;
      case 87:
        v205 = sub_1401EC0(&v345, (int)&v248, "menu-grab-item.wav");
        v206 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 91;
        v25 = (*(int (__stdcall **)(int))(v206 + 28))(v205);
        v26 = &v345;
        goto LABEL_104;
      case 88:
        v207 = sub_1401EC0(&v347, (int)&v248, "menu-drop-item.wav");
        v208 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 92;
        v25 = (*(int (__stdcall **)(int))(v208 + 28))(v207);
        v26 = &v347;
        goto LABEL_104;
      case 89:
        v209 = sub_1401EC0(&v349, (int)&v248, "craft.wav");
        v210 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 93;
        v25 = (*(int (__stdcall **)(int))(v210 + 28))(v209);
        v26 = &v349;
        goto LABEL_104;
      case 90:
        v211 = sub_1401EC0(&v351, (int)&v248, "craft-proc.wav");
        v212 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 94;
        v25 = (*(int (__stdcall **)(int))(v212 + 28))(v211);
        v26 = &v351;
        goto LABEL_104;
      case 94:
        v213 = sub_1401EC0(&v353, (int)&v248, "bird1.wav");
        v214 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 95;
        v25 = (*(int (__stdcall **)(int))(v214 + 28))(v213);
        v26 = &v353;
        goto LABEL_104;
      case 95:
        v215 = sub_1401EC0(&v355, (int)&v248, "bird2.wav");
        v216 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 96;
        v25 = (*(int (__stdcall **)(int))(v216 + 28))(v215);
        v26 = &v355;
        goto LABEL_104;
      case 96:
        v217 = sub_1401EC0(&v357, (int)&v248, "bird3.wav");
        v218 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 97;
        v25 = (*(int (__stdcall **)(int))(v218 + 28))(v217);
        v26 = &v357;
        goto LABEL_104;
      case 99:
        v219 = sub_1401EC0(&v359, (int)&v248, "owl1.wav");
        v220 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 98;
        v25 = (*(int (__stdcall **)(int))(v220 + 28))(v219);
        v26 = &v359;
        goto LABEL_104;
      case 100:
        v221 = sub_1401EC0(&v361, (int)&v248, "owl2.wav");
        v222 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 99;
        v25 = (*(int (__stdcall **)(int))(v222 + 28))(v221);
        v26 = &v361;
        goto LABEL_104;
      case 97:
        v223 = sub_1401EC0(&v363, (int)&v248, "cricket1.wav");
        v224 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 100;
        v25 = (*(int (__stdcall **)(int))(v224 + 28))(v223);
        v26 = &v363;
        goto LABEL_104;
      case 98:
        v225 = sub_1401EC0(&v365, (int)&v248, "cricket2.wav");
        v226 = **(_DWORD **)(LODWORD(v15) + 8390420);
        LOBYTE(v367) = 101;
        v25 = (*(int (__stdcall **)(int))(v226 + 28))(v225);