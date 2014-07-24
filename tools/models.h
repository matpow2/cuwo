void __userpurge init_models(int a1<ecx>, int manager<edi>, int a3<esi>, int a4)
{
  int v4; // ecx@1
  int v5; // edi@1
  int v6; // ebx@1
  signed int v7; // esi@1
  int v8; // ecx@3
  signed int v9; // eax@5
  void *v10; // eax@7
  void *v11; // eax@8
  void *v12; // eax@11
  int v13; // eax@11
  int *v14; // ecx@11
  int v15; // ecx@11
  int v16; // eax@11
  int *v17; // ecx@11
  int v18; // ecx@11
  int v19; // eax@11
  int *v20; // ecx@11
  int v21; // ecx@11
  int v22; // eax@11
  int *v23; // ecx@11
  int v24; // ecx@11
  int v25; // eax@11
  int *v26; // ecx@11
  int v27; // ecx@11
  int v28; // eax@11
  int *v29; // ecx@11
  int v30; // ecx@11
  int v31; // eax@11
  int *v32; // ecx@11
  int v33; // ecx@11
  int v34; // eax@11
  int *v35; // ecx@11
  int v36; // ecx@11
  int v37; // eax@11
  int *v38; // ecx@11
  int v39; // ecx@11
  int v40; // eax@11
  int *v41; // ecx@11
  int v42; // ecx@11
  int v43; // eax@11
  int *v44; // ecx@11
  int v45; // ecx@11
  int v46; // eax@11
  int *v47; // ecx@11
  int v48; // ecx@11
  int v49; // eax@11
  int *v50; // ecx@11
  int v51; // ecx@11
  int v52; // eax@11
  int *v53; // ecx@11
  int v54; // ecx@11
  int v55; // eax@11
  int *v56; // ecx@11
  int v57; // ecx@11
  int v58; // eax@11
  int *v59; // ecx@11
  int v60; // ecx@11
  int v61; // eax@11
  int *v62; // ecx@11
  int v63; // ecx@11
  int v64; // eax@11
  int *v65; // ecx@11
  int v66; // ecx@11
  int v67; // eax@11
  int *v68; // ecx@11
  int v69; // ecx@11
  int v70; // eax@11
  int *v71; // ecx@11
  int v72; // ecx@11
  int v73; // eax@11
  int *v74; // ecx@11
  int v75; // ecx@11
  int v76; // eax@11
  int *v77; // ecx@11
  int v78; // ecx@11
  int v79; // eax@11
  int *v80; // ecx@11
  int v81; // ecx@11
  int v82; // eax@11
  int *v83; // ecx@11
  int v84; // ecx@11
  int v85; // eax@11
  int *v86; // ecx@11
  int v87; // ecx@11
  int v88; // eax@11
  int *v89; // ecx@11
  int v90; // ecx@11
  int v91; // eax@11
  int *v92; // ecx@11
  int v93; // ecx@11
  int v94; // eax@11
  int *v95; // ecx@11
  int v96; // ecx@11
  int v97; // eax@11
  int *v98; // ecx@11
  int v99; // ecx@11
  int v100; // eax@11
  int *v101; // ecx@11
  int v102; // ecx@11
  int v103; // eax@11
  int *v104; // ecx@11
  int v105; // ecx@11
  int v106; // eax@11
  int *v107; // ecx@11
  int v108; // ecx@11
  int v109; // eax@11
  int *v110; // ecx@11
  int v111; // ecx@11
  int v112; // eax@11
  int *v113; // ecx@11
  int v114; // ecx@11
  int v115; // eax@11
  int *v116; // ecx@11
  int v117; // ecx@11
  int v118; // eax@11
  int *v119; // ecx@11
  int v120; // ecx@11
  int v121; // eax@11
  int *v122; // ecx@11
  int v123; // ecx@11
  int v124; // eax@11
  int *v125; // ecx@11
  int v126; // ecx@11
  int v127; // eax@11
  int *v128; // ecx@11
  int v129; // ecx@11
  int v130; // eax@11
  int *v131; // ecx@11
  int v132; // ecx@11
  int v133; // eax@11
  int *v134; // ecx@11
  int v135; // ecx@11
  int v136; // eax@11
  int *v137; // ecx@11
  int v138; // ecx@11
  int v139; // eax@11
  int *v140; // ecx@11
  int v141; // ecx@11
  int v142; // eax@11
  int *v143; // ecx@11
  int v144; // ecx@11
  int v145; // eax@11
  int *v146; // ecx@11
  int v147; // ecx@11
  int v148; // eax@11
  int *v149; // ecx@11
  int v150; // ecx@11
  int v151; // eax@11
  int *v152; // ecx@11
  int v153; // ecx@11
  int v154; // eax@11
  int *v155; // ecx@11
  int v156; // ecx@11
  int v157; // eax@11
  int *v158; // ecx@11
  int v159; // ecx@11
  int v160; // eax@11
  int *v161; // ecx@11
  int v162; // ecx@11
  int v163; // eax@11
  int *v164; // ecx@11
  int v165; // ecx@11
  int v166; // eax@11
  int *v167; // ecx@11
  int v168; // ecx@11
  int v169; // eax@11
  int *v170; // ecx@11
  int v171; // ecx@11
  int v172; // eax@11
  int *v173; // ecx@11
  int v174; // ecx@11
  int v175; // eax@11
  int *v176; // ecx@11
  int v177; // ecx@11
  int v178; // eax@11
  int *v179; // ecx@11
  int v180; // ecx@11
  int v181; // eax@11
  int *v182; // ecx@11
  int v183; // ecx@11
  int v184; // eax@11
  int *v185; // ecx@11
  int v186; // ecx@11
  int v187; // eax@11
  int *v188; // ecx@11
  int v189; // ecx@11
  int v190; // eax@11
  int *v191; // ecx@11
  int v192; // ecx@11
  int v193; // eax@11
  int *v194; // ecx@11
  int v195; // ecx@11
  int v196; // eax@11
  int *v197; // ecx@11
  int v198; // ecx@11
  int v199; // eax@11
  int *v200; // ecx@11
  int v201; // ecx@11
  int v202; // eax@11
  int *v203; // ecx@11
  int v204; // ecx@11
  int v205; // eax@11
  int *v206; // ecx@11
  int v207; // ecx@11
  int v208; // eax@11
  int *v209; // ecx@11
  int v210; // ecx@11
  int v211; // eax@11
  int *v212; // ecx@11
  int v213; // ecx@11
  int v214; // eax@11
  int *v215; // ecx@11
  int v216; // ecx@11
  int v217; // eax@11
  int *v218; // ecx@11
  int v219; // ecx@11
  int v220; // eax@11
  int *v221; // ecx@11
  int v222; // ecx@11
  int v223; // eax@11
  int *v224; // ecx@11
  int v225; // ecx@11
  int v226; // eax@11
  int *v227; // ecx@11
  int v228; // ecx@11
  int v229; // eax@11
  int *v230; // ecx@11
  int v231; // ecx@11
  int v232; // eax@11
  int *v233; // ecx@11
  int v234; // ecx@11
  int v235; // eax@11
  int *v236; // ecx@11
  int v237; // ecx@11
  int v238; // eax@11
  int *v239; // ecx@11
  int v240; // ecx@11
  int v241; // eax@11
  int *v242; // ecx@11
  int v243; // ecx@11
  int v244; // eax@11
  int *v245; // ecx@11
  int v246; // ecx@11
  int v247; // eax@11
  int *v248; // ecx@11
  int v249; // ecx@11
  int v250; // eax@11
  int *v251; // ecx@11
  int v252; // ecx@11
  int v253; // eax@11
  int *v254; // ecx@11
  int v255; // ecx@11
  int v256; // eax@11
  int *v257; // ecx@11
  int v258; // ecx@11
  int v259; // eax@11
  int *v260; // ecx@11
  int v261; // ecx@11
  int v262; // eax@11
  int *v263; // ecx@11
  int v264; // ecx@11
  int v265; // eax@11
  int *v266; // ecx@11
  int v267; // ecx@11
  int v268; // eax@11
  int *v269; // ecx@11
  int v270; // ecx@11
  int v271; // eax@11
  int *v272; // ecx@11
  int v273; // ecx@11
  int v274; // eax@11
  int *v275; // ecx@11
  int v276; // ecx@11
  int v277; // eax@11
  int *v278; // ecx@11
  int v279; // ecx@11
  int v280; // eax@11
  int *v281; // ecx@11
  int v282; // ecx@11
  int v283; // eax@11
  int *v284; // ecx@11
  int v285; // ecx@11
  int v286; // eax@11
  int *v287; // ecx@11
  int v288; // ecx@11
  int v289; // eax@11
  int *v290; // ecx@11
  int v291; // ecx@11
  int v292; // eax@11
  int *v293; // ecx@11
  int v294; // ecx@11
  int v295; // eax@11
  int *v296; // ecx@11
  int v297; // ecx@11
  int v298; // eax@11
  int *v299; // ecx@11
  int v300; // ecx@11
  int v301; // eax@11
  int *v302; // ecx@11
  int v303; // ecx@11
  int v304; // eax@11
  int *v305; // ecx@11
  int v306; // ecx@11
  int v307; // eax@11
  int *v308; // ecx@11
  int v309; // ecx@11
  int v310; // eax@11
  int *v311; // ecx@11
  int v312; // ecx@11
  int v313; // eax@11
  int *v314; // ecx@11
  int v315; // ecx@11
  int v316; // eax@11
  int *v317; // ecx@11
  int v318; // ecx@11
  int v319; // eax@11
  int *v320; // ecx@11
  int v321; // ecx@11
  int v322; // eax@11
  int *v323; // ecx@11
  int v324; // ecx@11
  int v325; // eax@11
  int *v326; // ecx@11
  int v327; // ecx@11
  int v328; // eax@11
  int *v329; // ecx@11
  int v330; // ecx@11
  int v331; // eax@11
  int *v332; // ecx@11
  int v333; // ecx@11
  int v334; // eax@11
  int *v335; // ecx@11
  int v336; // ecx@11
  int v337; // esi@11
  int v338; // eax@11
  int v339; // esi@11
  int v340; // eax@11
  int v341; // esi@11
  int v342; // eax@11
  int v343; // esi@11
  int v344; // eax@11
  int v345; // esi@11
  int v346; // eax@11
  int v347; // esi@11
  int v348; // eax@11
  int v349; // esi@11
  int v350; // eax@11
  int v351; // esi@11
  int v352; // eax@11
  int v353; // esi@11
  int v354; // eax@11
  int v355; // esi@11
  int v356; // eax@11
  int v357; // esi@11
  int v358; // eax@11
  int v359; // esi@11
  int v360; // eax@11
  int v361; // esi@11
  int v362; // eax@11
  int v363; // esi@11
  int v364; // eax@11
  int v365; // esi@11
  int v366; // eax@11
  int v367; // esi@11
  int v368; // eax@11
  int v369; // esi@11
  int v370; // eax@11
  int v371; // esi@11
  int v372; // eax@11
  int v373; // esi@11
  int v374; // eax@11
  int v375; // esi@11
  int v376; // eax@11
  int v377; // esi@11
  int v378; // eax@11
  int v379; // esi@11
  int v380; // eax@11
  int v381; // esi@11
  int v382; // eax@11
  int v383; // esi@11
  int v384; // eax@11
  int v385; // esi@11
  int v386; // eax@11
  int v387; // esi@11
  int v388; // eax@11
  int v389; // esi@11
  int v390; // eax@11
  int v391; // esi@11
  int v392; // eax@11
  int v393; // esi@11
  int v394; // eax@11
  int v395; // esi@11
  int v396; // eax@11
  int v397; // esi@11
  int v398; // eax@11
  int v399; // esi@11
  int v400; // eax@11
  int v401; // esi@11
  int v402; // eax@11
  int v403; // esi@11
  int v404; // eax@11
  int v405; // esi@11
  int v406; // eax@11
  int v407; // esi@11
  int v408; // eax@11
  int v409; // esi@11
  int v410; // eax@11
  int v411; // esi@11
  int v412; // eax@11
  int v413; // esi@11
  int v414; // eax@11
  int v415; // esi@11
  int v416; // eax@11
  int v417; // esi@11
  int v418; // eax@11
  int v419; // esi@11
  int v420; // eax@11
  int v421; // esi@11
  int v422; // eax@11
  int v423; // esi@11
  int v424; // eax@11
  int v425; // esi@11
  int v426; // eax@11
  int v427; // esi@11
  int v428; // eax@11
  int v429; // esi@11
  int v430; // eax@11
  int v431; // esi@11
  int v432; // eax@11
  int v433; // esi@11
  int v434; // eax@11
  int v435; // esi@11
  int v436; // eax@11
  int v437; // esi@11
  int v438; // eax@11
  int v439; // esi@11
  int v440; // eax@11
  int v441; // esi@11
  int v442; // eax@11
  int v443; // esi@11
  int v444; // eax@11
  int v445; // esi@11
  int v446; // eax@11
  int v447; // esi@11
  int v448; // eax@11
  int v449; // esi@11
  int v450; // eax@11
  int v451; // esi@11
  int v452; // eax@11
  int v453; // esi@11
  int v454; // eax@11
  int v455; // esi@11
  int v456; // eax@11
  int v457; // esi@11
  int v458; // eax@11
  int v459; // esi@11
  int v460; // eax@11
  int v461; // esi@11
  int v462; // eax@11
  int v463; // esi@11
  int v464; // eax@11
  int v465; // esi@11
  int v466; // eax@11
  int v467; // esi@11
  int v468; // eax@11
  int v469; // esi@11
  int v470; // eax@11
  int v471; // esi@11
  int v472; // eax@11
  int v473; // esi@11
  int v474; // eax@11
  int v475; // esi@11
  int v476; // eax@11
  int v477; // esi@11
  int v478; // eax@11
  int v479; // esi@11
  int v480; // eax@11
  int v481; // esi@11
  int v482; // eax@11
  int v483; // esi@11
  int v484; // eax@11
  int v485; // esi@11
  int v486; // eax@11
  int v487; // esi@11
  int v488; // eax@11
  int v489; // esi@11
  int v490; // eax@11
  int v491; // esi@11
  int v492; // eax@11
  int v493; // esi@11
  int v494; // eax@11
  int v495; // esi@11
  int v496; // eax@11
  int v497; // esi@11
  int v498; // eax@11
  int v499; // esi@11
  int v500; // eax@11
  int v501; // esi@11
  int v502; // eax@11
  int v503; // esi@11
  int v504; // eax@11
  int v505; // esi@11
  int v506; // eax@11
  int v507; // esi@11
  int v508; // eax@11
  int v509; // esi@11
  int v510; // eax@11
  int v511; // esi@11
  int v512; // eax@11
  int v513; // esi@11
  int v514; // eax@11
  int v515; // esi@11
  int v516; // eax@11
  int v517; // esi@11
  int v518; // eax@11
  int v519; // esi@11
  int v520; // eax@11
  int v521; // esi@11
  int v522; // eax@11
  int v523; // esi@11
  int v524; // eax@11
  int v525; // esi@11
  int v526; // eax@11
  int v527; // esi@11
  int v528; // eax@11
  int v529; // esi@11
  int v530; // eax@11
  int v531; // esi@11
  int v532; // eax@11
  int v533; // esi@11
  int v534; // eax@11
  int v535; // esi@11
  int v536; // eax@11
  int v537; // esi@11
  int v538; // eax@11
  int v539; // esi@11
  int v540; // eax@11
  int v541; // esi@11
  int v542; // eax@11
  int v543; // esi@11
  int v544; // eax@11
  int v545; // esi@11
  int v546; // eax@11
  int v547; // esi@11
  int v548; // eax@11
  int v549; // esi@11
  int v550; // eax@11
  int v551; // esi@11
  int v552; // eax@11
  int v553; // esi@11
  int v554; // eax@11
  int v555; // esi@11
  int v556; // eax@11
  int v557; // esi@11
  int v558; // eax@11
  int v559; // esi@11
  int v560; // eax@11
  int v561; // esi@11
  int v562; // eax@11
  int v563; // esi@11
  int v564; // eax@11
  int v565; // esi@11
  int v566; // eax@11
  int v567; // esi@11
  int v568; // eax@11
  int v569; // esi@11
  int v570; // eax@11
  int v571; // esi@11
  int v572; // eax@11
  int v573; // esi@11
  int v574; // eax@11
  int v575; // esi@11
  int v576; // eax@11
  int v577; // esi@11
  int v578; // eax@11
  int v579; // esi@11
  int v580; // eax@11
  int v581; // esi@11
  int v582; // eax@11
  int v583; // esi@11
  int v584; // eax@11
  int v585; // esi@11
  int v586; // eax@11
  int v587; // esi@11
  int v588; // eax@11
  int v589; // esi@11
  int v590; // eax@11
  int v591; // esi@11
  int v592; // eax@11
  int v593; // esi@11
  int v594; // eax@11
  int v595; // esi@11
  int v596; // eax@11
  int v597; // esi@11
  int v598; // eax@11
  int v599; // esi@11
  int v600; // eax@11
  int v601; // esi@11
  int v602; // eax@11
  int v603; // esi@11
  int v604; // eax@11
  int v605; // esi@11
  int v606; // eax@11
  int v607; // esi@11
  int v608; // eax@11
  int v609; // esi@11
  int v610; // eax@11
  int v611; // esi@11
  int v612; // eax@11
  int v613; // esi@11
  int v614; // eax@11
  int v615; // esi@11
  int v616; // eax@11
  int v617; // esi@11
  int v618; // eax@11
  int v619; // esi@11
  int v620; // eax@11
  int v621; // esi@11
  int v622; // eax@11
  int v623; // esi@11
  int v624; // eax@11
  int v625; // esi@11
  int v626; // eax@11
  int v627; // esi@11
  int v628; // eax@11
  int v629; // esi@11
  int v630; // eax@11
  int v631; // esi@11
  int v632; // eax@11
  int v633; // esi@11
  int v634; // eax@11
  int v635; // esi@11
  int v636; // eax@11
  int v637; // esi@11
  int v638; // eax@11
  int v639; // esi@11
  int v640; // eax@11
  int v641; // esi@11
  int v642; // eax@11
  int v643; // esi@11
  int v644; // eax@11
  int v645; // esi@11
  int v646; // eax@11
  int v647; // esi@11
  int v648; // eax@11
  int v649; // esi@11
  int v650; // eax@11
  int v651; // esi@11
  int v652; // eax@11
  int v653; // esi@11
  int v654; // eax@11
  int v655; // esi@11
  int v656; // eax@11
  int v657; // esi@11
  int v658; // eax@11
  int v659; // esi@11
  int v660; // eax@11
  int v661; // esi@11
  int v662; // eax@11
  int v663; // esi@11
  int v664; // eax@11
  int v665; // esi@11
  int v666; // eax@11
  int v667; // esi@11
  int v668; // eax@11
  int v669; // esi@11
  int v670; // eax@11
  int v671; // esi@11
  int v672; // eax@11
  int v673; // esi@11
  int v674; // eax@11
  int v675; // esi@11
  int v676; // eax@11
  int v677; // esi@11
  int v678; // eax@11
  int v679; // esi@11
  int v680; // eax@11
  int v681; // esi@11
  int v682; // eax@11
  int v683; // esi@11
  int v684; // eax@11
  int v685; // esi@11
  int v686; // eax@11
  int v687; // esi@11
  int v688; // eax@11
  int v689; // esi@11
  int v690; // eax@11
  int v691; // esi@11
  int v692; // eax@11
  int v693; // esi@11
  int v694; // eax@11
  int v695; // esi@11
  int v696; // eax@11
  int v697; // esi@11
  int v698; // eax@11
  int v699; // esi@11
  int v700; // eax@11
  int v701; // esi@11
  int v702; // eax@11
  int v703; // esi@11
  int v704; // eax@11
  int v705; // esi@11
  int v706; // eax@11
  int v707; // esi@11
  int v708; // eax@11
  int v709; // esi@11
  int v710; // eax@11
  int v711; // esi@11
  int v712; // eax@11
  int v713; // esi@11
  int v714; // eax@11
  int v715; // esi@11
  int v716; // eax@11
  int v717; // esi@11
  int v718; // eax@11
  int v719; // esi@11
  int v720; // eax@11
  int v721; // esi@11
  int v722; // eax@11
  int v723; // esi@11
  int v724; // eax@11
  int v725; // esi@11
  int v726; // eax@11
  int v727; // esi@11
  int v728; // eax@11
  int v729; // esi@11
  int v730; // eax@11
  int v731; // esi@11
  int v732; // eax@11
  int v733; // esi@11
  int v734; // eax@11
  int v735; // esi@11
  int v736; // eax@11
  int v737; // esi@11
  int v738; // eax@11
  int v739; // esi@11
  int v740; // eax@11
  int v741; // esi@11
  int v742; // eax@11
  int v743; // esi@11
  int v744; // eax@11
  int v745; // esi@11
  int v746; // eax@11
  int v747; // esi@11
  int v748; // eax@11
  int v749; // esi@11
  int v750; // eax@11
  int v751; // esi@11
  int v752; // eax@11
  int v753; // esi@11
  int v754; // eax@11
  int v755; // esi@11
  int v756; // eax@11
  int v757; // esi@11
  int v758; // eax@11
  int v759; // esi@11
  int v760; // eax@11
  int v761; // esi@11
  int v762; // eax@11
  int v763; // esi@11
  int v764; // eax@11
  int v765; // esi@11
  int v766; // eax@11
  int v767; // esi@11
  int v768; // eax@11
  int v769; // esi@11
  int v770; // eax@11
  int v771; // esi@11
  int v772; // eax@11
  int v773; // esi@11
  int v774; // eax@11
  int v775; // esi@11
  int v776; // eax@11
  int v777; // esi@11
  int v778; // eax@11
  int v779; // esi@11
  int v780; // eax@11
  int v781; // esi@11
  int v782; // eax@11
  int v783; // esi@11
  int v784; // eax@11
  int v785; // esi@11
  int v786; // eax@11
  int v787; // esi@11
  int v788; // eax@11
  int v789; // esi@11
  int v790; // eax@11
  int v791; // esi@11
  int v792; // eax@11
  int v793; // esi@11
  int v794; // eax@11
  int v795; // esi@11
  int v796; // eax@11
  int v797; // esi@11
  int v798; // eax@11
  int v799; // esi@11
  int v800; // eax@11
  int v801; // esi@11
  int v802; // eax@11
  int v803; // esi@11
  int v804; // eax@11
  int v805; // esi@11
  int v806; // eax@11
  int v807; // esi@11
  int v808; // eax@11
  int v809; // esi@11
  int v810; // eax@11
  int v811; // esi@11
  int v812; // eax@11
  int v813; // esi@11
  int v814; // eax@11
  int v815; // esi@11
  int v816; // eax@11
  int v817; // esi@11
  int v818; // eax@11
  int v819; // esi@11
  int v820; // eax@11
  int v821; // esi@11
  int v822; // eax@11
  int v823; // esi@11
  int v824; // eax@11
  int v825; // esi@11
  int v826; // eax@11
  int v827; // esi@11
  int v828; // eax@11
  int v829; // esi@11
  int v830; // eax@11
  int v831; // esi@11
  int v832; // eax@11
  int v833; // esi@11
  int v834; // eax@11
  int v835; // esi@11
  int v836; // eax@11
  int v837; // esi@11
  int v838; // eax@11
  int v839; // esi@11
  int v840; // eax@11
  int v841; // esi@11
  int v842; // eax@11
  int v843; // esi@11
  int v844; // eax@11
  int v845; // esi@11
  int v846; // eax@11
  int v847; // esi@11
  int v848; // eax@11
  int v849; // esi@11
  int v850; // eax@11
  int v851; // esi@11
  int v852; // eax@11
  int v853; // esi@11
  int v854; // eax@11
  int v855; // esi@11
  int v856; // eax@11
  int v857; // esi@11
  int v858; // eax@11
  int v859; // esi@11
  int v860; // eax@11
  int v861; // esi@11
  int v862; // eax@11
  int v863; // esi@11
  int v864; // eax@11
  int v865; // esi@11
  int v866; // eax@11
  int v867; // esi@11
  int v868; // eax@11
  int v869; // esi@11
  int v870; // eax@11
  int v871; // esi@11
  int v872; // eax@11
  int v873; // esi@11
  int v874; // eax@11
  int v875; // esi@11
  int v876; // eax@11
  int v877; // esi@11
  int v878; // eax@11
  int v879; // esi@11
  int v880; // eax@11
  int v881; // esi@11
  int v882; // eax@11
  int v883; // esi@11
  int v884; // eax@11
  int v885; // esi@11
  int v886; // eax@11
  int v887; // esi@11
  int v888; // eax@11
  int v889; // esi@11
  int v890; // eax@11
  int v891; // esi@11
  int v892; // eax@11
  int v893; // esi@11
  int v894; // eax@11
  int v895; // esi@11
  int v896; // eax@11
  int v897; // esi@11
  int v898; // eax@11
  int v899; // esi@11
  int v900; // eax@11
  int v901; // esi@11
  int v902; // eax@11
  int v903; // esi@11
  int v904; // eax@11
  int v905; // esi@11
  int v906; // eax@11
  int v907; // esi@11
  int v908; // eax@11
  int v909; // esi@11
  int v910; // eax@11
  int v911; // esi@11
  int v912; // eax@11
  int v913; // esi@11
  int v914; // eax@11
  int v915; // esi@11
  int v916; // eax@11
  int v917; // esi@11
  int v918; // eax@11
  int v919; // esi@11
  int v920; // eax@11
  int v921; // esi@11
  int v922; // eax@11
  int v923; // esi@11
  int v924; // eax@11
  int v925; // esi@11
  int v926; // eax@11
  int v927; // esi@11
  int v928; // eax@11
  int v929; // esi@11
  int v930; // eax@11
  int v931; // esi@11
  int v932; // eax@11
  int v933; // esi@11
  int v934; // eax@11
  int v935; // esi@11
  int v936; // eax@11
  int v937; // esi@11
  int v938; // eax@11
  int v939; // esi@11
  int v940; // eax@11
  int v941; // esi@11
  int v942; // eax@11
  int v943; // esi@11
  int v944; // eax@11
  int v945; // esi@11
  int v946; // eax@11
  int v947; // esi@11
  int v948; // eax@11
  int v949; // esi@11
  int v950; // eax@11
  int v951; // esi@11
  int v952; // eax@11
  int v953; // esi@11
  int v954; // eax@11
  int v955; // esi@11
  int v956; // eax@11
  int v957; // esi@11
  int v958; // eax@11
  int v959; // esi@11
  int v960; // eax@11
  int v961; // esi@11
  int v962; // eax@11
  int v963; // esi@11
  int v964; // eax@11
  int v965; // esi@11
  int v966; // eax@11
  int v967; // esi@11
  int v968; // eax@11
  int v969; // esi@11
  int v970; // eax@11
  int v971; // esi@11
  int v972; // eax@11
  int v973; // esi@11
  int v974; // eax@11
  int v975; // esi@11
  int v976; // eax@11
  int v977; // esi@11
  int v978; // eax@11
  int v979; // esi@11
  int v980; // eax@11
  int v981; // esi@11
  int v982; // eax@11
  int v983; // esi@11
  int v984; // eax@11
  int v985; // esi@11
  int v986; // eax@11
  int v987; // esi@11
  int v988; // eax@11
  int v989; // esi@11
  int v990; // eax@11
  int v991; // esi@11
  int v992; // eax@11
  int v993; // esi@11
  int v994; // eax@11
  int v995; // esi@11
  int v996; // eax@11
  int v997; // esi@11
  int v998; // eax@11
  int v999; // esi@11
  int v1000; // eax@11
  int v1001; // esi@11
  int v1002; // eax@11
  int v1003; // esi@11
  int v1004; // eax@11
  int v1005; // esi@11
  int v1006; // eax@11
  int v1007; // esi@11
  int v1008; // eax@11
  int v1009; // esi@11
  int v1010; // eax@11
  int v1011; // esi@11
  int v1012; // eax@11
  int v1013; // esi@11
  int v1014; // eax@11
  int v1015; // esi@11
  int v1016; // eax@11
  int v1017; // esi@11
  int v1018; // eax@11
  int v1019; // esi@11
  int v1020; // eax@11
  int v1021; // esi@11
  int v1022; // eax@11
  int v1023; // esi@11
  int v1024; // eax@11
  int v1025; // esi@11
  int v1026; // eax@11
  int v1027; // esi@11
  int v1028; // eax@11
  int v1029; // esi@11
  int v1030; // eax@11
  int v1031; // esi@11
  int v1032; // eax@11
  int v1033; // esi@11
  int v1034; // eax@11
  int v1035; // esi@11
  int v1036; // eax@11
  int v1037; // esi@11
  int v1038; // eax@11
  int v1039; // esi@11
  int v1040; // eax@11
  int v1041; // esi@11
  int v1042; // eax@11
  int v1043; // esi@11
  int v1044; // eax@11
  int v1045; // esi@11
  int v1046; // eax@11
  int v1047; // esi@11
  int v1048; // eax@11
  int v1049; // esi@11
  int v1050; // eax@11
  int v1051; // esi@11
  int v1052; // eax@11
  int v1053; // esi@11
  int v1054; // eax@11
  int v1055; // esi@11
  int v1056; // eax@11
  int v1057; // esi@11
  int v1058; // eax@11
  int v1059; // esi@11
  int v1060; // eax@11
  int v1061; // esi@11
  int v1062; // eax@11
  int v1063; // esi@11
  int v1064; // eax@11
  int v1065; // esi@11
  int v1066; // eax@11
  int v1067; // esi@11
  int v1068; // eax@11
  int v1069; // esi@11
  int v1070; // eax@11
  int v1071; // esi@11
  int v1072; // eax@11
  int v1073; // esi@11
  int v1074; // eax@11
  int v1075; // esi@11
  int v1076; // eax@11
  int v1077; // esi@11
  int v1078; // eax@11
  int v1079; // esi@11
  int v1080; // eax@11
  int v1081; // esi@11
  int v1082; // eax@11
  int v1083; // esi@11
  int v1084; // eax@11
  int v1085; // esi@11
  int v1086; // eax@11
  int v1087; // esi@11
  int v1088; // eax@11
  int v1089; // esi@11
  int v1090; // eax@11
  int v1091; // esi@11
  int v1092; // eax@11
  int v1093; // esi@11
  int v1094; // eax@11
  int v1095; // esi@11
  int v1096; // eax@11
  int v1097; // esi@11
  int v1098; // eax@11
  int v1099; // esi@11
  int v1100; // eax@11
  int v1101; // esi@11
  int v1102; // eax@11
  int v1103; // esi@11
  int v1104; // eax@11
  int v1105; // esi@11
  int v1106; // eax@11
  int v1107; // esi@11
  int v1108; // eax@11
  int v1109; // esi@11
  int v1110; // eax@11
  int v1111; // esi@11
  int v1112; // eax@11
  int v1113; // esi@11
  int v1114; // eax@11
  int v1115; // esi@11
  int v1116; // eax@11
  int v1117; // esi@11
  int v1118; // eax@11
  int v1119; // esi@11
  int v1120; // eax@11
  int v1121; // esi@11
  int v1122; // eax@11
  int v1123; // esi@11
  int v1124; // eax@11
  int v1125; // esi@11
  int v1126; // eax@11
  int v1127; // esi@11
  int v1128; // eax@11
  int v1129; // esi@11
  int v1130; // eax@11
  int v1131; // esi@11
  int v1132; // eax@11
  int v1133; // esi@11
  int v1134; // eax@11
  int v1135; // esi@11
  int v1136; // eax@11
  int v1137; // esi@11
  int v1138; // eax@11
  int v1139; // esi@11
  int v1140; // eax@11
  int v1141; // esi@11
  int v1142; // eax@11
  int v1143; // esi@11
  int v1144; // eax@11
  int v1145; // esi@11
  int v1146; // eax@11
  int v1147; // esi@11
  int v1148; // eax@11
  int v1149; // esi@11
  int v1150; // eax@11
  int v1151; // esi@11
  int v1152; // eax@11
  int v1153; // esi@11
  int v1154; // eax@11
  int v1155; // esi@11
  int v1156; // eax@11
  int v1157; // esi@11
  int v1158; // eax@11
  int v1159; // esi@11
  int v1160; // eax@11
  int v1161; // esi@11
  int v1162; // eax@11
  int v1163; // esi@11
  int v1164; // eax@11
  int v1165; // esi@11
  int v1166; // eax@11
  int v1167; // esi@11
  int v1168; // eax@11
  int v1169; // esi@11
  int v1170; // eax@11
  int v1171; // esi@11
  int v1172; // eax@11
  int v1173; // esi@11
  int v1174; // eax@11
  int v1175; // esi@11
  int v1176; // eax@11
  int v1177; // esi@11
  int v1178; // eax@11
  int v1179; // esi@11
  int v1180; // eax@11
  int v1181; // esi@11
  int v1182; // eax@11
  int v1183; // esi@11
  int v1184; // eax@11
  int v1185; // esi@11
  int v1186; // eax@11
  int v1187; // esi@11
  int v1188; // eax@11
  int v1189; // esi@11
  int v1190; // eax@11
  int v1191; // esi@11
  int v1192; // eax@11
  int v1193; // esi@11
  int v1194; // eax@11
  int v1195; // esi@11
  int v1196; // eax@11
  int v1197; // esi@11
  int v1198; // eax@11
  int v1199; // esi@11
  int v1200; // eax@11
  int v1201; // esi@11
  int v1202; // eax@11
  int v1203; // esi@11
  int v1204; // eax@11
  int v1205; // esi@11
  int v1206; // eax@11
  int v1207; // esi@11
  int v1208; // eax@11
  int v1209; // esi@11
  int v1210; // eax@11
  int v1211; // esi@11
  int v1212; // eax@11
  int v1213; // esi@11
  int v1214; // eax@11
  int v1215; // esi@11
  int v1216; // eax@11
  int v1217; // esi@11
  int v1218; // eax@11
  int v1219; // esi@11
  int v1220; // eax@11
  int v1221; // esi@11
  int v1222; // eax@11
  int v1223; // esi@11
  int v1224; // eax@11
  int v1225; // esi@11
  int v1226; // eax@11
  int v1227; // esi@11
  int v1228; // eax@11
  int v1229; // esi@11
  int v1230; // eax@11
  int v1231; // esi@11
  int v1232; // eax@11
  int v1233; // esi@11
  int v1234; // eax@11
  int v1235; // esi@11
  int v1236; // eax@11
  int v1237; // esi@11
  int v1238; // eax@11
  int v1239; // esi@11
  int v1240; // eax@11
  int v1241; // esi@11
  int v1242; // eax@11
  int v1243; // esi@11
  int v1244; // eax@11
  int v1245; // esi@11
  int v1246; // eax@11
  int v1247; // esi@11
  int v1248; // eax@11
  int v1249; // esi@11
  int v1250; // eax@11
  int v1251; // esi@11
  int v1252; // eax@11
  int v1253; // esi@11
  int v1254; // eax@11
  int v1255; // esi@11
  int v1256; // eax@11
  int v1257; // esi@11
  int v1258; // eax@11
  int v1259; // esi@11
  int v1260; // eax@11
  int v1261; // esi@11
  int v1262; // eax@11
  int v1263; // esi@11
  int v1264; // eax@11
  int v1265; // esi@11
  int v1266; // eax@11
  int v1267; // esi@11
  int v1268; // eax@11
  int v1269; // esi@11
  int v1270; // eax@11
  int v1271; // esi@11
  int v1272; // eax@11
  int v1273; // esi@11
  int v1274; // eax@11
  int v1275; // esi@11
  int v1276; // eax@11
  int v1277; // esi@11
  int v1278; // eax@11
  int v1279; // esi@11
  int v1280; // eax@11
  int v1281; // esi@11
  int v1282; // eax@11
  int v1283; // esi@11
  int v1284; // eax@11
  int v1285; // esi@11
  int v1286; // eax@11
  int v1287; // esi@11
  int v1288; // eax@11
  int v1289; // esi@11
  int v1290; // eax@11
  int v1291; // esi@11
  int v1292; // eax@11
  int v1293; // esi@11
  int v1294; // eax@11
  int v1295; // esi@11
  int v1296; // eax@11
  int v1297; // esi@11
  int v1298; // eax@11
  int v1299; // esi@11
  int v1300; // eax@11
  int v1301; // esi@11
  int v1302; // eax@11
  int v1303; // esi@11
  int v1304; // eax@11
  int v1305; // esi@11
  int v1306; // eax@11
  int v1307; // esi@11
  int v1308; // eax@11
  int v1309; // esi@11
  int v1310; // eax@11
  int v1311; // esi@11
  int v1312; // eax@11
  int v1313; // esi@11
  int v1314; // eax@11
  int v1315; // esi@11
  int v1316; // eax@11
  int v1317; // esi@11
  int v1318; // eax@11
  int v1319; // esi@11
  int v1320; // eax@11
  int v1321; // esi@11
  int v1322; // eax@11
  int v1323; // esi@11
  int v1324; // eax@11
  int v1325; // esi@11
  int v1326; // eax@11
  int v1327; // esi@11
  int v1328; // eax@11
  int v1329; // esi@11
  int v1330; // eax@11
  int v1331; // esi@11
  int v1332; // eax@11
  int v1333; // esi@11
  int v1334; // eax@11
  int v1335; // esi@11
  int v1336; // eax@11
  int v1337; // esi@11
  int v1338; // eax@11
  int v1339; // esi@11
  int v1340; // eax@11
  int v1341; // esi@11
  int v1342; // eax@11
  int v1343; // esi@11
  int v1344; // eax@11
  int v1345; // esi@11
  int v1346; // eax@11
  int v1347; // esi@11
  int v1348; // eax@11
  int v1349; // esi@11
  int v1350; // eax@11
  int v1351; // esi@11
  int v1352; // eax@11
  int v1353; // esi@11
  int v1354; // eax@11
  int v1355; // esi@11
  int v1356; // eax@11
  int v1357; // esi@11
  int v1358; // eax@11
  int v1359; // esi@11
  int v1360; // eax@11
  int v1361; // esi@11
  int v1362; // eax@11
  int v1363; // esi@11
  int v1364; // eax@11
  int v1365; // esi@11
  int v1366; // eax@11
  int v1367; // esi@11
  int v1368; // eax@11
  int v1369; // esi@11
  int v1370; // eax@11
  int v1371; // esi@11
  int v1372; // eax@11
  int v1373; // esi@11
  int v1374; // eax@11
  int v1375; // esi@11
  int v1376; // eax@11
  int v1377; // esi@11
  int v1378; // eax@11
  int v1379; // esi@11
  int v1380; // eax@11
  int v1381; // esi@11
  int v1382; // eax@11
  int v1383; // esi@11
  int v1384; // eax@11
  int v1385; // esi@11
  int v1386; // eax@11
  int v1387; // esi@11
  int v1388; // eax@11
  int v1389; // esi@11
  int v1390; // eax@11
  int v1391; // esi@11
  int v1392; // eax@11
  int v1393; // esi@11
  int v1394; // eax@11
  int v1395; // esi@11
  int v1396; // eax@11
  int v1397; // esi@11
  int v1398; // eax@11
  int v1399; // esi@11
  int v1400; // eax@11
  int v1401; // esi@11
  int v1402; // eax@11
  int v1403; // esi@11
  int v1404; // eax@11
  int v1405; // esi@11
  int v1406; // eax@11
  int v1407; // esi@11
  int v1408; // eax@11
  int v1409; // esi@11
  int v1410; // eax@11
  int v1411; // esi@11
  int v1412; // eax@11
  int v1413; // esi@11
  int v1414; // eax@11
  int v1415; // esi@11
  int v1416; // eax@11
  int v1417; // esi@11
  int v1418; // eax@11
  int v1419; // esi@11
  int v1420; // eax@11
  int v1421; // esi@11
  int v1422; // eax@11
  int v1423; // esi@11
  int v1424; // eax@11
  int v1425; // esi@11
  int v1426; // eax@11
  int v1427; // esi@11
  int v1428; // eax@11
  int v1429; // esi@11
  int v1430; // eax@11
  int v1431; // esi@11
  int v1432; // eax@11
  int v1433; // esi@11
  int v1434; // eax@11
  int v1435; // esi@11
  int v1436; // eax@11
  int v1437; // esi@11
  int v1438; // eax@11
  int v1439; // esi@11
  int v1440; // eax@11
  int v1441; // esi@11
  int v1442; // eax@11
  int v1443; // esi@11
  int v1444; // eax@11
  int v1445; // esi@11
  int v1446; // eax@11
  int v1447; // esi@11
  int v1448; // eax@11
  int v1449; // esi@11
  int v1450; // eax@11
  int v1451; // esi@11
  int v1452; // eax@11
  int v1453; // esi@11
  int v1454; // eax@11
  int v1455; // esi@11
  int v1456; // eax@11
  int v1457; // esi@11
  int v1458; // eax@11
  int v1459; // esi@11
  int v1460; // eax@11
  int v1461; // esi@11
  int v1462; // eax@11
  int v1463; // esi@11
  int v1464; // eax@11
  int v1465; // esi@11
  int v1466; // eax@11
  int v1467; // esi@11
  int v1468; // eax@11
  int v1469; // esi@11
  int v1470; // eax@11
  int v1471; // esi@11
  int v1472; // eax@11
  int v1473; // esi@11
  int v1474; // eax@11
  int v1475; // esi@11
  int v1476; // eax@11
  int v1477; // esi@11
  int v1478; // eax@11
  int v1479; // esi@11
  int v1480; // eax@11
  int v1481; // esi@11
  int v1482; // eax@11
  int v1483; // esi@11
  int v1484; // eax@11
  int v1485; // esi@11
  int v1486; // eax@11
  int v1487; // esi@11
  int v1488; // eax@11
  int v1489; // esi@11
  int v1490; // eax@11
  int v1491; // esi@11
  int v1492; // eax@11
  int v1493; // esi@11
  int v1494; // eax@11
  int v1495; // esi@11
  int v1496; // eax@11
  int v1497; // esi@11
  int v1498; // eax@11
  int v1499; // esi@11
  int v1500; // eax@11
  int v1501; // esi@11
  int v1502; // eax@11
  int v1503; // esi@11
  int v1504; // eax@11
  int v1505; // esi@11
  int v1506; // eax@11
  int v1507; // esi@11
  int v1508; // eax@11
  int v1509; // esi@11
  int v1510; // eax@11
  int v1511; // esi@11
  int v1512; // eax@11
  int v1513; // esi@11
  int v1514; // eax@11
  int v1515; // esi@11
  int v1516; // eax@11
  int v1517; // esi@11
  int v1518; // eax@11
  int v1519; // esi@11
  int v1520; // eax@11
  int v1521; // esi@11
  int v1522; // eax@11
  int v1523; // esi@11
  int v1524; // eax@11
  int v1525; // esi@11
  int v1526; // eax@11
  int v1527; // esi@11
  int v1528; // eax@11
  int v1529; // esi@11
  int v1530; // eax@11
  int v1531; // esi@11
  int v1532; // eax@11
  int v1533; // esi@11
  int v1534; // eax@11
  int v1535; // esi@11
  int v1536; // eax@11
  int v1537; // esi@11
  int v1538; // eax@11
  int v1539; // esi@11
  int v1540; // eax@11
  int v1541; // esi@11
  int v1542; // eax@11
  int v1543; // esi@11
  int v1544; // eax@11
  int v1545; // esi@11
  int v1546; // eax@11
  int v1547; // esi@11
  int v1548; // eax@11
  int v1549; // esi@11
  int v1550; // eax@11
  int v1551; // esi@11
  int v1552; // eax@11
  int v1553; // esi@11
  int v1554; // eax@11
  int v1555; // esi@11
  int v1556; // eax@11
  int v1557; // esi@11
  int v1558; // eax@11
  int v1559; // esi@11
  int v1560; // eax@11
  int v1561; // esi@11
  int v1562; // eax@11
  int v1563; // esi@11
  int v1564; // eax@11
  int v1565; // esi@11
  int v1566; // eax@11
  int v1567; // esi@11
  int v1568; // eax@11
  int v1569; // esi@11
  int v1570; // eax@11
  int v1571; // esi@11
  int v1572; // eax@11
  int v1573; // esi@11
  int v1574; // eax@11
  int v1575; // esi@11
  int v1576; // eax@11
  int v1577; // esi@11
  int v1578; // eax@11
  int v1579; // esi@11
  int v1580; // eax@11
  int v1581; // esi@11
  int v1582; // eax@11
  int v1583; // esi@11
  int v1584; // eax@11
  int v1585; // esi@11
  int v1586; // eax@11
  int v1587; // esi@11
  int v1588; // eax@11
  int v1589; // esi@11
  int v1590; // eax@11
  int v1591; // esi@11
  int v1592; // eax@11
  int v1593; // esi@11
  int v1594; // eax@11
  int v1595; // esi@11
  int v1596; // eax@11
  int v1597; // esi@11
  int v1598; // eax@11
  int v1599; // esi@11
  int v1600; // eax@11
  int v1601; // esi@11
  int v1602; // eax@11
  int v1603; // esi@11
  int v1604; // eax@11
  int v1605; // esi@11
  int v1606; // eax@11
  int v1607; // esi@11
  int v1608; // eax@11
  int v1609; // esi@11
  int v1610; // eax@11
  int v1611; // esi@11
  int v1612; // eax@11
  int v1613; // esi@11
  int v1614; // eax@11
  int v1615; // esi@11
  int v1616; // eax@11
  int v1617; // esi@11
  int v1618; // eax@11
  int v1619; // esi@11
  int v1620; // eax@11
  int v1621; // esi@11
  int v1622; // eax@11
  int v1623; // esi@11
  int v1624; // eax@11
  int v1625; // esi@11
  int v1626; // eax@11
  int v1627; // esi@11
  int v1628; // eax@11
  int v1629; // esi@11
  int v1630; // eax@11
  int v1631; // esi@11
  int v1632; // eax@11
  int v1633; // esi@11
  int v1634; // eax@11
  int v1635; // esi@11
  int v1636; // eax@11
  int v1637; // esi@11
  int v1638; // eax@11
  int v1639; // esi@11
  int v1640; // eax@11
  int v1641; // esi@11
  int v1642; // eax@11
  int v1643; // esi@11
  int v1644; // eax@11
  int v1645; // esi@11
  int v1646; // eax@11
  int v1647; // esi@11
  int v1648; // eax@11
  int v1649; // esi@11
  int v1650; // eax@11
  int v1651; // esi@11
  int v1652; // eax@11
  int v1653; // esi@11
  int v1654; // eax@11
  int v1655; // esi@11
  int v1656; // eax@11
  int v1657; // esi@11
  int v1658; // eax@11
  int v1659; // esi@11
  int v1660; // eax@11
  int v1661; // esi@11
  int v1662; // eax@11
  int v1663; // esi@11
  int v1664; // eax@11
  int v1665; // esi@11
  int v1666; // eax@11
  int v1667; // esi@11
  int v1668; // eax@11
  int v1669; // esi@11
  int v1670; // eax@11
  int v1671; // esi@11
  int v1672; // eax@11
  int v1673; // esi@11
  int v1674; // eax@11
  int v1675; // esi@11
  int v1676; // eax@11
  int v1677; // esi@11
  int v1678; // eax@11
  int v1679; // esi@11
  int v1680; // eax@11
  int v1681; // esi@11
  int v1682; // eax@11
  int v1683; // esi@11
  int v1684; // eax@11
  int v1685; // esi@11
  int v1686; // eax@11
  int v1687; // esi@11
  int v1688; // eax@11
  int v1689; // esi@11
  int v1690; // eax@11
  int v1691; // esi@11
  int v1692; // eax@11
  int v1693; // esi@11
  int v1694; // eax@11
  int v1695; // esi@11
  int v1696; // eax@11
  int v1697; // esi@11
  int v1698; // eax@11
  int v1699; // esi@11
  int v1700; // eax@11
  int v1701; // esi@11
  int v1702; // eax@11
  int v1703; // esi@11
  int v1704; // eax@11
  int v1705; // esi@11
  int v1706; // eax@11
  int v1707; // esi@11
  int v1708; // eax@11
  int v1709; // esi@11
  int v1710; // eax@11
  int v1711; // esi@11
  int v1712; // eax@11
  int v1713; // esi@11
  int v1714; // eax@11
  int v1715; // esi@11
  int v1716; // eax@11
  int v1717; // esi@11
  int v1718; // eax@11
  int v1719; // esi@11
  int v1720; // eax@11
  int v1721; // esi@11
  int v1722; // eax@11
  int v1723; // esi@11
  int v1724; // eax@11
  int v1725; // esi@11
  int v1726; // eax@11
  int v1727; // esi@11
  int v1728; // eax@11
  int v1729; // esi@11
  int v1730; // eax@11
  int v1731; // esi@11
  int v1732; // eax@11
  int v1733; // esi@11
  int v1734; // eax@11
  int v1735; // esi@11
  int v1736; // eax@11
  int v1737; // esi@11
  int v1738; // eax@11
  int v1739; // esi@11
  int v1740; // eax@11
  int v1741; // esi@11
  int v1742; // eax@11
  int v1743; // esi@11
  int v1744; // eax@11
  int v1745; // esi@11
  int v1746; // eax@11
  int v1747; // esi@11
  int v1748; // eax@11
  int v1749; // esi@11
  int v1750; // eax@11
  int v1751; // esi@11
  int v1752; // eax@11
  int v1753; // esi@11
  int v1754; // eax@11
  int v1755; // esi@11
  int v1756; // eax@11
  int v1757; // esi@11
  int v1758; // eax@11
  int v1759; // esi@11
  int v1760; // eax@11
  int v1761; // esi@11
  int v1762; // eax@11
  int v1763; // esi@11
  int v1764; // eax@11
  int v1765; // esi@11
  int v1766; // eax@11
  int v1767; // esi@11
  int v1768; // eax@11
  int v1769; // esi@11
  int v1770; // eax@11
  int v1771; // esi@11
  int v1772; // eax@11
  int v1773; // esi@11
  int v1774; // eax@11
  int v1775; // esi@11
  int v1776; // eax@11
  int v1777; // esi@11
  int v1778; // eax@11
  int v1779; // esi@11
  int v1780; // eax@11
  int v1781; // esi@11
  int v1782; // eax@11
  int v1783; // esi@11
  int v1784; // eax@11
  int v1785; // esi@11
  int v1786; // eax@11
  int v1787; // esi@11
  int v1788; // eax@11
  int v1789; // esi@11
  int v1790; // eax@11
  int v1791; // esi@11
  int v1792; // eax@11
  int v1793; // esi@11
  int v1794; // eax@11
  int v1795; // esi@11
  int v1796; // eax@11
  int v1797; // esi@11
  int v1798; // eax@11
  int v1799; // esi@11
  int v1800; // eax@11
  int v1801; // esi@11
  int v1802; // eax@11
  int v1803; // esi@11
  int v1804; // eax@11
  int v1805; // esi@11
  int v1806; // eax@11
  int v1807; // esi@11
  int v1808; // eax@11
  int v1809; // esi@11
  int v1810; // eax@11
  int v1811; // esi@11
  int v1812; // eax@11
  int v1813; // esi@11
  int v1814; // eax@11
  int v1815; // esi@11
  int v1816; // eax@11
  int v1817; // esi@11
  int v1818; // eax@11
  int v1819; // esi@11
  int v1820; // eax@11
  int v1821; // esi@11
  int v1822; // eax@11
  int v1823; // esi@11
  int v1824; // eax@11
  int v1825; // esi@11
  int v1826; // eax@11
  int v1827; // esi@11
  int v1828; // eax@11
  int v1829; // esi@11
  int v1830; // eax@11
  int v1831; // esi@11
  int v1832; // eax@11
  int v1833; // esi@11
  int v1834; // eax@11
  int v1835; // esi@11
  int v1836; // eax@11
  int v1837; // esi@11
  int v1838; // eax@11
  int v1839; // esi@11
  int v1840; // eax@11
  int v1841; // esi@11
  int v1842; // eax@11
  int v1843; // esi@11
  int v1844; // eax@11
  int v1845; // esi@11
  int v1846; // eax@11
  int v1847; // esi@11
  int v1848; // eax@11
  int v1849; // esi@11
  int v1850; // eax@11
  int v1851; // esi@11
  int v1852; // eax@11
  int v1853; // esi@11
  int v1854; // eax@11
  int v1855; // esi@11
  int v1856; // eax@11
  int v1857; // esi@11
  int v1858; // eax@11
  int v1859; // esi@11
  int v1860; // eax@11
  int v1861; // esi@11
  int v1862; // eax@11
  int v1863; // esi@11
  int v1864; // eax@11
  int v1865; // esi@11
  int v1866; // eax@11
  int v1867; // esi@11
  int v1868; // eax@11
  int v1869; // esi@11
  int v1870; // eax@11
  int v1871; // esi@11
  int v1872; // eax@11
  int v1873; // esi@11
  int v1874; // eax@11
  int v1875; // esi@11
  int v1876; // eax@11
  int v1877; // esi@11
  int v1878; // eax@11
  int v1879; // esi@11
  int v1880; // eax@11
  int v1881; // esi@11
  int v1882; // eax@11
  int v1883; // esi@11
  int v1884; // eax@11
  int v1885; // esi@11
  int v1886; // eax@11
  int v1887; // esi@11
  int v1888; // eax@11
  int v1889; // esi@11
  int v1890; // eax@11
  int v1891; // esi@11
  int v1892; // eax@11
  int v1893; // esi@11
  int v1894; // eax@11
  int v1895; // esi@11
  int v1896; // eax@11
  int v1897; // esi@11
  int v1898; // eax@11
  int v1899; // esi@11
  int v1900; // eax@11
  int v1901; // esi@11
  int v1902; // eax@11
  int v1903; // esi@11
  int v1904; // eax@11
  int v1905; // esi@11
  int v1906; // eax@11
  int v1907; // esi@11
  int v1908; // eax@11
  int v1909; // esi@11
  int v1910; // eax@11
  int v1911; // esi@11
  int v1912; // eax@11
  int v1913; // esi@11
  int v1914; // eax@11
  int v1915; // esi@11
  int v1916; // eax@11
  int v1917; // esi@11
  int v1918; // eax@11
  int v1919; // esi@11
  int v1920; // eax@11
  int v1921; // esi@11
  int v1922; // eax@11
  int v1923; // esi@11
  int v1924; // eax@11
  int v1925; // esi@11
  int v1926; // eax@11
  int v1927; // esi@11
  int v1928; // eax@11
  int v1929; // esi@11
  int v1930; // eax@11
  int v1931; // esi@11
  int v1932; // eax@11
  int v1933; // esi@11
  int v1934; // eax@11
  int v1935; // esi@11
  int v1936; // eax@11
  int v1937; // esi@11
  int v1938; // eax@11
  int v1939; // esi@11
  int v1940; // eax@11
  int v1941; // esi@11
  int v1942; // eax@11
  int v1943; // esi@11
  int v1944; // eax@11
  int v1945; // esi@11
  int v1946; // eax@11
  int v1947; // esi@11
  int v1948; // eax@11
  int v1949; // esi@11
  int v1950; // eax@11
  int v1951; // esi@11
  int v1952; // eax@11
  int v1953; // esi@11
  int v1954; // eax@11
  int v1955; // esi@11
  int v1956; // eax@11
  int v1957; // esi@11
  int v1958; // eax@11
  int v1959; // esi@11
  int v1960; // eax@11
  int v1961; // esi@11
  int v1962; // eax@11
  int v1963; // esi@11
  int v1964; // eax@11
  int v1965; // esi@11
  int v1966; // eax@11
  int v1967; // esi@11
  int v1968; // eax@11
  int v1969; // esi@11
  int v1970; // eax@11
  int v1971; // esi@11
  int v1972; // eax@11
  int v1973; // esi@11
  int v1974; // eax@11
  int v1975; // esi@11
  int v1976; // eax@11
  int v1977; // esi@11
  int v1978; // eax@11
  int v1979; // esi@11
  int v1980; // eax@11
  int v1981; // esi@11
  int v1982; // eax@11
  int v1983; // esi@11
  int v1984; // eax@11
  int v1985; // esi@11
  int v1986; // eax@11
  int v1987; // esi@11
  int v1988; // eax@11
  int v1989; // esi@11
  int v1990; // eax@11
  int v1991; // esi@11
  int v1992; // eax@11
  int v1993; // esi@11
  int v1994; // eax@11
  int v1995; // esi@11
  int v1996; // eax@11
  int v1997; // esi@11
  int v1998; // eax@11
  int v1999; // esi@11
  int v2000; // eax@11
  int v2001; // esi@11
  int v2002; // eax@11
  int v2003; // esi@11
  int v2004; // eax@11
  int v2005; // esi@11
  int v2006; // eax@11
  int v2007; // esi@11
  int v2008; // eax@11
  int v2009; // esi@11
  int v2010; // eax@11
  int v2011; // esi@11
  int v2012; // eax@11
  int v2013; // esi@11
  int v2014; // eax@11
  int v2015; // esi@11
  int v2016; // eax@11
  int v2017; // esi@11
  int v2018; // eax@11
  int v2019; // esi@11
  int v2020; // eax@11
  int v2021; // esi@11
  int v2022; // eax@11
  int v2023; // esi@11
  int v2024; // eax@11
  int v2025; // esi@11
  int v2026; // eax@11
  int v2027; // esi@11
  int v2028; // eax@11
  int v2029; // esi@11
  int v2030; // eax@11
  int v2031; // esi@11
  int v2032; // eax@11
  int v2033; // esi@11
  int v2034; // eax@11
  int v2035; // esi@11
  int v2036; // eax@11
  int v2037; // esi@11
  int v2038; // eax@11
  int v2039; // esi@11
  int v2040; // eax@11
  int v2041; // esi@11
  int v2042; // eax@11
  int v2043; // esi@11
  int v2044; // eax@11
  int v2045; // esi@11
  int v2046; // eax@11
  int v2047; // esi@11
  int v2048; // eax@11
  int v2049; // esi@11
  int v2050; // eax@11
  int v2051; // esi@11
  int v2052; // eax@11
  int v2053; // esi@11
  int v2054; // eax@11
  int v2055; // esi@11
  int v2056; // eax@11
  int v2057; // esi@11
  int v2058; // eax@11
  int v2059; // esi@11
  int v2060; // eax@11
  int v2061; // esi@11
  int v2062; // eax@11
  int v2063; // esi@11
  int v2064; // eax@11
  int v2065; // esi@11
  int v2066; // eax@11
  int v2067; // esi@11
  int v2068; // eax@11
  int v2069; // esi@11
  int v2070; // eax@11
  int v2071; // esi@11
  int v2072; // eax@11
  int v2073; // esi@11
  int v2074; // eax@11
  int v2075; // esi@11
  int v2076; // eax@11
  int v2077; // esi@11
  int v2078; // eax@11
  int v2079; // esi@11
  int v2080; // eax@11
  int v2081; // esi@11
  int v2082; // eax@11
  int v2083; // esi@11
  int v2084; // eax@11
  int v2085; // esi@11
  int v2086; // eax@11
  int v2087; // esi@11
  int v2088; // eax@11
  int v2089; // esi@11
  int v2090; // eax@11
  int v2091; // esi@11
  int v2092; // eax@11
  int v2093; // esi@11
  int v2094; // eax@11
  int v2095; // esi@11
  int v2096; // eax@11
  int v2097; // esi@11
  int v2098; // eax@11
  int v2099; // esi@11
  int v2100; // eax@11
  int v2101; // esi@11
  int v2102; // eax@11
  int v2103; // esi@11
  int v2104; // eax@11
  int v2105; // esi@11
  int v2106; // eax@11
  int v2107; // esi@11
  int v2108; // eax@11
  int v2109; // esi@11
  int v2110; // eax@11
  int v2111; // esi@11
  int v2112; // eax@11
  int v2113; // esi@11
  int v2114; // eax@11
  int v2115; // esi@11
  int v2116; // eax@11
  int v2117; // esi@11
  int v2118; // eax@11
  int v2119; // esi@11
  int v2120; // eax@11
  int v2121; // esi@11
  int v2122; // eax@11
  int v2123; // esi@11
  int v2124; // eax@11
  int v2125; // esi@11
  int v2126; // eax@11
  int v2127; // esi@11
  int v2128; // eax@11
  int v2129; // esi@11
  int v2130; // eax@11
  int v2131; // esi@11
  int v2132; // eax@11
  int v2133; // esi@11
  int v2134; // eax@11
  int v2135; // esi@11
  int v2136; // eax@11
  int v2137; // esi@11
  int v2138; // eax@11
  int v2139; // esi@11
  int v2140; // eax@11
  int v2141; // esi@11
  int v2142; // eax@11
  int v2143; // esi@11
  int v2144; // eax@11
  int v2145; // esi@11
  int v2146; // eax@11
  int v2147; // esi@11
  int v2148; // eax@11
  int v2149; // esi@11
  int v2150; // eax@11
  int v2151; // esi@11
  int v2152; // eax@11
  int v2153; // esi@11
  int v2154; // eax@11
  int v2155; // esi@11
  int v2156; // eax@11
  int v2157; // esi@11
  int v2158; // eax@11
  int v2159; // esi@11
  int v2160; // eax@11
  int v2161; // esi@11
  int v2162; // eax@11
  int v2163; // esi@11
  int v2164; // eax@11
  int v2165; // esi@11
  int v2166; // eax@11
  int v2167; // esi@11
  int v2168; // eax@11
  int v2169; // esi@11
  int v2170; // eax@11
  int v2171; // esi@11
  int v2172; // eax@11
  int v2173; // esi@11
  int v2174; // eax@11
  int v2175; // esi@11
  int v2176; // eax@11
  int v2177; // esi@11
  int v2178; // eax@11
  int v2179; // esi@11
  int v2180; // eax@11
  int v2181; // esi@11
  int v2182; // eax@11
  int v2183; // esi@11
  int v2184; // eax@11
  int v2185; // esi@11
  int v2186; // eax@11
  int v2187; // esi@11
  int v2188; // eax@11
  int v2189; // esi@11
  int v2190; // eax@11
  int v2191; // esi@11
  int v2192; // eax@11
  int v2193; // esi@11
  int v2194; // eax@11
  int v2195; // esi@11
  int v2196; // eax@11
  int v2197; // esi@11
  int v2198; // eax@11
  int v2199; // esi@11
  int v2200; // eax@11
  int v2201; // esi@11
  int v2202; // eax@11
  int v2203; // esi@11
  int v2204; // eax@11
  int v2205; // esi@11
  int v2206; // eax@11
  int v2207; // esi@11
  int v2208; // eax@11
  int v2209; // esi@11
  int v2210; // eax@11
  int v2211; // esi@11
  int v2212; // eax@11
  int v2213; // esi@11
  int v2214; // eax@11
  int v2215; // esi@11
  int v2216; // eax@11
  int v2217; // esi@11
  int v2218; // eax@11
  int v2219; // esi@11
  int v2220; // eax@11
  int v2221; // esi@11
  int v2222; // eax@11
  int v2223; // esi@11
  int v2224; // eax@11
  int v2225; // esi@11
  int v2226; // eax@11
  int v2227; // esi@11
  int v2228; // eax@11
  int v2229; // esi@11
  int v2230; // eax@11
  int v2231; // esi@11
  int v2232; // eax@11
  int v2233; // esi@11
  int v2234; // eax@11
  int v2235; // esi@11
  int v2236; // eax@11
  int v2237; // esi@11
  int v2238; // eax@11
  int v2239; // esi@11
  int v2240; // eax@11
  int v2241; // esi@11
  int v2242; // eax@11
  int v2243; // esi@11
  int v2244; // eax@11
  int v2245; // esi@11
  int v2246; // eax@11
  int v2247; // esi@11
  int v2248; // eax@11
  int v2249; // esi@11
  int v2250; // eax@11
  int v2251; // esi@11
  int v2252; // eax@11
  int v2253; // esi@11
  int v2254; // eax@11
  int v2255; // esi@11
  int v2256; // eax@11
  int v2257; // esi@11
  int v2258; // eax@11
  int v2259; // esi@11
  int v2260; // eax@11
  int v2261; // esi@11
  int v2262; // eax@11
  int v2263; // esi@11
  int v2264; // eax@11
  int v2265; // esi@11
  int v2266; // eax@11
  int v2267; // esi@11
  int v2268; // eax@11
  int v2269; // esi@11
  int v2270; // eax@11
  int v2271; // esi@11
  int v2272; // eax@11
  int v2273; // esi@11
  int v2274; // eax@11
  int v2275; // esi@11
  int v2276; // eax@11
  int v2277; // esi@11
  int v2278; // eax@11
  int v2279; // esi@11
  int v2280; // eax@11
  int v2281; // esi@11
  int v2282; // eax@11
  int v2283; // esi@11
  int v2284; // eax@11
  int v2285; // esi@11
  int v2286; // eax@11
  int v2287; // esi@11
  int v2288; // eax@11
  int v2289; // esi@11
  int v2290; // eax@11
  int v2291; // esi@11
  int v2292; // eax@11
  int v2293; // esi@11
  int v2294; // eax@11
  int v2295; // esi@11
  int v2296; // eax@11
  int v2297; // esi@11
  int v2298; // eax@11
  int v2299; // esi@11
  int v2300; // eax@11
  int v2301; // esi@11
  int v2302; // eax@11
  int v2303; // esi@11
  int v2304; // eax@11
  int v2305; // esi@11
  int v2306; // eax@11
  int v2307; // esi@11
  int v2308; // eax@11
  int v2309; // esi@11
  int v2310; // eax@11
  int v2311; // esi@11
  int v2312; // eax@11
  int v2313; // esi@11
  int v2314; // eax@11
  int v2315; // esi@11
  int v2316; // eax@11
  int v2317; // esi@11
  int v2318; // eax@11
  int v2319; // esi@11
  int v2320; // eax@11
  int v2321; // esi@11
  int v2322; // eax@11
  int v2323; // esi@11
  int v2324; // eax@11
  int v2325; // esi@11
  int v2326; // eax@11
  int v2327; // esi@11
  int v2328; // eax@11
  int v2329; // esi@11
  int v2330; // eax@11
  int v2331; // esi@11
  int v2332; // eax@11
  int v2333; // esi@11
  int v2334; // eax@11
  int v2335; // esi@11
  int v2336; // eax@11
  int v2337; // esi@11
  int v2338; // eax@11
  int v2339; // esi@11
  int v2340; // eax@11
  int v2341; // esi@11
  int v2342; // eax@11
  int v2343; // esi@11
  int v2344; // eax@11
  int v2345; // esi@11
  int v2346; // eax@11
  int v2347; // esi@11
  int v2348; // eax@11
  int v2349; // esi@11
  int v2350; // eax@11
  int v2351; // esi@11
  int v2352; // eax@11
  int v2353; // esi@11
  int v2354; // eax@11
  int v2355; // esi@11
  int v2356; // eax@11
  int v2357; // esi@11
  int v2358; // eax@11
  int v2359; // esi@11
  int v2360; // eax@11
  int v2361; // esi@11
  int v2362; // eax@11
  int v2363; // esi@11
  int v2364; // eax@11
  int v2365; // esi@11
  int v2366; // eax@11
  int v2367; // esi@11
  int v2368; // eax@11
  int v2369; // esi@11
  int v2370; // eax@11
  int v2371; // esi@11
  int v2372; // eax@11
  int v2373; // esi@11
  int v2374; // eax@11
  int v2375; // esi@11
  int v2376; // eax@11
  int v2377; // esi@11
  int v2378; // eax@11
  int v2379; // esi@11
  int v2380; // eax@11
  int v2381; // esi@11
  int v2382; // eax@11
  int v2383; // esi@11
  int v2384; // eax@11
  int v2385; // esi@11
  int v2386; // eax@11
  int v2387; // esi@11
  int v2388; // eax@11
  int v2389; // esi@11
  int v2390; // eax@11
  int v2391; // esi@11
  int v2392; // eax@11
  int v2393; // esi@11
  int v2394; // eax@11
  int v2395; // esi@11
  int v2396; // eax@11
  int v2397; // esi@11
  int v2398; // eax@11
  int v2399; // esi@11
  int v2400; // eax@11
  int v2401; // esi@11
  int v2402; // eax@11
  int v2403; // esi@11
  int v2404; // eax@11
  int v2405; // esi@11
  int v2406; // eax@11
  int v2407; // esi@11
  int v2408; // eax@11
  int v2409; // esi@11
  int v2410; // eax@11
  int v2411; // esi@11
  int v2412; // eax@11
  int v2413; // esi@11
  int v2414; // eax@11
  int v2415; // esi@11
  int v2416; // eax@11
  int v2417; // esi@11
  int v2418; // eax@11
  int v2419; // esi@11
  int v2420; // eax@11
  int v2421; // esi@11
  int v2422; // eax@11
  int v2423; // esi@11
  int v2424; // eax@11
  int v2425; // esi@11
  int v2426; // eax@11
  int v2427; // esi@11
  int v2428; // eax@11
  int v2429; // esi@11
  int v2430; // eax@11
  int v2431; // esi@11
  int v2432; // eax@11
  int v2433; // esi@11
  int v2434; // eax@11
  int v2435; // esi@11
  int v2436; // eax@11
  int v2437; // esi@11
  int v2438; // eax@11
  int v2439; // esi@11
  int v2440; // eax@11
  int v2441; // esi@11
  int v2442; // eax@11
  int v2443; // esi@11
  int v2444; // eax@11
  int v2445; // esi@11
  int v2446; // eax@11
  int v2447; // esi@11
  int v2448; // eax@11
  int v2449; // esi@11
  int v2450; // eax@11
  int v2451; // esi@11
  int v2452; // eax@11
  int v2453; // esi@11
  int v2454; // eax@11
  int v2455; // esi@11
  int v2456; // eax@11
  int v2457; // esi@11
  int v2458; // eax@11
  int v2459; // esi@11
  int v2460; // eax@11
  int v2461; // esi@11
  int v2462; // eax@11
  int v2463; // esi@11
  int v2464; // eax@11
  int v2465; // esi@11
  int v2466; // eax@11
  int v2467; // esi@11
  int v2468; // eax@11
  int v2469; // esi@11
  int v2470; // eax@11
  int v2471; // esi@11
  int v2472; // eax@11
  int v2473; // esi@11
  int v2474; // eax@11
  int v2475; // esi@11
  int v2476; // eax@11
  int v2477; // esi@11
  int v2478; // eax@11
  int v2479; // esi@11
  int v2480; // eax@11
  int v2481; // esi@11
  int v2482; // eax@11
  int v2483; // esi@11
  int v2484; // eax@11
  int v2485; // esi@11
  int v2486; // eax@11
  int v2487; // esi@11
  int v2488; // eax@11
  int v2489; // esi@11
  int v2490; // eax@11
  int v2491; // esi@11
  int v2492; // eax@11
  int v2493; // esi@11
  int v2494; // eax@11
  int v2495; // esi@11
  int v2496; // eax@11
  int v2497; // esi@11
  int v2498; // eax@11
  int v2499; // esi@11
  int v2500; // eax@11
  int v2501; // esi@11
  int v2502; // eax@11
  int v2503; // esi@11
  int v2504; // eax@11
  int v2505; // esi@11
  int v2506; // eax@11
  int v2507; // esi@11
  int v2508; // eax@11
  int v2509; // esi@11
  int v2510; // eax@11
  int v2511; // esi@11
  int v2512; // eax@11
  int v2513; // esi@11
  int v2514; // eax@11
  int v2515; // esi@11
  int v2516; // eax@11
  int v2517; // esi@11
  int v2518; // eax@11
  int v2519; // esi@11
  int v2520; // eax@11
  int v2521; // esi@11
  int v2522; // eax@11
  int v2523; // esi@11
  int v2524; // eax@11
  int v2525; // esi@11
  int v2526; // eax@11
  int v2527; // esi@11
  int v2528; // eax@11
  int v2529; // esi@11
  int v2530; // eax@11
  int v2531; // esi@11
  int v2532; // eax@11
  int v2533; // esi@11
  int v2534; // eax@11
  int v2535; // esi@11
  int v2536; // eax@11
  int v2537; // esi@11
  int v2538; // eax@11
  int v2539; // esi@11
  int v2540; // eax@11
  int v2541; // esi@11
  int v2542; // eax@11
  int v2543; // esi@11
  int v2544; // eax@11
  int v2545; // esi@11
  int v2546; // eax@11
  int v2547; // esi@11
  int v2548; // eax@11
  int v2549; // esi@11
  int v2550; // eax@11
  int v2551; // esi@11
  int v2552; // eax@11
  int v2553; // esi@11
  int v2554; // eax@11
  int v2555; // esi@11
  int v2556; // eax@11
  int v2557; // esi@11
  int v2558; // eax@11
  int v2559; // esi@11
  int v2560; // eax@11
  int v2561; // esi@11
  int v2562; // eax@11
  int v2563; // esi@11
  int v2564; // eax@11
  int v2565; // esi@11
  int v2566; // eax@11
  int v2567; // esi@11
  int v2568; // eax@11
  int v2569; // esi@11
  int v2570; // eax@11
  int v2571; // esi@11
  int v2572; // eax@11
  int v2573; // esi@11
  int v2574; // eax@11
  int v2575; // esi@11
  int v2576; // eax@11
  int v2577; // esi@11
  int v2578; // eax@11
  int v2579; // esi@11
  int v2580; // eax@11
  int v2581; // esi@11
  int v2582; // eax@11
  int v2583; // esi@11
  int v2584; // eax@11
  int v2585; // esi@11
  int v2586; // eax@11
  int v2587; // esi@11
  int v2588; // eax@11
  int v2589; // esi@11
  int v2590; // eax@11
  int v2591; // esi@11
  int v2592; // eax@11
  int v2593; // esi@11
  int v2594; // eax@11
  int v2595; // esi@11
  int v2596; // eax@11
  int v2597; // esi@11
  int v2598; // eax@11
  int v2599; // esi@11
  int v2600; // eax@11
  int v2601; // esi@11
  int v2602; // eax@11
  int v2603; // esi@11
  int v2604; // eax@11
  int v2605; // esi@11
  int v2606; // eax@11
  int v2607; // esi@11
  int v2608; // eax@11
  int v2609; // esi@11
  int v2610; // eax@11
  int v2611; // esi@11
  int v2612; // eax@11
  int v2613; // esi@11
  int v2614; // eax@11
  int v2615; // esi@11
  int v2616; // eax@11
  int v2617; // esi@11
  int v2618; // eax@11
  int v2619; // esi@11
  int v2620; // eax@11
  int v2621; // esi@11
  int v2622; // eax@11
  int v2623; // esi@11
  int v2624; // eax@11
  int v2625; // esi@11
  int v2626; // eax@11
  int v2627; // esi@11
  int v2628; // eax@11
  int v2629; // esi@11
  int v2630; // eax@11
  int v2631; // esi@11
  int v2632; // eax@11
  int v2633; // esi@11
  int v2634; // eax@11
  int v2635; // esi@11
  int v2636; // eax@11
  int v2637; // esi@11
  int v2638; // eax@11
  int v2639; // esi@11
  int v2640; // eax@11
  int v2641; // esi@11
  int v2642; // eax@11
  int v2643; // esi@11
  int v2644; // eax@11
  int v2645; // esi@11
  int v2646; // eax@11
  int v2647; // esi@11
  int v2648; // eax@11
  int v2649; // esi@11
  int v2650; // eax@11
  int v2651; // esi@11
  int v2652; // eax@11
  int v2653; // esi@11
  int v2654; // eax@11
  int v2655; // esi@11
  int v2656; // eax@11
  int v2657; // esi@11
  int v2658; // eax@11
  int v2659; // esi@11
  int v2660; // eax@11
  int v2661; // esi@11
  int v2662; // eax@11
  int v2663; // esi@11
  int v2664; // eax@11
  int v2665; // esi@11
  int v2666; // eax@11
  int v2667; // esi@11
  int v2668; // eax@11
  int v2669; // esi@11
  int v2670; // eax@11
  int v2671; // esi@11
  int v2672; // eax@11
  int v2673; // esi@11
  int v2674; // eax@11
  int v2675; // esi@11
  int v2676; // eax@11
  int v2677; // esi@11
  int v2678; // eax@11
  int v2679; // esi@11
  int v2680; // eax@11
  int v2681; // esi@11
  int v2682; // eax@11
  int v2683; // esi@11
  int v2684; // eax@11
  int v2685; // esi@11
  int v2686; // eax@11
  int v2687; // esi@11
  int v2688; // eax@11
  int v2689; // esi@11
  int v2690; // eax@11
  int v2691; // esi@11
  int v2692; // eax@11
  int v2693; // esi@11
  int v2694; // eax@11
  int v2695; // esi@11
  int v2696; // eax@11
  int v2697; // esi@11
  int v2698; // eax@11
  int v2699; // esi@11
  int v2700; // eax@11
  int v2701; // esi@11
  int v2702; // eax@11
  int v2703; // esi@11
  int v2704; // eax@11
  int v2705; // esi@11
  int v2706; // eax@11
  int v2707; // esi@11
  int v2708; // eax@11
  int v2709; // esi@11
  int v2710; // eax@11
  int v2711; // esi@11
  int v2712; // eax@11
  int v2713; // esi@11
  int v2714; // eax@11
  int v2715; // esi@11
  int v2716; // eax@11
  int v2717; // esi@11
  int v2718; // eax@11
  int v2719; // esi@11
  int v2720; // eax@11
  int v2721; // esi@11
  int v2722; // eax@11
  int v2723; // esi@11
  int v2724; // eax@11
  int v2725; // esi@11
  int v2726; // eax@11
  int v2727; // esi@11
  int v2728; // eax@11
  int v2729; // esi@11
  int v2730; // eax@11
  int v2731; // esi@11
  int v2732; // eax@11
  int v2733; // esi@11
  int v2734; // eax@11
  int v2735; // esi@11
  int v2736; // eax@11
  int v2737; // esi@11
  int v2738; // eax@11
  int v2739; // esi@11
  int v2740; // eax@11
  int v2741; // esi@11
  int v2742; // eax@11
  int v2743; // esi@11
  int v2744; // eax@11
  int v2745; // esi@11
  int v2746; // eax@11
  int v2747; // esi@11
  int v2748; // eax@11
  int v2749; // esi@11
  int v2750; // eax@11
  int v2751; // esi@11
  int v2752; // eax@11
  int v2753; // esi@11
  int v2754; // eax@11
  int v2755; // esi@11
  int v2756; // eax@11
  int v2757; // esi@11
  int v2758; // eax@11
  int v2759; // esi@11
  int v2760; // eax@11
  int v2761; // esi@11
  int v2762; // eax@11
  int v2763; // esi@11
  int v2764; // eax@11
  int v2765; // esi@11
  int v2766; // eax@11
  int v2767; // esi@11
  int v2768; // eax@11
  int v2769; // esi@11
  int v2770; // eax@11
  int v2771; // esi@11
  int v2772; // eax@11
  int v2773; // esi@11
  int v2774; // eax@11
  int v2775; // esi@11
  int v2776; // eax@11
  int v2777; // esi@11
  int v2778; // eax@11
  int v2779; // esi@11
  int v2780; // eax@11
  int v2781; // esi@11
  int v2782; // eax@11
  int v2783; // esi@11
  int v2784; // eax@11
  int v2785; // esi@11
  int v2786; // eax@11
  int v2787; // esi@11
  int v2788; // eax@11
  int v2789; // esi@11
  int v2790; // eax@11
  int v2791; // esi@11
  int v2792; // eax@11
  int v2793; // esi@11
  int v2794; // eax@11
  int v2795; // esi@11
  int v2796; // eax@11
  int v2797; // esi@11
  int v2798; // eax@11
  int v2799; // esi@11
  int v2800; // eax@11
  int v2801; // esi@11
  int v2802; // eax@11
  int v2803; // esi@11
  int v2804; // eax@11
  int v2805; // esi@11
  int v2806; // eax@11
  int v2807; // esi@11
  int v2808; // eax@11
  int v2809; // esi@11
  int v2810; // eax@11
  int v2811; // esi@11
  int v2812; // eax@11
  int v2813; // esi@11
  int v2814; // eax@11
  int v2815; // esi@11
  int v2816; // eax@11
  int v2817; // esi@11
  int v2818; // eax@11
  int v2819; // esi@11
  int v2820; // eax@11
  int v2821; // esi@11
  int v2822; // eax@11
  int v2823; // esi@11
  int v2824; // eax@11
  int v2825; // esi@11
  int v2826; // eax@11
  int v2827; // esi@11
  int v2828; // eax@11
  int v2829; // esi@11
  int v2830; // eax@11
  int v2831; // esi@11
  int v2832; // eax@11
  int v2833; // esi@11
  int v2834; // eax@11
  int v2835; // esi@11
  int v2836; // eax@11
  int v2837; // esi@11
  int v2838; // eax@11
  int v2839; // esi@11
  int v2840; // eax@11
  int v2841; // esi@11
  int v2842; // eax@11
  int v2843; // esi@11
  int v2844; // eax@11
  int v2845; // esi@11
  int v2846; // eax@11
  int v2847; // esi@11
  int v2848; // eax@11
  int v2849; // esi@11
  int v2850; // eax@11
  int v2851; // esi@11
  int v2852; // eax@11
  int v2853; // esi@11
  int v2854; // eax@11
  int v2855; // esi@11
  int v2856; // eax@11
  int v2857; // esi@11
  int v2858; // eax@11
  int v2859; // esi@11
  int v2860; // eax@11
  int v2861; // esi@11
  int v2862; // eax@11
  int v2863; // esi@11
  int v2864; // eax@11
  int v2865; // esi@11
  int v2866; // eax@11
  int v2867; // esi@11
  int v2868; // eax@11
  int v2869; // esi@11
  int v2870; // eax@11
  int v2871; // esi@11
  int v2872; // eax@11
  int v2873; // esi@11
  int v2874; // eax@11
  int v2875; // esi@11
  int v2876; // eax@11
  int v2877; // esi@11
  int v2878; // eax@11
  int v2879; // esi@11
  int v2880; // eax@11
  int v2881; // esi@11
  int v2882; // eax@11
  int v2883; // esi@11
  int v2884; // eax@11
  int v2885; // esi@11
  int v2886; // eax@11
  int v2887; // esi@11
  int v2888; // eax@11
  int v2889; // esi@11
  int v2890; // eax@11
  int v2891; // esi@11
  int v2892; // eax@11
  int v2893; // esi@11
  int v2894; // eax@11
  int v2895; // esi@11
  int v2896; // eax@11
  int v2897; // esi@11
  int v2898; // eax@11
  int v2899; // esi@11
  int v2900; // eax@11
  int v2901; // esi@11
  int v2902; // eax@11
  int v2903; // esi@11
  int v2904; // eax@11
  int v2905; // esi@11
  int v2906; // eax@11
  int v2907; // esi@11
  int v2908; // eax@11
  int v2909; // esi@11
  int v2910; // eax@11
  int v2911; // esi@11
  int v2912; // eax@11
  int v2913; // esi@11
  int v2914; // eax@11
  int v2915; // esi@11
  int v2916; // eax@11
  int v2917; // esi@11
  int v2918; // eax@11
  int v2919; // esi@11
  int v2920; // eax@11
  int v2921; // esi@11
  int v2922; // eax@11
  int v2923; // esi@11
  int v2924; // eax@11
  int v2925; // esi@11
  int v2926; // eax@11
  int v2927; // esi@11
  int v2928; // eax@11
  int v2929; // esi@11
  int v2930; // eax@11
  int v2931; // esi@11
  int v2932; // eax@11
  int v2933; // esi@11
  int v2934; // eax@11
  int v2935; // esi@11
  int v2936; // eax@11
  int v2937; // esi@11
  int v2938; // eax@11
  int v2939; // esi@11
  int v2940; // eax@11
  int v2941; // esi@11
  int v2942; // eax@11
  int v2943; // esi@11
  int v2944; // eax@11
  int v2945; // esi@11
  int v2946; // eax@11
  int v2947; // esi@11
  int v2948; // eax@11
  int v2949; // esi@11
  int v2950; // eax@11
  int v2951; // esi@11
  int v2952; // eax@11
  int v2953; // esi@11
  int v2954; // eax@11
  int v2955; // esi@11
  int v2956; // eax@11
  int v2957; // esi@11
  int v2958; // eax@11
  int v2959; // esi@11
  int v2960; // eax@11
  int v2961; // esi@11
  int v2962; // eax@11
  int v2963; // esi@11
  int v2964; // eax@11
  int v2965; // esi@11
  int v2966; // eax@11
  int v2967; // esi@11
  int v2968; // eax@11
  int v2969; // esi@11
  int v2970; // eax@11
  int v2971; // esi@11
  int v2972; // eax@11
  int v2973; // esi@11
  int v2974; // eax@11
  int v2975; // esi@11
  int v2976; // eax@11
  int v2977; // esi@11
  int v2978; // eax@11
  int v2979; // esi@11
  int v2980; // eax@11
  int v2981; // esi@11
  int v2982; // eax@11
  int v2983; // esi@11
  int v2984; // eax@11
  int v2985; // esi@11
  int v2986; // eax@11
  int v2987; // esi@11
  int v2988; // eax@11
  int v2989; // esi@11
  int v2990; // eax@11
  int v2991; // esi@11
  int v2992; // eax@11
  int v2993; // esi@11
  int v2994; // eax@11
  int v2995; // esi@11
  int v2996; // eax@11
  int v2997; // esi@11
  int v2998; // eax@11
  int v2999; // esi@11
  int v3000; // eax@11
  int v3001; // esi@11
  int v3002; // eax@11
  int v3003; // esi@11
  int v3004; // eax@11
  int v3005; // esi@11
  int v3006; // eax@11
  int v3007; // esi@11
  int v3008; // eax@11
  int v3009; // esi@11
  int v3010; // eax@11
  int v3011; // esi@11
  int v3012; // eax@11
  int v3013; // esi@11
  int v3014; // eax@11
  int v3015; // esi@11
  int v3016; // eax@11
  int v3017; // esi@11
  int v3018; // eax@11
  int v3019; // esi@11
  int v3020; // eax@11
  int v3021; // esi@11
  int v3022; // eax@11
  int v3023; // esi@11
  int v3024; // eax@11
  int v3025; // esi@11
  int v3026; // eax@11
  int v3027; // esi@11
  int v3028; // eax@11
  int v3029; // esi@11
  int v3030; // eax@11
  int v3031; // esi@11
  int v3032; // eax@11
  int v3033; // esi@11
  int v3034; // eax@11
  int v3035; // esi@11
  int v3036; // eax@11
  int v3037; // esi@11
  int v3038; // eax@11
  int v3039; // esi@11
  int v3040; // eax@11
  int v3041; // esi@11
  int v3042; // eax@11
  int v3043; // esi@11
  int v3044; // eax@11
  int v3045; // esi@11
  int v3046; // eax@11
  int v3047; // esi@11
  int v3048; // eax@11
  int v3049; // esi@11
  int v3050; // eax@11
  int v3051; // esi@11
  int v3052; // eax@11
  int v3053; // esi@11
  int v3054; // eax@11
  int v3055; // esi@11
  int v3056; // eax@11
  int v3057; // esi@11
  int v3058; // eax@11
  int v3059; // esi@11
  int v3060; // eax@11
  int v3061; // esi@11
  int v3062; // eax@11
  int v3063; // esi@11
  int v3064; // eax@11
  int v3065; // esi@11
  int v3066; // eax@11
  int v3067; // esi@11
  int v3068; // eax@11
  int v3069; // esi@11
  int v3070; // eax@11
  int v3071; // esi@11
  int v3072; // eax@11
  int v3073; // esi@11
  int v3074; // eax@11
  int v3075; // esi@11
  int v3076; // eax@11
  int v3077; // esi@11
  int v3078; // eax@11
  int v3079; // esi@11
  int v3080; // eax@11
  int v3081; // esi@11
  int v3082; // eax@11
  int v3083; // esi@11
  int v3084; // eax@11
  int v3085; // esi@11
  int v3086; // eax@11
  int v3087; // esi@11
  int v3088; // eax@11
  int v3089; // esi@11
  int v3090; // eax@11
  int v3091; // esi@11
  int v3092; // eax@11
  int v3093; // esi@11
  int v3094; // eax@11
  int v3095; // esi@11
  int v3096; // eax@11
  int v3097; // esi@11
  int v3098; // eax@11
  int v3099; // esi@11
  int v3100; // eax@11
  int v3101; // esi@11
  int v3102; // eax@11
  int v3103; // esi@11
  int v3104; // eax@11
  int v3105; // esi@11
  int v3106; // eax@11
  int v3107; // esi@11
  int v3108; // eax@11
  int v3109; // esi@11
  int v3110; // eax@11
  int v3111; // esi@11
  int v3112; // eax@11
  int v3113; // esi@11
  int v3114; // eax@11
  int v3115; // esi@11
  int v3116; // eax@11
  int v3117; // esi@11
  int v3118; // eax@11
  int v3119; // esi@11
  int v3120; // eax@11
  int v3121; // esi@11
  int v3122; // eax@11
  int v3123; // esi@11
  int v3124; // eax@11
  int v3125; // esi@11
  int v3126; // eax@11
  int v3127; // esi@11
  int v3128; // eax@11
  int v3129; // esi@11
  int v3130; // eax@11
  int v3131; // esi@11
  int v3132; // eax@11
  int v3133; // esi@11
  int v3134; // eax@11
  int v3135; // esi@11
  int v3136; // eax@11
  int v3137; // esi@11
  int v3138; // eax@11
  int v3139; // esi@11
  int v3140; // eax@11
  int v3141; // esi@11
  int v3142; // eax@11
  int v3143; // esi@11
  int v3144; // eax@11
  int v3145; // esi@11
  int v3146; // eax@11
  int v3147; // esi@11
  int v3148; // eax@11
  int v3149; // esi@11
  int v3150; // eax@11
  int v3151; // esi@11
  int v3152; // eax@11
  int v3153; // esi@11
  int v3154; // eax@11
  int v3155; // esi@11
  int v3156; // eax@11
  int v3157; // esi@11
  int v3158; // eax@11
  int v3159; // esi@11
  int v3160; // eax@11
  int v3161; // esi@11
  int v3162; // eax@11
  int v3163; // esi@11
  int v3164; // eax@11
  int v3165; // esi@11
  int v3166; // eax@11
  int v3167; // esi@11
  int v3168; // eax@11
  int v3169; // esi@11
  int v3170; // eax@11
  int v3171; // esi@11
  int v3172; // eax@11
  int v3173; // esi@11
  int v3174; // eax@11
  int v3175; // esi@11
  int v3176; // eax@11
  int v3177; // esi@11
  int v3178; // eax@11
  int v3179; // esi@11
  int v3180; // eax@11
  int v3181; // esi@11
  int v3182; // eax@11
  int v3183; // esi@11
  int v3184; // eax@11
  int v3185; // esi@11
  int v3186; // eax@11
  int v3187; // esi@11
  int v3188; // eax@11
  int v3189; // esi@11
  int v3190; // eax@11
  int v3191; // esi@11
  int v3192; // eax@11
  int v3193; // esi@11
  int v3194; // eax@11
  int v3195; // esi@11
  int v3196; // eax@11
  int v3197; // esi@11
  int v3198; // eax@11
  int v3199; // esi@11
  int v3200; // eax@11
  int v3201; // esi@11
  int v3202; // eax@11
  int v3203; // esi@11
  int v3204; // eax@11
  int v3205; // esi@11
  int v3206; // eax@11
  int v3207; // esi@11
  int v3208; // eax@11
  int v3209; // esi@11
  int v3210; // eax@11
  int v3211; // esi@11
  int v3212; // eax@11
  int v3213; // esi@11
  int v3214; // eax@11
  int v3215; // esi@11
  int v3216; // eax@11
  int v3217; // esi@11
  int v3218; // eax@11
  int v3219; // esi@11
  int v3220; // eax@11
  int v3221; // esi@11
  int v3222; // eax@11
  int v3223; // esi@11
  int v3224; // eax@11
  int v3225; // esi@11
  int v3226; // eax@11
  int v3227; // esi@11
  int v3228; // eax@11
  int v3229; // esi@11
  int v3230; // eax@11
  int v3231; // esi@11
  int v3232; // eax@11
  int v3233; // esi@11
  int v3234; // eax@11
  int v3235; // esi@11
  int v3236; // eax@11
  int v3237; // esi@11
  int v3238; // eax@11
  int v3239; // esi@11
  int v3240; // eax@11
  int v3241; // esi@11
  int v3242; // eax@11
  int v3243; // esi@11
  int v3244; // eax@11
  int v3245; // esi@11
  int v3246; // eax@11
  int v3247; // esi@11
  int v3248; // eax@11
  int v3249; // esi@11
  int v3250; // eax@11
  int v3251; // esi@11
  int v3252; // eax@11
  int v3253; // esi@11
  int v3254; // eax@11
  int v3255; // esi@11
  int v3256; // eax@11
  int v3257; // esi@11
  int v3258; // eax@11
  int v3259; // esi@11
  int v3260; // eax@11
  int v3261; // esi@11
  int v3262; // eax@11
  int v3263; // esi@11
  int v3264; // eax@11
  int v3265; // esi@11
  int v3266; // eax@11
  int v3267; // esi@11
  int v3268; // eax@11
  int v3269; // esi@11
  int v3270; // eax@11
  int v3271; // esi@11
  int v3272; // eax@11
  int v3273; // esi@11
  int v3274; // eax@11
  int v3275; // esi@11
  int v3276; // eax@11
  int v3277; // esi@11
  int v3278; // eax@11
  int v3279; // esi@11
  int v3280; // eax@11
  int v3281; // esi@11
  int v3282; // eax@11
  int v3283; // esi@11
  int v3284; // eax@11
  int v3285; // esi@11
  int v3286; // eax@11
  int v3287; // esi@11
  int v3288; // eax@11
  int v3289; // esi@11
  int v3290; // eax@11
  int v3291; // esi@11
  int v3292; // eax@11
  int v3293; // esi@11
  int v3294; // eax@11
  int v3295; // esi@11
  int v3296; // eax@11
  int v3297; // esi@11
  int v3298; // eax@11
  int v3299; // esi@11
  int v3300; // eax@11
  int v3301; // esi@11
  int v3302; // eax@11
  int v3303; // esi@11
  int v3304; // eax@11
  int v3305; // esi@11
  int v3306; // eax@11
  int v3307; // esi@11
  int v3308; // eax@11
  int v3309; // esi@11
  int v3310; // eax@11
  int v3311; // esi@11
  int v3312; // eax@11
  int v3313; // esi@11
  int v3314; // eax@11
  int v3315; // esi@11
  int v3316; // eax@11
  int v3317; // esi@11
  int v3318; // eax@11
  int v3319; // esi@11
  int v3320; // eax@11
  int v3321; // esi@11
  int v3322; // eax@11
  int v3323; // esi@11
  int v3324; // eax@11
  int v3325; // esi@11
  int v3326; // eax@11
  int v3327; // esi@11
  int v3328; // eax@11
  int v3329; // esi@11
  int v3330; // eax@11
  int v3331; // esi@11
  int v3332; // eax@11
  int v3333; // esi@11
  int v3334; // eax@11
  int v3335; // esi@11
  int v3336; // eax@11
  int v3337; // esi@11
  int v3338; // eax@11
  int v3339; // esi@11
  int v3340; // eax@11
  int v3341; // esi@11
  int v3342; // eax@11
  int v3343; // esi@11
  int v3344; // eax@11
  int v3345; // esi@11
  int v3346; // eax@11
  int v3347; // esi@11
  int v3348; // eax@11
  int v3349; // esi@11
  int v3350; // eax@11
  int v3351; // esi@11
  int v3352; // eax@11
  int v3353; // esi@11
  int v3354; // eax@11
  int v3355; // esi@11
  int v3356; // eax@11
  int v3357; // esi@11
  int v3358; // eax@11
  int v3359; // esi@11
  int v3360; // eax@11
  int v3361; // esi@11
  int v3362; // eax@11
  int v3363; // esi@11
  int v3364; // eax@11
  int v3365; // esi@11
  int v3366; // eax@11
  int v3367; // esi@11
  int v3368; // eax@11
  int v3369; // esi@11
  int v3370; // eax@11
  int v3371; // esi@11
  int v3372; // eax@11
  int v3373; // esi@11
  int v3374; // eax@11
  int v3375; // esi@11
  int v3376; // eax@11
  int v3377; // esi@11
  int v3378; // eax@11
  int v3379; // esi@11
  int v3380; // eax@11
  int v3381; // esi@11
  int v3382; // eax@11
  int v3383; // esi@11
  int v3384; // eax@11
  int v3385; // esi@11
  int v3386; // eax@11
  int v3387; // esi@11
  int v3388; // eax@11
  int v3389; // esi@11
  int v3390; // eax@11
  int v3391; // esi@11
  int v3392; // eax@11
  int v3393; // esi@11
  int v3394; // eax@11
  int v3395; // esi@11
  int v3396; // eax@11
  int v3397; // esi@11
  int v3398; // eax@11
  int v3399; // esi@11
  int v3400; // eax@11
  int v3401; // esi@11
  int v3402; // eax@11
  int v3403; // esi@11
  int v3404; // eax@11
  int v3405; // esi@11
  int v3406; // eax@11
  int v3407; // esi@11
  int v3408; // eax@11
  int v3409; // esi@11
  int v3410; // eax@11
  int v3411; // esi@11
  int v3412; // eax@11
  int v3413; // esi@11
  int v3414; // eax@11
  int v3415; // esi@11
  int v3416; // eax@11
  int v3417; // esi@11
  int v3418; // eax@11
  int v3419; // esi@11
  int v3420; // eax@11
  int v3421; // esi@11
  int v3422; // eax@11
  int v3423; // esi@11
  int v3424; // eax@11
  int v3425; // esi@11
  int v3426; // eax@11
  int v3427; // esi@11
  int v3428; // eax@11
  int v3429; // esi@11
  int v3430; // eax@11
  int v3431; // esi@11
  int v3432; // eax@11
  int v3433; // esi@11
  int v3434; // eax@11
  int v3435; // esi@11
  int v3436; // eax@11
  int v3437; // esi@11
  int v3438; // eax@11
  int v3439; // esi@11
  int v3440; // eax@11
  int v3441; // esi@11
  int v3442; // eax@11
  int v3443; // esi@11
  int v3444; // eax@11
  int v3445; // esi@11
  int v3446; // eax@11
  int v3447; // esi@11
  int v3448; // eax@11
  int v3449; // esi@11
  int v3450; // eax@11
  int v3451; // esi@11
  int v3452; // eax@11
  int v3453; // esi@11
  int v3454; // eax@11
  int v3455; // esi@11
  int v3456; // eax@11
  int v3457; // esi@11
  int v3458; // eax@11
  int v3459; // esi@11
  int v3460; // eax@11
  int v3461; // esi@11
  int v3462; // eax@11
  int v3463; // esi@11
  int v3464; // eax@11
  int v3465; // esi@11
  int v3466; // eax@11
  int v3467; // esi@11
  int v3468; // eax@11
  int v3469; // esi@11
  int v3470; // eax@11
  int v3471; // esi@11
  int v3472; // eax@11
  int v3473; // esi@11
  int v3474; // eax@11
  int v3475; // esi@11
  int v3476; // eax@11
  int v3477; // esi@11
  int v3478; // eax@11
  int v3479; // esi@11
  int v3480; // eax@11
  int v3481; // esi@11
  int v3482; // eax@11
  int v3483; // esi@11
  int v3484; // eax@11
  int v3485; // esi@11
  int v3486; // eax@11
  int v3487; // esi@11
  int v3488; // eax@11
  int v3489; // esi@11
  int v3490; // eax@11
  int v3491; // esi@11
  int v3492; // eax@11
  int v3493; // esi@11
  int v3494; // eax@11
  int v3495; // esi@11
  int v3496; // eax@11
  int v3497; // esi@11
  int v3498; // eax@11
  int v3499; // esi@11
  int v3500; // eax@11
  int v3501; // esi@11
  int v3502; // eax@11
  int v3503; // esi@11
  int v3504; // eax@11
  int v3505; // esi@11
  int v3506; // eax@11
  int v3507; // esi@11
  int v3508; // eax@11
  int v3509; // esi@11
  int v3510; // eax@11
  int v3511; // esi@11
  int v3512; // eax@11
  int v3513; // esi@11
  int v3514; // eax@11
  int v3515; // esi@11
  int v3516; // eax@11
  int v3517; // esi@11
  int v3518; // eax@11
  int v3519; // esi@11
  int v3520; // eax@11
  int v3521; // esi@11
  int v3522; // eax@11
  int v3523; // esi@11
  int v3524; // eax@11
  int v3525; // esi@11
  int v3526; // eax@11
  int v3527; // esi@11
  int v3528; // eax@11
  int v3529; // esi@11
  int v3530; // eax@11
  int v3531; // esi@11
  int v3532; // eax@11
  int v3533; // esi@11
  int v3534; // eax@11
  int v3535; // esi@11
  int v3536; // eax@11
  int v3537; // esi@11
  int v3538; // eax@11
  int v3539; // esi@11
  int v3540; // eax@11
  int v3541; // esi@11
  int v3542; // eax@11
  int v3543; // esi@11
  int v3544; // eax@11
  int v3545; // esi@11
  int v3546; // eax@11
  int v3547; // esi@11
  int v3548; // eax@11
  int v3549; // esi@11
  int v3550; // eax@11
  int v3551; // esi@11
  int v3552; // eax@11
  int v3553; // esi@11
  int v3554; // eax@11
  int v3555; // esi@11
  int v3556; // eax@11
  int v3557; // esi@11
  int v3558; // eax@11
  int v3559; // esi@11
  int v3560; // eax@11
  int v3561; // esi@11
  int v3562; // eax@11
  int v3563; // esi@11
  int v3564; // eax@11
  int v3565; // esi@11
  int v3566; // eax@11
  int v3567; // esi@11
  int v3568; // eax@11
  int v3569; // esi@11
  int v3570; // eax@11
  int v3571; // esi@11
  int v3572; // eax@11
  int v3573; // esi@11
  int v3574; // eax@11
  int v3575; // esi@11
  int v3576; // eax@11
  int v3577; // esi@11
  int v3578; // eax@11
  int v3579; // esi@11
  int v3580; // eax@11
  int v3581; // esi@11
  int v3582; // eax@11
  int v3583; // esi@11
  int v3584; // eax@11
  int v3585; // esi@11
  int v3586; // eax@11
  int v3587; // esi@11
  int v3588; // eax@11
  int v3589; // esi@11
  int v3590; // eax@11
  int v3591; // esi@11
  int v3592; // eax@11
  int v3593; // esi@11
  int v3594; // eax@11
  int v3595; // esi@11
  int v3596; // eax@11
  int v3597; // esi@11
  int v3598; // eax@11
  int v3599; // esi@11
  int v3600; // eax@11
  int v3601; // esi@11
  int v3602; // eax@11
  int v3603; // esi@11
  int v3604; // eax@11
  int v3605; // esi@11
  int v3606; // eax@11
  int v3607; // esi@11
  int v3608; // eax@11
  int v3609; // esi@11
  int v3610; // eax@11
  int v3611; // esi@11
  int v3612; // eax@11
  int v3613; // esi@11
  int v3614; // eax@11
  int v3615; // esi@11
  int v3616; // eax@11
  int v3617; // esi@11
  int v3618; // eax@11
  int v3619; // esi@11
  int v3620; // eax@11
  int v3621; // esi@11
  int v3622; // eax@11
  int v3623; // esi@11
  int v3624; // eax@11
  int v3625; // esi@11
  int v3626; // eax@11
  int v3627; // esi@11
  int v3628; // eax@11
  int v3629; // esi@11
  int v3630; // eax@11
  int v3631; // esi@11
  int v3632; // eax@11
  int v3633; // esi@11
  int v3634; // eax@11
  int v3635; // esi@11
  int v3636; // eax@11
  int v3637; // esi@11
  int v3638; // eax@11
  int v3639; // esi@11
  int v3640; // eax@11
  int v3641; // esi@11
  int v3642; // eax@11
  int v3643; // esi@11
  int v3644; // eax@11
  int v3645; // esi@11
  int v3646; // eax@11
  int v3647; // esi@11
  int v3648; // eax@11
  int v3649; // esi@11
  int v3650; // eax@11
  int v3651; // esi@11
  int v3652; // eax@11
  int v3653; // esi@11
  int v3654; // eax@11
  int v3655; // esi@11
  int v3656; // eax@11
  int v3657; // esi@11
  int v3658; // eax@11
  int v3659; // esi@11
  int v3660; // eax@11
  int v3661; // esi@11
  int v3662; // eax@11
  int v3663; // esi@11
  int v3664; // eax@11
  int v3665; // esi@11
  int v3666; // eax@11
  int v3667; // esi@11
  int v3668; // eax@11
  int v3669; // esi@11
  int v3670; // eax@11
  int v3671; // esi@11
  int v3672; // eax@11
  int v3673; // esi@11
  int v3674; // eax@11
  int v3675; // esi@11
  int v3676; // eax@11
  int v3677; // esi@11
  int v3678; // eax@11
  int v3679; // esi@11
  int v3680; // eax@11
  int v3681; // esi@11
  int v3682; // eax@11
  int v3683; // esi@11
  int v3684; // eax@11
  int v3685; // esi@11
  int v3686; // eax@11
  int v3687; // esi@11
  int v3688; // eax@11
  int v3689; // esi@11
  int v3690; // eax@11
  int v3691; // esi@11
  int v3692; // eax@11
  int v3693; // esi@11
  int v3694; // eax@11
  int v3695; // esi@11
  int v3696; // eax@11
  int v3697; // esi@11
  int v3698; // eax@11
  int v3699; // esi@11
  int v3700; // eax@11
  int v3701; // esi@11
  int v3702; // eax@11
  int v3703; // esi@11
  int v3704; // eax@11
  int v3705; // esi@11
  int v3706; // eax@11
  int v3707; // esi@11
  int v3708; // eax@11
  int v3709; // esi@11
  int v3710; // eax@11
  int v3711; // esi@11
  int v3712; // eax@11
  int v3713; // esi@11
  int v3714; // eax@11
  int v3715; // esi@11
  int v3716; // eax@11
  int v3717; // esi@11
  int v3718; // eax@11
  int v3719; // esi@11
  int v3720; // eax@11
  int v3721; // esi@11
  int v3722; // eax@11
  int v3723; // esi@11
  int v3724; // eax@11
  int v3725; // esi@11
  int v3726; // eax@11
  int v3727; // esi@11
  int v3728; // eax@11
  int v3729; // esi@11
  int v3730; // eax@11
  int v3731; // esi@11
  int v3732; // eax@11
  int v3733; // esi@11
  int v3734; // eax@11
  int v3735; // esi@11
  int v3736; // eax@11
  int v3737; // esi@11
  int v3738; // eax@11
  int v3739; // esi@11
  int v3740; // eax@11
  int v3741; // esi@11
  int v3742; // eax@11
  int v3743; // esi@11
  int v3744; // eax@11
  int v3745; // esi@11
  int v3746; // eax@11
  int v3747; // esi@11
  int v3748; // eax@11
  int v3749; // esi@11
  int v3750; // eax@11
  int v3751; // esi@11
  int v3752; // eax@11
  int v3753; // esi@11
  int v3754; // eax@11
  int v3755; // esi@11
  int v3756; // eax@11
  int v3757; // esi@11
  int v3758; // eax@11
  int v3759; // esi@11
  int v3760; // eax@11
  int v3761; // esi@11
  int v3762; // eax@11
  int v3763; // esi@11
  int v3764; // eax@11
  int v3765; // esi@11
  int v3766; // eax@11
  int v3767; // esi@11
  int v3768; // eax@11
  int v3769; // esi@11
  int v3770; // eax@11
  int v3771; // esi@11
  int v3772; // eax@11
  int v3773; // esi@11
  int v3774; // eax@11
  int v3775; // esi@11
  int v3776; // eax@11
  int v3777; // esi@11
  int v3778; // eax@11
  int v3779; // esi@11
  int v3780; // eax@11
  int v3781; // esi@11
  int v3782; // eax@11
  int v3783; // esi@11
  int v3784; // eax@11
  int v3785; // esi@11
  int v3786; // eax@11
  int v3787; // esi@11
  int v3788; // eax@11
  int v3789; // esi@11
  int v3790; // eax@11
  int v3791; // esi@11
  int v3792; // eax@11
  int v3793; // esi@11
  int v3794; // eax@11
  int v3795; // esi@11
  int v3796; // eax@11
  int v3797; // esi@11
  int v3798; // eax@11
  int v3799; // esi@11
  int v3800; // eax@11
  int v3801; // esi@11
  int v3802; // eax@11
  int v3803; // esi@11
  int v3804; // eax@11
  int v3805; // esi@11
  int v3806; // eax@11
  int v3807; // esi@11
  int v3808; // eax@11
  int v3809; // esi@11
  int v3810; // eax@11
  int v3811; // esi@11
  int v3812; // eax@11
  int v3813; // esi@11
  int v3814; // eax@11
  int v3815; // esi@11
  int v3816; // eax@11
  int v3817; // esi@11
  int v3818; // eax@11
  int v3819; // esi@11
  int v3820; // eax@11
  int v3821; // esi@11
  int v3822; // eax@11
  int v3823; // esi@11
  int v3824; // eax@11
  int v3825; // esi@11
  int v3826; // eax@11
  int v3827; // esi@11
  int v3828; // eax@11
  int v3829; // esi@11
  int v3830; // eax@11
  int v3831; // esi@11
  int v3832; // eax@11
  int v3833; // esi@11
  int v3834; // eax@11
  int v3835; // esi@11
  int v3836; // eax@11
  int v3837; // esi@11
  int v3838; // eax@11
  int v3839; // esi@11
  int v3840; // eax@11
  int v3841; // esi@11
  int v3842; // eax@11
  int v3843; // esi@11
  int v3844; // eax@11
  int v3845; // esi@11
  int v3846; // eax@11
  int v3847; // esi@11
  int v3848; // eax@11
  int v3849; // esi@11
  int v3850; // eax@11
  int v3851; // esi@11
  int v3852; // eax@11
  int v3853; // esi@11
  int v3854; // eax@11
  int v3855; // esi@11
  int v3856; // eax@11
  int v3857; // esi@11
  int v3858; // eax@11
  int v3859; // esi@11
  int v3860; // eax@11
  int v3861; // esi@11
  int v3862; // eax@11
  int v3863; // esi@11
  int v3864; // eax@11
  int v3865; // esi@11
  int v3866; // eax@11
  int v3867; // esi@11
  int v3868; // eax@11
  int v3869; // esi@11
  int v3870; // eax@11
  int v3871; // esi@11
  int v3872; // eax@11
  int v3873; // esi@11
  int v3874; // eax@11
  int v3875; // esi@11
  int v3876; // eax@11
  int v3877; // esi@11
  int v3878; // eax@11
  int v3879; // esi@11
  int v3880; // eax@11
  int v3881; // esi@11
  int v3882; // eax@11
  int v3883; // esi@11
  int v3884; // eax@11
  int v3885; // esi@11
  int v3886; // eax@11
  int v3887; // esi@11
  int v3888; // eax@11
  int v3889; // esi@11
  int v3890; // eax@11
  int v3891; // esi@11
  int v3892; // eax@11
  int v3893; // esi@11
  int v3894; // eax@11
  int v3895; // esi@11
  int v3896; // eax@11
  int v3897; // esi@11
  int v3898; // eax@11
  int v3899; // esi@11
  int v3900; // eax@11
  int v3901; // esi@11
  int v3902; // eax@11
  int v3903; // esi@11
  int v3904; // eax@11
  int v3905; // esi@11
  int v3906; // eax@11
  int v3907; // esi@11
  int v3908; // eax@11
  int v3909; // esi@11
  int v3910; // eax@11
  int v3911; // esi@11
  int v3912; // eax@11
  int v3913; // esi@11
  int v3914; // eax@11
  int v3915; // esi@11
  int v3916; // eax@11
  int v3917; // esi@11
  int v3918; // eax@11
  int v3919; // esi@11
  int v3920; // eax@11
  int v3921; // esi@11
  int v3922; // eax@11
  int v3923; // esi@11
  int v3924; // eax@11
  int v3925; // esi@11
  int v3926; // eax@11
  int v3927; // esi@11
  int v3928; // eax@11
  int v3929; // esi@11
  int v3930; // eax@11
  int v3931; // esi@11
  int v3932; // eax@11
  int v3933; // esi@11
  int v3934; // eax@11
  int v3935; // esi@11
  int v3936; // eax@11
  int v3937; // esi@11
  int v3938; // eax@11
  int v3939; // esi@11
  int v3940; // eax@11
  int v3941; // esi@11
  int v3942; // eax@11
  int v3943; // esi@11
  int v3944; // eax@11
  int v3945; // esi@11
  int v3946; // eax@11
  int v3947; // esi@11
  int v3948; // eax@11
  int v3949; // esi@11
  int v3950; // eax@11
  int v3951; // esi@11
  int v3952; // eax@11
  int v3953; // esi@11
  int v3954; // eax@11
  int v3955; // esi@11
  int v3956; // eax@11
  int v3957; // esi@11
  int v3958; // eax@11
  int v3959; // esi@11
  int v3960; // eax@11
  int v3961; // esi@11
  int v3962; // eax@11
  int v3963; // esi@11
  int v3964; // eax@11
  int v3965; // esi@11
  int v3966; // eax@11
  int v3967; // esi@11
  int v3968; // eax@11
  int v3969; // esi@11
  int v3970; // eax@11
  int v3971; // esi@11
  int v3972; // eax@11
  int v3973; // esi@11
  int v3974; // eax@11
  int v3975; // esi@11
  int v3976; // eax@11
  int v3977; // esi@11
  int v3978; // eax@11
  int v3979; // esi@11
  int v3980; // eax@11
  int v3981; // esi@11
  int v3982; // eax@11
  int v3983; // esi@11
  int v3984; // eax@11
  int v3985; // esi@11
  int v3986; // eax@11
  int v3987; // esi@11
  int v3988; // eax@11
  int v3989; // esi@11
  int v3990; // eax@11
  int v3991; // esi@11
  int v3992; // eax@11
  int v3993; // esi@11
  int v3994; // eax@11
  int v3995; // esi@11
  int v3996; // eax@11
  int v3997; // esi@11
  int v3998; // eax@11
  int v3999; // esi@11
  int v4000; // eax@11
  int v4001; // esi@11
  int v4002; // eax@11
  int v4003; // esi@11
  int v4004; // eax@11
  int v4005; // esi@11
  int v4006; // eax@11
  int v4007; // esi@11
  int v4008; // eax@11
  int v4009; // esi@11
  int v4010; // eax@11
  int v4011; // esi@11
  int v4012; // eax@11
  int v4013; // esi@11
  int v4014; // eax@11
  int v4015; // esi@11
  int v4016; // eax@11
  int v4017; // esi@11
  int v4018; // eax@11
  int v4019; // esi@11
  int v4020; // eax@11
  int v4021; // esi@11
  int v4022; // eax@11
  int v4023; // esi@11
  int v4024; // eax@11
  int v4025; // esi@11
  int v4026; // eax@11
  int v4027; // esi@11
  int v4028; // eax@11
  int v4029; // esi@11
  int v4030; // eax@11
  int v4031; // esi@11
  int v4032; // eax@11
  int v4033; // esi@11
  int v4034; // eax@11
  int v4035; // esi@11
  int v4036; // eax@11
  int v4037; // esi@11
  int v4038; // eax@11
  int v4039; // esi@11
  int v4040; // eax@11
  int v4041; // esi@11
  int v4042; // eax@11
  int v4043; // esi@11
  int v4044; // eax@11
  int v4045; // esi@11
  int v4046; // eax@11
  int v4047; // esi@11
  int v4048; // eax@11
  int v4049; // esi@11
  int v4050; // eax@11
  int v4051; // esi@11
  int v4052; // eax@11
  int v4053; // esi@11
  int v4054; // eax@11
  int v4055; // esi@11
  int v4056; // eax@11
  int v4057; // esi@11
  int v4058; // eax@11
  int v4059; // esi@11
  int v4060; // eax@11
  int v4061; // esi@11
  int v4062; // eax@11
  int v4063; // esi@11
  int v4064; // eax@11
  int v4065; // esi@11
  int v4066; // eax@11
  int v4067; // esi@11
  int v4068; // eax@11
  int v4069; // esi@11
  int v4070; // eax@11
  int v4071; // esi@11
  int v4072; // eax@11
  int v4073; // esi@11
  int v4074; // eax@11
  int v4075; // esi@11
  int v4076; // eax@11
  int v4077; // esi@11
  int v4078; // eax@11
  int v4079; // esi@11
  int v4080; // eax@11
  int v4081; // esi@11
  int v4082; // eax@11
  int v4083; // esi@11
  int v4084; // eax@11
  int v4085; // esi@11
  int v4086; // eax@11
  int v4087; // esi@11
  int v4088; // eax@11
  int v4089; // esi@11
  int v4090; // eax@11
  int v4091; // esi@11
  int v4092; // eax@11
  int v4093; // esi@11
  int v4094; // eax@11
  int v4095; // esi@11
  int v4096; // eax@11
  int v4097; // esi@11
  int v4098; // eax@11
  int v4099; // esi@11
  int v4100; // eax@11
  int v4101; // esi@11
  int v4102; // eax@11
  int v4103; // esi@11
  int v4104; // eax@11
  int v4105; // esi@11
  int v4106; // eax@11
  int v4107; // esi@11
  int v4108; // eax@11
  int v4109; // esi@11
  int v4110; // eax@11
  int v4111; // esi@11
  int v4112; // eax@11
  int v4113; // esi@11
  int v4114; // eax@11
  int v4115; // esi@11
  int v4116; // eax@11
  int v4117; // esi@11
  int v4118; // eax@11
  int v4119; // esi@11
  int v4120; // eax@11
  int v4121; // esi@11
  int v4122; // eax@11
  int v4123; // esi@11
  int v4124; // eax@11
  int v4125; // esi@11
  int v4126; // eax@11
  int v4127; // esi@11
  int v4128; // eax@11
  int v4129; // esi@11
  int v4130; // eax@11
  int v4131; // esi@11
  int v4132; // eax@11
  int v4133; // esi@11
  int v4134; // eax@11
  int v4135; // esi@11
  int v4136; // eax@11
  int v4137; // esi@11
  int v4138; // eax@11
  int v4139; // esi@11
  int v4140; // eax@11
  int v4141; // esi@11
  int v4142; // eax@11
  int v4143; // esi@11
  int v4144; // eax@11
  int v4145; // esi@11
  int v4146; // eax@11
  int v4147; // esi@11
  int v4148; // eax@11
  int v4149; // esi@11
  int v4150; // eax@11
  int v4151; // esi@11
  int v4152; // eax@11
  int v4153; // esi@11
  int v4154; // eax@11
  int v4155; // esi@11
  int v4156; // eax@11
  int v4157; // esi@11
  int v4158; // eax@11
  int v4159; // esi@11
  int v4160; // eax@11
  int v4161; // esi@11
  int v4162; // eax@11
  int v4163; // esi@11
  int v4164; // eax@11
  int v4165; // esi@11
  int v4166; // eax@11
  int v4167; // esi@11
  int v4168; // eax@11
  int v4169; // esi@11
  int v4170; // eax@11
  int v4171; // esi@11
  int v4172; // eax@11
  int v4173; // esi@11
  int v4174; // eax@11
  int v4175; // esi@11
  int v4176; // eax@11
  int v4177; // esi@11
  int v4178; // eax@11
  int v4179; // esi@11
  int v4180; // eax@11
  int v4181; // esi@11
  int v4182; // eax@11
  int v4183; // esi@11
  int v4184; // eax@11
  int v4185; // esi@11
  int v4186; // eax@11
  int v4187; // esi@11
  int v4188; // eax@11
  int v4189; // esi@11
  int v4190; // eax@11
  int v4191; // esi@11
  int v4192; // eax@11
  int v4193; // esi@11
  int v4194; // eax@11
  int v4195; // esi@11
  int v4196; // eax@11
  int v4197; // esi@11
  int v4198; // eax@11
  int v4199; // esi@11
  int v4200; // eax@11
  int v4201; // esi@11
  int v4202; // eax@11
  int v4203; // esi@11
  int v4204; // eax@11
  int v4205; // esi@11
  int v4206; // eax@11
  int v4207; // esi@11
  int v4208; // eax@11
  int v4209; // esi@11
  int v4210; // eax@11
  int v4211; // esi@11
  int v4212; // eax@11
  int v4213; // esi@11
  int v4214; // eax@11
  int v4215; // esi@11
  int v4216; // eax@11
  int v4217; // esi@11
  int v4218; // eax@11
  int v4219; // esi@11
  int v4220; // eax@11
  int v4221; // esi@11
  int v4222; // eax@11
  int v4223; // esi@11
  int v4224; // eax@11
  int v4225; // esi@11
  int v4226; // eax@11
  int v4227; // esi@11
  int v4228; // eax@11
  int v4229; // esi@11
  int v4230; // eax@11
  int v4231; // esi@11
  int v4232; // eax@11
  int v4233; // esi@11
  int v4234; // eax@11
  int v4235; // esi@11
  int v4236; // eax@11
  int v4237; // esi@11
  int v4238; // eax@11
  int v4239; // esi@11
  int v4240; // eax@11
  int v4241; // esi@11
  int v4242; // eax@11
  int v4243; // esi@11
  int v4244; // eax@11
  int v4245; // esi@11
  int v4246; // eax@11
  int v4247; // esi@11
  int v4248; // eax@11
  int v4249; // esi@11
  int v4250; // eax@11
  int v4251; // esi@11
  int v4252; // eax@11
  int v4253; // esi@11
  int v4254; // eax@11
  int v4255; // esi@11
  int v4256; // eax@11
  int v4257; // esi@11
  int v4258; // eax@11
  int v4259; // esi@11
  int v4260; // eax@11
  int v4261; // esi@11
  int v4262; // eax@11
  int v4263; // esi@11
  int v4264; // eax@11
  int v4265; // esi@11
  int v4266; // eax@11
  int v4267; // esi@11
  int v4268; // eax@11
  int v4269; // esi@11
  int v4270; // eax@11
  int v4271; // esi@11
  int v4272; // eax@11
  int v4273; // esi@11
  int v4274; // eax@11
  int v4275; // esi@11
  int v4276; // eax@11
  int v4277; // esi@11
  int v4278; // eax@11
  int v4279; // esi@11
  int v4280; // eax@11
  int v4281; // esi@11
  int v4282; // eax@11
  int v4283; // esi@11
  int v4284; // eax@11
  int v4285; // esi@11
  int v4286; // eax@11
  int v4287; // esi@11
  int v4288; // eax@11
  int v4289; // esi@11
  int v4290; // eax@11
  int v4291; // esi@11
  int v4292; // eax@11
  int v4293; // esi@11
  int v4294; // eax@11
  int v4295; // esi@11
  int v4296; // eax@11
  int v4297; // esi@11
  int v4298; // eax@11
  int v4299; // esi@11
  int v4300; // eax@11
  int v4301; // esi@11
  int v4302; // eax@11
  int v4303; // esi@11
  int v4304; // eax@11
  int v4305; // esi@11
  int v4306; // eax@11
  int v4307; // esi@11
  int v4308; // eax@11
  int v4309; // esi@11
  int v4310; // eax@11
  int v4311; // esi@11
  int v4312; // eax@11
  int v4313; // esi@11
  int v4314; // eax@11
  int v4315; // esi@11
  int v4316; // eax@11
  int v4317; // esi@11
  int v4318; // eax@11
  int v4319; // esi@11
  int v4320; // eax@11
  int v4321; // esi@11
  int v4322; // eax@11
  int v4323; // esi@11
  int v4324; // eax@11
  int v4325; // esi@11
  int v4326; // eax@11
  int v4327; // esi@11
  int v4328; // eax@11
  int v4329; // esi@11
  int v4330; // eax@11
  int v4331; // esi@11
  int v4332; // eax@11
  int v4333; // esi@11
  int v4334; // eax@11
  int v4335; // esi@11
  int v4336; // eax@11
  int v4337; // esi@11
  int v4338; // eax@11
  int v4339; // esi@11
  int v4340; // eax@11
  int v4341; // esi@11
  int v4342; // eax@11
  int v4343; // esi@11
  int v4344; // eax@11
  int v4345; // esi@11
  int v4346; // eax@11
  int v4347; // esi@11
  int v4348; // eax@11
  int v4349; // esi@11
  int v4350; // eax@11
  int v4351; // esi@11
  int v4352; // eax@11
  int v4353; // esi@11
  int v4354; // eax@11
  int v4355; // esi@11
  int v4356; // eax@11
  int v4357; // esi@11
  int v4358; // eax@11
  int v4359; // esi@11
  int v4360; // eax@11
  int v4361; // esi@11
  int v4362; // eax@11
  int v4363; // esi@11
  int v4364; // eax@11
  int v4365; // esi@11
  int v4366; // eax@11
  int v4367; // esi@11
  int v4368; // eax@11
  int v4369; // esi@11
  int v4370; // eax@11
  int v4371; // esi@11
  int v4372; // eax@11
  int v4373; // esi@11
  int v4374; // eax@11
  int v4375; // esi@11
  int v4376; // eax@11
  int v4377; // esi@11
  int v4378; // eax@11
  int v4379; // esi@11
  int v4380; // eax@11
  int v4381; // esi@11
  int v4382; // eax@11
  int v4383; // esi@11
  int v4384; // eax@11
  int v4385; // esi@11
  int v4386; // eax@11
  int v4387; // esi@11
  int v4388; // eax@11
  int v4389; // esi@11
  int v4390; // eax@11
  int v4391; // esi@11
  int v4392; // eax@11
  int v4393; // esi@11
  int v4394; // eax@11
  int v4395; // esi@11
  int v4396; // eax@11
  int v4397; // esi@11
  int v4398; // eax@11
  int v4399; // esi@11
  int v4400; // eax@11
  int v4401; // esi@11
  int v4402; // eax@11
  int v4403; // esi@11
  int v4404; // eax@11
  int v4405; // esi@11
  int v4406; // eax@11
  int v4407; // esi@11
  int v4408; // eax@11
  int v4409; // esi@11
  int v4410; // eax@11
  int v4411; // esi@11
  int v4412; // eax@11
  int v4413; // esi@11
  int v4414; // eax@11
  int v4415; // esi@11
  int v4416; // eax@11
  int v4417; // esi@11
  int v4418; // eax@11
  int v4419; // esi@11
  int v4420; // eax@11
  int v4421; // esi@11
  int v4422; // eax@11
  int v4423; // esi@11
  int v4424; // eax@11
  int v4425; // esi@11
  int v4426; // eax@11
  int v4427; // esi@11
  int v4428; // eax@11
  int v4429; // esi@11
  int v4430; // eax@11
  int v4431; // esi@11
  int v4432; // eax@11
  int v4433; // esi@11
  int v4434; // eax@11
  int v4435; // esi@11
  int v4436; // eax@11
  int v4437; // esi@11
  int v4438; // eax@11
  int v4439; // esi@11
  int v4440; // eax@11
  int v4441; // esi@11
  int v4442; // eax@11
  int v4443; // esi@11
  int v4444; // eax@11
  int v4445; // esi@11
  int v4446; // eax@11
  int v4447; // esi@11
  int v4448; // eax@11
  int v4449; // esi@11
  int v4450; // eax@11
  int v4451; // esi@11
  int v4452; // eax@11
  int v4453; // esi@11
  int v4454; // eax@11
  int v4455; // esi@11
  int v4456; // eax@11
  int v4457; // esi@11
  int v4458; // eax@11
  int v4459; // esi@11
  int v4460; // eax@11
  int v4461; // esi@11
  int v4462; // eax@11
  int v4463; // esi@11
  int v4464; // eax@11
  int v4465; // esi@11
  int v4466; // eax@11
  int v4467; // esi@11
  int v4468; // eax@11
  int v4469; // esi@11
  int v4470; // eax@11
  int v4471; // esi@11
  int v4472; // eax@11
  int v4473; // esi@11
  int v4474; // eax@11
  int v4475; // esi@11
  int v4476; // eax@11
  int v4477; // esi@11
  int v4478; // eax@11
  int v4479; // esi@11
  int v4480; // eax@11
  int v4481; // esi@11
  int v4482; // eax@11
  int v4483; // esi@11
  int v4484; // eax@11
  int v4485; // esi@11
  int v4486; // eax@11
  int v4487; // esi@11
  int v4488; // eax@11
  int v4489; // esi@11
  int v4490; // eax@11
  int v4491; // esi@11
  int v4492; // eax@11
  int v4493; // esi@11
  int v4494; // eax@11
  int v4495; // esi@11
  int v4496; // eax@11
  int v4497; // esi@11
  int v4498; // eax@11
  int v4499; // esi@11
  int v4500; // eax@11
  int v4501; // esi@11
  int v4502; // eax@11
  int v4503; // esi@11
  int v4504; // eax@11
  int v4505; // esi@11
  int v4506; // eax@11
  int v4507; // esi@11
  int v4508; // eax@11
  int v4509; // esi@11
  int v4510; // eax@11
  int v4511; // esi@11
  int v4512; // eax@11
  int v4513; // esi@11
  int v4514; // eax@11
  int v4515; // esi@11
  int v4516; // eax@11
  int v4517; // esi@11
  int v4518; // eax@11
  int v4519; // esi@11
  int v4520; // eax@11
  int v4521; // esi@11
  int v4522; // eax@11
  int v4523; // esi@11
  int v4524; // eax@11
  int v4525; // esi@11
  int v4526; // eax@11
  int v4527; // esi@11
  int v4528; // eax@11
  int v4529; // esi@11
  int v4530; // eax@11
  int v4531; // esi@11
  int v4532; // eax@11
  int v4533; // esi@11
  int v4534; // eax@11
  int v4535; // esi@11
  int v4536; // eax@11
  int v4537; // esi@11
  int v4538; // eax@11
  int v4539; // esi@11
  int v4540; // eax@11
  int v4541; // esi@11
  int v4542; // eax@11
  int v4543; // esi@11
  int v4544; // eax@11
  int v4545; // esi@11
  int v4546; // eax@11
  int v4547; // esi@11
  int v4548; // eax@11
  int v4549; // esi@11
  int v4550; // eax@11
  int v4551; // esi@11
  int v4552; // eax@11
  int v4553; // esi@11
  int v4554; // eax@11
  int v4555; // esi@11
  int v4556; // eax@11
  int v4557; // esi@11
  int v4558; // eax@11
  int v4559; // esi@11
  int v4560; // eax@11
  int v4561; // esi@11
  int v4562; // eax@11
  int v4563; // esi@11
  int v4564; // eax@11
  int v4565; // esi@11
  int v4566; // eax@11
  int v4567; // esi@11
  int v4568; // eax@11
  int v4569; // esi@11
  int v4570; // eax@11
  int v4571; // esi@11
  int v4572; // eax@11
  int v4573; // esi@11
  int v4574; // eax@11
  int v4575; // esi@11
  int v4576; // eax@11
  int v4577; // esi@11
  int v4578; // eax@11
  int v4579; // esi@11
  int v4580; // eax@11
  int v4581; // esi@11
  int v4582; // eax@11
  int v4583; // esi@11
  int v4584; // eax@11
  int v4585; // esi@11
  int v4586; // eax@11
  int v4587; // esi@11
  int v4588; // eax@11
  int v4589; // esi@11
  int v4590; // eax@11
  int v4591; // esi@11
  int v4592; // eax@11
  int v4593; // esi@11
  int v4594; // eax@11
  int v4595; // esi@11
  int v4596; // eax@11
  int v4597; // esi@11
  int v4598; // eax@11
  int v4599; // esi@11
  int v4600; // eax@11
  int v4601; // esi@11
  int v4602; // eax@11
  int v4603; // esi@11
  int v4604; // eax@11
  int v4605; // esi@11
  int v4606; // eax@11
  int v4607; // esi@11
  int v4608; // eax@11
  int v4609; // esi@11
  int v4610; // eax@11
  int v4611; // esi@11
  int v4612; // eax@11
  int v4613; // esi@11
  int v4614; // eax@11
  int v4615; // esi@11
  int v4616; // eax@11
  int v4617; // esi@11
  int v4618; // eax@11
  int v4619; // esi@11
  int v4620; // eax@11
  int v4621; // esi@11
  int v4622; // eax@11
  int v4623; // esi@11
  int v4624; // eax@11
  int v4625; // esi@11
  int v4626; // eax@11
  int v4627; // esi@11
  int v4628; // eax@11
  int v4629; // esi@11
  int v4630; // eax@11
  int v4631; // esi@11
  int v4632; // eax@11
  int v4633; // esi@11
  int v4634; // eax@11
  int v4635; // esi@11
  int v4636; // eax@11
  int v4637; // esi@11
  int v4638; // eax@11
  int v4639; // esi@11
  int v4640; // eax@11
  int v4641; // esi@11
  int v4642; // eax@11
  int v4643; // esi@11
  int v4644; // eax@11
  int v4645; // esi@11
  int v4646; // eax@11
  int v4647; // esi@11
  int v4648; // eax@11
  int v4649; // esi@11
  int v4650; // eax@11
  int v4651; // esi@11
  int v4652; // eax@11
  int v4653; // esi@11
  int v4654; // eax@11
  int v4655; // esi@11
  int v4656; // eax@11
  int v4657; // esi@11
  int v4658; // eax@11
  int v4659; // esi@11
  int v4660; // eax@11
  int v4661; // esi@11
  int v4662; // eax@11
  int v4663; // esi@11
  int v4664; // eax@11
  int v4665; // esi@11
  int v4666; // eax@11
  int v4667; // esi@11
  int v4668; // eax@11
  int v4669; // esi@11
  int v4670; // eax@11
  int v4671; // esi@11
  int v4672; // eax@11
  int v4673; // esi@11
  int v4674; // eax@11
  int v4675; // esi@11
  int v4676; // eax@11
  int v4677; // esi@11
  int v4678; // eax@11
  int v4679; // esi@11
  int v4680; // eax@11
  int v4681; // esi@11
  int v4682; // eax@11
  int v4683; // esi@11
  int v4684; // eax@11
  int v4685; // esi@11
  int v4686; // eax@11
  int v4687; // esi@11
  int v4688; // eax@11
  int v4689; // esi@11
  int v4690; // eax@11
  int v4691; // esi@11
  int v4692; // eax@11
  int v4693; // esi@11
  int v4694; // eax@11
  int v4695; // esi@11
  int v4696; // eax@11
  int v4697; // esi@11
  int v4698; // eax@11
  int v4699; // esi@11
  int v4700; // eax@11
  int v4701; // esi@11
  int v4702; // eax@11
  int v4703; // esi@11
  int v4704; // eax@11
  int v4705; // esi@11
  int v4706; // eax@11
  int v4707; // esi@11
  int v4708; // eax@11
  int v4709; // esi@11
  int v4710; // eax@11
  int v4711; // esi@11
  int v4712; // eax@11
  int v4713; // esi@11
  int v4714; // eax@11
  int v4715; // esi@11
  int v4716; // eax@11
  int v4717; // esi@11
  int v4718; // eax@11
  int v4719; // esi@11
  int v4720; // eax@11
  int v4721; // esi@11
  int v4722; // eax@11
  int v4723; // esi@11
  int v4724; // eax@11
  int v4725; // esi@11
  int v4726; // eax@11
  int v4727; // esi@11
  int v4728; // eax@11
  int v4729; // esi@11
  int v4730; // eax@11
  int v4731; // esi@11
  int v4732; // eax@11
  int v4733; // esi@11
  int v4734; // eax@11
  int v4735; // esi@11
  int v4736; // eax@11
  int v4737; // esi@11
  int v4738; // eax@11
  int v4739; // esi@11
  int v4740; // eax@11
  int v4741; // esi@11
  int v4742; // eax@11
  int v4743; // esi@11
  int v4744; // eax@11
  int v4745; // esi@11
  int v4746; // eax@11
  int v4747; // esi@11
  int v4748; // eax@11
  int v4749; // esi@11
  int v4750; // eax@11
  int v4751; // esi@11
  int v4752; // eax@11
  int v4753; // esi@11
  int v4754; // eax@11
  int v4755; // esi@11
  int v4756; // eax@11
  int v4757; // esi@11
  int v4758; // eax@11
  int v4759; // esi@11
  int v4760; // eax@11
  int v4761; // esi@11
  int v4762; // eax@11
  int v4763; // esi@11
  int v4764; // eax@11
  int v4765; // esi@11
  int v4766; // eax@11
  int v4767; // esi@11
  int v4768; // eax@11
  int v4769; // esi@11
  int v4770; // eax@11
  int v4771; // esi@11
  int v4772; // eax@11
  int v4773; // esi@11
  int v4774; // eax@11
  int v4775; // esi@11
  int v4776; // eax@11
  int v4777; // esi@11
  int v4778; // eax@11
  int v4779; // esi@11
  int v4780; // eax@11
  int v4781; // esi@11
  int v4782; // eax@11
  int v4783; // esi@11
  int v4784; // eax@11
  int v4785; // esi@11
  int v4786; // eax@11
  int v4787; // esi@11
  int v4788; // eax@11
  int v4789; // esi@11
  int v4790; // eax@11
  int v4791; // esi@11
  int v4792; // eax@11
  int v4793; // esi@11
  int v4794; // eax@11
  int v4795; // esi@11
  int v4796; // eax@11
  int v4797; // esi@11
  int v4798; // eax@11
  int v4799; // esi@11
  int v4800; // eax@11
  int v4801; // esi@11
  int v4802; // eax@11
  int v4803; // esi@11
  int v4804; // eax@11
  int v4805; // esi@11
  int v4806; // eax@11
  int v4807; // esi@11
  int v4808; // eax@11
  int v4809; // esi@11
  int v4810; // eax@11
  int v4811; // esi@11
  int v4812; // eax@11
  int v4813; // esi@11
  int v4814; // eax@11
  int v4815; // esi@11
  int v4816; // eax@11
  int v4817; // esi@11
  int v4818; // eax@11
  int v4819; // esi@11
  int v4820; // eax@11
  int v4821; // esi@11
  int v4822; // eax@11
  int v4823; // esi@11
  int v4824; // eax@11
  int v4825; // esi@11
  int v4826; // eax@11
  int v4827; // esi@11
  int v4828; // eax@11
  int v4829; // esi@11
  int v4830; // eax@11
  int v4831; // esi@11
  int v4832; // eax@11
  int v4833; // esi@11
  int v4834; // eax@11
  int v4835; // esi@11
  int v4836; // eax@11
  int v4837; // esi@11
  int v4838; // eax@11
  int v4839; // esi@11
  int v4840; // eax@11
  int v4841; // esi@11
  int v4842; // eax@11
  int v4843; // esi@11
  int v4844; // eax@11
  int v4845; // esi@11
  int v4846; // eax@11
  int v4847; // esi@11
  int v4848; // eax@11
  int v4849; // esi@11
  int v4850; // eax@11
  int v4851; // esi@11
  int v4852; // eax@11
  int v4853; // esi@11
  int v4854; // eax@11
  int v4855; // esi@11
  int v4856; // eax@11
  int v4857; // esi@11
  int v4858; // eax@11
  int v4859; // esi@11
  int v4860; // eax@11
  int v4861; // esi@11
  int v4862; // eax@11
  int v4863; // esi@11
  int v4864; // eax@11
  int v4865; // esi@11
  int v4866; // eax@11
  int v4867; // esi@11
  int v4868; // eax@11
  int v4869; // esi@11
  int v4870; // eax@11
  int v4871; // esi@11
  int v4872; // eax@11
  int v4873; // esi@11
  int v4874; // eax@11
  int v4875; // esi@11
  int v4876; // eax@11
  int v4877; // esi@11
  int v4878; // eax@11
  int v4879; // esi@11
  int v4880; // eax@11
  int v4881; // esi@11
  int v4882; // eax@11
  int v4883; // esi@11
  int v4884; // eax@11
  int v4885; // esi@11
  int v4886; // eax@11
  int v4887; // esi@11
  int v4888; // eax@11
  int v4889; // esi@11
  int v4890; // eax@11
  int v4891; // esi@11
  int v4892; // eax@11
  int v4893; // esi@11
  int v4894; // eax@11
  int v4895; // esi@11
  int v4896; // eax@11
  int v4897; // esi@11
  int v4898; // eax@11
  int v4899; // esi@11
  int v4900; // eax@11
  int v4901; // esi@11
  int v4902; // eax@11
  int v4903; // esi@11
  int v4904; // eax@11
  int v4905; // esi@11
  int v4906; // eax@11
  int v4907; // esi@11
  int v4908; // eax@11
  int v4909; // esi@11
  int v4910; // eax@11
  int v4911; // esi@11
  int v4912; // eax@11
  int v4913; // esi@11
  int v4914; // eax@11
  int v4915; // esi@11
  int v4916; // eax@11
  int v4917; // esi@11
  int v4918; // eax@11
  int v4919; // esi@11
  int v4920; // eax@11
  int v4921; // esi@11
  int v4922; // eax@11
  int v4923; // esi@11
  int v4924; // eax@11
  int v4925; // esi@11
  int v4926; // eax@11
  int v4927; // esi@11
  int v4928; // eax@11
  int v4929; // esi@11
  int v4930; // eax@11
  int v4931; // esi@11
  int v4932; // eax@11
  int v4933; // esi@11
  int v4934; // eax@11
  int v4935; // esi@11
  int v4936; // eax@11
  int v4937; // esi@11
  int v4938; // eax@11
  int v4939; // esi@11
  int v4940; // eax@11
  int v4941; // esi@11
  int v4942; // eax@11
  int v4943; // esi@11
  int v4944; // eax@11
  int v4945; // esi@11
  int v4946; // eax@11
  int v4947; // esi@11
  int v4948; // eax@11
  int v4949; // esi@11
  int v4950; // eax@11
  int v4951; // esi@11
  int v4952; // eax@11
  int v4953; // esi@11
  int v4954; // eax@11
  int v4955; // esi@11
  int v4956; // eax@11
  int v4957; // esi@11
  int v4958; // eax@11
  int v4959; // esi@11
  int v4960; // eax@11
  int v4961; // esi@11
  int v4962; // eax@11
  int v4963; // esi@11
  int v4964; // eax@11
  int v4965; // esi@11
  int v4966; // eax@11
  int v4967; // esi@11
  int v4968; // eax@11
  int v4969; // esi@11
  int v4970; // eax@11
  int v4971; // esi@11
  int v4972; // eax@11
  int v4973; // esi@11
  int v4974; // eax@11
  int v4975; // esi@11
  int v4976; // eax@11
  int v4977; // esi@11
  int v4978; // eax@11
  int v4979; // esi@11
  int v4980; // eax@11
  int v4981; // esi@11
  int v4982; // eax@11
  int v4983; // esi@11
  int v4984; // eax@11
  int v4985; // esi@11
  int v4986; // eax@11
  int v4987; // esi@11
  int v4988; // eax@11
  int v4989; // esi@11
  int v4990; // eax@11
  int v4991; // esi@11
  int v4992; // eax@11
  int v4993; // esi@11
  int v4994; // eax@11
  int v4995; // esi@11
  int v4996; // eax@11
  int v4997; // esi@11
  int v4998; // eax@11
  int v4999; // esi@11
  int v5000; // eax@11
  int v5001; // esi@11
  int v5002; // eax@11
  int v5003; // esi@11
  int v5004; // eax@11
  int v5005; // esi@11
  int v5006; // eax@11
  int v5007; // esi@11
  int v5008; // eax@11
  int v5009; // esi@11
  int v5010; // eax@11
  int v5011; // esi@11
  int v5012; // eax@11
  int v5013; // esi@11
  int v5014; // eax@11
  int v5015; // esi@11
  int v5016; // eax@11
  int v5017; // esi@11
  int v5018; // eax@11
  int v5019; // esi@11
  int v5020; // eax@11
  int v5021; // esi@11
  int v5022; // eax@11
  int v5023; // esi@11
  int v5024; // eax@11
  int v5025; // esi@11
  int v5026; // eax@11
  int v5027; // esi@11
  int v5028; // eax@11
  int v5029; // esi@11
  int v5030; // eax@11
  int v5031; // esi@11
  int v5032; // eax@11
  int v5033; // esi@11
  int v5034; // eax@11
  int v5035; // esi@11
  int v5036; // eax@11
  int v5037; // esi@11
  int v5038; // eax@11
  int v5039; // esi@11
  int v5040; // eax@11
  int v5041; // esi@11
  int v5042; // eax@11
  int v5043; // esi@11
  int v5044; // eax@11
  int v5045; // esi@11
  int v5046; // eax@11
  int v5047; // esi@11
  int v5048; // eax@11
  int v5049; // esi@11
  int v5050; // eax@11
  int v5051; // esi@11
  int v5052; // eax@11
  int v5053; // esi@11
  int v5054; // eax@11
  int v5055; // esi@11
  int v5056; // eax@11
  int v5057; // esi@11
  int v5058; // eax@11
  int v5059; // esi@11
  int v5060; // eax@11
  int v5061; // esi@11
  int v5062; // eax@11
  int v5063; // esi@11
  int v5064; // eax@11
  int v5065; // esi@11
  int v5066; // eax@11
  int v5067; // esi@11
  int v5068; // eax@11
  int v5069; // esi@11
  int v5070; // eax@11
  int v5071; // esi@11
  int v5072; // eax@11
  int v5073; // esi@11
  int v5074; // eax@11
  int v5075; // esi@11
  int v5076; // eax@11
  int v5077; // esi@11
  int v5078; // eax@11
  int v5079; // esi@11
  int v5080; // eax@11
  int v5081; // esi@11
  int v5082; // eax@11
  int v5083; // esi@11
  int v5084; // eax@11
  int v5085; // esi@11
  int v5086; // eax@11
  int v5087; // esi@11
  int v5088; // eax@11
  int v5089; // esi@11
  int v5090; // eax@11
  int v5091; // esi@11
  int v5092; // eax@11
  int v5093; // esi@11
  int v5094; // eax@11
  int v5095; // esi@11
  int v5096; // eax@11
  int v5097; // esi@11
  int v5098; // eax@11
  int v5099; // esi@11
  int v5100; // eax@11
  int v5101; // esi@11
  int v5102; // eax@11
  int v5103; // esi@11
  int v5104; // eax@11
  int v5105; // esi@11
  int v5106; // eax@11
  int v5107; // esi@11
  int v5108; // eax@11
  int v5109; // esi@11
  int v5110; // eax@11
  int v5111; // esi@11
  int v5112; // eax@11
  int v5113; // esi@11
  int v5114; // eax@11
  int v5115; // esi@11
  int v5116; // eax@11
  int v5117; // esi@11
  int v5118; // eax@11
  int v5119; // esi@11
  int v5120; // eax@11
  int v5121; // esi@11
  int v5122; // eax@11
  int v5123; // esi@11
  int v5124; // eax@11
  int v5125; // esi@11
  int v5126; // eax@11
  int v5127; // esi@11
  int v5128; // eax@11
  int v5129; // esi@11
  int v5130; // eax@11
  int v5131; // esi@11
  int v5132; // eax@11
  int v5133; // esi@11
  int v5134; // eax@11
  int v5135; // esi@11
  int v5136; // eax@11
  int v5137; // esi@11
  int v5138; // eax@11
  int v5139; // esi@11
  int v5140; // eax@11
  int v5141; // esi@11
  int v5142; // eax@11
  int v5143; // esi@11
  int v5144; // eax@11
  int v5145; // esi@11
  int v5146; // eax@11
  int v5147; // esi@11
  int v5148; // eax@11
  int v5149; // esi@11
  int v5150; // eax@11
  int v5151; // esi@11
  int v5152; // eax@11
  int v5153; // esi@11
  int v5154; // eax@11
  int v5155; // esi@11
  int v5156; // eax@11
  int v5157; // esi@11
  int v5158; // eax@11
  int v5159; // esi@11
  int v5160; // eax@11
  int v5161; // esi@11
  int v5162; // eax@11
  int v5163; // esi@11
  int v5164; // eax@11
  int v5165; // esi@11
  int v5166; // eax@11
  int v5167; // esi@11
  int v5168; // eax@11
  int v5169; // esi@11
  int v5170; // eax@11
  int v5171; // esi@11
  int v5172; // eax@11
  int v5173; // esi@11
  int v5174; // eax@11
  int v5175; // esi@11
  int v5176; // eax@11
  int v5177; // esi@11
  int v5178; // eax@11
  int v5179; // esi@11
  int v5180; // eax@11
  int v5181; // esi@11
  int v5182; // eax@11
  int v5183; // esi@11
  int v5184; // eax@11
  int v5185; // esi@11
  int v5186; // eax@11
  int v5187; // esi@11
  int v5188; // eax@11
  int v5189; // esi@11
  int v5190; // eax@11
  int v5191; // esi@11
  int v5192; // eax@11
  int v5193; // esi@11
  int v5194; // eax@11
  int v5195; // esi@11
  int v5196; // eax@11
  int v5197; // esi@11
  int v5198; // eax@11
  int v5199; // esi@11
  int v5200; // eax@11
  int v5201; // esi@11
  int v5202; // eax@11
  int v5203; // esi@11
  int v5204; // eax@11
  int v5205; // esi@11
  int v5206; // eax@11
  int v5207; // esi@11
  int v5208; // eax@11
  int v5209; // esi@11
  int v5210; // eax@11
  int v5211; // esi@11
  int v5212; // eax@11
  int v5213; // esi@11
  int v5214; // eax@11
  int v5215; // esi@11
  int v5216; // eax@11
  int v5217; // esi@11
  int v5218; // eax@11
  int v5219; // esi@11
  int v5220; // eax@11
  int v5221; // esi@11
  int v5222; // eax@11
  int v5223; // esi@11
  int v5224; // eax@11
  int v5225; // esi@11
  int v5226; // eax@11
  int v5227; // edi@12
  int v5228; // eax@12
  int v5229; // esi@13
  int v5230; // eax@13
  int v5231; // eax@16
  int v5232; // eax@18
  int v5233; // eax@20
  int v5234; // esi@21
  int v5235; // eax@21
  int v5236; // esi@21
  int v5237; // eax@21
  int v5238; // esi@21
  int v5239; // eax@21
  int v5240; // esi@21
  int v5241; // eax@21
  int v5242; // esi@21
  int v5243; // eax@21
  void *v5244; // [sp+8h] [bp-F02Ch]@2
  int v5245; // [sp+Ch] [bp-F028h]@12
  int v5246; // [sp+10h] [bp-F024h]@1
  int v5247; // [sp+14h] [bp-F020h]@9
  char v5248; // [sp+18h] [bp-F01Ch]@21
  char v5249; // [sp+30h] [bp-F004h]@11
  char v5250; // [sp+48h] [bp-EFECh]@21
  char v5251; // [sp+60h] [bp-EFD4h]@11
  char v5252; // [sp+78h] [bp-EFBCh]@21
  char v5253; // [sp+90h] [bp-EFA4h]@11
  char v5254; // [sp+A8h] [bp-EF8Ch]@21
  char v5255; // [sp+C0h] [bp-EF74h]@11
  char v5256; // [sp+D8h] [bp-EF5Ch]@11
  char v5257; // [sp+F0h] [bp-EF44h]@11
  char v5258; // [sp+108h] [bp-EF2Ch]@11
  char v5259; // [sp+120h] [bp-EF14h]@11
  char v5260; // [sp+138h] [bp-EEFCh]@11
  char v5261; // [sp+150h] [bp-EEE4h]@11
  char v5262; // [sp+168h] [bp-EECCh]@11
  char v5263; // [sp+180h] [bp-EEB4h]@11
  char v5264; // [sp+198h] [bp-EE9Ch]@11
  char v5265; // [sp+1B0h] [bp-EE84h]@11
  char v5266; // [sp+1C8h] [bp-EE6Ch]@11
  char v5267; // [sp+1E0h] [bp-EE54h]@11
  char v5268; // [sp+1F8h] [bp-EE3Ch]@11
  char v5269; // [sp+210h] [bp-EE24h]@11
  char v5270; // [sp+228h] [bp-EE0Ch]@11
  char v5271; // [sp+240h] [bp-EDF4h]@11
  char v5272; // [sp+258h] [bp-EDDCh]@11
  char v5273; // [sp+270h] [bp-EDC4h]@11
  char v5274; // [sp+288h] [bp-EDACh]@11
  char v5275; // [sp+2A0h] [bp-ED94h]@11
  char v5276; // [sp+2B8h] [bp-ED7Ch]@11
  char v5277; // [sp+2D0h] [bp-ED64h]@11
  char v5278; // [sp+2E8h] [bp-ED4Ch]@11
  char v5279; // [sp+300h] [bp-ED34h]@11
  char v5280; // [sp+318h] [bp-ED1Ch]@11
  char v5281; // [sp+330h] [bp-ED04h]@11
  char v5282; // [sp+348h] [bp-ECECh]@11
  char v5283; // [sp+360h] [bp-ECD4h]@11
  char v5284; // [sp+378h] [bp-ECBCh]@11
  char v5285; // [sp+390h] [bp-ECA4h]@11
  char v5286; // [sp+3A8h] [bp-EC8Ch]@11
  char v5287; // [sp+3C0h] [bp-EC74h]@11
  char v5288; // [sp+3D8h] [bp-EC5Ch]@11
  char v5289; // [sp+3F0h] [bp-EC44h]@11
  char v5290; // [sp+408h] [bp-EC2Ch]@11
  char v5291; // [sp+420h] [bp-EC14h]@11
  char v5292; // [sp+438h] [bp-EBFCh]@11
  char v5293; // [sp+450h] [bp-EBE4h]@11
  char v5294; // [sp+468h] [bp-EBCCh]@11
  char v5295; // [sp+480h] [bp-EBB4h]@11
  char v5296; // [sp+498h] [bp-EB9Ch]@11
  char v5297; // [sp+4B0h] [bp-EB84h]@11
  char v5298; // [sp+4C8h] [bp-EB6Ch]@11
  char v5299; // [sp+4E0h] [bp-EB54h]@11
  char v5300; // [sp+4F8h] [bp-EB3Ch]@11
  char v5301; // [sp+510h] [bp-EB24h]@11
  char v5302; // [sp+528h] [bp-EB0Ch]@11
  char v5303; // [sp+540h] [bp-EAF4h]@11
  char v5304; // [sp+558h] [bp-EADCh]@11
  char v5305; // [sp+570h] [bp-EAC4h]@11
  char v5306; // [sp+588h] [bp-EAACh]@11
  char v5307; // [sp+5A0h] [bp-EA94h]@11
  char v5308; // [sp+5B8h] [bp-EA7Ch]@11
  char v5309; // [sp+5D0h] [bp-EA64h]@11
  char v5310; // [sp+5E8h] [bp-EA4Ch]@11
  char v5311; // [sp+600h] [bp-EA34h]@11
  char v5312; // [sp+618h] [bp-EA1Ch]@11
  char v5313; // [sp+630h] [bp-EA04h]@11
  char v5314; // [sp+648h] [bp-E9ECh]@11
  char v5315; // [sp+660h] [bp-E9D4h]@11
  char v5316; // [sp+678h] [bp-E9BCh]@11
  char v5317; // [sp+690h] [bp-E9A4h]@11
  char v5318; // [sp+6A8h] [bp-E98Ch]@11
  char v5319; // [sp+6C0h] [bp-E974h]@11
  char v5320; // [sp+6D8h] [bp-E95Ch]@11
  char v5321; // [sp+6F0h] [bp-E944h]@11
  char v5322; // [sp+708h] [bp-E92Ch]@11
  char v5323; // [sp+720h] [bp-E914h]@11
  char v5324; // [sp+738h] [bp-E8FCh]@11
  char v5325; // [sp+750h] [bp-E8E4h]@11
  char v5326; // [sp+768h] [bp-E8CCh]@11
  char v5327; // [sp+780h] [bp-E8B4h]@11
  char v5328; // [sp+798h] [bp-E89Ch]@11
  char v5329; // [sp+7B0h] [bp-E884h]@11
  char v5330; // [sp+7C8h] [bp-E86Ch]@11
  char v5331; // [sp+7E0h] [bp-E854h]@11
  char v5332; // [sp+7F8h] [bp-E83Ch]@11
  char v5333; // [sp+810h] [bp-E824h]@11
  char v5334; // [sp+828h] [bp-E80Ch]@11
  char v5335; // [sp+840h] [bp-E7F4h]@11
  char v5336; // [sp+858h] [bp-E7DCh]@11
  char v5337; // [sp+870h] [bp-E7C4h]@11
  char v5338; // [sp+888h] [bp-E7ACh]@11
  char v5339; // [sp+8A0h] [bp-E794h]@11
  char v5340; // [sp+8B8h] [bp-E77Ch]@11
  char v5341; // [sp+8D0h] [bp-E764h]@11
  char v5342; // [sp+8E8h] [bp-E74Ch]@11
  char v5343; // [sp+900h] [bp-E734h]@11
  char v5344; // [sp+918h] [bp-E71Ch]@11
  char v5345; // [sp+930h] [bp-E704h]@11
  char v5346; // [sp+948h] [bp-E6ECh]@11
  char v5347; // [sp+960h] [bp-E6D4h]@11
  char v5348; // [sp+978h] [bp-E6BCh]@11
  char v5349; // [sp+990h] [bp-E6A4h]@11
  char v5350; // [sp+9A8h] [bp-E68Ch]@11
  char v5351; // [sp+9C0h] [bp-E674h]@11
  char v5352; // [sp+9D8h] [bp-E65Ch]@11
  char v5353; // [sp+9F0h] [bp-E644h]@11
  char v5354; // [sp+A08h] [bp-E62Ch]@11
  char v5355; // [sp+A20h] [bp-E614h]@11
  char v5356; // [sp+A38h] [bp-E5FCh]@11
  char v5357; // [sp+A50h] [bp-E5E4h]@11
  char v5358; // [sp+A68h] [bp-E5CCh]@11
  char v5359; // [sp+A80h] [bp-E5B4h]@11
  char v5360; // [sp+A98h] [bp-E59Ch]@11
  char v5361; // [sp+AB0h] [bp-E584h]@11
  char v5362; // [sp+AC8h] [bp-E56Ch]@11
  char v5363; // [sp+AE0h] [bp-E554h]@11
  char v5364; // [sp+AF8h] [bp-E53Ch]@11
  char v5365; // [sp+B10h] [bp-E524h]@11
  char v5366; // [sp+B28h] [bp-E50Ch]@11
  char v5367; // [sp+B40h] [bp-E4F4h]@11
  char v5368; // [sp+B58h] [bp-E4DCh]@11
  char v5369; // [sp+B70h] [bp-E4C4h]@11
  char v5370; // [sp+B88h] [bp-E4ACh]@11
  char v5371; // [sp+BA0h] [bp-E494h]@11
  char v5372; // [sp+BB8h] [bp-E47Ch]@11
  char v5373; // [sp+BD0h] [bp-E464h]@11
  char v5374; // [sp+BE8h] [bp-E44Ch]@11
  char v5375; // [sp+C00h] [bp-E434h]@11
  char v5376; // [sp+C18h] [bp-E41Ch]@11
  char v5377; // [sp+C30h] [bp-E404h]@11
  char v5378; // [sp+C48h] [bp-E3ECh]@11
  char v5379; // [sp+C60h] [bp-E3D4h]@11
  char v5380; // [sp+C78h] [bp-E3BCh]@11
  char v5381; // [sp+C90h] [bp-E3A4h]@11
  char v5382; // [sp+CA8h] [bp-E38Ch]@11
  char v5383; // [sp+CC0h] [bp-E374h]@11
  char v5384; // [sp+CD8h] [bp-E35Ch]@11
  char v5385; // [sp+CF0h] [bp-E344h]@11
  char v5386; // [sp+D08h] [bp-E32Ch]@11
  char v5387; // [sp+D20h] [bp-E314h]@11
  char v5388; // [sp+D38h] [bp-E2FCh]@11
  char v5389; // [sp+D50h] [bp-E2E4h]@11
  char v5390; // [sp+D68h] [bp-E2CCh]@11
  char v5391; // [sp+D80h] [bp-E2B4h]@11
  char v5392; // [sp+D98h] [bp-E29Ch]@11
  char v5393; // [sp+DB0h] [bp-E284h]@11
  char v5394; // [sp+DC8h] [bp-E26Ch]@11
  char v5395; // [sp+DE0h] [bp-E254h]@11
  char v5396; // [sp+DF8h] [bp-E23Ch]@11
  char v5397; // [sp+E10h] [bp-E224h]@11
  char v5398; // [sp+E28h] [bp-E20Ch]@11
  char v5399; // [sp+E40h] [bp-E1F4h]@11
  char v5400; // [sp+E58h] [bp-E1DCh]@11
  char v5401; // [sp+E70h] [bp-E1C4h]@11
  char v5402; // [sp+E88h] [bp-E1ACh]@11
  char v5403; // [sp+EA0h] [bp-E194h]@11
  char v5404; // [sp+EB8h] [bp-E17Ch]@11
  char v5405; // [sp+ED0h] [bp-E164h]@11
  char v5406; // [sp+EE8h] [bp-E14Ch]@11
  char v5407; // [sp+F00h] [bp-E134h]@11
  char v5408; // [sp+F18h] [bp-E11Ch]@11
  char v5409; // [sp+F30h] [bp-E104h]@11
  char v5410; // [sp+F48h] [bp-E0ECh]@11
  char v5411; // [sp+F60h] [bp-E0D4h]@11
  char v5412; // [sp+F78h] [bp-E0BCh]@11
  char v5413; // [sp+F90h] [bp-E0A4h]@11
  char v5414; // [sp+FA8h] [bp-E08Ch]@11
  char v5415; // [sp+FC0h] [bp-E074h]@11
  char v5416; // [sp+FD8h] [bp-E05Ch]@11
  char v5417; // [sp+FF0h] [bp-E044h]@11
  char v5418; // [sp+1008h] [bp-E02Ch]@11
  char v5419; // [sp+1020h] [bp-E014h]@11
  char v5420; // [sp+1038h] [bp-DFFCh]@11
  char v5421; // [sp+1050h] [bp-DFE4h]@11
  char v5422; // [sp+1068h] [bp-DFCCh]@11
  char v5423; // [sp+1080h] [bp-DFB4h]@11
  char v5424; // [sp+1098h] [bp-DF9Ch]@11
  char v5425; // [sp+10B0h] [bp-DF84h]@11
  char v5426; // [sp+10C8h] [bp-DF6Ch]@11
  char v5427; // [sp+10E0h] [bp-DF54h]@11
  char v5428; // [sp+10F8h] [bp-DF3Ch]@11
  char v5429; // [sp+1110h] [bp-DF24h]@11
  char v5430; // [sp+1128h] [bp-DF0Ch]@11
  char v5431; // [sp+1140h] [bp-DEF4h]@11
  char v5432; // [sp+1158h] [bp-DEDCh]@11
  char v5433; // [sp+1170h] [bp-DEC4h]@11
  char v5434; // [sp+1188h] [bp-DEACh]@11
  char v5435; // [sp+11A0h] [bp-DE94h]@11
  char v5436; // [sp+11B8h] [bp-DE7Ch]@11
  char v5437; // [sp+11D0h] [bp-DE64h]@11
  char v5438; // [sp+11E8h] [bp-DE4Ch]@11
  char v5439; // [sp+1200h] [bp-DE34h]@11
  char v5440; // [sp+1218h] [bp-DE1Ch]@11
  char v5441; // [sp+1230h] [bp-DE04h]@11
  char v5442; // [sp+1248h] [bp-DDECh]@11
  char v5443; // [sp+1260h] [bp-DDD4h]@11
  char v5444; // [sp+1278h] [bp-DDBCh]@11
  char v5445; // [sp+1290h] [bp-DDA4h]@11
  char v5446; // [sp+12A8h] [bp-DD8Ch]@11
  char v5447; // [sp+12C0h] [bp-DD74h]@11
  char v5448; // [sp+12D8h] [bp-DD5Ch]@11
  char v5449; // [sp+12F0h] [bp-DD44h]@11
  char v5450; // [sp+1308h] [bp-DD2Ch]@11
  char v5451; // [sp+1320h] [bp-DD14h]@11
  char v5452; // [sp+1338h] [bp-DCFCh]@11
  char v5453; // [sp+1350h] [bp-DCE4h]@11
  char v5454; // [sp+1368h] [bp-DCCCh]@11
  char v5455; // [sp+1380h] [bp-DCB4h]@11
  char v5456; // [sp+1398h] [bp-DC9Ch]@11
  char v5457; // [sp+13B0h] [bp-DC84h]@11
  char v5458; // [sp+13C8h] [bp-DC6Ch]@11
  char v5459; // [sp+13E0h] [bp-DC54h]@11
  char v5460; // [sp+13F8h] [bp-DC3Ch]@11
  char v5461; // [sp+1410h] [bp-DC24h]@11
  char v5462; // [sp+1428h] [bp-DC0Ch]@11
  char v5463; // [sp+1440h] [bp-DBF4h]@11
  char v5464; // [sp+1458h] [bp-DBDCh]@11
  char v5465; // [sp+1470h] [bp-DBC4h]@11
  char v5466; // [sp+1488h] [bp-DBACh]@11
  char v5467; // [sp+14A0h] [bp-DB94h]@11
  char v5468; // [sp+14B8h] [bp-DB7Ch]@11
  char v5469; // [sp+14D0h] [bp-DB64h]@11
  char v5470; // [sp+14E8h] [bp-DB4Ch]@11
  char v5471; // [sp+1500h] [bp-DB34h]@11
  char v5472; // [sp+1518h] [bp-DB1Ch]@11
  char v5473; // [sp+1530h] [bp-DB04h]@11
  char v5474; // [sp+1548h] [bp-DAECh]@11
  char v5475; // [sp+1560h] [bp-DAD4h]@11
  char v5476; // [sp+1578h] [bp-DABCh]@11
  char v5477; // [sp+1590h] [bp-DAA4h]@11
  char v5478; // [sp+15A8h] [bp-DA8Ch]@11
  char v5479; // [sp+15C0h] [bp-DA74h]@11
  char v5480; // [sp+15D8h] [bp-DA5Ch]@11
  char v5481; // [sp+15F0h] [bp-DA44h]@11
  char v5482; // [sp+1608h] [bp-DA2Ch]@11
  char v5483; // [sp+1620h] [bp-DA14h]@11
  char v5484; // [sp+1638h] [bp-D9FCh]@11
  char v5485; // [sp+1650h] [bp-D9E4h]@11
  char v5486; // [sp+1668h] [bp-D9CCh]@11
  char v5487; // [sp+1680h] [bp-D9B4h]@11
  char v5488; // [sp+1698h] [bp-D99Ch]@11
  char v5489; // [sp+16B0h] [bp-D984h]@11
  char v5490; // [sp+16C8h] [bp-D96Ch]@11
  char v5491; // [sp+16E0h] [bp-D954h]@11
  char v5492; // [sp+16F8h] [bp-D93Ch]@11
  char v5493; // [sp+1710h] [bp-D924h]@11
  char v5494; // [sp+1728h] [bp-D90Ch]@11
  char v5495; // [sp+1740h] [bp-D8F4h]@11
  char v5496; // [sp+1758h] [bp-D8DCh]@11
  char v5497; // [sp+1770h] [bp-D8C4h]@11
  char v5498; // [sp+1788h] [bp-D8ACh]@11
  char v5499; // [sp+17A0h] [bp-D894h]@11
  char v5500; // [sp+17B8h] [bp-D87Ch]@11
  char v5501; // [sp+17D0h] [bp-D864h]@11
  char v5502; // [sp+17E8h] [bp-D84Ch]@11
  char v5503; // [sp+1800h] [bp-D834h]@11
  char v5504; // [sp+1818h] [bp-D81Ch]@11
  char v5505; // [sp+1830h] [bp-D804h]@11
  char v5506; // [sp+1848h] [bp-D7ECh]@11
  char v5507; // [sp+1860h] [bp-D7D4h]@11
  char v5508; // [sp+1878h] [bp-D7BCh]@11
  char v5509; // [sp+1890h] [bp-D7A4h]@11
  char v5510; // [sp+18A8h] [bp-D78Ch]@11
  char v5511; // [sp+18C0h] [bp-D774h]@11
  char v5512; // [sp+18D8h] [bp-D75Ch]@11
  char v5513; // [sp+18F0h] [bp-D744h]@11
  char v5514; // [sp+1908h] [bp-D72Ch]@11
  char v5515; // [sp+1920h] [bp-D714h]@11
  char v5516; // [sp+1938h] [bp-D6FCh]@11
  char v5517; // [sp+1950h] [bp-D6E4h]@11
  char v5518; // [sp+1968h] [bp-D6CCh]@11
  char v5519; // [sp+1980h] [bp-D6B4h]@11
  char v5520; // [sp+1998h] [bp-D69Ch]@11
  char v5521; // [sp+19B0h] [bp-D684h]@11
  char v5522; // [sp+19C8h] [bp-D66Ch]@11
  char v5523; // [sp+19E0h] [bp-D654h]@11
  char v5524; // [sp+19F8h] [bp-D63Ch]@11
  char v5525; // [sp+1A10h] [bp-D624h]@11
  char v5526; // [sp+1A28h] [bp-D60Ch]@11
  char v5527; // [sp+1A40h] [bp-D5F4h]@11
  char v5528; // [sp+1A58h] [bp-D5DCh]@11
  char v5529; // [sp+1A70h] [bp-D5C4h]@11
  char v5530; // [sp+1A88h] [bp-D5ACh]@11
  char v5531; // [sp+1AA0h] [bp-D594h]@11
  char v5532; // [sp+1AB8h] [bp-D57Ch]@11
  char v5533; // [sp+1AD0h] [bp-D564h]@11
  char v5534; // [sp+1AE8h] [bp-D54Ch]@11
  char v5535; // [sp+1B00h] [bp-D534h]@11
  char v5536; // [sp+1B18h] [bp-D51Ch]@11
  char v5537; // [sp+1B30h] [bp-D504h]@11
  char v5538; // [sp+1B48h] [bp-D4ECh]@11
  char v5539; // [sp+1B60h] [bp-D4D4h]@11
  char v5540; // [sp+1B78h] [bp-D4BCh]@11
  char v5541; // [sp+1B90h] [bp-D4A4h]@11
  char v5542; // [sp+1BA8h] [bp-D48Ch]@11
  char v5543; // [sp+1BC0h] [bp-D474h]@11
  char v5544; // [sp+1BD8h] [bp-D45Ch]@11
  char v5545; // [sp+1BF0h] [bp-D444h]@11
  char v5546; // [sp+1C08h] [bp-D42Ch]@11
  char v5547; // [sp+1C20h] [bp-D414h]@11
  char v5548; // [sp+1C38h] [bp-D3FCh]@11
  char v5549; // [sp+1C50h] [bp-D3E4h]@11
  char v5550; // [sp+1C68h] [bp-D3CCh]@11
  char v5551; // [sp+1C80h] [bp-D3B4h]@11
  char v5552; // [sp+1C98h] [bp-D39Ch]@11
  char v5553; // [sp+1CB0h] [bp-D384h]@11
  char v5554; // [sp+1CC8h] [bp-D36Ch]@11
  char v5555; // [sp+1CE0h] [bp-D354h]@11
  char v5556; // [sp+1CF8h] [bp-D33Ch]@11
  char v5557; // [sp+1D10h] [bp-D324h]@11
  char v5558; // [sp+1D28h] [bp-D30Ch]@11
  char v5559; // [sp+1D40h] [bp-D2F4h]@11
  char v5560; // [sp+1D58h] [bp-D2DCh]@11
  char v5561; // [sp+1D70h] [bp-D2C4h]@11
  char v5562; // [sp+1D88h] [bp-D2ACh]@11
  char v5563; // [sp+1DA0h] [bp-D294h]@11
  char v5564; // [sp+1DB8h] [bp-D27Ch]@11
  char v5565; // [sp+1DD0h] [bp-D264h]@11
  char v5566; // [sp+1DE8h] [bp-D24Ch]@11
  char v5567; // [sp+1E00h] [bp-D234h]@11
  char v5568; // [sp+1E18h] [bp-D21Ch]@11
  char v5569; // [sp+1E30h] [bp-D204h]@11
  char v5570; // [sp+1E48h] [bp-D1ECh]@11
  char v5571; // [sp+1E60h] [bp-D1D4h]@11
  char v5572; // [sp+1E78h] [bp-D1BCh]@11
  char v5573; // [sp+1E90h] [bp-D1A4h]@11
  char v5574; // [sp+1EA8h] [bp-D18Ch]@11
  char v5575; // [sp+1EC0h] [bp-D174h]@11
  char v5576; // [sp+1ED8h] [bp-D15Ch]@11
  char v5577; // [sp+1EF0h] [bp-D144h]@11
  char v5578; // [sp+1F08h] [bp-D12Ch]@11
  char v5579; // [sp+1F20h] [bp-D114h]@11
  char v5580; // [sp+1F38h] [bp-D0FCh]@11
  char v5581; // [sp+1F50h] [bp-D0E4h]@11
  char v5582; // [sp+1F68h] [bp-D0CCh]@11
  char v5583; // [sp+1F80h] [bp-D0B4h]@11
  char v5584; // [sp+1F98h] [bp-D09Ch]@11
  char v5585; // [sp+1FB0h] [bp-D084h]@11
  char v5586; // [sp+1FC8h] [bp-D06Ch]@11
  char v5587; // [sp+1FE0h] [bp-D054h]@11
  char v5588; // [sp+1FF8h] [bp-D03Ch]@11
  char v5589; // [sp+2010h] [bp-D024h]@11
  char v5590; // [sp+2028h] [bp-D00Ch]@11
  char v5591; // [sp+2040h] [bp-CFF4h]@11
  char v5592; // [sp+2058h] [bp-CFDCh]@11
  char v5593; // [sp+2070h] [bp-CFC4h]@11
  char v5594; // [sp+2088h] [bp-CFACh]@11
  char v5595; // [sp+20A0h] [bp-CF94h]@11
  char v5596; // [sp+20B8h] [bp-CF7Ch]@11
  char v5597; // [sp+20D0h] [bp-CF64h]@11
  char v5598; // [sp+20E8h] [bp-CF4Ch]@11
  char v5599; // [sp+2100h] [bp-CF34h]@11
  char v5600; // [sp+2118h] [bp-CF1Ch]@11
  char v5601; // [sp+2130h] [bp-CF04h]@11
  char v5602; // [sp+2148h] [bp-CEECh]@11
  char v5603; // [sp+2160h] [bp-CED4h]@11
  char v5604; // [sp+2178h] [bp-CEBCh]@11
  char v5605; // [sp+2190h] [bp-CEA4h]@11
  char v5606; // [sp+21A8h] [bp-CE8Ch]@11
  char v5607; // [sp+21C0h] [bp-CE74h]@11
  char v5608; // [sp+21D8h] [bp-CE5Ch]@11
  char v5609; // [sp+21F0h] [bp-CE44h]@11
  char v5610; // [sp+2208h] [bp-CE2Ch]@11
  char v5611; // [sp+2220h] [bp-CE14h]@11
  char v5612; // [sp+2238h] [bp-CDFCh]@11
  char v5613; // [sp+2250h] [bp-CDE4h]@11
  char v5614; // [sp+2268h] [bp-CDCCh]@11
  char v5615; // [sp+2280h] [bp-CDB4h]@11
  char v5616; // [sp+2298h] [bp-CD9Ch]@11
  char v5617; // [sp+22B0h] [bp-CD84h]@11
  char v5618; // [sp+22C8h] [bp-CD6Ch]@11
  char v5619; // [sp+22E0h] [bp-CD54h]@11
  char v5620; // [sp+22F8h] [bp-CD3Ch]@11
  char v5621; // [sp+2310h] [bp-CD24h]@11
  char v5622; // [sp+2328h] [bp-CD0Ch]@11
  char v5623; // [sp+2340h] [bp-CCF4h]@11
  char v5624; // [sp+2358h] [bp-CCDCh]@11
  char v5625; // [sp+2370h] [bp-CCC4h]@11
  char v5626; // [sp+2388h] [bp-CCACh]@11
  char v5627; // [sp+23A0h] [bp-CC94h]@11
  char v5628; // [sp+23B8h] [bp-CC7Ch]@11
  char v5629; // [sp+23D0h] [bp-CC64h]@11
  char v5630; // [sp+23E8h] [bp-CC4Ch]@11
  char v5631; // [sp+2400h] [bp-CC34h]@11
  char v5632; // [sp+2418h] [bp-CC1Ch]@11
  char v5633; // [sp+2430h] [bp-CC04h]@11
  char v5634; // [sp+2448h] [bp-CBECh]@11
  char v5635; // [sp+2460h] [bp-CBD4h]@11
  char v5636; // [sp+2478h] [bp-CBBCh]@11
  char v5637; // [sp+2490h] [bp-CBA4h]@11
  char v5638; // [sp+24A8h] [bp-CB8Ch]@11
  char v5639; // [sp+24C0h] [bp-CB74h]@11
  char v5640; // [sp+24D8h] [bp-CB5Ch]@11
  char v5641; // [sp+24F0h] [bp-CB44h]@11
  char v5642; // [sp+2508h] [bp-CB2Ch]@11
  char v5643; // [sp+2520h] [bp-CB14h]@11
  char v5644; // [sp+2538h] [bp-CAFCh]@11
  char v5645; // [sp+2550h] [bp-CAE4h]@11
  char v5646; // [sp+2568h] [bp-CACCh]@11
  char v5647; // [sp+2580h] [bp-CAB4h]@11
  char v5648; // [sp+2598h] [bp-CA9Ch]@11
  char v5649; // [sp+25B0h] [bp-CA84h]@11
  char v5650; // [sp+25C8h] [bp-CA6Ch]@11
  char v5651; // [sp+25E0h] [bp-CA54h]@11
  char v5652; // [sp+25F8h] [bp-CA3Ch]@11
  char v5653; // [sp+2610h] [bp-CA24h]@11
  char v5654; // [sp+2628h] [bp-CA0Ch]@11
  char v5655; // [sp+2640h] [bp-C9F4h]@11
  char v5656; // [sp+2658h] [bp-C9DCh]@11
  char v5657; // [sp+2670h] [bp-C9C4h]@11
  char v5658; // [sp+2688h] [bp-C9ACh]@11
  char v5659; // [sp+26A0h] [bp-C994h]@11
  char v5660; // [sp+26B8h] [bp-C97Ch]@11
  char v5661; // [sp+26D0h] [bp-C964h]@11
  char v5662; // [sp+26E8h] [bp-C94Ch]@11
  char v5663; // [sp+2700h] [bp-C934h]@11
  char v5664; // [sp+2718h] [bp-C91Ch]@11
  char v5665; // [sp+2730h] [bp-C904h]@11
  char v5666; // [sp+2748h] [bp-C8ECh]@11
  char v5667; // [sp+2760h] [bp-C8D4h]@11
  char v5668; // [sp+2778h] [bp-C8BCh]@11
  char v5669; // [sp+2790h] [bp-C8A4h]@11
  char v5670; // [sp+27A8h] [bp-C88Ch]@11
  char v5671; // [sp+27C0h] [bp-C874h]@11
  char v5672; // [sp+27D8h] [bp-C85Ch]@11
  char v5673; // [sp+27F0h] [bp-C844h]@11
  char v5674; // [sp+2808h] [bp-C82Ch]@11
  char v5675; // [sp+2820h] [bp-C814h]@11
  char v5676; // [sp+2838h] [bp-C7FCh]@11
  char v5677; // [sp+2850h] [bp-C7E4h]@11
  char v5678; // [sp+2868h] [bp-C7CCh]@11
  char v5679; // [sp+2880h] [bp-C7B4h]@11
  char v5680; // [sp+2898h] [bp-C79Ch]@11
  char v5681; // [sp+28B0h] [bp-C784h]@11
  char v5682; // [sp+28C8h] [bp-C76Ch]@11
  char v5683; // [sp+28E0h] [bp-C754h]@11
  char v5684; // [sp+28F8h] [bp-C73Ch]@11
  char v5685; // [sp+2910h] [bp-C724h]@11
  char v5686; // [sp+2928h] [bp-C70Ch]@11
  char v5687; // [sp+2940h] [bp-C6F4h]@11
  char v5688; // [sp+2958h] [bp-C6DCh]@11
  char v5689; // [sp+2970h] [bp-C6C4h]@11
  char v5690; // [sp+2988h] [bp-C6ACh]@11
  char v5691; // [sp+29A0h] [bp-C694h]@11
  char v5692; // [sp+29B8h] [bp-C67Ch]@11
  char v5693; // [sp+29D0h] [bp-C664h]@11
  char v5694; // [sp+29E8h] [bp-C64Ch]@11
  char v5695; // [sp+2A00h] [bp-C634h]@11
  char v5696; // [sp+2A18h] [bp-C61Ch]@11
  char v5697; // [sp+2A30h] [bp-C604h]@11
  char v5698; // [sp+2A48h] [bp-C5ECh]@11
  char v5699; // [sp+2A60h] [bp-C5D4h]@11
  char v5700; // [sp+2A78h] [bp-C5BCh]@11
  char v5701; // [sp+2A90h] [bp-C5A4h]@11
  char v5702; // [sp+2AA8h] [bp-C58Ch]@11
  char v5703; // [sp+2AC0h] [bp-C574h]@11
  char v5704; // [sp+2AD8h] [bp-C55Ch]@11
  char v5705; // [sp+2AF0h] [bp-C544h]@11
  char v5706; // [sp+2B08h] [bp-C52Ch]@11
  char v5707; // [sp+2B20h] [bp-C514h]@11
  char v5708; // [sp+2B38h] [bp-C4FCh]@11
  char v5709; // [sp+2B50h] [bp-C4E4h]@11
  char v5710; // [sp+2B68h] [bp-C4CCh]@11
  char v5711; // [sp+2B80h] [bp-C4B4h]@11
  char v5712; // [sp+2B98h] [bp-C49Ch]@11
  char v5713; // [sp+2BB0h] [bp-C484h]@11
  char v5714; // [sp+2BC8h] [bp-C46Ch]@11
  char v5715; // [sp+2BE0h] [bp-C454h]@11
  char v5716; // [sp+2BF8h] [bp-C43Ch]@11
  char v5717; // [sp+2C10h] [bp-C424h]@11
  char v5718; // [sp+2C28h] [bp-C40Ch]@11
  char v5719; // [sp+2C40h] [bp-C3F4h]@11
  char v5720; // [sp+2C58h] [bp-C3DCh]@11
  char v5721; // [sp+2C70h] [bp-C3C4h]@11
  char v5722; // [sp+2C88h] [bp-C3ACh]@11
  char v5723; // [sp+2CA0h] [bp-C394h]@11
  char v5724; // [sp+2CB8h] [bp-C37Ch]@11
  char v5725; // [sp+2CD0h] [bp-C364h]@11
  char v5726; // [sp+2CE8h] [bp-C34Ch]@11
  char v5727; // [sp+2D00h] [bp-C334h]@11
  char v5728; // [sp+2D18h] [bp-C31Ch]@11
  char v5729; // [sp+2D30h] [bp-C304h]@11
  char v5730; // [sp+2D48h] [bp-C2ECh]@11
  char v5731; // [sp+2D60h] [bp-C2D4h]@11
  char v5732; // [sp+2D78h] [bp-C2BCh]@11
  char v5733; // [sp+2D90h] [bp-C2A4h]@11
  char v5734; // [sp+2DA8h] [bp-C28Ch]@11
  char v5735; // [sp+2DC0h] [bp-C274h]@11
  char v5736; // [sp+2DD8h] [bp-C25Ch]@11
  char v5737; // [sp+2DF0h] [bp-C244h]@11
  char v5738; // [sp+2E08h] [bp-C22Ch]@11
  char v5739; // [sp+2E20h] [bp-C214h]@11
  char v5740; // [sp+2E38h] [bp-C1FCh]@11
  char v5741; // [sp+2E50h] [bp-C1E4h]@11
  char v5742; // [sp+2E68h] [bp-C1CCh]@11
  char v5743; // [sp+2E80h] [bp-C1B4h]@11
  char v5744; // [sp+2E98h] [bp-C19Ch]@11
  char v5745; // [sp+2EB0h] [bp-C184h]@11
  char v5746; // [sp+2EC8h] [bp-C16Ch]@11
  char v5747; // [sp+2EE0h] [bp-C154h]@11
  char v5748; // [sp+2EF8h] [bp-C13Ch]@11
  char v5749; // [sp+2F10h] [bp-C124h]@11
  char v5750; // [sp+2F28h] [bp-C10Ch]@11
  char v5751; // [sp+2F40h] [bp-C0F4h]@11
  char v5752; // [sp+2F58h] [bp-C0DCh]@11
  char v5753; // [sp+2F70h] [bp-C0C4h]@11
  char v5754; // [sp+2F88h] [bp-C0ACh]@11
  char v5755; // [sp+2FA0h] [bp-C094h]@11
  char v5756; // [sp+2FB8h] [bp-C07Ch]@11
  char v5757; // [sp+2FD0h] [bp-C064h]@11
  char v5758; // [sp+2FE8h] [bp-C04Ch]@11
  char v5759; // [sp+3000h] [bp-C034h]@11
  char v5760; // [sp+3018h] [bp-C01Ch]@11
  char v5761; // [sp+3030h] [bp-C004h]@11
  char v5762; // [sp+3048h] [bp-BFECh]@11
  char v5763; // [sp+3060h] [bp-BFD4h]@11
  char v5764; // [sp+3078h] [bp-BFBCh]@11
  char v5765; // [sp+3090h] [bp-BFA4h]@11
  char v5766; // [sp+30A8h] [bp-BF8Ch]@11
  char v5767; // [sp+30C0h] [bp-BF74h]@11
  char v5768; // [sp+30D8h] [bp-BF5Ch]@11
  char v5769; // [sp+30F0h] [bp-BF44h]@11
  char v5770; // [sp+3108h] [bp-BF2Ch]@11
  char v5771; // [sp+3120h] [bp-BF14h]@11
  char v5772; // [sp+3138h] [bp-BEFCh]@11
  char v5773; // [sp+3150h] [bp-BEE4h]@11
  char v5774; // [sp+3168h] [bp-BECCh]@11
  char v5775; // [sp+3180h] [bp-BEB4h]@11
  char v5776; // [sp+3198h] [bp-BE9Ch]@11
  char v5777; // [sp+31B0h] [bp-BE84h]@11
  char v5778; // [sp+31C8h] [bp-BE6Ch]@11
  char v5779; // [sp+31E0h] [bp-BE54h]@11
  char v5780; // [sp+31F8h] [bp-BE3Ch]@11
  char v5781; // [sp+3210h] [bp-BE24h]@11
  char v5782; // [sp+3228h] [bp-BE0Ch]@11
  char v5783; // [sp+3240h] [bp-BDF4h]@11
  char v5784; // [sp+3258h] [bp-BDDCh]@11
  char v5785; // [sp+3270h] [bp-BDC4h]@11
  char v5786; // [sp+3288h] [bp-BDACh]@11
  char v5787; // [sp+32A0h] [bp-BD94h]@11
  char v5788; // [sp+32B8h] [bp-BD7Ch]@11
  char v5789; // [sp+32D0h] [bp-BD64h]@11
  char v5790; // [sp+32E8h] [bp-BD4Ch]@11
  char v5791; // [sp+3300h] [bp-BD34h]@11
  char v5792; // [sp+3318h] [bp-BD1Ch]@11
  char v5793; // [sp+3330h] [bp-BD04h]@11
  char v5794; // [sp+3348h] [bp-BCECh]@11
  char v5795; // [sp+3360h] [bp-BCD4h]@11
  char v5796; // [sp+3378h] [bp-BCBCh]@11
  char v5797; // [sp+3390h] [bp-BCA4h]@11
  char v5798; // [sp+33A8h] [bp-BC8Ch]@11
  char v5799; // [sp+33C0h] [bp-BC74h]@11
  char v5800; // [sp+33D8h] [bp-BC5Ch]@11
  char v5801; // [sp+33F0h] [bp-BC44h]@11
  char v5802; // [sp+3408h] [bp-BC2Ch]@11
  char v5803; // [sp+3420h] [bp-BC14h]@11
  char v5804; // [sp+3438h] [bp-BBFCh]@11
  char v5805; // [sp+3450h] [bp-BBE4h]@11
  char v5806; // [sp+3468h] [bp-BBCCh]@11
  char v5807; // [sp+3480h] [bp-BBB4h]@11
  char v5808; // [sp+3498h] [bp-BB9Ch]@11
  char v5809; // [sp+34B0h] [bp-BB84h]@11
  char v5810; // [sp+34C8h] [bp-BB6Ch]@11
  char v5811; // [sp+34E0h] [bp-BB54h]@11
  char v5812; // [sp+34F8h] [bp-BB3Ch]@11
  char v5813; // [sp+3510h] [bp-BB24h]@11
  char v5814; // [sp+3528h] [bp-BB0Ch]@11
  char v5815; // [sp+3540h] [bp-BAF4h]@11
  char v5816; // [sp+3558h] [bp-BADCh]@11
  char v5817; // [sp+3570h] [bp-BAC4h]@11
  char v5818; // [sp+3588h] [bp-BAACh]@11
  char v5819; // [sp+35A0h] [bp-BA94h]@11
  char v5820; // [sp+35B8h] [bp-BA7Ch]@11
  char v5821; // [sp+35D0h] [bp-BA64h]@11
  char v5822; // [sp+35E8h] [bp-BA4Ch]@11
  char v5823; // [sp+3600h] [bp-BA34h]@11
  char v5824; // [sp+3618h] [bp-BA1Ch]@11
  char v5825; // [sp+3630h] [bp-BA04h]@11
  char v5826; // [sp+3648h] [bp-B9ECh]@11
  char v5827; // [sp+3660h] [bp-B9D4h]@11
  char v5828; // [sp+3678h] [bp-B9BCh]@11
  char v5829; // [sp+3690h] [bp-B9A4h]@11
  char v5830; // [sp+36A8h] [bp-B98Ch]@11
  char v5831; // [sp+36C0h] [bp-B974h]@11
  char v5832; // [sp+36D8h] [bp-B95Ch]@11
  char v5833; // [sp+36F0h] [bp-B944h]@11
  char v5834; // [sp+3708h] [bp-B92Ch]@11
  char v5835; // [sp+3720h] [bp-B914h]@11
  char v5836; // [sp+3738h] [bp-B8FCh]@11
  char v5837; // [sp+3750h] [bp-B8E4h]@11
  char v5838; // [sp+3768h] [bp-B8CCh]@11
  char v5839; // [sp+3780h] [bp-B8B4h]@11
  char v5840; // [sp+3798h] [bp-B89Ch]@11
  char v5841; // [sp+37B0h] [bp-B884h]@11
  char v5842; // [sp+37C8h] [bp-B86Ch]@11
  char v5843; // [sp+37E0h] [bp-B854h]@11
  char v5844; // [sp+37F8h] [bp-B83Ch]@11
  char v5845; // [sp+3810h] [bp-B824h]@11
  char v5846; // [sp+3828h] [bp-B80Ch]@11
  char v5847; // [sp+3840h] [bp-B7F4h]@11
  char v5848; // [sp+3858h] [bp-B7DCh]@11
  char v5849; // [sp+3870h] [bp-B7C4h]@11
  char v5850; // [sp+3888h] [bp-B7ACh]@11
  char v5851; // [sp+38A0h] [bp-B794h]@11
  char v5852; // [sp+38B8h] [bp-B77Ch]@11
  char v5853; // [sp+38D0h] [bp-B764h]@11
  char v5854; // [sp+38E8h] [bp-B74Ch]@11
  char v5855; // [sp+3900h] [bp-B734h]@11
  char v5856; // [sp+3918h] [bp-B71Ch]@11
  char v5857; // [sp+3930h] [bp-B704h]@11
  char v5858; // [sp+3948h] [bp-B6ECh]@11
  char v5859; // [sp+3960h] [bp-B6D4h]@11
  char v5860; // [sp+3978h] [bp-B6BCh]@11
  char v5861; // [sp+3990h] [bp-B6A4h]@11
  char v5862; // [sp+39A8h] [bp-B68Ch]@11
  char v5863; // [sp+39C0h] [bp-B674h]@11
  char v5864; // [sp+39D8h] [bp-B65Ch]@11
  char v5865; // [sp+39F0h] [bp-B644h]@11
  char v5866; // [sp+3A08h] [bp-B62Ch]@11
  char v5867; // [sp+3A20h] [bp-B614h]@11
  char v5868; // [sp+3A38h] [bp-B5FCh]@11
  char v5869; // [sp+3A50h] [bp-B5E4h]@11
  char v5870; // [sp+3A68h] [bp-B5CCh]@11
  char v5871; // [sp+3A80h] [bp-B5B4h]@11
  char v5872; // [sp+3A98h] [bp-B59Ch]@11
  char v5873; // [sp+3AB0h] [bp-B584h]@11
  char v5874; // [sp+3AC8h] [bp-B56Ch]@11
  char v5875; // [sp+3AE0h] [bp-B554h]@11
  char v5876; // [sp+3AF8h] [bp-B53Ch]@11
  char v5877; // [sp+3B10h] [bp-B524h]@11
  char v5878; // [sp+3B28h] [bp-B50Ch]@11
  char v5879; // [sp+3B40h] [bp-B4F4h]@11
  char v5880; // [sp+3B58h] [bp-B4DCh]@11
  char v5881; // [sp+3B70h] [bp-B4C4h]@11
  char v5882; // [sp+3B88h] [bp-B4ACh]@11
  char v5883; // [sp+3BA0h] [bp-B494h]@11
  char v5884; // [sp+3BB8h] [bp-B47Ch]@11
  char v5885; // [sp+3BD0h] [bp-B464h]@11
  char v5886; // [sp+3BE8h] [bp-B44Ch]@11
  char v5887; // [sp+3C00h] [bp-B434h]@21
  char v5888; // [sp+3C18h] [bp-B41Ch]@11
  char v5889; // [sp+3C30h] [bp-B404h]@11
  char v5890; // [sp+3C48h] [bp-B3ECh]@11
  char v5891; // [sp+3C60h] [bp-B3D4h]@11
  char v5892; // [sp+3C78h] [bp-B3BCh]@11
  char v5893; // [sp+3C90h] [bp-B3A4h]@11
  char v5894; // [sp+3CA8h] [bp-B38Ch]@11
  char v5895; // [sp+3CC0h] [bp-B374h]@11
  char v5896; // [sp+3CD8h] [bp-B35Ch]@11
  char v5897; // [sp+3CF0h] [bp-B344h]@11
  char v5898; // [sp+3D08h] [bp-B32Ch]@11
  char v5899; // [sp+3D20h] [bp-B314h]@11
  char v5900; // [sp+3D38h] [bp-B2FCh]@11
  char v5901; // [sp+3D50h] [bp-B2E4h]@11
  char v5902; // [sp+3D68h] [bp-B2CCh]@11
  char v5903; // [sp+3D80h] [bp-B2B4h]@11
  char v5904; // [sp+3D98h] [bp-B29Ch]@11
  char v5905; // [sp+3DB0h] [bp-B284h]@11
  char v5906; // [sp+3DC8h] [bp-B26Ch]@11
  char v5907; // [sp+3DE0h] [bp-B254h]@11
  char v5908; // [sp+3DF8h] [bp-B23Ch]@11
  char v5909; // [sp+3E10h] [bp-B224h]@11
  char v5910; // [sp+3E28h] [bp-B20Ch]@11
  char v5911; // [sp+3E40h] [bp-B1F4h]@11
  char v5912; // [sp+3E58h] [bp-B1DCh]@11
  char v5913; // [sp+3E70h] [bp-B1C4h]@11
  char v5914; // [sp+3E88h] [bp-B1ACh]@11
  char v5915; // [sp+3EA0h] [bp-B194h]@11
  char v5916; // [sp+3EB8h] [bp-B17Ch]@11
  char v5917; // [sp+3ED0h] [bp-B164h]@11
  char v5918; // [sp+3EE8h] [bp-B14Ch]@11
  char v5919; // [sp+3F00h] [bp-B134h]@11
  char v5920; // [sp+3F18h] [bp-B11Ch]@11
  char v5921; // [sp+3F30h] [bp-B104h]@11
  char v5922; // [sp+3F48h] [bp-B0ECh]@11
  char v5923; // [sp+3F60h] [bp-B0D4h]@11
  char v5924; // [sp+3F78h] [bp-B0BCh]@11
  char v5925; // [sp+3F90h] [bp-B0A4h]@11
  char v5926; // [sp+3FA8h] [bp-B08Ch]@11
  char v5927; // [sp+3FC0h] [bp-B074h]@11
  char v5928; // [sp+3FD8h] [bp-B05Ch]@11
  char v5929; // [sp+3FF0h] [bp-B044h]@11
  char v5930; // [sp+4008h] [bp-B02Ch]@11
  char v5931; // [sp+4020h] [bp-B014h]@11
  char v5932; // [sp+4038h] [bp-AFFCh]@11
  char v5933; // [sp+4050h] [bp-AFE4h]@11
  char v5934; // [sp+4068h] [bp-AFCCh]@11
  char v5935; // [sp+4080h] [bp-AFB4h]@11
  char v5936; // [sp+4098h] [bp-AF9Ch]@11
  char v5937; // [sp+40B0h] [bp-AF84h]@11
  char v5938; // [sp+40C8h] [bp-AF6Ch]@11
  char v5939; // [sp+40E0h] [bp-AF54h]@11
  char v5940; // [sp+40F8h] [bp-AF3Ch]@11
  char v5941; // [sp+4110h] [bp-AF24h]@11
  char v5942; // [sp+4128h] [bp-AF0Ch]@11
  char v5943; // [sp+4140h] [bp-AEF4h]@11
  char v5944; // [sp+4158h] [bp-AEDCh]@11
  char v5945; // [sp+4170h] [bp-AEC4h]@11
  char v5946; // [sp+4188h] [bp-AEACh]@11
  char v5947; // [sp+41A0h] [bp-AE94h]@11
  char v5948; // [sp+41B8h] [bp-AE7Ch]@11
  char v5949; // [sp+41D0h] [bp-AE64h]@11
  char v5950; // [sp+41E8h] [bp-AE4Ch]@11
  char v5951; // [sp+4200h] [bp-AE34h]@11
  char v5952; // [sp+4218h] [bp-AE1Ch]@11
  char v5953; // [sp+4230h] [bp-AE04h]@11
  char v5954; // [sp+4248h] [bp-ADECh]@11
  char v5955; // [sp+4260h] [bp-ADD4h]@11
  char v5956; // [sp+4278h] [bp-ADBCh]@11
  char v5957; // [sp+4290h] [bp-ADA4h]@11
  char v5958; // [sp+42A8h] [bp-AD8Ch]@11
  char v5959; // [sp+42C0h] [bp-AD74h]@11
  char v5960; // [sp+42D8h] [bp-AD5Ch]@11
  char v5961; // [sp+42F0h] [bp-AD44h]@11
  char v5962; // [sp+4308h] [bp-AD2Ch]@11
  char v5963; // [sp+4320h] [bp-AD14h]@11
  char v5964; // [sp+4338h] [bp-ACFCh]@11
  char v5965; // [sp+4350h] [bp-ACE4h]@11
  char v5966; // [sp+4368h] [bp-ACCCh]@11
  char v5967; // [sp+4380h] [bp-ACB4h]@11
  char v5968; // [sp+4398h] [bp-AC9Ch]@11
  char v5969; // [sp+43B0h] [bp-AC84h]@11
  char v5970; // [sp+43C8h] [bp-AC6Ch]@11
  char v5971; // [sp+43E0h] [bp-AC54h]@11
  char v5972; // [sp+43F8h] [bp-AC3Ch]@11
  char v5973; // [sp+4410h] [bp-AC24h]@11
  char v5974; // [sp+4428h] [bp-AC0Ch]@11
  char v5975; // [sp+4440h] [bp-ABF4h]@11
  char v5976; // [sp+4458h] [bp-ABDCh]@11
  char v5977; // [sp+4470h] [bp-ABC4h]@11
  char v5978; // [sp+4488h] [bp-ABACh]@11
  char v5979; // [sp+44A0h] [bp-AB94h]@11
  char v5980; // [sp+44B8h] [bp-AB7Ch]@11
  char v5981; // [sp+44D0h] [bp-AB64h]@11
  char v5982; // [sp+44E8h] [bp-AB4Ch]@11
  char v5983; // [sp+4500h] [bp-AB34h]@11
  char v5984; // [sp+4518h] [bp-AB1Ch]@11
  char v5985; // [sp+4530h] [bp-AB04h]@11
  char v5986; // [sp+4548h] [bp-AAECh]@11
  char v5987; // [sp+4560h] [bp-AAD4h]@11
  char v5988; // [sp+4578h] [bp-AABCh]@11
  char v5989; // [sp+4590h] [bp-AAA4h]@11
  char v5990; // [sp+45A8h] [bp-AA8Ch]@11
  char v5991; // [sp+45C0h] [bp-AA74h]@11
  char v5992; // [sp+45D8h] [bp-AA5Ch]@11
  char v5993; // [sp+45F0h] [bp-AA44h]@11
  char v5994; // [sp+4608h] [bp-AA2Ch]@11
  char v5995; // [sp+4620h] [bp-AA14h]@11
  char v5996; // [sp+4638h] [bp-A9FCh]@11
  char v5997; // [sp+4650h] [bp-A9E4h]@11
  char v5998; // [sp+4668h] [bp-A9CCh]@11
  char v5999; // [sp+4680h] [bp-A9B4h]@11
  char v6000; // [sp+4698h] [bp-A99Ch]@11
  char v6001; // [sp+46B0h] [bp-A984h]@11
  char v6002; // [sp+46C8h] [bp-A96Ch]@11
  char v6003; // [sp+46E0h] [bp-A954h]@11
  char v6004; // [sp+46F8h] [bp-A93Ch]@11
  char v6005; // [sp+4710h] [bp-A924h]@11
  char v6006; // [sp+4728h] [bp-A90Ch]@11
  char v6007; // [sp+4740h] [bp-A8F4h]@11
  char v6008; // [sp+4758h] [bp-A8DCh]@11
  char v6009; // [sp+4770h] [bp-A8C4h]@11
  char v6010; // [sp+4788h] [bp-A8ACh]@11
  char v6011; // [sp+47A0h] [bp-A894h]@11
  char v6012; // [sp+47B8h] [bp-A87Ch]@11
  char v6013; // [sp+47D0h] [bp-A864h]@11
  char v6014; // [sp+47E8h] [bp-A84Ch]@11
  char v6015; // [sp+4800h] [bp-A834h]@11
  char v6016; // [sp+4818h] [bp-A81Ch]@11
  char v6017; // [sp+4830h] [bp-A804h]@11
  char v6018; // [sp+4848h] [bp-A7ECh]@11
  char v6019; // [sp+4860h] [bp-A7D4h]@11
  char v6020; // [sp+4878h] [bp-A7BCh]@11
  char v6021; // [sp+4890h] [bp-A7A4h]@11
  char v6022; // [sp+48A8h] [bp-A78Ch]@11
  char v6023; // [sp+48C0h] [bp-A774h]@11
  char v6024; // [sp+48D8h] [bp-A75Ch]@11
  char v6025; // [sp+48F0h] [bp-A744h]@11
  char v6026; // [sp+4908h] [bp-A72Ch]@11
  char v6027; // [sp+4920h] [bp-A714h]@11
  char v6028; // [sp+4938h] [bp-A6FCh]@11
  char v6029; // [sp+4950h] [bp-A6E4h]@11
  char v6030; // [sp+4968h] [bp-A6CCh]@11
  char v6031; // [sp+4980h] [bp-A6B4h]@11
  char v6032; // [sp+4998h] [bp-A69Ch]@11
  char v6033; // [sp+49B0h] [bp-A684h]@11
  char v6034; // [sp+49C8h] [bp-A66Ch]@11
  char v6035; // [sp+49E0h] [bp-A654h]@11
  char v6036; // [sp+49F8h] [bp-A63Ch]@11
  char v6037; // [sp+4A10h] [bp-A624h]@11
  char v6038; // [sp+4A28h] [bp-A60Ch]@11
  char v6039; // [sp+4A40h] [bp-A5F4h]@11
  char v6040; // [sp+4A58h] [bp-A5DCh]@11
  char v6041; // [sp+4A70h] [bp-A5C4h]@11
  char v6042; // [sp+4A88h] [bp-A5ACh]@11
  char v6043; // [sp+4AA0h] [bp-A594h]@11
  char v6044; // [sp+4AB8h] [bp-A57Ch]@11
  char v6045; // [sp+4AD0h] [bp-A564h]@11
  char v6046; // [sp+4AE8h] [bp-A54Ch]@11
  char v6047; // [sp+4B00h] [bp-A534h]@11
  char v6048; // [sp+4B18h] [bp-A51Ch]@11
  char v6049; // [sp+4B30h] [bp-A504h]@11
  char v6050; // [sp+4B48h] [bp-A4ECh]@11
  char v6051; // [sp+4B60h] [bp-A4D4h]@11
  char v6052; // [sp+4B78h] [bp-A4BCh]@11
  char v6053; // [sp+4B90h] [bp-A4A4h]@11
  char v6054; // [sp+4BA8h] [bp-A48Ch]@11
  char v6055; // [sp+4BC0h] [bp-A474h]@11
  char v6056; // [sp+4BD8h] [bp-A45Ch]@11
  char v6057; // [sp+4BF0h] [bp-A444h]@11
  char v6058; // [sp+4C08h] [bp-A42Ch]@11
  char v6059; // [sp+4C20h] [bp-A414h]@11
  char v6060; // [sp+4C38h] [bp-A3FCh]@11
  char v6061; // [sp+4C50h] [bp-A3E4h]@11
  char v6062; // [sp+4C68h] [bp-A3CCh]@11
  char v6063; // [sp+4C80h] [bp-A3B4h]@11
  char v6064; // [sp+4C98h] [bp-A39Ch]@11
  char v6065; // [sp+4CB0h] [bp-A384h]@11
  char v6066; // [sp+4CC8h] [bp-A36Ch]@11
  char v6067; // [sp+4CE0h] [bp-A354h]@11
  char v6068; // [sp+4CF8h] [bp-A33Ch]@11
  char v6069; // [sp+4D10h] [bp-A324h]@11
  char v6070; // [sp+4D28h] [bp-A30Ch]@11
  char v6071; // [sp+4D40h] [bp-A2F4h]@11
  char v6072; // [sp+4D58h] [bp-A2DCh]@11
  char v6073; // [sp+4D70h] [bp-A2C4h]@11
  char v6074; // [sp+4D88h] [bp-A2ACh]@11
  char v6075; // [sp+4DA0h] [bp-A294h]@11
  char v6076; // [sp+4DB8h] [bp-A27Ch]@11
  char v6077; // [sp+4DD0h] [bp-A264h]@11
  char v6078; // [sp+4DE8h] [bp-A24Ch]@11
  char v6079; // [sp+4E00h] [bp-A234h]@11
  char v6080; // [sp+4E18h] [bp-A21Ch]@11
  char v6081; // [sp+4E30h] [bp-A204h]@11
  char v6082; // [sp+4E48h] [bp-A1ECh]@11
  char v6083; // [sp+4E60h] [bp-A1D4h]@11
  char v6084; // [sp+4E78h] [bp-A1BCh]@11
  char v6085; // [sp+4E90h] [bp-A1A4h]@11
  char v6086; // [sp+4EA8h] [bp-A18Ch]@11
  char v6087; // [sp+4EC0h] [bp-A174h]@11
  char v6088; // [sp+4ED8h] [bp-A15Ch]@11
  char v6089; // [sp+4EF0h] [bp-A144h]@11
  char v6090; // [sp+4F08h] [bp-A12Ch]@11
  char v6091; // [sp+4F20h] [bp-A114h]@11
  char v6092; // [sp+4F38h] [bp-A0FCh]@11
  char v6093; // [sp+4F50h] [bp-A0E4h]@11
  char v6094; // [sp+4F68h] [bp-A0CCh]@11
  char v6095; // [sp+4F80h] [bp-A0B4h]@11
  char v6096; // [sp+4F98h] [bp-A09Ch]@11
  char v6097; // [sp+4FB0h] [bp-A084h]@11
  char v6098; // [sp+4FC8h] [bp-A06Ch]@11
  char v6099; // [sp+4FE0h] [bp-A054h]@11
  char v6100; // [sp+4FF8h] [bp-A03Ch]@11
  char v6101; // [sp+5010h] [bp-A024h]@11
  char v6102; // [sp+5028h] [bp-A00Ch]@11
  char v6103; // [sp+5040h] [bp-9FF4h]@11
  char v6104; // [sp+5058h] [bp-9FDCh]@11
  char v6105; // [sp+5070h] [bp-9FC4h]@11
  char v6106; // [sp+5088h] [bp-9FACh]@11
  char v6107; // [sp+50A0h] [bp-9F94h]@11
  char v6108; // [sp+50B8h] [bp-9F7Ch]@11
  char v6109; // [sp+50D0h] [bp-9F64h]@11
  char v6110; // [sp+50E8h] [bp-9F4Ch]@11
  char v6111; // [sp+5100h] [bp-9F34h]@11
  char v6112; // [sp+5118h] [bp-9F1Ch]@11
  char v6113; // [sp+5130h] [bp-9F04h]@11
  char v6114; // [sp+5148h] [bp-9EECh]@11
  char v6115; // [sp+5160h] [bp-9ED4h]@11
  char v6116; // [sp+5178h] [bp-9EBCh]@11
  char v6117; // [sp+5190h] [bp-9EA4h]@11
  char v6118; // [sp+51A8h] [bp-9E8Ch]@11
  char v6119; // [sp+51C0h] [bp-9E74h]@11
  char v6120; // [sp+51D8h] [bp-9E5Ch]@11
  char v6121; // [sp+51F0h] [bp-9E44h]@11
  char v6122; // [sp+5208h] [bp-9E2Ch]@11
  char v6123; // [sp+5220h] [bp-9E14h]@11
  char v6124; // [sp+5238h] [bp-9DFCh]@11
  char v6125; // [sp+5250h] [bp-9DE4h]@11
  char v6126; // [sp+5268h] [bp-9DCCh]@11
  char v6127; // [sp+5280h] [bp-9DB4h]@11
  char v6128; // [sp+5298h] [bp-9D9Ch]@11
  char v6129; // [sp+52B0h] [bp-9D84h]@11
  char v6130; // [sp+52C8h] [bp-9D6Ch]@11
  char v6131; // [sp+52E0h] [bp-9D54h]@11
  char v6132; // [sp+52F8h] [bp-9D3Ch]@11
  char v6133; // [sp+5310h] [bp-9D24h]@11
  char v6134; // [sp+5328h] [bp-9D0Ch]@11
  char v6135; // [sp+5340h] [bp-9CF4h]@11
  char v6136; // [sp+5358h] [bp-9CDCh]@11
  char v6137; // [sp+5370h] [bp-9CC4h]@11
  char v6138; // [sp+5388h] [bp-9CACh]@11
  char v6139; // [sp+53A0h] [bp-9C94h]@11
  char v6140; // [sp+53B8h] [bp-9C7Ch]@11
  char v6141; // [sp+53D0h] [bp-9C64h]@11
  char v6142; // [sp+53E8h] [bp-9C4Ch]@11
  char v6143; // [sp+5400h] [bp-9C34h]@11
  char v6144; // [sp+5418h] [bp-9C1Ch]@11
  char v6145; // [sp+5430h] [bp-9C04h]@11
  char v6146; // [sp+5448h] [bp-9BECh]@11
  char v6147; // [sp+5460h] [bp-9BD4h]@11
  char v6148; // [sp+5478h] [bp-9BBCh]@11
  char v6149; // [sp+5490h] [bp-9BA4h]@11
  char v6150; // [sp+54A8h] [bp-9B8Ch]@11
  char v6151; // [sp+54C0h] [bp-9B74h]@11
  char v6152; // [sp+54D8h] [bp-9B5Ch]@11
  char v6153; // [sp+54F0h] [bp-9B44h]@11
  char v6154; // [sp+5508h] [bp-9B2Ch]@11
  char v6155; // [sp+5520h] [bp-9B14h]@11
  char v6156; // [sp+5538h] [bp-9AFCh]@11
  char v6157; // [sp+5550h] [bp-9AE4h]@11
  char v6158; // [sp+5568h] [bp-9ACCh]@11
  char v6159; // [sp+5580h] [bp-9AB4h]@11
  char v6160; // [sp+5598h] [bp-9A9Ch]@11
  char v6161; // [sp+55B0h] [bp-9A84h]@11
  char v6162; // [sp+55C8h] [bp-9A6Ch]@11
  char v6163; // [sp+55E0h] [bp-9A54h]@11
  char v6164; // [sp+55F8h] [bp-9A3Ch]@11
  char v6165; // [sp+5610h] [bp-9A24h]@11
  char v6166; // [sp+5628h] [bp-9A0Ch]@11
  char v6167; // [sp+5640h] [bp-99F4h]@11
  char v6168; // [sp+5658h] [bp-99DCh]@11
  char v6169; // [sp+5670h] [bp-99C4h]@11
  char v6170; // [sp+5688h] [bp-99ACh]@11
  char v6171; // [sp+56A0h] [bp-9994h]@11
  char v6172; // [sp+56B8h] [bp-997Ch]@11
  char v6173; // [sp+56D0h] [bp-9964h]@11
  char v6174; // [sp+56E8h] [bp-994Ch]@11
  char v6175; // [sp+5700h] [bp-9934h]@11
  char v6176; // [sp+5718h] [bp-991Ch]@11
  char v6177; // [sp+5730h] [bp-9904h]@11
  char v6178; // [sp+5748h] [bp-98ECh]@11
  char v6179; // [sp+5760h] [bp-98D4h]@11
  char v6180; // [sp+5778h] [bp-98BCh]@11
  char v6181; // [sp+5790h] [bp-98A4h]@11
  char v6182; // [sp+57A8h] [bp-988Ch]@11
  char v6183; // [sp+57C0h] [bp-9874h]@11
  char v6184; // [sp+57D8h] [bp-985Ch]@11
  char v6185; // [sp+57F0h] [bp-9844h]@11
  char v6186; // [sp+5808h] [bp-982Ch]@11
  char v6187; // [sp+5820h] [bp-9814h]@11
  char v6188; // [sp+5838h] [bp-97FCh]@11
  char v6189; // [sp+5850h] [bp-97E4h]@11
  char v6190; // [sp+5868h] [bp-97CCh]@11
  char v6191; // [sp+5880h] [bp-97B4h]@11
  char v6192; // [sp+5898h] [bp-979Ch]@11
  char v6193; // [sp+58B0h] [bp-9784h]@11
  char v6194; // [sp+58C8h] [bp-976Ch]@11
  char v6195; // [sp+58E0h] [bp-9754h]@11
  char v6196; // [sp+58F8h] [bp-973Ch]@11
  char v6197; // [sp+5910h] [bp-9724h]@11
  char v6198; // [sp+5928h] [bp-970Ch]@11
  char v6199; // [sp+5940h] [bp-96F4h]@11
  char v6200; // [sp+5958h] [bp-96DCh]@11
  char v6201; // [sp+5970h] [bp-96C4h]@11
  char v6202; // [sp+5988h] [bp-96ACh]@11
  char v6203; // [sp+59A0h] [bp-9694h]@11
  char v6204; // [sp+59B8h] [bp-967Ch]@11
  char v6205; // [sp+59D0h] [bp-9664h]@11
  char v6206; // [sp+59E8h] [bp-964Ch]@11
  char v6207; // [sp+5A00h] [bp-9634h]@11
  char v6208; // [sp+5A18h] [bp-961Ch]@11
  char v6209; // [sp+5A30h] [bp-9604h]@11
  char v6210; // [sp+5A48h] [bp-95ECh]@11
  char v6211; // [sp+5A60h] [bp-95D4h]@11
  char v6212; // [sp+5A78h] [bp-95BCh]@11
  char v6213; // [sp+5A90h] [bp-95A4h]@11
  char v6214; // [sp+5AA8h] [bp-958Ch]@11
  char v6215; // [sp+5AC0h] [bp-9574h]@11
  char v6216; // [sp+5AD8h] [bp-955Ch]@11
  char v6217; // [sp+5AF0h] [bp-9544h]@11
  char v6218; // [sp+5B08h] [bp-952Ch]@11
  char v6219; // [sp+5B20h] [bp-9514h]@11
  char v6220; // [sp+5B38h] [bp-94FCh]@11
  char v6221; // [sp+5B50h] [bp-94E4h]@11
  char v6222; // [sp+5B68h] [bp-94CCh]@11
  char v6223; // [sp+5B80h] [bp-94B4h]@11
  char v6224; // [sp+5B98h] [bp-949Ch]@11
  char v6225; // [sp+5BB0h] [bp-9484h]@11
  char v6226; // [sp+5BC8h] [bp-946Ch]@11
  char v6227; // [sp+5BE0h] [bp-9454h]@11
  char v6228; // [sp+5BF8h] [bp-943Ch]@11
  char v6229; // [sp+5C10h] [bp-9424h]@11
  char v6230; // [sp+5C28h] [bp-940Ch]@11
  char v6231; // [sp+5C40h] [bp-93F4h]@11
  char v6232; // [sp+5C58h] [bp-93DCh]@11
  char v6233; // [sp+5C70h] [bp-93C4h]@11
  char v6234; // [sp+5C88h] [bp-93ACh]@11
  char v6235; // [sp+5CA0h] [bp-9394h]@11
  char v6236; // [sp+5CB8h] [bp-937Ch]@11
  char v6237; // [sp+5CD0h] [bp-9364h]@11
  char v6238; // [sp+5CE8h] [bp-934Ch]@11
  char v6239; // [sp+5D00h] [bp-9334h]@11
  char v6240; // [sp+5D18h] [bp-931Ch]@11
  char v6241; // [sp+5D30h] [bp-9304h]@11
  char v6242; // [sp+5D48h] [bp-92ECh]@11
  char v6243; // [sp+5D60h] [bp-92D4h]@11
  char v6244; // [sp+5D78h] [bp-92BCh]@11
  char v6245; // [sp+5D90h] [bp-92A4h]@11
  char v6246; // [sp+5DA8h] [bp-928Ch]@11
  char v6247; // [sp+5DC0h] [bp-9274h]@11
  char v6248; // [sp+5DD8h] [bp-925Ch]@11
  char v6249; // [sp+5DF0h] [bp-9244h]@11
  char v6250; // [sp+5E08h] [bp-922Ch]@11
  char v6251; // [sp+5E20h] [bp-9214h]@11
  char v6252; // [sp+5E38h] [bp-91FCh]@11
  char v6253; // [sp+5E50h] [bp-91E4h]@11
  char v6254; // [sp+5E68h] [bp-91CCh]@11
  char v6255; // [sp+5E80h] [bp-91B4h]@11
  char v6256; // [sp+5E98h] [bp-919Ch]@11
  char v6257; // [sp+5EB0h] [bp-9184h]@11
  char v6258; // [sp+5EC8h] [bp-916Ch]@11
  char v6259; // [sp+5EE0h] [bp-9154h]@11
  char v6260; // [sp+5EF8h] [bp-913Ch]@11
  char v6261; // [sp+5F10h] [bp-9124h]@11
  char v6262; // [sp+5F28h] [bp-910Ch]@11
  char v6263; // [sp+5F40h] [bp-90F4h]@11
  char v6264; // [sp+5F58h] [bp-90DCh]@11
  char v6265; // [sp+5F70h] [bp-90C4h]@11
  char v6266; // [sp+5F88h] [bp-90ACh]@11
  char v6267; // [sp+5FA0h] [bp-9094h]@11
  char v6268; // [sp+5FB8h] [bp-907Ch]@11
  char v6269; // [sp+5FD0h] [bp-9064h]@11
  char v6270; // [sp+5FE8h] [bp-904Ch]@11
  char v6271; // [sp+6000h] [bp-9034h]@11
  char v6272; // [sp+6018h] [bp-901Ch]@11
  char v6273; // [sp+6030h] [bp-9004h]@11
  char v6274; // [sp+6048h] [bp-8FECh]@11
  char v6275; // [sp+6060h] [bp-8FD4h]@11
  char v6276; // [sp+6078h] [bp-8FBCh]@11
  char v6277; // [sp+6090h] [bp-8FA4h]@11
  char v6278; // [sp+60A8h] [bp-8F8Ch]@11
  char v6279; // [sp+60C0h] [bp-8F74h]@11
  char v6280; // [sp+60D8h] [bp-8F5Ch]@11
  char v6281; // [sp+60F0h] [bp-8F44h]@11
  char v6282; // [sp+6108h] [bp-8F2Ch]@11
  char v6283; // [sp+6120h] [bp-8F14h]@11
  char v6284; // [sp+6138h] [bp-8EFCh]@11
  char v6285; // [sp+6150h] [bp-8EE4h]@11
  char v6286; // [sp+6168h] [bp-8ECCh]@11
  char v6287; // [sp+6180h] [bp-8EB4h]@11
  char v6288; // [sp+6198h] [bp-8E9Ch]@11
  char v6289; // [sp+61B0h] [bp-8E84h]@11
  char v6290; // [sp+61C8h] [bp-8E6Ch]@11
  char v6291; // [sp+61E0h] [bp-8E54h]@11
  char v6292; // [sp+61F8h] [bp-8E3Ch]@11
  char v6293; // [sp+6210h] [bp-8E24h]@11
  char v6294; // [sp+6228h] [bp-8E0Ch]@11
  char v6295; // [sp+6240h] [bp-8DF4h]@11
  char v6296; // [sp+6258h] [bp-8DDCh]@11
  char v6297; // [sp+6270h] [bp-8DC4h]@11
  char v6298; // [sp+6288h] [bp-8DACh]@11
  char v6299; // [sp+62A0h] [bp-8D94h]@11
  char v6300; // [sp+62B8h] [bp-8D7Ch]@11
  char v6301; // [sp+62D0h] [bp-8D64h]@11
  char v6302; // [sp+62E8h] [bp-8D4Ch]@11
  char v6303; // [sp+6300h] [bp-8D34h]@11
  char v6304; // [sp+6318h] [bp-8D1Ch]@11
  char v6305; // [sp+6330h] [bp-8D04h]@11
  char v6306; // [sp+6348h] [bp-8CECh]@11
  char v6307; // [sp+6360h] [bp-8CD4h]@11
  char v6308; // [sp+6378h] [bp-8CBCh]@11
  char v6309; // [sp+6390h] [bp-8CA4h]@11
  char v6310; // [sp+63A8h] [bp-8C8Ch]@11
  char v6311; // [sp+63C0h] [bp-8C74h]@11
  char v6312; // [sp+63D8h] [bp-8C5Ch]@11
  char v6313; // [sp+63F0h] [bp-8C44h]@11
  char v6314; // [sp+6408h] [bp-8C2Ch]@11
  char v6315; // [sp+6420h] [bp-8C14h]@11
  char v6316; // [sp+6438h] [bp-8BFCh]@11
  char v6317; // [sp+6450h] [bp-8BE4h]@11
  char v6318; // [sp+6468h] [bp-8BCCh]@11
  char v6319; // [sp+6480h] [bp-8BB4h]@11
  char v6320; // [sp+6498h] [bp-8B9Ch]@11
  char v6321; // [sp+64B0h] [bp-8B84h]@11
  char v6322; // [sp+64C8h] [bp-8B6Ch]@11
  char v6323; // [sp+64E0h] [bp-8B54h]@11
  char v6324; // [sp+64F8h] [bp-8B3Ch]@11
  char v6325; // [sp+6510h] [bp-8B24h]@11
  char v6326; // [sp+6528h] [bp-8B0Ch]@11
  char v6327; // [sp+6540h] [bp-8AF4h]@11
  char v6328; // [sp+6558h] [bp-8ADCh]@11
  char v6329; // [sp+6570h] [bp-8AC4h]@11
  char v6330; // [sp+6588h] [bp-8AACh]@11
  char v6331; // [sp+65A0h] [bp-8A94h]@11
  char v6332; // [sp+65B8h] [bp-8A7Ch]@11
  char v6333; // [sp+65D0h] [bp-8A64h]@11
  char v6334; // [sp+65E8h] [bp-8A4Ch]@11
  char v6335; // [sp+6600h] [bp-8A34h]@11
  char v6336; // [sp+6618h] [bp-8A1Ch]@11
  char v6337; // [sp+6630h] [bp-8A04h]@11
  char v6338; // [sp+6648h] [bp-89ECh]@11
  char v6339; // [sp+6660h] [bp-89D4h]@11
  char v6340; // [sp+6678h] [bp-89BCh]@11
  char v6341; // [sp+6690h] [bp-89A4h]@11
  char v6342; // [sp+66A8h] [bp-898Ch]@11
  char v6343; // [sp+66C0h] [bp-8974h]@11
  char v6344; // [sp+66D8h] [bp-895Ch]@11
  char v6345; // [sp+66F0h] [bp-8944h]@11
  char v6346; // [sp+6708h] [bp-892Ch]@11
  char v6347; // [sp+6720h] [bp-8914h]@11
  char v6348; // [sp+6738h] [bp-88FCh]@11
  char v6349; // [sp+6750h] [bp-88E4h]@11
  char v6350; // [sp+6768h] [bp-88CCh]@11
  char v6351; // [sp+6780h] [bp-88B4h]@11
  char v6352; // [sp+6798h] [bp-889Ch]@11
  char v6353; // [sp+67B0h] [bp-8884h]@11
  char v6354; // [sp+67C8h] [bp-886Ch]@11
  char v6355; // [sp+67E0h] [bp-8854h]@11
  char v6356; // [sp+67F8h] [bp-883Ch]@11
  char v6357; // [sp+6810h] [bp-8824h]@11
  char v6358; // [sp+6828h] [bp-880Ch]@11
  char v6359; // [sp+6840h] [bp-87F4h]@11
  char v6360; // [sp+6858h] [bp-87DCh]@11
  char v6361; // [sp+6870h] [bp-87C4h]@11
  char v6362; // [sp+6888h] [bp-87ACh]@11
  char v6363; // [sp+68A0h] [bp-8794h]@11
  char v6364; // [sp+68B8h] [bp-877Ch]@11
  char v6365; // [sp+68D0h] [bp-8764h]@11
  char v6366; // [sp+68E8h] [bp-874Ch]@11
  char v6367; // [sp+6900h] [bp-8734h]@11
  char v6368; // [sp+6918h] [bp-871Ch]@11
  char v6369; // [sp+6930h] [bp-8704h]@11
  char v6370; // [sp+6948h] [bp-86ECh]@11
  char v6371; // [sp+6960h] [bp-86D4h]@11
  char v6372; // [sp+6978h] [bp-86BCh]@11
  char v6373; // [sp+6990h] [bp-86A4h]@11
  char v6374; // [sp+69A8h] [bp-868Ch]@11
  char v6375; // [sp+69C0h] [bp-8674h]@11
  char v6376; // [sp+69D8h] [bp-865Ch]@11
  char v6377; // [sp+69F0h] [bp-8644h]@11
  char v6378; // [sp+6A08h] [bp-862Ch]@11
  char v6379; // [sp+6A20h] [bp-8614h]@11
  char v6380; // [sp+6A38h] [bp-85FCh]@11
  char v6381; // [sp+6A50h] [bp-85E4h]@11
  char v6382; // [sp+6A68h] [bp-85CCh]@11
  char v6383; // [sp+6A80h] [bp-85B4h]@11
  char v6384; // [sp+6A98h] [bp-859Ch]@11
  char v6385; // [sp+6AB0h] [bp-8584h]@11
  char v6386; // [sp+6AC8h] [bp-856Ch]@11
  char v6387; // [sp+6AE0h] [bp-8554h]@11
  char v6388; // [sp+6AF8h] [bp-853Ch]@11
  char v6389; // [sp+6B10h] [bp-8524h]@11
  char v6390; // [sp+6B28h] [bp-850Ch]@11
  char v6391; // [sp+6B40h] [bp-84F4h]@11
  char v6392; // [sp+6B58h] [bp-84DCh]@11
  char v6393; // [sp+6B70h] [bp-84C4h]@11
  char v6394; // [sp+6B88h] [bp-84ACh]@11
  char v6395; // [sp+6BA0h] [bp-8494h]@11
  char v6396; // [sp+6BB8h] [bp-847Ch]@11
  char v6397; // [sp+6BD0h] [bp-8464h]@11
  char v6398; // [sp+6BE8h] [bp-844Ch]@11
  char v6399; // [sp+6C00h] [bp-8434h]@11
  char v6400; // [sp+6C18h] [bp-841Ch]@11
  char v6401; // [sp+6C30h] [bp-8404h]@11
  char v6402; // [sp+6C48h] [bp-83ECh]@11
  char v6403; // [sp+6C60h] [bp-83D4h]@11
  char v6404; // [sp+6C78h] [bp-83BCh]@11
  char v6405; // [sp+6C90h] [bp-83A4h]@11
  char v6406; // [sp+6CA8h] [bp-838Ch]@11
  char v6407; // [sp+6CC0h] [bp-8374h]@11
  char v6408; // [sp+6CD8h] [bp-835Ch]@11
  char v6409; // [sp+6CF0h] [bp-8344h]@11
  char v6410; // [sp+6D08h] [bp-832Ch]@11
  char v6411; // [sp+6D20h] [bp-8314h]@11
  char v6412; // [sp+6D38h] [bp-82FCh]@11
  char v6413; // [sp+6D50h] [bp-82E4h]@11
  char v6414; // [sp+6D68h] [bp-82CCh]@11
  char v6415; // [sp+6D80h] [bp-82B4h]@11
  char v6416; // [sp+6D98h] [bp-829Ch]@11
  char v6417; // [sp+6DB0h] [bp-8284h]@11
  char v6418; // [sp+6DC8h] [bp-826Ch]@11
  char v6419; // [sp+6DE0h] [bp-8254h]@11
  char v6420; // [sp+6DF8h] [bp-823Ch]@11
  char v6421; // [sp+6E10h] [bp-8224h]@11
  char v6422; // [sp+6E28h] [bp-820Ch]@11
  char v6423; // [sp+6E40h] [bp-81F4h]@11
  char v6424; // [sp+6E58h] [bp-81DCh]@11
  char v6425; // [sp+6E70h] [bp-81C4h]@11
  char v6426; // [sp+6E88h] [bp-81ACh]@11
  char v6427; // [sp+6EA0h] [bp-8194h]@11
  char v6428; // [sp+6EB8h] [bp-817Ch]@11
  char v6429; // [sp+6ED0h] [bp-8164h]@11
  char v6430; // [sp+6EE8h] [bp-814Ch]@11
  char v6431; // [sp+6F00h] [bp-8134h]@11
  char v6432; // [sp+6F18h] [bp-811Ch]@11
  char v6433; // [sp+6F30h] [bp-8104h]@11
  char v6434; // [sp+6F48h] [bp-80ECh]@11
  char v6435; // [sp+6F60h] [bp-80D4h]@11
  char v6436; // [sp+6F78h] [bp-80BCh]@11
  char v6437; // [sp+6F90h] [bp-80A4h]@11
  char v6438; // [sp+6FA8h] [bp-808Ch]@11
  char v6439; // [sp+6FC0h] [bp-8074h]@11
  char v6440; // [sp+6FD8h] [bp-805Ch]@11
  char v6441; // [sp+6FF0h] [bp-8044h]@11
  char v6442; // [sp+7008h] [bp-802Ch]@11
  char v6443; // [sp+7020h] [bp-8014h]@11
  char v6444; // [sp+7038h] [bp-7FFCh]@11
  char v6445; // [sp+7050h] [bp-7FE4h]@11
  char v6446; // [sp+7068h] [bp-7FCCh]@11
  char v6447; // [sp+7080h] [bp-7FB4h]@11
  char v6448; // [sp+7098h] [bp-7F9Ch]@11
  char v6449; // [sp+70B0h] [bp-7F84h]@11
  char v6450; // [sp+70C8h] [bp-7F6Ch]@11
  char v6451; // [sp+70E0h] [bp-7F54h]@11
  char v6452; // [sp+70F8h] [bp-7F3Ch]@11
  char v6453; // [sp+7110h] [bp-7F24h]@11
  char v6454; // [sp+7128h] [bp-7F0Ch]@11
  char v6455; // [sp+7140h] [bp-7EF4h]@11
  char v6456; // [sp+7158h] [bp-7EDCh]@11
  char v6457; // [sp+7170h] [bp-7EC4h]@11
  char v6458; // [sp+7188h] [bp-7EACh]@11
  char v6459; // [sp+71A0h] [bp-7E94h]@11
  char v6460; // [sp+71B8h] [bp-7E7Ch]@11
  char v6461; // [sp+71D0h] [bp-7E64h]@11
  char v6462; // [sp+71E8h] [bp-7E4Ch]@11
  char v6463; // [sp+7200h] [bp-7E34h]@11
  char v6464; // [sp+7218h] [bp-7E1Ch]@11
  char v6465; // [sp+7230h] [bp-7E04h]@11
  char v6466; // [sp+7248h] [bp-7DECh]@11
  char v6467; // [sp+7260h] [bp-7DD4h]@11
  char v6468; // [sp+7278h] [bp-7DBCh]@11
  char v6469; // [sp+7290h] [bp-7DA4h]@11
  char v6470; // [sp+72A8h] [bp-7D8Ch]@11
  char v6471; // [sp+72C0h] [bp-7D74h]@11
  char v6472; // [sp+72D8h] [bp-7D5Ch]@11
  char v6473; // [sp+72F0h] [bp-7D44h]@11
  char v6474; // [sp+7308h] [bp-7D2Ch]@11
  char v6475; // [sp+7320h] [bp-7D14h]@11
  char v6476; // [sp+7338h] [bp-7CFCh]@11
  char v6477; // [sp+7350h] [bp-7CE4h]@11
  char v6478; // [sp+7368h] [bp-7CCCh]@11
  char v6479; // [sp+7380h] [bp-7CB4h]@11
  char v6480; // [sp+7398h] [bp-7C9Ch]@11
  char v6481; // [sp+73B0h] [bp-7C84h]@11
  char v6482; // [sp+73C8h] [bp-7C6Ch]@11
  char v6483; // [sp+73E0h] [bp-7C54h]@11
  char v6484; // [sp+73F8h] [bp-7C3Ch]@11
  char v6485; // [sp+7410h] [bp-7C24h]@11
  char v6486; // [sp+7428h] [bp-7C0Ch]@11
  char v6487; // [sp+7440h] [bp-7BF4h]@11
  char v6488; // [sp+7458h] [bp-7BDCh]@11
  char v6489; // [sp+7470h] [bp-7BC4h]@11
  char v6490; // [sp+7488h] [bp-7BACh]@11
  char v6491; // [sp+74A0h] [bp-7B94h]@11
  char v6492; // [sp+74B8h] [bp-7B7Ch]@11
  char v6493; // [sp+74D0h] [bp-7B64h]@11
  char v6494; // [sp+74E8h] [bp-7B4Ch]@11
  char v6495; // [sp+7500h] [bp-7B34h]@11
  char v6496; // [sp+7518h] [bp-7B1Ch]@11
  char v6497; // [sp+7530h] [bp-7B04h]@11
  char v6498; // [sp+7548h] [bp-7AECh]@11
  char v6499; // [sp+7560h] [bp-7AD4h]@11
  char v6500; // [sp+7578h] [bp-7ABCh]@11
  char v6501; // [sp+7590h] [bp-7AA4h]@11
  char v6502; // [sp+75A8h] [bp-7A8Ch]@11
  char v6503; // [sp+75C0h] [bp-7A74h]@11
  char v6504; // [sp+75D8h] [bp-7A5Ch]@11
  char v6505; // [sp+75F0h] [bp-7A44h]@11
  char v6506; // [sp+7608h] [bp-7A2Ch]@11
  char v6507; // [sp+7620h] [bp-7A14h]@11
  char v6508; // [sp+7638h] [bp-79FCh]@11
  char v6509; // [sp+7650h] [bp-79E4h]@11
  char v6510; // [sp+7668h] [bp-79CCh]@11
  char v6511; // [sp+7680h] [bp-79B4h]@11
  char v6512; // [sp+7698h] [bp-799Ch]@11
  char v6513; // [sp+76B0h] [bp-7984h]@11
  char v6514; // [sp+76C8h] [bp-796Ch]@11
  char v6515; // [sp+76E0h] [bp-7954h]@11
  char v6516; // [sp+76F8h] [bp-793Ch]@11
  char v6517; // [sp+7710h] [bp-7924h]@11
  char v6518; // [sp+7728h] [bp-790Ch]@11
  char v6519; // [sp+7740h] [bp-78F4h]@11
  char v6520; // [sp+7758h] [bp-78DCh]@11
  char v6521; // [sp+7770h] [bp-78C4h]@11
  char v6522; // [sp+7788h] [bp-78ACh]@11
  char v6523; // [sp+77A0h] [bp-7894h]@11
  char v6524; // [sp+77B8h] [bp-787Ch]@11
  char v6525; // [sp+77D0h] [bp-7864h]@7
  char v6526; // [sp+77E8h] [bp-784Ch]@11
  char v6527; // [sp+7800h] [bp-7834h]@11
  char v6528; // [sp+7818h] [bp-781Ch]@11
  char v6529; // [sp+7830h] [bp-7804h]@11
  char v6530; // [sp+7848h] [bp-77ECh]@11
  char v6531; // [sp+7860h] [bp-77D4h]@11
  char v6532; // [sp+7878h] [bp-77BCh]@11
  char v6533; // [sp+7890h] [bp-77A4h]@11
  char v6534; // [sp+78A8h] [bp-778Ch]@11
  char v6535; // [sp+78C0h] [bp-7774h]@11
  char v6536; // [sp+78D8h] [bp-775Ch]@11
  char v6537; // [sp+78F0h] [bp-7744h]@11
  char v6538; // [sp+7908h] [bp-772Ch]@11
  char v6539; // [sp+7920h] [bp-7714h]@11
  char v6540; // [sp+7938h] [bp-76FCh]@11
  char v6541; // [sp+7950h] [bp-76E4h]@11
  char v6542; // [sp+7968h] [bp-76CCh]@11
  char v6543; // [sp+7980h] [bp-76B4h]@11
  char v6544; // [sp+7998h] [bp-769Ch]@11
  char v6545; // [sp+79B0h] [bp-7684h]@11
  char v6546; // [sp+79C8h] [bp-766Ch]@11
  char v6547; // [sp+79E0h] [bp-7654h]@11
  char v6548; // [sp+79F8h] [bp-763Ch]@11
  char v6549; // [sp+7A10h] [bp-7624h]@11
  char v6550; // [sp+7A28h] [bp-760Ch]@11
  char v6551; // [sp+7A40h] [bp-75F4h]@11
  char v6552; // [sp+7A58h] [bp-75DCh]@11
  char v6553; // [sp+7A70h] [bp-75C4h]@11
  char v6554; // [sp+7A88h] [bp-75ACh]@11
  char v6555; // [sp+7AA0h] [bp-7594h]@11
  char v6556; // [sp+7AB8h] [bp-757Ch]@11
  char v6557; // [sp+7AD0h] [bp-7564h]@11
  char v6558; // [sp+7AE8h] [bp-754Ch]@11
  char v6559; // [sp+7B00h] [bp-7534h]@11
  char v6560; // [sp+7B18h] [bp-751Ch]@11
  char v6561; // [sp+7B30h] [bp-7504h]@11
  char v6562; // [sp+7B48h] [bp-74ECh]@11
  char v6563; // [sp+7B60h] [bp-74D4h]@11
  char v6564; // [sp+7B78h] [bp-74BCh]@11
  char v6565; // [sp+7B90h] [bp-74A4h]@11
  char v6566; // [sp+7BA8h] [bp-748Ch]@11
  char v6567; // [sp+7BC0h] [bp-7474h]@11
  char v6568; // [sp+7BD8h] [bp-745Ch]@11
  char v6569; // [sp+7BF0h] [bp-7444h]@11
  char v6570; // [sp+7C08h] [bp-742Ch]@11
  char v6571; // [sp+7C20h] [bp-7414h]@11
  char v6572; // [sp+7C38h] [bp-73FCh]@11
  char v6573; // [sp+7C50h] [bp-73E4h]@11
  char v6574; // [sp+7C68h] [bp-73CCh]@11
  char v6575; // [sp+7C80h] [bp-73B4h]@11
  char v6576; // [sp+7C98h] [bp-739Ch]@11
  char v6577; // [sp+7CB0h] [bp-7384h]@11
  char v6578; // [sp+7CC8h] [bp-736Ch]@11
  char v6579; // [sp+7CE0h] [bp-7354h]@11
  char v6580; // [sp+7CF8h] [bp-733Ch]@11
  char v6581; // [sp+7D10h] [bp-7324h]@11
  char v6582; // [sp+7D28h] [bp-730Ch]@11
  char v6583; // [sp+7D40h] [bp-72F4h]@11
  char v6584; // [sp+7D58h] [bp-72DCh]@11
  char v6585; // [sp+7D70h] [bp-72C4h]@11
  char v6586; // [sp+7D88h] [bp-72ACh]@11
  char v6587; // [sp+7DA0h] [bp-7294h]@11
  char v6588; // [sp+7DB8h] [bp-727Ch]@11
  char v6589; // [sp+7DD0h] [bp-7264h]@11
  char v6590; // [sp+7DE8h] [bp-724Ch]@11
  char v6591; // [sp+7E00h] [bp-7234h]@11
  char v6592; // [sp+7E18h] [bp-721Ch]@11
  char v6593; // [sp+7E30h] [bp-7204h]@11
  char v6594; // [sp+7E48h] [bp-71ECh]@11
  char v6595; // [sp+7E60h] [bp-71D4h]@11
  char v6596; // [sp+7E78h] [bp-71BCh]@11
  char v6597; // [sp+7E90h] [bp-71A4h]@11
  char v6598; // [sp+7EA8h] [bp-718Ch]@11
  char v6599; // [sp+7EC0h] [bp-7174h]@11
  char v6600; // [sp+7ED8h] [bp-715Ch]@11
  char v6601; // [sp+7EF0h] [bp-7144h]@11
  char v6602; // [sp+7F08h] [bp-712Ch]@11
  char v6603; // [sp+7F20h] [bp-7114h]@11
  char v6604; // [sp+7F38h] [bp-70FCh]@11
  char v6605; // [sp+7F50h] [bp-70E4h]@11
  char v6606; // [sp+7F68h] [bp-70CCh]@11
  char v6607; // [sp+7F80h] [bp-70B4h]@11
  char v6608; // [sp+7F98h] [bp-709Ch]@11
  char v6609; // [sp+7FB0h] [bp-7084h]@11
  char v6610; // [sp+7FC8h] [bp-706Ch]@11
  char v6611; // [sp+7FE0h] [bp-7054h]@11
  char v6612; // [sp+7FF8h] [bp-703Ch]@11
  char v6613; // [sp+8010h] [bp-7024h]@11
  char v6614; // [sp+8028h] [bp-700Ch]@11
  char v6615; // [sp+8040h] [bp-6FF4h]@11
  char v6616; // [sp+8058h] [bp-6FDCh]@11
  char v6617; // [sp+8070h] [bp-6FC4h]@11
  char v6618; // [sp+8088h] [bp-6FACh]@11
  char v6619; // [sp+80A0h] [bp-6F94h]@11
  char v6620; // [sp+80B8h] [bp-6F7Ch]@11
  char v6621; // [sp+80D0h] [bp-6F64h]@11
  char v6622; // [sp+80E8h] [bp-6F4Ch]@11
  char v6623; // [sp+8100h] [bp-6F34h]@11
  char v6624; // [sp+8118h] [bp-6F1Ch]@11
  char v6625; // [sp+8130h] [bp-6F04h]@11
  char v6626; // [sp+8148h] [bp-6EECh]@11
  char v6627; // [sp+8160h] [bp-6ED4h]@11
  char v6628; // [sp+8178h] [bp-6EBCh]@11
  char v6629; // [sp+8190h] [bp-6EA4h]@11
  char v6630; // [sp+81A8h] [bp-6E8Ch]@11
  char v6631; // [sp+81C0h] [bp-6E74h]@11
  char v6632; // [sp+81D8h] [bp-6E5Ch]@11
  char v6633; // [sp+81F0h] [bp-6E44h]@11
  char v6634; // [sp+8208h] [bp-6E2Ch]@11
  char v6635; // [sp+8220h] [bp-6E14h]@11
  char v6636; // [sp+8238h] [bp-6DFCh]@11
  char v6637; // [sp+8250h] [bp-6DE4h]@11
  char v6638; // [sp+8268h] [bp-6DCCh]@11
  char v6639; // [sp+8280h] [bp-6DB4h]@11
  char v6640; // [sp+8298h] [bp-6D9Ch]@11
  char v6641; // [sp+82B0h] [bp-6D84h]@11
  char v6642; // [sp+82C8h] [bp-6D6Ch]@11
  char v6643; // [sp+82E0h] [bp-6D54h]@11
  char v6644; // [sp+82F8h] [bp-6D3Ch]@11
  char v6645; // [sp+8310h] [bp-6D24h]@11
  char v6646; // [sp+8328h] [bp-6D0Ch]@11
  char v6647; // [sp+8340h] [bp-6CF4h]@11
  char v6648; // [sp+8358h] [bp-6CDCh]@11
  char v6649; // [sp+8370h] [bp-6CC4h]@11
  char v6650; // [sp+8388h] [bp-6CACh]@11
  char v6651; // [sp+83A0h] [bp-6C94h]@11
  char v6652; // [sp+83B8h] [bp-6C7Ch]@11
  char v6653; // [sp+83D0h] [bp-6C64h]@11
  char v6654; // [sp+83E8h] [bp-6C4Ch]@11
  char v6655; // [sp+8400h] [bp-6C34h]@11
  char v6656; // [sp+8418h] [bp-6C1Ch]@11
  char v6657; // [sp+8430h] [bp-6C04h]@11
  char v6658; // [sp+8448h] [bp-6BECh]@11
  char v6659; // [sp+8460h] [bp-6BD4h]@11
  char v6660; // [sp+8478h] [bp-6BBCh]@11
  char v6661; // [sp+8490h] [bp-6BA4h]@11
  char v6662; // [sp+84A8h] [bp-6B8Ch]@11
  char v6663; // [sp+84C0h] [bp-6B74h]@11
  char v6664; // [sp+84D8h] [bp-6B5Ch]@11
  char v6665; // [sp+84F0h] [bp-6B44h]@11
  char v6666; // [sp+8508h] [bp-6B2Ch]@11
  char v6667; // [sp+8520h] [bp-6B14h]@11
  char v6668; // [sp+8538h] [bp-6AFCh]@11
  char v6669; // [sp+8550h] [bp-6AE4h]@11
  char v6670; // [sp+8568h] [bp-6ACCh]@11
  char v6671; // [sp+8580h] [bp-6AB4h]@11
  char v6672; // [sp+8598h] [bp-6A9Ch]@11
  char v6673; // [sp+85B0h] [bp-6A84h]@11
  char v6674; // [sp+85C8h] [bp-6A6Ch]@11
  char v6675; // [sp+85E0h] [bp-6A54h]@11
  char v6676; // [sp+85F8h] [bp-6A3Ch]@11
  char v6677; // [sp+8610h] [bp-6A24h]@11
  char v6678; // [sp+8628h] [bp-6A0Ch]@11
  char v6679; // [sp+8640h] [bp-69F4h]@11
  char v6680; // [sp+8658h] [bp-69DCh]@11
  char v6681; // [sp+8670h] [bp-69C4h]@11
  char v6682; // [sp+8688h] [bp-69ACh]@11
  char v6683; // [sp+86A0h] [bp-6994h]@11
  char v6684; // [sp+86B8h] [bp-697Ch]@11
  char v6685; // [sp+86D0h] [bp-6964h]@11
  char v6686; // [sp+86E8h] [bp-694Ch]@11
  char v6687; // [sp+8700h] [bp-6934h]@11
  char v6688; // [sp+8718h] [bp-691Ch]@11
  char v6689; // [sp+8730h] [bp-6904h]@11
  char v6690; // [sp+8748h] [bp-68ECh]@11
  char v6691; // [sp+8760h] [bp-68D4h]@11
  char v6692; // [sp+8778h] [bp-68BCh]@11
  char v6693; // [sp+8790h] [bp-68A4h]@11
  char v6694; // [sp+87A8h] [bp-688Ch]@11
  char v6695; // [sp+87C0h] [bp-6874h]@11
  char v6696; // [sp+87D8h] [bp-685Ch]@11
  char v6697; // [sp+87F0h] [bp-6844h]@11
  char v6698; // [sp+8808h] [bp-682Ch]@11
  char v6699; // [sp+8820h] [bp-6814h]@11
  char v6700; // [sp+8838h] [bp-67FCh]@11
  char v6701; // [sp+8850h] [bp-67E4h]@11
  char v6702; // [sp+8868h] [bp-67CCh]@11
  char v6703; // [sp+8880h] [bp-67B4h]@11
  char v6704; // [sp+8898h] [bp-679Ch]@11
  char v6705; // [sp+88B0h] [bp-6784h]@11
  char v6706; // [sp+88C8h] [bp-676Ch]@11
  char v6707; // [sp+88E0h] [bp-6754h]@11
  char v6708; // [sp+88F8h] [bp-673Ch]@11
  char v6709; // [sp+8910h] [bp-6724h]@11
  char v6710; // [sp+8928h] [bp-670Ch]@11
  char v6711; // [sp+8940h] [bp-66F4h]@11
  char v6712; // [sp+8958h] [bp-66DCh]@11
  char v6713; // [sp+8970h] [bp-66C4h]@11
  char v6714; // [sp+8988h] [bp-66ACh]@11
  char v6715; // [sp+89A0h] [bp-6694h]@11
  char v6716; // [sp+89B8h] [bp-667Ch]@11
  char v6717; // [sp+89D0h] [bp-6664h]@11
  char v6718; // [sp+89E8h] [bp-664Ch]@11
  char v6719; // [sp+8A00h] [bp-6634h]@11
  char v6720; // [sp+8A18h] [bp-661Ch]@11
  char v6721; // [sp+8A30h] [bp-6604h]@11
  char v6722; // [sp+8A48h] [bp-65ECh]@11
  char v6723; // [sp+8A60h] [bp-65D4h]@11
  char v6724; // [sp+8A78h] [bp-65BCh]@11
  char v6725; // [sp+8A90h] [bp-65A4h]@11
  char v6726; // [sp+8AA8h] [bp-658Ch]@11
  char v6727; // [sp+8AC0h] [bp-6574h]@11
  char v6728; // [sp+8AD8h] [bp-655Ch]@11
  char v6729; // [sp+8AF0h] [bp-6544h]@11
  char v6730; // [sp+8B08h] [bp-652Ch]@11
  char v6731; // [sp+8B20h] [bp-6514h]@11
  char v6732; // [sp+8B38h] [bp-64FCh]@11
  char v6733; // [sp+8B50h] [bp-64E4h]@11
  char v6734; // [sp+8B68h] [bp-64CCh]@11
  char v6735; // [sp+8B80h] [bp-64B4h]@11
  char v6736; // [sp+8B98h] [bp-649Ch]@11
  char v6737; // [sp+8BB0h] [bp-6484h]@11
  char v6738; // [sp+8BC8h] [bp-646Ch]@11
  char v6739; // [sp+8BE0h] [bp-6454h]@11
  char v6740; // [sp+8BF8h] [bp-643Ch]@11
  char v6741; // [sp+8C10h] [bp-6424h]@11
  char v6742; // [sp+8C28h] [bp-640Ch]@11
  char v6743; // [sp+8C40h] [bp-63F4h]@11
  char v6744; // [sp+8C58h] [bp-63DCh]@11
  char v6745; // [sp+8C70h] [bp-63C4h]@11
  char v6746; // [sp+8C88h] [bp-63ACh]@11
  char v6747; // [sp+8CA0h] [bp-6394h]@11
  char v6748; // [sp+8CB8h] [bp-637Ch]@11
  char v6749; // [sp+8CD0h] [bp-6364h]@11
  char v6750; // [sp+8CE8h] [bp-634Ch]@11
  char v6751; // [sp+8D00h] [bp-6334h]@11
  char v6752; // [sp+8D18h] [bp-631Ch]@11
  char v6753; // [sp+8D30h] [bp-6304h]@11
  char v6754; // [sp+8D48h] [bp-62ECh]@11
  char v6755; // [sp+8D60h] [bp-62D4h]@11
  char v6756; // [sp+8D78h] [bp-62BCh]@11
  char v6757; // [sp+8D90h] [bp-62A4h]@11
  char v6758; // [sp+8DA8h] [bp-628Ch]@11
  char v6759; // [sp+8DC0h] [bp-6274h]@11
  char v6760; // [sp+8DD8h] [bp-625Ch]@11
  char v6761; // [sp+8DF0h] [bp-6244h]@11
  char v6762; // [sp+8E08h] [bp-622Ch]@11
  char v6763; // [sp+8E20h] [bp-6214h]@11
  char v6764; // [sp+8E38h] [bp-61FCh]@11
  char v6765; // [sp+8E50h] [bp-61E4h]@11
  char v6766; // [sp+8E68h] [bp-61CCh]@11
  char v6767; // [sp+8E80h] [bp-61B4h]@11
  char v6768; // [sp+8E98h] [bp-619Ch]@11
  char v6769; // [sp+8EB0h] [bp-6184h]@11
  char v6770; // [sp+8EC8h] [bp-616Ch]@11
  char v6771; // [sp+8EE0h] [bp-6154h]@11
  char v6772; // [sp+8EF8h] [bp-613Ch]@11
  char v6773; // [sp+8F10h] [bp-6124h]@11
  char v6774; // [sp+8F28h] [bp-610Ch]@11
  char v6775; // [sp+8F40h] [bp-60F4h]@11
  char v6776; // [sp+8F58h] [bp-60DCh]@11
  char v6777; // [sp+8F70h] [bp-60C4h]@11
  char v6778; // [sp+8F88h] [bp-60ACh]@11
  char v6779; // [sp+8FA0h] [bp-6094h]@11
  char v6780; // [sp+8FB8h] [bp-607Ch]@11
  char v6781; // [sp+8FD0h] [bp-6064h]@11
  char v6782; // [sp+8FE8h] [bp-604Ch]@11
  char v6783; // [sp+9000h] [bp-6034h]@11
  char v6784; // [sp+9018h] [bp-601Ch]@11
  char v6785; // [sp+9030h] [bp-6004h]@11
  char v6786; // [sp+9048h] [bp-5FECh]@11
  char v6787; // [sp+9060h] [bp-5FD4h]@11
  char v6788; // [sp+9078h] [bp-5FBCh]@11
  char v6789; // [sp+9090h] [bp-5FA4h]@11
  char v6790; // [sp+90A8h] [bp-5F8Ch]@11
  char v6791; // [sp+90C0h] [bp-5F74h]@11
  char v6792; // [sp+90D8h] [bp-5F5Ch]@11
  char v6793; // [sp+90F0h] [bp-5F44h]@11
  char v6794; // [sp+9108h] [bp-5F2Ch]@11
  char v6795; // [sp+9120h] [bp-5F14h]@11
  char v6796; // [sp+9138h] [bp-5EFCh]@11
  char v6797; // [sp+9150h] [bp-5EE4h]@11
  char v6798; // [sp+9168h] [bp-5ECCh]@11
  char v6799; // [sp+9180h] [bp-5EB4h]@11
  char v6800; // [sp+9198h] [bp-5E9Ch]@11
  char v6801; // [sp+91B0h] [bp-5E84h]@11
  char v6802; // [sp+91C8h] [bp-5E6Ch]@11
  char v6803; // [sp+91E0h] [bp-5E54h]@11
  char v6804; // [sp+91F8h] [bp-5E3Ch]@11
  char v6805; // [sp+9210h] [bp-5E24h]@11
  char v6806; // [sp+9228h] [bp-5E0Ch]@11
  char v6807; // [sp+9240h] [bp-5DF4h]@11
  char v6808; // [sp+9258h] [bp-5DDCh]@11
  char v6809; // [sp+9270h] [bp-5DC4h]@11
  char v6810; // [sp+9288h] [bp-5DACh]@11
  char v6811; // [sp+92A0h] [bp-5D94h]@11
  char v6812; // [sp+92B8h] [bp-5D7Ch]@11
  char v6813; // [sp+92D0h] [bp-5D64h]@11
  char v6814; // [sp+92E8h] [bp-5D4Ch]@11
  char v6815; // [sp+9300h] [bp-5D34h]@11
  char v6816; // [sp+9318h] [bp-5D1Ch]@11
  char v6817; // [sp+9330h] [bp-5D04h]@11
  char v6818; // [sp+9348h] [bp-5CECh]@11
  char v6819; // [sp+9360h] [bp-5CD4h]@11
  char v6820; // [sp+9378h] [bp-5CBCh]@11
  char v6821; // [sp+9390h] [bp-5CA4h]@11
  char v6822; // [sp+93A8h] [bp-5C8Ch]@11
  char v6823; // [sp+93C0h] [bp-5C74h]@11
  char v6824; // [sp+93D8h] [bp-5C5Ch]@11
  char v6825; // [sp+93F0h] [bp-5C44h]@11
  char v6826; // [sp+9408h] [bp-5C2Ch]@11
  char v6827; // [sp+9420h] [bp-5C14h]@11
  char v6828; // [sp+9438h] [bp-5BFCh]@11
  char v6829; // [sp+9450h] [bp-5BE4h]@11
  char v6830; // [sp+9468h] [bp-5BCCh]@11
  char v6831; // [sp+9480h] [bp-5BB4h]@11
  char v6832; // [sp+9498h] [bp-5B9Ch]@11
  char v6833; // [sp+94B0h] [bp-5B84h]@11
  char v6834; // [sp+94C8h] [bp-5B6Ch]@11
  char v6835; // [sp+94E0h] [bp-5B54h]@11
  char v6836; // [sp+94F8h] [bp-5B3Ch]@11
  char v6837; // [sp+9510h] [bp-5B24h]@11
  char v6838; // [sp+9528h] [bp-5B0Ch]@11
  char v6839; // [sp+9540h] [bp-5AF4h]@11
  char v6840; // [sp+9558h] [bp-5ADCh]@11
  char v6841; // [sp+9570h] [bp-5AC4h]@11
  char v6842; // [sp+9588h] [bp-5AACh]@11
  char v6843; // [sp+95A0h] [bp-5A94h]@11
  char v6844; // [sp+95B8h] [bp-5A7Ch]@11
  char v6845; // [sp+95D0h] [bp-5A64h]@11
  char v6846; // [sp+95E8h] [bp-5A4Ch]@11
  char v6847; // [sp+9600h] [bp-5A34h]@11
  char v6848; // [sp+9618h] [bp-5A1Ch]@11
  char v6849; // [sp+9630h] [bp-5A04h]@11
  char v6850; // [sp+9648h] [bp-59ECh]@11
  char v6851; // [sp+9660h] [bp-59D4h]@11
  char v6852; // [sp+9678h] [bp-59BCh]@11
  char v6853; // [sp+9690h] [bp-59A4h]@11
  char v6854; // [sp+96A8h] [bp-598Ch]@11
  char v6855; // [sp+96C0h] [bp-5974h]@11
  char v6856; // [sp+96D8h] [bp-595Ch]@11
  char v6857; // [sp+96F0h] [bp-5944h]@11
  char v6858; // [sp+9708h] [bp-592Ch]@11
  char v6859; // [sp+9720h] [bp-5914h]@11
  char v6860; // [sp+9738h] [bp-58FCh]@11
  char v6861; // [sp+9750h] [bp-58E4h]@11
  char v6862; // [sp+9768h] [bp-58CCh]@11
  char v6863; // [sp+9780h] [bp-58B4h]@11
  char v6864; // [sp+9798h] [bp-589Ch]@11
  char v6865; // [sp+97B0h] [bp-5884h]@11
  char v6866; // [sp+97C8h] [bp-586Ch]@11
  char v6867; // [sp+97E0h] [bp-5854h]@11
  char v6868; // [sp+97F8h] [bp-583Ch]@11
  char v6869; // [sp+9810h] [bp-5824h]@11
  char v6870; // [sp+9828h] [bp-580Ch]@11
  char v6871; // [sp+9840h] [bp-57F4h]@11
  char v6872; // [sp+9858h] [bp-57DCh]@11
  char v6873; // [sp+9870h] [bp-57C4h]@11
  char v6874; // [sp+9888h] [bp-57ACh]@11
  char v6875; // [sp+98A0h] [bp-5794h]@11
  char v6876; // [sp+98B8h] [bp-577Ch]@11
  char v6877; // [sp+98D0h] [bp-5764h]@11
  char v6878; // [sp+98E8h] [bp-574Ch]@11
  char v6879; // [sp+9900h] [bp-5734h]@11
  char v6880; // [sp+9918h] [bp-571Ch]@11
  char v6881; // [sp+9930h] [bp-5704h]@11
  char v6882; // [sp+9948h] [bp-56ECh]@11
  char v6883; // [sp+9960h] [bp-56D4h]@11
  char v6884; // [sp+9978h] [bp-56BCh]@11
  char v6885; // [sp+9990h] [bp-56A4h]@11
  char v6886; // [sp+99A8h] [bp-568Ch]@11
  char v6887; // [sp+99C0h] [bp-5674h]@11
  char v6888; // [sp+99D8h] [bp-565Ch]@11
  char v6889; // [sp+99F0h] [bp-5644h]@11
  char v6890; // [sp+9A08h] [bp-562Ch]@11
  char v6891; // [sp+9A20h] [bp-5614h]@11
  char v6892; // [sp+9A38h] [bp-55FCh]@11
  char v6893; // [sp+9A50h] [bp-55E4h]@11
  char v6894; // [sp+9A68h] [bp-55CCh]@11
  char v6895; // [sp+9A80h] [bp-55B4h]@11
  char v6896; // [sp+9A98h] [bp-559Ch]@11
  char v6897; // [sp+9AB0h] [bp-5584h]@11
  char v6898; // [sp+9AC8h] [bp-556Ch]@11
  char v6899; // [sp+9AE0h] [bp-5554h]@11
  char v6900; // [sp+9AF8h] [bp-553Ch]@11
  char v6901; // [sp+9B10h] [bp-5524h]@11
  char v6902; // [sp+9B28h] [bp-550Ch]@11
  char v6903; // [sp+9B40h] [bp-54F4h]@11
  char v6904; // [sp+9B58h] [bp-54DCh]@11
  char v6905; // [sp+9B70h] [bp-54C4h]@11
  char v6906; // [sp+9B88h] [bp-54ACh]@11
  char v6907; // [sp+9BA0h] [bp-5494h]@11
  char v6908; // [sp+9BB8h] [bp-547Ch]@11
  char v6909; // [sp+9BD0h] [bp-5464h]@11
  char v6910; // [sp+9BE8h] [bp-544Ch]@11
  char v6911; // [sp+9C00h] [bp-5434h]@11
  char v6912; // [sp+9C18h] [bp-541Ch]@11
  char v6913; // [sp+9C30h] [bp-5404h]@11
  char v6914; // [sp+9C48h] [bp-53ECh]@11
  char v6915; // [sp+9C60h] [bp-53D4h]@11
  char v6916; // [sp+9C78h] [bp-53BCh]@11
  char v6917; // [sp+9C90h] [bp-53A4h]@11
  char v6918; // [sp+9CA8h] [bp-538Ch]@11
  char v6919; // [sp+9CC0h] [bp-5374h]@11
  char v6920; // [sp+9CD8h] [bp-535Ch]@11
  char v6921; // [sp+9CF0h] [bp-5344h]@11
  char v6922; // [sp+9D08h] [bp-532Ch]@11
  char v6923; // [sp+9D20h] [bp-5314h]@11
  char v6924; // [sp+9D38h] [bp-52FCh]@11
  char v6925; // [sp+9D50h] [bp-52E4h]@11
  char v6926; // [sp+9D68h] [bp-52CCh]@11
  char v6927; // [sp+9D80h] [bp-52B4h]@11
  char v6928; // [sp+9D98h] [bp-529Ch]@11
  char v6929; // [sp+9DB0h] [bp-5284h]@11
  char v6930; // [sp+9DC8h] [bp-526Ch]@11
  char v6931; // [sp+9DE0h] [bp-5254h]@11
  char v6932; // [sp+9DF8h] [bp-523Ch]@11
  char v6933; // [sp+9E10h] [bp-5224h]@11
  char v6934; // [sp+9E28h] [bp-520Ch]@11
  char v6935; // [sp+9E40h] [bp-51F4h]@11
  char v6936; // [sp+9E58h] [bp-51DCh]@11
  char v6937; // [sp+9E70h] [bp-51C4h]@11
  char v6938; // [sp+9E88h] [bp-51ACh]@11
  char v6939; // [sp+9EA0h] [bp-5194h]@11
  char v6940; // [sp+9EB8h] [bp-517Ch]@11
  char v6941; // [sp+9ED0h] [bp-5164h]@11
  char v6942; // [sp+9EE8h] [bp-514Ch]@11
  char v6943; // [sp+9F00h] [bp-5134h]@11
  char v6944; // [sp+9F18h] [bp-511Ch]@11
  char v6945; // [sp+9F30h] [bp-5104h]@11
  char v6946; // [sp+9F48h] [bp-50ECh]@11
  char v6947; // [sp+9F60h] [bp-50D4h]@11
  char v6948; // [sp+9F78h] [bp-50BCh]@11
  char v6949; // [sp+9F90h] [bp-50A4h]@11
  char v6950; // [sp+9FA8h] [bp-508Ch]@11
  char v6951; // [sp+9FC0h] [bp-5074h]@11
  char v6952; // [sp+9FD8h] [bp-505Ch]@11
  char v6953; // [sp+9FF0h] [bp-5044h]@11
  char v6954; // [sp+A008h] [bp-502Ch]@11
  char v6955; // [sp+A020h] [bp-5014h]@11
  char v6956; // [sp+A038h] [bp-4FFCh]@11
  char v6957; // [sp+A050h] [bp-4FE4h]@11
  char v6958; // [sp+A068h] [bp-4FCCh]@11
  char v6959; // [sp+A080h] [bp-4FB4h]@11
  char v6960; // [sp+A098h] [bp-4F9Ch]@11
  char v6961; // [sp+A0B0h] [bp-4F84h]@11
  char v6962; // [sp+A0C8h] [bp-4F6Ch]@11
  char v6963; // [sp+A0E0h] [bp-4F54h]@11
  char v6964; // [sp+A0F8h] [bp-4F3Ch]@11
  char v6965; // [sp+A110h] [bp-4F24h]@11
  char v6966; // [sp+A128h] [bp-4F0Ch]@11
  char v6967; // [sp+A140h] [bp-4EF4h]@11
  char v6968; // [sp+A158h] [bp-4EDCh]@11
  char v6969; // [sp+A170h] [bp-4EC4h]@11
  char v6970; // [sp+A188h] [bp-4EACh]@11
  char v6971; // [sp+A1A0h] [bp-4E94h]@11
  char v6972; // [sp+A1B8h] [bp-4E7Ch]@11
  char v6973; // [sp+A1D0h] [bp-4E64h]@11
  char v6974; // [sp+A1E8h] [bp-4E4Ch]@11
  char v6975; // [sp+A200h] [bp-4E34h]@11
  char v6976; // [sp+A218h] [bp-4E1Ch]@11
  char v6977; // [sp+A230h] [bp-4E04h]@11
  char v6978; // [sp+A248h] [bp-4DECh]@11
  char v6979; // [sp+A260h] [bp-4DD4h]@11
  char v6980; // [sp+A278h] [bp-4DBCh]@11
  char v6981; // [sp+A290h] [bp-4DA4h]@11
  char v6982; // [sp+A2A8h] [bp-4D8Ch]@11
  char v6983; // [sp+A2C0h] [bp-4D74h]@11
  char v6984; // [sp+A2D8h] [bp-4D5Ch]@11
  char v6985; // [sp+A2F0h] [bp-4D44h]@11
  char v6986; // [sp+A308h] [bp-4D2Ch]@11
  char v6987; // [sp+A320h] [bp-4D14h]@11
  char v6988; // [sp+A338h] [bp-4CFCh]@11
  char v6989; // [sp+A350h] [bp-4CE4h]@11
  char v6990; // [sp+A368h] [bp-4CCCh]@11
  char v6991; // [sp+A380h] [bp-4CB4h]@11
  char v6992; // [sp+A398h] [bp-4C9Ch]@11
  char v6993; // [sp+A3B0h] [bp-4C84h]@11
  char v6994; // [sp+A3C8h] [bp-4C6Ch]@11
  char v6995; // [sp+A3E0h] [bp-4C54h]@11
  char v6996; // [sp+A3F8h] [bp-4C3Ch]@11
  char v6997; // [sp+A410h] [bp-4C24h]@11
  char v6998; // [sp+A428h] [bp-4C0Ch]@11
  char v6999; // [sp+A440h] [bp-4BF4h]@11
  char v7000; // [sp+A458h] [bp-4BDCh]@11
  char v7001; // [sp+A470h] [bp-4BC4h]@11
  char v7002; // [sp+A488h] [bp-4BACh]@11
  char v7003; // [sp+A4A0h] [bp-4B94h]@11
  char v7004; // [sp+A4B8h] [bp-4B7Ch]@11
  char v7005; // [sp+A4D0h] [bp-4B64h]@11
  char v7006; // [sp+A4E8h] [bp-4B4Ch]@11
  char v7007; // [sp+A500h] [bp-4B34h]@11
  char v7008; // [sp+A518h] [bp-4B1Ch]@11
  char v7009; // [sp+A530h] [bp-4B04h]@11
  char v7010; // [sp+A548h] [bp-4AECh]@11
  char v7011; // [sp+A560h] [bp-4AD4h]@11
  char v7012; // [sp+A578h] [bp-4ABCh]@11
  char v7013; // [sp+A590h] [bp-4AA4h]@11
  char v7014; // [sp+A5A8h] [bp-4A8Ch]@11
  char v7015; // [sp+A5C0h] [bp-4A74h]@11
  char v7016; // [sp+A5D8h] [bp-4A5Ch]@11
  char v7017; // [sp+A5F0h] [bp-4A44h]@11
  char v7018; // [sp+A608h] [bp-4A2Ch]@11
  char v7019; // [sp+A620h] [bp-4A14h]@11
  char v7020; // [sp+A638h] [bp-49FCh]@11
  char v7021; // [sp+A650h] [bp-49E4h]@11
  char v7022; // [sp+A668h] [bp-49CCh]@11
  char v7023; // [sp+A680h] [bp-49B4h]@11
  char v7024; // [sp+A698h] [bp-499Ch]@11
  char v7025; // [sp+A6B0h] [bp-4984h]@11
  char v7026; // [sp+A6C8h] [bp-496Ch]@11
  char v7027; // [sp+A6E0h] [bp-4954h]@11
  char v7028; // [sp+A6F8h] [bp-493Ch]@11
  char v7029; // [sp+A710h] [bp-4924h]@11
  char v7030; // [sp+A728h] [bp-490Ch]@11
  char v7031; // [sp+A740h] [bp-48F4h]@11
  char v7032; // [sp+A758h] [bp-48DCh]@11
  char v7033; // [sp+A770h] [bp-48C4h]@11
  char v7034; // [sp+A788h] [bp-48ACh]@11
  char v7035; // [sp+A7A0h] [bp-4894h]@11
  char v7036; // [sp+A7B8h] [bp-487Ch]@11
  char v7037; // [sp+A7D0h] [bp-4864h]@11
  char v7038; // [sp+A7E8h] [bp-484Ch]@11
  char v7039; // [sp+A800h] [bp-4834h]@11
  char v7040; // [sp+A818h] [bp-481Ch]@11
  char v7041; // [sp+A830h] [bp-4804h]@11
  char v7042; // [sp+A848h] [bp-47ECh]@11
  char v7043; // [sp+A860h] [bp-47D4h]@11
  char v7044; // [sp+A878h] [bp-47BCh]@11
  char v7045; // [sp+A890h] [bp-47A4h]@11
  char v7046; // [sp+A8A8h] [bp-478Ch]@11
  char v7047; // [sp+A8C0h] [bp-4774h]@11
  char v7048; // [sp+A8D8h] [bp-475Ch]@11
  char v7049; // [sp+A8F0h] [bp-4744h]@11
  char v7050; // [sp+A908h] [bp-472Ch]@11
  char v7051; // [sp+A920h] [bp-4714h]@11
  char v7052; // [sp+A938h] [bp-46FCh]@11
  char v7053; // [sp+A950h] [bp-46E4h]@11
  char v7054; // [sp+A968h] [bp-46CCh]@11
  char v7055; // [sp+A980h] [bp-46B4h]@11
  char v7056; // [sp+A998h] [bp-469Ch]@11
  char v7057; // [sp+A9B0h] [bp-4684h]@11
  char v7058; // [sp+A9C8h] [bp-466Ch]@11
  char v7059; // [sp+A9E0h] [bp-4654h]@11
  char v7060; // [sp+A9F8h] [bp-463Ch]@11
  char v7061; // [sp+AA10h] [bp-4624h]@11
  char v7062; // [sp+AA28h] [bp-460Ch]@11
  char v7063; // [sp+AA40h] [bp-45F4h]@11
  char v7064; // [sp+AA58h] [bp-45DCh]@11
  char v7065; // [sp+AA70h] [bp-45C4h]@11
  char v7066; // [sp+AA88h] [bp-45ACh]@11
  char v7067; // [sp+AAA0h] [bp-4594h]@11
  char v7068; // [sp+AAB8h] [bp-457Ch]@11
  char v7069; // [sp+AAD0h] [bp-4564h]@11
  char v7070; // [sp+AAE8h] [bp-454Ch]@11
  char v7071; // [sp+AB00h] [bp-4534h]@11
  char v7072; // [sp+AB18h] [bp-451Ch]@11
  char v7073; // [sp+AB30h] [bp-4504h]@11
  char v7074; // [sp+AB48h] [bp-44ECh]@11
  char v7075; // [sp+AB60h] [bp-44D4h]@11
  char v7076; // [sp+AB78h] [bp-44BCh]@11
  char v7077; // [sp+AB90h] [bp-44A4h]@11
  char v7078; // [sp+ABA8h] [bp-448Ch]@11
  char v7079; // [sp+ABC0h] [bp-4474h]@11
  char v7080; // [sp+ABD8h] [bp-445Ch]@11
  char v7081; // [sp+ABF0h] [bp-4444h]@11
  char v7082; // [sp+AC08h] [bp-442Ch]@11
  char v7083; // [sp+AC20h] [bp-4414h]@11
  char v7084; // [sp+AC38h] [bp-43FCh]@11
  char v7085; // [sp+AC50h] [bp-43E4h]@11
  char v7086; // [sp+AC68h] [bp-43CCh]@11
  char v7087; // [sp+AC80h] [bp-43B4h]@11
  char v7088; // [sp+AC98h] [bp-439Ch]@11
  char v7089; // [sp+ACB0h] [bp-4384h]@11
  char v7090; // [sp+ACC8h] [bp-436Ch]@11
  char v7091; // [sp+ACE0h] [bp-4354h]@11
  char v7092; // [sp+ACF8h] [bp-433Ch]@11
  char v7093; // [sp+AD10h] [bp-4324h]@11
  char v7094; // [sp+AD28h] [bp-430Ch]@11
  char v7095; // [sp+AD40h] [bp-42F4h]@11
  char v7096; // [sp+AD58h] [bp-42DCh]@11
  char v7097; // [sp+AD70h] [bp-42C4h]@11
  char v7098; // [sp+AD88h] [bp-42ACh]@11
  char v7099; // [sp+ADA0h] [bp-4294h]@11
  char v7100; // [sp+ADB8h] [bp-427Ch]@11
  char v7101; // [sp+ADD0h] [bp-4264h]@11
  char v7102; // [sp+ADE8h] [bp-424Ch]@11
  char v7103; // [sp+AE00h] [bp-4234h]@11
  char v7104; // [sp+AE18h] [bp-421Ch]@11
  char v7105; // [sp+AE30h] [bp-4204h]@11
  char v7106; // [sp+AE48h] [bp-41ECh]@11
  char v7107; // [sp+AE60h] [bp-41D4h]@11
  char v7108; // [sp+AE78h] [bp-41BCh]@11
  char v7109; // [sp+AE90h] [bp-41A4h]@11
  char v7110; // [sp+AEA8h] [bp-418Ch]@11
  char v7111; // [sp+AEC0h] [bp-4174h]@11
  char v7112; // [sp+AED8h] [bp-415Ch]@11
  char v7113; // [sp+AEF0h] [bp-4144h]@11
  char v7114; // [sp+AF08h] [bp-412Ch]@11
  char v7115; // [sp+AF20h] [bp-4114h]@11
  char v7116; // [sp+AF38h] [bp-40FCh]@11
  char v7117; // [sp+AF50h] [bp-40E4h]@11
  char v7118; // [sp+AF68h] [bp-40CCh]@11
  char v7119; // [sp+AF80h] [bp-40B4h]@11
  char v7120; // [sp+AF98h] [bp-409Ch]@11
  char v7121; // [sp+AFB0h] [bp-4084h]@11
  char v7122; // [sp+AFC8h] [bp-406Ch]@11
  char v7123; // [sp+AFE0h] [bp-4054h]@11
  char v7124; // [sp+AFF8h] [bp-403Ch]@11
  char v7125; // [sp+B010h] [bp-4024h]@11
  char v7126; // [sp+B028h] [bp-400Ch]@11
  char v7127; // [sp+B040h] [bp-3FF4h]@11
  char v7128; // [sp+B058h] [bp-3FDCh]@11
  char v7129; // [sp+B070h] [bp-3FC4h]@11
  char v7130; // [sp+B088h] [bp-3FACh]@11
  char v7131; // [sp+B0A0h] [bp-3F94h]@11
  char v7132; // [sp+B0B8h] [bp-3F7Ch]@11
  char v7133; // [sp+B0D0h] [bp-3F64h]@11
  char v7134; // [sp+B0E8h] [bp-3F4Ch]@11
  char v7135; // [sp+B100h] [bp-3F34h]@11
  char v7136; // [sp+B118h] [bp-3F1Ch]@11
  char v7137; // [sp+B130h] [bp-3F04h]@11
  char v7138; // [sp+B148h] [bp-3EECh]@11
  char v7139; // [sp+B160h] [bp-3ED4h]@11
  char v7140; // [sp+B178h] [bp-3EBCh]@11
  char v7141; // [sp+B190h] [bp-3EA4h]@11
  char v7142; // [sp+B1A8h] [bp-3E8Ch]@11
  char v7143; // [sp+B1C0h] [bp-3E74h]@11
  char v7144; // [sp+B1D8h] [bp-3E5Ch]@11
  char v7145; // [sp+B1F0h] [bp-3E44h]@11
  char v7146; // [sp+B208h] [bp-3E2Ch]@11
  char v7147; // [sp+B220h] [bp-3E14h]@11
  char v7148; // [sp+B238h] [bp-3DFCh]@11
  char v7149; // [sp+B250h] [bp-3DE4h]@11
  char v7150; // [sp+B268h] [bp-3DCCh]@11
  char v7151; // [sp+B280h] [bp-3DB4h]@11
  char v7152; // [sp+B298h] [bp-3D9Ch]@11
  char v7153; // [sp+B2B0h] [bp-3D84h]@11
  char v7154; // [sp+B2C8h] [bp-3D6Ch]@11
  char v7155; // [sp+B2E0h] [bp-3D54h]@11
  char v7156; // [sp+B2F8h] [bp-3D3Ch]@11
  char v7157; // [sp+B310h] [bp-3D24h]@11
  char v7158; // [sp+B328h] [bp-3D0Ch]@11
  char v7159; // [sp+B340h] [bp-3CF4h]@11
  char v7160; // [sp+B358h] [bp-3CDCh]@11
  char v7161; // [sp+B370h] [bp-3CC4h]@11
  char v7162; // [sp+B388h] [bp-3CACh]@11
  char v7163; // [sp+B3A0h] [bp-3C94h]@11
  char v7164; // [sp+B3B8h] [bp-3C7Ch]@11
  char v7165; // [sp+B3D0h] [bp-3C64h]@11
  char v7166; // [sp+B3E8h] [bp-3C4Ch]@11
  char v7167; // [sp+B400h] [bp-3C34h]@11
  char v7168; // [sp+B418h] [bp-3C1Ch]@11
  char v7169; // [sp+B430h] [bp-3C04h]@11
  char v7170; // [sp+B448h] [bp-3BECh]@11
  char v7171; // [sp+B460h] [bp-3BD4h]@11
  char v7172; // [sp+B478h] [bp-3BBCh]@11
  char v7173; // [sp+B490h] [bp-3BA4h]@11
  char v7174; // [sp+B4A8h] [bp-3B8Ch]@11
  char v7175; // [sp+B4C0h] [bp-3B74h]@11
  char v7176; // [sp+B4D8h] [bp-3B5Ch]@11
  char v7177; // [sp+B4F0h] [bp-3B44h]@11
  char v7178; // [sp+B508h] [bp-3B2Ch]@11
  char v7179; // [sp+B520h] [bp-3B14h]@11
  char v7180; // [sp+B538h] [bp-3AFCh]@11
  char v7181; // [sp+B550h] [bp-3AE4h]@11
  char v7182; // [sp+B568h] [bp-3ACCh]@11
  char v7183; // [sp+B580h] [bp-3AB4h]@11
  char v7184; // [sp+B598h] [bp-3A9Ch]@11
  char v7185; // [sp+B5B0h] [bp-3A84h]@11
  char v7186; // [sp+B5C8h] [bp-3A6Ch]@11
  char v7187; // [sp+B5E0h] [bp-3A54h]@11
  char v7188; // [sp+B5F8h] [bp-3A3Ch]@11
  char v7189; // [sp+B610h] [bp-3A24h]@11
  char v7190; // [sp+B628h] [bp-3A0Ch]@11
  char v7191; // [sp+B640h] [bp-39F4h]@11
  char v7192; // [sp+B658h] [bp-39DCh]@11
  char v7193; // [sp+B670h] [bp-39C4h]@11
  char v7194; // [sp+B688h] [bp-39ACh]@11
  char v7195; // [sp+B6A0h] [bp-3994h]@11
  char v7196; // [sp+B6B8h] [bp-397Ch]@11
  char v7197; // [sp+B6D0h] [bp-3964h]@11
  char v7198; // [sp+B6E8h] [bp-394Ch]@11
  char v7199; // [sp+B700h] [bp-3934h]@11
  char v7200; // [sp+B718h] [bp-391Ch]@11
  char v7201; // [sp+B730h] [bp-3904h]@11
  char v7202; // [sp+B748h] [bp-38ECh]@11
  char v7203; // [sp+B760h] [bp-38D4h]@11
  char v7204; // [sp+B778h] [bp-38BCh]@11
  char v7205; // [sp+B790h] [bp-38A4h]@11
  char v7206; // [sp+B7A8h] [bp-388Ch]@11
  char v7207; // [sp+B7C0h] [bp-3874h]@11
  char v7208; // [sp+B7D8h] [bp-385Ch]@11
  char v7209; // [sp+B7F0h] [bp-3844h]@11
  char v7210; // [sp+B808h] [bp-382Ch]@11
  char v7211; // [sp+B820h] [bp-3814h]@11
  char v7212; // [sp+B838h] [bp-37FCh]@11
  char v7213; // [sp+B850h] [bp-37E4h]@11
  char v7214; // [sp+B868h] [bp-37CCh]@11
  char v7215; // [sp+B880h] [bp-37B4h]@11
  char v7216; // [sp+B898h] [bp-379Ch]@11
  char v7217; // [sp+B8B0h] [bp-3784h]@11
  char v7218; // [sp+B8C8h] [bp-376Ch]@11
  char v7219; // [sp+B8E0h] [bp-3754h]@11
  char v7220; // [sp+B8F8h] [bp-373Ch]@11
  char v7221; // [sp+B910h] [bp-3724h]@11
  char v7222; // [sp+B928h] [bp-370Ch]@11
  char v7223; // [sp+B940h] [bp-36F4h]@11
  char v7224; // [sp+B958h] [bp-36DCh]@11
  char v7225; // [sp+B970h] [bp-36C4h]@11
  char v7226; // [sp+B988h] [bp-36ACh]@11
  char v7227; // [sp+B9A0h] [bp-3694h]@11
  char v7228; // [sp+B9B8h] [bp-367Ch]@11
  char v7229; // [sp+B9D0h] [bp-3664h]@11
  char v7230; // [sp+B9E8h] [bp-364Ch]@11
  char v7231; // [sp+BA00h] [bp-3634h]@11
  char v7232; // [sp+BA18h] [bp-361Ch]@11
  char v7233; // [sp+BA30h] [bp-3604h]@11
  char v7234; // [sp+BA48h] [bp-35ECh]@11
  char v7235; // [sp+BA60h] [bp-35D4h]@11
  char v7236; // [sp+BA78h] [bp-35BCh]@11
  char v7237; // [sp+BA90h] [bp-35A4h]@11
  char v7238; // [sp+BAA8h] [bp-358Ch]@11
  char v7239; // [sp+BAC0h] [bp-3574h]@11
  char v7240; // [sp+BAD8h] [bp-355Ch]@11
  char v7241; // [sp+BAF0h] [bp-3544h]@11
  char v7242; // [sp+BB08h] [bp-352Ch]@11
  char v7243; // [sp+BB20h] [bp-3514h]@11
  char v7244; // [sp+BB38h] [bp-34FCh]@11
  char v7245; // [sp+BB50h] [bp-34E4h]@11
  char v7246; // [sp+BB68h] [bp-34CCh]@11
  char v7247; // [sp+BB80h] [bp-34B4h]@11
  char v7248; // [sp+BB98h] [bp-349Ch]@11
  char v7249; // [sp+BBB0h] [bp-3484h]@11
  char v7250; // [sp+BBC8h] [bp-346Ch]@11
  char v7251; // [sp+BBE0h] [bp-3454h]@11
  char v7252; // [sp+BBF8h] [bp-343Ch]@11
  char v7253; // [sp+BC10h] [bp-3424h]@11
  char v7254; // [sp+BC28h] [bp-340Ch]@11
  char v7255; // [sp+BC40h] [bp-33F4h]@11
  char v7256; // [sp+BC58h] [bp-33DCh]@11
  char v7257; // [sp+BC70h] [bp-33C4h]@11
  char v7258; // [sp+BC88h] [bp-33ACh]@11
  char v7259; // [sp+BCA0h] [bp-3394h]@11
  char v7260; // [sp+BCB8h] [bp-337Ch]@11
  char v7261; // [sp+BCD0h] [bp-3364h]@11
  char v7262; // [sp+BCE8h] [bp-334Ch]@11
  char v7263; // [sp+BD00h] [bp-3334h]@11
  char v7264; // [sp+BD18h] [bp-331Ch]@11
  char v7265; // [sp+BD30h] [bp-3304h]@11
  char v7266; // [sp+BD48h] [bp-32ECh]@11
  char v7267; // [sp+BD60h] [bp-32D4h]@11
  char v7268; // [sp+BD78h] [bp-32BCh]@11
  char v7269; // [sp+BD90h] [bp-32A4h]@11
  char v7270; // [sp+BDA8h] [bp-328Ch]@11
  char v7271; // [sp+BDC0h] [bp-3274h]@11
  char v7272; // [sp+BDD8h] [bp-325Ch]@11
  char v7273; // [sp+BDF0h] [bp-3244h]@11
  char v7274; // [sp+BE08h] [bp-322Ch]@11
  char v7275; // [sp+BE20h] [bp-3214h]@11
  char v7276; // [sp+BE38h] [bp-31FCh]@11
  char v7277; // [sp+BE50h] [bp-31E4h]@11
  char v7278; // [sp+BE68h] [bp-31CCh]@11
  char v7279; // [sp+BE80h] [bp-31B4h]@11
  char v7280; // [sp+BE98h] [bp-319Ch]@11
  char v7281; // [sp+BEB0h] [bp-3184h]@11
  char v7282; // [sp+BEC8h] [bp-316Ch]@11
  char v7283; // [sp+BEE0h] [bp-3154h]@11
  char v7284; // [sp+BEF8h] [bp-313Ch]@11
  char v7285; // [sp+BF10h] [bp-3124h]@11
  char v7286; // [sp+BF28h] [bp-310Ch]@11
  char v7287; // [sp+BF40h] [bp-30F4h]@11
  char v7288; // [sp+BF58h] [bp-30DCh]@11
  char v7289; // [sp+BF70h] [bp-30C4h]@11
  char v7290; // [sp+BF88h] [bp-30ACh]@11
  char v7291; // [sp+BFA0h] [bp-3094h]@11
  char v7292; // [sp+BFB8h] [bp-307Ch]@11
  char v7293; // [sp+BFD0h] [bp-3064h]@11
  char v7294; // [sp+BFE8h] [bp-304Ch]@11
  char v7295; // [sp+C000h] [bp-3034h]@11
  char v7296; // [sp+C018h] [bp-301Ch]@11
  char v7297; // [sp+C030h] [bp-3004h]@11
  char v7298; // [sp+C048h] [bp-2FECh]@11
  char v7299; // [sp+C060h] [bp-2FD4h]@11
  char v7300; // [sp+C078h] [bp-2FBCh]@11
  char v7301; // [sp+C090h] [bp-2FA4h]@11
  char v7302; // [sp+C0A8h] [bp-2F8Ch]@11
  char v7303; // [sp+C0C0h] [bp-2F74h]@11
  char v7304; // [sp+C0D8h] [bp-2F5Ch]@11
  char v7305; // [sp+C0F0h] [bp-2F44h]@11
  char v7306; // [sp+C108h] [bp-2F2Ch]@11
  char v7307; // [sp+C120h] [bp-2F14h]@11
  char v7308; // [sp+C138h] [bp-2EFCh]@11
  char v7309; // [sp+C150h] [bp-2EE4h]@11
  char v7310; // [sp+C168h] [bp-2ECCh]@11
  char v7311; // [sp+C180h] [bp-2EB4h]@11
  char v7312; // [sp+C198h] [bp-2E9Ch]@11
  char v7313; // [sp+C1B0h] [bp-2E84h]@11
  char v7314; // [sp+C1C8h] [bp-2E6Ch]@11
  char v7315; // [sp+C1E0h] [bp-2E54h]@11
  char v7316; // [sp+C1F8h] [bp-2E3Ch]@11
  char v7317; // [sp+C210h] [bp-2E24h]@11
  char v7318; // [sp+C228h] [bp-2E0Ch]@11
  char v7319; // [sp+C240h] [bp-2DF4h]@11
  char v7320; // [sp+C258h] [bp-2DDCh]@11
  char v7321; // [sp+C270h] [bp-2DC4h]@11
  char v7322; // [sp+C288h] [bp-2DACh]@11
  char v7323; // [sp+C2A0h] [bp-2D94h]@11
  char v7324; // [sp+C2B8h] [bp-2D7Ch]@11
  char v7325; // [sp+C2D0h] [bp-2D64h]@11
  char v7326; // [sp+C2E8h] [bp-2D4Ch]@11
  char v7327; // [sp+C300h] [bp-2D34h]@11
  char v7328; // [sp+C318h] [bp-2D1Ch]@11
  char v7329; // [sp+C330h] [bp-2D04h]@11
  char v7330; // [sp+C348h] [bp-2CECh]@11
  char v7331; // [sp+C360h] [bp-2CD4h]@11
  char v7332; // [sp+C378h] [bp-2CBCh]@11
  char v7333; // [sp+C390h] [bp-2CA4h]@11
  char v7334; // [sp+C3A8h] [bp-2C8Ch]@11
  char v7335; // [sp+C3C0h] [bp-2C74h]@11
  char v7336; // [sp+C3D8h] [bp-2C5Ch]@11
  char v7337; // [sp+C3F0h] [bp-2C44h]@11
  char v7338; // [sp+C408h] [bp-2C2Ch]@11
  char v7339; // [sp+C420h] [bp-2C14h]@11
  char v7340; // [sp+C438h] [bp-2BFCh]@11
  char v7341; // [sp+C450h] [bp-2BE4h]@11
  char v7342; // [sp+C468h] [bp-2BCCh]@11
  char v7343; // [sp+C480h] [bp-2BB4h]@11
  char v7344; // [sp+C498h] [bp-2B9Ch]@11
  char v7345; // [sp+C4B0h] [bp-2B84h]@11
  char v7346; // [sp+C4C8h] [bp-2B6Ch]@11
  char v7347; // [sp+C4E0h] [bp-2B54h]@11
  char v7348; // [sp+C4F8h] [bp-2B3Ch]@11
  char v7349; // [sp+C510h] [bp-2B24h]@11
  char v7350; // [sp+C528h] [bp-2B0Ch]@11
  char v7351; // [sp+C540h] [bp-2AF4h]@11
  char v7352; // [sp+C558h] [bp-2ADCh]@11
  char v7353; // [sp+C570h] [bp-2AC4h]@11
  char v7354; // [sp+C588h] [bp-2AACh]@11
  char v7355; // [sp+C5A0h] [bp-2A94h]@11
  char v7356; // [sp+C5B8h] [bp-2A7Ch]@11
  char v7357; // [sp+C5D0h] [bp-2A64h]@11
  char v7358; // [sp+C5E8h] [bp-2A4Ch]@11
  char v7359; // [sp+C600h] [bp-2A34h]@11
  char v7360; // [sp+C618h] [bp-2A1Ch]@11
  char v7361; // [sp+C630h] [bp-2A04h]@11
  char v7362; // [sp+C648h] [bp-29ECh]@11
  char v7363; // [sp+C660h] [bp-29D4h]@11
  char v7364; // [sp+C678h] [bp-29BCh]@11
  char v7365; // [sp+C690h] [bp-29A4h]@11
  char v7366; // [sp+C6A8h] [bp-298Ch]@11
  char v7367; // [sp+C6C0h] [bp-2974h]@11
  char v7368; // [sp+C6D8h] [bp-295Ch]@11
  char v7369; // [sp+C6F0h] [bp-2944h]@11
  char v7370; // [sp+C708h] [bp-292Ch]@11
  char v7371; // [sp+C720h] [bp-2914h]@11
  char v7372; // [sp+C738h] [bp-28FCh]@11
  char v7373; // [sp+C750h] [bp-28E4h]@11
  char v7374; // [sp+C768h] [bp-28CCh]@11
  char v7375; // [sp+C780h] [bp-28B4h]@11
  char v7376; // [sp+C798h] [bp-289Ch]@11
  char v7377; // [sp+C7B0h] [bp-2884h]@11
  char v7378; // [sp+C7C8h] [bp-286Ch]@11
  char v7379; // [sp+C7E0h] [bp-2854h]@11
  char v7380; // [sp+C7F8h] [bp-283Ch]@11
  char v7381; // [sp+C810h] [bp-2824h]@11
  char v7382; // [sp+C828h] [bp-280Ch]@11
  char v7383; // [sp+C840h] [bp-27F4h]@11
  char v7384; // [sp+C858h] [bp-27DCh]@11
  char v7385; // [sp+C870h] [bp-27C4h]@11
  char v7386; // [sp+C888h] [bp-27ACh]@11
  char v7387; // [sp+C8A0h] [bp-2794h]@11
  char v7388; // [sp+C8B8h] [bp-277Ch]@11
  char v7389; // [sp+C8D0h] [bp-2764h]@11
  char v7390; // [sp+C8E8h] [bp-274Ch]@11
  char v7391; // [sp+C900h] [bp-2734h]@11
  char v7392; // [sp+C918h] [bp-271Ch]@11
  char v7393; // [sp+C930h] [bp-2704h]@11
  char v7394; // [sp+C948h] [bp-26ECh]@11
  char v7395; // [sp+C960h] [bp-26D4h]@11
  char v7396; // [sp+C978h] [bp-26BCh]@11
  char v7397; // [sp+C990h] [bp-26A4h]@11
  char v7398; // [sp+C9A8h] [bp-268Ch]@11
  char v7399; // [sp+C9C0h] [bp-2674h]@11
  char v7400; // [sp+C9D8h] [bp-265Ch]@11
  char v7401; // [sp+C9F0h] [bp-2644h]@11
  char v7402; // [sp+CA08h] [bp-262Ch]@11
  char v7403; // [sp+CA20h] [bp-2614h]@11
  char v7404; // [sp+CA38h] [bp-25FCh]@11
  char v7405; // [sp+CA50h] [bp-25E4h]@11
  char v7406; // [sp+CA68h] [bp-25CCh]@11
  char v7407; // [sp+CA80h] [bp-25B4h]@11
  char v7408; // [sp+CA98h] [bp-259Ch]@11
  char v7409; // [sp+CAB0h] [bp-2584h]@11
  char v7410; // [sp+CAC8h] [bp-256Ch]@11
  char v7411; // [sp+CAE0h] [bp-2554h]@11
  char v7412; // [sp+CAF8h] [bp-253Ch]@11
  char v7413; // [sp+CB10h] [bp-2524h]@11
  char v7414; // [sp+CB28h] [bp-250Ch]@11
  char v7415; // [sp+CB40h] [bp-24F4h]@11
  char v7416; // [sp+CB58h] [bp-24DCh]@11
  char v7417; // [sp+CB70h] [bp-24C4h]@11
  char v7418; // [sp+CB88h] [bp-24ACh]@11
  char v7419; // [sp+CBA0h] [bp-2494h]@11
  char v7420; // [sp+CBB8h] [bp-247Ch]@11
  char v7421; // [sp+CBD0h] [bp-2464h]@11
  char v7422; // [sp+CBE8h] [bp-244Ch]@11
  char v7423; // [sp+CC00h] [bp-2434h]@11
  char v7424; // [sp+CC18h] [bp-241Ch]@11
  char v7425; // [sp+CC30h] [bp-2404h]@11
  char v7426; // [sp+CC48h] [bp-23ECh]@11
  char v7427; // [sp+CC60h] [bp-23D4h]@11
  char v7428; // [sp+CC78h] [bp-23BCh]@11
  char v7429; // [sp+CC90h] [bp-23A4h]@11
  char v7430; // [sp+CCA8h] [bp-238Ch]@11
  char v7431; // [sp+CCC0h] [bp-2374h]@11
  char v7432; // [sp+CCD8h] [bp-235Ch]@11
  char v7433; // [sp+CCF0h] [bp-2344h]@11
  char v7434; // [sp+CD08h] [bp-232Ch]@11
  char v7435; // [sp+CD20h] [bp-2314h]@11
  char v7436; // [sp+CD38h] [bp-22FCh]@11
  char v7437; // [sp+CD50h] [bp-22E4h]@11
  char v7438; // [sp+CD68h] [bp-22CCh]@11
  char v7439; // [sp+CD80h] [bp-22B4h]@11
  char v7440; // [sp+CD98h] [bp-229Ch]@11
  char v7441; // [sp+CDB0h] [bp-2284h]@11
  char v7442; // [sp+CDC8h] [bp-226Ch]@11
  char v7443; // [sp+CDE0h] [bp-2254h]@11
  char v7444; // [sp+CDF8h] [bp-223Ch]@11
  char v7445; // [sp+CE10h] [bp-2224h]@11
  char v7446; // [sp+CE28h] [bp-220Ch]@11
  char v7447; // [sp+CE40h] [bp-21F4h]@11
  char v7448; // [sp+CE58h] [bp-21DCh]@11
  char v7449; // [sp+CE70h] [bp-21C4h]@11
  char v7450; // [sp+CE88h] [bp-21ACh]@11
  char v7451; // [sp+CEA0h] [bp-2194h]@11
  char v7452; // [sp+CEB8h] [bp-217Ch]@11
  char v7453; // [sp+CED0h] [bp-2164h]@11
  char v7454; // [sp+CEE8h] [bp-214Ch]@11
  char v7455; // [sp+CF00h] [bp-2134h]@11
  char v7456; // [sp+CF18h] [bp-211Ch]@11
  char v7457; // [sp+CF30h] [bp-2104h]@11
  char v7458; // [sp+CF48h] [bp-20ECh]@11
  char v7459; // [sp+CF60h] [bp-20D4h]@11
  char v7460; // [sp+CF78h] [bp-20BCh]@11
  char v7461; // [sp+CF90h] [bp-20A4h]@11
  char v7462; // [sp+CFA8h] [bp-208Ch]@11
  char v7463; // [sp+CFC0h] [bp-2074h]@11
  char v7464; // [sp+CFD8h] [bp-205Ch]@11
  char v7465; // [sp+CFF0h] [bp-2044h]@11
  char v7466; // [sp+D008h] [bp-202Ch]@11
  char v7467; // [sp+D020h] [bp-2014h]@11
  char v7468; // [sp+D038h] [bp-1FFCh]@11
  char v7469; // [sp+D050h] [bp-1FE4h]@11
  char v7470; // [sp+D068h] [bp-1FCCh]@11
  char v7471; // [sp+D080h] [bp-1FB4h]@11
  char v7472; // [sp+D098h] [bp-1F9Ch]@11
  char v7473; // [sp+D0B0h] [bp-1F84h]@11
  char v7474; // [sp+D0C8h] [bp-1F6Ch]@11
  char v7475; // [sp+D0E0h] [bp-1F54h]@11
  char v7476; // [sp+D0F8h] [bp-1F3Ch]@11
  char v7477; // [sp+D110h] [bp-1F24h]@11
  char v7478; // [sp+D128h] [bp-1F0Ch]@11
  char v7479; // [sp+D140h] [bp-1EF4h]@11
  char v7480; // [sp+D158h] [bp-1EDCh]@11
  char v7481; // [sp+D170h] [bp-1EC4h]@11
  char v7482; // [sp+D188h] [bp-1EACh]@11
  char v7483; // [sp+D1A0h] [bp-1E94h]@11
  char v7484; // [sp+D1B8h] [bp-1E7Ch]@11
  char v7485; // [sp+D1D0h] [bp-1E64h]@11
  char v7486; // [sp+D1E8h] [bp-1E4Ch]@11
  char v7487; // [sp+D200h] [bp-1E34h]@11
  char v7488; // [sp+D218h] [bp-1E1Ch]@11
  char v7489; // [sp+D230h] [bp-1E04h]@11
  char v7490; // [sp+D248h] [bp-1DECh]@11
  char v7491; // [sp+D260h] [bp-1DD4h]@11
  char v7492; // [sp+D278h] [bp-1DBCh]@11
  char v7493; // [sp+D290h] [bp-1DA4h]@11
  char v7494; // [sp+D2A8h] [bp-1D8Ch]@11
  char v7495; // [sp+D2C0h] [bp-1D74h]@11
  char v7496; // [sp+D2D8h] [bp-1D5Ch]@11
  char v7497; // [sp+D2F0h] [bp-1D44h]@11
  char v7498; // [sp+D308h] [bp-1D2Ch]@11
  char v7499; // [sp+D320h] [bp-1D14h]@11
  char v7500; // [sp+D338h] [bp-1CFCh]@11
  char v7501; // [sp+D350h] [bp-1CE4h]@11
  char v7502; // [sp+D368h] [bp-1CCCh]@11
  char v7503; // [sp+D380h] [bp-1CB4h]@11
  char v7504; // [sp+D398h] [bp-1C9Ch]@11
  char v7505; // [sp+D3B0h] [bp-1C84h]@11
  char v7506; // [sp+D3C8h] [bp-1C6Ch]@11
  char v7507; // [sp+D3E0h] [bp-1C54h]@11
  char v7508; // [sp+D3F8h] [bp-1C3Ch]@11
  char v7509; // [sp+D410h] [bp-1C24h]@11
  char v7510; // [sp+D428h] [bp-1C0Ch]@11
  char v7511; // [sp+D440h] [bp-1BF4h]@11
  char v7512; // [sp+D458h] [bp-1BDCh]@11
  char v7513; // [sp+D470h] [bp-1BC4h]@11
  char v7514; // [sp+D488h] [bp-1BACh]@11
  char v7515; // [sp+D4A0h] [bp-1B94h]@11
  char v7516; // [sp+D4B8h] [bp-1B7Ch]@11
  char v7517; // [sp+D4D0h] [bp-1B64h]@11
  char v7518; // [sp+D4E8h] [bp-1B4Ch]@11
  char v7519; // [sp+D500h] [bp-1B34h]@11
  char v7520; // [sp+D518h] [bp-1B1Ch]@11
  char v7521; // [sp+D530h] [bp-1B04h]@11
  char v7522; // [sp+D548h] [bp-1AECh]@11
  char v7523; // [sp+D560h] [bp-1AD4h]@11
  char v7524; // [sp+D578h] [bp-1ABCh]@11
  char v7525; // [sp+D590h] [bp-1AA4h]@11
  char v7526; // [sp+D5A8h] [bp-1A8Ch]@11
  char v7527; // [sp+D5C0h] [bp-1A74h]@11
  char v7528; // [sp+D5D8h] [bp-1A5Ch]@11
  char v7529; // [sp+D5F0h] [bp-1A44h]@11
  char v7530; // [sp+D608h] [bp-1A2Ch]@11
  char v7531; // [sp+D620h] [bp-1A14h]@11
  char v7532; // [sp+D638h] [bp-19FCh]@11
  char v7533; // [sp+D650h] [bp-19E4h]@11
  char v7534; // [sp+D668h] [bp-19CCh]@11
  char v7535; // [sp+D680h] [bp-19B4h]@11
  char v7536; // [sp+D698h] [bp-199Ch]@11
  char v7537; // [sp+D6B0h] [bp-1984h]@11
  char v7538; // [sp+D6C8h] [bp-196Ch]@11
  char v7539; // [sp+D6E0h] [bp-1954h]@11
  char v7540; // [sp+D6F8h] [bp-193Ch]@11
  char v7541; // [sp+D710h] [bp-1924h]@11
  char v7542; // [sp+D728h] [bp-190Ch]@11
  char v7543; // [sp+D740h] [bp-18F4h]@11
  char v7544; // [sp+D758h] [bp-18DCh]@11
  char v7545; // [sp+D770h] [bp-18C4h]@11
  char v7546; // [sp+D788h] [bp-18ACh]@11
  char v7547; // [sp+D7A0h] [bp-1894h]@11
  char v7548; // [sp+D7B8h] [bp-187Ch]@11
  char v7549; // [sp+D7D0h] [bp-1864h]@11
  char v7550; // [sp+D7E8h] [bp-184Ch]@11
  char v7551; // [sp+D800h] [bp-1834h]@11
  char v7552; // [sp+D818h] [bp-181Ch]@11
  char v7553; // [sp+D830h] [bp-1804h]@11
  char v7554; // [sp+D848h] [bp-17ECh]@11
  char v7555; // [sp+D860h] [bp-17D4h]@11
  char v7556; // [sp+D878h] [bp-17BCh]@11
  char v7557; // [sp+D890h] [bp-17A4h]@11
  char v7558; // [sp+D8A8h] [bp-178Ch]@11
  char v7559; // [sp+D8C0h] [bp-1774h]@11
  char v7560; // [sp+D8D8h] [bp-175Ch]@11
  char v7561; // [sp+D8F0h] [bp-1744h]@11
  char v7562; // [sp+D908h] [bp-172Ch]@11
  char v7563; // [sp+D920h] [bp-1714h]@11
  char v7564; // [sp+D938h] [bp-16FCh]@11
  char v7565; // [sp+D950h] [bp-16E4h]@11
  char v7566; // [sp+D968h] [bp-16CCh]@11
  char v7567; // [sp+D980h] [bp-16B4h]@11
  char v7568; // [sp+D998h] [bp-169Ch]@11
  char v7569; // [sp+D9B0h] [bp-1684h]@11
  char v7570; // [sp+D9C8h] [bp-166Ch]@11
  char v7571; // [sp+D9E0h] [bp-1654h]@11
  char v7572; // [sp+D9F8h] [bp-163Ch]@11
  char v7573; // [sp+DA10h] [bp-1624h]@11
  char v7574; // [sp+DA28h] [bp-160Ch]@11
  char v7575; // [sp+DA40h] [bp-15F4h]@11
  char v7576; // [sp+DA58h] [bp-15DCh]@11
  char v7577; // [sp+DA70h] [bp-15C4h]@11
  char v7578; // [sp+DA88h] [bp-15ACh]@11
  char v7579; // [sp+DAA0h] [bp-1594h]@11
  char v7580; // [sp+DAB8h] [bp-157Ch]@11
  char v7581; // [sp+DAD0h] [bp-1564h]@11
  char v7582; // [sp+DAE8h] [bp-154Ch]@11
  char v7583; // [sp+DB00h] [bp-1534h]@11
  char v7584; // [sp+DB18h] [bp-151Ch]@11
  char v7585; // [sp+DB30h] [bp-1504h]@11
  char v7586; // [sp+DB48h] [bp-14ECh]@11
  char v7587; // [sp+DB60h] [bp-14D4h]@11
  char v7588; // [sp+DB78h] [bp-14BCh]@11
  char v7589; // [sp+DB90h] [bp-14A4h]@11
  char v7590; // [sp+DBA8h] [bp-148Ch]@11
  char v7591; // [sp+DBC0h] [bp-1474h]@11
  char v7592; // [sp+DBD8h] [bp-145Ch]@11
  char v7593; // [sp+DBF0h] [bp-1444h]@11
  char v7594; // [sp+DC08h] [bp-142Ch]@11
  char v7595; // [sp+DC20h] [bp-1414h]@11
  char v7596; // [sp+DC38h] [bp-13FCh]@11
  char v7597; // [sp+DC50h] [bp-13E4h]@11
  char v7598; // [sp+DC68h] [bp-13CCh]@11
  char v7599; // [sp+DC80h] [bp-13B4h]@11
  char v7600; // [sp+DC98h] [bp-139Ch]@11
  char v7601; // [sp+DCB0h] [bp-1384h]@11
  char v7602; // [sp+DCC8h] [bp-136Ch]@11
  char v7603; // [sp+DCE0h] [bp-1354h]@11
  char v7604; // [sp+DCF8h] [bp-133Ch]@11
  char v7605; // [sp+DD10h] [bp-1324h]@11
  char v7606; // [sp+DD28h] [bp-130Ch]@11
  char v7607; // [sp+DD40h] [bp-12F4h]@11
  char v7608; // [sp+DD58h] [bp-12DCh]@11
  char v7609; // [sp+DD70h] [bp-12C4h]@11
  char v7610; // [sp+DD88h] [bp-12ACh]@11
  char v7611; // [sp+DDA0h] [bp-1294h]@11
  char v7612; // [sp+DDB8h] [bp-127Ch]@11
  char v7613; // [sp+DDD0h] [bp-1264h]@11
  char v7614; // [sp+DDE8h] [bp-124Ch]@11
  char v7615; // [sp+DE00h] [bp-1234h]@11
  char v7616; // [sp+DE18h] [bp-121Ch]@11
  char v7617; // [sp+DE30h] [bp-1204h]@11
  char v7618; // [sp+DE48h] [bp-11ECh]@11
  char v7619; // [sp+DE60h] [bp-11D4h]@11
  char v7620; // [sp+DE78h] [bp-11BCh]@11
  char v7621; // [sp+DE90h] [bp-11A4h]@11
  char v7622; // [sp+DEA8h] [bp-118Ch]@11
  char v7623; // [sp+DEC0h] [bp-1174h]@11
  char v7624; // [sp+DED8h] [bp-115Ch]@11
  char v7625; // [sp+DEF0h] [bp-1144h]@11
  char v7626; // [sp+DF08h] [bp-112Ch]@11
  char v7627; // [sp+DF20h] [bp-1114h]@11
  char v7628; // [sp+DF38h] [bp-10FCh]@11
  char v7629; // [sp+DF50h] [bp-10E4h]@11
  char v7630; // [sp+DF68h] [bp-10CCh]@11
  char v7631; // [sp+DF80h] [bp-10B4h]@11
  char v7632; // [sp+DF98h] [bp-109Ch]@11
  char v7633; // [sp+DFB0h] [bp-1084h]@11
  char v7634; // [sp+DFC8h] [bp-106Ch]@11
  char v7635; // [sp+DFE0h] [bp-1054h]@11
  char v7636; // [sp+DFF8h] [bp-103Ch]@11
  char v7637; // [sp+E010h] [bp-1024h]@11
  char v7638; // [sp+E028h] [bp-100Ch]@11
  char v7639; // [sp+E040h] [bp-FF4h]@11
  char v7640; // [sp+E058h] [bp-FDCh]@11
  char v7641; // [sp+E070h] [bp-FC4h]@11
  char v7642; // [sp+E088h] [bp-FACh]@11
  char v7643; // [sp+E0A0h] [bp-F94h]@11
  char v7644; // [sp+E0B8h] [bp-F7Ch]@11
  char v7645; // [sp+E0D0h] [bp-F64h]@11
  char v7646; // [sp+E0E8h] [bp-F4Ch]@11
  char v7647; // [sp+E100h] [bp-F34h]@11
  char v7648; // [sp+E118h] [bp-F1Ch]@11
  char v7649; // [sp+E130h] [bp-F04h]@11
  char v7650; // [sp+E148h] [bp-EECh]@11
  char v7651; // [sp+E160h] [bp-ED4h]@11
  char v7652; // [sp+E178h] [bp-EBCh]@11
  char v7653; // [sp+E190h] [bp-EA4h]@11
  char v7654; // [sp+E1A8h] [bp-E8Ch]@11
  char v7655; // [sp+E1C0h] [bp-E74h]@11
  char v7656; // [sp+E1D8h] [bp-E5Ch]@11
  char v7657; // [sp+E1F0h] [bp-E44h]@11
  char v7658; // [sp+E208h] [bp-E2Ch]@11
  char v7659; // [sp+E220h] [bp-E14h]@11
  char v7660; // [sp+E238h] [bp-DFCh]@11
  char v7661; // [sp+E250h] [bp-DE4h]@11
  char v7662; // [sp+E268h] [bp-DCCh]@11
  char v7663; // [sp+E280h] [bp-DB4h]@11
  char v7664; // [sp+E298h] [bp-D9Ch]@11
  char v7665; // [sp+E2B0h] [bp-D84h]@11
  char v7666; // [sp+E2C8h] [bp-D6Ch]@11
  char v7667; // [sp+E2E0h] [bp-D54h]@11
  char v7668; // [sp+E2F8h] [bp-D3Ch]@11
  char v7669; // [sp+E310h] [bp-D24h]@11
  char v7670; // [sp+E328h] [bp-D0Ch]@11
  char v7671; // [sp+E340h] [bp-CF4h]@11
  char v7672; // [sp+E358h] [bp-CDCh]@11
  char v7673; // [sp+E370h] [bp-CC4h]@11
  char v7674; // [sp+E388h] [bp-CACh]@11
  char v7675; // [sp+E3A0h] [bp-C94h]@11
  char v7676; // [sp+E3B8h] [bp-C7Ch]@11
  char v7677; // [sp+E3D0h] [bp-C64h]@11
  char v7678; // [sp+E3E8h] [bp-C4Ch]@11
  char v7679; // [sp+E400h] [bp-C34h]@11
  char v7680; // [sp+E418h] [bp-C1Ch]@11
  char v7681; // [sp+E430h] [bp-C04h]@11
  char v7682; // [sp+E448h] [bp-BECh]@11
  char v7683; // [sp+E460h] [bp-BD4h]@11
  char v7684; // [sp+E478h] [bp-BBCh]@11
  char v7685; // [sp+E490h] [bp-BA4h]@11
  char v7686; // [sp+E4A8h] [bp-B8Ch]@11
  char v7687; // [sp+E4C0h] [bp-B74h]@11
  char v7688; // [sp+E4D8h] [bp-B5Ch]@11
  char v7689; // [sp+E4F0h] [bp-B44h]@11
  char v7690; // [sp+E508h] [bp-B2Ch]@11
  char v7691; // [sp+E520h] [bp-B14h]@11
  char v7692; // [sp+E538h] [bp-AFCh]@11
  char v7693; // [sp+E550h] [bp-AE4h]@11
  char v7694; // [sp+E568h] [bp-ACCh]@11
  char v7695; // [sp+E580h] [bp-AB4h]@11
  char v7696; // [sp+E598h] [bp-A9Ch]@11
  char v7697; // [sp+E5B0h] [bp-A84h]@11
  char v7698; // [sp+E5C8h] [bp-A6Ch]@11
  char v7699; // [sp+E5E0h] [bp-A54h]@11
  char v7700; // [sp+E5F8h] [bp-A3Ch]@11
  char v7701; // [sp+E610h] [bp-A24h]@11
  char v7702; // [sp+E628h] [bp-A0Ch]@11
  char v7703; // [sp+E640h] [bp-9F4h]@11
  char v7704; // [sp+E658h] [bp-9DCh]@11
  char v7705; // [sp+E670h] [bp-9C4h]@11
  char v7706; // [sp+E688h] [bp-9ACh]@11
  char v7707; // [sp+E6A0h] [bp-994h]@11
  char v7708; // [sp+E6B8h] [bp-97Ch]@11
  char v7709; // [sp+E6D0h] [bp-964h]@11
  char v7710; // [sp+E6E8h] [bp-94Ch]@11
  char v7711; // [sp+E700h] [bp-934h]@11
  char v7712; // [sp+E718h] [bp-91Ch]@11
  char v7713; // [sp+E730h] [bp-904h]@11
  char v7714; // [sp+E748h] [bp-8ECh]@11
  char v7715; // [sp+E760h] [bp-8D4h]@11
  char v7716; // [sp+E778h] [bp-8BCh]@11
  char v7717; // [sp+E790h] [bp-8A4h]@11
  char v7718; // [sp+E7A8h] [bp-88Ch]@11
  char v7719; // [sp+E7C0h] [bp-874h]@11
  char v7720; // [sp+E7D8h] [bp-85Ch]@11
  char v7721; // [sp+E7F0h] [bp-844h]@11
  char v7722; // [sp+E808h] [bp-82Ch]@11
  char v7723; // [sp+E820h] [bp-814h]@11
  char v7724; // [sp+E838h] [bp-7FCh]@11
  char v7725; // [sp+E850h] [bp-7E4h]@11
  char v7726; // [sp+E868h] [bp-7CCh]@11
  char v7727; // [sp+E880h] [bp-7B4h]@11
  char v7728; // [sp+E898h] [bp-79Ch]@11
  char v7729; // [sp+E8B0h] [bp-784h]@11
  char v7730; // [sp+E8C8h] [bp-76Ch]@11
  char v7731; // [sp+E8E0h] [bp-754h]@11
  char v7732; // [sp+E8F8h] [bp-73Ch]@11
  char v7733; // [sp+E910h] [bp-724h]@11
  char v7734; // [sp+E928h] [bp-70Ch]@11
  char v7735; // [sp+E940h] [bp-6F4h]@11
  char v7736; // [sp+E958h] [bp-6DCh]@11
  char v7737; // [sp+E970h] [bp-6C4h]@11
  char v7738; // [sp+E988h] [bp-6ACh]@11
  char v7739; // [sp+E9A0h] [bp-694h]@11
  char v7740; // [sp+E9B8h] [bp-67Ch]@11
  char v7741; // [sp+E9D0h] [bp-664h]@11
  char v7742; // [sp+E9E8h] [bp-64Ch]@11
  char v7743; // [sp+EA00h] [bp-634h]@11
  char v7744; // [sp+EA18h] [bp-61Ch]@11
  char v7745; // [sp+EA30h] [bp-604h]@11
  char v7746; // [sp+EA48h] [bp-5ECh]@11
  char v7747; // [sp+EA60h] [bp-5D4h]@11
  char v7748; // [sp+EA78h] [bp-5BCh]@11
  char v7749; // [sp+EA90h] [bp-5A4h]@11
  char v7750; // [sp+EAA8h] [bp-58Ch]@11
  char v7751; // [sp+EAC0h] [bp-574h]@11
  char v7752; // [sp+EAD8h] [bp-55Ch]@11
  char v7753; // [sp+EAF0h] [bp-544h]@11
  char v7754; // [sp+EB08h] [bp-52Ch]@11
  char v7755; // [sp+EB20h] [bp-514h]@11
  char v7756; // [sp+EB38h] [bp-4FCh]@11
  char v7757; // [sp+EB50h] [bp-4E4h]@11
  char v7758; // [sp+EB68h] [bp-4CCh]@11
  char v7759; // [sp+EB80h] [bp-4B4h]@11
  char v7760; // [sp+EB98h] [bp-49Ch]@11
  char v7761; // [sp+EBB0h] [bp-484h]@11
  char v7762; // [sp+EBC8h] [bp-46Ch]@11
  char v7763; // [sp+EBE0h] [bp-454h]@11
  char v7764; // [sp+EBF8h] [bp-43Ch]@11
  char v7765; // [sp+EC10h] [bp-424h]@11
  char v7766; // [sp+EC28h] [bp-40Ch]@11
  char v7767; // [sp+EC40h] [bp-3F4h]@11
  char v7768; // [sp+EC58h] [bp-3DCh]@11
  char v7769; // [sp+EC70h] [bp-3C4h]@11
  char v7770; // [sp+EC88h] [bp-3ACh]@11
  char v7771; // [sp+ECA0h] [bp-394h]@11
  char v7772; // [sp+ECB8h] [bp-37Ch]@11
  char v7773; // [sp+ECD0h] [bp-364h]@11
  char v7774; // [sp+ECE8h] [bp-34Ch]@11
  char v7775; // [sp+ED00h] [bp-334h]@11
  char v7776; // [sp+ED18h] [bp-31Ch]@11
  char v7777; // [sp+ED30h] [bp-304h]@11
  char v7778; // [sp+ED48h] [bp-2ECh]@11
  char v7779; // [sp+ED60h] [bp-2D4h]@11
  char v7780; // [sp+ED78h] [bp-2BCh]@11
  char v7781; // [sp+ED90h] [bp-2A4h]@11
  char v7782; // [sp+EDA8h] [bp-28Ch]@11
  char v7783; // [sp+EDC0h] [bp-274h]@11
  char v7784; // [sp+EDD8h] [bp-25Ch]@11
  char v7785; // [sp+EDF0h] [bp-244h]@11
  char v7786; // [sp+EE08h] [bp-22Ch]@11
  char v7787; // [sp+EE20h] [bp-214h]@11
  char v7788; // [sp+EE38h] [bp-1FCh]@11
  char v7789; // [sp+EE50h] [bp-1E4h]@11
  char v7790; // [sp+EE68h] [bp-1CCh]@11
  char v7791; // [sp+EE80h] [bp-1B4h]@11
  char v7792; // [sp+EE98h] [bp-19Ch]@11
  char v7793; // [sp+EEB0h] [bp-184h]@11
  char v7794; // [sp+EEC8h] [bp-16Ch]@11
  char v7795; // [sp+EEE0h] [bp-154h]@11
  char v7796; // [sp+EEF8h] [bp-13Ch]@11
  char v7797; // [sp+EF10h] [bp-124h]@11
  char v7798; // [sp+EF28h] [bp-10Ch]@11
  char v7799; // [sp+EF40h] [bp-F4h]@11
  char v7800; // [sp+EF58h] [bp-DCh]@11
  char v7801; // [sp+EF70h] [bp-C4h]@11
  char v7802; // [sp+EF88h] [bp-ACh]@11
  char v7803; // [sp+EFACh] [bp-88h]@11
  char v7804; // [sp+EFC4h] [bp-70h]@11
  char v7805; // [sp+EFDCh] [bp-58h]@11
  char v7806; // [sp+EFF4h] [bp-40h]@11
  char Dst; // [sp+F00Ch] [bp-28h]@6
  int v7808; // [sp+F010h] [bp-24h]@11
  signed int v7809; // [sp+F014h] [bp-20h]@11
  unsigned int v7810; // [sp+F018h] [bp-1Ch]@1
  int manager2; // [sp+F01Ch] [bp-18h]@1
  int v7812; // [sp+F020h] [bp-14h]@1
  int v7813; // [sp+F030h] [bp-4h]@2
  int v7814; // [sp+F034h] [bp+0h]@1

  alloc_stack(0xF028u, a1);
  v7812 = a3;
  manager2 = manager;
  v7810 = (unsigned int)&v7814 ^ __security_cookie;
  v5 = v4;
  v6 = v4 + 4;
  v5246 = a4;
  sub_12DCD40(2569);
  v7 = 0;
  if ( ((*(_DWORD *)(v6 + 4) - *(_DWORD *)v6) & 0xFFFFFFFC) > 0 )
  {
    do
    {
      v5244 = operator new(0x60u);
      v7813 = 0;
      if ( v5244 )
        v8 = sub_122F0E0(*(_DWORD *)(v5 + 16), 0);
      else
        v8 = 0;
      ++v7;
      *(_DWORD *)(*(_DWORD *)v6 + 4 * v7 - 4) = v8;
      v9 = *(_DWORD *)(v6 + 4) - *(_DWORD *)v6;
      v7813 = -1;
    }
    while ( v7 < v9 >> 2 );
  }
  v7812 = 15;
  manager2 = 0;
  Dst = 0;
  v7813 = 1;
  if ( *(_DWORD *)(v5246 + 16) )
  {
    v10 = std_string_append(&v6525, v5246, &byte_135B530);
    sub_1231410(&Dst, v10);
    delete_std_string((int)&v6525);
  }
  v11 = operator new(8u);
  v5244 = v11;
  LOBYTE(v7813) = 2;
  if ( v11 )
    v5247 = sub_1212300(v11);
  else
    v5247 = 0;
  LOBYTE(v7813) = 1;
  v12 = std_string_append(&v7801, (int)&Dst, "data1.db");
  LOBYTE(v7813) = 3;
  open_table(v12);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7801);
  sub_1231450(byte_135B524);
  v13 = (int)std_string_append(&v5567, (int)&Dst, "cubequest4.cub");
  v14 = *(int **)v6;
  v7809 = 1;
  v15 = v14[2312];
  LOBYTE(v7813) = 4;
  something_database(v15, v13, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5567);
  v16 = (int)std_string_append(&v7799, (int)&Dst, "spiribit.cub");
  v17 = *(int **)v6;
  v7809 = 1;
  v18 = v17[2336];
  LOBYTE(v7813) = 5;
  something_database(v18, v16, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7799);
  v19 = (int)std_string_append(&v6523, (int)&Dst, "pet-box.cub");
  v20 = *(int **)v6;
  v7809 = 1;
  v21 = v20[2080];
  LOBYTE(v7813) = 6;
  something_database(v21, v19, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6523);
  v22 = (int)std_string_append(&v7797, (int)&Dst, "egg1.cub");
  v23 = *(int **)v6;
  v7809 = 1;
  v24 = v23[2164];
  LOBYTE(v7813) = 7;
  something_database(v24, v22, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7797);
  v25 = (int)std_string_append(&v5885, (int)&Dst, "egg1.cub");
  v26 = *(int **)v6;
  v7809 = 1;
  v27 = v26[2165];
  LOBYTE(v7813) = 8;
  something_database(v27, v25, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5885);
  v28 = (int)std_string_append(&v7795, (int)&Dst, "egg1.cub");
  v29 = *(int **)v6;
  v7809 = 1;
  v30 = v29[2166];
  LOBYTE(v7813) = 9;
  something_database(v30, v28, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7795);
  v31 = (int)std_string_append(&v6521, (int)&Dst, "formula.cub");
  v32 = *(int **)v6;
  v7809 = 1;
  v33 = v32[2421];
  LOBYTE(v7813) = 10;
  something_database(v33, v31, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6521);
  v34 = (int)std_string_append(&v7793, (int)&Dst, "body2.cub");
  v35 = *(int **)v6;
  v7809 = 1;
  v36 = v35[0];
  LOBYTE(v7813) = 11;
  something_database(v36, v34, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7793);
  v37 = (int)std_string_append(&v5407, (int)&Dst, "body4.cub");
  v38 = *(int **)v6;
  v7809 = 1;
  v39 = v38[1];
  LOBYTE(v7813) = 12;
  something_database(v39, v37, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5407);
  v40 = (int)std_string_append(&v7791, (int)&Dst, "body3.cub");
  v41 = *(int **)v6;
  v7809 = 1;
  v42 = v41[2];
  LOBYTE(v7813) = 13;
  something_database(v42, v40, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7791);
  v43 = (int)std_string_append(&v6519, (int)&Dst, "glove.cub");
  v44 = *(int **)v6;
  v7809 = 1;
  v45 = v44[7];
  LOBYTE(v7813) = 14;
  something_database(v45, v43, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6519);
  v46 = (int)std_string_append(&v7789, (int)&Dst, "head2.cub");
  v47 = *(int **)v6;
  v7809 = 1;
  v48 = v47[8];
  LOBYTE(v7813) = 15;
  something_database(v48, v46, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7789);
  v49 = (int)std_string_append(&v5883, (int)&Dst, "old-head.cub");
  v50 = *(int **)v6;
  v7809 = 1;
  v51 = v50[11];
  LOBYTE(v7813) = 16;
  something_database(v51, v49, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5883);
  v52 = (int)std_string_append(&v7787, (int)&Dst, "girl-head3.cub");
  v53 = *(int **)v6;
  v7809 = 1;
  v54 = v53[9];
  LOBYTE(v7813) = 17;
  something_database(v54, v52, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7787);
  v55 = (int)std_string_append(&v6517, (int)&Dst, "elf-head-female.cub");
  v56 = *(int **)v6;
  v7809 = 1;
  v57 = v56[10];
  LOBYTE(v7813) = 18;
  something_database(v57, v55, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6517);
  v58 = (int)std_string_append(&v7785, (int)&Dst, "hand2.cub");
  v59 = *(int **)v6;
  v7809 = 1;
  v60 = v59[430];
  LOBYTE(v7813) = 19;
  something_database(v60, v58, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7785);
  v61 = (int)std_string_append(&v5565, (int)&Dst, "brown-hand.cub");
  v62 = *(int **)v6;
  v7809 = 1;
  v63 = v62[431];
  LOBYTE(v7813) = 20;
  something_database(v63, v61, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5565);
  v64 = (int)std_string_append(&v7783, (int)&Dst, "foot.cub");
  v65 = *(int **)v6;
  v7809 = 1;
  v66 = v65[432];
  LOBYTE(v7813) = 21;
  something_database(v66, v64, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7783);
  v67 = (int)std_string_append(&v6515, (int)&Dst, "boot.cub");
  v68 = *(int **)v6;
  v7809 = 1;
  v69 = v68[433];
  LOBYTE(v7813) = 22;
  something_database(v69, v67, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6515);
  v70 = (int)std_string_append(&v7781, (int)&Dst, "troll-foot.cub");
  v71 = *(int **)v6;
  v7809 = 1;
  v72 = v71[28];
  LOBYTE(v7813) = 23;
  something_database(v72, v70, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7781);
  v73 = (int)std_string_append(&v5881, (int)&Dst, "troll-head.cub");
  v74 = *(int **)v6;
  v7809 = 1;
  v75 = v74[24];
  LOBYTE(v7813) = 24;
  something_database(v75, v73, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5881);
  v76 = (int)std_string_append(&v7779, (int)&Dst, "troll-body.cub");
  v77 = *(int **)v6;
  v7809 = 1;
  v78 = v77[25];
  LOBYTE(v7813) = 25;
  something_database(v78, v76, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7779);
  v79 = (int)std_string_append(&v6513, (int)&Dst, "troll-hand.cub");
  v80 = *(int **)v6;
  v7809 = 1;
  v81 = v80[27];
  LOBYTE(v7813) = 26;
  something_database(v81, v79, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6513);
  v82 = (int)std_string_append(&v7777, (int)&Dst, "troll-arm.cub");
  v83 = *(int **)v6;
  v7809 = 1;
  v84 = v83[26];
  LOBYTE(v7813) = 27;
  something_database(v84, v82, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7777);
  v85 = (int)std_string_append(&v5327, (int)&Dst, "dark-troll-foot.cub");
  v86 = *(int **)v6;
  v7809 = 1;
  v87 = v86[34];
  LOBYTE(v7813) = 28;
  something_database(v87, v85, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5327);
  v88 = (int)std_string_append(&v7775, (int)&Dst, "dark-troll-head.cub");
  v89 = *(int **)v6;
  v7809 = 1;
  v90 = v89[30];
  LOBYTE(v7813) = 29;
  something_database(v90, v88, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7775);
  v91 = (int)std_string_append(&v6511, (int)&Dst, "dark-troll-body.cub");
  v92 = *(int **)v6;
  v7809 = 1;
  v93 = v92[31];
  LOBYTE(v7813) = 30;
  something_database(v93, v91, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6511);
  v94 = (int)std_string_append(&v7773, (int)&Dst, "dark-troll-hand.cub");
  v95 = *(int **)v6;
  v7809 = 1;
  v96 = v95[33];
  LOBYTE(v7813) = 31;
  something_database(v96, v94, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7773);
  v97 = (int)std_string_append(&v5879, (int)&Dst, "dark-troll-arm.cub");
  v98 = *(int **)v6;
  v7809 = 1;
  v99 = v98[32];
  LOBYTE(v7813) = 32;
  something_database(v99, v97, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5879);
  v100 = (int)std_string_append(&v7771, (int)&Dst, "dark-troll-eyes.cub");
  v101 = *(int **)v6;
  v7809 = 0;
  v102 = v101[29];
  LOBYTE(v7813) = 33;
  something_database(v102, v100, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7771);
  v103 = (int)std_string_append(&v6509, (int)&Dst, "hell-demon-foot.cub");
  v104 = *(int **)v6;
  v7809 = 1;
  v105 = v104[39];
  LOBYTE(v7813) = 34;
  something_database(v105, v103, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6509);
  v106 = (int)std_string_append(&v7769, (int)&Dst, "hell-demon-head.cub");
  v107 = *(int **)v6;
  v7809 = 1;
  v108 = v107[35];
  LOBYTE(v7813) = 35;
  something_database(v108, v106, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7769);
  v109 = (int)std_string_append(&v5563, (int)&Dst, "hell-demon-body.cub");
  v110 = *(int **)v6;
  v7809 = 1;
  v111 = v110[36];
  LOBYTE(v7813) = 36;
  something_database(v111, v109, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5563);
  v112 = (int)std_string_append(&v7767, (int)&Dst, "hell-demon-arm.cub");
  v113 = *(int **)v6;
  v7809 = 1;
  v114 = v113[37];
  LOBYTE(v7813) = 37;
  something_database(v114, v112, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7767);
  v115 = (int)std_string_append(&v6507, (int)&Dst, "hell-demon-hand.cub");
  v116 = *(int **)v6;
  v7809 = 1;
  v117 = v116[38];
  LOBYTE(v7813) = 38;
  something_database(v117, v115, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6507);
  v118 = (int)std_string_append(&v7765, (int)&Dst, "golem-foot.cub");
  v119 = *(int **)v6;
  v7809 = 1;
  v120 = v119[44];
  LOBYTE(v7813) = 39;
  something_database(v120, v118, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7765);
  v121 = (int)std_string_append(&v5877, (int)&Dst, "golem-head.cub");
  v122 = *(int **)v6;
  v7809 = 1;
  v123 = v122[40];
  LOBYTE(v7813) = 40;
  something_database(v123, v121, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5877);
  v124 = (int)std_string_append(&v7763, (int)&Dst, "golem-body.cub");
  v125 = *(int **)v6;
  v7809 = 1;
  v126 = v125[41];
  LOBYTE(v7813) = 41;
  something_database(v126, v124, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7763);
  v127 = (int)std_string_append(&v6505, (int)&Dst, "golem-hand.cub");
  v128 = *(int **)v6;
  v7809 = 1;
  v129 = v128[43];
  LOBYTE(v7813) = 42;
  something_database(v129, v127, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6505);
  v130 = (int)std_string_append(&v7761, (int)&Dst, "golem-arm.cub");
  v131 = *(int **)v6;
  v7809 = 1;
  v132 = v131[42];
  LOBYTE(v7813) = 43;
  something_database(v132, v130, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7761);
  v133 = (int)std_string_append(&v5405, (int)&Dst, "golem-ember-foot.cub");
  v134 = *(int **)v6;
  v7809 = 1;
  v135 = v134[49];
  LOBYTE(v7813) = 44;
  something_database(v135, v133, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5405);
  v136 = (int)std_string_append(&v7759, (int)&Dst, "golem-ember-head.cub");
  v137 = *(int **)v6;
  v7809 = 1;
  v138 = v137[45];
  LOBYTE(v7813) = 45;
  something_database(v138, v136, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7759);
  v139 = (int)std_string_append(&v6503, (int)&Dst, "golem-ember-body.cub");
  v140 = *(int **)v6;
  v7809 = 1;
  v141 = v140[46];
  LOBYTE(v7813) = 46;
  something_database(v141, v139, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6503);
  v142 = (int)std_string_append(&v7757, (int)&Dst, "golem-ember-hand.cub");
  v143 = *(int **)v6;
  v7809 = 1;
  v144 = v143[48];
  LOBYTE(v7813) = 47;
  something_database(v144, v142, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7757);
  v145 = (int)std_string_append(&v5875, (int)&Dst, "golem-ember-arm.cub");
  v146 = *(int **)v6;
  v7809 = 1;
  v147 = v146[47];
  LOBYTE(v7813) = 48;
  something_database(v147, v145, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5875);
  v148 = (int)std_string_append(&v7755, (int)&Dst, "golem-snow-foot.cub");
  v149 = *(int **)v6;
  v7809 = 1;
  v150 = v149[54];
  LOBYTE(v7813) = 49;
  something_database(v150, v148, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7755);
  v151 = (int)std_string_append(&v6501, (int)&Dst, "golem-snow-head.cub");
  v152 = *(int **)v6;
  v7809 = 1;
  v153 = v152[50];
  LOBYTE(v7813) = 50;
  something_database(v153, v151, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6501);
  v154 = (int)std_string_append(&v7753, (int)&Dst, "golem-snow-body.cub");
  v155 = *(int **)v6;
  v7809 = 1;
  v156 = v155[51];
  LOBYTE(v7813) = 51;
  something_database(v156, v154, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7753);
  v157 = (int)std_string_append(&v5561, (int)&Dst, "golem-snow-hand.cub");
  v158 = *(int **)v6;
  v7809 = 1;
  v159 = v158[53];
  LOBYTE(v7813) = 52;
  something_database(v159, v157, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5561);
  v160 = (int)std_string_append(&v7751, (int)&Dst, "golem-snow-arm.cub");
  v161 = *(int **)v6;
  v7809 = 1;
  v162 = v161[52];
  LOBYTE(v7813) = 53;
  something_database(v162, v160, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7751);
  v163 = (int)std_string_append(&v6499, (int)&Dst, "yeti-foot.cub");
  v164 = *(int **)v6;
  v7809 = 1;
  v165 = v164[59];
  LOBYTE(v7813) = 54;
  something_database(v165, v163, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6499);
  v166 = (int)std_string_append(&v7749, (int)&Dst, "yeti-head.cub");
  v167 = *(int **)v6;
  v7809 = 1;
  v168 = v167[55];
  LOBYTE(v7813) = 55;
  something_database(v168, v166, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7749);
  v169 = (int)std_string_append(&v5873, (int)&Dst, "yeti-body.cub");
  v170 = *(int **)v6;
  v7809 = 1;
  v171 = v170[56];
  LOBYTE(v7813) = 56;
  something_database(v171, v169, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5873);
  v172 = (int)std_string_append(&v7747, (int)&Dst, "yeti-hand.cub");
  v173 = *(int **)v6;
  v7809 = 1;
  v174 = v173[58];
  LOBYTE(v7813) = 57;
  something_database(v174, v172, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7747);
  v175 = (int)std_string_append(&v6497, (int)&Dst, "yeti-arm.cub");
  v176 = *(int **)v6;
  v7809 = 1;
  v177 = v176[57];
  LOBYTE(v7813) = 58;
  something_database(v177, v175, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6497);
  v178 = (int)std_string_append(&v7745, (int)&Dst, "cyclops-foot.cub");
  v179 = *(int **)v6;
  v7809 = 1;
  v180 = v179[71];
  LOBYTE(v7813) = 59;
  something_database(v180, v178, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7745);
  v181 = (int)std_string_append(&v5287, (int)&Dst, "cyclops-head.cub");
  v182 = *(int **)v6;
  v7809 = 1;
  v183 = v182[67];
  LOBYTE(v7813) = 60;
  something_database(v183, v181, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5287);
  v184 = (int)std_string_append(&v7743, (int)&Dst, "cyclops-body.cub");
  v185 = *(int **)v6;
  v7809 = 1;
  v186 = v185[68];
  LOBYTE(v7813) = 61;
  something_database(v186, v184, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7743);
  v187 = (int)std_string_append(&v6495, (int)&Dst, "cyclops-hand.cub");
  v188 = *(int **)v6;
  v7809 = 1;
  v189 = v188[70];
  LOBYTE(v7813) = 62;
  something_database(v189, v187, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6495);
  v190 = (int)std_string_append(&v7741, (int)&Dst, "cyclops-arm.cub");
  v191 = *(int **)v6;
  v7809 = 1;
  v192 = v191[69];
  LOBYTE(v7813) = 63;
  something_database(v192, v190, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7741);
  v193 = (int)std_string_append(&v5871, (int)&Dst, "ogre-foot.cub");
  v194 = *(int **)v6;
  v7809 = 1;
  v195 = v194[63];
  LOBYTE(v7813) = 64;
  something_database(v195, v193, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5871);
  v196 = (int)std_string_append(&v7739, (int)&Dst, "ogre-head.cub");
  v197 = *(int **)v6;
  v7809 = 1;
  v198 = v197[60];
  LOBYTE(v7813) = 65;
  something_database(v198, v196, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7739);
  v199 = (int)std_string_append(&v6493, (int)&Dst, "ogre-body.cub");
  v200 = *(int **)v6;
  v7809 = 1;
  v201 = v200[61];
  LOBYTE(v7813) = 66;
  something_database(v201, v199, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6493);
  v202 = (int)std_string_append(&v7737, (int)&Dst, "ogre-hand.cub");
  v203 = *(int **)v6;
  v7809 = 1;
  v204 = v203[62];
  LOBYTE(v7813) = 67;
  something_database(v204, v202, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7737);
  v205 = (int)std_string_append(&v5559, (int)&Dst, "rockling-foot.cub");
  v206 = *(int **)v6;
  v7809 = 1;
  v207 = v206[66];
  LOBYTE(v7813) = 68;
  something_database(v207, v205, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5559);
  v208 = (int)std_string_append(&v7735, (int)&Dst, "rockling-head.cub");
  v209 = *(int **)v6;
  v7809 = 1;
  v210 = v209[64];
  LOBYTE(v7813) = 69;
  something_database(v210, v208, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7735);
  v211 = (int)std_string_append(&v6491, (int)&Dst, "rockling-hand.cub");
  v212 = *(int **)v6;
  v7809 = 1;
  v213 = v212[65];
  LOBYTE(v7813) = 70;
  something_database(v213, v211, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6491);
  v214 = (int)std_string_append(&v7733, (int)&Dst, "spike-foot.cub");
  v215 = *(int **)v6;
  v7809 = 1;
  v216 = v215[161];
  LOBYTE(v7813) = 71;
  something_database(v216, v214, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7733);
  v217 = (int)std_string_append(&v5869, (int)&Dst, "spike-head.cub");
  v218 = *(int **)v6;
  v7809 = 1;
  v219 = v218[160];
  LOBYTE(v7813) = 72;
  something_database(v219, v217, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5869);
  v220 = (int)std_string_append(&v7731, (int)&Dst, "spike-body.cub");
  v221 = *(int **)v6;
  v7809 = 1;
  v222 = v221[162];
  LOBYTE(v7813) = 73;
  something_database(v222, v220, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7731);
  v223 = (int)std_string_append(&v6489, (int)&Dst, "spike-hand.cub");
  v224 = *(int **)v6;
  v7809 = 1;
  v225 = v224[163];
  LOBYTE(v7813) = 74;
  something_database(v225, v223, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6489);
  v226 = (int)std_string_append(&v7729, (int)&Dst, "anubis-foot.cub");
  v227 = *(int **)v6;
  v7809 = 1;
  v228 = v227[165];
  LOBYTE(v7813) = 75;
  something_database(v228, v226, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7729);
  v229 = (int)std_string_append(&v5403, (int)&Dst, "anubis-head.cub");
  v230 = *(int **)v6;
  v7809 = 1;
  v231 = v230[164];
  LOBYTE(v7813) = 76;
  something_database(v231, v229, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5403);
  v232 = (int)std_string_append(&v7727, (int)&Dst, "anubis-body.cub");
  v233 = *(int **)v6;
  v7809 = 1;
  v234 = v233[166];
  LOBYTE(v7813) = 77;
  something_database(v234, v232, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7727);
  v235 = (int)std_string_append(&v6487, (int)&Dst, "anubis-hand.cub");
  v236 = *(int **)v6;
  v7809 = 1;
  v237 = v236[167];
  LOBYTE(v7813) = 78;
  something_database(v237, v235, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6487);
  v238 = (int)std_string_append(&v7725, (int)&Dst, "horus-foot.cub");
  v239 = *(int **)v6;
  v7809 = 1;
  v240 = v239[169];
  LOBYTE(v7813) = 79;
  something_database(v240, v238, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7725);
  v241 = (int)std_string_append(&v5867, (int)&Dst, "horus-head.cub");
  v242 = *(int **)v6;
  v7809 = 1;
  v243 = v242[168];
  LOBYTE(v7813) = 80;
  something_database(v243, v241, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5867);
  v244 = (int)std_string_append(&v7723, (int)&Dst, "horus-body.cub");
  v245 = *(int **)v6;
  v7809 = 1;
  v246 = v245[170];
  LOBYTE(v7813) = 81;
  something_database(v246, v244, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7723);
  v247 = (int)std_string_append(&v6485, (int)&Dst, "horus-hand.cub");
  v248 = *(int **)v6;
  v7809 = 1;
  v249 = v248[171];
  LOBYTE(v7813) = 82;
  something_database(v249, v247, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6485);
  v250 = (int)std_string_append(&v7721, (int)&Dst, "jester-foot.cub");
  v251 = *(int **)v6;
  v7809 = 1;
  v252 = v251[173];
  LOBYTE(v7813) = 83;
  something_database(v252, v250, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7721);
  v253 = (int)std_string_append(&v5557, (int)&Dst, "jester-head.cub");
  v254 = *(int **)v6;
  v7809 = 1;
  v255 = v254[172];
  LOBYTE(v7813) = 84;
  something_database(v255, v253, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5557);
  v256 = (int)std_string_append(&v7719, (int)&Dst, "jester-body.cub");
  v257 = *(int **)v6;
  v7809 = 1;
  v258 = v257[174];
  LOBYTE(v7813) = 85;
  something_database(v258, v256, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7719);
  v259 = (int)std_string_append(&v6483, (int)&Dst, "jester-hand.cub");
  v260 = *(int **)v6;
  v7809 = 1;
  v261 = v260[175];
  LOBYTE(v7813) = 86;
  something_database(v261, v259, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6483);
  v262 = (int)std_string_append(&v7717, (int)&Dst, "spectrino-foot.cub");
  v263 = *(int **)v6;
  v7809 = 1;
  v264 = v263[177];
  LOBYTE(v7813) = 87;
  something_database(v264, v262, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7717);
  v265 = (int)std_string_append(&v5865, (int)&Dst, "spectrino-head.cub");
  v266 = *(int **)v6;
  v7809 = 1;
  v267 = v266[176];
  LOBYTE(v7813) = 88;
  something_database(v267, v265, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5865);
  v268 = (int)std_string_append(&v7715, (int)&Dst, "spectrino-body.cub");
  v269 = *(int **)v6;
  v7809 = 1;
  v270 = v269[178];
  LOBYTE(v7813) = 89;
  something_database(v270, v268, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7715);
  v271 = (int)std_string_append(&v6481, (int)&Dst, "spectrino-hand.cub");
  v272 = *(int **)v6;
  v7809 = 1;
  v273 = v272[179];
  LOBYTE(v7813) = 90;
  something_database(v273, v271, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6481);
  v274 = (int)std_string_append(&v7713, (int)&Dst, "djinn-foot.cub");
  v275 = *(int **)v6;
  v7809 = 1;
  v276 = v275[191];
  LOBYTE(v7813) = 91;
  something_database(v276, v274, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7713);
  v277 = (int)std_string_append(&v5325, (int)&Dst, "djinn-head.cub");
  v278 = *(int **)v6;
  v7809 = 1;
  v279 = v278[190];
  LOBYTE(v7813) = 92;
  something_database(v279, v277, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5325);
  v280 = (int)std_string_append(&v7711, (int)&Dst, "djinn-body.cub");
  v281 = *(int **)v6;
  v7809 = 1;
  v282 = v281[192];
  LOBYTE(v7813) = 93;
  something_database(v282, v280, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7711);
  v283 = (int)std_string_append(&v6479, (int)&Dst, "djinn-hand.cub");
  v284 = *(int **)v6;
  v7809 = 1;
  v285 = v284[193];
  LOBYTE(v7813) = 94;
  something_database(v285, v283, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6479);
  v286 = (int)std_string_append(&v7709, (int)&Dst, "minotaur-foot.cub");
  v287 = *(int **)v6;
  v7809 = 1;
  v288 = v287[195];
  LOBYTE(v7813) = 95;
  something_database(v288, v286, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7709);
  v289 = (int)std_string_append(&v5863, (int)&Dst, "minotaur-head.cub");
  v290 = *(int **)v6;
  v7809 = 1;
  v291 = v290[194];
  LOBYTE(v7813) = 96;
  something_database(v291, v289, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5863);
  v292 = (int)std_string_append(&v7707, (int)&Dst, "minotaur-body.cub");
  v293 = *(int **)v6;
  v7809 = 1;
  v294 = v293[196];
  LOBYTE(v7813) = 97;
  something_database(v294, v292, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7707);
  v295 = (int)std_string_append(&v6477, (int)&Dst, "minotaur-hand.cub");
  v296 = *(int **)v6;
  v7809 = 1;
  v297 = v296[197];
  LOBYTE(v7813) = 98;
  something_database(v297, v295, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6477);
  v298 = (int)std_string_append(&v7705, (int)&Dst, "minotaur-arm.cub");
  v299 = *(int **)v6;
  v7809 = 1;
  v300 = v299[198];
  LOBYTE(v7813) = 99;
  something_database(v300, v298, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7705);
  v301 = (int)std_string_append(&v5555, (int)&Dst, "desert-nomad-foot.cub");
  v302 = *(int **)v6;
  v7809 = 1;
  v303 = v302[186];
  LOBYTE(v7813) = 100;
  something_database(v303, v301, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5555);
  v304 = (int)std_string_append(&v7703, (int)&Dst, "desert-nomad-head1.cub");
  v305 = *(int **)v6;
  v7809 = 1;
  v306 = v305[180];
  LOBYTE(v7813) = 101;
  something_database(v306, v304, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7703);
  v307 = (int)std_string_append(&v6475, (int)&Dst, "desert-nomad-head2.cub");
  v308 = *(int **)v6;
  v7809 = 1;
  v309 = v308[181];
  LOBYTE(v7813) = 102;
  something_database(v309, v307, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6475);
  v310 = (int)std_string_append(&v7701, (int)&Dst, "desert-nomad-head3.cub");
  v311 = *(int **)v6;
  v7809 = 1;
  v312 = v311[182];
  LOBYTE(v7813) = 103;
  something_database(v312, v310, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7701);
  v313 = (int)std_string_append(&v5861, (int)&Dst, "desert-nomad-female-head1.cub");
  v314 = *(int **)v6;
  v7809 = 1;
  v315 = v314[183];
  LOBYTE(v7813) = 104;
  something_database(v315, v313, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5861);
  v316 = (int)std_string_append(&v7699, (int)&Dst, "desert-nomad-female-head2.cub");
  v317 = *(int **)v6;
  v7809 = 1;
  v318 = v317[184];
  LOBYTE(v7813) = 105;
  something_database(v318, v316, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7699);
  v319 = (int)std_string_append(&v6473, (int)&Dst, "desert-nomad-female-head3.cub");
  v320 = *(int **)v6;
  v7809 = 1;
  v321 = v320[185];
  LOBYTE(v7813) = 106;
  something_database(v321, v319, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6473);
  v322 = (int)std_string_append(&v7697, (int)&Dst, "desert-nomad-body.cub");
  v323 = *(int **)v6;
  v7809 = 1;
  v324 = v323[187];
  LOBYTE(v7813) = 107;
  something_database(v324, v322, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7697);
  v325 = (int)std_string_append(&v5401, (int)&Dst, "desert-nomad-hand.cub");
  v326 = *(int **)v6;
  v7809 = 1;
  v327 = v326[188];
  LOBYTE(v7813) = 108;
  something_database(v327, v325, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5401);
  v328 = (int)std_string_append(&v7695, (int)&Dst, "desert-nomad-hand2.cub");
  v329 = *(int **)v6;
  v7809 = 1;
  v330 = v329[189];
  LOBYTE(v7813) = 109;
  something_database(v330, v328, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7695);
  v331 = (int)std_string_append(&v6471, (int)&Dst, "imp-foot.cub");
  v332 = *(int **)v6;
  v7809 = 1;
  v333 = v332[201];
  LOBYTE(v7813) = 110;
  something_database(v333, v331, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6471);
  v334 = (int)std_string_append(&v7693, (int)&Dst, "imp-head.cub");
  v335 = *(int **)v6;
  v7809 = 1;
  v336 = v335[200];
  LOBYTE(v7813) = 111;
  something_database(v336, v334, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7693);
  v337 = (int)std_string_append(&v5859, (int)&Dst, "imp-body.cub");
  LOBYTE(v7813) = 112;
  v338 = this_4pointer_off((void *)v6, 202);
  something_database(*(_DWORD *)v338, v337, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5859);
  v339 = (int)std_string_append(&v7691, (int)&Dst, "imp-hand.cub");
  LOBYTE(v7813) = 113;
  v340 = this_4pointer_off((void *)v6, 203);
  something_database(*(_DWORD *)v340, v339, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7691);
  v341 = (int)std_string_append(&v6469, (int)&Dst, "imp-eyes.cub");
  LOBYTE(v7813) = 114;
  v342 = this_4pointer_off((void *)v6, 199);
  something_database(*(_DWORD *)v342, v341, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6469);
  v343 = (int)std_string_append(&v7689, (int)&Dst, "squid-foot.cub");
  LOBYTE(v7813) = 115;
  v344 = this_4pointer_off((void *)v6, 159);
  something_database(*(_DWORD *)v344, v343, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7689);
  v345 = (int)std_string_append(&v5553, (int)&Dst, "squid-body.cub");
  LOBYTE(v7813) = 116;
  v346 = this_4pointer_off((void *)v6, 158);
  something_database(*(_DWORD *)v346, v345, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5553);
  v347 = (int)std_string_append(&v7687, (int)&Dst, "mammoth-body.cub");
  LOBYTE(v7813) = 117;
  v348 = this_4pointer_off((void *)v6, 73);
  something_database(*(_DWORD *)v348, v347, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7687);
  v349 = (int)std_string_append(&v6467, (int)&Dst, "mammoth-head.cub");
  LOBYTE(v7813) = 118;
  v350 = this_4pointer_off((void *)v6, 72);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v349;
  something_database(*(_DWORD *)v350, v349, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6467);
  v351 = (int)std_string_append(&v7685, (int)&Dst, "mammoth-foot.cub");
  LOBYTE(v7813) = 119;
  v352 = this_4pointer_off((void *)v6, 74);
  something_database(*(_DWORD *)v352, v351, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7685);
  v353 = (int)std_string_append(&v5857, (int)&Dst, "bullterrier-head1.cub");
  LOBYTE(v7813) = 120;
  v354 = this_4pointer_off((void *)v6, 2379);
  something_database(*(_DWORD *)v354, v353, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5857);
  v355 = (int)std_string_append(&v7683, (int)&Dst, "bullterrier-head2.cub");
  LOBYTE(v7813) = 121;
  v356 = this_4pointer_off((void *)v6, 2380);
  something_database(*(_DWORD *)v356, v355, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7683);
  v357 = (int)std_string_append(&v6465, (int)&Dst, "bullterrier-head3.cub");
  LOBYTE(v7813) = 122;
  v358 = this_4pointer_off((void *)v6, 2381);
  something_database(*(_DWORD *)v358, v357, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6465);
  v359 = (int)std_string_append(&v7681, (int)&Dst, "goblin-head-m01.cub");
  LOBYTE(v7813) = 123;
  v360 = this_4pointer_off((void *)v6, 75);
  something_database(*(_DWORD *)v360, v359, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7681);
  v361 = (int)std_string_append(&v5267, (int)&Dst, "goblin-head-m02.cub");
  LOBYTE(v7813) = 124;
  v362 = this_4pointer_off((void *)v6, 76);
  something_database(*(_DWORD *)v362, v361, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5267);
  v363 = (int)std_string_append(&v7679, (int)&Dst, "goblin-head-m03.cub");
  LOBYTE(v7813) = 125;
  v364 = this_4pointer_off((void *)v6, 77);
  something_database(*(_DWORD *)v364, v363, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7679);
  v365 = (int)std_string_append(&v6463, (int)&Dst, "goblin-head-m04.cub");
  LOBYTE(v7813) = 126;
  v366 = this_4pointer_off((void *)v6, 78);
  something_database(*(_DWORD *)v366, v365, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6463);
  v367 = (int)std_string_append(&v7677, (int)&Dst, "goblin-head-m05.cub");
  LOBYTE(v7813) = 127;
  v368 = this_4pointer_off((void *)v6, 79);
  something_database(*(_DWORD *)v368, v367, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7677);
  v369 = (int)std_string_append(&v5855, (int)&Dst, "goblin-hair-m01.cub");
  LOBYTE(v7813) = -128;
  v370 = this_4pointer_off((void *)v6, 80);
  something_database(*(_DWORD *)v370, v369, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5855);
  v371 = (int)std_string_append(&v7675, (int)&Dst, "goblin-hair-m02.cub");
  LOBYTE(v7813) = -127;
  v372 = this_4pointer_off((void *)v6, 81);
  something_database(*(_DWORD *)v372, v371, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7675);
  v373 = (int)std_string_append(&v6461, (int)&Dst, "goblin-hair-m03.cub");
  LOBYTE(v7813) = -126;
  v374 = this_4pointer_off((void *)v6, 82);
  something_database(*(_DWORD *)v374, v373, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6461);
  v375 = (int)std_string_append(&v7673, (int)&Dst, "goblin-hair-m04.cub");
  LOBYTE(v7813) = -125;
  v376 = this_4pointer_off((void *)v6, 83);
  something_database(*(_DWORD *)v376, v375, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7673);
  v377 = (int)std_string_append(&v5551, (int)&Dst, "goblin-hair-m05.cub");
  LOBYTE(v7813) = -124;
  v378 = this_4pointer_off((void *)v6, 84);
  something_database(*(_DWORD *)v378, v377, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5551);
  v379 = (int)std_string_append(&v7671, (int)&Dst, "goblin-hair-m06.cub");
  LOBYTE(v7813) = -123;
  v380 = this_4pointer_off((void *)v6, 85);
  something_database(*(_DWORD *)v380, v379, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7671);
  v381 = (int)std_string_append(&v6459, (int)&Dst, "goblin-head-f01.cub");
  LOBYTE(v7813) = -122;
  v382 = this_4pointer_off((void *)v6, 86);
  something_database(*(_DWORD *)v382, v381, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6459);
  v383 = (int)std_string_append(&v7669, (int)&Dst, "goblin-head-f02.cub");
  LOBYTE(v7813) = -121;
  v384 = this_4pointer_off((void *)v6, 87);
  something_database(*(_DWORD *)v384, v383, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7669);
  v385 = (int)std_string_append(&v5853, (int)&Dst, "goblin-head-f03.cub");
  LOBYTE(v7813) = -120;
  v386 = this_4pointer_off((void *)v6, 88);
  something_database(*(_DWORD *)v386, v385, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5853);
  v387 = (int)std_string_append(&v7667, (int)&Dst, "goblin-head-f04.cub");
  LOBYTE(v7813) = -119;
  v388 = this_4pointer_off((void *)v6, 89);
  something_database(*(_DWORD *)v388, v387, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7667);
  v389 = (int)std_string_append(&v6457, (int)&Dst, "goblin-head-f05.cub");
  LOBYTE(v7813) = -118;
  v390 = this_4pointer_off((void *)v6, 90);
  something_database(*(_DWORD *)v390, v389, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6457);
  v391 = (int)std_string_append(&v7665, (int)&Dst, "goblin-hair-f01.cub");
  LOBYTE(v7813) = -117;
  v392 = this_4pointer_off((void *)v6, 91);
  something_database(*(_DWORD *)v392, v391, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7665);
  v393 = (int)std_string_append(&v5399, (int)&Dst, "goblin-hair-f02.cub");
  LOBYTE(v7813) = -116;
  v394 = this_4pointer_off((void *)v6, 92);
  something_database(*(_DWORD *)v394, v393, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5399);
  v395 = (int)std_string_append(&v7663, (int)&Dst, "goblin-hair-f03.cub");
  LOBYTE(v7813) = -115;
  v396 = this_4pointer_off((void *)v6, 93);
  something_database(*(_DWORD *)v396, v395, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7663);
  v397 = (int)std_string_append(&v6455, (int)&Dst, "goblin-hair-f04.cub");
  LOBYTE(v7813) = -114;
  v398 = this_4pointer_off((void *)v6, 94);
  something_database(*(_DWORD *)v398, v397, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6455);
  v399 = (int)std_string_append(&v7661, (int)&Dst, "goblin-hair-f05.cub");
  LOBYTE(v7813) = -113;
  v400 = this_4pointer_off((void *)v6, 95);
  something_database(*(_DWORD *)v400, v399, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7661);
  v401 = (int)std_string_append(&v5851, (int)&Dst, "goblin-hair-f06.cub");
  LOBYTE(v7813) = -112;
  v402 = this_4pointer_off((void *)v6, 96);
  something_database(*(_DWORD *)v402, v401, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5851);
  v403 = (int)std_string_append(&v7659, (int)&Dst, "goblin-hand.cub");
  LOBYTE(v7813) = -111;
  v404 = this_4pointer_off((void *)v6, 97);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v403;
  something_database(*(_DWORD *)v404, v403, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7659);
  v405 = (int)std_string_append(&v6453, (int)&Dst, "elf-head-m01.cub");
  LOBYTE(v7813) = -110;
  v406 = this_4pointer_off((void *)v6, 1236);
  something_database(*(_DWORD *)v406, v405, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6453);
  v407 = (int)std_string_append(&v7657, (int)&Dst, "elf-head-m02.cub");
  LOBYTE(v7813) = -109;
  v408 = this_4pointer_off((void *)v6, 1237);
  something_database(*(_DWORD *)v408, v407, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7657);
  v409 = (int)std_string_append(&v5549, (int)&Dst, "elf-head-m03.cub");
  LOBYTE(v7813) = -108;
  v410 = this_4pointer_off((void *)v6, 1238);
  something_database(*(_DWORD *)v410, v409, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5549);
  v411 = (int)std_string_append(&v7655, (int)&Dst, "elf-head-m04.cub");
  LOBYTE(v7813) = -107;
  v412 = this_4pointer_off((void *)v6, 1239);
  something_database(*(_DWORD *)v412, v411, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7655);
  v413 = (int)std_string_append(&v6451, (int)&Dst, "elf-head-f01.cub");
  LOBYTE(v7813) = -106;
  v414 = this_4pointer_off((void *)v6, 1240);
  something_database(*(_DWORD *)v414, v413, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6451);
  v415 = (int)std_string_append(&v7653, (int)&Dst, "elf-head-f02.cub");
  LOBYTE(v7813) = -105;
  v416 = this_4pointer_off((void *)v6, 1241);
  something_database(*(_DWORD *)v416, v415, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7653);
  v417 = (int)std_string_append(&v5849, (int)&Dst, "elf-head-f03.cub");
  LOBYTE(v7813) = -104;
  v418 = this_4pointer_off((void *)v6, 1242);
  something_database(*(_DWORD *)v418, v417, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5849);
  v419 = (int)std_string_append(&v7651, (int)&Dst, "elf-head-f04.cub");
  LOBYTE(v7813) = -103;
  v420 = this_4pointer_off((void *)v6, 1243);
  something_database(*(_DWORD *)v420, v419, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7651);
  v421 = (int)std_string_append(&v6449, (int)&Dst, "elf-head-f05.cub");
  LOBYTE(v7813) = -102;
  v422 = this_4pointer_off((void *)v6, 1244);
  something_database(*(_DWORD *)v422, v421, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6449);
  v423 = (int)std_string_append(&v7649, (int)&Dst, "elf-head-f06.cub");
  LOBYTE(v7813) = -101;
  v424 = this_4pointer_off((void *)v6, 1245);
  something_database(*(_DWORD *)v424, v423, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7649);
  v425 = (int)std_string_append(&v5323, (int)&Dst, "human-head-m01.cub");
  LOBYTE(v7813) = -100;
  v426 = this_4pointer_off((void *)v6, 1246);
  something_database(*(_DWORD *)v426, v425, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5323);
  v427 = (int)std_string_append(&v7647, (int)&Dst, "human-head-m02.cub");
  LOBYTE(v7813) = -99;
  v428 = this_4pointer_off((void *)v6, 1247);
  something_database(*(_DWORD *)v428, v427, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7647);
  v429 = (int)std_string_append(&v6447, (int)&Dst, "human-head-m03.cub");
  LOBYTE(v7813) = -98;
  v430 = this_4pointer_off((void *)v6, 1248);
  something_database(*(_DWORD *)v430, v429, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6447);
  v431 = (int)std_string_append(&v7645, (int)&Dst, "human-head-m04.cub");
  LOBYTE(v7813) = -97;
  v432 = this_4pointer_off((void *)v6, 1249);
  something_database(*(_DWORD *)v432, v431, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7645);
  v433 = (int)std_string_append(&v5847, (int)&Dst, "human-head-m05.cub");
  LOBYTE(v7813) = -96;
  v434 = this_4pointer_off((void *)v6, 1250);
  something_database(*(_DWORD *)v434, v433, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5847);
  v435 = (int)std_string_append(&v7643, (int)&Dst, "human-head-m06.cub");
  LOBYTE(v7813) = -95;
  v436 = this_4pointer_off((void *)v6, 1251);
  something_database(*(_DWORD *)v436, v435, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7643);
  v437 = (int)std_string_append(&v6445, (int)&Dst, "human-hair-m01.cub");
  LOBYTE(v7813) = -94;
  v438 = this_4pointer_off((void *)v6, 1252);
  something_database(*(_DWORD *)v438, v437, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6445);
  v439 = (int)std_string_append(&v7641, (int)&Dst, "human-hair-m02.cub");
  LOBYTE(v7813) = -93;
  v440 = this_4pointer_off((void *)v6, 1253);
  something_database(*(_DWORD *)v440, v439, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7641);
  v441 = (int)std_string_append(&v5547, (int)&Dst, "human-hair-m03.cub");
  LOBYTE(v7813) = -92;
  v442 = this_4pointer_off((void *)v6, 1254);
  something_database(*(_DWORD *)v442, v441, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5547);
  v443 = (int)std_string_append(&v7639, (int)&Dst, "human-hair-m04.cub");
  LOBYTE(v7813) = -91;
  v444 = this_4pointer_off((void *)v6, 1255);
  something_database(*(_DWORD *)v444, v443, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7639);
  v445 = (int)std_string_append(&v6443, (int)&Dst, "human-hair-m05.cub");
  LOBYTE(v7813) = -90;
  v446 = this_4pointer_off((void *)v6, 1256);
  something_database(*(_DWORD *)v446, v445, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6443);
  v447 = (int)std_string_append(&v7637, (int)&Dst, "human-hair-m06.cub");
  LOBYTE(v7813) = -89;
  v448 = this_4pointer_off((void *)v6, 1257);
  something_database(*(_DWORD *)v448, v447, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7637);
  v449 = (int)std_string_append(&v5845, (int)&Dst, "human-hair-m07.cub");
  LOBYTE(v7813) = -88;
  v450 = this_4pointer_off((void *)v6, 1258);
  something_database(*(_DWORD *)v450, v449, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5845);
  v451 = (int)std_string_append(&v7635, (int)&Dst, "human-hair-m08.cub");
  LOBYTE(v7813) = -87;
  v452 = this_4pointer_off((void *)v6, 1259);
  something_database(*(_DWORD *)v452, v451, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7635);
  v453 = (int)std_string_append(&v6441, (int)&Dst, "human-hair-m09.cub");
  LOBYTE(v7813) = -86;
  v454 = this_4pointer_off((void *)v6, 1260);
  something_database(*(_DWORD *)v454, v453, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6441);
  v455 = (int)std_string_append(&v7633, (int)&Dst, "human-hair-m10.cub");
  LOBYTE(v7813) = -85;
  v456 = this_4pointer_off((void *)v6, 1261);
  something_database(*(_DWORD *)v456, v455, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7633);
  v457 = (int)std_string_append(&v5397, (int)&Dst, "human-hair-m11.cub");
  LOBYTE(v7813) = -84;
  v458 = this_4pointer_off((void *)v6, 1262);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v457;
  something_database(*(_DWORD *)v458, v457, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5397);
  v459 = (int)std_string_append(&v7631, (int)&Dst, "human-hair-m12.cub");
  LOBYTE(v7813) = -83;
  v460 = this_4pointer_off((void *)v6, 1263);
  something_database(*(_DWORD *)v460, v459, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7631);
  v461 = (int)std_string_append(&v6439, (int)&Dst, "human-hair-m13.cub");
  LOBYTE(v7813) = -82;
  v462 = this_4pointer_off((void *)v6, 1264);
  something_database(*(_DWORD *)v462, v461, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6439);
  v463 = (int)std_string_append(&v7629, (int)&Dst, "human-hair-m14.cub");
  LOBYTE(v7813) = -81;
  v464 = this_4pointer_off((void *)v6, 1265);
  something_database(*(_DWORD *)v464, v463, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7629);
  v465 = (int)std_string_append(&v5843, (int)&Dst, "human-hair-m15.cub");
  LOBYTE(v7813) = -80;
  v466 = this_4pointer_off((void *)v6, 1266);
  something_database(*(_DWORD *)v466, v465, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5843);
  v467 = (int)std_string_append(&v7627, (int)&Dst, "human-head-f01.cub");
  LOBYTE(v7813) = -79;
  v468 = this_4pointer_off((void *)v6, 1267);
  something_database(*(_DWORD *)v468, v467, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7627);
  v469 = (int)std_string_append(&v6437, (int)&Dst, "human-head-f02.cub");
  LOBYTE(v7813) = -78;
  v470 = this_4pointer_off((void *)v6, 1268);
  something_database(*(_DWORD *)v470, v469, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6437);
  v471 = (int)std_string_append(&v7625, (int)&Dst, "human-head-f03.cub");
  LOBYTE(v7813) = -77;
  v472 = this_4pointer_off((void *)v6, 1269);
  something_database(*(_DWORD *)v472, v471, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7625);
  v473 = (int)std_string_append(&v5545, (int)&Dst, "human-head-f04.cub");
  LOBYTE(v7813) = -76;
  v474 = this_4pointer_off((void *)v6, 1270);
  something_database(*(_DWORD *)v474, v473, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5545);
  v475 = (int)std_string_append(&v7623, (int)&Dst, "human-head-f05.cub");
  LOBYTE(v7813) = -75;
  v476 = this_4pointer_off((void *)v6, 1271);
  something_database(*(_DWORD *)v476, v475, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7623);
  v477 = (int)std_string_append(&v6435, (int)&Dst, "human-head-f06.cub");
  LOBYTE(v7813) = -74;
  v478 = this_4pointer_off((void *)v6, 1272);
  something_database(*(_DWORD *)v478, v477, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6435);
  v479 = (int)std_string_append(&v7621, (int)&Dst, "human-hair-f01.cub");
  LOBYTE(v7813) = -73;
  v480 = this_4pointer_off((void *)v6, 1273);
  something_database(*(_DWORD *)v480, v479, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7621);
  v481 = (int)std_string_append(&v5841, (int)&Dst, "human-hair-f02.cub");
  LOBYTE(v7813) = -72;
  v482 = this_4pointer_off((void *)v6, 1274);
  something_database(*(_DWORD *)v482, v481, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5841);
  v483 = (int)std_string_append(&v7619, (int)&Dst, "human-hair-f03.cub");
  LOBYTE(v7813) = -71;
  v484 = this_4pointer_off((void *)v6, 1275);
  something_database(*(_DWORD *)v484, v483, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7619);
  v485 = (int)std_string_append(&v6433, (int)&Dst, "human-hair-f04.cub");
  LOBYTE(v7813) = -70;
  v486 = this_4pointer_off((void *)v6, 1276);
  something_database(*(_DWORD *)v486, v485, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6433);
  v487 = (int)std_string_append(&v7617, (int)&Dst, "human-hair-f05.cub");
  LOBYTE(v7813) = -69;
  v488 = this_4pointer_off((void *)v6, 1277);
  something_database(*(_DWORD *)v488, v487, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7617);
  v489 = (int)std_string_append(&v5285, (int)&Dst, "human-hair-f06.cub");
  LOBYTE(v7813) = -68;
  v490 = this_4pointer_off((void *)v6, 1278);
  something_database(*(_DWORD *)v490, v489, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5285);
  v491 = (int)std_string_append(&v7615, (int)&Dst, "human-hair-f07.cub");
  LOBYTE(v7813) = -67;
  v492 = this_4pointer_off((void *)v6, 1279);
  something_database(*(_DWORD *)v492, v491, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7615);
  v493 = (int)std_string_append(&v6431, (int)&Dst, "elf-hair-m01.cub");
  LOBYTE(v7813) = -66;
  v494 = this_4pointer_off((void *)v6, 1280);
  something_database(*(_DWORD *)v494, v493, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6431);
  v495 = (int)std_string_append(&v7613, (int)&Dst, "elf-hair-m02.cub");
  LOBYTE(v7813) = -65;
  v496 = this_4pointer_off((void *)v6, 1281);
  something_database(*(_DWORD *)v496, v495, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7613);
  v497 = (int)std_string_append(&v5839, (int)&Dst, "elf-hair-m03.cub");
  LOBYTE(v7813) = -64;
  v498 = this_4pointer_off((void *)v6, 1282);
  something_database(*(_DWORD *)v498, v497, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5839);
  v499 = (int)std_string_append(&v7611, (int)&Dst, "elf-hair-m04.cub");
  LOBYTE(v7813) = -63;
  v500 = this_4pointer_off((void *)v6, 1283);
  something_database(*(_DWORD *)v500, v499, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7611);
  v501 = (int)std_string_append(&v6429, (int)&Dst, "elf-hair-m05.cub");
  LOBYTE(v7813) = -62;
  v502 = this_4pointer_off((void *)v6, 1284);
  something_database(*(_DWORD *)v502, v501, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6429);
  v503 = (int)std_string_append(&v7609, (int)&Dst, "elf-hair-m06.cub");
  LOBYTE(v7813) = -61;
  v504 = this_4pointer_off((void *)v6, 1285);
  something_database(*(_DWORD *)v504, v503, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7609);
  v505 = (int)std_string_append(&v5543, (int)&Dst, "elf-hair-m07.cub");
  LOBYTE(v7813) = -60;
  v506 = this_4pointer_off((void *)v6, 1286);
  something_database(*(_DWORD *)v506, v505, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5543);
  v507 = (int)std_string_append(&v7607, (int)&Dst, "elf-hair-m08.cub");
  LOBYTE(v7813) = -59;
  v508 = this_4pointer_off((void *)v6, 1287);
  something_database(*(_DWORD *)v508, v507, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7607);
  v509 = (int)std_string_append(&v6427, (int)&Dst, "elf-hair-m09.cub");
  LOBYTE(v7813) = -58;
  v510 = this_4pointer_off((void *)v6, 1288);
  something_database(*(_DWORD *)v510, v509, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6427);
  v511 = (int)std_string_append(&v7605, (int)&Dst, "elf-hair-m10.cub");
  LOBYTE(v7813) = -57;
  v512 = this_4pointer_off((void *)v6, 1289);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v511;
  something_database(*(_DWORD *)v512, v511, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7605);
  v513 = (int)std_string_append(&v5837, (int)&Dst, "elf-hair-f01.cub");
  LOBYTE(v7813) = -56;
  v514 = this_4pointer_off((void *)v6, 1290);
  something_database(*(_DWORD *)v514, v513, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5837);
  v515 = (int)std_string_append(&v7603, (int)&Dst, "elf-hair-f02.cub");
  LOBYTE(v7813) = -55;
  v516 = this_4pointer_off((void *)v6, 1291);
  something_database(*(_DWORD *)v516, v515, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7603);
  v517 = (int)std_string_append(&v6425, (int)&Dst, "elf-hair-f03.cub");
  LOBYTE(v7813) = -54;
  v518 = this_4pointer_off((void *)v6, 1292);
  something_database(*(_DWORD *)v518, v517, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6425);
  v519 = (int)std_string_append(&v7601, (int)&Dst, "elf-hair-f04.cub");
  LOBYTE(v7813) = -53;
  v520 = this_4pointer_off((void *)v6, 1293);
  something_database(*(_DWORD *)v520, v519, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7601);
  v521 = (int)std_string_append(&v5395, (int)&Dst, "elf-hair-f05.cub");
  LOBYTE(v7813) = -52;
  v522 = this_4pointer_off((void *)v6, 1294);
  something_database(*(_DWORD *)v522, v521, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5395);
  v523 = (int)std_string_append(&v7599, (int)&Dst, "elf-hair-f06.cub");
  LOBYTE(v7813) = -51;
  v524 = this_4pointer_off((void *)v6, 1295);
  something_database(*(_DWORD *)v524, v523, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7599);
  v525 = (int)std_string_append(&v6423, (int)&Dst, "elf-hair-f07.cub");
  LOBYTE(v7813) = -50;
  v526 = this_4pointer_off((void *)v6, 1296);
  something_database(*(_DWORD *)v526, v525, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6423);
  v527 = (int)std_string_append(&v7597, (int)&Dst, "elf-hair-f08.cub");
  LOBYTE(v7813) = -49;
  v528 = this_4pointer_off((void *)v6, 1297);
  something_database(*(_DWORD *)v528, v527, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7597);
  v529 = (int)std_string_append(&v5835, (int)&Dst, "elf-hair-f09.cub");
  LOBYTE(v7813) = -48;
  v530 = this_4pointer_off((void *)v6, 1298);
  something_database(*(_DWORD *)v530, v529, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5835);
  v531 = (int)std_string_append(&v7595, (int)&Dst, "elf-hair-f10.cub");
  LOBYTE(v7813) = -47;
  v532 = this_4pointer_off((void *)v6, 1299);
  something_database(*(_DWORD *)v532, v531, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7595);
  v533 = (int)std_string_append(&v6421, (int)&Dst, "gnobold-foot.cub");
  LOBYTE(v7813) = -46;
  v534 = this_4pointer_off((void *)v6, 2382);
  something_database(*(_DWORD *)v534, v533, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6421);
  v535 = (int)std_string_append(&v7593, (int)&Dst, "gnobold-hand.cub");
  LOBYTE(v7813) = -45;
  v536 = this_4pointer_off((void *)v6, 2384);
  something_database(*(_DWORD *)v536, v535, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7593);
  v537 = (int)std_string_append(&v5541, (int)&Dst, "gnobold-head.cub");
  LOBYTE(v7813) = -44;
  v538 = this_4pointer_off((void *)v6, 2383);
  something_database(*(_DWORD *)v538, v537, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5541);
  v539 = (int)std_string_append(&v7591, (int)&Dst, "insectoid-foot.cub");
  LOBYTE(v7813) = -43;
  v540 = this_4pointer_off((void *)v6, 2385);
  something_database(*(_DWORD *)v540, v539, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7591);
  v541 = (int)std_string_append(&v6419, (int)&Dst, "insectoid-hand.cub");
  LOBYTE(v7813) = -42;
  v542 = this_4pointer_off((void *)v6, 2387);
  something_database(*(_DWORD *)v542, v541, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6419);
  v543 = (int)std_string_append(&v7589, (int)&Dst, "insectoid-head.cub");
  LOBYTE(v7813) = -41;
  v544 = this_4pointer_off((void *)v6, 2386);
  something_database(*(_DWORD *)v544, v543, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7589);
  v545 = (int)std_string_append(&v5833, (int)&Dst, "insectoid-body.cub");
  LOBYTE(v7813) = -40;
  v546 = this_4pointer_off((void *)v6, 2388);
  something_database(*(_DWORD *)v546, v545, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5833);
  v547 = (int)std_string_append(&v7587, (int)&Dst, "gnoll-foot.cub");
  LOBYTE(v7813) = -39;
  v548 = this_4pointer_off((void *)v6, 15);
  something_database(*(_DWORD *)v548, v547, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7587);
  v549 = (int)std_string_append(&v6417, (int)&Dst, "gnoll-hand.cub");
  LOBYTE(v7813) = -38;
  v550 = this_4pointer_off((void *)v6, 14);
  something_database(*(_DWORD *)v550, v549, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6417);
  v551 = (int)std_string_append(&v7585, (int)&Dst, "gnoll-head.cub");
  LOBYTE(v7813) = -37;
  v552 = this_4pointer_off((void *)v6, 12);
  something_database(*(_DWORD *)v552, v551, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7585);
  v553 = (int)std_string_append(&v5321, (int)&Dst, "gnoll-body.cub");
  LOBYTE(v7813) = -36;
  v554 = this_4pointer_off((void *)v6, 13);
  something_database(*(_DWORD *)v554, v553, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5321);
  v555 = (int)std_string_append(&v7583, (int)&Dst, "polar-gnoll-foot.cub");
  LOBYTE(v7813) = -35;
  v556 = this_4pointer_off((void *)v6, 19);
  something_database(*(_DWORD *)v556, v555, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7583);
  v557 = (int)std_string_append(&v6415, (int)&Dst, "polar-gnoll-hand.cub");
  LOBYTE(v7813) = -34;
  v558 = this_4pointer_off((void *)v6, 18);
  something_database(*(_DWORD *)v558, v557, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6415);
  v559 = (int)std_string_append(&v7581, (int)&Dst, "polar-gnoll-head.cub");
  LOBYTE(v7813) = -33;
  v560 = this_4pointer_off((void *)v6, 16);
  something_database(*(_DWORD *)v560, v559, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7581);
  v561 = (int)std_string_append(&v5831, (int)&Dst, "polar-gnoll-body.cub");
  LOBYTE(v7813) = -32;
  v562 = this_4pointer_off((void *)v6, 17);
  something_database(*(_DWORD *)v562, v561, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5831);
  v563 = (int)std_string_append(&v7579, (int)&Dst, "monkey-foot.cub");
  LOBYTE(v7813) = -31;
  v564 = this_4pointer_off((void *)v6, 23);
  something_database(*(_DWORD *)v564, v563, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7579);
  v565 = (int)std_string_append(&v6413, (int)&Dst, "monkey-hand.cub");
  LOBYTE(v7813) = -30;
  v566 = this_4pointer_off((void *)v6, 22);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v565;
  something_database(*(_DWORD *)v566, v565, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6413);
  v567 = (int)std_string_append(&v7577, (int)&Dst, "monkey-head.cub");
  LOBYTE(v7813) = -29;
  v568 = this_4pointer_off((void *)v6, 20);
  something_database(*(_DWORD *)v568, v567, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7577);
  v569 = (int)std_string_append(&v5539, (int)&Dst, "monkey-body.cub");
  LOBYTE(v7813) = -28;
  v570 = this_4pointer_off((void *)v6, 21);
  something_database(*(_DWORD *)v570, v569, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5539);
  v571 = (int)std_string_append(&v7575, (int)&Dst, "orc-head-m01.cub");
  LOBYTE(v7813) = -27;
  v572 = this_4pointer_off((void *)v6, 1300);
  something_database(*(_DWORD *)v572, v571, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7575);
  v573 = (int)std_string_append(&v6411, (int)&Dst, "orc-head-m02.cub");
  LOBYTE(v7813) = -26;
  v574 = this_4pointer_off((void *)v6, 1301);
  something_database(*(_DWORD *)v574, v573, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6411);
  v575 = (int)std_string_append(&v7573, (int)&Dst, "orc-head-m03.cub");
  LOBYTE(v7813) = -25;
  v576 = this_4pointer_off((void *)v6, 1302);
  something_database(*(_DWORD *)v576, v575, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7573);
  v577 = (int)std_string_append(&v5829, (int)&Dst, "orc-head-m04.cub");
  LOBYTE(v7813) = -24;
  v578 = this_4pointer_off((void *)v6, 1303);
  something_database(*(_DWORD *)v578, v577, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5829);
  v579 = (int)std_string_append(&v7571, (int)&Dst, "orc-head-m05.cub");
  LOBYTE(v7813) = -23;
  v580 = this_4pointer_off((void *)v6, 1304);
  something_database(*(_DWORD *)v580, v579, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7571);
  v581 = (int)std_string_append(&v6409, (int)&Dst, "orc-hair-m01.cub");
  LOBYTE(v7813) = -22;
  v582 = this_4pointer_off((void *)v6, 1310);
  something_database(*(_DWORD *)v582, v581, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6409);
  v583 = (int)std_string_append(&v7569, (int)&Dst, "orc-hair-m02.cub");
  LOBYTE(v7813) = -21;
  v584 = this_4pointer_off((void *)v6, 1311);
  something_database(*(_DWORD *)v584, v583, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7569);
  v585 = (int)std_string_append(&v5393, (int)&Dst, "orc-hair-m03.cub");
  LOBYTE(v7813) = -20;
  v586 = this_4pointer_off((void *)v6, 1312);
  something_database(*(_DWORD *)v586, v585, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5393);
  v587 = (int)std_string_append(&v7567, (int)&Dst, "orc-hair-m04.cub");
  LOBYTE(v7813) = -19;
  v588 = this_4pointer_off((void *)v6, 1313);
  something_database(*(_DWORD *)v588, v587, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7567);
  v589 = (int)std_string_append(&v6407, (int)&Dst, "orc-hair-m05.cub");
  LOBYTE(v7813) = -18;
  v590 = this_4pointer_off((void *)v6, 1314);
  something_database(*(_DWORD *)v590, v589, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6407);
  v591 = (int)std_string_append(&v7565, (int)&Dst, "orc-hair-m06.cub");
  LOBYTE(v7813) = -17;
  v592 = this_4pointer_off((void *)v6, 1315);
  something_database(*(_DWORD *)v592, v591, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7565);
  v593 = (int)std_string_append(&v5827, (int)&Dst, "orc-hair-m07.cub");
  LOBYTE(v7813) = -16;
  v594 = this_4pointer_off((void *)v6, 1316);
  something_database(*(_DWORD *)v594, v593, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5827);
  v595 = (int)std_string_append(&v7563, (int)&Dst, "orc-hair-m08.cub");
  LOBYTE(v7813) = -15;
  v596 = this_4pointer_off((void *)v6, 1317);
  something_database(*(_DWORD *)v596, v595, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7563);
  v597 = (int)std_string_append(&v6405, (int)&Dst, "orc-hair-m09.cub");
  LOBYTE(v7813) = -14;
  v598 = this_4pointer_off((void *)v6, 1318);
  something_database(*(_DWORD *)v598, v597, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6405);
  v599 = (int)std_string_append(&v7561, (int)&Dst, "orc-hair-m10.cub");
  LOBYTE(v7813) = -13;
  v600 = this_4pointer_off((void *)v6, 1319);
  something_database(*(_DWORD *)v600, v599, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7561);
  v601 = (int)std_string_append(&v5537, (int)&Dst, "orc-hair-f01.cub");
  LOBYTE(v7813) = -12;
  v602 = this_4pointer_off((void *)v6, 1320);
  something_database(*(_DWORD *)v602, v601, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5537);
  v603 = (int)std_string_append(&v7559, (int)&Dst, "orc-hair-f02.cub");
  LOBYTE(v7813) = -11;
  v604 = this_4pointer_off((void *)v6, 1321);
  something_database(*(_DWORD *)v604, v603, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7559);
  v605 = (int)std_string_append(&v6403, (int)&Dst, "orc-hair-f03.cub");
  LOBYTE(v7813) = -10;
  v606 = this_4pointer_off((void *)v6, 1322);
  something_database(*(_DWORD *)v606, v605, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6403);
  v607 = (int)std_string_append(&v7557, (int)&Dst, "orc-hair-f04.cub");
  LOBYTE(v7813) = -9;
  v608 = this_4pointer_off((void *)v6, 1323);
  something_database(*(_DWORD *)v608, v607, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7557);
  v609 = (int)std_string_append(&v5825, (int)&Dst, "frogman-head-m01.cub");
  LOBYTE(v7813) = -8;
  v610 = this_4pointer_off((void *)v6, 1324);
  something_database(*(_DWORD *)v610, v609, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5825);
  v611 = (int)std_string_append(&v7555, (int)&Dst, "frogman-head-m02.cub");
  LOBYTE(v7813) = -7;
  v612 = this_4pointer_off((void *)v6, 1325);
  something_database(*(_DWORD *)v612, v611, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7555);
  v613 = (int)std_string_append(&v6401, (int)&Dst, "frogman-head-m03.cub");
  LOBYTE(v7813) = -6;
  v614 = this_4pointer_off((void *)v6, 1326);
  something_database(*(_DWORD *)v614, v613, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6401);
  v615 = (int)std_string_append(&v7553, (int)&Dst, "frogman-head-m04.cub");
  LOBYTE(v7813) = -5;
  v616 = this_4pointer_off((void *)v6, 1327);
  something_database(*(_DWORD *)v616, v615, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7553);
  v617 = (int)std_string_append(&v5257, (int)&Dst, "frogman-head-m05.cub");
  LOBYTE(v7813) = -4;
  v618 = this_4pointer_off((void *)v6, 1328);
  something_database(*(_DWORD *)v618, v617, v5247, 1);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v5257);
  v619 = (int)std_string_append(&v7551, (int)&Dst, "frogman-hair-m01.cub");
  LOBYTE(v7813) = -3;
  v620 = this_4pointer_off((void *)v6, 1329);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v619;
  something_database(*(_DWORD *)v620, v619, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7551);
  v621 = (int)std_string_append(&v6399, (int)&Dst, "frogman-hair-m02.cub");
  LOBYTE(v7813) = -2;
  v622 = this_4pointer_off((void *)v6, 1330);
  something_database(*(_DWORD *)v622, v621, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v6399);
  v623 = (int)std_string_append(&v7549, (int)&Dst, "frogman-hair-m03.cub");
  LOBYTE(v7813) = -1;
  v624 = this_4pointer_off((void *)v6, 1331);
  something_database(*(_DWORD *)v624, v623, v5247, 0);
  LOBYTE(v7813) = 1;
  delete_std_string((int)&v7549);
  v625 = (int)std_string_append(&v5823, (int)&Dst, "frogman-hair-m04.cub");
  v7813 = 256;
  v626 = this_4pointer_off((void *)v6, 1332);
  something_database(*(_DWORD *)v626, v625, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5823);
  v627 = (int)std_string_append(&v7547, (int)&Dst, "frogman-hair-m05.cub");
  v7813 = 257;
  v628 = this_4pointer_off((void *)v6, 1333);
  something_database(*(_DWORD *)v628, v627, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7547);
  v629 = (int)std_string_append(&v6397, (int)&Dst, "frogman-head-f01.cub");
  v7813 = 258;
  v630 = this_4pointer_off((void *)v6, 1334);
  something_database(*(_DWORD *)v630, v629, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6397);
  v631 = (int)std_string_append(&v7545, (int)&Dst, "frogman-head-f02.cub");
  v7813 = 259;
  v632 = this_4pointer_off((void *)v6, 1335);
  something_database(*(_DWORD *)v632, v631, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7545);
  v633 = (int)std_string_append(&v5535, (int)&Dst, "frogman-head-f03.cub");
  v7813 = 260;
  v634 = this_4pointer_off((void *)v6, 1336);
  something_database(*(_DWORD *)v634, v633, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5535);
  v635 = (int)std_string_append(&v7543, (int)&Dst, "frogman-head-f04.cub");
  v7813 = 261;
  v636 = this_4pointer_off((void *)v6, 1337);
  something_database(*(_DWORD *)v636, v635, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7543);
  v637 = (int)std_string_append(&v6395, (int)&Dst, "frogman-hair-f01.cub");
  v7813 = 262;
  v638 = this_4pointer_off((void *)v6, 1338);
  something_database(*(_DWORD *)v638, v637, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6395);
  v639 = (int)std_string_append(&v7541, (int)&Dst, "frogman-hair-f02.cub");
  v7813 = 263;
  v640 = this_4pointer_off((void *)v6, 1339);
  something_database(*(_DWORD *)v640, v639, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7541);
  v641 = (int)std_string_append(&v5821, (int)&Dst, "frogman-hair-f03.cub");
  v7813 = 264;
  v642 = this_4pointer_off((void *)v6, 1340);
  something_database(*(_DWORD *)v642, v641, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5821);
  v643 = (int)std_string_append(&v7539, (int)&Dst, "frogman-hair-f04.cub");
  v7813 = 265;
  v644 = this_4pointer_off((void *)v6, 1341);
  something_database(*(_DWORD *)v644, v643, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7539);
  v645 = (int)std_string_append(&v6393, (int)&Dst, "frogman-hand.cub");
  v7813 = 266;
  v646 = this_4pointer_off((void *)v6, 1342);
  something_database(*(_DWORD *)v646, v645, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6393);
  v647 = (int)std_string_append(&v7537, (int)&Dst, "mermaid-head-f01.cub");
  v7813 = 267;
  v648 = this_4pointer_off((void *)v6, 1343);
  something_database(*(_DWORD *)v648, v647, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7537);
  v649 = (int)std_string_append(&v5391, (int)&Dst, "mermaid-head-f02.cub");
  v7813 = 268;
  v650 = this_4pointer_off((void *)v6, 1344);
  something_database(*(_DWORD *)v650, v649, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5391);
  v651 = (int)std_string_append(&v7535, (int)&Dst, "mermaid-head-f03.cub");
  v7813 = 269;
  v652 = this_4pointer_off((void *)v6, 1345);
  something_database(*(_DWORD *)v652, v651, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7535);
  v653 = (int)std_string_append(&v6391, (int)&Dst, "mermaid-hair-f01.cub");
  v7813 = 270;
  v654 = this_4pointer_off((void *)v6, 1346);
  something_database(*(_DWORD *)v654, v653, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6391);
  v655 = (int)std_string_append(&v7533, (int)&Dst, "mermaid-hair-f02.cub");
  v7813 = 271;
  v656 = this_4pointer_off((void *)v6, 1347);
  something_database(*(_DWORD *)v656, v655, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7533);
  v657 = (int)std_string_append(&v5819, (int)&Dst, "mermaid-hair-f03.cub");
  v7813 = 272;
  v658 = this_4pointer_off((void *)v6, 1348);
  something_database(*(_DWORD *)v658, v657, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5819);
  v659 = (int)std_string_append(&v7531, (int)&Dst, "mermaid-body.cub");
  v7813 = 273;
  v660 = this_4pointer_off((void *)v6, 1349);
  something_database(*(_DWORD *)v660, v659, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7531);
  v661 = (int)std_string_append(&v6389, (int)&Dst, "mermaid-hand.cub");
  v7813 = 274;
  v662 = this_4pointer_off((void *)v6, 1350);
  something_database(*(_DWORD *)v662, v661, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6389);
  v663 = (int)std_string_append(&v7529, (int)&Dst, "merman-head-m01.cub");
  v7813 = 275;
  v664 = this_4pointer_off((void *)v6, 1351);
  something_database(*(_DWORD *)v664, v663, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7529);
  v665 = (int)std_string_append(&v5533, (int)&Dst, "merman-head-m02.cub");
  v7813 = 276;
  v666 = this_4pointer_off((void *)v6, 1352);
  something_database(*(_DWORD *)v666, v665, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5533);
  v667 = (int)std_string_append(&v7527, (int)&Dst, "merman-head-m03.cub");
  v7813 = 277;
  v668 = this_4pointer_off((void *)v6, 1353);
  something_database(*(_DWORD *)v668, v667, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7527);
  v669 = (int)std_string_append(&v6387, (int)&Dst, "merman-hair-m01.cub");
  v7813 = 278;
  v670 = this_4pointer_off((void *)v6, 1354);
  something_database(*(_DWORD *)v670, v669, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6387);
  v671 = (int)std_string_append(&v7525, (int)&Dst, "merman-hair-m02.cub");
  v7813 = 279;
  v672 = this_4pointer_off((void *)v6, 1355);
  something_database(*(_DWORD *)v672, v671, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7525);
  v673 = (int)std_string_append(&v5817, (int)&Dst, "merman-hair-m03.cub");
  v7813 = 280;
  v674 = this_4pointer_off((void *)v6, 1356);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v673;
  something_database(*(_DWORD *)v674, v673, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5817);
  v675 = (int)std_string_append(&v7523, (int)&Dst, "merman-body.cub");
  v7813 = 281;
  v676 = this_4pointer_off((void *)v6, 1357);
  something_database(*(_DWORD *)v676, v675, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7523);
  v677 = (int)std_string_append(&v6385, (int)&Dst, "mermaid-hand.cub");
  v7813 = 282;
  v678 = this_4pointer_off((void *)v6, 1358);
  something_database(*(_DWORD *)v678, v677, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6385);
  v679 = (int)std_string_append(&v7521, (int)&Dst, "lizard-head-m01.cub");
  v7813 = 283;
  v680 = this_4pointer_off((void *)v6, 98);
  something_database(*(_DWORD *)v680, v679, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7521);
  v681 = (int)std_string_append(&v5319, (int)&Dst, "lizard-head-m02.cub");
  v7813 = 284;
  v682 = this_4pointer_off((void *)v6, 99);
  something_database(*(_DWORD *)v682, v681, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5319);
  v683 = (int)std_string_append(&v7519, (int)&Dst, "lizard-hair-m01.cub");
  v7813 = 285;
  v684 = this_4pointer_off((void *)v6, 100);
  something_database(*(_DWORD *)v684, v683, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7519);
  v685 = (int)std_string_append(&v6383, (int)&Dst, "lizard-hair-m02.cub");
  v7813 = 286;
  v686 = this_4pointer_off((void *)v6, 101);
  something_database(*(_DWORD *)v686, v685, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6383);
  v687 = (int)std_string_append(&v7517, (int)&Dst, "lizard-hair-m03.cub");
  v7813 = 287;
  v688 = this_4pointer_off((void *)v6, 102);
  something_database(*(_DWORD *)v688, v687, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7517);
  v689 = (int)std_string_append(&v5815, (int)&Dst, "lizard-hair-m04.cub");
  v7813 = 288;
  v690 = this_4pointer_off((void *)v6, 103);
  something_database(*(_DWORD *)v690, v689, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5815);
  v691 = (int)std_string_append(&v7515, (int)&Dst, "lizard-hair-m05.cub");
  v7813 = 289;
  v692 = this_4pointer_off((void *)v6, 104);
  something_database(*(_DWORD *)v692, v691, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7515);
  v693 = (int)std_string_append(&v6381, (int)&Dst, "lizard-hair-m06.cub");
  v7813 = 290;
  v694 = this_4pointer_off((void *)v6, 105);
  something_database(*(_DWORD *)v694, v693, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6381);
  v695 = (int)std_string_append(&v7513, (int)&Dst, "lizard-head-f01.cub");
  v7813 = 291;
  v696 = this_4pointer_off((void *)v6, 106);
  something_database(*(_DWORD *)v696, v695, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7513);
  v697 = (int)std_string_append(&v5531, (int)&Dst, "lizard-head-f02.cub");
  v7813 = 292;
  v698 = this_4pointer_off((void *)v6, 107);
  something_database(*(_DWORD *)v698, v697, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5531);
  v699 = (int)std_string_append(&v7511, (int)&Dst, "lizard-head-f03.cub");
  v7813 = 293;
  v700 = this_4pointer_off((void *)v6, 108);
  something_database(*(_DWORD *)v700, v699, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7511);
  v701 = (int)std_string_append(&v6379, (int)&Dst, "lizard-head-f04.cub");
  v7813 = 294;
  v702 = this_4pointer_off((void *)v6, 109);
  something_database(*(_DWORD *)v702, v701, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6379);
  v703 = (int)std_string_append(&v7509, (int)&Dst, "lizard-head-f05.cub");
  v7813 = 295;
  v704 = this_4pointer_off((void *)v6, 110);
  something_database(*(_DWORD *)v704, v703, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7509);
  v705 = (int)std_string_append(&v5813, (int)&Dst, "lizard-hand.cub");
  v7813 = 296;
  v706 = this_4pointer_off((void *)v6, 111);
  something_database(*(_DWORD *)v706, v705, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5813);
  v707 = (int)std_string_append(&v7507, (int)&Dst, "lizard-body.cub");
  v7813 = 297;
  v708 = this_4pointer_off((void *)v6, 112);
  something_database(*(_DWORD *)v708, v707, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7507);
  v709 = (int)std_string_append(&v6377, (int)&Dst, "lizard-foot.cub");
  v7813 = 298;
  v710 = this_4pointer_off((void *)v6, 113);
  something_database(*(_DWORD *)v710, v709, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6377);
  v711 = (int)std_string_append(&v7505, (int)&Dst, "dwarf-head-m01.cub");
  v7813 = 299;
  v712 = this_4pointer_off((void *)v6, 282);
  something_database(*(_DWORD *)v712, v711, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7505);
  v713 = (int)std_string_append(&v5389, (int)&Dst, "dwarf-head-m02.cub");
  v7813 = 300;
  v714 = this_4pointer_off((void *)v6, 283);
  something_database(*(_DWORD *)v714, v713, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5389);
  v715 = (int)std_string_append(&v7503, (int)&Dst, "dwarf-head-m03.cub");
  v7813 = 301;
  v716 = this_4pointer_off((void *)v6, 284);
  something_database(*(_DWORD *)v716, v715, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7503);
  v717 = (int)std_string_append(&v6375, (int)&Dst, "dwarf-head-m04.cub");
  v7813 = 302;
  v718 = this_4pointer_off((void *)v6, 285);
  something_database(*(_DWORD *)v718, v717, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6375);
  v719 = (int)std_string_append(&v7501, (int)&Dst, "dwarf-head-m05.cub");
  v7813 = 303;
  v720 = this_4pointer_off((void *)v6, 286);
  something_database(*(_DWORD *)v720, v719, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7501);
  v721 = (int)std_string_append(&v5811, (int)&Dst, "dwarf-hair-m01.cub");
  v7813 = 304;
  v722 = this_4pointer_off((void *)v6, 287);
  something_database(*(_DWORD *)v722, v721, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5811);
  v723 = (int)std_string_append(&v7499, (int)&Dst, "dwarf-hair-m02.cub");
  v7813 = 305;
  v724 = this_4pointer_off((void *)v6, 288);
  something_database(*(_DWORD *)v724, v723, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7499);
  v725 = (int)std_string_append(&v6373, (int)&Dst, "dwarf-hair-m03.cub");
  v7813 = 306;
  v726 = this_4pointer_off((void *)v6, 289);
  something_database(*(_DWORD *)v726, v725, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6373);
  v727 = (int)std_string_append(&v7497, (int)&Dst, "dwarf-head-f01.cub");
  v7813 = 307;
  v728 = this_4pointer_off((void *)v6, 290);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v727;
  something_database(*(_DWORD *)v728, v727, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7497);
  v729 = (int)std_string_append(&v5529, (int)&Dst, "dwarf-head-f02.cub");
  v7813 = 308;
  v730 = this_4pointer_off((void *)v6, 291);
  something_database(*(_DWORD *)v730, v729, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5529);
  v731 = (int)std_string_append(&v7495, (int)&Dst, "dwarf-head-f03.cub");
  v7813 = 309;
  v732 = this_4pointer_off((void *)v6, 292);
  something_database(*(_DWORD *)v732, v731, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7495);
  v733 = (int)std_string_append(&v6371, (int)&Dst, "dwarf-head-f04.cub");
  v7813 = 310;
  v734 = this_4pointer_off((void *)v6, 293);
  something_database(*(_DWORD *)v734, v733, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6371);
  v735 = (int)std_string_append(&v7493, (int)&Dst, "dwarf-head-f05.cub");
  v7813 = 311;
  v736 = this_4pointer_off((void *)v6, 294);
  something_database(*(_DWORD *)v736, v735, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7493);
  v737 = (int)std_string_append(&v5809, (int)&Dst, "dwarf-hair-f01.cub");
  v7813 = 312;
  v738 = this_4pointer_off((void *)v6, 295);
  something_database(*(_DWORD *)v738, v737, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5809);
  v739 = (int)std_string_append(&v7491, (int)&Dst, "dwarf-hair-f02.cub");
  v7813 = 313;
  v740 = this_4pointer_off((void *)v6, 296);
  something_database(*(_DWORD *)v740, v739, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7491);
  v741 = (int)std_string_append(&v6369, (int)&Dst, "dwarf-hair-f03.cub");
  v7813 = 314;
  v742 = this_4pointer_off((void *)v6, 297);
  something_database(*(_DWORD *)v742, v741, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6369);
  v743 = (int)std_string_append(&v7489, (int)&Dst, "dwarf-hair-f04.cub");
  v7813 = 315;
  v744 = this_4pointer_off((void *)v6, 298);
  something_database(*(_DWORD *)v744, v743, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7489);
  v745 = (int)std_string_append(&v5283, (int)&Dst, "dwarf-hair-f05.cub");
  v7813 = 316;
  v746 = this_4pointer_off((void *)v6, 299);
  something_database(*(_DWORD *)v746, v745, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5283);
  v747 = (int)std_string_append(&v7487, (int)&Dst, "dwarf-body.cub");
  v7813 = 317;
  v748 = this_4pointer_off((void *)v6, 300);
  something_database(*(_DWORD *)v748, v747, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7487);
  v749 = (int)std_string_append(&v6367, (int)&Dst, "dwarf-body-female.cub");
  v7813 = 318;
  v750 = this_4pointer_off((void *)v6, 301);
  something_database(*(_DWORD *)v750, v749, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6367);
  v751 = (int)std_string_append(&v7485, (int)&Dst, "orc-head.cub");
  v7813 = 319;
  v752 = this_4pointer_off((void *)v6, 1300);
  something_database(*(_DWORD *)v752, v751, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7485);
  v753 = (int)std_string_append(&v5807, (int)&Dst, "orc-hand.cub");
  v7813 = 320;
  v754 = this_4pointer_off((void *)v6, 302);
  something_database(*(_DWORD *)v754, v753, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5807);
  v755 = (int)std_string_append(&v7483, (int)&Dst, "orc-head-f01.cub");
  v7813 = 321;
  v756 = this_4pointer_off((void *)v6, 1305);
  something_database(*(_DWORD *)v756, v755, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7483);
  v757 = (int)std_string_append(&v6365, (int)&Dst, "orc-head-f02.cub");
  v7813 = 322;
  v758 = this_4pointer_off((void *)v6, 1306);
  something_database(*(_DWORD *)v758, v757, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6365);
  v759 = (int)std_string_append(&v7481, (int)&Dst, "orc-head-f03.cub");
  v7813 = 323;
  v760 = this_4pointer_off((void *)v6, 1307);
  something_database(*(_DWORD *)v760, v759, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7481);
  v761 = (int)std_string_append(&v5527, (int)&Dst, "orc-head-f04.cub");
  v7813 = 324;
  v762 = this_4pointer_off((void *)v6, 1308);
  something_database(*(_DWORD *)v762, v761, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5527);
  v763 = (int)std_string_append(&v7479, (int)&Dst, "orc-head-f05.cub");
  v7813 = 325;
  v764 = this_4pointer_off((void *)v6, 1309);
  something_database(*(_DWORD *)v764, v763, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7479);
  v765 = (int)std_string_append(&v6363, (int)&Dst, "undead-head-m01.cub");
  v7813 = 326;
  v766 = this_4pointer_off((void *)v6, 303);
  something_database(*(_DWORD *)v766, v765, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6363);
  v767 = (int)std_string_append(&v7477, (int)&Dst, "undead-head-m02.cub");
  v7813 = 327;
  v768 = this_4pointer_off((void *)v6, 304);
  something_database(*(_DWORD *)v768, v767, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7477);
  v769 = (int)std_string_append(&v5805, (int)&Dst, "undead-head-m03.cub");
  v7813 = 328;
  v770 = this_4pointer_off((void *)v6, 305);
  something_database(*(_DWORD *)v770, v769, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5805);
  v771 = (int)std_string_append(&v7475, (int)&Dst, "undead-head-m04.cub");
  v7813 = 329;
  v772 = this_4pointer_off((void *)v6, 306);
  something_database(*(_DWORD *)v772, v771, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7475);
  v773 = (int)std_string_append(&v6361, (int)&Dst, "undead-head-m05.cub");
  v7813 = 330;
  v774 = this_4pointer_off((void *)v6, 307);
  something_database(*(_DWORD *)v774, v773, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6361);
  v775 = (int)std_string_append(&v7473, (int)&Dst, "undead-head-m06.cub");
  v7813 = 331;
  v776 = this_4pointer_off((void *)v6, 308);
  something_database(*(_DWORD *)v776, v775, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7473);
  v777 = (int)std_string_append(&v5387, (int)&Dst, "undead-hair-m01.cub");
  v7813 = 332;
  v778 = this_4pointer_off((void *)v6, 309);
  something_database(*(_DWORD *)v778, v777, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5387);
  v779 = (int)std_string_append(&v7471, (int)&Dst, "undead-hair-m02.cub");
  v7813 = 333;
  v780 = this_4pointer_off((void *)v6, 310);
  something_database(*(_DWORD *)v780, v779, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7471);
  v781 = (int)std_string_append(&v6359, (int)&Dst, "undead-hair-m03.cub");
  v7813 = 334;
  v782 = this_4pointer_off((void *)v6, 311);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v781;
  something_database(*(_DWORD *)v782, v781, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6359);
  v783 = (int)std_string_append(&v7469, (int)&Dst, "undead-hair-m04.cub");
  v7813 = 335;
  v784 = this_4pointer_off((void *)v6, 312);
  something_database(*(_DWORD *)v784, v783, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7469);
  v785 = (int)std_string_append(&v5803, (int)&Dst, "undead-hair-m05.cub");
  v7813 = 336;
  v786 = this_4pointer_off((void *)v6, 313);
  something_database(*(_DWORD *)v786, v785, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5803);
  v787 = (int)std_string_append(&v7467, (int)&Dst, "undead-hair-m06.cub");
  v7813 = 337;
  v788 = this_4pointer_off((void *)v6, 314);
  something_database(*(_DWORD *)v788, v787, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7467);
  v789 = (int)std_string_append(&v6357, (int)&Dst, "undead-head-f01.cub");
  v7813 = 338;
  v790 = this_4pointer_off((void *)v6, 315);
  something_database(*(_DWORD *)v790, v789, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6357);
  v791 = (int)std_string_append(&v7465, (int)&Dst, "undead-head-f02.cub");
  v7813 = 339;
  v792 = this_4pointer_off((void *)v6, 316);
  something_database(*(_DWORD *)v792, v791, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7465);
  v793 = (int)std_string_append(&v5525, (int)&Dst, "undead-head-f03.cub");
  v7813 = 340;
  v794 = this_4pointer_off((void *)v6, 317);
  something_database(*(_DWORD *)v794, v793, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5525);
  v795 = (int)std_string_append(&v7463, (int)&Dst, "undead-head-f04.cub");
  v7813 = 341;
  v796 = this_4pointer_off((void *)v6, 318);
  something_database(*(_DWORD *)v796, v795, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7463);
  v797 = (int)std_string_append(&v6355, (int)&Dst, "undead-head-f05.cub");
  v7813 = 342;
  v798 = this_4pointer_off((void *)v6, 319);
  something_database(*(_DWORD *)v798, v797, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6355);
  v799 = (int)std_string_append(&v7461, (int)&Dst, "undead-head-f06.cub");
  v7813 = 343;
  v800 = this_4pointer_off((void *)v6, 320);
  something_database(*(_DWORD *)v800, v799, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7461);
  v801 = (int)std_string_append(&v5801, (int)&Dst, "undead-hair-f01.cub");
  v7813 = 344;
  v802 = this_4pointer_off((void *)v6, 321);
  something_database(*(_DWORD *)v802, v801, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5801);
  v803 = (int)std_string_append(&v7459, (int)&Dst, "undead-hair-f02.cub");
  v7813 = 345;
  v804 = this_4pointer_off((void *)v6, 322);
  something_database(*(_DWORD *)v804, v803, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7459);
  v805 = (int)std_string_append(&v6353, (int)&Dst, "undead-hair-f03.cub");
  v7813 = 346;
  v806 = this_4pointer_off((void *)v6, 323);
  something_database(*(_DWORD *)v806, v805, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6353);
  v807 = (int)std_string_append(&v7457, (int)&Dst, "undead-hair-f04.cub");
  v7813 = 347;
  v808 = this_4pointer_off((void *)v6, 324);
  something_database(*(_DWORD *)v808, v807, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7457);
  v809 = (int)std_string_append(&v5317, (int)&Dst, "undead-hair-f05.cub");
  v7813 = 348;
  v810 = this_4pointer_off((void *)v6, 325);
  something_database(*(_DWORD *)v810, v809, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5317);
  v811 = (int)std_string_append(&v7455, (int)&Dst, "undead-hair-f06.cub");
  v7813 = 349;
  v812 = this_4pointer_off((void *)v6, 326);
  something_database(*(_DWORD *)v812, v811, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7455);
  v813 = (int)std_string_append(&v6351, (int)&Dst, "undead-hand.cub");
  v7813 = 350;
  v814 = this_4pointer_off((void *)v6, 327);
  something_database(*(_DWORD *)v814, v813, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6351);
  v815 = (int)std_string_append(&v7453, (int)&Dst, "skeleton-eyes.cub");
  v7813 = 351;
  v816 = this_4pointer_off((void *)v6, 329);
  something_database(*(_DWORD *)v816, v815, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7453);
  v817 = (int)std_string_append(&v5799, (int)&Dst, "skeleton-head.cub");
  v7813 = 352;
  v818 = this_4pointer_off((void *)v6, 328);
  something_database(*(_DWORD *)v818, v817, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5799);
  v819 = (int)std_string_append(&v7451, (int)&Dst, "skeleton-hand.cub");
  v7813 = 353;
  v820 = this_4pointer_off((void *)v6, 330);
  something_database(*(_DWORD *)v820, v819, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7451);
  v821 = (int)std_string_append(&v6349, (int)&Dst, "skeleton-body.cub");
  v7813 = 354;
  v822 = this_4pointer_off((void *)v6, 331);
  something_database(*(_DWORD *)v822, v821, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6349);
  v823 = (int)std_string_append(&v7449, (int)&Dst, "skeleton-foot.cub");
  v7813 = 355;
  v824 = this_4pointer_off((void *)v6, 332);
  something_database(*(_DWORD *)v824, v823, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7449);
  v825 = (int)std_string_append(&v5523, (int)&Dst, "wizard-head.cub");
  v7813 = 356;
  v826 = this_4pointer_off((void *)v6, 3);
  something_database(*(_DWORD *)v826, v825, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5523);
  v827 = (int)std_string_append(&v7447, (int)&Dst, "wizard-body.cub");
  v7813 = 357;
  v828 = this_4pointer_off((void *)v6, 4);
  something_database(*(_DWORD *)v828, v827, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7447);
  v829 = (int)std_string_append(&v6347, (int)&Dst, "witch-head.cub");
  v7813 = 358;
  v830 = this_4pointer_off((void *)v6, 5);
  something_database(*(_DWORD *)v830, v829, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6347);
  v831 = (int)std_string_append(&v7445, (int)&Dst, "witch-body.cub");
  v7813 = 359;
  v832 = this_4pointer_off((void *)v6, 6);
  something_database(*(_DWORD *)v832, v831, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7445);
  v833 = (int)std_string_append(&v5797, (int)&Dst, "santa-head.cub");
  v7813 = 360;
  v834 = this_4pointer_off((void *)v6, 225);
  something_database(*(_DWORD *)v834, v833, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5797);
  v835 = (int)std_string_append(&v7443, (int)&Dst, "santa-body.cub");
  v7813 = 361;
  v836 = this_4pointer_off((void *)v6, 224);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v835;
  something_database(*(_DWORD *)v836, v835, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7443);
  v837 = (int)std_string_append(&v6345, (int)&Dst, "werewolf-body.cub");
  v7813 = 362;
  v838 = this_4pointer_off((void *)v6, 2169);
  something_database(*(_DWORD *)v838, v837, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6345);
  v839 = (int)std_string_append(&v7441, (int)&Dst, "werewolf-hand.cub");
  v7813 = 363;
  v840 = this_4pointer_off((void *)v6, 2168);
  something_database(*(_DWORD *)v840, v839, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7441);
  v841 = (int)std_string_append(&v5385, (int)&Dst, "werewolf-head.cub");
  v7813 = 364;
  v842 = this_4pointer_off((void *)v6, 2167);
  something_database(*(_DWORD *)v842, v841, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5385);
  v843 = (int)std_string_append(&v7439, (int)&Dst, "werewolf-foot.cub");
  v7813 = 365;
  v844 = this_4pointer_off((void *)v6, 2170);
  something_database(*(_DWORD *)v844, v843, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7439);
  v845 = (int)std_string_append(&v6343, (int)&Dst, "zombie-body.cub");
  v7813 = 366;
  v846 = this_4pointer_off((void *)v6, 226);
  something_database(*(_DWORD *)v846, v845, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6343);
  v847 = (int)std_string_append(&v7437, (int)&Dst, "zombie-hand.cub");
  v7813 = 367;
  v848 = this_4pointer_off((void *)v6, 229);
  something_database(*(_DWORD *)v848, v847, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7437);
  v849 = (int)std_string_append(&v5795, (int)&Dst, "zombie-head.cub");
  v7813 = 368;
  v850 = this_4pointer_off((void *)v6, 227);
  something_database(*(_DWORD *)v850, v849, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5795);
  v851 = (int)std_string_append(&v7435, (int)&Dst, "foot.cub");
  v7813 = 369;
  v852 = this_4pointer_off((void *)v6, 228);
  something_database(*(_DWORD *)v852, v851, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7435);
  v853 = (int)std_string_append(&v6341, (int)&Dst, "lich-body.cub");
  v7813 = 370;
  v854 = this_4pointer_off((void *)v6, 278);
  something_database(*(_DWORD *)v854, v853, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6341);
  v855 = (int)std_string_append(&v7433, (int)&Dst, "lich-hand.cub");
  v7813 = 371;
  v856 = this_4pointer_off((void *)v6, 280);
  something_database(*(_DWORD *)v856, v855, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7433);
  v857 = (int)std_string_append(&v5521, (int)&Dst, "lich-head.cub");
  v7813 = 372;
  v858 = this_4pointer_off((void *)v6, 279);
  something_database(*(_DWORD *)v858, v857, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5521);
  v859 = (int)std_string_append(&v7431, (int)&Dst, "lich-arm.cub");
  v7813 = 373;
  v860 = this_4pointer_off((void *)v6, 281);
  something_database(*(_DWORD *)v860, v859, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7431);
  v861 = (int)std_string_append(&v6339, (int)&Dst, "frog-body.cub");
  v7813 = 374;
  v862 = this_4pointer_off((void *)v6, 114);
  something_database(*(_DWORD *)v862, v861, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6339);
  v863 = (int)std_string_append(&v7429, (int)&Dst, "frog-hand.cub");
  v7813 = 375;
  v864 = this_4pointer_off((void *)v6, 117);
  something_database(*(_DWORD *)v864, v863, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7429);
  v865 = (int)std_string_append(&v5793, (int)&Dst, "frog-head.cub");
  v7813 = 376;
  v866 = this_4pointer_off((void *)v6, 115);
  something_database(*(_DWORD *)v866, v865, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5793);
  v867 = (int)std_string_append(&v7427, (int)&Dst, "frog-foot.cub");
  v7813 = 377;
  v868 = this_4pointer_off((void *)v6, 116);
  something_database(*(_DWORD *)v868, v867, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7427);
  v869 = (int)std_string_append(&v6337, (int)&Dst, "plant-creature-body.cub");
  v7813 = 378;
  v870 = this_4pointer_off((void *)v6, 118);
  something_database(*(_DWORD *)v870, v869, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6337);
  v871 = (int)std_string_append(&v7425, (int)&Dst, "plant-creature-hand.cub");
  v7813 = 379;
  v872 = this_4pointer_off((void *)v6, 121);
  something_database(*(_DWORD *)v872, v871, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7425);
  v873 = (int)std_string_append(&v5265, (int)&Dst, "plant-creature-head.cub");
  v7813 = 380;
  v874 = this_4pointer_off((void *)v6, 119);
  something_database(*(_DWORD *)v874, v873, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5265);
  v875 = (int)std_string_append(&v7423, (int)&Dst, "plant-creature-foot.cub");
  v7813 = 381;
  v876 = this_4pointer_off((void *)v6, 120);
  something_database(*(_DWORD *)v876, v875, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7423);
  v877 = (int)std_string_append(&v6335, (int)&Dst, "radish-creature-head.cub");
  v7813 = 382;
  v878 = this_4pointer_off((void *)v6, 122);
  something_database(*(_DWORD *)v878, v877, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6335);
  v879 = (int)std_string_append(&v7421, (int)&Dst, "radish-creature-hand.cub");
  v7813 = 383;
  v880 = this_4pointer_off((void *)v6, 124);
  something_database(*(_DWORD *)v880, v879, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7421);
  v881 = (int)std_string_append(&v5791, (int)&Dst, "radish-creature-foot.cub");
  v7813 = 384;
  v882 = this_4pointer_off((void *)v6, 123);
  something_database(*(_DWORD *)v882, v881, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5791);
  v883 = (int)std_string_append(&v7419, (int)&Dst, "onionling-head.cub");
  v7813 = 385;
  v884 = this_4pointer_off((void *)v6, 125);
  something_database(*(_DWORD *)v884, v883, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7419);
  v885 = (int)std_string_append(&v6333, (int)&Dst, "onionling-foot.cub");
  v7813 = 386;
  v886 = this_4pointer_off((void *)v6, 126);
  something_database(*(_DWORD *)v886, v885, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6333);
  v887 = (int)std_string_append(&v7417, (int)&Dst, "desert-onionling.cub");
  v7813 = 387;
  v888 = this_4pointer_off((void *)v6, 127);
  something_database(*(_DWORD *)v888, v887, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7417);
  v889 = (int)std_string_append(&v5519, (int)&Dst, "desert-onionling-foot.cub");
  v7813 = 388;
  v890 = this_4pointer_off((void *)v6, 128);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v889;
  something_database(*(_DWORD *)v890, v889, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5519);
  v891 = (int)std_string_append(&v7415, (int)&Dst, "devourer-head.cub");
  v7813 = 389;
  v892 = this_4pointer_off((void *)v6, 129);
  something_database(*(_DWORD *)v892, v891, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7415);
  v893 = (int)std_string_append(&v6331, (int)&Dst, "devourer-foot.cub");
  v7813 = 390;
  v894 = this_4pointer_off((void *)v6, 130);
  something_database(*(_DWORD *)v894, v893, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6331);
  v895 = (int)std_string_append(&v7413, (int)&Dst, "mole-body.cub");
  v7813 = 391;
  v896 = this_4pointer_off((void *)v6, 131);
  something_database(*(_DWORD *)v896, v895, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7413);
  v897 = (int)std_string_append(&v5789, (int)&Dst, "mole-hand.cub");
  v7813 = 392;
  v898 = this_4pointer_off((void *)v6, 134);
  something_database(*(_DWORD *)v898, v897, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5789);
  v899 = (int)std_string_append(&v7411, (int)&Dst, "mole-head.cub");
  v7813 = 393;
  v900 = this_4pointer_off((void *)v6, 132);
  something_database(*(_DWORD *)v900, v899, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7411);
  v901 = (int)std_string_append(&v6329, (int)&Dst, "mole-foot.cub");
  v7813 = 394;
  v902 = this_4pointer_off((void *)v6, 133);
  something_database(*(_DWORD *)v902, v901, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6329);
  v903 = (int)std_string_append(&v7409, (int)&Dst, "biter-body.cub");
  v7813 = 395;
  v904 = this_4pointer_off((void *)v6, 135);
  something_database(*(_DWORD *)v904, v903, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7409);
  v905 = (int)std_string_append(&v5383, (int)&Dst, "biter-hand.cub");
  v7813 = 396;
  v906 = this_4pointer_off((void *)v6, 138);
  something_database(*(_DWORD *)v906, v905, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5383);
  v907 = (int)std_string_append(&v7407, (int)&Dst, "biter-head.cub");
  v7813 = 397;
  v908 = this_4pointer_off((void *)v6, 136);
  something_database(*(_DWORD *)v908, v907, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7407);
  v909 = (int)std_string_append(&v6327, (int)&Dst, "biter-foot.cub");
  v7813 = 398;
  v910 = this_4pointer_off((void *)v6, 137);
  something_database(*(_DWORD *)v910, v909, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6327);
  v911 = (int)std_string_append(&v7405, (int)&Dst, "koala-body.cub");
  v7813 = 399;
  v912 = this_4pointer_off((void *)v6, 139);
  something_database(*(_DWORD *)v912, v911, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7405);
  v913 = (int)std_string_append(&v5787, (int)&Dst, "koala-hand.cub");
  v7813 = 400;
  v914 = this_4pointer_off((void *)v6, 142);
  something_database(*(_DWORD *)v914, v913, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5787);
  v915 = (int)std_string_append(&v7403, (int)&Dst, "koala-head.cub");
  v7813 = 401;
  v916 = this_4pointer_off((void *)v6, 140);
  something_database(*(_DWORD *)v916, v915, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7403);
  v917 = (int)std_string_append(&v6325, (int)&Dst, "koala-foot.cub");
  v7813 = 402;
  v918 = this_4pointer_off((void *)v6, 141);
  something_database(*(_DWORD *)v918, v917, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6325);
  v919 = (int)std_string_append(&v7401, (int)&Dst, "squirrel-body.cub");
  v7813 = 403;
  v920 = this_4pointer_off((void *)v6, 143);
  something_database(*(_DWORD *)v920, v919, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7401);
  v921 = (int)std_string_append(&v5517, (int)&Dst, "squirrel-hand.cub");
  v7813 = 404;
  v922 = this_4pointer_off((void *)v6, 146);
  something_database(*(_DWORD *)v922, v921, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5517);
  v923 = (int)std_string_append(&v7399, (int)&Dst, "squirrel-head.cub");
  v7813 = 405;
  v924 = this_4pointer_off((void *)v6, 144);
  something_database(*(_DWORD *)v924, v923, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7399);
  v925 = (int)std_string_append(&v6323, (int)&Dst, "squirrel-foot.cub");
  v7813 = 406;
  v926 = this_4pointer_off((void *)v6, 145);
  something_database(*(_DWORD *)v926, v925, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6323);
  v927 = (int)std_string_append(&v7397, (int)&Dst, "raccoon-body.cub");
  v7813 = 407;
  v928 = this_4pointer_off((void *)v6, 147);
  something_database(*(_DWORD *)v928, v927, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7397);
  v929 = (int)std_string_append(&v5785, (int)&Dst, "raccoon-hand.cub");
  v7813 = 408;
  v930 = this_4pointer_off((void *)v6, 150);
  something_database(*(_DWORD *)v930, v929, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5785);
  v931 = (int)std_string_append(&v7395, (int)&Dst, "raccoon-head.cub");
  v7813 = 409;
  v932 = this_4pointer_off((void *)v6, 148);
  something_database(*(_DWORD *)v932, v931, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7395);
  v933 = (int)std_string_append(&v6321, (int)&Dst, "raccoon-foot.cub");
  v7813 = 410;
  v934 = this_4pointer_off((void *)v6, 149);
  something_database(*(_DWORD *)v934, v933, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6321);
  v935 = (int)std_string_append(&v7393, (int)&Dst, "owl-hand.cub");
  v7813 = 411;
  v936 = this_4pointer_off((void *)v6, 153);
  something_database(*(_DWORD *)v936, v935, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7393);
  v937 = (int)std_string_append(&v5315, (int)&Dst, "owl-head.cub");
  v7813 = 412;
  v938 = this_4pointer_off((void *)v6, 151);
  something_database(*(_DWORD *)v938, v937, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5315);
  v939 = (int)std_string_append(&v7391, (int)&Dst, "owl-foot.cub");
  v7813 = 413;
  v940 = this_4pointer_off((void *)v6, 152);
  something_database(*(_DWORD *)v940, v939, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7391);
  v941 = (int)std_string_append(&v6319, (int)&Dst, "penguin-body.cub");
  v7813 = 414;
  v942 = this_4pointer_off((void *)v6, 204);
  something_database(*(_DWORD *)v942, v941, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6319);
  v943 = (int)std_string_append(&v7389, (int)&Dst, "penguin-hand.cub");
  v7813 = 415;
  v944 = this_4pointer_off((void *)v6, 207);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v943;
  something_database(*(_DWORD *)v944, v943, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7389);
  v945 = (int)std_string_append(&v5783, (int)&Dst, "penguin-head.cub");
  v7813 = 416;
  v946 = this_4pointer_off((void *)v6, 205);
  something_database(*(_DWORD *)v946, v945, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5783);
  v947 = (int)std_string_append(&v7387, (int)&Dst, "penguin-foot.cub");
  v7813 = 417;
  v948 = this_4pointer_off((void *)v6, 206);
  something_database(*(_DWORD *)v948, v947, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7387);
  v949 = (int)std_string_append(&v6317, (int)&Dst, "crab-body.cub");
  v7813 = 418;
  v950 = this_4pointer_off((void *)v6, 208);
  something_database(*(_DWORD *)v950, v949, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6317);
  v951 = (int)std_string_append(&v7385, (int)&Dst, "crab-hand.cub");
  v7813 = 419;
  v952 = this_4pointer_off((void *)v6, 211);
  something_database(*(_DWORD *)v952, v951, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7385);
  v953 = (int)std_string_append(&v5515, (int)&Dst, "crab-head.cub");
  v7813 = 420;
  v954 = this_4pointer_off((void *)v6, 209);
  something_database(*(_DWORD *)v954, v953, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5515);
  v955 = (int)std_string_append(&v7383, (int)&Dst, "crab-foot.cub");
  v7813 = 421;
  v956 = this_4pointer_off((void *)v6, 210);
  something_database(*(_DWORD *)v956, v955, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7383);
  v957 = (int)std_string_append(&v6315, (int)&Dst, "hornet-body.cub");
  v7813 = 422;
  v958 = this_4pointer_off((void *)v6, 230);
  something_database(*(_DWORD *)v958, v957, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6315);
  v959 = (int)std_string_append(&v7381, (int)&Dst, "hornet-hand.cub");
  v7813 = 423;
  v960 = this_4pointer_off((void *)v6, 233);
  something_database(*(_DWORD *)v960, v959, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7381);
  v961 = (int)std_string_append(&v5781, (int)&Dst, "hornet-head.cub");
  v7813 = 424;
  v962 = this_4pointer_off((void *)v6, 231);
  something_database(*(_DWORD *)v962, v961, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5781);
  v963 = (int)std_string_append(&v7379, (int)&Dst, "hornet-foot.cub");
  v7813 = 425;
  v964 = this_4pointer_off((void *)v6, 232);
  something_database(*(_DWORD *)v964, v963, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7379);
  v965 = (int)std_string_append(&v6313, (int)&Dst, "insect-guard-body.cub");
  v7813 = 426;
  v966 = this_4pointer_off((void *)v6, 234);
  something_database(*(_DWORD *)v966, v965, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6313);
  v967 = (int)std_string_append(&v7377, (int)&Dst, "insect-guard-wing.cub");
  v7813 = 427;
  v968 = this_4pointer_off((void *)v6, 238);
  something_database(*(_DWORD *)v968, v967, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7377);
  v969 = (int)std_string_append(&v5381, (int)&Dst, "insect-guard-head.cub");
  v7813 = 428;
  v970 = this_4pointer_off((void *)v6, 235);
  something_database(*(_DWORD *)v970, v969, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5381);
  v971 = (int)std_string_append(&v7375, (int)&Dst, "insect-guard-hand.cub");
  v7813 = 429;
  v972 = this_4pointer_off((void *)v6, 237);
  something_database(*(_DWORD *)v972, v971, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7375);
  v973 = (int)std_string_append(&v6311, (int)&Dst, "insect-guard-foot.cub");
  v7813 = 430;
  v974 = this_4pointer_off((void *)v6, 236);
  something_database(*(_DWORD *)v974, v973, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6311);
  v975 = (int)std_string_append(&v7373, (int)&Dst, "fly-body.cub");
  v7813 = 431;
  v976 = this_4pointer_off((void *)v6, 239);
  something_database(*(_DWORD *)v976, v975, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7373);
  v977 = (int)std_string_append(&v5779, (int)&Dst, "fly-hand.cub");
  v7813 = 432;
  v978 = this_4pointer_off((void *)v6, 242);
  something_database(*(_DWORD *)v978, v977, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5779);
  v979 = (int)std_string_append(&v7371, (int)&Dst, "fly-head.cub");
  v7813 = 433;
  v980 = this_4pointer_off((void *)v6, 240);
  something_database(*(_DWORD *)v980, v979, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7371);
  v981 = (int)std_string_append(&v6309, (int)&Dst, "fly-foot.cub");
  v7813 = 434;
  v982 = this_4pointer_off((void *)v6, 241);
  something_database(*(_DWORD *)v982, v981, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6309);
  v983 = (int)std_string_append(&v7369, (int)&Dst, "bumblebee.cub");
  v7813 = 435;
  v984 = this_4pointer_off((void *)v6, 243);
  something_database(*(_DWORD *)v984, v983, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7369);
  v985 = (int)std_string_append(&v5513, (int)&Dst, "bumblebee-hand.cub");
  v7813 = 436;
  v986 = this_4pointer_off((void *)v6, 244);
  something_database(*(_DWORD *)v986, v985, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5513);
  v987 = (int)std_string_append(&v7367, (int)&Dst, "bumblebee-foot.cub");
  v7813 = 437;
  v988 = this_4pointer_off((void *)v6, 245);
  something_database(*(_DWORD *)v988, v987, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7367);
  v989 = (int)std_string_append(&v6307, (int)&Dst, "midge-body.cub");
  v7813 = 438;
  v990 = this_4pointer_off((void *)v6, 246);
  something_database(*(_DWORD *)v990, v989, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6307);
  v991 = (int)std_string_append(&v7365, (int)&Dst, "midge-hand.cub");
  v7813 = 439;
  v992 = this_4pointer_off((void *)v6, 249);
  something_database(*(_DWORD *)v992, v991, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7365);
  v993 = (int)std_string_append(&v5777, (int)&Dst, "midge-head.cub");
  v7813 = 440;
  v994 = this_4pointer_off((void *)v6, 247);
  something_database(*(_DWORD *)v994, v993, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5777);
  v995 = (int)std_string_append(&v7363, (int)&Dst, "midge-foot.cub");
  v7813 = 441;
  v996 = this_4pointer_off((void *)v6, 248);
  something_database(*(_DWORD *)v996, v995, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7363);
  v997 = (int)std_string_append(&v6305, (int)&Dst, "mosquito-body.cub");
  v7813 = 442;
  v998 = this_4pointer_off((void *)v6, 250);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v997;
  something_database(*(_DWORD *)v998, v997, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6305);
  v999 = (int)std_string_append(&v7361, (int)&Dst, "mosquito-hand.cub");
  v7813 = 443;
  v1000 = this_4pointer_off((void *)v6, 253);
  something_database(*(_DWORD *)v1000, v999, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7361);
  v1001 = (int)std_string_append(&v5281, (int)&Dst, "mosquito-head.cub");
  v7813 = 444;
  v1002 = this_4pointer_off((void *)v6, 251);
  something_database(*(_DWORD *)v1002, v1001, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5281);
  v1003 = (int)std_string_append(&v7359, (int)&Dst, "mosquito-foot.cub");
  v7813 = 445;
  v1004 = this_4pointer_off((void *)v6, 252);
  something_database(*(_DWORD *)v1004, v1003, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7359);
  v1005 = (int)std_string_append(&v6303, (int)&Dst, "ginseng.cub");
  v7813 = 446;
  v1006 = this_4pointer_off((void *)v6, 2096);
  something_database(*(_DWORD *)v1006, v1005, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6303);
  v1007 = (int)std_string_append(&v7357, (int)&Dst, "ginseng-root.cub");
  v7813 = 447;
  v1008 = this_4pointer_off((void *)v6, 2097);
  something_database(*(_DWORD *)v1008, v1007, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7357);
  v1009 = (int)std_string_append(&v5775, (int)&Dst, "crow-body.cub");
  v7813 = 448;
  v1010 = this_4pointer_off((void *)v6, 254);
  something_database(*(_DWORD *)v1010, v1009, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5775);
  v1011 = (int)std_string_append(&v7355, (int)&Dst, "crow-hand.cub");
  v7813 = 449;
  v1012 = this_4pointer_off((void *)v6, 257);
  something_database(*(_DWORD *)v1012, v1011, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7355);
  v1013 = (int)std_string_append(&v6301, (int)&Dst, "crow-head.cub");
  v7813 = 450;
  v1014 = this_4pointer_off((void *)v6, 255);
  something_database(*(_DWORD *)v1014, v1013, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6301);
  v1015 = (int)std_string_append(&v7353, (int)&Dst, "crow-foot.cub");
  v7813 = 451;
  v1016 = this_4pointer_off((void *)v6, 256);
  something_database(*(_DWORD *)v1016, v1015, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7353);
  v1017 = (int)std_string_append(&v5511, (int)&Dst, "chicken-body.cub");
  v7813 = 452;
  v1018 = this_4pointer_off((void *)v6, 258);
  something_database(*(_DWORD *)v1018, v1017, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5511);
  v1019 = (int)std_string_append(&v7351, (int)&Dst, "chicken-hand.cub");
  v7813 = 453;
  v1020 = this_4pointer_off((void *)v6, 261);
  something_database(*(_DWORD *)v1020, v1019, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7351);
  v1021 = (int)std_string_append(&v6299, (int)&Dst, "chicken-head.cub");
  v7813 = 454;
  v1022 = this_4pointer_off((void *)v6, 259);
  something_database(*(_DWORD *)v1022, v1021, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6299);
  v1023 = (int)std_string_append(&v7349, (int)&Dst, "chicken-foot.cub");
  v7813 = 455;
  v1024 = this_4pointer_off((void *)v6, 260);
  something_database(*(_DWORD *)v1024, v1023, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7349);
  v1025 = (int)std_string_append(&v5773, (int)&Dst, "parrot-body.cub");
  v7813 = 456;
  v1026 = this_4pointer_off((void *)v6, 266);
  something_database(*(_DWORD *)v1026, v1025, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5773);
  v1027 = (int)std_string_append(&v7347, (int)&Dst, "parrot-hand.cub");
  v7813 = 457;
  v1028 = this_4pointer_off((void *)v6, 269);
  something_database(*(_DWORD *)v1028, v1027, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7347);
  v1029 = (int)std_string_append(&v6297, (int)&Dst, "parrot-head.cub");
  v7813 = 458;
  v1030 = this_4pointer_off((void *)v6, 267);
  something_database(*(_DWORD *)v1030, v1029, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6297);
  v1031 = (int)std_string_append(&v7345, (int)&Dst, "parrot-foot.cub");
  v7813 = 459;
  v1032 = this_4pointer_off((void *)v6, 268);
  something_database(*(_DWORD *)v1032, v1031, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7345);
  v1033 = (int)std_string_append(&v5379, (int)&Dst, "parrot-blue-body.cub");
  v7813 = 460;
  v1034 = this_4pointer_off((void *)v6, 270);
  something_database(*(_DWORD *)v1034, v1033, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5379);
  v1035 = (int)std_string_append(&v7343, (int)&Dst, "parrot-blue-hand.cub");
  v7813 = 461;
  v1036 = this_4pointer_off((void *)v6, 273);
  something_database(*(_DWORD *)v1036, v1035, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7343);
  v1037 = (int)std_string_append(&v6295, (int)&Dst, "parrot-blue-head.cub");
  v7813 = 462;
  v1038 = this_4pointer_off((void *)v6, 271);
  something_database(*(_DWORD *)v1038, v1037, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6295);
  v1039 = (int)std_string_append(&v7341, (int)&Dst, "parrot-blue-foot.cub");
  v7813 = 463;
  v1040 = this_4pointer_off((void *)v6, 272);
  something_database(*(_DWORD *)v1040, v1039, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7341);
  v1041 = (int)std_string_append(&v5771, (int)&Dst, "barkbeetle-head.cub");
  v7813 = 464;
  v1042 = this_4pointer_off((void *)v6, 216);
  something_database(*(_DWORD *)v1042, v1041, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5771);
  v1043 = (int)std_string_append(&v7339, (int)&Dst, "barkbeetle-foot.cub");
  v7813 = 465;
  v1044 = this_4pointer_off((void *)v6, 217);
  something_database(*(_DWORD *)v1044, v1043, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7339);
  v1045 = (int)std_string_append(&v6293, (int)&Dst, "firebeetle-head.cub");
  v7813 = 466;
  v1046 = this_4pointer_off((void *)v6, 218);
  something_database(*(_DWORD *)v1046, v1045, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6293);
  v1047 = (int)std_string_append(&v7337, (int)&Dst, "firebeetle-foot.cub");
  v7813 = 467;
  v1048 = this_4pointer_off((void *)v6, 219);
  something_database(*(_DWORD *)v1048, v1047, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7337);
  v1049 = (int)std_string_append(&v5509, (int)&Dst, "snoutbeetle-head.cub");
  v7813 = 468;
  v1050 = this_4pointer_off((void *)v6, 220);
  something_database(*(_DWORD *)v1050, v1049, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5509);
  v1051 = (int)std_string_append(&v7335, (int)&Dst, "snoutbeetle-foot.cub");
  v7813 = 469;
  v1052 = this_4pointer_off((void *)v6, 221);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1051;
  something_database(*(_DWORD *)v1052, v1051, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7335);
  v1053 = (int)std_string_append(&v6291, (int)&Dst, "lemonbeetle-head.cub");
  v7813 = 470;
  v1054 = this_4pointer_off((void *)v6, 222);
  something_database(*(_DWORD *)v1054, v1053, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6291);
  v1055 = (int)std_string_append(&v7333, (int)&Dst, "lemonbeetle-foot.cub");
  v7813 = 471;
  v1056 = this_4pointer_off((void *)v6, 223);
  something_database(*(_DWORD *)v1056, v1055, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7333);
  v1057 = (int)std_string_append(&v5769, (int)&Dst, "seagull-body.cub");
  v7813 = 472;
  v1058 = this_4pointer_off((void *)v6, 262);
  something_database(*(_DWORD *)v1058, v1057, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5769);
  v1059 = (int)std_string_append(&v7331, (int)&Dst, "seagull-hand.cub");
  v7813 = 473;
  v1060 = this_4pointer_off((void *)v6, 265);
  something_database(*(_DWORD *)v1060, v1059, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7331);
  v1061 = (int)std_string_append(&v6289, (int)&Dst, "seagull-head.cub");
  v7813 = 474;
  v1062 = this_4pointer_off((void *)v6, 263);
  something_database(*(_DWORD *)v1062, v1061, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6289);
  v1063 = (int)std_string_append(&v7329, (int)&Dst, "seagull-foot.cub");
  v7813 = 475;
  v1064 = this_4pointer_off((void *)v6, 264);
  something_database(*(_DWORD *)v1064, v1063, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7329);
  v1065 = (int)std_string_append(&v5313, (int)&Dst, "bat-body.cub");
  v7813 = 476;
  v1066 = this_4pointer_off((void *)v6, 274);
  something_database(*(_DWORD *)v1066, v1065, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5313);
  v1067 = (int)std_string_append(&v7327, (int)&Dst, "bat-hand.cub");
  v7813 = 477;
  v1068 = this_4pointer_off((void *)v6, 277);
  something_database(*(_DWORD *)v1068, v1067, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7327);
  v1069 = (int)std_string_append(&v6287, (int)&Dst, "bat-head.cub");
  v7813 = 478;
  v1070 = this_4pointer_off((void *)v6, 275);
  something_database(*(_DWORD *)v1070, v1069, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6287);
  v1071 = (int)std_string_append(&v7325, (int)&Dst, "bat-foot.cub");
  v7813 = 479;
  v1072 = this_4pointer_off((void *)v6, 276);
  something_database(*(_DWORD *)v1072, v1071, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7325);
  v1073 = (int)std_string_append(&v5767, (int)&Dst, "pony-body.cub");
  v7813 = 480;
  v1074 = this_4pointer_off((void *)v6, 344);
  something_database(*(_DWORD *)v1074, v1073, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5767);
  v1075 = (int)std_string_append(&v7323, (int)&Dst, "pony-head.cub");
  v7813 = 481;
  v1076 = this_4pointer_off((void *)v6, 345);
  something_database(*(_DWORD *)v1076, v1075, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7323);
  v1077 = (int)std_string_append(&v6285, (int)&Dst, "pony-foot.cub");
  v7813 = 482;
  v1078 = this_4pointer_off((void *)v6, 346);
  something_database(*(_DWORD *)v1078, v1077, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6285);
  v1079 = (int)std_string_append(&v7321, (int)&Dst, "pony-tail.cub");
  v7813 = 483;
  v1080 = this_4pointer_off((void *)v6, 347);
  something_database(*(_DWORD *)v1080, v1079, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7321);
  v1081 = (int)std_string_append(&v5507, (int)&Dst, "camel-body.cub");
  v7813 = 484;
  v1082 = this_4pointer_off((void *)v6, 348);
  something_database(*(_DWORD *)v1082, v1081, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5507);
  v1083 = (int)std_string_append(&v7319, (int)&Dst, "camel-head.cub");
  v7813 = 485;
  v1084 = this_4pointer_off((void *)v6, 349);
  something_database(*(_DWORD *)v1084, v1083, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7319);
  v1085 = (int)std_string_append(&v6283, (int)&Dst, "camel-foot.cub");
  v7813 = 486;
  v1086 = this_4pointer_off((void *)v6, 350);
  something_database(*(_DWORD *)v1086, v1085, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6283);
  v1087 = (int)std_string_append(&v7317, (int)&Dst, "cow-body.cub");
  v7813 = 487;
  v1088 = this_4pointer_off((void *)v6, 351);
  something_database(*(_DWORD *)v1088, v1087, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7317);
  v1089 = (int)std_string_append(&v5765, (int)&Dst, "cow-head.cub");
  v7813 = 488;
  v1090 = this_4pointer_off((void *)v6, 352);
  something_database(*(_DWORD *)v1090, v1089, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5765);
  v1091 = (int)std_string_append(&v7315, (int)&Dst, "cow-foot.cub");
  v7813 = 489;
  v1092 = this_4pointer_off((void *)v6, 353);
  something_database(*(_DWORD *)v1092, v1091, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7315);
  v1093 = (int)std_string_append(&v6281, (int)&Dst, "collie-body.cub");
  v7813 = 490;
  v1094 = this_4pointer_off((void *)v6, 354);
  something_database(*(_DWORD *)v1094, v1093, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6281);
  v1095 = (int)std_string_append(&v7313, (int)&Dst, "collie-head.cub");
  v7813 = 491;
  v1096 = this_4pointer_off((void *)v6, 355);
  something_database(*(_DWORD *)v1096, v1095, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7313);
  v1097 = (int)std_string_append(&v5377, (int)&Dst, "collie-foot.cub");
  v7813 = 492;
  v1098 = this_4pointer_off((void *)v6, 357);
  something_database(*(_DWORD *)v1098, v1097, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5377);
  v1099 = (int)std_string_append(&v7311, (int)&Dst, "collie-hand.cub");
  v7813 = 493;
  v1100 = this_4pointer_off((void *)v6, 356);
  something_database(*(_DWORD *)v1100, v1099, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7311);
  v1101 = (int)std_string_append(&v6279, (int)&Dst, "collie-tail.cub");
  v7813 = 494;
  v1102 = this_4pointer_off((void *)v6, 358);
  something_database(*(_DWORD *)v1102, v1101, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6279);
  v1103 = (int)std_string_append(&v7309, (int)&Dst, "shepherd-dog-body.cub");
  v7813 = 495;
  v1104 = this_4pointer_off((void *)v6, 359);
  something_database(*(_DWORD *)v1104, v1103, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7309);
  v1105 = (int)std_string_append(&v5763, (int)&Dst, "shepherd-dog-head.cub");
  v7813 = 496;
  v1106 = this_4pointer_off((void *)v6, 360);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1105;
  something_database(*(_DWORD *)v1106, v1105, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5763);
  v1107 = (int)std_string_append(&v7307, (int)&Dst, "shepherd-dog-foot.cub");
  v7813 = 497;
  v1108 = this_4pointer_off((void *)v6, 362);
  something_database(*(_DWORD *)v1108, v1107, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7307);
  v1109 = (int)std_string_append(&v6277, (int)&Dst, "shepherd-dog-hand.cub");
  v7813 = 498;
  v1110 = this_4pointer_off((void *)v6, 361);
  something_database(*(_DWORD *)v1110, v1109, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6277);
  v1111 = (int)std_string_append(&v7305, (int)&Dst, "shepherd-dog-tail.cub");
  v7813 = 499;
  v1112 = this_4pointer_off((void *)v6, 363);
  something_database(*(_DWORD *)v1112, v1111, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7305);
  v1113 = (int)std_string_append(&v5505, (int)&Dst, "skull-bull-body.cub");
  v7813 = 500;
  v1114 = this_4pointer_off((void *)v6, 364);
  something_database(*(_DWORD *)v1114, v1113, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5505);
  v1115 = (int)std_string_append(&v7303, (int)&Dst, "skull-bull-head.cub");
  v7813 = 501;
  v1116 = this_4pointer_off((void *)v6, 365);
  something_database(*(_DWORD *)v1116, v1115, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7303);
  v1117 = (int)std_string_append(&v6275, (int)&Dst, "skull-bull-foot.cub");
  v7813 = 502;
  v1118 = this_4pointer_off((void *)v6, 367);
  something_database(*(_DWORD *)v1118, v1117, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6275);
  v1119 = (int)std_string_append(&v7301, (int)&Dst, "skull-bull-hand.cub");
  v7813 = 503;
  v1120 = this_4pointer_off((void *)v6, 366);
  something_database(*(_DWORD *)v1120, v1119, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7301);
  v1121 = (int)std_string_append(&v5761, (int)&Dst, "skull-bull-tail.cub");
  v7813 = 504;
  v1122 = this_4pointer_off((void *)v6, 368);
  something_database(*(_DWORD *)v1122, v1121, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5761);
  v1123 = (int)std_string_append(&v7299, (int)&Dst, "alpaca-body.cub");
  v7813 = 505;
  v1124 = this_4pointer_off((void *)v6, 369);
  something_database(*(_DWORD *)v1124, v1123, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7299);
  v1125 = (int)std_string_append(&v6273, (int)&Dst, "alpaca-head.cub");
  v7813 = 506;
  v1126 = this_4pointer_off((void *)v6, 370);
  something_database(*(_DWORD *)v1126, v1125, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6273);
  v1127 = (int)std_string_append(&v7297, (int)&Dst, "alpaca-foot.cub");
  v7813 = 507;
  v1128 = this_4pointer_off((void *)v6, 372);
  something_database(*(_DWORD *)v1128, v1127, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7297);
  v1129 = (int)std_string_append(&v5249, (int)&Dst, "alpaca-hand.cub");
  v7813 = 508;
  v1130 = this_4pointer_off((void *)v6, 371);
  something_database(*(_DWORD *)v1130, v1129, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5249);
  v1131 = (int)std_string_append(&v7295, (int)&Dst, "alpaca-brown-body.cub");
  v7813 = 509;
  v1132 = this_4pointer_off((void *)v6, 373);
  something_database(*(_DWORD *)v1132, v1131, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7295);
  v1133 = (int)std_string_append(&v6271, (int)&Dst, "alpaca-brown-head.cub");
  v7813 = 510;
  v1134 = this_4pointer_off((void *)v6, 374);
  something_database(*(_DWORD *)v1134, v1133, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6271);
  v1135 = (int)std_string_append(&v7293, (int)&Dst, "alpaca-brown-foot.cub");
  v7813 = 511;
  v1136 = this_4pointer_off((void *)v6, 376);
  something_database(*(_DWORD *)v1136, v1135, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7293);
  v1137 = (int)std_string_append(&v5759, (int)&Dst, "alpaca-brown-hand.cub");
  v7813 = 512;
  v1138 = this_4pointer_off((void *)v6, 375);
  something_database(*(_DWORD *)v1138, v1137, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5759);
  v1139 = (int)std_string_append(&v7291, (int)&Dst, "turtle-body.cub");
  v7813 = 513;
  v1140 = this_4pointer_off((void *)v6, 2161);
  something_database(*(_DWORD *)v1140, v1139, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7291);
  v1141 = (int)std_string_append(&v6269, (int)&Dst, "turtle-head.cub");
  v7813 = 514;
  v1142 = this_4pointer_off((void *)v6, 2162);
  something_database(*(_DWORD *)v1142, v1141, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6269);
  v1143 = (int)std_string_append(&v7289, (int)&Dst, "turtle-foot.cub");
  v7813 = 515;
  v1144 = this_4pointer_off((void *)v6, 2163);
  something_database(*(_DWORD *)v1144, v1143, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7289);
  v1145 = (int)std_string_append(&v5503, (int)&Dst, "dog-body2.cub");
  v7813 = 516;
  v1146 = this_4pointer_off((void *)v6, 377);
  something_database(*(_DWORD *)v1146, v1145, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5503);
  v1147 = (int)std_string_append(&v7287, (int)&Dst, "dog-head2.cub");
  v7813 = 517;
  v1148 = this_4pointer_off((void *)v6, 378);
  something_database(*(_DWORD *)v1148, v1147, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7287);
  v1149 = (int)std_string_append(&v6267, (int)&Dst, "dog-foot2.cub");
  v7813 = 518;
  v1150 = this_4pointer_off((void *)v6, 380);
  something_database(*(_DWORD *)v1150, v1149, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6267);
  v1151 = (int)std_string_append(&v7285, (int)&Dst, "dog-hand2.cub");
  v7813 = 519;
  v1152 = this_4pointer_off((void *)v6, 379);
  something_database(*(_DWORD *)v1152, v1151, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7285);
  v1153 = (int)std_string_append(&v5757, (int)&Dst, "dog-tail2.cub");
  v7813 = 520;
  v1154 = this_4pointer_off((void *)v6, 381);
  something_database(*(_DWORD *)v1154, v1153, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5757);
  v1155 = (int)std_string_append(&v7283, (int)&Dst, "scottish-terrier-body.cub");
  v7813 = 521;
  v1156 = this_4pointer_off((void *)v6, 382);
  something_database(*(_DWORD *)v1156, v1155, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7283);
  v1157 = (int)std_string_append(&v6265, (int)&Dst, "scottish-terrier-head.cub");
  v7813 = 522;
  v1158 = this_4pointer_off((void *)v6, 383);
  something_database(*(_DWORD *)v1158, v1157, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6265);
  v1159 = (int)std_string_append(&v7281, (int)&Dst, "scottish-terrier-foot.cub");
  v7813 = 523;
  v1160 = this_4pointer_off((void *)v6, 385);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1159;
  something_database(*(_DWORD *)v1160, v1159, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7281);
  v1161 = (int)std_string_append(&v5375, (int)&Dst, "scottish-terrier-hand.cub");
  v7813 = 524;
  v1162 = this_4pointer_off((void *)v6, 384);
  something_database(*(_DWORD *)v1162, v1161, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5375);
  v1163 = (int)std_string_append(&v7279, (int)&Dst, "scottish-terrier-tail.cub");
  v7813 = 525;
  v1164 = this_4pointer_off((void *)v6, 386);
  something_database(*(_DWORD *)v1164, v1163, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7279);
  v1165 = (int)std_string_append(&v6263, (int)&Dst, "wolf-body.cub");
  v7813 = 526;
  v1166 = this_4pointer_off((void *)v6, 387);
  something_database(*(_DWORD *)v1166, v1165, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6263);
  v1167 = (int)std_string_append(&v7277, (int)&Dst, "wolf-head.cub");
  v7813 = 527;
  v1168 = this_4pointer_off((void *)v6, 388);
  something_database(*(_DWORD *)v1168, v1167, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7277);
  v1169 = (int)std_string_append(&v5755, (int)&Dst, "wolf-foot.cub");
  v7813 = 528;
  v1170 = this_4pointer_off((void *)v6, 390);
  something_database(*(_DWORD *)v1170, v1169, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5755);
  v1171 = (int)std_string_append(&v7275, (int)&Dst, "wolf-hand.cub");
  v7813 = 529;
  v1172 = this_4pointer_off((void *)v6, 389);
  something_database(*(_DWORD *)v1172, v1171, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7275);
  v1173 = (int)std_string_append(&v6261, (int)&Dst, "wolf-tail.cub");
  v7813 = 530;
  v1174 = this_4pointer_off((void *)v6, 391);
  something_database(*(_DWORD *)v1174, v1173, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6261);
  v1175 = (int)std_string_append(&v7273, (int)&Dst, "panther-body.cub");
  v7813 = 531;
  v1176 = this_4pointer_off((void *)v6, 392);
  something_database(*(_DWORD *)v1176, v1175, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7273);
  v1177 = (int)std_string_append(&v5501, (int)&Dst, "panther-head.cub");
  v7813 = 532;
  v1178 = this_4pointer_off((void *)v6, 393);
  something_database(*(_DWORD *)v1178, v1177, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5501);
  v1179 = (int)std_string_append(&v7271, (int)&Dst, "panther-foot.cub");
  v7813 = 533;
  v1180 = this_4pointer_off((void *)v6, 395);
  something_database(*(_DWORD *)v1180, v1179, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7271);
  v1181 = (int)std_string_append(&v6259, (int)&Dst, "panther-hand.cub");
  v7813 = 534;
  v1182 = this_4pointer_off((void *)v6, 394);
  something_database(*(_DWORD *)v1182, v1181, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6259);
  v1183 = (int)std_string_append(&v7269, (int)&Dst, "panther-tail.cub");
  v7813 = 535;
  v1184 = this_4pointer_off((void *)v6, 396);
  something_database(*(_DWORD *)v1184, v1183, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7269);
  v1185 = (int)std_string_append(&v5753, (int)&Dst, "cat-body.cub");
  v7813 = 536;
  v1186 = this_4pointer_off((void *)v6, 397);
  something_database(*(_DWORD *)v1186, v1185, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5753);
  v1187 = (int)std_string_append(&v7267, (int)&Dst, "cat-head.cub");
  v7813 = 537;
  v1188 = this_4pointer_off((void *)v6, 398);
  something_database(*(_DWORD *)v1188, v1187, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7267);
  v1189 = (int)std_string_append(&v6257, (int)&Dst, "cat-foot.cub");
  v7813 = 538;
  v1190 = this_4pointer_off((void *)v6, 400);
  something_database(*(_DWORD *)v1190, v1189, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6257);
  v1191 = (int)std_string_append(&v7265, (int)&Dst, "cat-hand.cub");
  v7813 = 539;
  v1192 = this_4pointer_off((void *)v6, 399);
  something_database(*(_DWORD *)v1192, v1191, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7265);
  v1193 = (int)std_string_append(&v5311, (int)&Dst, "cat-tail.cub");
  v7813 = 540;
  v1194 = this_4pointer_off((void *)v6, 401);
  something_database(*(_DWORD *)v1194, v1193, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5311);
  v1195 = (int)std_string_append(&v7263, (int)&Dst, "cat-body2.cub");
  v7813 = 541;
  v1196 = this_4pointer_off((void *)v6, 402);
  something_database(*(_DWORD *)v1196, v1195, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7263);
  v1197 = (int)std_string_append(&v6255, (int)&Dst, "cat-head2.cub");
  v7813 = 542;
  v1198 = this_4pointer_off((void *)v6, 403);
  something_database(*(_DWORD *)v1198, v1197, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6255);
  v1199 = (int)std_string_append(&v7261, (int)&Dst, "cat-foot2.cub");
  v7813 = 543;
  v1200 = this_4pointer_off((void *)v6, 405);
  something_database(*(_DWORD *)v1200, v1199, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7261);
  v1201 = (int)std_string_append(&v5751, (int)&Dst, "cat-hand2.cub");
  v7813 = 544;
  v1202 = this_4pointer_off((void *)v6, 404);
  something_database(*(_DWORD *)v1202, v1201, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5751);
  v1203 = (int)std_string_append(&v7259, (int)&Dst, "cat-tail2.cub");
  v7813 = 545;
  v1204 = this_4pointer_off((void *)v6, 406);
  something_database(*(_DWORD *)v1204, v1203, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7259);
  v1205 = (int)std_string_append(&v6253, (int)&Dst, "cat-body3.cub");
  v7813 = 546;
  v1206 = this_4pointer_off((void *)v6, 407);
  something_database(*(_DWORD *)v1206, v1205, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6253);
  v1207 = (int)std_string_append(&v7257, (int)&Dst, "cat-head3.cub");
  v7813 = 547;
  v1208 = this_4pointer_off((void *)v6, 408);
  something_database(*(_DWORD *)v1208, v1207, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7257);
  v1209 = (int)std_string_append(&v5499, (int)&Dst, "cat-foot3.cub");
  v7813 = 548;
  v1210 = this_4pointer_off((void *)v6, 410);
  something_database(*(_DWORD *)v1210, v1209, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5499);
  v1211 = (int)std_string_append(&v7255, (int)&Dst, "cat-hand3.cub");
  v7813 = 549;
  v1212 = this_4pointer_off((void *)v6, 409);
  something_database(*(_DWORD *)v1212, v1211, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7255);
  v1213 = (int)std_string_append(&v6251, (int)&Dst, "cat-tail3.cub");
  v7813 = 550;
  v1214 = this_4pointer_off((void *)v6, 411);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1213;
  something_database(*(_DWORD *)v1214, v1213, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6251);
  v1215 = (int)std_string_append(&v7253, (int)&Dst, "dragon-body.cub");
  v7813 = 551;
  v1216 = this_4pointer_off((void *)v6, 425);
  something_database(*(_DWORD *)v1216, v1215, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7253);
  v1217 = (int)std_string_append(&v5749, (int)&Dst, "dragon-head.cub");
  v7813 = 552;
  v1218 = this_4pointer_off((void *)v6, 426);
  something_database(*(_DWORD *)v1218, v1217, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5749);
  v1219 = (int)std_string_append(&v7251, (int)&Dst, "dragon-foot.cub");
  v7813 = 553;
  v1220 = this_4pointer_off((void *)v6, 427);
  something_database(*(_DWORD *)v1220, v1219, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7251);
  v1221 = (int)std_string_append(&v6249, (int)&Dst, "dragon-wing.cub");
  v7813 = 554;
  v1222 = this_4pointer_off((void *)v6, 428);
  something_database(*(_DWORD *)v1222, v1221, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6249);
  v1223 = (int)std_string_append(&v7249, (int)&Dst, "dragon-tail.cub");
  v7813 = 555;
  v1224 = this_4pointer_off((void *)v6, 429);
  something_database(*(_DWORD *)v1224, v1223, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7249);
  v1225 = (int)std_string_append(&v5373, (int)&Dst, "crab-body-blue.cub");
  v7813 = 556;
  v1226 = this_4pointer_off((void *)v6, 212);
  something_database(*(_DWORD *)v1226, v1225, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5373);
  v1227 = (int)std_string_append(&v7247, (int)&Dst, "crab-hand-blue.cub");
  v7813 = 557;
  v1228 = this_4pointer_off((void *)v6, 215);
  something_database(*(_DWORD *)v1228, v1227, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7247);
  v1229 = (int)std_string_append(&v6247, (int)&Dst, "crab-head-blue.cub");
  v7813 = 558;
  v1230 = this_4pointer_off((void *)v6, 213);
  something_database(*(_DWORD *)v1230, v1229, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6247);
  v1231 = (int)std_string_append(&v7245, (int)&Dst, "crab-foot-blue.cub");
  v7813 = 559;
  v1232 = this_4pointer_off((void *)v6, 214);
  something_database(*(_DWORD *)v1232, v1231, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7245);
  v1233 = (int)std_string_append(&v5747, (int)&Dst, "plainrunner-body.cub");
  v7813 = 560;
  v1234 = this_4pointer_off((void *)v6, 333);
  something_database(*(_DWORD *)v1234, v1233, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5747);
  v1235 = (int)std_string_append(&v7243, (int)&Dst, "plainrunner-foot.cub");
  v7813 = 561;
  v1236 = this_4pointer_off((void *)v6, 334);
  something_database(*(_DWORD *)v1236, v1235, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7243);
  v1237 = (int)std_string_append(&v6245, (int)&Dst, "leafrunner-body.cub");
  v7813 = 562;
  v1238 = this_4pointer_off((void *)v6, 335);
  something_database(*(_DWORD *)v1238, v1237, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6245);
  v1239 = (int)std_string_append(&v7241, (int)&Dst, "leafrunner-foot.cub");
  v7813 = 563;
  v1240 = this_4pointer_off((void *)v6, 336);
  something_database(*(_DWORD *)v1240, v1239, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7241);
  v1241 = (int)std_string_append(&v5497, (int)&Dst, "snowrunner-body.cub");
  v7813 = 564;
  v1242 = this_4pointer_off((void *)v6, 337);
  something_database(*(_DWORD *)v1242, v1241, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5497);
  v1243 = (int)std_string_append(&v7239, (int)&Dst, "snowrunner-foot.cub");
  v7813 = 565;
  v1244 = this_4pointer_off((void *)v6, 338);
  something_database(*(_DWORD *)v1244, v1243, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7239);
  v1245 = (int)std_string_append(&v6243, (int)&Dst, "desertrunner-body.cub");
  v7813 = 566;
  v1246 = this_4pointer_off((void *)v6, 339);
  something_database(*(_DWORD *)v1246, v1245, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6243);
  v1247 = (int)std_string_append(&v7237, (int)&Dst, "desertrunner-foot.cub");
  v7813 = 567;
  v1248 = this_4pointer_off((void *)v6, 340);
  something_database(*(_DWORD *)v1248, v1247, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7237);
  v1249 = (int)std_string_append(&v5745, (int)&Dst, "peacock-body.cub");
  v7813 = 568;
  v1250 = this_4pointer_off((void *)v6, 341);
  something_database(*(_DWORD *)v1250, v1249, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5745);
  v1251 = (int)std_string_append(&v7235, (int)&Dst, "peacock-foot.cub");
  v7813 = 569;
  v1252 = this_4pointer_off((void *)v6, 342);
  something_database(*(_DWORD *)v1252, v1251, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7235);
  v1253 = (int)std_string_append(&v6241, (int)&Dst, "peacock-head.cub");
  v7813 = 570;
  v1254 = this_4pointer_off((void *)v6, 343);
  something_database(*(_DWORD *)v1254, v1253, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6241);
  v1255 = (int)std_string_append(&v7233, (int)&Dst, "wood-staff1.cub");
  v7813 = 571;
  v1256 = this_4pointer_off((void *)v6, 434);
  something_database(*(_DWORD *)v1256, v1255, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7233);
  v1257 = (int)std_string_append(&v5279, (int)&Dst, "wood-staff2.cub");
  v7813 = 572;
  v1258 = this_4pointer_off((void *)v6, 435);
  something_database(*(_DWORD *)v1258, v1257, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5279);
  v1259 = (int)std_string_append(&v7231, (int)&Dst, "wood-staff3.cub");
  v7813 = 573;
  v1260 = this_4pointer_off((void *)v6, 436);
  something_database(*(_DWORD *)v1260, v1259, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7231);
  v1261 = (int)std_string_append(&v6239, (int)&Dst, "wood-staff4.cub");
  v7813 = 574;
  v1262 = this_4pointer_off((void *)v6, 437);
  something_database(*(_DWORD *)v1262, v1261, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6239);
  v1263 = (int)std_string_append(&v7229, (int)&Dst, "wood-staff6.cub");
  v7813 = 575;
  v1264 = this_4pointer_off((void *)v6, 438);
  something_database(*(_DWORD *)v1264, v1263, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7229);
  v1265 = (int)std_string_append(&v5743, (int)&Dst, "wood-staff1-random1.cub");
  v7813 = 576;
  v1266 = this_4pointer_off((void *)v6, 439);
  something_database(*(_DWORD *)v1266, v1265, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5743);
  v1267 = (int)std_string_append(&v7227, (int)&Dst, "wood-staff2-random1.cub");
  v7813 = 577;
  v1268 = this_4pointer_off((void *)v6, 440);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1267;
  something_database(*(_DWORD *)v1268, v1267, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7227);
  v1269 = (int)std_string_append(&v6237, (int)&Dst, "wood-staff3-random1.cub");
  v7813 = 578;
  v1270 = this_4pointer_off((void *)v6, 441);
  something_database(*(_DWORD *)v1270, v1269, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6237);
  v1271 = (int)std_string_append(&v7225, (int)&Dst, "wood-staff4-random1.cub");
  v7813 = 579;
  v1272 = this_4pointer_off((void *)v6, 442);
  something_database(*(_DWORD *)v1272, v1271, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7225);
  v1273 = (int)std_string_append(&v5495, (int)&Dst, "wood-staff5-random1.cub");
  v7813 = 580;
  v1274 = this_4pointer_off((void *)v6, 443);
  something_database(*(_DWORD *)v1274, v1273, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5495);
  v1275 = (int)std_string_append(&v7223, (int)&Dst, "wood-staff1-random2.cub");
  v7813 = 581;
  v1276 = this_4pointer_off((void *)v6, 444);
  something_database(*(_DWORD *)v1276, v1275, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7223);
  v1277 = (int)std_string_append(&v6235, (int)&Dst, "wood-staff2-random2.cub");
  v7813 = 582;
  v1278 = this_4pointer_off((void *)v6, 445);
  something_database(*(_DWORD *)v1278, v1277, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6235);
  v1279 = (int)std_string_append(&v7221, (int)&Dst, "wood-staff3-random2.cub");
  v7813 = 583;
  v1280 = this_4pointer_off((void *)v6, 446);
  something_database(*(_DWORD *)v1280, v1279, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7221);
  v1281 = (int)std_string_append(&v5741, (int)&Dst, "wood-staff4-random2.cub");
  v7813 = 584;
  v1282 = this_4pointer_off((void *)v6, 447);
  something_database(*(_DWORD *)v1282, v1281, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5741);
  v1283 = (int)std_string_append(&v7219, (int)&Dst, "wood-staff5-random2.cub");
  v7813 = 585;
  v1284 = this_4pointer_off((void *)v6, 448);
  something_database(*(_DWORD *)v1284, v1283, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7219);
  v1285 = (int)std_string_append(&v6233, (int)&Dst, "wood-staff1-random3.cub");
  v7813 = 586;
  v1286 = this_4pointer_off((void *)v6, 449);
  something_database(*(_DWORD *)v1286, v1285, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6233);
  v1287 = (int)std_string_append(&v7217, (int)&Dst, "wood-staff2-random3.cub");
  v7813 = 587;
  v1288 = this_4pointer_off((void *)v6, 450);
  something_database(*(_DWORD *)v1288, v1287, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7217);
  v1289 = (int)std_string_append(&v5371, (int)&Dst, "wood-staff3-random3.cub");
  v7813 = 588;
  v1290 = this_4pointer_off((void *)v6, 451);
  something_database(*(_DWORD *)v1290, v1289, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5371);
  v1291 = (int)std_string_append(&v7215, (int)&Dst, "wood-staff4-random3.cub");
  v7813 = 589;
  v1292 = this_4pointer_off((void *)v6, 452);
  something_database(*(_DWORD *)v1292, v1291, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7215);
  v1293 = (int)std_string_append(&v6231, (int)&Dst, "wood-staff5-random3.cub");
  v7813 = 590;
  v1294 = this_4pointer_off((void *)v6, 453);
  something_database(*(_DWORD *)v1294, v1293, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6231);
  v1295 = (int)std_string_append(&v7213, (int)&Dst, "wood-staff1-random4.cub");
  v7813 = 591;
  v1296 = this_4pointer_off((void *)v6, 454);
  something_database(*(_DWORD *)v1296, v1295, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7213);
  v1297 = (int)std_string_append(&v5739, (int)&Dst, "wood-staff2-random4.cub");
  v7813 = 592;
  v1298 = this_4pointer_off((void *)v6, 455);
  something_database(*(_DWORD *)v1298, v1297, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5739);
  v1299 = (int)std_string_append(&v7211, (int)&Dst, "wood-staff3-random4.cub");
  v7813 = 593;
  v1300 = this_4pointer_off((void *)v6, 456);
  something_database(*(_DWORD *)v1300, v1299, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7211);
  v1301 = (int)std_string_append(&v6229, (int)&Dst, "wood-staff4-random4.cub");
  v7813 = 594;
  v1302 = this_4pointer_off((void *)v6, 457);
  something_database(*(_DWORD *)v1302, v1301, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6229);
  v1303 = (int)std_string_append(&v7209, (int)&Dst, "wood-staff5-random4.cub");
  v7813 = 595;
  v1304 = this_4pointer_off((void *)v6, 458);
  something_database(*(_DWORD *)v1304, v1303, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7209);
  v1305 = (int)std_string_append(&v5493, (int)&Dst, "wood-staff1-random5.cub");
  v7813 = 596;
  v1306 = this_4pointer_off((void *)v6, 459);
  something_database(*(_DWORD *)v1306, v1305, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5493);
  v1307 = (int)std_string_append(&v7207, (int)&Dst, "wood-staff2-random5.cub");
  v7813 = 597;
  v1308 = this_4pointer_off((void *)v6, 460);
  something_database(*(_DWORD *)v1308, v1307, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7207);
  v1309 = (int)std_string_append(&v6227, (int)&Dst, "wood-staff3-random5.cub");
  v7813 = 598;
  v1310 = this_4pointer_off((void *)v6, 461);
  something_database(*(_DWORD *)v1310, v1309, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6227);
  v1311 = (int)std_string_append(&v7205, (int)&Dst, "wood-staff4-random5.cub");
  v7813 = 599;
  v1312 = this_4pointer_off((void *)v6, 462);
  something_database(*(_DWORD *)v1312, v1311, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7205);
  v1313 = (int)std_string_append(&v5737, (int)&Dst, "wood-staff5-random5.cub");
  v7813 = 600;
  v1314 = this_4pointer_off((void *)v6, 463);
  something_database(*(_DWORD *)v1314, v1313, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5737);
  v1315 = (int)std_string_append(&v7203, (int)&Dst, "wood-staff1-random6.cub");
  v7813 = 601;
  v1316 = this_4pointer_off((void *)v6, 464);
  something_database(*(_DWORD *)v1316, v1315, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7203);
  v1317 = (int)std_string_append(&v6225, (int)&Dst, "wood-staff2-random6.cub");
  v7813 = 602;
  v1318 = this_4pointer_off((void *)v6, 465);
  something_database(*(_DWORD *)v1318, v1317, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6225);
  v1319 = (int)std_string_append(&v7201, (int)&Dst, "wood-staff3-random6.cub");
  v7813 = 603;
  v1320 = this_4pointer_off((void *)v6, 466);
  something_database(*(_DWORD *)v1320, v1319, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7201);
  v1321 = (int)std_string_append(&v5309, (int)&Dst, "wood-staff4-random6.cub");
  v7813 = 604;
  v1322 = this_4pointer_off((void *)v6, 467);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1321;
  something_database(*(_DWORD *)v1322, v1321, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5309);
  v1323 = (int)std_string_append(&v7199, (int)&Dst, "wood-staff5-random6.cub");
  v7813 = 605;
  v1324 = this_4pointer_off((void *)v6, 468);
  something_database(*(_DWORD *)v1324, v1323, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7199);
  v1325 = (int)std_string_append(&v6223, (int)&Dst, "wood-staff1-random7.cub");
  v7813 = 606;
  v1326 = this_4pointer_off((void *)v6, 469);
  something_database(*(_DWORD *)v1326, v1325, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6223);
  v1327 = (int)std_string_append(&v7197, (int)&Dst, "wood-staff2-random7.cub");
  v7813 = 607;
  v1328 = this_4pointer_off((void *)v6, 470);
  something_database(*(_DWORD *)v1328, v1327, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7197);
  v1329 = (int)std_string_append(&v5735, (int)&Dst, "wood-staff3-random7.cub");
  v7813 = 608;
  v1330 = this_4pointer_off((void *)v6, 471);
  something_database(*(_DWORD *)v1330, v1329, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5735);
  v1331 = (int)std_string_append(&v7195, (int)&Dst, "wood-staff4-random7.cub");
  v7813 = 609;
  v1332 = this_4pointer_off((void *)v6, 472);
  something_database(*(_DWORD *)v1332, v1331, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7195);
  v1333 = (int)std_string_append(&v6221, (int)&Dst, "wood-staff5-random7.cub");
  v7813 = 610;
  v1334 = this_4pointer_off((void *)v6, 473);
  something_database(*(_DWORD *)v1334, v1333, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6221);
  v1335 = (int)std_string_append(&v7193, (int)&Dst, "wood-staff1-random8.cub");
  v7813 = 611;
  v1336 = this_4pointer_off((void *)v6, 474);
  something_database(*(_DWORD *)v1336, v1335, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7193);
  v1337 = (int)std_string_append(&v5491, (int)&Dst, "wood-staff2-random8.cub");
  v7813 = 612;
  v1338 = this_4pointer_off((void *)v6, 475);
  something_database(*(_DWORD *)v1338, v1337, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5491);
  v1339 = (int)std_string_append(&v7191, (int)&Dst, "wood-staff3-random8.cub");
  v7813 = 613;
  v1340 = this_4pointer_off((void *)v6, 476);
  something_database(*(_DWORD *)v1340, v1339, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7191);
  v1341 = (int)std_string_append(&v6219, (int)&Dst, "wood-staff4-random8.cub");
  v7813 = 614;
  v1342 = this_4pointer_off((void *)v6, 477);
  something_database(*(_DWORD *)v1342, v1341, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6219);
  v1343 = (int)std_string_append(&v7189, (int)&Dst, "wood-staff5-random8.cub");
  v7813 = 615;
  v1344 = this_4pointer_off((void *)v6, 478);
  something_database(*(_DWORD *)v1344, v1343, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7189);
  v1345 = (int)std_string_append(&v5733, (int)&Dst, "wood-staff1-random9.cub");
  v7813 = 616;
  v1346 = this_4pointer_off((void *)v6, 479);
  something_database(*(_DWORD *)v1346, v1345, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5733);
  v1347 = (int)std_string_append(&v7187, (int)&Dst, "wood-staff2-random9.cub");
  v7813 = 617;
  v1348 = this_4pointer_off((void *)v6, 480);
  something_database(*(_DWORD *)v1348, v1347, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7187);
  v1349 = (int)std_string_append(&v6217, (int)&Dst, "wood-staff3-random9.cub");
  v7813 = 618;
  v1350 = this_4pointer_off((void *)v6, 481);
  something_database(*(_DWORD *)v1350, v1349, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6217);
  v1351 = (int)std_string_append(&v7185, (int)&Dst, "wood-staff4-random9.cub");
  v7813 = 619;
  v1352 = this_4pointer_off((void *)v6, 482);
  something_database(*(_DWORD *)v1352, v1351, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7185);
  v1353 = (int)std_string_append(&v5369, (int)&Dst, "wood-staff5-random9.cub");
  v7813 = 620;
  v1354 = this_4pointer_off((void *)v6, 483);
  something_database(*(_DWORD *)v1354, v1353, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5369);
  v1355 = (int)std_string_append(&v7183, (int)&Dst, "wood-staff1-random10.cub");
  v7813 = 621;
  v1356 = this_4pointer_off((void *)v6, 484);
  something_database(*(_DWORD *)v1356, v1355, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7183);
  v1357 = (int)std_string_append(&v6215, (int)&Dst, "wood-staff2-random10.cub");
  v7813 = 622;
  v1358 = this_4pointer_off((void *)v6, 485);
  something_database(*(_DWORD *)v1358, v1357, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6215);
  v1359 = (int)std_string_append(&v7181, (int)&Dst, "wood-staff3-random10.cub");
  v7813 = 623;
  v1360 = this_4pointer_off((void *)v6, 486);
  something_database(*(_DWORD *)v1360, v1359, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7181);
  v1361 = (int)std_string_append(&v5731, (int)&Dst, "wood-staff4-random10.cub");
  v7813 = 624;
  v1362 = this_4pointer_off((void *)v6, 487);
  something_database(*(_DWORD *)v1362, v1361, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5731);
  v1363 = (int)std_string_append(&v7179, (int)&Dst, "wood-staff5-random10.cub");
  v7813 = 625;
  v1364 = this_4pointer_off((void *)v6, 488);
  something_database(*(_DWORD *)v1364, v1363, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7179);
  v1365 = (int)std_string_append(&v6213, (int)&Dst, "obsidian-staff1.cub");
  v7813 = 626;
  v1366 = this_4pointer_off((void *)v6, 604);
  something_database(*(_DWORD *)v1366, v1365, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6213);
  v1367 = (int)std_string_append(&v7177, (int)&Dst, "obsidian-staff2.cub");
  v7813 = 627;
  v1368 = this_4pointer_off((void *)v6, 605);
  something_database(*(_DWORD *)v1368, v1367, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7177);
  v1369 = (int)std_string_append(&v5489, (int)&Dst, "obsidian-staff3.cub");
  v7813 = 628;
  v1370 = this_4pointer_off((void *)v6, 606);
  something_database(*(_DWORD *)v1370, v1369, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5489);
  v1371 = (int)std_string_append(&v7175, (int)&Dst, "obsidian-staff4.cub");
  v7813 = 629;
  v1372 = this_4pointer_off((void *)v6, 607);
  something_database(*(_DWORD *)v1372, v1371, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7175);
  v1373 = (int)std_string_append(&v6211, (int)&Dst, "obsidian-staff5.cub");
  v7813 = 630;
  v1374 = this_4pointer_off((void *)v6, 608);
  something_database(*(_DWORD *)v1374, v1373, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6211);
  v1375 = (int)std_string_append(&v7173, (int)&Dst, "wood-wand1.cub");
  v7813 = 631;
  v1376 = this_4pointer_off((void *)v6, 489);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1375;
  something_database(*(_DWORD *)v1376, v1375, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7173);
  v1377 = (int)std_string_append(&v5729, (int)&Dst, "wood-wand2.cub");
  v7813 = 632;
  v1378 = this_4pointer_off((void *)v6, 490);
  something_database(*(_DWORD *)v1378, v1377, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5729);
  v1379 = (int)std_string_append(&v7171, (int)&Dst, "wood-wand3.cub");
  v7813 = 633;
  v1380 = this_4pointer_off((void *)v6, 491);
  something_database(*(_DWORD *)v1380, v1379, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7171);
  v1381 = (int)std_string_append(&v6209, (int)&Dst, "wood-wand4.cub");
  v7813 = 634;
  v1382 = this_4pointer_off((void *)v6, 492);
  something_database(*(_DWORD *)v1382, v1381, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6209);
  v1383 = (int)std_string_append(&v7169, (int)&Dst, "wood-wand5.cub");
  v7813 = 635;
  v1384 = this_4pointer_off((void *)v6, 493);
  something_database(*(_DWORD *)v1384, v1383, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7169);
  v1385 = (int)std_string_append(&v5263, (int)&Dst, "wood-wand1-random1.cub");
  v7813 = 636;
  v1386 = this_4pointer_off((void *)v6, 494);
  something_database(*(_DWORD *)v1386, v1385, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5263);
  v1387 = (int)std_string_append(&v7167, (int)&Dst, "wood-wand2-random1.cub");
  v7813 = 637;
  v1388 = this_4pointer_off((void *)v6, 495);
  something_database(*(_DWORD *)v1388, v1387, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7167);
  v1389 = (int)std_string_append(&v6207, (int)&Dst, "wood-wand3-random1.cub");
  v7813 = 638;
  v1390 = this_4pointer_off((void *)v6, 496);
  something_database(*(_DWORD *)v1390, v1389, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6207);
  v1391 = (int)std_string_append(&v7165, (int)&Dst, "wood-wand4-random1.cub");
  v7813 = 639;
  v1392 = this_4pointer_off((void *)v6, 497);
  something_database(*(_DWORD *)v1392, v1391, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7165);
  v1393 = (int)std_string_append(&v5727, (int)&Dst, "wood-wand5-random1.cub");
  v7813 = 640;
  v1394 = this_4pointer_off((void *)v6, 498);
  something_database(*(_DWORD *)v1394, v1393, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5727);
  v1395 = (int)std_string_append(&v7163, (int)&Dst, "wood-wand1-random2.cub");
  v7813 = 641;
  v1396 = this_4pointer_off((void *)v6, 499);
  something_database(*(_DWORD *)v1396, v1395, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7163);
  v1397 = (int)std_string_append(&v6205, (int)&Dst, "wood-wand2-random2.cub");
  v7813 = 642;
  v1398 = this_4pointer_off((void *)v6, 500);
  something_database(*(_DWORD *)v1398, v1397, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6205);
  v1399 = (int)std_string_append(&v7161, (int)&Dst, "wood-wand3-random2.cub");
  v7813 = 643;
  v1400 = this_4pointer_off((void *)v6, 501);
  something_database(*(_DWORD *)v1400, v1399, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7161);
  v1401 = (int)std_string_append(&v5487, (int)&Dst, "wood-wand4-random2.cub");
  v7813 = 644;
  v1402 = this_4pointer_off((void *)v6, 502);
  something_database(*(_DWORD *)v1402, v1401, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5487);
  v1403 = (int)std_string_append(&v7159, (int)&Dst, "wood-wand5-random2.cub");
  v7813 = 645;
  v1404 = this_4pointer_off((void *)v6, 503);
  something_database(*(_DWORD *)v1404, v1403, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7159);
  v1405 = (int)std_string_append(&v6203, (int)&Dst, "wood-wand1-random3.cub");
  v7813 = 646;
  v1406 = this_4pointer_off((void *)v6, 504);
  something_database(*(_DWORD *)v1406, v1405, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6203);
  v1407 = (int)std_string_append(&v7157, (int)&Dst, "wood-wand2-random3.cub");
  v7813 = 647;
  v1408 = this_4pointer_off((void *)v6, 505);
  something_database(*(_DWORD *)v1408, v1407, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7157);
  v1409 = (int)std_string_append(&v5725, (int)&Dst, "wood-wand3-random3.cub");
  v7813 = 648;
  v1410 = this_4pointer_off((void *)v6, 506);
  something_database(*(_DWORD *)v1410, v1409, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5725);
  v1411 = (int)std_string_append(&v7155, (int)&Dst, "wood-wand4-random3.cub");
  v7813 = 649;
  v1412 = this_4pointer_off((void *)v6, 507);
  something_database(*(_DWORD *)v1412, v1411, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7155);
  v1413 = (int)std_string_append(&v6201, (int)&Dst, "wood-wand5-random3.cub");
  v7813 = 650;
  v1414 = this_4pointer_off((void *)v6, 508);
  something_database(*(_DWORD *)v1414, v1413, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6201);
  v1415 = (int)std_string_append(&v7153, (int)&Dst, "wood-wand1-random4.cub");
  v7813 = 651;
  v1416 = this_4pointer_off((void *)v6, 509);
  something_database(*(_DWORD *)v1416, v1415, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7153);
  v1417 = (int)std_string_append(&v5367, (int)&Dst, "wood-wand2-random4.cub");
  v7813 = 652;
  v1418 = this_4pointer_off((void *)v6, 510);
  something_database(*(_DWORD *)v1418, v1417, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5367);
  v1419 = (int)std_string_append(&v7151, (int)&Dst, "wood-wand3-random4.cub");
  v7813 = 653;
  v1420 = this_4pointer_off((void *)v6, 511);
  something_database(*(_DWORD *)v1420, v1419, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7151);
  v1421 = (int)std_string_append(&v6199, (int)&Dst, "wood-wand4-random4.cub");
  v7813 = 654;
  v1422 = this_4pointer_off((void *)v6, 512);
  something_database(*(_DWORD *)v1422, v1421, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6199);
  v1423 = (int)std_string_append(&v7149, (int)&Dst, "wood-wand5-random4.cub");
  v7813 = 655;
  v1424 = this_4pointer_off((void *)v6, 513);
  something_database(*(_DWORD *)v1424, v1423, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7149);
  v1425 = (int)std_string_append(&v5723, (int)&Dst, "wood-wand1-random5.cub");
  v7813 = 656;
  v1426 = this_4pointer_off((void *)v6, 514);
  something_database(*(_DWORD *)v1426, v1425, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5723);
  v1427 = (int)std_string_append(&v7147, (int)&Dst, "wood-wand2-random5.cub");
  v7813 = 657;
  v1428 = this_4pointer_off((void *)v6, 515);
  something_database(*(_DWORD *)v1428, v1427, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7147);
  v1429 = (int)std_string_append(&v6197, (int)&Dst, "wood-wand3-random5.cub");
  v7813 = 658;
  v1430 = this_4pointer_off((void *)v6, 516);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1429;
  something_database(*(_DWORD *)v1430, v1429, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6197);
  v1431 = (int)std_string_append(&v7145, (int)&Dst, "wood-wand4-random5.cub");
  v7813 = 659;
  v1432 = this_4pointer_off((void *)v6, 517);
  something_database(*(_DWORD *)v1432, v1431, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7145);
  v1433 = (int)std_string_append(&v5485, (int)&Dst, "wood-wand5-random5.cub");
  v7813 = 660;
  v1434 = this_4pointer_off((void *)v6, 518);
  something_database(*(_DWORD *)v1434, v1433, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5485);
  v1435 = (int)std_string_append(&v7143, (int)&Dst, "wood-wand1-random6.cub");
  v7813 = 661;
  v1436 = this_4pointer_off((void *)v6, 519);
  something_database(*(_DWORD *)v1436, v1435, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7143);
  v1437 = (int)std_string_append(&v6195, (int)&Dst, "wood-wand2-random6.cub");
  v7813 = 662;
  v1438 = this_4pointer_off((void *)v6, 520);
  something_database(*(_DWORD *)v1438, v1437, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6195);
  v1439 = (int)std_string_append(&v7141, (int)&Dst, "wood-wand3-random6.cub");
  v7813 = 663;
  v1440 = this_4pointer_off((void *)v6, 521);
  something_database(*(_DWORD *)v1440, v1439, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7141);
  v1441 = (int)std_string_append(&v5721, (int)&Dst, "wood-wand4-random6.cub");
  v7813 = 664;
  v1442 = this_4pointer_off((void *)v6, 522);
  something_database(*(_DWORD *)v1442, v1441, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5721);
  v1443 = (int)std_string_append(&v7139, (int)&Dst, "wood-wand5-random6.cub");
  v7813 = 665;
  v1444 = this_4pointer_off((void *)v6, 523);
  something_database(*(_DWORD *)v1444, v1443, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7139);
  v1445 = (int)std_string_append(&v6193, (int)&Dst, "wood-wand1-random7.cub");
  v7813 = 666;
  v1446 = this_4pointer_off((void *)v6, 524);
  something_database(*(_DWORD *)v1446, v1445, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6193);
  v1447 = (int)std_string_append(&v7137, (int)&Dst, "wood-wand2-random7.cub");
  v7813 = 667;
  v1448 = this_4pointer_off((void *)v6, 525);
  something_database(*(_DWORD *)v1448, v1447, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7137);
  v1449 = (int)std_string_append(&v5307, (int)&Dst, "wood-wand3-random7.cub");
  v7813 = 668;
  v1450 = this_4pointer_off((void *)v6, 526);
  something_database(*(_DWORD *)v1450, v1449, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5307);
  v1451 = (int)std_string_append(&v7135, (int)&Dst, "wood-wand4-random7.cub");
  v7813 = 669;
  v1452 = this_4pointer_off((void *)v6, 527);
  something_database(*(_DWORD *)v1452, v1451, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7135);
  v1453 = (int)std_string_append(&v6191, (int)&Dst, "wood-wand5-random7.cub");
  v7813 = 670;
  v1454 = this_4pointer_off((void *)v6, 528);
  something_database(*(_DWORD *)v1454, v1453, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6191);
  v1455 = (int)std_string_append(&v7133, (int)&Dst, "wood-wand1-random8.cub");
  v7813 = 671;
  v1456 = this_4pointer_off((void *)v6, 529);
  something_database(*(_DWORD *)v1456, v1455, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7133);
  v1457 = (int)std_string_append(&v5719, (int)&Dst, "wood-wand2-random8.cub");
  v7813 = 672;
  v1458 = this_4pointer_off((void *)v6, 530);
  something_database(*(_DWORD *)v1458, v1457, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5719);
  v1459 = (int)std_string_append(&v7131, (int)&Dst, "wood-wand3-random8.cub");
  v7813 = 673;
  v1460 = this_4pointer_off((void *)v6, 531);
  something_database(*(_DWORD *)v1460, v1459, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7131);
  v1461 = (int)std_string_append(&v6189, (int)&Dst, "wood-wand4-random8.cub");
  v7813 = 674;
  v1462 = this_4pointer_off((void *)v6, 532);
  something_database(*(_DWORD *)v1462, v1461, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6189);
  v1463 = (int)std_string_append(&v7129, (int)&Dst, "wood-wand5-random8.cub");
  v7813 = 675;
  v1464 = this_4pointer_off((void *)v6, 533);
  something_database(*(_DWORD *)v1464, v1463, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7129);
  v1465 = (int)std_string_append(&v5483, (int)&Dst, (const char *)"wood-wand1-random9.cub");
  v7813 = 676;
  v1466 = this_4pointer_off((void *)v6, 534);
  something_database(*(_DWORD *)v1466, v1465, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5483);
  v1467 = (int)std_string_append(&v7127, (int)&Dst, "wood-wand2-random9.cub");
  v7813 = 677;
  v1468 = this_4pointer_off((void *)v6, 535);
  something_database(*(_DWORD *)v1468, v1467, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7127);
  v1469 = (int)std_string_append(&v6187, (int)&Dst, (const char *)"wood-wand3-random9.cub");
  v7813 = 678;
  v1470 = this_4pointer_off((void *)v6, 536);
  something_database(*(_DWORD *)v1470, v1469, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6187);
  v1471 = (int)std_string_append(&v7125, (int)&Dst, "wood-wand4-random9.cub");
  v7813 = 679;
  v1472 = this_4pointer_off((void *)v6, 537);
  something_database(*(_DWORD *)v1472, v1471, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7125);
  v1473 = (int)std_string_append(&v5717, (int)&Dst, "wood-wand5-random9.cub");
  v7813 = 680;
  v1474 = this_4pointer_off((void *)v6, 538);
  something_database(*(_DWORD *)v1474, v1473, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5717);
  v1475 = (int)std_string_append(&v7123, (int)&Dst, "wood-wand1-random10.cub");
  v7813 = 681;
  v1476 = this_4pointer_off((void *)v6, 539);
  something_database(*(_DWORD *)v1476, v1475, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7123);
  v1477 = (int)std_string_append(&v6185, (int)&Dst, "wood-wand2-random10.cub");
  v7813 = 682;
  v1478 = this_4pointer_off((void *)v6, 540);
  something_database(*(_DWORD *)v1478, v1477, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6185);
  v1479 = (int)std_string_append(&v7121, (int)&Dst, "wood-wand3-random10.cub");
  v7813 = 683;
  v1480 = this_4pointer_off((void *)v6, 541);
  something_database(*(_DWORD *)v1480, v1479, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7121);
  v1481 = (int)std_string_append(&v5365, (int)&Dst, "wood-wand4-random10.cub");
  v7813 = 684;
  v1482 = this_4pointer_off((void *)v6, 542);
  something_database(*(_DWORD *)v1482, v1481, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5365);
  v1483 = (int)std_string_append(&v7119, (int)&Dst, "wood-wand5-random10.cub");
  v7813 = 685;
  v1484 = this_4pointer_off((void *)v6, 543);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1483;
  something_database(*(_DWORD *)v1484, v1483, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7119);
  v1485 = (int)std_string_append(&v6183, (int)&Dst, "gold-bracelet1.cub");
  v7813 = 686;
  v1486 = this_4pointer_off((void *)v6, 544);
  something_database(*(_DWORD *)v1486, v1485, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6183);
  v1487 = (int)std_string_append(&v7117, (int)&Dst, "gold-bracelet2.cub");
  v7813 = 687;
  v1488 = this_4pointer_off((void *)v6, 545);
  something_database(*(_DWORD *)v1488, v1487, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7117);
  v1489 = (int)std_string_append(&v5715, (int)&Dst, "gold-bracelet3.cub");
  v7813 = 688;
  v1490 = this_4pointer_off((void *)v6, 546);
  something_database(*(_DWORD *)v1490, v1489, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5715);
  v1491 = (int)std_string_append(&v7115, (int)&Dst, "gold-bracelet4.cub");
  v7813 = 689;
  v1492 = this_4pointer_off((void *)v6, 547);
  something_database(*(_DWORD *)v1492, v1491, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7115);
  v1493 = (int)std_string_append(&v6181, (int)&Dst, "gold-bracelet5.cub");
  v7813 = 690;
  v1494 = this_4pointer_off((void *)v6, 548);
  something_database(*(_DWORD *)v1494, v1493, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6181);
  v1495 = (int)std_string_append(&v7113, (int)&Dst, "gold-bracelet1-random1.cub");
  v7813 = 691;
  v1496 = this_4pointer_off((void *)v6, 549);
  something_database(*(_DWORD *)v1496, v1495, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7113);
  v1497 = (int)std_string_append(&v5481, (int)&Dst, "gold-bracelet2-random1.cub");
  v7813 = 692;
  v1498 = this_4pointer_off((void *)v6, 550);
  something_database(*(_DWORD *)v1498, v1497, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5481);
  v1499 = (int)std_string_append(&v7111, (int)&Dst, "gold-bracelet3-random1.cub");
  v7813 = 693;
  v1500 = this_4pointer_off((void *)v6, 551);
  something_database(*(_DWORD *)v1500, v1499, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7111);
  v1501 = (int)std_string_append(&v6179, (int)&Dst, "gold-bracelet4-random1.cub");
  v7813 = 694;
  v1502 = this_4pointer_off((void *)v6, 552);
  something_database(*(_DWORD *)v1502, v1501, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6179);
  v1503 = (int)std_string_append(&v7109, (int)&Dst, "gold-bracelet5-random1.cub");
  v7813 = 695;
  v1504 = this_4pointer_off((void *)v6, 553);
  something_database(*(_DWORD *)v1504, v1503, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7109);
  v1505 = (int)std_string_append(&v5713, (int)&Dst, "gold-bracelet1-random2.cub");
  v7813 = 696;
  v1506 = this_4pointer_off((void *)v6, 554);
  something_database(*(_DWORD *)v1506, v1505, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5713);
  v1507 = (int)std_string_append(&v7107, (int)&Dst, "gold-bracelet2-random2.cub");
  v7813 = 697;
  v1508 = this_4pointer_off((void *)v6, 555);
  something_database(*(_DWORD *)v1508, v1507, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7107);
  v1509 = (int)std_string_append(&v6177, (int)&Dst, "gold-bracelet3-random2.cub");
  v7813 = 698;
  v1510 = this_4pointer_off((void *)v6, 556);
  something_database(*(_DWORD *)v1510, v1509, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6177);
  v1511 = (int)std_string_append(&v7105, (int)&Dst, "gold-bracelet4-random2.cub");
  v7813 = 699;
  v1512 = this_4pointer_off((void *)v6, 557);
  something_database(*(_DWORD *)v1512, v1511, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7105);
  v1513 = (int)std_string_append(&v5277, (int)&Dst, "gold-bracelet5-random2.cub");
  v7813 = 700;
  v1514 = this_4pointer_off((void *)v6, 558);
  something_database(*(_DWORD *)v1514, v1513, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5277);
  v1515 = (int)std_string_append(&v7103, (int)&Dst, "gold-bracelet1-random3.cub");
  v7813 = 701;
  v1516 = this_4pointer_off((void *)v6, 559);
  something_database(*(_DWORD *)v1516, v1515, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7103);
  v1517 = (int)std_string_append(&v6175, (int)&Dst, "gold-bracelet2-random3.cub");
  v7813 = 702;
  v1518 = this_4pointer_off((void *)v6, 560);
  something_database(*(_DWORD *)v1518, v1517, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6175);
  v1519 = (int)std_string_append(&v7101, (int)&Dst, "gold-bracelet3-random3.cub");
  v7813 = 703;
  v1520 = this_4pointer_off((void *)v6, 561);
  something_database(*(_DWORD *)v1520, v1519, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7101);
  v1521 = (int)std_string_append(&v5711, (int)&Dst, "gold-bracelet4-random3.cub");
  v7813 = 704;
  v1522 = this_4pointer_off((void *)v6, 562);
  something_database(*(_DWORD *)v1522, v1521, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5711);
  v1523 = (int)std_string_append(&v7099, (int)&Dst, "gold-bracelet5-random3.cub");
  v7813 = 705;
  v1524 = this_4pointer_off((void *)v6, 563);
  something_database(*(_DWORD *)v1524, v1523, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7099);
  v1525 = (int)std_string_append(&v6173, (int)&Dst, "gold-bracelet1-random4.cub");
  v7813 = 706;
  v1526 = this_4pointer_off((void *)v6, 564);
  something_database(*(_DWORD *)v1526, v1525, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6173);
  v1527 = (int)std_string_append(&v7097, (int)&Dst, "gold-bracelet2-random4.cub");
  v7813 = 707;
  v1528 = this_4pointer_off((void *)v6, 565);
  something_database(*(_DWORD *)v1528, v1527, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7097);
  v1529 = (int)std_string_append(&v5479, (int)&Dst, "gold-bracelet3-random4.cub");
  v7813 = 708;
  v1530 = this_4pointer_off((void *)v6, 566);
  something_database(*(_DWORD *)v1530, v1529, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5479);
  v1531 = (int)std_string_append(&v7095, (int)&Dst, "gold-bracelet4-random4.cub");
  v7813 = 709;
  v1532 = this_4pointer_off((void *)v6, 567);
  something_database(*(_DWORD *)v1532, v1531, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7095);
  v1533 = (int)std_string_append(&v6171, (int)&Dst, "gold-bracelet5-random4.cub");
  v7813 = 710;
  v1534 = this_4pointer_off((void *)v6, 568);
  something_database(*(_DWORD *)v1534, v1533, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6171);
  v1535 = (int)std_string_append(&v7093, (int)&Dst, "gold-bracelet1-random5.cub");
  v7813 = 711;
  v1536 = this_4pointer_off((void *)v6, 569);
  something_database(*(_DWORD *)v1536, v1535, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7093);
  v1537 = (int)std_string_append(&v5709, (int)&Dst, "gold-bracelet2-random5.cub");
  v7813 = 712;
  v1538 = this_4pointer_off((void *)v6, 570);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1537;
  something_database(*(_DWORD *)v1538, v1537, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5709);
  v1539 = (int)std_string_append(&v7091, (int)&Dst, "gold-bracelet3-random5.cub");
  v7813 = 713;
  v1540 = this_4pointer_off((void *)v6, 571);
  something_database(*(_DWORD *)v1540, v1539, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7091);
  v1541 = (int)std_string_append(&v6169, (int)&Dst, "gold-bracelet4-random5.cub");
  v7813 = 714;
  v1542 = this_4pointer_off((void *)v6, 572);
  something_database(*(_DWORD *)v1542, v1541, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6169);
  v1543 = (int)std_string_append(&v7089, (int)&Dst, "gold-bracelet5-random5.cub");
  v7813 = 715;
  v1544 = this_4pointer_off((void *)v6, 573);
  something_database(*(_DWORD *)v1544, v1543, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7089);
  v1545 = (int)std_string_append(&v5363, (int)&Dst, "silver-bracelet1.cub");
  v7813 = 716;
  v1546 = this_4pointer_off((void *)v6, 574);
  something_database(*(_DWORD *)v1546, v1545, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5363);
  v1547 = (int)std_string_append(&v7087, (int)&Dst, "silver-bracelet2.cub");
  v7813 = 717;
  v1548 = this_4pointer_off((void *)v6, 575);
  something_database(*(_DWORD *)v1548, v1547, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7087);
  v1549 = (int)std_string_append(&v6167, (int)&Dst, "silver-bracelet3.cub");
  v7813 = 718;
  v1550 = this_4pointer_off((void *)v6, 576);
  something_database(*(_DWORD *)v1550, v1549, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6167);
  v1551 = (int)std_string_append(&v7085, (int)&Dst, "silver-bracelet4.cub");
  v7813 = 719;
  v1552 = this_4pointer_off((void *)v6, 577);
  something_database(*(_DWORD *)v1552, v1551, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7085);
  v1553 = (int)std_string_append(&v5707, (int)&Dst, "silver-bracelet5.cub");
  v7813 = 720;
  v1554 = this_4pointer_off((void *)v6, 578);
  something_database(*(_DWORD *)v1554, v1553, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5707);
  v1555 = (int)std_string_append(&v7083, (int)&Dst, "silver-bracelet1-random1.cub");
  v7813 = 721;
  v1556 = this_4pointer_off((void *)v6, 579);
  something_database(*(_DWORD *)v1556, v1555, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7083);
  v1557 = (int)std_string_append(&v6165, (int)&Dst, "silver-bracelet2-random1.cub");
  v7813 = 722;
  v1558 = this_4pointer_off((void *)v6, 580);
  something_database(*(_DWORD *)v1558, v1557, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6165);
  v1559 = (int)std_string_append(&v7081, (int)&Dst, "silver-bracelet3-random1.cub");
  v7813 = 723;
  v1560 = this_4pointer_off((void *)v6, 581);
  something_database(*(_DWORD *)v1560, v1559, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7081);
  v1561 = (int)std_string_append(&v5477, (int)&Dst, "silver-bracelet4-random1.cub");
  v7813 = 724;
  v1562 = this_4pointer_off((void *)v6, 582);
  something_database(*(_DWORD *)v1562, v1561, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5477);
  v1563 = (int)std_string_append(&v7079, (int)&Dst, "silver-bracelet5-random1.cub");
  v7813 = 725;
  v1564 = this_4pointer_off((void *)v6, 583);
  something_database(*(_DWORD *)v1564, v1563, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7079);
  v1565 = (int)std_string_append(&v6163, (int)&Dst, "silver-bracelet1-random2.cub");
  v7813 = 726;
  v1566 = this_4pointer_off((void *)v6, 584);
  something_database(*(_DWORD *)v1566, v1565, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6163);
  v1567 = (int)std_string_append(&v7077, (int)&Dst, "silver-bracelet2-random2.cub");
  v7813 = 727;
  v1568 = this_4pointer_off((void *)v6, 585);
  something_database(*(_DWORD *)v1568, v1567, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7077);
  v1569 = (int)std_string_append(&v5705, (int)&Dst, "silver-bracelet3-random2.cub");
  v7813 = 728;
  v1570 = this_4pointer_off((void *)v6, 586);
  something_database(*(_DWORD *)v1570, v1569, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5705);
  v1571 = (int)std_string_append(&v7075, (int)&Dst, "silver-bracelet4-random2.cub");
  v7813 = 729;
  v1572 = this_4pointer_off((void *)v6, 587);
  something_database(*(_DWORD *)v1572, v1571, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7075);
  v1573 = (int)std_string_append(&v6161, (int)&Dst, "silver-bracelet5-random2.cub");
  v7813 = 730;
  v1574 = this_4pointer_off((void *)v6, 588);
  something_database(*(_DWORD *)v1574, v1573, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6161);
  v1575 = (int)std_string_append(&v7073, (int)&Dst, "silver-bracelet1-random3.cub");
  v7813 = 731;
  v1576 = this_4pointer_off((void *)v6, 589);
  something_database(*(_DWORD *)v1576, v1575, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7073);
  v1577 = (int)std_string_append(&v5305, (int)&Dst, "silver-bracelet2-random3.cub");
  v7813 = 732;
  v1578 = this_4pointer_off((void *)v6, 590);
  something_database(*(_DWORD *)v1578, v1577, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5305);
  v1579 = (int)std_string_append(&v7071, (int)&Dst, "silver-bracelet3-random3.cub");
  v7813 = 733;
  v1580 = this_4pointer_off((void *)v6, 591);
  something_database(*(_DWORD *)v1580, v1579, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7071);
  v1581 = (int)std_string_append(&v6159, (int)&Dst, "silver-bracelet4-random3.cub");
  v7813 = 734;
  v1582 = this_4pointer_off((void *)v6, 592);
  something_database(*(_DWORD *)v1582, v1581, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6159);
  v1583 = (int)std_string_append(&v7069, (int)&Dst, "silver-bracelet5-random3.cub");
  v7813 = 735;
  v1584 = this_4pointer_off((void *)v6, 593);
  something_database(*(_DWORD *)v1584, v1583, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7069);
  v1585 = (int)std_string_append(&v5703, (int)&Dst, "silver-bracelet1-random4.cub");
  v7813 = 736;
  v1586 = this_4pointer_off((void *)v6, 594);
  something_database(*(_DWORD *)v1586, v1585, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5703);
  v1587 = (int)std_string_append(&v7067, (int)&Dst, "silver-bracelet2-random4.cub");
  v7813 = 737;
  v1588 = this_4pointer_off((void *)v6, 595);
  something_database(*(_DWORD *)v1588, v1587, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7067);
  v1589 = (int)std_string_append(&v6157, (int)&Dst, "silver-bracelet3-random4.cub");
  v7813 = 738;
  v1590 = this_4pointer_off((void *)v6, 596);
  something_database(*(_DWORD *)v1590, v1589, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6157);
  v1591 = (int)std_string_append(&v7065, (int)&Dst, "silver-bracelet4-random4.cub");
  v7813 = 739;
  v1592 = this_4pointer_off((void *)v6, 597);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1591;
  something_database(*(_DWORD *)v1592, v1591, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7065);
  v1593 = (int)std_string_append(&v5475, (int)&Dst, "silver-bracelet5-random4.cub");
  v7813 = 740;
  v1594 = this_4pointer_off((void *)v6, 598);
  something_database(*(_DWORD *)v1594, v1593, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5475);
  v1595 = (int)std_string_append(&v7063, (int)&Dst, "silver-bracelet1-random5.cub");
  v7813 = 741;
  v1596 = this_4pointer_off((void *)v6, 599);
  something_database(*(_DWORD *)v1596, v1595, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7063);
  v1597 = (int)std_string_append(&v6155, (int)&Dst, "silver-bracelet2-random5.cub");
  v7813 = 742;
  v1598 = this_4pointer_off((void *)v6, 600);
  something_database(*(_DWORD *)v1598, v1597, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6155);
  v1599 = (int)std_string_append(&v7061, (int)&Dst, "silver-bracelet3-random5.cub");
  v7813 = 743;
  v1600 = this_4pointer_off((void *)v6, 601);
  something_database(*(_DWORD *)v1600, v1599, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7061);
  v1601 = (int)std_string_append(&v5701, (int)&Dst, "silver-bracelet4-random5.cub");
  v7813 = 744;
  v1602 = this_4pointer_off((void *)v6, 602);
  something_database(*(_DWORD *)v1602, v1601, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5701);
  v1603 = (int)std_string_append(&v7059, (int)&Dst, "silver-bracelet5-random5.cub");
  v7813 = 745;
  v1604 = this_4pointer_off((void *)v6, 603);
  something_database(*(_DWORD *)v1604, v1603, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7059);
  v1605 = (int)std_string_append(&v6153, (int)&Dst, "iron-mace1.cub");
  v7813 = 746;
  v1606 = this_4pointer_off((void *)v6, 609);
  something_database(*(_DWORD *)v1606, v1605, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6153);
  v1607 = (int)std_string_append(&v7057, (int)&Dst, "iron-mace2.cub");
  v7813 = 747;
  v1608 = this_4pointer_off((void *)v6, 610);
  something_database(*(_DWORD *)v1608, v1607, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7057);
  v1609 = (int)std_string_append(&v5361, (int)&Dst, "iron-mace3.cub");
  v7813 = 748;
  v1610 = this_4pointer_off((void *)v6, 611);
  something_database(*(_DWORD *)v1610, v1609, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5361);
  v1611 = (int)std_string_append(&v7055, (int)&Dst, "iron-mace4.cub");
  v7813 = 749;
  v1612 = this_4pointer_off((void *)v6, 612);
  something_database(*(_DWORD *)v1612, v1611, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7055);
  v1613 = (int)std_string_append(&v6151, (int)&Dst, "iron-mace5.cub");
  v7813 = 750;
  v1614 = this_4pointer_off((void *)v6, 613);
  something_database(*(_DWORD *)v1614, v1613, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6151);
  v1615 = (int)std_string_append(&v7053, (int)&Dst, "iron-mace1-random1.cub");
  v7813 = 751;
  v1616 = this_4pointer_off((void *)v6, 614);
  something_database(*(_DWORD *)v1616, v1615, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7053);
  v1617 = (int)std_string_append(&v5699, (int)&Dst, "iron-mace2-random1.cub");
  v7813 = 752;
  v1618 = this_4pointer_off((void *)v6, 615);
  something_database(*(_DWORD *)v1618, v1617, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5699);
  v1619 = (int)std_string_append(&v7051, (int)&Dst, "iron-mace3-random1.cub");
  v7813 = 753;
  v1620 = this_4pointer_off((void *)v6, 616);
  something_database(*(_DWORD *)v1620, v1619, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7051);
  v1621 = (int)std_string_append(&v6149, (int)&Dst, "iron-mace4-random1.cub");
  v7813 = 754;
  v1622 = this_4pointer_off((void *)v6, 617);
  something_database(*(_DWORD *)v1622, v1621, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6149);
  v1623 = (int)std_string_append(&v7049, (int)&Dst, "iron-mace5-random1.cub");
  v7813 = 755;
  v1624 = this_4pointer_off((void *)v6, 618);
  something_database(*(_DWORD *)v1624, v1623, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7049);
  v1625 = (int)std_string_append(&v5473, (int)&Dst, "iron-mace1-random2.cub");
  v7813 = 756;
  v1626 = this_4pointer_off((void *)v6, 619);
  something_database(*(_DWORD *)v1626, v1625, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5473);
  v1627 = (int)std_string_append(&v7047, (int)&Dst, "iron-mace2-random2.cub");
  v7813 = 757;
  v1628 = this_4pointer_off((void *)v6, 620);
  something_database(*(_DWORD *)v1628, v1627, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7047);
  v1629 = (int)std_string_append(&v6147, (int)&Dst, "iron-mace3-random2.cub");
  v7813 = 758;
  v1630 = this_4pointer_off((void *)v6, 621);
  something_database(*(_DWORD *)v1630, v1629, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6147);
  v1631 = (int)std_string_append(&v7045, (int)&Dst, "iron-mace4-random2.cub");
  v7813 = 759;
  v1632 = this_4pointer_off((void *)v6, 622);
  something_database(*(_DWORD *)v1632, v1631, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7045);
  v1633 = (int)std_string_append(&v5697, (int)&Dst, "iron-mace5-random2.cub");
  v7813 = 760;
  v1634 = this_4pointer_off((void *)v6, 623);
  something_database(*(_DWORD *)v1634, v1633, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5697);
  v1635 = (int)std_string_append(&v7043, (int)&Dst, "iron-mace1-random3.cub");
  v7813 = 761;
  v1636 = this_4pointer_off((void *)v6, 624);
  something_database(*(_DWORD *)v1636, v1635, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7043);
  v1637 = (int)std_string_append(&v6145, (int)&Dst, "iron-mace2-random3.cub");
  v7813 = 762;
  v1638 = this_4pointer_off((void *)v6, 625);
  something_database(*(_DWORD *)v1638, v1637, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6145);
  v1639 = (int)std_string_append(&v7041, (int)&Dst, "iron-mace3-random3.cub");
  v7813 = 763;
  v1640 = this_4pointer_off((void *)v6, 626);
  something_database(*(_DWORD *)v1640, v1639, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7041);
  v1641 = (int)std_string_append(&v5255, (int)&Dst, "iron-mace4-random3.cub");
  v7813 = 764;
  v1642 = this_4pointer_off((void *)v6, 627);
  something_database(*(_DWORD *)v1642, v1641, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5255);
  v1643 = (int)std_string_append(&v7039, (int)&Dst, "iron-mace5-random3.cub");
  v7813 = 765;
  v1644 = this_4pointer_off((void *)v6, 628);
  something_database(*(_DWORD *)v1644, v1643, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7039);
  v1645 = (int)std_string_append(&v6143, (int)&Dst, (const char *)"iron-mace1-random4.cub");
  v7813 = 766;
  v1646 = this_4pointer_off((void *)v6, 629);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1645;
  something_database(*(_DWORD *)v1646, v1645, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6143);
  v1647 = (int)std_string_append(&v7037, (int)&Dst, "iron-mace2-random4.cub");
  v7813 = 767;
  v1648 = this_4pointer_off((void *)v6, 630);
  something_database(*(_DWORD *)v1648, v1647, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7037);
  v1649 = (int)std_string_append(&v5695, (int)&Dst, "iron-mace3-random4.cub");
  v7813 = 768;
  v1650 = this_4pointer_off((void *)v6, 631);
  something_database(*(_DWORD *)v1650, v1649, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5695);
  v1651 = (int)std_string_append(&v7035, (int)&Dst, "iron-mace4-random4.cub");
  v7813 = 769;
  v1652 = this_4pointer_off((void *)v6, 632);
  something_database(*(_DWORD *)v1652, v1651, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7035);
  v1653 = (int)std_string_append(&v6141, (int)&Dst, "iron-mace5-random4.cub");
  v7813 = 770;
  v1654 = this_4pointer_off((void *)v6, 633);
  something_database(*(_DWORD *)v1654, v1653, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6141);
  v1655 = (int)std_string_append(&v7033, (int)&Dst, "iron-mace1-random5.cub");
  v7813 = 771;
  v1656 = this_4pointer_off((void *)v6, 634);
  something_database(*(_DWORD *)v1656, v1655, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7033);
  v1657 = (int)std_string_append(&v5471, (int)&Dst, "iron-mace2-random5.cub");
  v7813 = 772;
  v1658 = this_4pointer_off((void *)v6, 635);
  something_database(*(_DWORD *)v1658, v1657, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5471);
  v1659 = (int)std_string_append(&v7031, (int)&Dst, "iron-mace3-random5.cub");
  v7813 = 773;
  v1660 = this_4pointer_off((void *)v6, 636);
  something_database(*(_DWORD *)v1660, v1659, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7031);
  v1661 = (int)std_string_append(&v6139, (int)&Dst, "iron-mace4-random5.cub");
  v7813 = 774;
  v1662 = this_4pointer_off((void *)v6, 637);
  something_database(*(_DWORD *)v1662, v1661, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6139);
  v1663 = (int)std_string_append(&v7029, (int)&Dst, "iron-mace5-random5.cub");
  v7813 = 775;
  v1664 = this_4pointer_off((void *)v6, 638);
  something_database(*(_DWORD *)v1664, v1663, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7029);
  v1665 = (int)std_string_append(&v5693, (int)&Dst, "iron-mace1-random6.cub");
  v7813 = 776;
  v1666 = this_4pointer_off((void *)v6, 639);
  something_database(*(_DWORD *)v1666, v1665, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5693);
  v1667 = (int)std_string_append(&v7027, (int)&Dst, "iron-mace2-random6.cub");
  v7813 = 777;
  v1668 = this_4pointer_off((void *)v6, 640);
  something_database(*(_DWORD *)v1668, v1667, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7027);
  v1669 = (int)std_string_append(&v6137, (int)&Dst, "iron-mace3-random6.cub");
  v7813 = 778;
  v1670 = this_4pointer_off((void *)v6, 641);
  something_database(*(_DWORD *)v1670, v1669, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6137);
  v1671 = (int)std_string_append(&v7025, (int)&Dst, "iron-mace4-random6.cub");
  v7813 = 779;
  v1672 = this_4pointer_off((void *)v6, 642);
  something_database(*(_DWORD *)v1672, v1671, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7025);
  v1673 = (int)std_string_append(&v5359, (int)&Dst, "iron-mace5-random6.cub");
  v7813 = 780;
  v1674 = this_4pointer_off((void *)v6, 643);
  something_database(*(_DWORD *)v1674, v1673, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5359);
  v1675 = (int)std_string_append(&v7023, (int)&Dst, "iron-mace1-random7.cub");
  v7813 = 781;
  v1676 = this_4pointer_off((void *)v6, 644);
  something_database(*(_DWORD *)v1676, v1675, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7023);
  v1677 = (int)std_string_append(&v6135, (int)&Dst, "iron-mace2-random7.cub");
  v7813 = 782;
  v1678 = this_4pointer_off((void *)v6, 645);
  something_database(*(_DWORD *)v1678, v1677, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6135);
  v1679 = (int)std_string_append(&v7021, (int)&Dst, "iron-mace3-random7.cub");
  v7813 = 783;
  v1680 = this_4pointer_off((void *)v6, 646);
  something_database(*(_DWORD *)v1680, v1679, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7021);
  v1681 = (int)std_string_append(&v5691, (int)&Dst, "iron-mace4-random7.cub");
  v7813 = 784;
  v1682 = this_4pointer_off((void *)v6, 647);
  something_database(*(_DWORD *)v1682, v1681, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5691);
  v1683 = (int)std_string_append(&v7019, (int)&Dst, "iron-mace5-random7.cub");
  v7813 = 785;
  v1684 = this_4pointer_off((void *)v6, 648);
  something_database(*(_DWORD *)v1684, v1683, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7019);
  v1685 = (int)std_string_append(&v6133, (int)&Dst, "iron-mace1-random8.cub");
  v7813 = 786;
  v1686 = this_4pointer_off((void *)v6, 649);
  something_database(*(_DWORD *)v1686, v1685, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6133);
  v1687 = (int)std_string_append(&v7017, (int)&Dst, "iron-mace2-random8.cub");
  v7813 = 787;
  v1688 = this_4pointer_off((void *)v6, 650);
  something_database(*(_DWORD *)v1688, v1687, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7017);
  v1689 = (int)std_string_append(&v5469, (int)&Dst, "iron-mace3-random8.cub");
  v7813 = 788;
  v1690 = this_4pointer_off((void *)v6, 651);
  something_database(*(_DWORD *)v1690, v1689, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5469);
  v1691 = (int)std_string_append(&v7015, (int)&Dst, "iron-mace4-random8.cub");
  v7813 = 789;
  v1692 = this_4pointer_off((void *)v6, 652);
  something_database(*(_DWORD *)v1692, v1691, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7015);
  v1693 = (int)std_string_append(&v6131, (int)&Dst, "iron-mace5-random8.cub");
  v7813 = 790;
  v1694 = this_4pointer_off((void *)v6, 653);
  something_database(*(_DWORD *)v1694, v1693, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6131);
  v1695 = (int)std_string_append(&v7013, (int)&Dst, "iron-mace1-random9.cub");
  v7813 = 791;
  v1696 = this_4pointer_off((void *)v6, 654);
  something_database(*(_DWORD *)v1696, v1695, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7013);
  v1697 = (int)std_string_append(&v5689, (int)&Dst, "iron-mace2-random9.cub");
  v7813 = 792;
  v1698 = this_4pointer_off((void *)v6, 655);
  something_database(*(_DWORD *)v1698, v1697, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5689);
  v1699 = (int)std_string_append(&v7011, (int)&Dst, "iron-mace3-random9.cub");
  v7813 = 793;
  v1700 = this_4pointer_off((void *)v6, 656);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1699;
  something_database(*(_DWORD *)v1700, v1699, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7011);
  v1701 = (int)std_string_append(&v6129, (int)&Dst, "iron-mace4-random9.cub");
  v7813 = 794;
  v1702 = this_4pointer_off((void *)v6, 657);
  something_database(*(_DWORD *)v1702, v1701, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6129);
  v1703 = (int)std_string_append(&v7009, (int)&Dst, "iron-mace5-random9.cub");
  v7813 = 795;
  v1704 = this_4pointer_off((void *)v6, 658);
  something_database(*(_DWORD *)v1704, v1703, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7009);
  v1705 = (int)std_string_append(&v5303, (int)&Dst, "iron-mace1-random10.cub");
  v7813 = 796;
  v1706 = this_4pointer_off((void *)v6, 659);
  something_database(*(_DWORD *)v1706, v1705, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5303);
  v1707 = (int)std_string_append(&v7007, (int)&Dst, "iron-mace2-random10.cub");
  v7813 = 797;
  v1708 = this_4pointer_off((void *)v6, 660);
  something_database(*(_DWORD *)v1708, v1707, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7007);
  v1709 = (int)std_string_append(&v6127, (int)&Dst, "iron-mace3-random10.cub");
  v7813 = 798;
  v1710 = this_4pointer_off((void *)v6, 661);
  something_database(*(_DWORD *)v1710, v1709, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6127);
  v1711 = (int)std_string_append(&v7005, (int)&Dst, "iron-mace4-random10.cub");
  v7813 = 799;
  v1712 = this_4pointer_off((void *)v6, 662);
  something_database(*(_DWORD *)v1712, v1711, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v7005);
  v1713 = (int)std_string_append(&v5687, (int)&Dst, "iron-mace5-random10.cub");
  v7813 = 800;
  v1714 = this_4pointer_off((void *)v6, 663);
  something_database(*(_DWORD *)v1714, v1713, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5687);
  v1715 = (int)std_string_append(&v7003, (int)&Dst, "wood-mace01.cub");
  v7813 = 801;
  v1716 = this_4pointer_off((void *)v6, 664);
  something_database(*(_DWORD *)v1716, v1715, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7003);
  v1717 = (int)std_string_append(&v6125, (int)&Dst, "wood-mace02.cub");
  v7813 = 802;
  v1718 = this_4pointer_off((void *)v6, 665);
  something_database(*(_DWORD *)v1718, v1717, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6125);
  v1719 = (int)std_string_append(&v7001, (int)&Dst, "wood-mace03.cub");
  v7813 = 803;
  v1720 = this_4pointer_off((void *)v6, 666);
  something_database(*(_DWORD *)v1720, v1719, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7001);
  v1721 = (int)std_string_append(&v5467, (int)&Dst, "wood-mace04.cub");
  v7813 = 804;
  v1722 = this_4pointer_off((void *)v6, 667);
  something_database(*(_DWORD *)v1722, v1721, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5467);
  v1723 = (int)std_string_append(&v6999, (int)&Dst, "wood-mace05.cub");
  v7813 = 805;
  v1724 = this_4pointer_off((void *)v6, 668);
  something_database(*(_DWORD *)v1724, v1723, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6999);
  v1725 = (int)std_string_append(&v6123, (int)&Dst, "bow.cub");
  v7813 = 806;
  v1726 = this_4pointer_off((void *)v6, 674);
  something_database(*(_DWORD *)v1726, v1725, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6123);
  v1727 = (int)std_string_append(&v6997, (int)&Dst, "wood-bow2.cub");
  v7813 = 807;
  v1728 = this_4pointer_off((void *)v6, 675);
  something_database(*(_DWORD *)v1728, v1727, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6997);
  v1729 = (int)std_string_append(&v5685, (int)&Dst, "wood-bow3.cub");
  v7813 = 808;
  v1730 = this_4pointer_off((void *)v6, 676);
  something_database(*(_DWORD *)v1730, v1729, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5685);
  v1731 = (int)std_string_append(&v6995, (int)&Dst, "wood-bow4.cub");
  v7813 = 809;
  v1732 = this_4pointer_off((void *)v6, 677);
  something_database(*(_DWORD *)v1732, v1731, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6995);
  v1733 = (int)std_string_append(&v6121, (int)&Dst, "wood-bow5.cub");
  v7813 = 810;
  v1734 = this_4pointer_off((void *)v6, 678);
  something_database(*(_DWORD *)v1734, v1733, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6121);
  v1735 = (int)std_string_append(&v6993, (int)&Dst, "wood-bow1-random1.cub");
  v7813 = 811;
  v1736 = this_4pointer_off((void *)v6, 679);
  something_database(*(_DWORD *)v1736, v1735, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6993);
  v1737 = (int)std_string_append(&v5357, (int)&Dst, "wood-bow2-random1.cub");
  v7813 = 812;
  v1738 = this_4pointer_off((void *)v6, 680);
  something_database(*(_DWORD *)v1738, v1737, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5357);
  v1739 = (int)std_string_append(&v6991, (int)&Dst, "wood-bow3-random1.cub");
  v7813 = 813;
  v1740 = this_4pointer_off((void *)v6, 681);
  something_database(*(_DWORD *)v1740, v1739, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6991);
  v1741 = (int)std_string_append(&v6119, (int)&Dst, "wood-bow4-random1.cub");
  v7813 = 814;
  v1742 = this_4pointer_off((void *)v6, 682);
  something_database(*(_DWORD *)v1742, v1741, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6119);
  v1743 = (int)std_string_append(&v6989, (int)&Dst, "wood-bow5-random1.cub");
  v7813 = 815;
  v1744 = this_4pointer_off((void *)v6, 683);
  something_database(*(_DWORD *)v1744, v1743, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6989);
  v1745 = (int)std_string_append(&v5683, (int)&Dst, "wood-bow1-random2.cub");
  v7813 = 816;
  v1746 = this_4pointer_off((void *)v6, 684);
  something_database(*(_DWORD *)v1746, v1745, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5683);
  v1747 = (int)std_string_append(&v6987, (int)&Dst, "wood-bow2-random2.cub");
  v7813 = 817;
  v1748 = this_4pointer_off((void *)v6, 685);
  something_database(*(_DWORD *)v1748, v1747, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6987);
  v1749 = (int)std_string_append(&v6117, (int)&Dst, "wood-bow3-random2.cub");
  v7813 = 818;
  v1750 = this_4pointer_off((void *)v6, 686);
  something_database(*(_DWORD *)v1750, v1749, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6117);
  v1751 = (int)std_string_append(&v6985, (int)&Dst, "wood-bow4-random2.cub");
  v7813 = 819;
  v1752 = this_4pointer_off((void *)v6, 687);
  something_database(*(_DWORD *)v1752, v1751, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6985);
  v1753 = (int)std_string_append(&v5465, (int)&Dst, "wood-bow5-random2.cub");
  v7813 = 820;
  v1754 = this_4pointer_off((void *)v6, 688);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1753;
  something_database(*(_DWORD *)v1754, v1753, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5465);
  v1755 = (int)std_string_append(&v6983, (int)&Dst, "wood-bow1-random3.cub");
  v7813 = 821;
  v1756 = this_4pointer_off((void *)v6, 689);
  something_database(*(_DWORD *)v1756, v1755, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6983);
  v1757 = (int)std_string_append(&v6115, (int)&Dst, "wood-bow2-random3.cub");
  v7813 = 822;
  v1758 = this_4pointer_off((void *)v6, 690);
  something_database(*(_DWORD *)v1758, v1757, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6115);
  v1759 = (int)std_string_append(&v6981, (int)&Dst, "wood-bow3-random3.cub");
  v7813 = 823;
  v1760 = this_4pointer_off((void *)v6, 691);
  something_database(*(_DWORD *)v1760, v1759, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6981);
  v1761 = (int)std_string_append(&v5681, (int)&Dst, "wood-bow4-random3.cub");
  v7813 = 824;
  v1762 = this_4pointer_off((void *)v6, 692);
  something_database(*(_DWORD *)v1762, v1761, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5681);
  v1763 = (int)std_string_append(&v6979, (int)&Dst, "wood-bow5-random3.cub");
  v7813 = 825;
  v1764 = this_4pointer_off((void *)v6, 693);
  something_database(*(_DWORD *)v1764, v1763, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6979);
  v1765 = (int)std_string_append(&v6113, (int)&Dst, "wood-bow1-random4.cub");
  v7813 = 826;
  v1766 = this_4pointer_off((void *)v6, 694);
  something_database(*(_DWORD *)v1766, v1765, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6113);
  v1767 = (int)std_string_append(&v6977, (int)&Dst, "wood-bow2-random4.cub");
  v7813 = 827;
  v1768 = this_4pointer_off((void *)v6, 695);
  something_database(*(_DWORD *)v1768, v1767, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6977);
  v1769 = (int)std_string_append(&v5275, (int)&Dst, "wood-bow3-random4.cub");
  v7813 = 828;
  v1770 = this_4pointer_off((void *)v6, 696);
  something_database(*(_DWORD *)v1770, v1769, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5275);
  v1771 = (int)std_string_append(&v6975, (int)&Dst, "wood-bow4-random4.cub");
  v7813 = 829;
  v1772 = this_4pointer_off((void *)v6, 697);
  something_database(*(_DWORD *)v1772, v1771, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6975);
  v1773 = (int)std_string_append(&v6111, (int)&Dst, "wood-bow5-random4.cub");
  v7813 = 830;
  v1774 = this_4pointer_off((void *)v6, 698);
  something_database(*(_DWORD *)v1774, v1773, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6111);
  v1775 = (int)std_string_append(&v6973, (int)&Dst, "wood-bow1-random5.cub");
  v7813 = 831;
  v1776 = this_4pointer_off((void *)v6, 699);
  something_database(*(_DWORD *)v1776, v1775, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6973);
  v1777 = (int)std_string_append(&v5679, (int)&Dst, "wood-bow2-random5.cub");
  v7813 = 832;
  v1778 = this_4pointer_off((void *)v6, 700);
  something_database(*(_DWORD *)v1778, v1777, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5679);
  v1779 = (int)std_string_append(&v6971, (int)&Dst, "wood-bow3-random5.cub");
  v7813 = 833;
  v1780 = this_4pointer_off((void *)v6, 701);
  something_database(*(_DWORD *)v1780, v1779, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6971);
  v1781 = (int)std_string_append(&v6109, (int)&Dst, "wood-bow4-random5.cub");
  v7813 = 834;
  v1782 = this_4pointer_off((void *)v6, 702);
  something_database(*(_DWORD *)v1782, v1781, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6109);
  v1783 = (int)std_string_append(&v6969, (int)&Dst, "wood-bow5-random5.cub");
  v7813 = 835;
  v1784 = this_4pointer_off((void *)v6, 703);
  something_database(*(_DWORD *)v1784, v1783, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6969);
  v1785 = (int)std_string_append(&v5463, (int)&Dst, "wood-bow1-random6.cub");
  v7813 = 836;
  v1786 = this_4pointer_off((void *)v6, 704);
  something_database(*(_DWORD *)v1786, v1785, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5463);
  v1787 = (int)std_string_append(&v6967, (int)&Dst, "wood-bow2-random6.cub");
  v7813 = 837;
  v1788 = this_4pointer_off((void *)v6, 705);
  something_database(*(_DWORD *)v1788, v1787, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6967);
  v1789 = (int)std_string_append(&v6107, (int)&Dst, "wood-bow3-random6.cub");
  v7813 = 838;
  v1790 = this_4pointer_off((void *)v6, 706);
  something_database(*(_DWORD *)v1790, v1789, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6107);
  v1791 = (int)std_string_append(&v6965, (int)&Dst, "wood-bow4-random6.cub");
  v7813 = 839;
  v1792 = this_4pointer_off((void *)v6, 707);
  something_database(*(_DWORD *)v1792, v1791, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6965);
  v1793 = (int)std_string_append(&v5677, (int)&Dst, "wood-bow5-random6.cub");
  v7813 = 840;
  v1794 = this_4pointer_off((void *)v6, 708);
  something_database(*(_DWORD *)v1794, v1793, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5677);
  v1795 = (int)std_string_append(&v6963, (int)&Dst, "wood-bow1-random7.cub");
  v7813 = 841;
  v1796 = this_4pointer_off((void *)v6, 709);
  something_database(*(_DWORD *)v1796, v1795, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6963);
  v1797 = (int)std_string_append(&v6105, (int)&Dst, "wood-bow2-random7.cub");
  v7813 = 842;
  v1798 = this_4pointer_off((void *)v6, 710);
  something_database(*(_DWORD *)v1798, v1797, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6105);
  v1799 = (int)std_string_append(&v6961, (int)&Dst, "wood-bow3-random7.cub");
  v7813 = 843;
  v1800 = this_4pointer_off((void *)v6, 711);
  something_database(*(_DWORD *)v1800, v1799, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6961);
  v1801 = (int)std_string_append(&v5355, (int)&Dst, "wood-bow4-random7.cub");
  v7813 = 844;
  v1802 = this_4pointer_off((void *)v6, 712);
  something_database(*(_DWORD *)v1802, v1801, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5355);
  v1803 = (int)std_string_append(&v6959, (int)&Dst, "wood-bow5-random7.cub");
  v7813 = 845;
  v1804 = this_4pointer_off((void *)v6, 713);
  something_database(*(_DWORD *)v1804, v1803, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6959);
  v1805 = (int)std_string_append(&v6103, (int)&Dst, "wood-bow1-random8.cub");
  v7813 = 846;
  v1806 = this_4pointer_off((void *)v6, 714);
  something_database(*(_DWORD *)v1806, v1805, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6103);
  v1807 = (int)std_string_append(&v6957, (int)&Dst, "wood-bow2-random8.cub");
  v7813 = 847;
  v1808 = this_4pointer_off((void *)v6, 715);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1807;
  something_database(*(_DWORD *)v1808, v1807, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6957);
  v1809 = (int)std_string_append(&v5675, (int)&Dst, "wood-bow3-random8.cub");
  v7813 = 848;
  v1810 = this_4pointer_off((void *)v6, 716);
  something_database(*(_DWORD *)v1810, v1809, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5675);
  v1811 = (int)std_string_append(&v6955, (int)&Dst, "wood-bow4-random8.cub");
  v7813 = 849;
  v1812 = this_4pointer_off((void *)v6, 717);
  something_database(*(_DWORD *)v1812, v1811, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6955);
  v1813 = (int)std_string_append(&v6101, (int)&Dst, "wood-bow5-random8.cub");
  v7813 = 850;
  v1814 = this_4pointer_off((void *)v6, 718);
  something_database(*(_DWORD *)v1814, v1813, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6101);
  v1815 = (int)std_string_append(&v6953, (int)&Dst, "wood-bow1-random9.cub");
  v7813 = 851;
  v1816 = this_4pointer_off((void *)v6, 719);
  something_database(*(_DWORD *)v1816, v1815, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6953);
  v1817 = (int)std_string_append(&v5461, (int)&Dst, "wood-bow2-random9.cub");
  v7813 = 852;
  v1818 = this_4pointer_off((void *)v6, 720);
  something_database(*(_DWORD *)v1818, v1817, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5461);
  v1819 = (int)std_string_append(&v6951, (int)&Dst, "wood-bow3-random9.cub");
  v7813 = 853;
  v1820 = this_4pointer_off((void *)v6, 721);
  something_database(*(_DWORD *)v1820, v1819, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6951);
  v1821 = (int)std_string_append(&v6099, (int)&Dst, "wood-bow4-random9.cub");
  v7813 = 854;
  v1822 = this_4pointer_off((void *)v6, 722);
  something_database(*(_DWORD *)v1822, v1821, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6099);
  v1823 = (int)std_string_append(&v6949, (int)&Dst, "wood-bow5-random9.cub");
  v7813 = 855;
  v1824 = this_4pointer_off((void *)v6, 723);
  something_database(*(_DWORD *)v1824, v1823, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6949);
  v1825 = (int)std_string_append(&v5673, (int)&Dst, "wood-bow1-random10.cub");
  v7813 = 856;
  v1826 = this_4pointer_off((void *)v6, 724);
  something_database(*(_DWORD *)v1826, v1825, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5673);
  v1827 = (int)std_string_append(&v6947, (int)&Dst, "wood-bow2-random10.cub");
  v7813 = 857;
  v1828 = this_4pointer_off((void *)v6, 725);
  something_database(*(_DWORD *)v1828, v1827, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6947);
  v1829 = (int)std_string_append(&v6097, (int)&Dst, "wood-bow3-random10.cub");
  v7813 = 858;
  v1830 = this_4pointer_off((void *)v6, 726);
  something_database(*(_DWORD *)v1830, v1829, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6097);
  v1831 = (int)std_string_append(&v6945, (int)&Dst, "wood-bow4-random10.cub");
  v7813 = 859;
  v1832 = this_4pointer_off((void *)v6, 727);
  something_database(*(_DWORD *)v1832, v1831, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6945);
  v1833 = (int)std_string_append(&v5301, (int)&Dst, "wood-bow5-random10.cub");
  v7813 = 860;
  v1834 = this_4pointer_off((void *)v6, 728);
  something_database(*(_DWORD *)v1834, v1833, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5301);
  v1835 = (int)std_string_append(&v6943, (int)&Dst, "wood-crossbow1.cub");
  v7813 = 861;
  v1836 = this_4pointer_off((void *)v6, 729);
  something_database(*(_DWORD *)v1836, v1835, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6943);
  v1837 = (int)std_string_append(&v6095, (int)&Dst, "wood-crossbow2.cub");
  v7813 = 862;
  v1838 = this_4pointer_off((void *)v6, 730);
  something_database(*(_DWORD *)v1838, v1837, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6095);
  v1839 = (int)std_string_append(&v6941, (int)&Dst, "wood-crossbow3.cub");
  v7813 = 863;
  v1840 = this_4pointer_off((void *)v6, 731);
  something_database(*(_DWORD *)v1840, v1839, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6941);
  v1841 = (int)std_string_append(&v5671, (int)&Dst, "wood-crossbow4.cub");
  v7813 = 864;
  v1842 = this_4pointer_off((void *)v6, 732);
  something_database(*(_DWORD *)v1842, v1841, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5671);
  v1843 = (int)std_string_append(&v6939, (int)&Dst, "wood-crossbow5.cub");
  v7813 = 865;
  v1844 = this_4pointer_off((void *)v6, 733);
  something_database(*(_DWORD *)v1844, v1843, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6939);
  v1845 = (int)std_string_append(&v6093, (int)&Dst, "wood-crossbow1-random1.cub");
  v7813 = 866;
  v1846 = this_4pointer_off((void *)v6, 734);
  something_database(*(_DWORD *)v1846, v1845, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6093);
  v1847 = (int)std_string_append(&v6937, (int)&Dst, "wood-crossbow2-random1.cub");
  v7813 = 867;
  v1848 = this_4pointer_off((void *)v6, 735);
  something_database(*(_DWORD *)v1848, v1847, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6937);
  v1849 = (int)std_string_append(&v5459, (int)&Dst, "wood-crossbow3-random1.cub");
  v7813 = 868;
  v1850 = this_4pointer_off((void *)v6, 736);
  something_database(*(_DWORD *)v1850, v1849, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5459);
  v1851 = (int)std_string_append(&v6935, (int)&Dst, "wood-crossbow4-random1.cub");
  v7813 = 869;
  v1852 = this_4pointer_off((void *)v6, 737);
  something_database(*(_DWORD *)v1852, v1851, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6935);
  v1853 = (int)std_string_append(&v6091, (int)&Dst, "wood-crossbow5-random1.cub");
  v7813 = 870;
  v1854 = this_4pointer_off((void *)v6, 738);
  something_database(*(_DWORD *)v1854, v1853, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6091);
  v1855 = (int)std_string_append(&v6933, (int)&Dst, "wood-crossbow1-random2.cub");
  v7813 = 871;
  v1856 = this_4pointer_off((void *)v6, 739);
  something_database(*(_DWORD *)v1856, v1855, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6933);
  v1857 = (int)std_string_append(&v5669, (int)&Dst, "wood-crossbow2-random2.cub");
  v7813 = 872;
  v1858 = this_4pointer_off((void *)v6, 740);
  something_database(*(_DWORD *)v1858, v1857, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5669);
  v1859 = (int)std_string_append(&v6931, (int)&Dst, "wood-crossbow3-random2.cub");
  v7813 = 873;
  v1860 = this_4pointer_off((void *)v6, 741);
  something_database(*(_DWORD *)v1860, v1859, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6931);
  v1861 = (int)std_string_append(&v6089, (int)&Dst, "wood-crossbow4-random2.cub");
  v7813 = 874;
  v1862 = this_4pointer_off((void *)v6, 742);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1861;
  something_database(*(_DWORD *)v1862, v1861, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6089);
  v1863 = (int)std_string_append(&v6929, (int)&Dst, "wood-crossbow5-random2.cub");
  v7813 = 875;
  v1864 = this_4pointer_off((void *)v6, 743);
  something_database(*(_DWORD *)v1864, v1863, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6929);
  v1865 = (int)std_string_append(&v5353, (int)&Dst, "wood-crossbow1-random3.cub");
  v7813 = 876;
  v1866 = this_4pointer_off((void *)v6, 744);
  something_database(*(_DWORD *)v1866, v1865, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5353);
  v1867 = (int)std_string_append(&v6927, (int)&Dst, "wood-crossbow2-random3.cub");
  v7813 = 877;
  v1868 = this_4pointer_off((void *)v6, 745);
  something_database(*(_DWORD *)v1868, v1867, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6927);
  v1869 = (int)std_string_append(&v6087, (int)&Dst, "wood-crossbow3-random3.cub");
  v7813 = 878;
  v1870 = this_4pointer_off((void *)v6, 746);
  something_database(*(_DWORD *)v1870, v1869, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6087);
  v1871 = (int)std_string_append(&v6925, (int)&Dst, "wood-crossbow4-random3.cub");
  v7813 = 879;
  v1872 = this_4pointer_off((void *)v6, 747);
  something_database(*(_DWORD *)v1872, v1871, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6925);
  v1873 = (int)std_string_append(&v5667, (int)&Dst, "wood-crossbow5-random3.cub");
  v7813 = 880;
  v1874 = this_4pointer_off((void *)v6, 748);
  something_database(*(_DWORD *)v1874, v1873, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5667);
  v1875 = (int)std_string_append(&v6923, (int)&Dst, "wood-crossbow1-random4.cub");
  v7813 = 881;
  v1876 = this_4pointer_off((void *)v6, 749);
  something_database(*(_DWORD *)v1876, v1875, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6923);
  v1877 = (int)std_string_append(&v6085, (int)&Dst, "wood-crossbow2-random4.cub");
  v7813 = 882;
  v1878 = this_4pointer_off((void *)v6, 750);
  something_database(*(_DWORD *)v1878, v1877, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6085);
  v1879 = (int)std_string_append(&v6921, (int)&Dst, "wood-crossbow3-random4.cub");
  v7813 = 883;
  v1880 = this_4pointer_off((void *)v6, 751);
  something_database(*(_DWORD *)v1880, v1879, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6921);
  v1881 = (int)std_string_append(&v5457, (int)&Dst, "wood-crossbow4-random4.cub");
  v7813 = 884;
  v1882 = this_4pointer_off((void *)v6, 752);
  something_database(*(_DWORD *)v1882, v1881, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5457);
  v1883 = (int)std_string_append(&v6919, (int)&Dst, "wood-crossbow5-random4.cub");
  v7813 = 885;
  v1884 = this_4pointer_off((void *)v6, 753);
  something_database(*(_DWORD *)v1884, v1883, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6919);
  v1885 = (int)std_string_append(&v6083, (int)&Dst, "wood-crossbow1-random5.cub");
  v7813 = 886;
  v1886 = this_4pointer_off((void *)v6, 754);
  something_database(*(_DWORD *)v1886, v1885, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6083);
  v1887 = (int)std_string_append(&v6917, (int)&Dst, "wood-crossbow2-random5.cub");
  v7813 = 887;
  v1888 = this_4pointer_off((void *)v6, 755);
  something_database(*(_DWORD *)v1888, v1887, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6917);
  v1889 = (int)std_string_append(&v5665, (int)&Dst, "wood-crossbow3-random5.cub");
  v7813 = 888;
  v1890 = this_4pointer_off((void *)v6, 756);
  something_database(*(_DWORD *)v1890, v1889, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5665);
  v1891 = (int)std_string_append(&v6915, (int)&Dst, "wood-crossbow4-random5.cub");
  v7813 = 889;
  v1892 = this_4pointer_off((void *)v6, 757);
  something_database(*(_DWORD *)v1892, v1891, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6915);
  v1893 = (int)std_string_append(&v6081, (int)&Dst, "wood-crossbow5-random5.cub");
  v7813 = 890;
  v1894 = this_4pointer_off((void *)v6, 758);
  something_database(*(_DWORD *)v1894, v1893, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6081);
  v1895 = (int)std_string_append(&v6913, (int)&Dst, "wood-crossbow1-random6.cub");
  v7813 = 891;
  v1896 = this_4pointer_off((void *)v6, 759);
  something_database(*(_DWORD *)v1896, v1895, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6913);
  v1897 = (int)std_string_append(&v5261, (int)&Dst, "wood-crossbow2-random6.cub");
  v7813 = 892;
  v1898 = this_4pointer_off((void *)v6, 760);
  something_database(*(_DWORD *)v1898, v1897, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5261);
  v1899 = (int)std_string_append(&v6911, (int)&Dst, "wood-crossbow3-random6.cub");
  v7813 = 893;
  v1900 = this_4pointer_off((void *)v6, 761);
  something_database(*(_DWORD *)v1900, v1899, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6911);
  v1901 = (int)std_string_append(&v6079, (int)&Dst, "wood-crossbow4-random6.cub");
  v7813 = 894;
  v1902 = this_4pointer_off((void *)v6, 762);
  something_database(*(_DWORD *)v1902, v1901, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6079);
  v1903 = (int)std_string_append(&v6909, (int)&Dst, "wood-crossbow5-random6.cub");
  v7813 = 895;
  v1904 = this_4pointer_off((void *)v6, 763);
  something_database(*(_DWORD *)v1904, v1903, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6909);
  v1905 = (int)std_string_append(&v5663, (int)&Dst, "wood-crossbow1-random7.cub");
  v7813 = 896;
  v1906 = this_4pointer_off((void *)v6, 764);
  something_database(*(_DWORD *)v1906, v1905, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5663);
  v1907 = (int)std_string_append(&v6907, (int)&Dst, "wood-crossbow2-random7.cub");
  v7813 = 897;
  v1908 = this_4pointer_off((void *)v6, 765);
  something_database(*(_DWORD *)v1908, v1907, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6907);
  v1909 = (int)std_string_append(&v6077, (int)&Dst, "wood-crossbow3-random7.cub");
  v7813 = 898;
  v1910 = this_4pointer_off((void *)v6, 766);
  something_database(*(_DWORD *)v1910, v1909, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6077);
  v1911 = (int)std_string_append(&v6905, (int)&Dst, "wood-crossbow4-random7.cub");
  v7813 = 899;
  v1912 = this_4pointer_off((void *)v6, 767);
  something_database(*(_DWORD *)v1912, v1911, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6905);
  v1913 = (int)std_string_append(&v5455, (int)&Dst, "wood-crossbow5-random7.cub");
  v7813 = 900;
  v1914 = this_4pointer_off((void *)v6, 768);
  something_database(*(_DWORD *)v1914, v1913, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5455);
  v1915 = (int)std_string_append(&v6903, (int)&Dst, "wood-crossbow1-random8.cub");
  v7813 = 901;
  v1916 = this_4pointer_off((void *)v6, 769);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1915;
  something_database(*(_DWORD *)v1916, v1915, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6903);
  v1917 = (int)std_string_append(&v6075, (int)&Dst, "wood-crossbow2-random8.cub");
  v7813 = 902;
  v1918 = this_4pointer_off((void *)v6, 770);
  something_database(*(_DWORD *)v1918, v1917, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6075);
  v1919 = (int)std_string_append(&v6901, (int)&Dst, "wood-crossbow3-random8.cub");
  v7813 = 903;
  v1920 = this_4pointer_off((void *)v6, 771);
  something_database(*(_DWORD *)v1920, v1919, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6901);
  v1921 = (int)std_string_append(&v5661, (int)&Dst, "wood-crossbow4-random8.cub");
  v7813 = 904;
  v1922 = this_4pointer_off((void *)v6, 772);
  something_database(*(_DWORD *)v1922, v1921, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5661);
  v1923 = (int)std_string_append(&v6899, (int)&Dst, "wood-crossbow5-random8.cub");
  v7813 = 905;
  v1924 = this_4pointer_off((void *)v6, 773);
  something_database(*(_DWORD *)v1924, v1923, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6899);
  v1925 = (int)std_string_append(&v6073, (int)&Dst, "wood-crossbow1-random9.cub");
  v7813 = 906;
  v1926 = this_4pointer_off((void *)v6, 774);
  something_database(*(_DWORD *)v1926, v1925, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6073);
  v1927 = (int)std_string_append(&v6897, (int)&Dst, "wood-crossbow2-random9.cub");
  v7813 = 907;
  v1928 = this_4pointer_off((void *)v6, 775);
  something_database(*(_DWORD *)v1928, v1927, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6897);
  v1929 = (int)std_string_append(&v5351, (int)&Dst, "wood-crossbow3-random9.cub");
  v7813 = 908;
  v1930 = this_4pointer_off((void *)v6, 776);
  something_database(*(_DWORD *)v1930, v1929, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5351);
  v1931 = (int)std_string_append(&v6895, (int)&Dst, "wood-crossbow4-random9.cub");
  v7813 = 909;
  v1932 = this_4pointer_off((void *)v6, 777);
  something_database(*(_DWORD *)v1932, v1931, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6895);
  v1933 = (int)std_string_append(&v6071, (int)&Dst, "wood-crossbow5-random9.cub");
  v7813 = 910;
  v1934 = this_4pointer_off((void *)v6, 778);
  something_database(*(_DWORD *)v1934, v1933, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6071);
  v1935 = (int)std_string_append(&v6893, (int)&Dst, "wood-crossbow1-random10.cub");
  v7813 = 911;
  v1936 = this_4pointer_off((void *)v6, 779);
  something_database(*(_DWORD *)v1936, v1935, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6893);
  v1937 = (int)std_string_append(&v5659, (int)&Dst, "wood-crossbow2-random10.cub");
  v7813 = 912;
  v1938 = this_4pointer_off((void *)v6, 780);
  something_database(*(_DWORD *)v1938, v1937, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5659);
  v1939 = (int)std_string_append(&v6891, (int)&Dst, "wood-crossbow3-random10.cub");
  v7813 = 913;
  v1940 = this_4pointer_off((void *)v6, 781);
  something_database(*(_DWORD *)v1940, v1939, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6891);
  v1941 = (int)std_string_append(&v6069, (int)&Dst, "wood-crossbow4-random10.cub");
  v7813 = 914;
  v1942 = this_4pointer_off((void *)v6, 782);
  something_database(*(_DWORD *)v1942, v1941, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6069);
  v1943 = (int)std_string_append(&v6889, (int)&Dst, "wood-crossbow5-random10.cub");
  v7813 = 915;
  v1944 = this_4pointer_off((void *)v6, 783);
  something_database(*(_DWORD *)v1944, v1943, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6889);
  v1945 = (int)std_string_append(&v5453, (int)&Dst, "wood-boomerang1.cub");
  v7813 = 916;
  v1946 = this_4pointer_off((void *)v6, 784);
  something_database(*(_DWORD *)v1946, v1945, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5453);
  v1947 = (int)std_string_append(&v6887, (int)&Dst, "wood-boomerang2.cub");
  v7813 = 917;
  v1948 = this_4pointer_off((void *)v6, 785);
  something_database(*(_DWORD *)v1948, v1947, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6887);
  v1949 = (int)std_string_append(&v6067, (int)&Dst, "wood-boomerang3.cub");
  v7813 = 918;
  v1950 = this_4pointer_off((void *)v6, 786);
  something_database(*(_DWORD *)v1950, v1949, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6067);
  v1951 = (int)std_string_append(&v6885, (int)&Dst, "wood-boomerang4.cub");
  v7813 = 919;
  v1952 = this_4pointer_off((void *)v6, 787);
  something_database(*(_DWORD *)v1952, v1951, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6885);
  v1953 = (int)std_string_append(&v5657, (int)&Dst, "wood-boomerang5.cub");
  v7813 = 920;
  v1954 = this_4pointer_off((void *)v6, 788);
  something_database(*(_DWORD *)v1954, v1953, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5657);
  v1955 = (int)std_string_append(&v6883, (int)&Dst, "wood-boomerang1-random1.cub");
  v7813 = 921;
  v1956 = this_4pointer_off((void *)v6, 789);
  something_database(*(_DWORD *)v1956, v1955, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6883);
  v1957 = (int)std_string_append(&v6065, (int)&Dst, "wood-boomerang2-random1.cub");
  v7813 = 922;
  v1958 = this_4pointer_off((void *)v6, 790);
  something_database(*(_DWORD *)v1958, v1957, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6065);
  v1959 = (int)std_string_append(&v6881, (int)&Dst, "wood-boomerang3-random1.cub");
  v7813 = 923;
  v1960 = this_4pointer_off((void *)v6, 791);
  something_database(*(_DWORD *)v1960, v1959, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6881);
  v1961 = (int)std_string_append(&v5299, (int)&Dst, "wood-boomerang4-random1.cub");
  v7813 = 924;
  v1962 = this_4pointer_off((void *)v6, 792);
  something_database(*(_DWORD *)v1962, v1961, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5299);
  v1963 = (int)std_string_append(&v6879, (int)&Dst, "wood-boomerang5-random1.cub");
  v7813 = 925;
  v1964 = this_4pointer_off((void *)v6, 793);
  something_database(*(_DWORD *)v1964, v1963, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6879);
  v1965 = (int)std_string_append(&v6063, (int)&Dst, "wood-boomerang1-random2.cub");
  v7813 = 926;
  v1966 = this_4pointer_off((void *)v6, 794);
  something_database(*(_DWORD *)v1966, v1965, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6063);
  v1967 = (int)std_string_append(&v6877, (int)&Dst, "wood-boomerang2-random2.cub");
  v7813 = 927;
  v1968 = this_4pointer_off((void *)v6, 795);
  something_database(*(_DWORD *)v1968, v1967, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6877);
  v1969 = (int)std_string_append(&v5655, (int)&Dst, "wood-boomerang3-random2.cub");
  v7813 = 928;
  v1970 = this_4pointer_off((void *)v6, 796);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v1969;
  something_database(*(_DWORD *)v1970, v1969, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5655);
  v1971 = (int)std_string_append(&v6875, (int)&Dst, "wood-boomerang4-random2.cub");
  v7813 = 929;
  v1972 = this_4pointer_off((void *)v6, 797);
  something_database(*(_DWORD *)v1972, v1971, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6875);
  v1973 = (int)std_string_append(&v6061, (int)&Dst, "wood-boomerang5-random2.cub");
  v7813 = 930;
  v1974 = this_4pointer_off((void *)v6, 798);
  something_database(*(_DWORD *)v1974, v1973, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6061);
  v1975 = (int)std_string_append(&v6873, (int)&Dst, "wood-boomerang1-random3.cub");
  v7813 = 931;
  v1976 = this_4pointer_off((void *)v6, 799);
  something_database(*(_DWORD *)v1976, v1975, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6873);
  v1977 = (int)std_string_append(&v5451, (int)&Dst, "wood-boomerang2-random3.cub");
  v7813 = 932;
  v1978 = this_4pointer_off((void *)v6, 800);
  something_database(*(_DWORD *)v1978, v1977, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5451);
  v1979 = (int)std_string_append(&v6871, (int)&Dst, "wood-boomerang3-random3.cub");
  v7813 = 933;
  v1980 = this_4pointer_off((void *)v6, 801);
  something_database(*(_DWORD *)v1980, v1979, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6871);
  v1981 = (int)std_string_append(&v6059, (int)&Dst, "wood-boomerang4-random3.cub");
  v7813 = 934;
  v1982 = this_4pointer_off((void *)v6, 802);
  something_database(*(_DWORD *)v1982, v1981, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6059);
  v1983 = (int)std_string_append(&v6869, (int)&Dst, "wood-boomerang5-random3.cub");
  v7813 = 935;
  v1984 = this_4pointer_off((void *)v6, 803);
  something_database(*(_DWORD *)v1984, v1983, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6869);
  v1985 = (int)std_string_append(&v5653, (int)&Dst, "wood-boomerang1-random4.cub");
  v7813 = 936;
  v1986 = this_4pointer_off((void *)v6, 804);
  something_database(*(_DWORD *)v1986, v1985, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5653);
  v1987 = (int)std_string_append(&v6867, (int)&Dst, "wood-boomerang2-random4.cub");
  v7813 = 937;
  v1988 = this_4pointer_off((void *)v6, 805);
  something_database(*(_DWORD *)v1988, v1987, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6867);
  v1989 = (int)std_string_append(&v6057, (int)&Dst, "wood-boomerang3-random4.cub");
  v7813 = 938;
  v1990 = this_4pointer_off((void *)v6, 806);
  something_database(*(_DWORD *)v1990, v1989, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6057);
  v1991 = (int)std_string_append(&v6865, (int)&Dst, "wood-boomerang4-random4.cub");
  v7813 = 939;
  v1992 = this_4pointer_off((void *)v6, 807);
  something_database(*(_DWORD *)v1992, v1991, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6865);
  v1993 = (int)std_string_append(&v5349, (int)&Dst, "wood-boomerang5-random4.cub");
  v7813 = 940;
  v1994 = this_4pointer_off((void *)v6, 808);
  something_database(*(_DWORD *)v1994, v1993, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5349);
  v1995 = (int)std_string_append(&v6863, (int)&Dst, "wood-boomerang1-random5.cub");
  v7813 = 941;
  v1996 = this_4pointer_off((void *)v6, 809);
  something_database(*(_DWORD *)v1996, v1995, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6863);
  v1997 = (int)std_string_append(&v6055, (int)&Dst, "wood-boomerang2-random5.cub");
  v7813 = 942;
  v1998 = this_4pointer_off((void *)v6, 810);
  something_database(*(_DWORD *)v1998, v1997, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6055);
  v1999 = (int)std_string_append(&v6861, (int)&Dst, "wood-boomerang3-random5.cub");
  v7813 = 943;
  v2000 = this_4pointer_off((void *)v6, 811);
  something_database(*(_DWORD *)v2000, v1999, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6861);
  v2001 = (int)std_string_append(&v5651, (int)&Dst, "wood-boomerang4-random5.cub");
  v7813 = 944;
  v2002 = this_4pointer_off((void *)v6, 812);
  something_database(*(_DWORD *)v2002, v2001, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5651);
  v2003 = (int)std_string_append(&v6859, (int)&Dst, "wood-boomerang5-random5.cub");
  v7813 = 945;
  v2004 = this_4pointer_off((void *)v6, 813);
  something_database(*(_DWORD *)v2004, v2003, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6859);
  v2005 = (int)std_string_append(&v6053, (int)&Dst, "wood-boomerang1-random6.cub");
  v7813 = 946;
  v2006 = this_4pointer_off((void *)v6, 814);
  something_database(*(_DWORD *)v2006, v2005, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6053);
  v2007 = (int)std_string_append(&v6857, (int)&Dst, "wood-boomerang2-random6.cub");
  v7813 = 947;
  v2008 = this_4pointer_off((void *)v6, 815);
  something_database(*(_DWORD *)v2008, v2007, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6857);
  v2009 = (int)std_string_append(&v5449, (int)&Dst, "wood-boomerang3-random6.cub");
  v7813 = 948;
  v2010 = this_4pointer_off((void *)v6, 816);
  something_database(*(_DWORD *)v2010, v2009, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5449);
  v2011 = (int)std_string_append(&v6855, (int)&Dst, "wood-boomerang4-random6.cub");
  v7813 = 949;
  v2012 = this_4pointer_off((void *)v6, 817);
  something_database(*(_DWORD *)v2012, v2011, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6855);
  v2013 = (int)std_string_append(&v6051, (int)&Dst, "wood-boomerang5-random6.cub");
  v7813 = 950;
  v2014 = this_4pointer_off((void *)v6, 818);
  something_database(*(_DWORD *)v2014, v2013, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6051);
  v2015 = (int)std_string_append(&v6853, (int)&Dst, "wood-boomerang1-random7.cub");
  v7813 = 951;
  v2016 = this_4pointer_off((void *)v6, 819);
  something_database(*(_DWORD *)v2016, v2015, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6853);
  v2017 = (int)std_string_append(&v5649, (int)&Dst, "wood-boomerang2-random7.cub");
  v7813 = 952;
  v2018 = this_4pointer_off((void *)v6, 820);
  something_database(*(_DWORD *)v2018, v2017, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5649);
  v2019 = (int)std_string_append(&v6851, (int)&Dst, "wood-boomerang3-random7.cub");
  v7813 = 953;
  v2020 = this_4pointer_off((void *)v6, 821);
  something_database(*(_DWORD *)v2020, v2019, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6851);
  v2021 = (int)std_string_append(&v6049, (int)&Dst, "wood-boomerang4-random7.cub");
  v7813 = 954;
  v2022 = this_4pointer_off((void *)v6, 822);
  something_database(*(_DWORD *)v2022, v2021, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6049);
  v2023 = (int)std_string_append(&v6849, (int)&Dst, "wood-boomerang5-random7.cub");
  v7813 = 955;
  v2024 = this_4pointer_off((void *)v6, 823);
  v7809 = 0;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2023;
  something_database(*(_DWORD *)v2024, v2023, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6849);
  v2025 = (int)std_string_append(&v5273, (int)&Dst, "wood-boomerang1-random8.cub");
  v7813 = 956;
  v2026 = this_4pointer_off((void *)v6, 824);
  something_database(*(_DWORD *)v2026, v2025, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5273);
  v2027 = (int)std_string_append(&v6847, (int)&Dst, "wood-boomerang2-random8.cub");
  v7813 = 957;
  v2028 = this_4pointer_off((void *)v6, 825);
  something_database(*(_DWORD *)v2028, v2027, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6847);
  v2029 = (int)std_string_append(&v6047, (int)&Dst, "wood-boomerang3-random8.cub");
  v7813 = 958;
  v2030 = this_4pointer_off((void *)v6, 826);
  something_database(*(_DWORD *)v2030, v2029, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6047);
  v2031 = (int)std_string_append(&v6845, (int)&Dst, "wood-boomerang4-random8.cub");
  v7813 = 959;
  v2032 = this_4pointer_off((void *)v6, 827);
  something_database(*(_DWORD *)v2032, v2031, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6845);
  v2033 = (int)std_string_append(&v5647, (int)&Dst, "wood-boomerang5-random8.cub");
  v7813 = 960;
  v2034 = this_4pointer_off((void *)v6, 828);
  something_database(*(_DWORD *)v2034, v2033, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5647);
  v2035 = (int)std_string_append(&v6843, (int)&Dst, "wood-boomerang1-random9.cub");
  v7813 = 961;
  v2036 = this_4pointer_off((void *)v6, 829);
  something_database(*(_DWORD *)v2036, v2035, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6843);
  v2037 = (int)std_string_append(&v6045, (int)&Dst, "wood-boomerang2-random9.cub");
  v7813 = 962;
  v2038 = this_4pointer_off((void *)v6, 830);
  something_database(*(_DWORD *)v2038, v2037, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6045);
  v2039 = (int)std_string_append(&v6841, (int)&Dst, "wood-boomerang3-random9.cub");
  v7813 = 963;
  v2040 = this_4pointer_off((void *)v6, 831);
  something_database(*(_DWORD *)v2040, v2039, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6841);
  v2041 = (int)std_string_append(&v5447, (int)&Dst, "wood-boomerang4-random9.cub");
  v7813 = 964;
  v2042 = this_4pointer_off((void *)v6, 832);
  something_database(*(_DWORD *)v2042, v2041, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5447);
  v2043 = (int)std_string_append(&v6839, (int)&Dst, "wood-boomerang5-random9.cub");
  v7813 = 965;
  v2044 = this_4pointer_off((void *)v6, 833);
  something_database(*(_DWORD *)v2044, v2043, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6839);
  v2045 = (int)std_string_append(&v6043, (int)&Dst, "wood-boomerang1-random10.cub");
  v7813 = 966;
  v2046 = this_4pointer_off((void *)v6, 834);
  something_database(*(_DWORD *)v2046, v2045, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6043);
  v2047 = (int)std_string_append(&v6837, (int)&Dst, "wood-boomerang2-random10.cub");
  v7813 = 967;
  v2048 = this_4pointer_off((void *)v6, 835);
  something_database(*(_DWORD *)v2048, v2047, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6837);
  v2049 = (int)std_string_append(&v5645, (int)&Dst, "wood-boomerang3-random10.cub");
  v7813 = 968;
  v2050 = this_4pointer_off((void *)v6, 836);
  something_database(*(_DWORD *)v2050, v2049, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5645);
  v2051 = (int)std_string_append(&v6835, (int)&Dst, "wood-boomerang4-random10.cub");
  v7813 = 969;
  v2052 = this_4pointer_off((void *)v6, 837);
  something_database(*(_DWORD *)v2052, v2051, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6835);
  v2053 = (int)std_string_append(&v6041, (int)&Dst, "wood-boomerang5-random10.cub");
  v7813 = 970;
  v2054 = this_4pointer_off((void *)v6, 838);
  something_database(*(_DWORD *)v2054, v2053, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6041);
  v2055 = (int)std_string_append(&v6833, (int)&Dst, "arrow.cub");
  v7813 = 971;
  v2056 = this_4pointer_off((void *)v6, 840);
  something_database(*(_DWORD *)v2056, v2055, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6833);
  v2057 = (int)std_string_append(&v5347, (int)&Dst, "fireball.cub");
  v7813 = 972;
  v2058 = this_4pointer_off((void *)v6, 841);
  something_database(*(_DWORD *)v2058, v2057, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5347);
  v2059 = (int)std_string_append(&v6831, (int)&Dst, "quiver.cub");
  v7813 = 973;
  v2060 = this_4pointer_off((void *)v6, 839);
  something_database(*(_DWORD *)v2060, v2059, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6831);
  v2061 = (int)std_string_append(&v6039, (int)&Dst, "torch.cub");
  v7813 = 974;
  v2062 = this_4pointer_off((void *)v6, 842);
  something_database(*(_DWORD *)v2062, v2061, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6039);
  v2063 = (int)std_string_append(&v6829, (int)&Dst, "cube.cub");
  v7813 = 975;
  v2064 = this_4pointer_off((void *)v6, 2075);
  something_database(*(_DWORD *)v2064, v2063, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6829);
  v2065 = (int)std_string_append(&v5643, (int)&Dst, "stars.cub");
  v7813 = 976;
  v2066 = this_4pointer_off((void *)v6, 2549);
  something_database(*(_DWORD *)v2066, v2065, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5643);
  v2067 = (int)std_string_append(&v6827, (int)&Dst, "plaster.cub");
  v7813 = 977;
  v2068 = this_4pointer_off((void *)v6, 2550);
  something_database(*(_DWORD *)v2068, v2067, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6827);
  v2069 = (int)std_string_append(&v6037, (int)&Dst, "zzz.cub");
  v7813 = 978;
  v2070 = this_4pointer_off((void *)v6, 2551);
  something_database(*(_DWORD *)v2070, v2069, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6037);
  v2071 = (int)std_string_append(&v6825, (int)&Dst, "heart.cub");
  v7813 = 979;
  v2072 = this_4pointer_off((void *)v6, 2552);
  something_database(*(_DWORD *)v2072, v2071, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6825);
  v2073 = (int)std_string_append(&v5445, (int)&Dst, "angry.cub");
  v7813 = 980;
  v2074 = this_4pointer_off((void *)v6, 2553);
  something_database(*(_DWORD *)v2074, v2073, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5445);
  v2075 = (int)std_string_append(&v6823, (int)&Dst, "door.cub");
  v7813 = 981;
  v2076 = this_4pointer_off((void *)v6, 2076);
  something_database(*(_DWORD *)v2076, v2075, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6823);
  v2077 = (int)std_string_append(&v6035, (int)&Dst, "window.cub");
  v7813 = 982;
  v2078 = this_4pointer_off((void *)v6, 2077);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2077;
  something_database(*(_DWORD *)v2078, v2077, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6035);
  v2079 = (int)std_string_append(&v6821, (int)&Dst, "goddess2.cub");
  v7813 = 983;
  v2080 = this_4pointer_off((void *)v6, 2078);
  something_database(*(_DWORD *)v2080, v2079, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6821);
  v2081 = (int)std_string_append(&v5641, (int)&Dst, "artifact.cub");
  v7813 = 984;
  v2082 = this_4pointer_off((void *)v6, 2079);
  something_database(*(_DWORD *)v2082, v2081, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5641);
  v2083 = (int)std_string_append(&v6819, (int)&Dst, "quest-item-amulet01.cub");
  v7813 = 985;
  v2084 = this_4pointer_off((void *)v6, 2081);
  something_database(*(_DWORD *)v2084, v2083, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6819);
  v2085 = (int)std_string_append(&v6033, (int)&Dst, "quest-item-amulet02.cub");
  v7813 = 986;
  v2086 = this_4pointer_off((void *)v6, 2082);
  something_database(*(_DWORD *)v2086, v2085, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6033);
  v2087 = (int)std_string_append(&v6817, (int)&Dst, "quest-item-jewel-case.cub");
  v7813 = 987;
  v2088 = this_4pointer_off((void *)v6, 2083);
  something_database(*(_DWORD *)v2088, v2087, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6817);
  v2089 = (int)std_string_append(&v5297, (int)&Dst, "mushroom.cub");
  v7813 = 988;
  v2090 = this_4pointer_off((void *)v6, 843);
  something_database(*(_DWORD *)v2090, v2089, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5297);
  v2091 = (int)std_string_append(&v6815, (int)&Dst, "shimmer-mushroom.cub");
  v7813 = 989;
  v2092 = this_4pointer_off((void *)v6, 844);
  something_database(*(_DWORD *)v2092, v2091, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6815);
  v2093 = (int)std_string_append(&v6031, (int)&Dst, "heartflower.cub");
  v7813 = 990;
  v2094 = this_4pointer_off((void *)v6, 845);
  something_database(*(_DWORD *)v2094, v2093, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6031);
  v2095 = (int)std_string_append(&v6813, (int)&Dst, "heartflower-frozen.cub");
  v7813 = 991;
  v2096 = this_4pointer_off((void *)v6, 846);
  something_database(*(_DWORD *)v2096, v2095, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6813);
  v2097 = (int)std_string_append(&v5639, (int)&Dst, "prickly-pear.cub");
  v7813 = 992;
  v2098 = this_4pointer_off((void *)v6, 847);
  something_database(*(_DWORD *)v2098, v2097, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5639);
  v2099 = (int)std_string_append(&v6811, (int)&Dst, "soulflower.cub");
  v7813 = 993;
  v2100 = this_4pointer_off((void *)v6, 848);
  something_database(*(_DWORD *)v2100, v2099, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6811);
  v2101 = (int)std_string_append(&v6029, (int)&Dst, "life-potion.cub");
  v7813 = 994;
  v2102 = this_4pointer_off((void *)v6, 849);
  something_database(*(_DWORD *)v2102, v2101, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6029);
  v2103 = (int)std_string_append(&v6809, (int)&Dst, "cactus-potion.cub");
  v7813 = 995;
  v2104 = this_4pointer_off((void *)v6, 850);
  something_database(*(_DWORD *)v2104, v2103, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6809);
  v2105 = (int)std_string_append(&v5443, (int)&Dst, "mana-potion.cub");
  v7813 = 996;
  v2106 = this_4pointer_off((void *)v6, 851);
  something_database(*(_DWORD *)v2106, v2105, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5443);
  v2107 = (int)std_string_append(&v6807, (int)&Dst, "cookie.cub");
  v7813 = 997;
  v2108 = this_4pointer_off((void *)v6, 852);
  something_database(*(_DWORD *)v2108, v2107, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6807);
  v2109 = (int)std_string_append(&v6027, (int)&Dst, "jelly-green.cub");
  v7813 = 998;
  v2110 = this_4pointer_off((void *)v6, 853);
  something_database(*(_DWORD *)v2110, v2109, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6027);
  v2111 = (int)std_string_append(&v6805, (int)&Dst, "jelly-blue.cub");
  v7813 = 999;
  v2112 = this_4pointer_off((void *)v6, 855);
  something_database(*(_DWORD *)v2112, v2111, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6805);
  v2113 = (int)std_string_append(&v5637, (int)&Dst, "jelly-pink.cub");
  v7813 = 1000;
  v2114 = this_4pointer_off((void *)v6, 854);
  something_database(*(_DWORD *)v2114, v2113, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5637);
  v2115 = (int)std_string_append(&v6803, (int)&Dst, "jelly-yellow.cub");
  v7813 = 1001;
  v2116 = this_4pointer_off((void *)v6, 856);
  something_database(*(_DWORD *)v2116, v2115, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6803);
  v2117 = (int)std_string_append(&v6025, (int)&Dst, "carrot.cub");
  v7813 = 1002;
  v2118 = this_4pointer_off((void *)v6, 857);
  something_database(*(_DWORD *)v2118, v2117, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6025);
  v2119 = (int)std_string_append(&v6801, (int)&Dst, "pumpkin-mash.cub");
  v7813 = 1003;
  v2120 = this_4pointer_off((void *)v6, 858);
  something_database(*(_DWORD *)v2120, v2119, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6801);
  v2121 = (int)std_string_append(&v5345, (int)&Dst, "candy.cub");
  v7813 = 1004;
  v2122 = this_4pointer_off((void *)v6, 859);
  something_database(*(_DWORD *)v2122, v2121, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5345);
  v2123 = (int)std_string_append(&v6799, (int)&Dst, "lollipop.cub");
  v7813 = 1005;
  v2124 = this_4pointer_off((void *)v6, 860);
  something_database(*(_DWORD *)v2124, v2123, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6799);
  v2125 = (int)std_string_append(&v6023, (int)&Dst, "softice.cub");
  v7813 = 1006;
  v2126 = this_4pointer_off((void *)v6, 861);
  something_database(*(_DWORD *)v2126, v2125, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6023);
  v2127 = (int)std_string_append(&v6797, (int)&Dst, "donut-chocolate.cub");
  v7813 = 1007;
  v2128 = this_4pointer_off((void *)v6, 862);
  something_database(*(_DWORD *)v2128, v2127, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6797);
  v2129 = (int)std_string_append(&v5635, (int)&Dst, "cotton-candy.cub");
  v7813 = 1008;
  v2130 = this_4pointer_off((void *)v6, 863);
  something_database(*(_DWORD *)v2130, v2129, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5635);
  v2131 = (int)std_string_append(&v6795, (int)&Dst, "popcorn.cub");
  v7813 = 1009;
  v2132 = this_4pointer_off((void *)v6, 864);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2131;
  something_database(*(_DWORD *)v2132, v2131, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6795);
  v2133 = (int)std_string_append(&v6021, (int)&Dst, "cereal-bar.cub");
  v7813 = 1010;
  v2134 = this_4pointer_off((void *)v6, 865);
  something_database(*(_DWORD *)v2134, v2133, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6021);
  v2135 = (int)std_string_append(&v6793, (int)&Dst, "strawberry-cake.cub");
  v7813 = 1011;
  v2136 = this_4pointer_off((void *)v6, 866);
  something_database(*(_DWORD *)v2136, v2135, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6793);
  v2137 = (int)std_string_append(&v5441, (int)&Dst, "chocolate-cake.cub");
  v7813 = 1012;
  v2138 = this_4pointer_off((void *)v6, 867);
  something_database(*(_DWORD *)v2138, v2137, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5441);
  v2139 = (int)std_string_append(&v6791, (int)&Dst, "vanilla-cupcake.cub");
  v7813 = 1013;
  v2140 = this_4pointer_off((void *)v6, 868);
  something_database(*(_DWORD *)v2140, v2139, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6791);
  v2141 = (int)std_string_append(&v6019, (int)&Dst, "chocolate-cupcake.cub");
  v7813 = 1014;
  v2142 = this_4pointer_off((void *)v6, 869);
  something_database(*(_DWORD *)v2142, v2141, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6019);
  v2143 = (int)std_string_append(&v6789, (int)&Dst, "banana-split.cub");
  v7813 = 1015;
  v2144 = this_4pointer_off((void *)v6, 870);
  something_database(*(_DWORD *)v2144, v2143, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6789);
  v2145 = (int)std_string_append(&v5633, (int)&Dst, "croissant.cub");
  v7813 = 1016;
  v2146 = this_4pointer_off((void *)v6, 871);
  something_database(*(_DWORD *)v2146, v2145, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5633);
  v2147 = (int)std_string_append(&v6787, (int)&Dst, "lolly.cub");
  v7813 = 1017;
  v2148 = this_4pointer_off((void *)v6, 872);
  something_database(*(_DWORD *)v2148, v2147, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6787);
  v2149 = (int)std_string_append(&v6017, (int)&Dst, "lemon-tart.cub");
  v7813 = 1018;
  v2150 = this_4pointer_off((void *)v6, 873);
  something_database(*(_DWORD *)v2150, v2149, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6017);
  v2151 = (int)std_string_append(&v6785, (int)&Dst, "chocolate-cookie.cub");
  v7813 = 1019;
  v2152 = this_4pointer_off((void *)v6, 874);
  something_database(*(_DWORD *)v2152, v2151, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6785);
  v2153 = (int)std_string_append(&v5251, (int)&Dst, "bubble-gum.cub");
  v7813 = 1020;
  v2154 = this_4pointer_off((void *)v6, 875);
  something_database(*(_DWORD *)v2154, v2153, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5251);
  v2155 = (int)std_string_append(&v6783, (int)&Dst, "licorice-candy.cub");
  v7813 = 1021;
  v2156 = this_4pointer_off((void *)v6, 876);
  something_database(*(_DWORD *)v2156, v2155, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6783);
  v2157 = (int)std_string_append(&v6015, (int)&Dst, "cinnamon-role.cub");
  v7813 = 1022;
  v2158 = this_4pointer_off((void *)v6, 877);
  something_database(*(_DWORD *)v2158, v2157, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6015);
  v2159 = (int)std_string_append(&v6781, (int)&Dst, "apple-ring.cub");
  v7813 = 1023;
  v2160 = this_4pointer_off((void *)v6, 878);
  something_database(*(_DWORD *)v2160, v2159, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6781);
  v2161 = (int)std_string_append(&v5631, (int)&Dst, "waffle.cub");
  v7813 = 1024;
  v2162 = this_4pointer_off((void *)v6, 879);
  something_database(*(_DWORD *)v2162, v2161, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5631);
  v2163 = (int)std_string_append(&v6779, (int)&Dst, "water-ice.cub");
  v7813 = 1025;
  v2164 = this_4pointer_off((void *)v6, 880);
  something_database(*(_DWORD *)v2164, v2163, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6779);
  v2165 = (int)std_string_append(&v6013, (int)&Dst, "date-cookie.cub");
  v7813 = 1026;
  v2166 = this_4pointer_off((void *)v6, 881);
  something_database(*(_DWORD *)v2166, v2165, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6013);
  v2167 = (int)std_string_append(&v6777, (int)&Dst, "candied-apple.cub");
  v7813 = 1027;
  v2168 = this_4pointer_off((void *)v6, 882);
  something_database(*(_DWORD *)v2168, v2167, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6777);
  v2169 = (int)std_string_append(&v5439, (int)&Dst, "strawberry-cocktail.cub");
  v7813 = 1028;
  v2170 = this_4pointer_off((void *)v6, 883);
  something_database(*(_DWORD *)v2170, v2169, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5439);
  v2171 = (int)std_string_append(&v6775, (int)&Dst, "milk-chocolate-bar.cub");
  v7813 = 1029;
  v2172 = this_4pointer_off((void *)v6, 884);
  something_database(*(_DWORD *)v2172, v2171, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6775);
  v2173 = (int)std_string_append(&v6011, (int)&Dst, "caramel-chocolate-bar.cub");
  v7813 = 1030;
  v2174 = this_4pointer_off((void *)v6, 885);
  something_database(*(_DWORD *)v2174, v2173, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6011);
  v2175 = (int)std_string_append(&v6773, (int)&Dst, "mint-chocolate-bar.cub");
  v7813 = 1031;
  v2176 = this_4pointer_off((void *)v6, 886);
  something_database(*(_DWORD *)v2176, v2175, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6773);
  v2177 = (int)std_string_append(&v5629, (int)&Dst, "white-chocolate-bar.cub");
  v7813 = 1032;
  v2178 = this_4pointer_off((void *)v6, 887);
  something_database(*(_DWORD *)v2178, v2177, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5629);
  v2179 = (int)std_string_append(&v6771, (int)&Dst, "sugar-candy.cub");
  v7813 = 1033;
  v2180 = this_4pointer_off((void *)v6, 888);
  something_database(*(_DWORD *)v2180, v2179, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6771);
  v2181 = (int)std_string_append(&v6009, (int)&Dst, "blackberry-marmelade.cub");
  v7813 = 1034;
  v2182 = this_4pointer_off((void *)v6, 889);
  something_database(*(_DWORD *)v2182, v2181, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6009);
  v2183 = (int)std_string_append(&v6769, (int)&Dst, "salted-caramel.cub");
  v7813 = 1035;
  v2184 = this_4pointer_off((void *)v6, 890);
  something_database(*(_DWORD *)v2184, v2183, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6769);
  v2185 = (int)std_string_append(&v5343, (int)&Dst, "ginger-tartlet.cub");
  v7813 = 1036;
  v2186 = this_4pointer_off((void *)v6, 891);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2185;
  something_database(*(_DWORD *)v2186, v2185, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5343);
  v2187 = (int)std_string_append(&v6767, (int)&Dst, "mango-juice.cub");
  v7813 = 1037;
  v2188 = this_4pointer_off((void *)v6, 892);
  something_database(*(_DWORD *)v2188, v2187, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6767);
  v2189 = (int)std_string_append(&v6007, (int)&Dst, "fruit-basket.cub");
  v7813 = 1038;
  v2190 = this_4pointer_off((void *)v6, 893);
  something_database(*(_DWORD *)v2190, v2189, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6007);
  v2191 = (int)std_string_append(&v6765, (int)&Dst, "melon-icecream.cub");
  v7813 = 1039;
  v2192 = this_4pointer_off((void *)v6, 894);
  something_database(*(_DWORD *)v2192, v2191, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6765);
  v2193 = (int)std_string_append(&v5627, (int)&Dst, "bloodorange-juice.cub");
  v7813 = 1040;
  v2194 = this_4pointer_off((void *)v6, 895);
  something_database(*(_DWORD *)v2194, v2193, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5627);
  v2195 = (int)std_string_append(&v6763, (int)&Dst, "pancakes.cub");
  v7813 = 1041;
  v2196 = this_4pointer_off((void *)v6, 896);
  something_database(*(_DWORD *)v2196, v2195, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6763);
  v2197 = (int)std_string_append(&v6005, (int)&Dst, "curry.cub");
  v7813 = 1042;
  v2198 = this_4pointer_off((void *)v6, 897);
  something_database(*(_DWORD *)v2198, v2197, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6005);
  v2199 = (int)std_string_append(&v6761, (int)&Dst, "biscuit-role.cub");
  v7813 = 1043;
  v2200 = this_4pointer_off((void *)v6, 898);
  something_database(*(_DWORD *)v2200, v2199, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6761);
  v2201 = (int)std_string_append(&v5437, (int)&Dst, "iron-sword1.cub");
  v7813 = 1044;
  v2202 = this_4pointer_off((void *)v6, 899);
  something_database(*(_DWORD *)v2202, v2201, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5437);
  v2203 = (int)std_string_append(&v6759, (int)&Dst, "iron-sword2.cub");
  v7813 = 1045;
  v2204 = this_4pointer_off((void *)v6, 900);
  something_database(*(_DWORD *)v2204, v2203, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6759);
  v2205 = (int)std_string_append(&v6003, (int)&Dst, "iron-sword3.cub");
  v7813 = 1046;
  v2206 = this_4pointer_off((void *)v6, 901);
  something_database(*(_DWORD *)v2206, v2205, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6003);
  v2207 = (int)std_string_append(&v6757, (int)&Dst, "iron-sword4.cub");
  v7813 = 1047;
  v2208 = this_4pointer_off((void *)v6, 902);
  something_database(*(_DWORD *)v2208, v2207, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6757);
  v2209 = (int)std_string_append(&v5625, (int)&Dst, "iron-sword5.cub");
  v7813 = 1048;
  v2210 = this_4pointer_off((void *)v6, 903);
  something_database(*(_DWORD *)v2210, v2209, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5625);
  v2211 = (int)std_string_append(&v6755, (int)&Dst, "iron-sword1-random1.cub");
  v7813 = 1049;
  v2212 = this_4pointer_off((void *)v6, 904);
  something_database(*(_DWORD *)v2212, v2211, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6755);
  v2213 = (int)std_string_append(&v6001, (int)&Dst, "iron-sword2-random1.cub");
  v7813 = 1050;
  v2214 = this_4pointer_off((void *)v6, 905);
  something_database(*(_DWORD *)v2214, v2213, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6001);
  v2215 = (int)std_string_append(&v6753, (int)&Dst, "iron-sword3-random1.cub");
  v7813 = 1051;
  v2216 = this_4pointer_off((void *)v6, 906);
  something_database(*(_DWORD *)v2216, v2215, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6753);
  v2217 = (int)std_string_append(&v5295, (int)&Dst, "iron-sword4-random1.cub");
  v7813 = 1052;
  v2218 = this_4pointer_off((void *)v6, 907);
  something_database(*(_DWORD *)v2218, v2217, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5295);
  v2219 = (int)std_string_append(&v6751, (int)&Dst, "iron-sword5-random1.cub");
  v7813 = 1053;
  v2220 = this_4pointer_off((void *)v6, 908);
  something_database(*(_DWORD *)v2220, v2219, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6751);
  v2221 = (int)std_string_append(&v5999, (int)&Dst, "iron-sword1-random2.cub");
  v7813 = 1054;
  v2222 = this_4pointer_off((void *)v6, 909);
  something_database(*(_DWORD *)v2222, v2221, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5999);
  v2223 = (int)std_string_append(&v6749, (int)&Dst, "iron-sword2-random2.cub");
  v7813 = 1055;
  v2224 = this_4pointer_off((void *)v6, 910);
  something_database(*(_DWORD *)v2224, v2223, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6749);
  v2225 = (int)std_string_append(&v5623, (int)&Dst, "iron-sword3-random2.cub");
  v7813 = 1056;
  v2226 = this_4pointer_off((void *)v6, 911);
  something_database(*(_DWORD *)v2226, v2225, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5623);
  v2227 = (int)std_string_append(&v6747, (int)&Dst, "iron-sword4-random2.cub");
  v7813 = 1057;
  v2228 = this_4pointer_off((void *)v6, 912);
  something_database(*(_DWORD *)v2228, v2227, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6747);
  v2229 = (int)std_string_append(&v5997, (int)&Dst, "iron-sword5-random2.cub");
  v7813 = 1058;
  v2230 = this_4pointer_off((void *)v6, 913);
  something_database(*(_DWORD *)v2230, v2229, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5997);
  v2231 = (int)std_string_append(&v6745, (int)&Dst, "iron-sword1-random3.cub");
  v7813 = 1059;
  v2232 = this_4pointer_off((void *)v6, 914);
  something_database(*(_DWORD *)v2232, v2231, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6745);
  v2233 = (int)std_string_append(&v5435, (int)&Dst, "iron-sword2-random3.cub");
  v7813 = 1060;
  v2234 = this_4pointer_off((void *)v6, 915);
  something_database(*(_DWORD *)v2234, v2233, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5435);
  v2235 = (int)std_string_append(&v6743, (int)&Dst, "iron-sword3-random3.cub");
  v7813 = 1061;
  v2236 = this_4pointer_off((void *)v6, 916);
  something_database(*(_DWORD *)v2236, v2235, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6743);
  v2237 = (int)std_string_append(&v5995, (int)&Dst, "iron-sword4-random3.cub");
  v7813 = 1062;
  v2238 = this_4pointer_off((void *)v6, 917);
  something_database(*(_DWORD *)v2238, v2237, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5995);
  v2239 = (int)std_string_append(&v6741, (int)&Dst, "iron-sword5-random3.cub");
  v7813 = 1063;
  v2240 = this_4pointer_off((void *)v6, 918);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2239;
  something_database(*(_DWORD *)v2240, v2239, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6741);
  v2241 = (int)std_string_append(&v5621, (int)&Dst, "iron-sword1-random4.cub");
  v7813 = 1064;
  v2242 = this_4pointer_off((void *)v6, 919);
  something_database(*(_DWORD *)v2242, v2241, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5621);
  v2243 = (int)std_string_append(&v6739, (int)&Dst, "iron-sword2-random4.cub");
  v7813 = 1065;
  v2244 = this_4pointer_off((void *)v6, 920);
  something_database(*(_DWORD *)v2244, v2243, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6739);
  v2245 = (int)std_string_append(&v5993, (int)&Dst, "iron-sword3-random4.cub");
  v7813 = 1066;
  v2246 = this_4pointer_off((void *)v6, 921);
  something_database(*(_DWORD *)v2246, v2245, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5993);
  v2247 = (int)std_string_append(&v6737, (int)&Dst, "iron-sword4-random4.cub");
  v7813 = 1067;
  v2248 = this_4pointer_off((void *)v6, 922);
  something_database(*(_DWORD *)v2248, v2247, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6737);
  v2249 = (int)std_string_append(&v5341, (int)&Dst, "iron-sword5-random4.cub");
  v7813 = 1068;
  v2250 = this_4pointer_off((void *)v6, 923);
  something_database(*(_DWORD *)v2250, v2249, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5341);
  v2251 = (int)std_string_append(&v6735, (int)&Dst, "iron-sword1-random5.cub");
  v7813 = 1069;
  v2252 = this_4pointer_off((void *)v6, 924);
  something_database(*(_DWORD *)v2252, v2251, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6735);
  v2253 = (int)std_string_append(&v5991, (int)&Dst, "iron-sword2-random5.cub");
  v7813 = 1070;
  v2254 = this_4pointer_off((void *)v6, 925);
  something_database(*(_DWORD *)v2254, v2253, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5991);
  v2255 = (int)std_string_append(&v6733, (int)&Dst, "iron-sword3-random5.cub");
  v7813 = 1071;
  v2256 = this_4pointer_off((void *)v6, 926);
  something_database(*(_DWORD *)v2256, v2255, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6733);
  v2257 = (int)std_string_append(&v5619, (int)&Dst, "iron-sword4-random5.cub");
  v7813 = 1072;
  v2258 = this_4pointer_off((void *)v6, 927);
  something_database(*(_DWORD *)v2258, v2257, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5619);
  v2259 = (int)std_string_append(&v6731, (int)&Dst, "iron-sword5-random5.cub");
  v7813 = 1073;
  v2260 = this_4pointer_off((void *)v6, 928);
  something_database(*(_DWORD *)v2260, v2259, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6731);
  v2261 = (int)std_string_append(&v5989, (int)&Dst, "iron-sword1-random6.cub");
  v7813 = 1074;
  v2262 = this_4pointer_off((void *)v6, 929);
  something_database(*(_DWORD *)v2262, v2261, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5989);
  v2263 = (int)std_string_append(&v6729, (int)&Dst, "iron-sword2-random6.cub");
  v7813 = 1075;
  v2264 = this_4pointer_off((void *)v6, 930);
  something_database(*(_DWORD *)v2264, v2263, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6729);
  v2265 = (int)std_string_append(&v5433, (int)&Dst, "iron-sword3-random6.cub");
  v7813 = 1076;
  v2266 = this_4pointer_off((void *)v6, 931);
  something_database(*(_DWORD *)v2266, v2265, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5433);
  v2267 = (int)std_string_append(&v6727, (int)&Dst, (const char *)"iron-sword4-random6.cub");
  v7813 = 1077;
  v2268 = this_4pointer_off((void *)v6, 932);
  something_database(*(_DWORD *)v2268, v2267, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6727);
  v2269 = (int)std_string_append(&v5987, (int)&Dst, "iron-sword5-random6.cub");
  v7813 = 1078;
  v2270 = this_4pointer_off((void *)v6, 933);
  something_database(*(_DWORD *)v2270, v2269, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5987);
  v2271 = (int)std_string_append(&v6725, (int)&Dst, "iron-sword1-random7.cub");
  v7813 = 1079;
  v2272 = this_4pointer_off((void *)v6, 934);
  something_database(*(_DWORD *)v2272, v2271, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6725);
  v2273 = (int)std_string_append(&v5617, (int)&Dst, "iron-sword2-random7.cub");
  v7813 = 1080;
  v2274 = this_4pointer_off((void *)v6, 935);
  something_database(*(_DWORD *)v2274, v2273, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5617);
  v2275 = (int)std_string_append(&v6723, (int)&Dst, "iron-sword3-random7.cub");
  v7813 = 1081;
  v2276 = this_4pointer_off((void *)v6, 936);
  something_database(*(_DWORD *)v2276, v2275, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6723);
  v2277 = (int)std_string_append(&v5985, (int)&Dst, "iron-sword4-random7.cub");
  v7813 = 1082;
  v2278 = this_4pointer_off((void *)v6, 937);
  something_database(*(_DWORD *)v2278, v2277, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5985);
  v2279 = (int)std_string_append(&v6721, (int)&Dst, "iron-sword5-random7.cub");
  v7813 = 1083;
  v2280 = this_4pointer_off((void *)v6, 938);
  something_database(*(_DWORD *)v2280, v2279, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6721);
  v2281 = (int)std_string_append(&v5271, (int)&Dst, "iron-sword1-random8.cub");
  v7813 = 1084;
  v2282 = this_4pointer_off((void *)v6, 939);
  something_database(*(_DWORD *)v2282, v2281, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5271);
  v2283 = (int)std_string_append(&v6719, (int)&Dst, "iron-sword2-random8.cub");
  v7813 = 1085;
  v2284 = this_4pointer_off((void *)v6, 940);
  something_database(*(_DWORD *)v2284, v2283, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6719);
  v2285 = (int)std_string_append(&v5983, (int)&Dst, "iron-sword3-random8.cub");
  v7813 = 1086;
  v2286 = this_4pointer_off((void *)v6, 941);
  something_database(*(_DWORD *)v2286, v2285, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5983);
  v2287 = (int)std_string_append(&v6717, (int)&Dst, "iron-sword4-random8.cub");
  v7813 = 1087;
  v2288 = this_4pointer_off((void *)v6, 942);
  something_database(*(_DWORD *)v2288, v2287, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6717);
  v2289 = (int)std_string_append(&v5615, (int)&Dst, "iron-sword5-random8.cub");
  v7813 = 1088;
  v2290 = this_4pointer_off((void *)v6, 943);
  something_database(*(_DWORD *)v2290, v2289, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5615);
  v2291 = (int)std_string_append(&v6715, (int)&Dst, "iron-sword1-random9.cub");
  v7813 = 1089;
  v2292 = this_4pointer_off((void *)v6, 944);
  something_database(*(_DWORD *)v2292, v2291, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6715);
  v2293 = (int)std_string_append(&v5981, (int)&Dst, "iron-sword2-random9.cub");
  v7813 = 1090;
  v2294 = this_4pointer_off((void *)v6, 945);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2293;
  something_database(*(_DWORD *)v2294, v2293, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5981);
  v2295 = (int)std_string_append(&v6713, (int)&Dst, "iron-sword3-random9.cub");
  v7813 = 1091;
  v2296 = this_4pointer_off((void *)v6, 946);
  something_database(*(_DWORD *)v2296, v2295, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6713);
  v2297 = (int)std_string_append(&v5431, (int)&Dst, "iron-sword4-random9.cub");
  v7813 = 1092;
  v2298 = this_4pointer_off((void *)v6, 947);
  something_database(*(_DWORD *)v2298, v2297, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5431);
  v2299 = (int)std_string_append(&v6711, (int)&Dst, "iron-sword5-random9.cub");
  v7813 = 1093;
  v2300 = this_4pointer_off((void *)v6, 948);
  something_database(*(_DWORD *)v2300, v2299, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6711);
  v2301 = (int)std_string_append(&v5979, (int)&Dst, "iron-sword1-random10.cub");
  v7813 = 1094;
  v2302 = this_4pointer_off((void *)v6, 949);
  something_database(*(_DWORD *)v2302, v2301, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5979);
  v2303 = (int)std_string_append(&v6709, (int)&Dst, "iron-sword2-random10.cub");
  v7813 = 1095;
  v2304 = this_4pointer_off((void *)v6, 950);
  something_database(*(_DWORD *)v2304, v2303, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6709);
  v2305 = (int)std_string_append(&v5613, (int)&Dst, "iron-sword3-random10.cub");
  v7813 = 1096;
  v2306 = this_4pointer_off((void *)v6, 951);
  something_database(*(_DWORD *)v2306, v2305, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5613);
  v2307 = (int)std_string_append(&v6707, (int)&Dst, "iron-sword4-random10.cub");
  v7813 = 1097;
  v2308 = this_4pointer_off((void *)v6, 952);
  something_database(*(_DWORD *)v2308, v2307, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6707);
  v2309 = (int)std_string_append(&v5977, (int)&Dst, "iron-sword5-random10.cub");
  v7813 = 1098;
  v2310 = this_4pointer_off((void *)v6, 953);
  something_database(*(_DWORD *)v2310, v2309, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5977);
  v2311 = (int)std_string_append(&v6705, (int)&Dst, "iron-dagger1.cub");
  v7813 = 1099;
  v2312 = this_4pointer_off((void *)v6, 954);
  something_database(*(_DWORD *)v2312, v2311, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6705);
  v2313 = (int)std_string_append(&v5339, (int)&Dst, "iron-dagger2.cub");
  v7813 = 1100;
  v2314 = this_4pointer_off((void *)v6, 955);
  something_database(*(_DWORD *)v2314, v2313, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5339);
  v2315 = (int)std_string_append(&v6703, (int)&Dst, "iron-dagger3.cub");
  v7813 = 1101;
  v2316 = this_4pointer_off((void *)v6, 956);
  something_database(*(_DWORD *)v2316, v2315, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6703);
  v2317 = (int)std_string_append(&v5975, (int)&Dst, "iron-dagger4.cub");
  v7813 = 1102;
  v2318 = this_4pointer_off((void *)v6, 957);
  something_database(*(_DWORD *)v2318, v2317, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5975);
  v2319 = (int)std_string_append(&v6701, (int)&Dst, "iron-dagger5.cub");
  v7813 = 1103;
  v2320 = this_4pointer_off((void *)v6, 958);
  something_database(*(_DWORD *)v2320, v2319, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6701);
  v2321 = (int)std_string_append(&v5611, (int)&Dst, "iron-dagger1-random1.cub");
  v7813 = 1104;
  v2322 = this_4pointer_off((void *)v6, 959);
  something_database(*(_DWORD *)v2322, v2321, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5611);
  v2323 = (int)std_string_append(&v6699, (int)&Dst, "iron-dagger2-random1.cub");
  v7813 = 1105;
  v2324 = this_4pointer_off((void *)v6, 960);
  something_database(*(_DWORD *)v2324, v2323, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6699);
  v2325 = (int)std_string_append(&v5973, (int)&Dst, (const char *)"iron-dagger3-random1.cub");
  v7813 = 1106;
  v2326 = this_4pointer_off((void *)v6, 961);
  something_database(*(_DWORD *)v2326, v2325, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5973);
  v2327 = (int)std_string_append(&v6697, (int)&Dst, "iron-dagger4-random1.cub");
  v7813 = 1107;
  v2328 = this_4pointer_off((void *)v6, 962);
  something_database(*(_DWORD *)v2328, v2327, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6697);
  v2329 = (int)std_string_append(&v5429, (int)&Dst, "iron-dagger5-random1.cub");
  v7813 = 1108;
  v2330 = this_4pointer_off((void *)v6, 963);
  something_database(*(_DWORD *)v2330, v2329, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5429);
  v2331 = (int)std_string_append(&v6695, (int)&Dst, "iron-dagger1-random2.cub");
  v7813 = 1109;
  v2332 = this_4pointer_off((void *)v6, 964);
  something_database(*(_DWORD *)v2332, v2331, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6695);
  v2333 = (int)std_string_append(&v5971, (int)&Dst, "iron-dagger2-random2.cub");
  v7813 = 1110;
  v2334 = this_4pointer_off((void *)v6, 965);
  something_database(*(_DWORD *)v2334, v2333, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5971);
  v2335 = (int)std_string_append(&v6693, (int)&Dst, "iron-dagger3-random2.cub");
  v7813 = 1111;
  v2336 = this_4pointer_off((void *)v6, 966);
  something_database(*(_DWORD *)v2336, v2335, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6693);
  v2337 = (int)std_string_append(&v5609, (int)&Dst, "iron-dagger4-random2.cub");
  v7813 = 1112;
  v2338 = this_4pointer_off((void *)v6, 967);
  something_database(*(_DWORD *)v2338, v2337, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5609);
  v2339 = (int)std_string_append(&v6691, (int)&Dst, "iron-dagger5-random2.cub");
  v7813 = 1113;
  v2340 = this_4pointer_off((void *)v6, 968);
  something_database(*(_DWORD *)v2340, v2339, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6691);
  v2341 = (int)std_string_append(&v5969, (int)&Dst, "iron-dagger1-random3.cub");
  v7813 = 1114;
  v2342 = this_4pointer_off((void *)v6, 969);
  something_database(*(_DWORD *)v2342, v2341, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5969);
  v2343 = (int)std_string_append(&v6689, (int)&Dst, "iron-dagger2-random3.cub");
  v7813 = 1115;
  v2344 = this_4pointer_off((void *)v6, 970);
  something_database(*(_DWORD *)v2344, v2343, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6689);
  v2345 = (int)std_string_append(&v5293, (int)&Dst, "iron-dagger3-random3.cub");
  v7813 = 1116;
  v2346 = this_4pointer_off((void *)v6, 971);
  something_database(*(_DWORD *)v2346, v2345, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5293);
  v2347 = (int)std_string_append(&v6687, (int)&Dst, "iron-dagger4-random3.cub");
  v7813 = 1117;
  v2348 = this_4pointer_off((void *)v6, 972);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2347;
  something_database(*(_DWORD *)v2348, v2347, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6687);
  v2349 = (int)std_string_append(&v5967, (int)&Dst, "iron-dagger5-random3.cub");
  v7813 = 1118;
  v2350 = this_4pointer_off((void *)v6, 973);
  something_database(*(_DWORD *)v2350, v2349, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5967);
  v2351 = (int)std_string_append(&v6685, (int)&Dst, "iron-dagger1-random4.cub");
  v7813 = 1119;
  v2352 = this_4pointer_off((void *)v6, 974);
  something_database(*(_DWORD *)v2352, v2351, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6685);
  v2353 = (int)std_string_append(&v5607, (int)&Dst, "iron-dagger2-random4.cub");
  v7813 = 1120;
  v2354 = this_4pointer_off((void *)v6, 975);
  something_database(*(_DWORD *)v2354, v2353, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5607);
  v2355 = (int)std_string_append(&v6683, (int)&Dst, "iron-dagger3-random4.cub");
  v7813 = 1121;
  v2356 = this_4pointer_off((void *)v6, 976);
  something_database(*(_DWORD *)v2356, v2355, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6683);
  v2357 = (int)std_string_append(&v5965, (int)&Dst, "iron-dagger4-random4.cub");
  v7813 = 1122;
  v2358 = this_4pointer_off((void *)v6, 977);
  something_database(*(_DWORD *)v2358, v2357, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5965);
  v2359 = (int)std_string_append(&v6681, (int)&Dst, "iron-dagger5-random4.cub");
  v7813 = 1123;
  v2360 = this_4pointer_off((void *)v6, 978);
  something_database(*(_DWORD *)v2360, v2359, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6681);
  v2361 = (int)std_string_append(&v5427, (int)&Dst, "iron-dagger1-random5.cub");
  v7813 = 1124;
  v2362 = this_4pointer_off((void *)v6, 979);
  something_database(*(_DWORD *)v2362, v2361, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5427);
  v2363 = (int)std_string_append(&v6679, (int)&Dst, "iron-dagger2-random5.cub");
  v7813 = 1125;
  v2364 = this_4pointer_off((void *)v6, 980);
  something_database(*(_DWORD *)v2364, v2363, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6679);
  v2365 = (int)std_string_append(&v5963, (int)&Dst, "iron-dagger3-random5.cub");
  v7813 = 1126;
  v2366 = this_4pointer_off((void *)v6, 981);
  something_database(*(_DWORD *)v2366, v2365, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5963);
  v2367 = (int)std_string_append(&v6677, (int)&Dst, "iron-dagger4-random5.cub");
  v7813 = 1127;
  v2368 = this_4pointer_off((void *)v6, 982);
  something_database(*(_DWORD *)v2368, v2367, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6677);
  v2369 = (int)std_string_append(&v5605, (int)&Dst, "iron-dagger5-random5.cub");
  v7813 = 1128;
  v2370 = this_4pointer_off((void *)v6, 983);
  something_database(*(_DWORD *)v2370, v2369, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5605);
  v2371 = (int)std_string_append(&v6675, (int)&Dst, "iron-dagger1-random6.cub");
  v7813 = 1129;
  v2372 = this_4pointer_off((void *)v6, 984);
  something_database(*(_DWORD *)v2372, v2371, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6675);
  v2373 = (int)std_string_append(&v5961, (int)&Dst, "iron-dagger2-random6.cub");
  v7813 = 1130;
  v2374 = this_4pointer_off((void *)v6, 985);
  something_database(*(_DWORD *)v2374, v2373, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5961);
  v2375 = (int)std_string_append(&v6673, (int)&Dst, "iron-dagger3-random6.cub");
  v7813 = 1131;
  v2376 = this_4pointer_off((void *)v6, 986);
  something_database(*(_DWORD *)v2376, v2375, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6673);
  v2377 = (int)std_string_append(&v5337, (int)&Dst, "iron-dagger4-random6.cub");
  v7813 = 1132;
  v2378 = this_4pointer_off((void *)v6, 987);
  something_database(*(_DWORD *)v2378, v2377, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5337);
  v2379 = (int)std_string_append(&v6671, (int)&Dst, "iron-dagger5-random6.cub");
  v7813 = 1133;
  v2380 = this_4pointer_off((void *)v6, 988);
  something_database(*(_DWORD *)v2380, v2379, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6671);
  v2381 = (int)std_string_append(&v5959, (int)&Dst, "iron-dagger1-random7.cub");
  v7813 = 1134;
  v2382 = this_4pointer_off((void *)v6, 989);
  something_database(*(_DWORD *)v2382, v2381, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5959);
  v2383 = (int)std_string_append(&v6669, (int)&Dst, "iron-dagger2-random7.cub");
  v7813 = 1135;
  v2384 = this_4pointer_off((void *)v6, 990);
  something_database(*(_DWORD *)v2384, v2383, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6669);
  v2385 = (int)std_string_append(&v5603, (int)&Dst, "iron-dagger3-random7.cub");
  v7813 = 1136;
  v2386 = this_4pointer_off((void *)v6, 991);
  something_database(*(_DWORD *)v2386, v2385, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5603);
  v2387 = (int)std_string_append(&v6667, (int)&Dst, "iron-dagger4-random7.cub");
  v7813 = 1137;
  v2388 = this_4pointer_off((void *)v6, 992);
  something_database(*(_DWORD *)v2388, v2387, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6667);
  v2389 = (int)std_string_append(&v5957, (int)&Dst, "iron-dagger5-random7.cub");
  v7813 = 1138;
  v2390 = this_4pointer_off((void *)v6, 993);
  something_database(*(_DWORD *)v2390, v2389, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5957);
  v2391 = (int)std_string_append(&v6665, (int)&Dst, "iron-dagger1-random8.cub");
  v7813 = 1139;
  v2392 = this_4pointer_off((void *)v6, 994);
  something_database(*(_DWORD *)v2392, v2391, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6665);
  v2393 = (int)std_string_append(&v5425, (int)&Dst, "iron-dagger2-random8.cub");
  v7813 = 1140;
  v2394 = this_4pointer_off((void *)v6, 995);
  something_database(*(_DWORD *)v2394, v2393, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5425);
  v2395 = (int)std_string_append(&v6663, (int)&Dst, "iron-dagger3-random8.cub");
  v7813 = 1141;
  v2396 = this_4pointer_off((void *)v6, 996);
  something_database(*(_DWORD *)v2396, v2395, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6663);
  v2397 = (int)std_string_append(&v5955, (int)&Dst, "iron-dagger4-random8.cub");
  v7813 = 1142;
  v2398 = this_4pointer_off((void *)v6, 997);
  something_database(*(_DWORD *)v2398, v2397, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5955);
  v2399 = (int)std_string_append(&v6661, (int)&Dst, "iron-dagger5-random8.cub");
  v7813 = 1143;
  v2400 = this_4pointer_off((void *)v6, 998);
  something_database(*(_DWORD *)v2400, v2399, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6661);
  v2401 = (int)std_string_append(&v5601, (int)&Dst, "iron-dagger1-random9.cub");
  v7813 = 1144;
  v2402 = this_4pointer_off((void *)v6, 999);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2401;
  something_database(*(_DWORD *)v2402, v2401, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5601);
  v2403 = (int)std_string_append(&v6659, (int)&Dst, "iron-dagger2-random9.cub");
  v7813 = 1145;
  v2404 = this_4pointer_off((void *)v6, 1000);
  something_database(*(_DWORD *)v2404, v2403, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6659);
  v2405 = (int)std_string_append(&v5953, (int)&Dst, "iron-dagger3-random9.cub");
  v7813 = 1146;
  v2406 = this_4pointer_off((void *)v6, 1001);
  something_database(*(_DWORD *)v2406, v2405, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5953);
  v2407 = (int)std_string_append(&v6657, (int)&Dst, "iron-dagger4-random9.cub");
  v7813 = 1147;
  v2408 = this_4pointer_off((void *)v6, 1002);
  something_database(*(_DWORD *)v2408, v2407, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6657);
  v2409 = (int)std_string_append(&v5259, (int)&Dst, "iron-dagger5-random9.cub");
  v7813 = 1148;
  v2410 = this_4pointer_off((void *)v6, 1003);
  something_database(*(_DWORD *)v2410, v2409, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5259);
  v2411 = (int)std_string_append(&v6655, (int)&Dst, "iron-dagger1-random10.cub");
  v7813 = 1149;
  v2412 = this_4pointer_off((void *)v6, 1004);
  something_database(*(_DWORD *)v2412, v2411, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6655);
  v2413 = (int)std_string_append(&v5951, (int)&Dst, "iron-dagger2-random10.cub");
  v7813 = 1150;
  v2414 = this_4pointer_off((void *)v6, 1005);
  something_database(*(_DWORD *)v2414, v2413, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5951);
  v2415 = (int)std_string_append(&v6653, (int)&Dst, "iron-dagger3-random10.cub");
  v7813 = 1151;
  v2416 = this_4pointer_off((void *)v6, 1006);
  something_database(*(_DWORD *)v2416, v2415, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6653);
  v2417 = (int)std_string_append(&v5599, (int)&Dst, "iron-dagger4-random10.cub");
  v7813 = 1152;
  v2418 = this_4pointer_off((void *)v6, 1007);
  something_database(*(_DWORD *)v2418, v2417, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5599);
  v2419 = (int)std_string_append(&v6651, (int)&Dst, "iron-dagger5-random10.cub");
  v7813 = 1153;
  v2420 = this_4pointer_off((void *)v6, 1008);
  something_database(*(_DWORD *)v2420, v2419, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6651);
  v2421 = (int)std_string_append(&v5949, (int)&Dst, "iron-fist1.cub");
  v7813 = 1154;
  v2422 = this_4pointer_off((void *)v6, 1009);
  something_database(*(_DWORD *)v2422, v2421, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5949);
  v2423 = (int)std_string_append(&v6649, (int)&Dst, "iron-fist2.cub");
  v7813 = 1155;
  v2424 = this_4pointer_off((void *)v6, 1010);
  something_database(*(_DWORD *)v2424, v2423, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6649);
  v2425 = (int)std_string_append(&v5423, (int)&Dst, (const char *)"iron-fist3.cub");
  v7813 = 1156;
  v2426 = this_4pointer_off((void *)v6, 1011);
  something_database(*(_DWORD *)v2426, v2425, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5423);
  v2427 = (int)std_string_append(&v6647, (int)&Dst, "iron-fist4.cub");
  v7813 = 1157;
  v2428 = this_4pointer_off((void *)v6, 1012);
  something_database(*(_DWORD *)v2428, v2427, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6647);
  v2429 = (int)std_string_append(&v5947, (int)&Dst, "iron-fist5.cub");
  v7813 = 1158;
  v2430 = this_4pointer_off((void *)v6, 1013);
  something_database(*(_DWORD *)v2430, v2429, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5947);
  v2431 = (int)std_string_append(&v6645, (int)&Dst, "iron-fist1-random1.cub");
  v7813 = 1159;
  v2432 = this_4pointer_off((void *)v6, 1014);
  something_database(*(_DWORD *)v2432, v2431, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6645);
  v2433 = (int)std_string_append(&v5597, (int)&Dst, "iron-fist2-random1.cub");
  v7813 = 1160;
  v2434 = this_4pointer_off((void *)v6, 1015);
  something_database(*(_DWORD *)v2434, v2433, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5597);
  v2435 = (int)std_string_append(&v6643, (int)&Dst, "iron-fist3-random1.cub");
  v7813 = 1161;
  v2436 = this_4pointer_off((void *)v6, 1016);
  something_database(*(_DWORD *)v2436, v2435, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6643);
  v2437 = (int)std_string_append(&v5945, (int)&Dst, "iron-fist4-random1.cub");
  v7813 = 1162;
  v2438 = this_4pointer_off((void *)v6, 1017);
  something_database(*(_DWORD *)v2438, v2437, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5945);
  v2439 = (int)std_string_append(&v6641, (int)&Dst, "iron-fist5-random1.cub");
  v7813 = 1163;
  v2440 = this_4pointer_off((void *)v6, 1018);
  something_database(*(_DWORD *)v2440, v2439, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6641);
  v2441 = (int)std_string_append(&v5335, (int)&Dst, "iron-fist1-random2.cub");
  v7813 = 1164;
  v2442 = this_4pointer_off((void *)v6, 1019);
  something_database(*(_DWORD *)v2442, v2441, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5335);
  v2443 = (int)std_string_append(&v6639, (int)&Dst, "iron-fist2-random2.cub");
  v7813 = 1165;
  v2444 = this_4pointer_off((void *)v6, 1020);
  something_database(*(_DWORD *)v2444, v2443, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6639);
  v2445 = (int)std_string_append(&v5943, (int)&Dst, "iron-fist3-random2.cub");
  v7813 = 1166;
  v2446 = this_4pointer_off((void *)v6, 1021);
  something_database(*(_DWORD *)v2446, v2445, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5943);
  v2447 = (int)std_string_append(&v6637, (int)&Dst, "iron-fist4-random2.cub");
  v7813 = 1167;
  v2448 = this_4pointer_off((void *)v6, 1022);
  something_database(*(_DWORD *)v2448, v2447, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6637);
  v2449 = (int)std_string_append(&v5595, (int)&Dst, "iron-fist5-random2.cub");
  v7813 = 1168;
  v2450 = this_4pointer_off((void *)v6, 1023);
  something_database(*(_DWORD *)v2450, v2449, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5595);
  v2451 = (int)std_string_append(&v6635, (int)&Dst, "iron-fist1-random3.cub");
  v7813 = 1169;
  v2452 = this_4pointer_off((void *)v6, 1024);
  something_database(*(_DWORD *)v2452, v2451, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6635);
  v2453 = (int)std_string_append(&v5941, (int)&Dst, "iron-fist2-random3.cub");
  v7813 = 1170;
  v2454 = this_4pointer_off((void *)v6, 1025);
  something_database(*(_DWORD *)v2454, v2453, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5941);
  v2455 = (int)std_string_append(&v6633, (int)&Dst, "iron-fist3-random3.cub");
  v7813 = 1171;
  v2456 = this_4pointer_off((void *)v6, 1026);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2455;
  something_database(*(_DWORD *)v2456, v2455, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6633);
  v2457 = (int)std_string_append(&v5421, (int)&Dst, "iron-fist4-random3.cub");
  v7813 = 1172;
  v2458 = this_4pointer_off((void *)v6, 1027);
  something_database(*(_DWORD *)v2458, v2457, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5421);
  v2459 = (int)std_string_append(&v6631, (int)&Dst, "iron-fist5-random3.cub");
  v7813 = 1173;
  v2460 = this_4pointer_off((void *)v6, 1028);
  something_database(*(_DWORD *)v2460, v2459, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6631);
  v2461 = (int)std_string_append(&v5939, (int)&Dst, "iron-fist1-random4.cub");
  v7813 = 1174;
  v2462 = this_4pointer_off((void *)v6, 1029);
  something_database(*(_DWORD *)v2462, v2461, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5939);
  v2463 = (int)std_string_append(&v6629, (int)&Dst, "iron-fist2-random4.cub");
  v7813 = 1175;
  v2464 = this_4pointer_off((void *)v6, 1030);
  something_database(*(_DWORD *)v2464, v2463, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6629);
  v2465 = (int)std_string_append(&v5593, (int)&Dst, "iron-fist3-random4.cub");
  v7813 = 1176;
  v2466 = this_4pointer_off((void *)v6, 1031);
  something_database(*(_DWORD *)v2466, v2465, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5593);
  v2467 = (int)std_string_append(&v6627, (int)&Dst, "iron-fist4-random4.cub");
  v7813 = 1177;
  v2468 = this_4pointer_off((void *)v6, 1032);
  something_database(*(_DWORD *)v2468, v2467, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6627);
  v2469 = (int)std_string_append(&v5937, (int)&Dst, "iron-fist5-random4.cub");
  v7813 = 1178;
  v2470 = this_4pointer_off((void *)v6, 1033);
  something_database(*(_DWORD *)v2470, v2469, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5937);
  v2471 = (int)std_string_append(&v6625, (int)&Dst, "iron-fist1-random5.cub");
  v7813 = 1179;
  v2472 = this_4pointer_off((void *)v6, 1034);
  something_database(*(_DWORD *)v2472, v2471, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6625);
  v2473 = (int)std_string_append(&v5291, (int)&Dst, "iron-fist2-random5.cub");
  v7813 = 1180;
  v2474 = this_4pointer_off((void *)v6, 1035);
  something_database(*(_DWORD *)v2474, v2473, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5291);
  v2475 = (int)std_string_append(&v6623, (int)&Dst, "iron-fist3-random5.cub");
  v7813 = 1181;
  v2476 = this_4pointer_off((void *)v6, 1036);
  something_database(*(_DWORD *)v2476, v2475, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6623);
  v2477 = (int)std_string_append(&v5935, (int)&Dst, "iron-fist4-random5.cub");
  v7813 = 1182;
  v2478 = this_4pointer_off((void *)v6, 1037);
  something_database(*(_DWORD *)v2478, v2477, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5935);
  v2479 = (int)std_string_append(&v6621, (int)&Dst, "iron-fist5-random5.cub");
  v7813 = 1183;
  v2480 = this_4pointer_off((void *)v6, 1038);
  something_database(*(_DWORD *)v2480, v2479, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6621);
  v2481 = (int)std_string_append(&v5591, (int)&Dst, "iron-fist1-random6.cub");
  v7813 = 1184;
  v2482 = this_4pointer_off((void *)v6, 1039);
  something_database(*(_DWORD *)v2482, v2481, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5591);
  v2483 = (int)std_string_append(&v6619, (int)&Dst, "iron-fist2-random6.cub");
  v7813 = 1185;
  v2484 = this_4pointer_off((void *)v6, 1040);
  something_database(*(_DWORD *)v2484, v2483, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6619);
  v2485 = (int)std_string_append(&v5933, (int)&Dst, "iron-fist3-random6.cub");
  v7813 = 1186;
  v2486 = this_4pointer_off((void *)v6, 1041);
  something_database(*(_DWORD *)v2486, v2485, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5933);
  v2487 = (int)std_string_append(&v6617, (int)&Dst, "iron-fist4-random6.cub");
  v7813 = 1187;
  v2488 = this_4pointer_off((void *)v6, 1042);
  something_database(*(_DWORD *)v2488, v2487, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6617);
  v2489 = (int)std_string_append(&v5419, (int)&Dst, "iron-fist5-random6.cub");
  v7813 = 1188;
  v2490 = this_4pointer_off((void *)v6, 1043);
  something_database(*(_DWORD *)v2490, v2489, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5419);
  v2491 = (int)std_string_append(&v6615, (int)&Dst, "iron-fist1-random7.cub");
  v7813 = 1189;
  v2492 = this_4pointer_off((void *)v6, 1044);
  something_database(*(_DWORD *)v2492, v2491, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6615);
  v2493 = (int)std_string_append(&v5931, (int)&Dst, "iron-fist2-random7.cub");
  v7813 = 1190;
  v2494 = this_4pointer_off((void *)v6, 1045);
  something_database(*(_DWORD *)v2494, v2493, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5931);
  v2495 = (int)std_string_append(&v6613, (int)&Dst, "iron-fist3-random7.cub");
  v7813 = 1191;
  v2496 = this_4pointer_off((void *)v6, 1046);
  something_database(*(_DWORD *)v2496, v2495, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6613);
  v2497 = (int)std_string_append(&v5589, (int)&Dst, "iron-fist4-random7.cub");
  v7813 = 1192;
  v2498 = this_4pointer_off((void *)v6, 1047);
  something_database(*(_DWORD *)v2498, v2497, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5589);
  v2499 = (int)std_string_append(&v6611, (int)&Dst, "iron-fist5-random7.cub");
  v7813 = 1193;
  v2500 = this_4pointer_off((void *)v6, 1048);
  something_database(*(_DWORD *)v2500, v2499, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6611);
  v2501 = (int)std_string_append(&v5929, (int)&Dst, "iron-fist1-random8.cub");
  v7813 = 1194;
  v2502 = this_4pointer_off((void *)v6, 1049);
  something_database(*(_DWORD *)v2502, v2501, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5929);
  v2503 = (int)std_string_append(&v6609, (int)&Dst, (const char *)"iron-fist2-random8.cub");
  v7813 = 1195;
  v2504 = this_4pointer_off((void *)v6, 1050);
  something_database(*(_DWORD *)v2504, v2503, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6609);
  v2505 = (int)std_string_append(&v5333, (int)&Dst, "iron-fist3-random8.cub");
  v7813 = 1196;
  v2506 = this_4pointer_off((void *)v6, 1051);
  something_database(*(_DWORD *)v2506, v2505, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5333);
  v2507 = (int)std_string_append(&v6607, (int)&Dst, "iron-fist4-random8.cub");
  v7813 = 1197;
  v2508 = this_4pointer_off((void *)v6, 1052);
  something_database(*(_DWORD *)v2508, v2507, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6607);
  v2509 = (int)std_string_append(&v5927, (int)&Dst, "iron-fist5-random8.cub");
  v7813 = 1198;
  v2510 = this_4pointer_off((void *)v6, 1053);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2509;
  something_database(*(_DWORD *)v2510, v2509, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5927);
  v2511 = (int)std_string_append(&v6605, (int)&Dst, (const char *)"iron-fist1-random9.cub");
  v7813 = 1199;
  v2512 = this_4pointer_off((void *)v6, 1054);
  something_database(*(_DWORD *)v2512, v2511, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6605);
  v2513 = (int)std_string_append(&v5587, (int)&Dst, "iron-fist2-random9.cub");
  v7813 = 1200;
  v2514 = this_4pointer_off((void *)v6, 1055);
  something_database(*(_DWORD *)v2514, v2513, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5587);
  v2515 = (int)std_string_append(&v6603, (int)&Dst, "iron-fist3-random9.cub");
  v7813 = 1201;
  v2516 = this_4pointer_off((void *)v6, 1056);
  something_database(*(_DWORD *)v2516, v2515, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6603);
  v2517 = (int)std_string_append(&v5925, (int)&Dst, "iron-fist4-random9.cub");
  v7813 = 1202;
  v2518 = this_4pointer_off((void *)v6, 1057);
  something_database(*(_DWORD *)v2518, v2517, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5925);
  v2519 = (int)std_string_append(&v6601, (int)&Dst, "iron-fist5-random9.cub");
  v7813 = 1203;
  v2520 = this_4pointer_off((void *)v6, 1058);
  something_database(*(_DWORD *)v2520, v2519, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6601);
  v2521 = (int)std_string_append(&v5417, (int)&Dst, "iron-fist1-random10.cub");
  v7813 = 1204;
  v2522 = this_4pointer_off((void *)v6, 1059);
  something_database(*(_DWORD *)v2522, v2521, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5417);
  v2523 = (int)std_string_append(&v6599, (int)&Dst, "iron-fist2-random10.cub");
  v7813 = 1205;
  v2524 = this_4pointer_off((void *)v6, 1060);
  something_database(*(_DWORD *)v2524, v2523, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6599);
  v2525 = (int)std_string_append(&v5923, (int)&Dst, "iron-fist3-random10.cub");
  v7813 = 1206;
  v2526 = this_4pointer_off((void *)v6, 1061);
  something_database(*(_DWORD *)v2526, v2525, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5923);
  v2527 = (int)std_string_append(&v6597, (int)&Dst, "iron-fist4-random10.cub");
  v7813 = 1207;
  v2528 = this_4pointer_off((void *)v6, 1062);
  something_database(*(_DWORD *)v2528, v2527, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6597);
  v2529 = (int)std_string_append(&v5585, (int)&Dst, "iron-fist5-random10.cub");
  v7813 = 1208;
  v2530 = this_4pointer_off((void *)v6, 1063);
  something_database(*(_DWORD *)v2530, v2529, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5585);
  v2531 = (int)std_string_append(&v6595, (int)&Dst, "iron-helmet.cub");
  v7813 = 1209;
  v2532 = this_4pointer_off((void *)v6, 1769);
  something_database(*(_DWORD *)v2532, v2531, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6595);
  v2533 = (int)std_string_append(&v5921, (int)&Dst, "innkeeper-chest.cub");
  v7813 = 1210;
  v2534 = this_4pointer_off((void *)v6, 1229);
  something_database(*(_DWORD *)v2534, v2533, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5921);
  v2535 = (int)std_string_append(&v6593, (int)&Dst, "backpack.cub");
  v7813 = 1211;
  v2536 = this_4pointer_off((void *)v6, 1230);
  something_database(*(_DWORD *)v2536, v2535, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6593);
  v2537 = (int)std_string_append(&v5269, (int)&Dst, "body1.cub");
  v7813 = 1212;
  v2538 = this_4pointer_off((void *)v6, 1231);
  something_database(*(_DWORD *)v2538, v2537, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5269);
  v2539 = (int)std_string_append(&v6591, (int)&Dst, "body2.cub");
  v7813 = 1213;
  v2540 = this_4pointer_off((void *)v6, 1232);
  something_database(*(_DWORD *)v2540, v2539, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6591);
  v2541 = (int)std_string_append(&v5919, (int)&Dst, "body3.cub");
  v7813 = 1214;
  v2542 = this_4pointer_off((void *)v6, 1233);
  something_database(*(_DWORD *)v2542, v2541, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5919);
  v2543 = (int)std_string_append(&v6589, (int)&Dst, "body4.cub");
  v7813 = 1215;
  v2544 = this_4pointer_off((void *)v6, 1234);
  something_database(*(_DWORD *)v2544, v2543, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6589);
  v2545 = (int)std_string_append(&v5583, (int)&Dst, "body5.cub");
  v7813 = 1216;
  v2546 = this_4pointer_off((void *)v6, 1235);
  something_database(*(_DWORD *)v2546, v2545, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5583);
  v2547 = (int)std_string_append(&v6587, (int)&Dst, "backpack.cub");
  v7813 = 1217;
  v2548 = this_4pointer_off((void *)v6, 1230);
  something_database(*(_DWORD *)v2548, v2547, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6587);
  v2549 = (int)std_string_append(&v5917, (int)&Dst, "obsidian-chest.cub");
  v7813 = 1218;
  v2550 = this_4pointer_off((void *)v6, 2054);
  something_database(*(_DWORD *)v2550, v2549, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5917);
  v2551 = (int)std_string_append(&v6585, (int)&Dst, "obsidian-shoulders.cub");
  v7813 = 1219;
  v2552 = this_4pointer_off((void *)v6, 2055);
  something_database(*(_DWORD *)v2552, v2551, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6585);
  v2553 = (int)std_string_append(&v5415, (int)&Dst, "obsidian-boot.cub");
  v7813 = 1220;
  v2554 = this_4pointer_off((void *)v6, 2056);
  something_database(*(_DWORD *)v2554, v2553, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5415);
  v2555 = (int)std_string_append(&v6583, (int)&Dst, "obsidian-glove.cub");
  v7813 = 1221;
  v2556 = this_4pointer_off((void *)v6, 2057);
  something_database(*(_DWORD *)v2556, v2555, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6583);
  v2557 = (int)std_string_append(&v5915, (int)&Dst, "obsidian-helmet.cub");
  v7813 = 1222;
  v2558 = this_4pointer_off((void *)v6, 2058);
  something_database(*(_DWORD *)v2558, v2557, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5915);
  v2559 = (int)std_string_append(&v6581, (int)&Dst, "gold-chest.cub");
  v7813 = 1223;
  v2560 = this_4pointer_off((void *)v6, 2062);
  something_database(*(_DWORD *)v2560, v2559, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6581);
  v2561 = (int)std_string_append(&v5581, (int)&Dst, "gold-shoulder.cub");
  v7813 = 1224;
  v2562 = this_4pointer_off((void *)v6, 2063);
  something_database(*(_DWORD *)v2562, v2561, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5581);
  v2563 = (int)std_string_append(&v6579, (int)&Dst, "gold-boot.cub");
  v7813 = 1225;
  v2564 = this_4pointer_off((void *)v6, 2064);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2563;
  something_database(*(_DWORD *)v2564, v2563, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6579);
  v2565 = (int)std_string_append(&v5913, (int)&Dst, "gold-glove.cub");
  v7813 = 1226;
  v2566 = this_4pointer_off((void *)v6, 2065);
  something_database(*(_DWORD *)v2566, v2565, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5913);
  v2567 = (int)std_string_append(&v6577, (int)&Dst, "gold-helmet.cub");
  v7813 = 1227;
  v2568 = this_4pointer_off((void *)v6, 2066);
  something_database(*(_DWORD *)v2568, v2567, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6577);
  v2569 = (int)std_string_append(&v5331, (int)&Dst, "ice-crystal-chest.cub");
  v7813 = 1228;
  v2570 = this_4pointer_off((void *)v6, 2360);
  something_database(*(_DWORD *)v2570, v2569, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5331);
  v2571 = (int)std_string_append(&v6575, (int)&Dst, "ice-crystal-shoulder.cub");
  v7813 = 1229;
  v2572 = this_4pointer_off((void *)v6, 2359);
  something_database(*(_DWORD *)v2572, v2571, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6575);
  v2573 = (int)std_string_append(&v5911, (int)&Dst, "ice-crystal-boot.cub");
  v7813 = 1230;
  v2574 = this_4pointer_off((void *)v6, 2361);
  something_database(*(_DWORD *)v2574, v2573, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5911);
  v2575 = (int)std_string_append(&v6573, (int)&Dst, "ice-crystal-glove.cub");
  v7813 = 1231;
  v2576 = this_4pointer_off((void *)v6, 2362);
  something_database(*(_DWORD *)v2576, v2575, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6573);
  v2577 = (int)std_string_append(&v5579, (int)&Dst, "ice-crystal-helmet.cub");
  v7813 = 1232;
  v2578 = this_4pointer_off((void *)v6, 2358);
  something_database(*(_DWORD *)v2578, v2577, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5579);
  v2579 = (int)std_string_append(&v6571, (int)&Dst, "saurian-chest.cub");
  v7813 = 1233;
  v2580 = this_4pointer_off((void *)v6, 1224);
  something_database(*(_DWORD *)v2580, v2579, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6571);
  v2581 = (int)std_string_append(&v5909, (int)&Dst, "saurian-shoulder.cub");
  v7813 = 1234;
  v2582 = this_4pointer_off((void *)v6, 1225);
  something_database(*(_DWORD *)v2582, v2581, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5909);
  v2583 = (int)std_string_append(&v6569, (int)&Dst, "saurian-boot.cub");
  v7813 = 1235;
  v2584 = this_4pointer_off((void *)v6, 1227);
  something_database(*(_DWORD *)v2584, v2583, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6569);
  v2585 = (int)std_string_append(&v5413, (int)&Dst, "saurian-glove.cub");
  v7813 = 1236;
  v2586 = this_4pointer_off((void *)v6, 1226);
  something_database(*(_DWORD *)v2586, v2585, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5413);
  v2587 = (int)std_string_append(&v6567, (int)&Dst, "saurian-helmet.cub");
  v7813 = 1237;
  v2588 = this_4pointer_off((void *)v6, 1228);
  something_database(*(_DWORD *)v2588, v2587, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6567);
  v2589 = (int)std_string_append(&v5907, (int)&Dst, "saurian-chest.cub");
  v7813 = 1238;
  v2590 = this_4pointer_off((void *)v6, 1224);
  something_database(*(_DWORD *)v2590, v2589, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5907);
  v2591 = (int)std_string_append(&v6565, (int)&Dst, "saurian-shoulder.cub");
  v7813 = 1239;
  v2592 = this_4pointer_off((void *)v6, 1225);
  something_database(*(_DWORD *)v2592, v2591, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6565);
  v2593 = (int)std_string_append(&v5577, (int)&Dst, "saurian-boot.cub");
  v7813 = 1240;
  v2594 = this_4pointer_off((void *)v6, 1227);
  something_database(*(_DWORD *)v2594, v2593, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5577);
  v2595 = (int)std_string_append(&v6563, (int)&Dst, "saurian-glove.cub");
  v7813 = 1241;
  v2596 = this_4pointer_off((void *)v6, 1226);
  something_database(*(_DWORD *)v2596, v2595, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6563);
  v2597 = (int)std_string_append(&v5905, (int)&Dst, "saurian-helmet.cub");
  v7813 = 1242;
  v2598 = this_4pointer_off((void *)v6, 1228);
  something_database(*(_DWORD *)v2598, v2597, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5905);
  v2599 = (int)std_string_append(&v6561, (int)&Dst, "parrot-chest.cub");
  v7813 = 1243;
  v2600 = this_4pointer_off((void *)v6, 2369);
  something_database(*(_DWORD *)v2600, v2599, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6561);
  v2601 = (int)std_string_append(&v5289, (int)&Dst, "parrot-shoulder.cub");
  v7813 = 1244;
  v2602 = this_4pointer_off((void *)v6, 2372);
  something_database(*(_DWORD *)v2602, v2601, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5289);
  v2603 = (int)std_string_append(&v6559, (int)&Dst, "parrot-boot.cub");
  v7813 = 1245;
  v2604 = this_4pointer_off((void *)v6, 2370);
  something_database(*(_DWORD *)v2604, v2603, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6559);
  v2605 = (int)std_string_append(&v5903, (int)&Dst, "parrot-glove.cub");
  v7813 = 1246;
  v2606 = this_4pointer_off((void *)v6, 2368);
  something_database(*(_DWORD *)v2606, v2605, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5903);
  v2607 = (int)std_string_append(&v6557, (int)&Dst, "parrot-helmet.cub");
  v7813 = 1247;
  v2608 = this_4pointer_off((void *)v6, 2371);
  something_database(*(_DWORD *)v2608, v2607, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6557);
  v2609 = (int)std_string_append(&v5575, (int)&Dst, "light-chest.cub");
  v7813 = 1248;
  v2610 = this_4pointer_off((void *)v6, 670);
  something_database(*(_DWORD *)v2610, v2609, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5575);
  v2611 = (int)std_string_append(&v6555, (int)&Dst, "light-shoulder.cub");
  v7813 = 1249;
  v2612 = this_4pointer_off((void *)v6, 671);
  something_database(*(_DWORD *)v2612, v2611, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6555);
  v2613 = (int)std_string_append(&v5901, (int)&Dst, "light-boot.cub");
  v7813 = 1250;
  v2614 = this_4pointer_off((void *)v6, 673);
  something_database(*(_DWORD *)v2614, v2613, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5901);
  v2615 = (int)std_string_append(&v6553, (int)&Dst, "light-glove.cub");
  v7813 = 1251;
  v2616 = this_4pointer_off((void *)v6, 672);
  something_database(*(_DWORD *)v2616, v2615, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6553);
  v2617 = (int)std_string_append(&v5411, (int)&Dst, "light-helmet.cub");
  v7813 = 1252;
  v2618 = this_4pointer_off((void *)v6, 669);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2617;
  something_database(*(_DWORD *)v2618, v2617, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5411);
  v2619 = (int)std_string_append(&v6551, (int)&Dst, "silk-chest1.cub");
  v7813 = 1253;
  v2620 = this_4pointer_off((void *)v6, 1669);
  something_database(*(_DWORD *)v2620, v2619, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6551);
  v2621 = (int)std_string_append(&v5899, (int)&Dst, "silk-chest2.cub");
  v7813 = 1254;
  v2622 = this_4pointer_off((void *)v6, 1670);
  something_database(*(_DWORD *)v2622, v2621, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5899);
  v2623 = (int)std_string_append(&v6549, (int)&Dst, "silk-chest3.cub");
  v7813 = 1255;
  v2624 = this_4pointer_off((void *)v6, 1671);
  something_database(*(_DWORD *)v2624, v2623, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6549);
  v2625 = (int)std_string_append(&v5573, (int)&Dst, "silk-chest4.cub");
  v7813 = 1256;
  v2626 = this_4pointer_off((void *)v6, 1672);
  something_database(*(_DWORD *)v2626, v2625, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5573);
  v2627 = (int)std_string_append(&v6547, (int)&Dst, "silk-chest5.cub");
  v7813 = 1257;
  v2628 = this_4pointer_off((void *)v6, 1673);
  something_database(*(_DWORD *)v2628, v2627, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6547);
  v2629 = (int)std_string_append(&v5897, (int)&Dst, "silk-chest1-random1.cub");
  v7813 = 1258;
  v2630 = this_4pointer_off((void *)v6, 1674);
  something_database(*(_DWORD *)v2630, v2629, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5897);
  v2631 = (int)std_string_append(&v6545, (int)&Dst, "silk-chest2-random1.cub");
  v7813 = 1259;
  v2632 = this_4pointer_off((void *)v6, 1675);
  something_database(*(_DWORD *)v2632, v2631, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6545);
  v2633 = (int)std_string_append(&v5329, (int)&Dst, "silk-chest3-random1.cub");
  v7813 = 1260;
  v2634 = this_4pointer_off((void *)v6, 1676);
  something_database(*(_DWORD *)v2634, v2633, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5329);
  v2635 = (int)std_string_append(&v6543, (int)&Dst, "silk-chest4-random1.cub");
  v7813 = 1261;
  v2636 = this_4pointer_off((void *)v6, 1677);
  something_database(*(_DWORD *)v2636, v2635, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6543);
  v2637 = (int)std_string_append(&v5895, (int)&Dst, "silk-chest5-random1.cub");
  v7813 = 1262;
  v2638 = this_4pointer_off((void *)v6, 1678);
  something_database(*(_DWORD *)v2638, v2637, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5895);
  v2639 = (int)std_string_append(&v6541, (int)&Dst, "silk-chest1-random2.cub");
  v7813 = 1263;
  v2640 = this_4pointer_off((void *)v6, 1679);
  something_database(*(_DWORD *)v2640, v2639, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6541);
  v2641 = (int)std_string_append(&v5571, (int)&Dst, "silk-chest2-random2.cub");
  v7813 = 1264;
  v2642 = this_4pointer_off((void *)v6, 1680);
  something_database(*(_DWORD *)v2642, v2641, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5571);
  v2643 = (int)std_string_append(&v6539, (int)&Dst, "silk-chest3-random2.cub");
  v7813 = 1265;
  v2644 = this_4pointer_off((void *)v6, 1681);
  something_database(*(_DWORD *)v2644, v2643, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6539);
  v2645 = (int)std_string_append(&v5893, (int)&Dst, "silk-chest4-random2.cub");
  v7813 = 1266;
  v2646 = this_4pointer_off((void *)v6, 1682);
  something_database(*(_DWORD *)v2646, v2645, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5893);
  v2647 = (int)std_string_append(&v6537, (int)&Dst, "silk-chest5-random2.cub");
  v7813 = 1267;
  v2648 = this_4pointer_off((void *)v6, 1683);
  something_database(*(_DWORD *)v2648, v2647, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6537);
  v2649 = (int)std_string_append(&v5409, (int)&Dst, "silk-chest1-random3.cub");
  v7813 = 1268;
  v2650 = this_4pointer_off((void *)v6, 1684);
  something_database(*(_DWORD *)v2650, v2649, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5409);
  v2651 = (int)std_string_append(&v6535, (int)&Dst, "silk-chest2-random3.cub");
  v7813 = 1269;
  v2652 = this_4pointer_off((void *)v6, 1685);
  something_database(*(_DWORD *)v2652, v2651, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6535);
  v2653 = (int)std_string_append(&v5891, (int)&Dst, "silk-chest3-random3.cub");
  v7813 = 1270;
  v2654 = this_4pointer_off((void *)v6, 1686);
  something_database(*(_DWORD *)v2654, v2653, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5891);
  v2655 = (int)std_string_append(&v6533, (int)&Dst, "silk-chest4-random3.cub");
  v7813 = 1271;
  v2656 = this_4pointer_off((void *)v6, 1687);
  something_database(*(_DWORD *)v2656, v2655, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6533);
  v2657 = (int)std_string_append(&v5569, (int)&Dst, "silk-chest5-random3.cub");
  v7813 = 1272;
  v2658 = this_4pointer_off((void *)v6, 1688);
  something_database(*(_DWORD *)v2658, v2657, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5569);
  v2659 = (int)std_string_append(&v6531, (int)&Dst, "silk-chest1-random4.cub");
  v7813 = 1273;
  v2660 = this_4pointer_off((void *)v6, 1689);
  something_database(*(_DWORD *)v2660, v2659, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6531);
  v2661 = (int)std_string_append(&v5889, (int)&Dst, "silk-chest2-random4.cub");
  v7813 = 1274;
  v2662 = this_4pointer_off((void *)v6, 1690);
  something_database(*(_DWORD *)v2662, v2661, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5889);
  v2663 = (int)std_string_append(&v6529, (int)&Dst, "silk-chest3-random4.cub");
  v7813 = 1275;
  v2664 = this_4pointer_off((void *)v6, 1691);
  something_database(*(_DWORD *)v2664, v2663, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6529);
  v2665 = (int)std_string_append(&v5253, (int)&Dst, "silk-chest4-random4.cub");
  v7813 = 1276;
  v2666 = this_4pointer_off((void *)v6, 1692);
  something_database(*(_DWORD *)v2666, v2665, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5253);
  v2667 = (int)std_string_append(&v7806, (int)&Dst, "silk-chest5-random4.cub");
  v7813 = 1277;
  v2668 = this_4pointer_off((void *)v6, 1693);
  something_database(*(_DWORD *)v2668, v2667, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7806);
  v2669 = (int)std_string_append(&v7805, (int)&Dst, "silk-shoulder1.cub");
  v7813 = 1278;
  v2670 = this_4pointer_off((void *)v6, 1694);
  something_database(*(_DWORD *)v2670, v2669, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7805);
  v2671 = (int)std_string_append(&v6527, (int)&Dst, "silk-shoulder2.cub");
  v7813 = 1279;
  v2672 = this_4pointer_off((void *)v6, 1695);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2671;
  something_database(*(_DWORD *)v2672, v2671, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6527);
  v2673 = (int)std_string_append(&v7804, (int)&Dst, "silk-shoulder3.cub");
  v7813 = 1280;
  v2674 = this_4pointer_off((void *)v6, 1696);
  something_database(*(_DWORD *)v2674, v2673, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7804);
  v2675 = (int)std_string_append(&v7803, (int)&Dst, "silk-shoulder4.cub");
  v7813 = 1281;
  v2676 = this_4pointer_off((void *)v6, 1697);
  something_database(*(_DWORD *)v2676, v2675, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7803);
  v2677 = (int)std_string_append(&v7802, (int)&Dst, "silk-shoulder5.cub");
  v7813 = 1282;
  v2678 = this_4pointer_off((void *)v6, 1698);
  something_database(*(_DWORD *)v2678, v2677, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7802);
  v2679 = (int)std_string_append(&v7800, (int)&Dst, "silk-shoulder1-random1.cub");
  v7813 = 1283;
  v2680 = this_4pointer_off((void *)v6, 1699);
  something_database(*(_DWORD *)v2680, v2679, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7800);
  v2681 = (int)std_string_append(&v7798, (int)&Dst, "silk-shoulder2-random1.cub");
  v7813 = 1284;
  v2682 = this_4pointer_off((void *)v6, 1700);
  something_database(*(_DWORD *)v2682, v2681, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7798);
  v2683 = (int)std_string_append(&v7796, (int)&Dst, "silk-shoulder3-random1.cub");
  v7813 = 1285;
  v2684 = this_4pointer_off((void *)v6, 1701);
  something_database(*(_DWORD *)v2684, v2683, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7796);
  v2685 = (int)std_string_append(&v7794, (int)&Dst, "silk-shoulder4-random1.cub");
  v7813 = 1286;
  v2686 = this_4pointer_off((void *)v6, 1702);
  something_database(*(_DWORD *)v2686, v2685, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7794);
  v2687 = (int)std_string_append(&v7792, (int)&Dst, "silk-shoulder5-random1.cub");
  v7813 = 1287;
  v2688 = this_4pointer_off((void *)v6, 1703);
  something_database(*(_DWORD *)v2688, v2687, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7792);
  v2689 = (int)std_string_append(&v7790, (int)&Dst, "silk-shoulder1-random2.cub");
  v7813 = 1288;
  v2690 = this_4pointer_off((void *)v6, 1704);
  something_database(*(_DWORD *)v2690, v2689, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7790);
  v2691 = (int)std_string_append(&v7788, (int)&Dst, "silk-shoulder2-random2.cub");
  v7813 = 1289;
  v2692 = this_4pointer_off((void *)v6, 1705);
  something_database(*(_DWORD *)v2692, v2691, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7788);
  v2693 = (int)std_string_append(&v7786, (int)&Dst, "silk-shoulder3-random2.cub");
  v7813 = 1290;
  v2694 = this_4pointer_off((void *)v6, 1706);
  something_database(*(_DWORD *)v2694, v2693, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7786);
  v2695 = (int)std_string_append(&v7784, (int)&Dst, "silk-shoulder4-random2.cub");
  v7813 = 1291;
  v2696 = this_4pointer_off((void *)v6, 1707);
  something_database(*(_DWORD *)v2696, v2695, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7784);
  v2697 = (int)std_string_append(&v7782, (int)&Dst, "silk-shoulder5-random2.cub");
  v7813 = 1292;
  v2698 = this_4pointer_off((void *)v6, 1708);
  something_database(*(_DWORD *)v2698, v2697, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7782);
  v2699 = (int)std_string_append(&v7780, (int)&Dst, "silk-shoulder1-random3.cub");
  v7813 = 1293;
  v2700 = this_4pointer_off((void *)v6, 1709);
  something_database(*(_DWORD *)v2700, v2699, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7780);
  v2701 = (int)std_string_append(&v7778, (int)&Dst, "silk-shoulder2-random3.cub");
  v7813 = 1294;
  v2702 = this_4pointer_off((void *)v6, 1710);
  something_database(*(_DWORD *)v2702, v2701, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7778);
  v2703 = (int)std_string_append(&v7776, (int)&Dst, "silk-shoulder3-random3.cub");
  v7813 = 1295;
  v2704 = this_4pointer_off((void *)v6, 1711);
  something_database(*(_DWORD *)v2704, v2703, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7776);
  v2705 = (int)std_string_append(&v7774, (int)&Dst, "silk-shoulder4-random3.cub");
  v7813 = 1296;
  v2706 = this_4pointer_off((void *)v6, 1712);
  something_database(*(_DWORD *)v2706, v2705, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7774);
  v2707 = (int)std_string_append(&v7772, (int)&Dst, "silk-shoulder5-random3.cub");
  v7813 = 1297;
  v2708 = this_4pointer_off((void *)v6, 1713);
  something_database(*(_DWORD *)v2708, v2707, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7772);
  v2709 = (int)std_string_append(&v7770, (int)&Dst, "silk-shoulder1-random4.cub");
  v7813 = 1298;
  v2710 = this_4pointer_off((void *)v6, 1714);
  something_database(*(_DWORD *)v2710, v2709, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7770);
  v2711 = (int)std_string_append(&v7768, (int)&Dst, "silk-shoulder2-random4.cub");
  v7813 = 1299;
  v2712 = this_4pointer_off((void *)v6, 1715);
  something_database(*(_DWORD *)v2712, v2711, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7768);
  v2713 = (int)std_string_append(&v7766, (int)&Dst, "silk-shoulder3-random4.cub");
  v7813 = 1300;
  v2714 = this_4pointer_off((void *)v6, 1716);
  something_database(*(_DWORD *)v2714, v2713, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7766);
  v2715 = (int)std_string_append(&v7764, (int)&Dst, (const char *)"silk-shoulder4-random4.cub");
  v7813 = 1301;
  v2716 = this_4pointer_off((void *)v6, 1717);
  something_database(*(_DWORD *)v2716, v2715, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7764);
  v2717 = (int)std_string_append(&v7762, (int)&Dst, "silk-shoulder5-random4.cub");
  v7813 = 1302;
  v2718 = this_4pointer_off((void *)v6, 1718);
  something_database(*(_DWORD *)v2718, v2717, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7762);
  v2719 = (int)std_string_append(&v7760, (int)&Dst, "silk-hand1.cub");
  v7813 = 1303;
  v2720 = this_4pointer_off((void *)v6, 1744);
  something_database(*(_DWORD *)v2720, v2719, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7760);
  v2721 = (int)std_string_append(&v7758, (int)&Dst, "silk-hand2.cub");
  v7813 = 1304;
  v2722 = this_4pointer_off((void *)v6, 1745);
  something_database(*(_DWORD *)v2722, v2721, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7758);
  v2723 = (int)std_string_append(&v7756, (int)&Dst, "silk-hand3.cub");
  v7813 = 1305;
  v2724 = this_4pointer_off((void *)v6, 1746);
  something_database(*(_DWORD *)v2724, v2723, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7756);
  v2725 = (int)std_string_append(&v7754, (int)&Dst, "silk-hand4.cub");
  v7813 = 1306;
  v2726 = this_4pointer_off((void *)v6, 1747);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2725;
  something_database(*(_DWORD *)v2726, v2725, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7754);
  v2727 = (int)std_string_append(&v7752, (int)&Dst, "silk-hand5.cub");
  v7813 = 1307;
  v2728 = this_4pointer_off((void *)v6, 1748);
  something_database(*(_DWORD *)v2728, v2727, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7752);
  v2729 = (int)std_string_append(&v7750, (int)&Dst, "silk-hand1-random1.cub");
  v7813 = 1308;
  v2730 = this_4pointer_off((void *)v6, 1749);
  something_database(*(_DWORD *)v2730, v2729, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7750);
  v2731 = (int)std_string_append(&v7748, (int)&Dst, "silk-hand2-random1.cub");
  v7813 = 1309;
  v2732 = this_4pointer_off((void *)v6, 1750);
  something_database(*(_DWORD *)v2732, v2731, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7748);
  v2733 = (int)std_string_append(&v7746, (int)&Dst, "silk-hand3-random1.cub");
  v7813 = 1310;
  v2734 = this_4pointer_off((void *)v6, 1751);
  something_database(*(_DWORD *)v2734, v2733, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7746);
  v2735 = (int)std_string_append(&v7744, (int)&Dst, "silk-hand4-random1.cub");
  v7813 = 1311;
  v2736 = this_4pointer_off((void *)v6, 1752);
  something_database(*(_DWORD *)v2736, v2735, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7744);
  v2737 = (int)std_string_append(&v7742, (int)&Dst, "silk-hand5-random1.cub");
  v7813 = 1312;
  v2738 = this_4pointer_off((void *)v6, 1753);
  something_database(*(_DWORD *)v2738, v2737, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7742);
  v2739 = (int)std_string_append(&v7740, (int)&Dst, "silk-hand1-random2.cub");
  v7813 = 1313;
  v2740 = this_4pointer_off((void *)v6, 1754);
  something_database(*(_DWORD *)v2740, v2739, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7740);
  v2741 = (int)std_string_append(&v7738, (int)&Dst, "silk-hand2-random2.cub");
  v7813 = 1314;
  v2742 = this_4pointer_off((void *)v6, 1755);
  something_database(*(_DWORD *)v2742, v2741, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7738);
  v2743 = (int)std_string_append(&v7736, (int)&Dst, "silk-hand3-random2.cub");
  v7813 = 1315;
  v2744 = this_4pointer_off((void *)v6, 1756);
  something_database(*(_DWORD *)v2744, v2743, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7736);
  v2745 = (int)std_string_append(&v7734, (int)&Dst, "silk-hand4-random2.cub");
  v7813 = 1316;
  v2746 = this_4pointer_off((void *)v6, 1757);
  something_database(*(_DWORD *)v2746, v2745, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7734);
  v2747 = (int)std_string_append(&v7732, (int)&Dst, "silk-hand5-random2.cub");
  v7813 = 1317;
  v2748 = this_4pointer_off((void *)v6, 1758);
  something_database(*(_DWORD *)v2748, v2747, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7732);
  v2749 = (int)std_string_append(&v7730, (int)&Dst, "silk-hand1-random3.cub");
  v7813 = 1318;
  v2750 = this_4pointer_off((void *)v6, 1759);
  something_database(*(_DWORD *)v2750, v2749, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7730);
  v2751 = (int)std_string_append(&v7728, (int)&Dst, "silk-hand2-random3.cub");
  v7813 = 1319;
  v2752 = this_4pointer_off((void *)v6, 1760);
  something_database(*(_DWORD *)v2752, v2751, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7728);
  v2753 = (int)std_string_append(&v7726, (int)&Dst, "silk-hand3-random3.cub");
  v7813 = 1320;
  v2754 = this_4pointer_off((void *)v6, 1761);
  something_database(*(_DWORD *)v2754, v2753, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7726);
  v2755 = (int)std_string_append(&v7724, (int)&Dst, "silk-hand4-random3.cub");
  v7813 = 1321;
  v2756 = this_4pointer_off((void *)v6, 1762);
  something_database(*(_DWORD *)v2756, v2755, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7724);
  v2757 = (int)std_string_append(&v7722, (int)&Dst, "silk-hand5-random3.cub");
  v7813 = 1322;
  v2758 = this_4pointer_off((void *)v6, 1763);
  something_database(*(_DWORD *)v2758, v2757, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7722);
  v2759 = (int)std_string_append(&v7720, (int)&Dst, "silk-hand1-random4.cub");
  v7813 = 1323;
  v2760 = this_4pointer_off((void *)v6, 1764);
  something_database(*(_DWORD *)v2760, v2759, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7720);
  v2761 = (int)std_string_append(&v7718, (int)&Dst, "silk-hand2-random4.cub");
  v7813 = 1324;
  v2762 = this_4pointer_off((void *)v6, 1765);
  something_database(*(_DWORD *)v2762, v2761, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7718);
  v2763 = (int)std_string_append(&v7716, (int)&Dst, "silk-hand3-random4.cub");
  v7813 = 1325;
  v2764 = this_4pointer_off((void *)v6, 1766);
  something_database(*(_DWORD *)v2764, v2763, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7716);
  v2765 = (int)std_string_append(&v7714, (int)&Dst, "silk-hand4-random4.cub");
  v7813 = 1326;
  v2766 = this_4pointer_off((void *)v6, 1767);
  something_database(*(_DWORD *)v2766, v2765, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7714);
  v2767 = (int)std_string_append(&v7712, (int)&Dst, "silk-hand5-random4.cub");
  v7813 = 1327;
  v2768 = this_4pointer_off((void *)v6, 1768);
  something_database(*(_DWORD *)v2768, v2767, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7712);
  v2769 = (int)std_string_append(&v7710, (int)&Dst, "silk-foot1.cub");
  v7813 = 1328;
  v2770 = this_4pointer_off((void *)v6, 1719);
  something_database(*(_DWORD *)v2770, v2769, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7710);
  v2771 = (int)std_string_append(&v7708, (int)&Dst, "silk-foot2.cub");
  v7813 = 1329;
  v2772 = this_4pointer_off((void *)v6, 1720);
  something_database(*(_DWORD *)v2772, v2771, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7708);
  v2773 = (int)std_string_append(&v7706, (int)&Dst, "silk-foot3.cub");
  v7813 = 1330;
  v2774 = this_4pointer_off((void *)v6, 1721);
  something_database(*(_DWORD *)v2774, v2773, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7706);
  v2775 = (int)std_string_append(&v7704, (int)&Dst, "silk-foot4.cub");
  v7813 = 1331;
  v2776 = this_4pointer_off((void *)v6, 1722);
  something_database(*(_DWORD *)v2776, v2775, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7704);
  v2777 = (int)std_string_append(&v7702, (int)&Dst, "silk-foot5.cub");
  v7813 = 1332;
  v2778 = this_4pointer_off((void *)v6, 1723);
  something_database(*(_DWORD *)v2778, v2777, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7702);
  v2779 = (int)std_string_append(&v7700, (int)&Dst, "silk-foot1-random1.cub");
  v7813 = 1333;
  v2780 = this_4pointer_off((void *)v6, 1724);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2779;
  something_database(*(_DWORD *)v2780, v2779, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7700);
  v2781 = (int)std_string_append(&v7698, (int)&Dst, "silk-foot2-random1.cub");
  v7813 = 1334;
  v2782 = this_4pointer_off((void *)v6, 1725);
  something_database(*(_DWORD *)v2782, v2781, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7698);
  v2783 = (int)std_string_append(&v7696, (int)&Dst, "silk-foot3-random1.cub");
  v7813 = 1335;
  v2784 = this_4pointer_off((void *)v6, 1726);
  something_database(*(_DWORD *)v2784, v2783, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7696);
  v2785 = (int)std_string_append(&v7694, (int)&Dst, "silk-foot4-random1.cub");
  v7813 = 1336;
  v2786 = this_4pointer_off((void *)v6, 1727);
  something_database(*(_DWORD *)v2786, v2785, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7694);
  v2787 = (int)std_string_append(&v7692, (int)&Dst, "silk-foot5-random1.cub");
  v7813 = 1337;
  v2788 = this_4pointer_off((void *)v6, 1728);
  something_database(*(_DWORD *)v2788, v2787, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7692);
  v2789 = (int)std_string_append(&v7690, (int)&Dst, "silk-foot1-random2.cub");
  v7813 = 1338;
  v2790 = this_4pointer_off((void *)v6, 1729);
  something_database(*(_DWORD *)v2790, v2789, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7690);
  v2791 = (int)std_string_append(&v7688, (int)&Dst, "silk-foot2-random2.cub");
  v7813 = 1339;
  v2792 = this_4pointer_off((void *)v6, 1730);
  something_database(*(_DWORD *)v2792, v2791, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7688);
  v2793 = (int)std_string_append(&v7686, (int)&Dst, "silk-foot3-random2.cub");
  v7813 = 1340;
  v2794 = this_4pointer_off((void *)v6, 1731);
  something_database(*(_DWORD *)v2794, v2793, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7686);
  v2795 = (int)std_string_append(&v7684, (int)&Dst, "silk-foot4-random2.cub");
  v7813 = 1341;
  v2796 = this_4pointer_off((void *)v6, 1732);
  something_database(*(_DWORD *)v2796, v2795, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7684);
  v2797 = (int)std_string_append(&v7682, (int)&Dst, "silk-foot5-random2.cub");
  v7813 = 1342;
  v2798 = this_4pointer_off((void *)v6, 1733);
  something_database(*(_DWORD *)v2798, v2797, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7682);
  v2799 = (int)std_string_append(&v7680, (int)&Dst, "silk-foot1-random3.cub");
  v7813 = 1343;
  v2800 = this_4pointer_off((void *)v6, 1734);
  something_database(*(_DWORD *)v2800, v2799, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7680);
  v2801 = (int)std_string_append(&v7678, (int)&Dst, "silk-foot2-random3.cub");
  v7813 = 1344;
  v2802 = this_4pointer_off((void *)v6, 1735);
  something_database(*(_DWORD *)v2802, v2801, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7678);
  v2803 = (int)std_string_append(&v7676, (int)&Dst, "silk-foot3-random3.cub");
  v7813 = 1345;
  v2804 = this_4pointer_off((void *)v6, 1736);
  something_database(*(_DWORD *)v2804, v2803, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7676);
  v2805 = (int)std_string_append(&v7674, (int)&Dst, "silk-foot4-random3.cub");
  v7813 = 1346;
  v2806 = this_4pointer_off((void *)v6, 1737);
  something_database(*(_DWORD *)v2806, v2805, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7674);
  v2807 = (int)std_string_append(&v7672, (int)&Dst, "silk-foot5-random3.cub");
  v7813 = 1347;
  v2808 = this_4pointer_off((void *)v6, 1738);
  something_database(*(_DWORD *)v2808, v2807, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7672);
  v2809 = (int)std_string_append(&v7670, (int)&Dst, "silk-foot1-random4.cub");
  v7813 = 1348;
  v2810 = this_4pointer_off((void *)v6, 1739);
  something_database(*(_DWORD *)v2810, v2809, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7670);
  v2811 = (int)std_string_append(&v7668, (int)&Dst, "silk-foot2-random4.cub");
  v7813 = 1349;
  v2812 = this_4pointer_off((void *)v6, 1740);
  something_database(*(_DWORD *)v2812, v2811, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7668);
  v2813 = (int)std_string_append(&v7666, (int)&Dst, "silk-foot3-random4.cub");
  v7813 = 1350;
  v2814 = this_4pointer_off((void *)v6, 1741);
  something_database(*(_DWORD *)v2814, v2813, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7666);
  v2815 = (int)std_string_append(&v7664, (int)&Dst, "silk-foot4-random4.cub");
  v7813 = 1351;
  v2816 = this_4pointer_off((void *)v6, 1742);
  something_database(*(_DWORD *)v2816, v2815, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7664);
  v2817 = (int)std_string_append(&v7662, (int)&Dst, "silk-foot5-random4.cub");
  v7813 = 1352;
  v2818 = this_4pointer_off((void *)v6, 1743);
  something_database(*(_DWORD *)v2818, v2817, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7662);
  v2819 = (int)std_string_append(&v7660, (int)&Dst, "gold-amulet1-random1.cub");
  v7813 = 1353;
  v2820 = this_4pointer_off((void *)v6, 1564);
  something_database(*(_DWORD *)v2820, v2819, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7660);
  v2821 = (int)std_string_append(&v7658, (int)&Dst, "gold-amulet2-random1.cub");
  v7813 = 1354;
  v2822 = this_4pointer_off((void *)v6, 1565);
  something_database(*(_DWORD *)v2822, v2821, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7658);
  v2823 = (int)std_string_append(&v7656, (int)&Dst, "gold-amulet3-random1.cub");
  v7813 = 1355;
  v2824 = this_4pointer_off((void *)v6, 1566);
  something_database(*(_DWORD *)v2824, v2823, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7656);
  v2825 = (int)std_string_append(&v7654, (int)&Dst, "gold-amulet4-random1.cub");
  v7813 = 1356;
  v2826 = this_4pointer_off((void *)v6, 1567);
  something_database(*(_DWORD *)v2826, v2825, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7654);
  v2827 = (int)std_string_append(&v7652, (int)&Dst, "gold-amulet5-random1.cub");
  v7813 = 1357;
  v2828 = this_4pointer_off((void *)v6, 1568);
  something_database(*(_DWORD *)v2828, v2827, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7652);
  v2829 = (int)std_string_append(&v7650, (int)&Dst, "gold-amulet1-random2.cub");
  v7813 = 1358;
  v2830 = this_4pointer_off((void *)v6, 1569);
  something_database(*(_DWORD *)v2830, v2829, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7650);
  v2831 = (int)std_string_append(&v7648, (int)&Dst, "gold-amulet2-random2.cub");
  v7813 = 1359;
  v2832 = this_4pointer_off((void *)v6, 1570);
  something_database(*(_DWORD *)v2832, v2831, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7648);
  v2833 = (int)std_string_append(&v7646, (int)&Dst, "gold-amulet3-random2.cub");
  v7813 = 1360;
  v2834 = this_4pointer_off((void *)v6, 1571);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2833;
  something_database(*(_DWORD *)v2834, v2833, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7646);
  v2835 = (int)std_string_append(&v7644, (int)&Dst, "gold-amulet4-random2.cub");
  v7813 = 1361;
  v2836 = this_4pointer_off((void *)v6, 1572);
  something_database(*(_DWORD *)v2836, v2835, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7644);
  v2837 = (int)std_string_append(&v7642, (int)&Dst, "gold-amulet5-random2.cub");
  v7813 = 1362;
  v2838 = this_4pointer_off((void *)v6, 1573);
  something_database(*(_DWORD *)v2838, v2837, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7642);
  v2839 = (int)std_string_append(&v7640, (int)&Dst, "gold-amulet1-random3.cub");
  v7813 = 1363;
  v2840 = this_4pointer_off((void *)v6, 1574);
  something_database(*(_DWORD *)v2840, v2839, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7640);
  v2841 = (int)std_string_append(&v7638, (int)&Dst, "gold-amulet2-random3.cub");
  v7813 = 1364;
  v2842 = this_4pointer_off((void *)v6, 1575);
  something_database(*(_DWORD *)v2842, v2841, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7638);
  v2843 = (int)std_string_append(&v7636, (int)&Dst, "gold-amulet3-random3.cub");
  v7813 = 1365;
  v2844 = this_4pointer_off((void *)v6, 1576);
  something_database(*(_DWORD *)v2844, v2843, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7636);
  v2845 = (int)std_string_append(&v7634, (int)&Dst, "gold-amulet4-random3.cub");
  v7813 = 1366;
  v2846 = this_4pointer_off((void *)v6, 1577);
  something_database(*(_DWORD *)v2846, v2845, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7634);
  v2847 = (int)std_string_append(&v7632, (int)&Dst, (const char *)"gold-amulet5-random3.cub");
  v7813 = 1367;
  v2848 = this_4pointer_off((void *)v6, 1578);
  something_database(*(_DWORD *)v2848, v2847, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7632);
  v2849 = (int)std_string_append(&v7630, (int)&Dst, "gold-amulet1-random4.cub");
  v7813 = 1368;
  v2850 = this_4pointer_off((void *)v6, 1579);
  something_database(*(_DWORD *)v2850, v2849, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7630);
  v2851 = (int)std_string_append(&v7628, (int)&Dst, "gold-amulet2-random4.cub");
  v7813 = 1369;
  v2852 = this_4pointer_off((void *)v6, 1580);
  something_database(*(_DWORD *)v2852, v2851, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7628);
  v2853 = (int)std_string_append(&v7626, (int)&Dst, "gold-amulet3-random4.cub");
  v7813 = 1370;
  v2854 = this_4pointer_off((void *)v6, 1581);
  something_database(*(_DWORD *)v2854, v2853, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7626);
  v2855 = (int)std_string_append(&v7624, (int)&Dst, "gold-amulet4-random4.cub");
  v7813 = 1371;
  v2856 = this_4pointer_off((void *)v6, 1582);
  something_database(*(_DWORD *)v2856, v2855, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7624);
  v2857 = (int)std_string_append(&v7622, (int)&Dst, "gold-amulet5-random4.cub");
  v7813 = 1372;
  v2858 = this_4pointer_off((void *)v6, 1583);
  something_database(*(_DWORD *)v2858, v2857, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7622);
  v2859 = (int)std_string_append(&v7620, (int)&Dst, "gold-amulet1-random5.cub");
  v7813 = 1373;
  v2860 = this_4pointer_off((void *)v6, 1584);
  something_database(*(_DWORD *)v2860, v2859, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7620);
  v2861 = (int)std_string_append(&v7618, (int)&Dst, "gold-amulet2-random5.cub");
  v7813 = 1374;
  v2862 = this_4pointer_off((void *)v6, 1585);
  something_database(*(_DWORD *)v2862, v2861, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7618);
  v2863 = (int)std_string_append(&v7616, (int)&Dst, "gold-amulet3-random5.cub");
  v7813 = 1375;
  v2864 = this_4pointer_off((void *)v6, 1586);
  something_database(*(_DWORD *)v2864, v2863, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7616);
  v2865 = (int)std_string_append(&v7614, (int)&Dst, "gold-amulet4-random5.cub");
  v7813 = 1376;
  v2866 = this_4pointer_off((void *)v6, 1587);
  something_database(*(_DWORD *)v2866, v2865, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7614);
  v2867 = (int)std_string_append(&v7612, (int)&Dst, "gold-amulet5-random5.cub");
  v7813 = 1377;
  v2868 = this_4pointer_off((void *)v6, 1588);
  something_database(*(_DWORD *)v2868, v2867, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7612);
  v2869 = (int)std_string_append(&v7610, (int)&Dst, "silver-amulet1-random1.cub");
  v7813 = 1378;
  v2870 = this_4pointer_off((void *)v6, 1594);
  something_database(*(_DWORD *)v2870, v2869, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7610);
  v2871 = (int)std_string_append(&v7608, (int)&Dst, "silver-amulet2-random1.cub");
  v7813 = 1379;
  v2872 = this_4pointer_off((void *)v6, 1595);
  something_database(*(_DWORD *)v2872, v2871, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7608);
  v2873 = (int)std_string_append(&v7606, (int)&Dst, "silver-amulet3-random1.cub");
  v7813 = 1380;
  v2874 = this_4pointer_off((void *)v6, 1596);
  something_database(*(_DWORD *)v2874, v2873, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7606);
  v2875 = (int)std_string_append(&v7604, (int)&Dst, "silver-amulet4-random1.cub");
  v7813 = 1381;
  v2876 = this_4pointer_off((void *)v6, 1597);
  something_database(*(_DWORD *)v2876, v2875, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7604);
  v2877 = (int)std_string_append(&v7602, (int)&Dst, "silver-amulet5-random1.cub");
  v7813 = 1382;
  v2878 = this_4pointer_off((void *)v6, 1598);
  something_database(*(_DWORD *)v2878, v2877, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7602);
  v2879 = (int)std_string_append(&v7600, (int)&Dst, "silver-amulet1-random2.cub");
  v7813 = 1383;
  v2880 = this_4pointer_off((void *)v6, 1599);
  something_database(*(_DWORD *)v2880, v2879, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7600);
  v2881 = (int)std_string_append(&v7598, (int)&Dst, "silver-amulet2-random2.cub");
  v7813 = 1384;
  v2882 = this_4pointer_off((void *)v6, 1600);
  something_database(*(_DWORD *)v2882, v2881, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7598);
  v2883 = (int)std_string_append(&v7596, (int)&Dst, "silver-amulet3-random2.cub");
  v7813 = 1385;
  v2884 = this_4pointer_off((void *)v6, 1601);
  something_database(*(_DWORD *)v2884, v2883, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7596);
  v2885 = (int)std_string_append(&v7594, (int)&Dst, "silver-amulet4-random2.cub");
  v7813 = 1386;
  v2886 = this_4pointer_off((void *)v6, 1602);
  something_database(*(_DWORD *)v2886, v2885, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7594);
  v2887 = (int)std_string_append(&v7592, (int)&Dst, "silver-amulet5-random2.cub");
  v7813 = 1387;
  v2888 = this_4pointer_off((void *)v6, 1603);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2887;
  something_database(*(_DWORD *)v2888, v2887, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7592);
  v2889 = (int)std_string_append(&v7590, (int)&Dst, "silver-amulet1-random3.cub");
  v7813 = 1388;
  v2890 = this_4pointer_off((void *)v6, 1604);
  something_database(*(_DWORD *)v2890, v2889, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7590);
  v2891 = (int)std_string_append(&v7588, (int)&Dst, "silver-amulet2-random3.cub");
  v7813 = 1389;
  v2892 = this_4pointer_off((void *)v6, 1605);
  something_database(*(_DWORD *)v2892, v2891, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7588);
  v2893 = (int)std_string_append(&v7586, (int)&Dst, "silver-amulet3-random3.cub");
  v7813 = 1390;
  v2894 = this_4pointer_off((void *)v6, 1606);
  something_database(*(_DWORD *)v2894, v2893, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7586);
  v2895 = (int)std_string_append(&v7584, (int)&Dst, "silver-amulet4-random3.cub");
  v7813 = 1391;
  v2896 = this_4pointer_off((void *)v6, 1607);
  something_database(*(_DWORD *)v2896, v2895, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7584);
  v2897 = (int)std_string_append(&v7582, (int)&Dst, "silver-amulet5-random3.cub");
  v7813 = 1392;
  v2898 = this_4pointer_off((void *)v6, 1608);
  something_database(*(_DWORD *)v2898, v2897, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7582);
  v2899 = (int)std_string_append(&v7580, (int)&Dst, "silver-amulet1-random4.cub");
  v7813 = 1393;
  v2900 = this_4pointer_off((void *)v6, 1609);
  something_database(*(_DWORD *)v2900, v2899, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7580);
  v2901 = (int)std_string_append(&v7578, (int)&Dst, "silver-amulet2-random4.cub");
  v7813 = 1394;
  v2902 = this_4pointer_off((void *)v6, 1610);
  something_database(*(_DWORD *)v2902, v2901, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7578);
  v2903 = (int)std_string_append(&v7576, (int)&Dst, "silver-amulet3-random4.cub");
  v7813 = 1395;
  v2904 = this_4pointer_off((void *)v6, 1611);
  something_database(*(_DWORD *)v2904, v2903, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7576);
  v2905 = (int)std_string_append(&v7574, (int)&Dst, "silver-amulet4-random4.cub");
  v7813 = 1396;
  v2906 = this_4pointer_off((void *)v6, 1612);
  something_database(*(_DWORD *)v2906, v2905, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7574);
  v2907 = (int)std_string_append(&v7572, (int)&Dst, "silver-amulet5-random4.cub");
  v7813 = 1397;
  v2908 = this_4pointer_off((void *)v6, 1613);
  something_database(*(_DWORD *)v2908, v2907, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7572);
  v2909 = (int)std_string_append(&v7570, (int)&Dst, "silver-amulet1-random5.cub");
  v7813 = 1398;
  v2910 = this_4pointer_off((void *)v6, 1614);
  something_database(*(_DWORD *)v2910, v2909, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7570);
  v2911 = (int)std_string_append(&v7568, (int)&Dst, "silver-amulet2-random5.cub");
  v7813 = 1399;
  v2912 = this_4pointer_off((void *)v6, 1615);
  something_database(*(_DWORD *)v2912, v2911, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7568);
  v2913 = (int)std_string_append(&v7566, (int)&Dst, "silver-amulet3-random5.cub");
  v7813 = 1400;
  v2914 = this_4pointer_off((void *)v6, 1616);
  something_database(*(_DWORD *)v2914, v2913, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7566);
  v2915 = (int)std_string_append(&v7564, (int)&Dst, "silver-amulet4-random5.cub");
  v7813 = 1401;
  v2916 = this_4pointer_off((void *)v6, 1617);
  something_database(*(_DWORD *)v2916, v2915, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7564);
  v2917 = (int)std_string_append(&v7562, (int)&Dst, "silver-amulet5-random5.cub");
  v7813 = 1402;
  v2918 = this_4pointer_off((void *)v6, 1618);
  something_database(*(_DWORD *)v2918, v2917, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7562);
  v2919 = (int)std_string_append(&v7560, (int)&Dst, "gold-ring1-random1.cub");
  v7813 = 1403;
  v2920 = this_4pointer_off((void *)v6, 1619);
  something_database(*(_DWORD *)v2920, v2919, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7560);
  v2921 = (int)std_string_append(&v7558, (int)&Dst, "gold-ring2-random1.cub");
  v7813 = 1404;
  v2922 = this_4pointer_off((void *)v6, 1620);
  something_database(*(_DWORD *)v2922, v2921, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7558);
  v2923 = (int)std_string_append(&v7556, (int)&Dst, "gold-ring3-random1.cub");
  v7813 = 1405;
  v2924 = this_4pointer_off((void *)v6, 1621);
  something_database(*(_DWORD *)v2924, v2923, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7556);
  v2925 = (int)std_string_append(&v7554, (int)&Dst, "gold-ring4-random1.cub");
  v7813 = 1406;
  v2926 = this_4pointer_off((void *)v6, 1622);
  something_database(*(_DWORD *)v2926, v2925, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7554);
  v2927 = (int)std_string_append(&v7552, (int)&Dst, "gold-ring5-random1.cub");
  v7813 = 1407;
  v2928 = this_4pointer_off((void *)v6, 1623);
  something_database(*(_DWORD *)v2928, v2927, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7552);
  v2929 = (int)std_string_append(&v7550, (int)&Dst, "gold-ring1-random2.cub");
  v7813 = 1408;
  v2930 = this_4pointer_off((void *)v6, 1624);
  something_database(*(_DWORD *)v2930, v2929, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7550);
  v2931 = (int)std_string_append(&v7548, (int)&Dst, (const char *)"gold-ring2-random2.cub");
  v7813 = 1409;
  v2932 = this_4pointer_off((void *)v6, 1625);
  something_database(*(_DWORD *)v2932, v2931, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7548);
  v2933 = (int)std_string_append(&v7546, (int)&Dst, "gold-ring3-random2.cub");
  v7813 = 1410;
  v2934 = this_4pointer_off((void *)v6, 1626);
  something_database(*(_DWORD *)v2934, v2933, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7546);
  v2935 = (int)std_string_append(&v7544, (int)&Dst, "gold-ring4-random2.cub");
  v7813 = 1411;
  v2936 = this_4pointer_off((void *)v6, 1627);
  something_database(*(_DWORD *)v2936, v2935, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7544);
  v2937 = (int)std_string_append(&v7542, (int)&Dst, "gold-ring5-random2.cub");
  v7813 = 1412;
  v2938 = this_4pointer_off((void *)v6, 1628);
  something_database(*(_DWORD *)v2938, v2937, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7542);
  v2939 = (int)std_string_append(&v7540, (int)&Dst, "gold-ring1-random3.cub");
  v7813 = 1413;
  v2940 = this_4pointer_off((void *)v6, 1629);
  something_database(*(_DWORD *)v2940, v2939, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7540);
  v2941 = (int)std_string_append(&v7538, (int)&Dst, "gold-ring2-random3.cub");
  v7813 = 1414;
  v2942 = this_4pointer_off((void *)v6, 1630);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2941;
  something_database(*(_DWORD *)v2942, v2941, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7538);
  v2943 = (int)std_string_append(&v7536, (int)&Dst, "gold-ring3-random3.cub");
  v7813 = 1415;
  v2944 = this_4pointer_off((void *)v6, 1631);
  something_database(*(_DWORD *)v2944, v2943, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7536);
  v2945 = (int)std_string_append(&v7534, (int)&Dst, "gold-ring4-random3.cub");
  v7813 = 1416;
  v2946 = this_4pointer_off((void *)v6, 1632);
  something_database(*(_DWORD *)v2946, v2945, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7534);
  v2947 = (int)std_string_append(&v7532, (int)&Dst, "gold-ring5-random3.cub");
  v7813 = 1417;
  v2948 = this_4pointer_off((void *)v6, 1633);
  something_database(*(_DWORD *)v2948, v2947, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7532);
  v2949 = (int)std_string_append(&v7530, (int)&Dst, "gold-ring1-random4.cub");
  v7813 = 1418;
  v2950 = this_4pointer_off((void *)v6, 1634);
  something_database(*(_DWORD *)v2950, v2949, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7530);
  v2951 = (int)std_string_append(&v7528, (int)&Dst, "gold-ring2-random4.cub");
  v7813 = 1419;
  v2952 = this_4pointer_off((void *)v6, 1635);
  something_database(*(_DWORD *)v2952, v2951, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7528);
  v2953 = (int)std_string_append(&v7526, (int)&Dst, "gold-ring3-random4.cub");
  v7813 = 1420;
  v2954 = this_4pointer_off((void *)v6, 1636);
  something_database(*(_DWORD *)v2954, v2953, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7526);
  v2955 = (int)std_string_append(&v7524, (int)&Dst, "gold-ring4-random4.cub");
  v7813 = 1421;
  v2956 = this_4pointer_off((void *)v6, 1637);
  something_database(*(_DWORD *)v2956, v2955, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7524);
  v2957 = (int)std_string_append(&v7522, (int)&Dst, "gold-ring5-random4.cub");
  v7813 = 1422;
  v2958 = this_4pointer_off((void *)v6, 1638);
  something_database(*(_DWORD *)v2958, v2957, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7522);
  v2959 = (int)std_string_append(&v7520, (int)&Dst, "gold-ring1-random5.cub");
  v7813 = 1423;
  v2960 = this_4pointer_off((void *)v6, 1639);
  something_database(*(_DWORD *)v2960, v2959, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7520);
  v2961 = (int)std_string_append(&v7518, (int)&Dst, "gold-ring2-random5.cub");
  v7813 = 1424;
  v2962 = this_4pointer_off((void *)v6, 1640);
  something_database(*(_DWORD *)v2962, v2961, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7518);
  v2963 = (int)std_string_append(&v7516, (int)&Dst, "gold-ring3-random5.cub");
  v7813 = 1425;
  v2964 = this_4pointer_off((void *)v6, 1641);
  something_database(*(_DWORD *)v2964, v2963, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7516);
  v2965 = (int)std_string_append(&v7514, (int)&Dst, "gold-ring4-random5.cub");
  v7813 = 1426;
  v2966 = this_4pointer_off((void *)v6, 1642);
  something_database(*(_DWORD *)v2966, v2965, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7514);
  v2967 = (int)std_string_append(&v7512, (int)&Dst, "gold-ring5-random5.cub");
  v7813 = 1427;
  v2968 = this_4pointer_off((void *)v6, 1643);
  something_database(*(_DWORD *)v2968, v2967, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7512);
  v2969 = (int)std_string_append(&v7510, (int)&Dst, "silver-ring1-random1.cub");
  v7813 = 1428;
  v2970 = this_4pointer_off((void *)v6, 1644);
  something_database(*(_DWORD *)v2970, v2969, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7510);
  v2971 = (int)std_string_append(&v7508, (int)&Dst, "silver-ring2-random1.cub");
  v7813 = 1429;
  v2972 = this_4pointer_off((void *)v6, 1645);
  something_database(*(_DWORD *)v2972, v2971, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7508);
  v2973 = (int)std_string_append(&v7506, (int)&Dst, "silver-ring3-random1.cub");
  v7813 = 1430;
  v2974 = this_4pointer_off((void *)v6, 1646);
  something_database(*(_DWORD *)v2974, v2973, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7506);
  v2975 = (int)std_string_append(&v7504, (int)&Dst, "silver-ring4-random1.cub");
  v7813 = 1431;
  v2976 = this_4pointer_off((void *)v6, 1647);
  something_database(*(_DWORD *)v2976, v2975, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7504);
  v2977 = (int)std_string_append(&v7502, (int)&Dst, "silver-ring5-random1.cub");
  v7813 = 1432;
  v2978 = this_4pointer_off((void *)v6, 1648);
  something_database(*(_DWORD *)v2978, v2977, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7502);
  v2979 = (int)std_string_append(&v7500, (int)&Dst, "silver-ring1-random2.cub");
  v7813 = 1433;
  v2980 = this_4pointer_off((void *)v6, 1649);
  something_database(*(_DWORD *)v2980, v2979, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7500);
  v2981 = (int)std_string_append(&v7498, (int)&Dst, "silver-ring2-random2.cub");
  v7813 = 1434;
  v2982 = this_4pointer_off((void *)v6, 1650);
  something_database(*(_DWORD *)v2982, v2981, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7498);
  v2983 = (int)std_string_append(&v7496, (int)&Dst, "silver-ring3-random2.cub");
  v7813 = 1435;
  v2984 = this_4pointer_off((void *)v6, 1651);
  something_database(*(_DWORD *)v2984, v2983, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7496);
  v2985 = (int)std_string_append(&v7494, (int)&Dst, "silver-ring4-random2.cub");
  v7813 = 1436;
  v2986 = this_4pointer_off((void *)v6, 1652);
  something_database(*(_DWORD *)v2986, v2985, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7494);
  v2987 = (int)std_string_append(&v7492, (int)&Dst, "silver-ring5-random2.cub");
  v7813 = 1437;
  v2988 = this_4pointer_off((void *)v6, 1653);
  something_database(*(_DWORD *)v2988, v2987, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7492);
  v2989 = (int)std_string_append(&v7490, (int)&Dst, "silver-ring1-random3.cub");
  v7813 = 1438;
  v2990 = this_4pointer_off((void *)v6, 1654);
  something_database(*(_DWORD *)v2990, v2989, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7490);
  v2991 = (int)std_string_append(&v7488, (int)&Dst, "silver-ring2-random3.cub");
  v7813 = 1439;
  v2992 = this_4pointer_off((void *)v6, 1655);
  something_database(*(_DWORD *)v2992, v2991, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7488);
  v2993 = (int)std_string_append(&v7486, (int)&Dst, "silver-ring3-random3.cub");
  v7813 = 1440;
  v2994 = this_4pointer_off((void *)v6, 1656);
  something_database(*(_DWORD *)v2994, v2993, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7486);
  v2995 = (int)std_string_append(&v7484, (int)&Dst, "silver-ring4-random3.cub");
  v7813 = 1441;
  v2996 = this_4pointer_off((void *)v6, 1657);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v2995;
  something_database(*(_DWORD *)v2996, v2995, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7484);
  v2997 = (int)std_string_append(&v7482, (int)&Dst, "silver-ring5-random3.cub");
  v7813 = 1442;
  v2998 = this_4pointer_off((void *)v6, 1658);
  something_database(*(_DWORD *)v2998, v2997, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7482);
  v2999 = (int)std_string_append(&v7480, (int)&Dst, "silver-ring1-random4.cub");
  v7813 = 1443;
  v3000 = this_4pointer_off((void *)v6, 1659);
  something_database(*(_DWORD *)v3000, v2999, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7480);
  v3001 = (int)std_string_append(&v7478, (int)&Dst, "silver-ring2-random4.cub");
  v7813 = 1444;
  v3002 = this_4pointer_off((void *)v6, 1660);
  something_database(*(_DWORD *)v3002, v3001, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7478);
  v3003 = (int)std_string_append(&v7476, (int)&Dst, "silver-ring3-random4.cub");
  v7813 = 1445;
  v3004 = this_4pointer_off((void *)v6, 1661);
  something_database(*(_DWORD *)v3004, v3003, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7476);
  v3005 = (int)std_string_append(&v7474, (int)&Dst, (const char *)"silver-ring4-random4.cub");
  v7813 = 1446;
  v3006 = this_4pointer_off((void *)v6, 1662);
  something_database(*(_DWORD *)v3006, v3005, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7474);
  v3007 = (int)std_string_append(&v7472, (int)&Dst, "silver-ring5-random4.cub");
  v7813 = 1447;
  v3008 = this_4pointer_off((void *)v6, 1663);
  something_database(*(_DWORD *)v3008, v3007, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7472);
  v3009 = (int)std_string_append(&v7470, (int)&Dst, "silver-ring1-random5.cub");
  v7813 = 1448;
  v3010 = this_4pointer_off((void *)v6, 1664);
  something_database(*(_DWORD *)v3010, v3009, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7470);
  v3011 = (int)std_string_append(&v7468, (int)&Dst, "silver-ring2-random5.cub");
  v7813 = 1449;
  v3012 = this_4pointer_off((void *)v6, 1665);
  something_database(*(_DWORD *)v3012, v3011, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7468);
  v3013 = (int)std_string_append(&v7466, (int)&Dst, "silver-ring3-random5.cub");
  v7813 = 1450;
  v3014 = this_4pointer_off((void *)v6, 1666);
  something_database(*(_DWORD *)v3014, v3013, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7466);
  v3015 = (int)std_string_append(&v7464, (int)&Dst, "silver-ring4-random5.cub");
  v7813 = 1451;
  v3016 = this_4pointer_off((void *)v6, 1667);
  something_database(*(_DWORD *)v3016, v3015, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7464);
  v3017 = (int)std_string_append(&v7462, (int)&Dst, "silver-ring5-random5.cub");
  v7813 = 1452;
  v3018 = this_4pointer_off((void *)v6, 1668);
  something_database(*(_DWORD *)v3018, v3017, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7462);
  v3019 = (int)std_string_append(&v7460, (int)&Dst, "parrot-feather.cub");
  v7813 = 1453;
  v3020 = this_4pointer_off((void *)v6, 2366);
  something_database(*(_DWORD *)v3020, v3019, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7460);
  v3021 = (int)std_string_append(&v7458, (int)&Dst, "parrot-beak.cub");
  v7813 = 1454;
  v3022 = this_4pointer_off((void *)v6, 2367);
  something_database(*(_DWORD *)v3022, v3021, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7458);
  v3023 = (int)std_string_append(&v7456, (int)&Dst, "mammoth-chest.cub");
  v7813 = 1455;
  v3024 = this_4pointer_off((void *)v6, 2375);
  something_database(*(_DWORD *)v3024, v3023, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7456);
  v3025 = (int)std_string_append(&v7454, (int)&Dst, "mammoth-shoulder.cub");
  v7813 = 1456;
  v3026 = this_4pointer_off((void *)v6, 2378);
  something_database(*(_DWORD *)v3026, v3025, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7454);
  v3027 = (int)std_string_append(&v7452, (int)&Dst, "mammoth-boot.cub");
  v7813 = 1457;
  v3028 = this_4pointer_off((void *)v6, 2376);
  something_database(*(_DWORD *)v3028, v3027, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7452);
  v3029 = (int)std_string_append(&v7450, (int)&Dst, "mammoth-glove.cub");
  v7813 = 1458;
  v3030 = this_4pointer_off((void *)v6, 2374);
  something_database(*(_DWORD *)v3030, v3029, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7450);
  v3031 = (int)std_string_append(&v7448, (int)&Dst, "mammoth-helmet.cub");
  v7813 = 1459;
  v3032 = this_4pointer_off((void *)v6, 2377);
  something_database(*(_DWORD *)v3032, v3031, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7448);
  v3033 = (int)std_string_append(&v7446, (int)&Dst, "mammoth-hair.cub");
  v7813 = 1460;
  v3034 = this_4pointer_off((void *)v6, 2373);
  something_database(*(_DWORD *)v3034, v3033, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7446);
  v3035 = (int)std_string_append(&v7444, (int)&Dst, "flask.cub");
  v7813 = 1461;
  v3036 = this_4pointer_off((void *)v6, 2389);
  something_database(*(_DWORD *)v3036, v3035, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7444);
  v3037 = (int)std_string_append(&v7442, (int)&Dst, "water-flask.cub");
  v7813 = 1462;
  v3038 = this_4pointer_off((void *)v6, 2390);
  something_database(*(_DWORD *)v3038, v3037, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7442);
  v3039 = (int)std_string_append(&v7440, (int)&Dst, "radish-slice.cub");
  v7813 = 1463;
  v3040 = this_4pointer_off((void *)v6, 2391);
  something_database(*(_DWORD *)v3040, v3039, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7440);
  v3041 = (int)std_string_append(&v7438, (int)&Dst, "onion-slice.cub");
  v7813 = 1464;
  v3042 = this_4pointer_off((void *)v6, 2392);
  something_database(*(_DWORD *)v3042, v3041, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7438);
  v3043 = (int)std_string_append(&v7436, (int)&Dst, "plant-fiber.cub");
  v7813 = 1465;
  v3044 = this_4pointer_off((void *)v6, 2394);
  something_database(*(_DWORD *)v3044, v3043, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7436);
  v3045 = (int)std_string_append(&v7434, (int)&Dst, "soup-ginseng.cub");
  v7813 = 1466;
  v3046 = this_4pointer_off((void *)v6, 2395);
  something_database(*(_DWORD *)v3046, v3045, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7434);
  v3047 = (int)std_string_append(&v7432, (int)&Dst, "mushroom-spit.cub");
  v7813 = 1467;
  v3048 = this_4pointer_off((void *)v6, 2393);
  something_database(*(_DWORD *)v3048, v3047, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7432);
  v3049 = (int)std_string_append(&v7430, (int)&Dst, "obsidian-sword.cub");
  v7813 = 1468;
  v3050 = this_4pointer_off((void *)v6, 2059);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3049;
  something_database(*(_DWORD *)v3050, v3049, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7430);
  v3051 = (int)std_string_append(&v7428, (int)&Dst, "bone-chest.cub");
  v7813 = 1469;
  v3052 = this_4pointer_off((void *)v6, 2067);
  something_database(*(_DWORD *)v3052, v3051, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7428);
  v3053 = (int)std_string_append(&v7426, (int)&Dst, "bone-shoulders.cub");
  v7813 = 1470;
  v3054 = this_4pointer_off((void *)v6, 2068);
  something_database(*(_DWORD *)v3054, v3053, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7426);
  v3055 = (int)std_string_append(&v7424, (int)&Dst, "bone-boot.cub");
  v7813 = 1471;
  v3056 = this_4pointer_off((void *)v6, 2069);
  something_database(*(_DWORD *)v3056, v3055, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7424);
  v3057 = (int)std_string_append(&v7422, (int)&Dst, "bone-glove.cub");
  v7813 = 1472;
  v3058 = this_4pointer_off((void *)v6, 2070);
  something_database(*(_DWORD *)v3058, v3057, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7422);
  v3059 = (int)std_string_append(&v7420, (int)&Dst, "bone-mace.cub");
  v7813 = 1473;
  v3060 = this_4pointer_off((void *)v6, 2073);
  something_database(*(_DWORD *)v3060, v3059, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7420);
  v3061 = (int)std_string_append(&v7418, (int)&Dst, "bone-sword.cub");
  v7813 = 1474;
  v3062 = this_4pointer_off((void *)v6, 2072);
  something_database(*(_DWORD *)v3062, v3061, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7418);
  v3063 = (int)std_string_append(&v7416, (int)&Dst, "bone-axe.cub");
  v7813 = 1475;
  v3064 = this_4pointer_off((void *)v6, 2074);
  something_database(*(_DWORD *)v3064, v3063, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7416);
  v3065 = (int)std_string_append(&v7414, (int)&Dst, "iron-chest1.cub");
  v7813 = 1476;
  v3066 = this_4pointer_off((void *)v6, 1124);
  something_database(*(_DWORD *)v3066, v3065, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7414);
  v3067 = (int)std_string_append(&v7412, (int)&Dst, "iron-chest2.cub");
  v7813 = 1477;
  v3068 = this_4pointer_off((void *)v6, 1125);
  something_database(*(_DWORD *)v3068, v3067, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7412);
  v3069 = (int)std_string_append(&v7410, (int)&Dst, "iron-chest3.cub");
  v7813 = 1478;
  v3070 = this_4pointer_off((void *)v6, 1126);
  something_database(*(_DWORD *)v3070, v3069, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7410);
  v3071 = (int)std_string_append(&v7408, (int)&Dst, "iron-chest4.cub");
  v7813 = 1479;
  v3072 = this_4pointer_off((void *)v6, 1127);
  something_database(*(_DWORD *)v3072, v3071, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7408);
  v3073 = (int)std_string_append(&v7406, (int)&Dst, "iron-chest5.cub");
  v7813 = 1480;
  v3074 = this_4pointer_off((void *)v6, 1128);
  something_database(*(_DWORD *)v3074, v3073, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7406);
  v3075 = (int)std_string_append(&v7404, (int)&Dst, "iron-chest1-random1.cub");
  v7813 = 1481;
  v3076 = this_4pointer_off((void *)v6, 1129);
  something_database(*(_DWORD *)v3076, v3075, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7404);
  v3077 = (int)std_string_append(&v7402, (int)&Dst, "iron-chest2-random1.cub");
  v7813 = 1482;
  v3078 = this_4pointer_off((void *)v6, 1130);
  something_database(*(_DWORD *)v3078, v3077, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7402);
  v3079 = (int)std_string_append(&v7400, (int)&Dst, "iron-chest3-random1.cub");
  v7813 = 1483;
  v3080 = this_4pointer_off((void *)v6, 1131);
  something_database(*(_DWORD *)v3080, v3079, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7400);
  v3081 = (int)std_string_append(&v7398, (int)&Dst, "iron-chest4-random1.cub");
  v7813 = 1484;
  v3082 = this_4pointer_off((void *)v6, 1132);
  something_database(*(_DWORD *)v3082, v3081, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7398);
  v3083 = (int)std_string_append(&v7396, (int)&Dst, "iron-chest5-random1.cub");
  v7813 = 1485;
  v3084 = this_4pointer_off((void *)v6, 1133);
  something_database(*(_DWORD *)v3084, v3083, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7396);
  v3085 = (int)std_string_append(&v7394, (int)&Dst, "iron-chest1-random2.cub");
  v7813 = 1486;
  v3086 = this_4pointer_off((void *)v6, 1134);
  something_database(*(_DWORD *)v3086, v3085, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7394);
  v3087 = (int)std_string_append(&v7392, (int)&Dst, "iron-chest2-random2.cub");
  v7813 = 1487;
  v3088 = this_4pointer_off((void *)v6, 1135);
  something_database(*(_DWORD *)v3088, v3087, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7392);
  v3089 = (int)std_string_append(&v7390, (int)&Dst, "iron-chest3-random2.cub");
  v7813 = 1488;
  v3090 = this_4pointer_off((void *)v6, 1136);
  something_database(*(_DWORD *)v3090, v3089, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7390);
  v3091 = (int)std_string_append(&v7388, (int)&Dst, "iron-chest4-random2.cub");
  v7813 = 1489;
  v3092 = this_4pointer_off((void *)v6, 1137);
  something_database(*(_DWORD *)v3092, v3091, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7388);
  v3093 = (int)std_string_append(&v7386, (int)&Dst, "iron-chest5-random2.cub");
  v7813 = 1490;
  v3094 = this_4pointer_off((void *)v6, 1138);
  something_database(*(_DWORD *)v3094, v3093, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7386);
  v3095 = (int)std_string_append(&v7384, (int)&Dst, "iron-chest1-random3.cub");
  v7813 = 1491;
  v3096 = this_4pointer_off((void *)v6, 1139);
  something_database(*(_DWORD *)v3096, v3095, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7384);
  v3097 = (int)std_string_append(&v7382, (int)&Dst, "iron-chest2-random3.cub");
  v7813 = 1492;
  v3098 = this_4pointer_off((void *)v6, 1140);
  something_database(*(_DWORD *)v3098, v3097, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7382);
  v3099 = (int)std_string_append(&v7380, (int)&Dst, "iron-chest3-random3.cub");
  v7813 = 1493;
  v3100 = this_4pointer_off((void *)v6, 1141);
  something_database(*(_DWORD *)v3100, v3099, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7380);
  v3101 = (int)std_string_append(&v7378, (int)&Dst, "iron-chest4-random3.cub");
  v7813 = 1494;
  v3102 = this_4pointer_off((void *)v6, 1142);
  something_database(*(_DWORD *)v3102, v3101, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7378);
  v3103 = (int)std_string_append(&v7376, (int)&Dst, "iron-chest5-random3.cub");
  v7813 = 1495;
  v3104 = this_4pointer_off((void *)v6, 1143);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3103;
  something_database(*(_DWORD *)v3104, v3103, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7376);
  v3105 = (int)std_string_append(&v7374, (int)&Dst, "iron-chest1-random4.cub");
  v7813 = 1496;
  v3106 = this_4pointer_off((void *)v6, 1144);
  something_database(*(_DWORD *)v3106, v3105, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7374);
  v3107 = (int)std_string_append(&v7372, (int)&Dst, "iron-chest2-random4.cub");
  v7813 = 1497;
  v3108 = this_4pointer_off((void *)v6, 1145);
  something_database(*(_DWORD *)v3108, v3107, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7372);
  v3109 = (int)std_string_append(&v7370, (int)&Dst, "iron-chest3-random4.cub");
  v7813 = 1498;
  v3110 = this_4pointer_off((void *)v6, 1146);
  something_database(*(_DWORD *)v3110, v3109, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7370);
  v3111 = (int)std_string_append(&v7368, (int)&Dst, "iron-chest4-random4.cub");
  v7813 = 1499;
  v3112 = this_4pointer_off((void *)v6, 1147);
  something_database(*(_DWORD *)v3112, v3111, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7368);
  v3113 = (int)std_string_append(&v7366, (int)&Dst, "iron-chest5-random4.cub");
  v7813 = 1500;
  v3114 = this_4pointer_off((void *)v6, 1148);
  something_database(*(_DWORD *)v3114, v3113, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7366);
  v3115 = (int)std_string_append(&v7364, (int)&Dst, "iron-shoulder1.cub");
  v7813 = 1501;
  v3116 = this_4pointer_off((void *)v6, 1149);
  something_database(*(_DWORD *)v3116, v3115, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7364);
  v3117 = (int)std_string_append(&v7362, (int)&Dst, "iron-shoulder2.cub");
  v7813 = 1502;
  v3118 = this_4pointer_off((void *)v6, 1150);
  something_database(*(_DWORD *)v3118, v3117, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7362);
  v3119 = (int)std_string_append(&v7360, (int)&Dst, "iron-shoulder3.cub");
  v7813 = 1503;
  v3120 = this_4pointer_off((void *)v6, 1151);
  something_database(*(_DWORD *)v3120, v3119, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7360);
  v3121 = (int)std_string_append(&v7358, (int)&Dst, "iron-shoulder4.cub");
  v7813 = 1504;
  v3122 = this_4pointer_off((void *)v6, 1152);
  something_database(*(_DWORD *)v3122, v3121, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7358);
  v3123 = (int)std_string_append(&v7356, (int)&Dst, "iron-shoulder5.cub");
  v7813 = 1505;
  v3124 = this_4pointer_off((void *)v6, 1153);
  something_database(*(_DWORD *)v3124, v3123, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7356);
  v3125 = (int)std_string_append(&v7354, (int)&Dst, "iron-shoulder1-random1.cub");
  v7813 = 1506;
  v3126 = this_4pointer_off((void *)v6, 1154);
  something_database(*(_DWORD *)v3126, v3125, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7354);
  v3127 = (int)std_string_append(&v7352, (int)&Dst, "iron-shoulder2-random1.cub");
  v7813 = 1507;
  v3128 = this_4pointer_off((void *)v6, 1155);
  something_database(*(_DWORD *)v3128, v3127, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7352);
  v3129 = (int)std_string_append(&v7350, (int)&Dst, "iron-shoulder3-random1.cub");
  v7813 = 1508;
  v3130 = this_4pointer_off((void *)v6, 1156);
  something_database(*(_DWORD *)v3130, v3129, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7350);
  v3131 = (int)std_string_append(&v7348, (int)&Dst, "iron-shoulder4-random1.cub");
  v7813 = 1509;
  v3132 = this_4pointer_off((void *)v6, 1157);
  something_database(*(_DWORD *)v3132, v3131, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7348);
  v3133 = (int)std_string_append(&v7346, (int)&Dst, "iron-shoulder5-random1.cub");
  v7813 = 1510;
  v3134 = this_4pointer_off((void *)v6, 1158);
  something_database(*(_DWORD *)v3134, v3133, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7346);
  v3135 = (int)std_string_append(&v7344, (int)&Dst, "iron-shoulder1-random2.cub");
  v7813 = 1511;
  v3136 = this_4pointer_off((void *)v6, 1159);
  something_database(*(_DWORD *)v3136, v3135, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7344);
  v3137 = (int)std_string_append(&v7342, (int)&Dst, "iron-shoulder2-random2.cub");
  v7813 = 1512;
  v3138 = this_4pointer_off((void *)v6, 1160);
  something_database(*(_DWORD *)v3138, v3137, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7342);
  v3139 = (int)std_string_append(&v7340, (int)&Dst, "iron-shoulder3-random2.cub");
  v7813 = 1513;
  v3140 = this_4pointer_off((void *)v6, 1161);
  something_database(*(_DWORD *)v3140, v3139, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7340);
  v3141 = (int)std_string_append(&v7338, (int)&Dst, "iron-shoulder4-random2.cub");
  v7813 = 1514;
  v3142 = this_4pointer_off((void *)v6, 1162);
  something_database(*(_DWORD *)v3142, v3141, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7338);
  v3143 = (int)std_string_append(&v7336, (int)&Dst, "iron-shoulder5-random2.cub");
  v7813 = 1515;
  v3144 = this_4pointer_off((void *)v6, 1163);
  something_database(*(_DWORD *)v3144, v3143, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7336);
  v3145 = (int)std_string_append(&v7334, (int)&Dst, "iron-shoulder1-random3.cub");
  v7813 = 1516;
  v3146 = this_4pointer_off((void *)v6, 1164);
  something_database(*(_DWORD *)v3146, v3145, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7334);
  v3147 = (int)std_string_append(&v7332, (int)&Dst, "iron-shoulder2-random3.cub");
  v7813 = 1517;
  v3148 = this_4pointer_off((void *)v6, 1165);
  something_database(*(_DWORD *)v3148, v3147, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7332);
  v3149 = (int)std_string_append(&v7330, (int)&Dst, "iron-shoulder3-random3.cub");
  v7813 = 1518;
  v3150 = this_4pointer_off((void *)v6, 1166);
  something_database(*(_DWORD *)v3150, v3149, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7330);
  v3151 = (int)std_string_append(&v7328, (int)&Dst, "iron-shoulder4-random3.cub");
  v7813 = 1519;
  v3152 = this_4pointer_off((void *)v6, 1167);
  something_database(*(_DWORD *)v3152, v3151, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7328);
  v3153 = (int)std_string_append(&v7326, (int)&Dst, "iron-shoulder5-random3.cub");
  v7813 = 1520;
  v3154 = this_4pointer_off((void *)v6, 1168);
  something_database(*(_DWORD *)v3154, v3153, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7326);
  v3155 = (int)std_string_append(&v7324, (int)&Dst, "iron-shoulder1-random4.cub");
  v7813 = 1521;
  v3156 = this_4pointer_off((void *)v6, 1169);
  something_database(*(_DWORD *)v3156, v3155, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7324);
  v3157 = (int)std_string_append(&v7322, (int)&Dst, "iron-shoulder2-random4.cub");
  v7813 = 1522;
  v3158 = this_4pointer_off((void *)v6, 1170);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3157;
  something_database(*(_DWORD *)v3158, v3157, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7322);
  v3159 = (int)std_string_append(&v7320, (int)&Dst, "iron-shoulder3-random4.cub");
  v7813 = 1523;
  v3160 = this_4pointer_off((void *)v6, 1171);
  something_database(*(_DWORD *)v3160, v3159, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7320);
  v3161 = (int)std_string_append(&v7318, (int)&Dst, "iron-shoulder4-random4.cub");
  v7813 = 1524;
  v3162 = this_4pointer_off((void *)v6, 1172);
  something_database(*(_DWORD *)v3162, v3161, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7318);
  v3163 = (int)std_string_append(&v7316, (int)&Dst, "iron-shoulder5-random4.cub");
  v7813 = 1525;
  v3164 = this_4pointer_off((void *)v6, 1173);
  something_database(*(_DWORD *)v3164, v3163, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7316);
  v3165 = (int)std_string_append(&v7314, (int)&Dst, "iron-hand1.cub");
  v7813 = 1526;
  v3166 = this_4pointer_off((void *)v6, 1174);
  something_database(*(_DWORD *)v3166, v3165, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7314);
  v3167 = (int)std_string_append(&v7312, (int)&Dst, "iron-hand2.cub");
  v7813 = 1527;
  v3168 = this_4pointer_off((void *)v6, 1175);
  something_database(*(_DWORD *)v3168, v3167, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7312);
  v3169 = (int)std_string_append(&v7310, (int)&Dst, "iron-hand3.cub");
  v7813 = 1528;
  v3170 = this_4pointer_off((void *)v6, 1176);
  something_database(*(_DWORD *)v3170, v3169, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7310);
  v3171 = (int)std_string_append(&v7308, (int)&Dst, "iron-hand4.cub");
  v7813 = 1529;
  v3172 = this_4pointer_off((void *)v6, 1177);
  something_database(*(_DWORD *)v3172, v3171, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7308);
  v3173 = (int)std_string_append(&v7306, (int)&Dst, "iron-hand5.cub");
  v7813 = 1530;
  v3174 = this_4pointer_off((void *)v6, 1178);
  something_database(*(_DWORD *)v3174, v3173, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7306);
  v3175 = (int)std_string_append(&v7304, (int)&Dst, "iron-hand1-random1.cub");
  v7813 = 1531;
  v3176 = this_4pointer_off((void *)v6, 1179);
  something_database(*(_DWORD *)v3176, v3175, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7304);
  v3177 = (int)std_string_append(&v7302, (int)&Dst, "iron-hand2-random1.cub");
  v7813 = 1532;
  v3178 = this_4pointer_off((void *)v6, 1180);
  something_database(*(_DWORD *)v3178, v3177, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7302);
  v3179 = (int)std_string_append(&v7300, (int)&Dst, "iron-hand3-random1.cub");
  v7813 = 1533;
  v3180 = this_4pointer_off((void *)v6, 1181);
  something_database(*(_DWORD *)v3180, v3179, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7300);
  v3181 = (int)std_string_append(&v7298, (int)&Dst, "iron-hand4-random1.cub");
  v7813 = 1534;
  v3182 = this_4pointer_off((void *)v6, 1182);
  something_database(*(_DWORD *)v3182, v3181, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7298);
  v3183 = (int)std_string_append(&v7296, (int)&Dst, "iron-hand5-random1.cub");
  v7813 = 1535;
  v3184 = this_4pointer_off((void *)v6, 1183);
  something_database(*(_DWORD *)v3184, v3183, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7296);
  v3185 = (int)std_string_append(&v7294, (int)&Dst, "iron-hand1-random2.cub");
  v7813 = 1536;
  v3186 = this_4pointer_off((void *)v6, 1184);
  something_database(*(_DWORD *)v3186, v3185, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7294);
  v3187 = (int)std_string_append(&v7292, (int)&Dst, "iron-hand2-random2.cub");
  v7813 = 1537;
  v3188 = this_4pointer_off((void *)v6, 1185);
  something_database(*(_DWORD *)v3188, v3187, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7292);
  v3189 = (int)std_string_append(&v7290, (int)&Dst, "iron-hand3-random2.cub");
  v7813 = 1538;
  v3190 = this_4pointer_off((void *)v6, 1186);
  something_database(*(_DWORD *)v3190, v3189, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7290);
  v3191 = (int)std_string_append(&v7288, (int)&Dst, "iron-hand4-random2.cub");
  v7813 = 1539;
  v3192 = this_4pointer_off((void *)v6, 1187);
  something_database(*(_DWORD *)v3192, v3191, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7288);
  v3193 = (int)std_string_append(&v7286, (int)&Dst, "iron-hand5-random2.cub");
  v7813 = 1540;
  v3194 = this_4pointer_off((void *)v6, 1188);
  something_database(*(_DWORD *)v3194, v3193, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7286);
  v3195 = (int)std_string_append(&v7284, (int)&Dst, "iron-hand1-random3.cub");
  v7813 = 1541;
  v3196 = this_4pointer_off((void *)v6, 1189);
  something_database(*(_DWORD *)v3196, v3195, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7284);
  v3197 = (int)std_string_append(&v7282, (int)&Dst, "iron-hand2-random3.cub");
  v7813 = 1542;
  v3198 = this_4pointer_off((void *)v6, 1190);
  something_database(*(_DWORD *)v3198, v3197, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7282);
  v3199 = (int)std_string_append(&v7280, (int)&Dst, "iron-hand3-random3.cub");
  v7813 = 1543;
  v3200 = this_4pointer_off((void *)v6, 1191);
  something_database(*(_DWORD *)v3200, v3199, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7280);
  v3201 = (int)std_string_append(&v7278, (int)&Dst, "iron-hand4-random3.cub");
  v7813 = 1544;
  v3202 = this_4pointer_off((void *)v6, 1192);
  something_database(*(_DWORD *)v3202, v3201, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7278);
  v3203 = (int)std_string_append(&v7276, (int)&Dst, "iron-hand5-random3.cub");
  v7813 = 1545;
  v3204 = this_4pointer_off((void *)v6, 1193);
  something_database(*(_DWORD *)v3204, v3203, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7276);
  v3205 = (int)std_string_append(&v7274, (int)&Dst, "iron-hand1-random4.cub");
  v7813 = 1546;
  v3206 = this_4pointer_off((void *)v6, 1194);
  something_database(*(_DWORD *)v3206, v3205, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7274);
  v3207 = (int)std_string_append(&v7272, (int)&Dst, "iron-hand2-random4.cub");
  v7813 = 1547;
  v3208 = this_4pointer_off((void *)v6, 1195);
  something_database(*(_DWORD *)v3208, v3207, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7272);
  v3209 = (int)std_string_append(&v7270, (int)&Dst, "iron-hand3-random4.cub");
  v7813 = 1548;
  v3210 = this_4pointer_off((void *)v6, 1196);
  something_database(*(_DWORD *)v3210, v3209, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7270);
  v3211 = (int)std_string_append(&v7268, (int)&Dst, "iron-hand4-random4.cub");
  v7813 = 1549;
  v3212 = this_4pointer_off((void *)v6, 1197);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3211;
  something_database(*(_DWORD *)v3212, v3211, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7268);
  v3213 = (int)std_string_append(&v7266, (int)&Dst, "iron-hand5-random4.cub");
  v7813 = 1550;
  v3214 = this_4pointer_off((void *)v6, 1198);
  something_database(*(_DWORD *)v3214, v3213, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7266);
  v3215 = (int)std_string_append(&v7264, (int)&Dst, "iron-foot1.cub");
  v7813 = 1551;
  v3216 = this_4pointer_off((void *)v6, 1199);
  something_database(*(_DWORD *)v3216, v3215, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7264);
  v3217 = (int)std_string_append(&v7262, (int)&Dst, "iron-foot2.cub");
  v7813 = 1552;
  v3218 = this_4pointer_off((void *)v6, 1200);
  something_database(*(_DWORD *)v3218, v3217, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7262);
  v3219 = (int)std_string_append(&v7260, (int)&Dst, "iron-foot3.cub");
  v7813 = 1553;
  v3220 = this_4pointer_off((void *)v6, 1201);
  something_database(*(_DWORD *)v3220, v3219, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7260);
  v3221 = (int)std_string_append(&v7258, (int)&Dst, "iron-foot4.cub");
  v7813 = 1554;
  v3222 = this_4pointer_off((void *)v6, 1202);
  something_database(*(_DWORD *)v3222, v3221, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7258);
  v3223 = (int)std_string_append(&v7256, (int)&Dst, "iron-foot5.cub");
  v7813 = 1555;
  v3224 = this_4pointer_off((void *)v6, 1203);
  something_database(*(_DWORD *)v3224, v3223, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7256);
  v3225 = (int)std_string_append(&v7254, (int)&Dst, "iron-foot1-random1.cub");
  v7813 = 1556;
  v3226 = this_4pointer_off((void *)v6, 1204);
  something_database(*(_DWORD *)v3226, v3225, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7254);
  v3227 = (int)std_string_append(&v7252, (int)&Dst, "iron-foot2-random1.cub");
  v7813 = 1557;
  v3228 = this_4pointer_off((void *)v6, 1205);
  something_database(*(_DWORD *)v3228, v3227, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7252);
  v3229 = (int)std_string_append(&v7250, (int)&Dst, "iron-foot3-random1.cub");
  v7813 = 1558;
  v3230 = this_4pointer_off((void *)v6, 1206);
  something_database(*(_DWORD *)v3230, v3229, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7250);
  v3231 = (int)std_string_append(&v7248, (int)&Dst, "iron-foot4-random1.cub");
  v7813 = 1559;
  v3232 = this_4pointer_off((void *)v6, 1207);
  something_database(*(_DWORD *)v3232, v3231, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7248);
  v3233 = (int)std_string_append(&v7246, (int)&Dst, "iron-foot5-random1.cub");
  v7813 = 1560;
  v3234 = this_4pointer_off((void *)v6, 1208);
  something_database(*(_DWORD *)v3234, v3233, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7246);
  v3235 = (int)std_string_append(&v7244, (int)&Dst, "iron-foot1-random2.cub");
  v7813 = 1561;
  v3236 = this_4pointer_off((void *)v6, 1209);
  something_database(*(_DWORD *)v3236, v3235, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7244);
  v3237 = (int)std_string_append(&v7242, (int)&Dst, "iron-foot2-random2.cub");
  v7813 = 1562;
  v3238 = this_4pointer_off((void *)v6, 1210);
  something_database(*(_DWORD *)v3238, v3237, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7242);
  v3239 = (int)std_string_append(&v7240, (int)&Dst, "iron-foot3-random2.cub");
  v7813 = 1563;
  v3240 = this_4pointer_off((void *)v6, 1211);
  something_database(*(_DWORD *)v3240, v3239, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7240);
  v3241 = (int)std_string_append(&v7238, (int)&Dst, "iron-foot4-random2.cub");
  v7813 = 1564;
  v3242 = this_4pointer_off((void *)v6, 1212);
  something_database(*(_DWORD *)v3242, v3241, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7238);
  v3243 = (int)std_string_append(&v7236, (int)&Dst, "iron-foot5-random2.cub");
  v7813 = 1565;
  v3244 = this_4pointer_off((void *)v6, 1213);
  something_database(*(_DWORD *)v3244, v3243, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7236);
  v3245 = (int)std_string_append(&v7234, (int)&Dst, "iron-foot1-random3.cub");
  v7813 = 1566;
  v3246 = this_4pointer_off((void *)v6, 1214);
  something_database(*(_DWORD *)v3246, v3245, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7234);
  v3247 = (int)std_string_append(&v7232, (int)&Dst, "iron-foot2-random3.cub");
  v7813 = 1567;
  v3248 = this_4pointer_off((void *)v6, 1215);
  something_database(*(_DWORD *)v3248, v3247, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7232);
  v3249 = (int)std_string_append(&v7230, (int)&Dst, "iron-foot3-random3.cub");
  v7813 = 1568;
  v3250 = this_4pointer_off((void *)v6, 1216);
  something_database(*(_DWORD *)v3250, v3249, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7230);
  v3251 = (int)std_string_append(&v7228, (int)&Dst, "iron-foot4-random3.cub");
  v7813 = 1569;
  v3252 = this_4pointer_off((void *)v6, 1217);
  something_database(*(_DWORD *)v3252, v3251, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7228);
  v3253 = (int)std_string_append(&v7226, (int)&Dst, "iron-foot5-random3.cub");
  v7813 = 1570;
  v3254 = this_4pointer_off((void *)v6, 1218);
  something_database(*(_DWORD *)v3254, v3253, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7226);
  v3255 = (int)std_string_append(&v7224, (int)&Dst, "iron-foot1-random4.cub");
  v7813 = 1571;
  v3256 = this_4pointer_off((void *)v6, 1219);
  something_database(*(_DWORD *)v3256, v3255, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7224);
  v3257 = (int)std_string_append(&v7222, (int)&Dst, "iron-foot2-random4.cub");
  v7813 = 1572;
  v3258 = this_4pointer_off((void *)v6, 1220);
  something_database(*(_DWORD *)v3258, v3257, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7222);
  v3259 = (int)std_string_append(&v7220, (int)&Dst, "iron-foot3-random4.cub");
  v7813 = 1573;
  v3260 = this_4pointer_off((void *)v6, 1221);
  something_database(*(_DWORD *)v3260, v3259, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7220);
  v3261 = (int)std_string_append(&v7218, (int)&Dst, "iron-foot4-random4.cub");
  v7813 = 1574;
  v3262 = this_4pointer_off((void *)v6, 1222);
  something_database(*(_DWORD *)v3262, v3261, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7218);
  v3263 = (int)std_string_append(&v7216, (int)&Dst, "iron-foot5-random4.cub");
  v7813 = 1575;
  v3264 = this_4pointer_off((void *)v6, 1223);
  something_database(*(_DWORD *)v3264, v3263, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7216);
  v3265 = (int)std_string_append(&v7214, (int)&Dst, "linen-chest1.cub");
  v7813 = 1576;
  v3266 = this_4pointer_off((void *)v6, 1359);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3265;
  something_database(*(_DWORD *)v3266, v3265, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7214);
  v3267 = (int)std_string_append(&v7212, (int)&Dst, "linen-chest2.cub");
  v7813 = 1577;
  v3268 = this_4pointer_off((void *)v6, 1360);
  something_database(*(_DWORD *)v3268, v3267, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7212);
  v3269 = (int)std_string_append(&v7210, (int)&Dst, "linen-chest3.cub");
  v7813 = 1578;
  v3270 = this_4pointer_off((void *)v6, 1361);
  something_database(*(_DWORD *)v3270, v3269, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7210);
  v3271 = (int)std_string_append(&v7208, (int)&Dst, "linen-chest4.cub");
  v7813 = 1579;
  v3272 = this_4pointer_off((void *)v6, 1362);
  something_database(*(_DWORD *)v3272, v3271, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7208);
  v3273 = (int)std_string_append(&v7206, (int)&Dst, "linen-chest5.cub");
  v7813 = 1580;
  v3274 = this_4pointer_off((void *)v6, 1363);
  something_database(*(_DWORD *)v3274, v3273, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7206);
  v3275 = (int)std_string_append(&v7204, (int)&Dst, "linen-chest1-random1.cub");
  v7813 = 1581;
  v3276 = this_4pointer_off((void *)v6, 1364);
  something_database(*(_DWORD *)v3276, v3275, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7204);
  v3277 = (int)std_string_append(&v7202, (int)&Dst, "linen-chest2-random1.cub");
  v7813 = 1582;
  v3278 = this_4pointer_off((void *)v6, 1365);
  something_database(*(_DWORD *)v3278, v3277, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7202);
  v3279 = (int)std_string_append(&v7200, (int)&Dst, "linen-chest3-random1.cub");
  v7813 = 1583;
  v3280 = this_4pointer_off((void *)v6, 1366);
  something_database(*(_DWORD *)v3280, v3279, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7200);
  v3281 = (int)std_string_append(&v7198, (int)&Dst, "linen-chest4-random1.cub");
  v7813 = 1584;
  v3282 = this_4pointer_off((void *)v6, 1367);
  something_database(*(_DWORD *)v3282, v3281, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7198);
  v3283 = (int)std_string_append(&v7196, (int)&Dst, "linen-chest5-random1.cub");
  v7813 = 1585;
  v3284 = this_4pointer_off((void *)v6, 1368);
  something_database(*(_DWORD *)v3284, v3283, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7196);
  v3285 = (int)std_string_append(&v7194, (int)&Dst, "linen-chest1-random2.cub");
  v7813 = 1586;
  v3286 = this_4pointer_off((void *)v6, 1369);
  something_database(*(_DWORD *)v3286, v3285, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7194);
  v3287 = (int)std_string_append(&v7192, (int)&Dst, "linen-chest2-random2.cub");
  v7813 = 1587;
  v3288 = this_4pointer_off((void *)v6, 1370);
  something_database(*(_DWORD *)v3288, v3287, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7192);
  v3289 = (int)std_string_append(&v7190, (int)&Dst, (const char *)"linen-chest3-random2.cub");
  v7813 = 1588;
  v3290 = this_4pointer_off((void *)v6, 1371);
  something_database(*(_DWORD *)v3290, v3289, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7190);
  v3291 = (int)std_string_append(&v7188, (int)&Dst, "linen-chest4-random2.cub");
  v7813 = 1589;
  v3292 = this_4pointer_off((void *)v6, 1372);
  something_database(*(_DWORD *)v3292, v3291, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7188);
  v3293 = (int)std_string_append(&v7186, (int)&Dst, "linen-chest5-random2.cub");
  v7813 = 1590;
  v3294 = this_4pointer_off((void *)v6, 1373);
  something_database(*(_DWORD *)v3294, v3293, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7186);
  v3295 = (int)std_string_append(&v7184, (int)&Dst, "linen-chest1-random3.cub");
  v7813 = 1591;
  v3296 = this_4pointer_off((void *)v6, 1374);
  something_database(*(_DWORD *)v3296, v3295, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7184);
  v3297 = (int)std_string_append(&v7182, (int)&Dst, "linen-chest2-random3.cub");
  v7813 = 1592;
  v3298 = this_4pointer_off((void *)v6, 1375);
  something_database(*(_DWORD *)v3298, v3297, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7182);
  v3299 = (int)std_string_append(&v7180, (int)&Dst, "linen-chest3-random3.cub");
  v7813 = 1593;
  v3300 = this_4pointer_off((void *)v6, 1376);
  something_database(*(_DWORD *)v3300, v3299, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7180);
  v3301 = (int)std_string_append(&v7178, (int)&Dst, "linen-chest4-random3.cub");
  v7813 = 1594;
  v3302 = this_4pointer_off((void *)v6, 1377);
  something_database(*(_DWORD *)v3302, v3301, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7178);
  v3303 = (int)std_string_append(&v7176, (int)&Dst, "linen-chest5-random3.cub");
  v7813 = 1595;
  v3304 = this_4pointer_off((void *)v6, 1378);
  something_database(*(_DWORD *)v3304, v3303, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7176);
  v3305 = (int)std_string_append(&v7174, (int)&Dst, "linen-chest1-random4.cub");
  v7813 = 1596;
  v3306 = this_4pointer_off((void *)v6, 1379);
  something_database(*(_DWORD *)v3306, v3305, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7174);
  v3307 = (int)std_string_append(&v7172, (int)&Dst, "linen-chest2-random4.cub");
  v7813 = 1597;
  v3308 = this_4pointer_off((void *)v6, 1380);
  something_database(*(_DWORD *)v3308, v3307, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7172);
  v3309 = (int)std_string_append(&v7170, (int)&Dst, "linen-chest3-random4.cub");
  v7813 = 1598;
  v3310 = this_4pointer_off((void *)v6, 1381);
  something_database(*(_DWORD *)v3310, v3309, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7170);
  v3311 = (int)std_string_append(&v7168, (int)&Dst, "linen-chest4-random4.cub");
  v7813 = 1599;
  v3312 = this_4pointer_off((void *)v6, 1382);
  something_database(*(_DWORD *)v3312, v3311, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7168);
  v3313 = (int)std_string_append(&v7166, (int)&Dst, "linen-chest5-random4.cub");
  v7813 = 1600;
  v3314 = this_4pointer_off((void *)v6, 1383);
  something_database(*(_DWORD *)v3314, v3313, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7166);
  v3315 = (int)std_string_append(&v7164, (int)&Dst, "linen-shoulder1.cub");
  v7813 = 1601;
  v3316 = this_4pointer_off((void *)v6, 1384);
  something_database(*(_DWORD *)v3316, v3315, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7164);
  v3317 = (int)std_string_append(&v7162, (int)&Dst, "linen-shoulder2.cub");
  v7813 = 1602;
  v3318 = this_4pointer_off((void *)v6, 1385);
  something_database(*(_DWORD *)v3318, v3317, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7162);
  v3319 = (int)std_string_append(&v7160, (int)&Dst, "linen-shoulder3.cub");
  v7813 = 1603;
  v3320 = this_4pointer_off((void *)v6, 1386);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3319;
  something_database(*(_DWORD *)v3320, v3319, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7160);
  v3321 = (int)std_string_append(&v7158, (int)&Dst, "linen-shoulder4.cub");
  v7813 = 1604;
  v3322 = this_4pointer_off((void *)v6, 1387);
  something_database(*(_DWORD *)v3322, v3321, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7158);
  v3323 = (int)std_string_append(&v7156, (int)&Dst, "linen-shoulder5.cub");
  v7813 = 1605;
  v3324 = this_4pointer_off((void *)v6, 1388);
  something_database(*(_DWORD *)v3324, v3323, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7156);
  v3325 = (int)std_string_append(&v7154, (int)&Dst, "linen-shoulder1-random1.cub");
  v7813 = 1606;
  v3326 = this_4pointer_off((void *)v6, 1389);
  something_database(*(_DWORD *)v3326, v3325, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7154);
  v3327 = (int)std_string_append(&v7152, (int)&Dst, "linen-shoulder2-random1.cub");
  v7813 = 1607;
  v3328 = this_4pointer_off((void *)v6, 1390);
  something_database(*(_DWORD *)v3328, v3327, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7152);
  v3329 = (int)std_string_append(&v7150, (int)&Dst, "linen-shoulder3-random1.cub");
  v7813 = 1608;
  v3330 = this_4pointer_off((void *)v6, 1391);
  something_database(*(_DWORD *)v3330, v3329, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7150);
  v3331 = (int)std_string_append(&v7148, (int)&Dst, "linen-shoulder4-random1.cub");
  v7813 = 1609;
  v3332 = this_4pointer_off((void *)v6, 1392);
  something_database(*(_DWORD *)v3332, v3331, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7148);
  v3333 = (int)std_string_append(&v7146, (int)&Dst, "linen-shoulder5-random1.cub");
  v7813 = 1610;
  v3334 = this_4pointer_off((void *)v6, 1393);
  something_database(*(_DWORD *)v3334, v3333, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7146);
  v3335 = (int)std_string_append(&v7144, (int)&Dst, "linen-shoulder1-random2.cub");
  v7813 = 1611;
  v3336 = this_4pointer_off((void *)v6, 1394);
  something_database(*(_DWORD *)v3336, v3335, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7144);
  v3337 = (int)std_string_append(&v7142, (int)&Dst, "linen-shoulder2-random2.cub");
  v7813 = 1612;
  v3338 = this_4pointer_off((void *)v6, 1395);
  something_database(*(_DWORD *)v3338, v3337, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7142);
  v3339 = (int)std_string_append(&v7140, (int)&Dst, "linen-shoulder3-random2.cub");
  v7813 = 1613;
  v3340 = this_4pointer_off((void *)v6, 1396);
  something_database(*(_DWORD *)v3340, v3339, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7140);
  v3341 = (int)std_string_append(&v7138, (int)&Dst, (const char *)"linen-shoulder4-random2.cub");
  v7813 = 1614;
  v3342 = this_4pointer_off((void *)v6, 1397);
  something_database(*(_DWORD *)v3342, v3341, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7138);
  v3343 = (int)std_string_append(&v7136, (int)&Dst, "linen-shoulder5-random2.cub");
  v7813 = 1615;
  v3344 = this_4pointer_off((void *)v6, 1398);
  something_database(*(_DWORD *)v3344, v3343, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7136);
  v3345 = (int)std_string_append(&v7134, (int)&Dst, "linen-shoulder1-random3.cub");
  v7813 = 1616;
  v3346 = this_4pointer_off((void *)v6, 1399);
  something_database(*(_DWORD *)v3346, v3345, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7134);
  v3347 = (int)std_string_append(&v7132, (int)&Dst, "linen-shoulder2-random3.cub");
  v7813 = 1617;
  v3348 = this_4pointer_off((void *)v6, 1400);
  something_database(*(_DWORD *)v3348, v3347, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7132);
  v3349 = (int)std_string_append(&v7130, (int)&Dst, "linen-shoulder3-random3.cub");
  v7813 = 1618;
  v3350 = this_4pointer_off((void *)v6, 1401);
  something_database(*(_DWORD *)v3350, v3349, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7130);
  v3351 = (int)std_string_append(&v7128, (int)&Dst, "linen-shoulder4-random3.cub");
  v7813 = 1619;
  v3352 = this_4pointer_off((void *)v6, 1402);
  something_database(*(_DWORD *)v3352, v3351, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7128);
  v3353 = (int)std_string_append(&v7126, (int)&Dst, "linen-shoulder5-random3.cub");
  v7813 = 1620;
  v3354 = this_4pointer_off((void *)v6, 1403);
  something_database(*(_DWORD *)v3354, v3353, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7126);
  v3355 = (int)std_string_append(&v7124, (int)&Dst, "linen-shoulder1-random4.cub");
  v7813 = 1621;
  v3356 = this_4pointer_off((void *)v6, 1404);
  something_database(*(_DWORD *)v3356, v3355, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7124);
  v3357 = (int)std_string_append(&v7122, (int)&Dst, "linen-shoulder2-random4.cub");
  v7813 = 1622;
  v3358 = this_4pointer_off((void *)v6, 1405);
  something_database(*(_DWORD *)v3358, v3357, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7122);
  v3359 = (int)std_string_append(&v7120, (int)&Dst, "linen-shoulder3-random4.cub");
  v7813 = 1623;
  v3360 = this_4pointer_off((void *)v6, 1406);
  something_database(*(_DWORD *)v3360, v3359, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7120);
  v3361 = (int)std_string_append(&v7118, (int)&Dst, "linen-shoulder4-random4.cub");
  v7813 = 1624;
  v3362 = this_4pointer_off((void *)v6, 1407);
  something_database(*(_DWORD *)v3362, v3361, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7118);
  v3363 = (int)std_string_append(&v7116, (int)&Dst, "linen-shoulder5-random4.cub");
  v7813 = 1625;
  v3364 = this_4pointer_off((void *)v6, 1408);
  something_database(*(_DWORD *)v3364, v3363, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7116);
  v3365 = (int)std_string_append(&v7114, (int)&Dst, "linen-hand1.cub");
  v7813 = 1626;
  v3366 = this_4pointer_off((void *)v6, 1434);
  something_database(*(_DWORD *)v3366, v3365, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7114);
  v3367 = (int)std_string_append(&v7112, (int)&Dst, "linen-hand2.cub");
  v7813 = 1627;
  v3368 = this_4pointer_off((void *)v6, 1435);
  something_database(*(_DWORD *)v3368, v3367, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7112);
  v3369 = (int)std_string_append(&v7110, (int)&Dst, "linen-hand3.cub");
  v7813 = 1628;
  v3370 = this_4pointer_off((void *)v6, 1436);
  something_database(*(_DWORD *)v3370, v3369, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7110);
  v3371 = (int)std_string_append(&v7108, (int)&Dst, "linen-hand4.cub");
  v7813 = 1629;
  v3372 = this_4pointer_off((void *)v6, 1437);
  something_database(*(_DWORD *)v3372, v3371, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7108);
  v3373 = (int)std_string_append(&v7106, (int)&Dst, "linen-hand5.cub");
  v7813 = 1630;
  v3374 = this_4pointer_off((void *)v6, 1438);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3373;
  something_database(*(_DWORD *)v3374, v3373, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7106);
  v3375 = (int)std_string_append(&v7104, (int)&Dst, "linen-hand1-random1.cub");
  v7813 = 1631;
  v3376 = this_4pointer_off((void *)v6, 1439);
  something_database(*(_DWORD *)v3376, v3375, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7104);
  v3377 = (int)std_string_append(&v7102, (int)&Dst, "linen-hand2-random1.cub");
  v7813 = 1632;
  v3378 = this_4pointer_off((void *)v6, 1440);
  something_database(*(_DWORD *)v3378, v3377, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7102);
  v3379 = (int)std_string_append(&v7100, (int)&Dst, "linen-hand3-random1.cub");
  v7813 = 1633;
  v3380 = this_4pointer_off((void *)v6, 1441);
  something_database(*(_DWORD *)v3380, v3379, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7100);
  v3381 = (int)std_string_append(&v7098, (int)&Dst, "linen-hand4-random1.cub");
  v7813 = 1634;
  v3382 = this_4pointer_off((void *)v6, 1442);
  something_database(*(_DWORD *)v3382, v3381, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7098);
  v3383 = (int)std_string_append(&v7096, (int)&Dst, "linen-hand5-random1.cub");
  v7813 = 1635;
  v3384 = this_4pointer_off((void *)v6, 1443);
  something_database(*(_DWORD *)v3384, v3383, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7096);
  v3385 = (int)std_string_append(&v7094, (int)&Dst, "linen-hand1-random2.cub");
  v7813 = 1636;
  v3386 = this_4pointer_off((void *)v6, 1444);
  something_database(*(_DWORD *)v3386, v3385, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7094);
  v3387 = (int)std_string_append(&v7092, (int)&Dst, "linen-hand2-random2.cub");
  v7813 = 1637;
  v3388 = this_4pointer_off((void *)v6, 1445);
  something_database(*(_DWORD *)v3388, v3387, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7092);
  v3389 = (int)std_string_append(&v7090, (int)&Dst, "linen-hand3-random2.cub");
  v7813 = 1638;
  v3390 = this_4pointer_off((void *)v6, 1446);
  something_database(*(_DWORD *)v3390, v3389, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7090);
  v3391 = (int)std_string_append(&v7088, (int)&Dst, "linen-hand4-random2.cub");
  v7813 = 1639;
  v3392 = this_4pointer_off((void *)v6, 1447);
  something_database(*(_DWORD *)v3392, v3391, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7088);
  v3393 = (int)std_string_append(&v7086, (int)&Dst, "linen-hand5-random2.cub");
  v7813 = 1640;
  v3394 = this_4pointer_off((void *)v6, 1448);
  something_database(*(_DWORD *)v3394, v3393, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7086);
  v3395 = (int)std_string_append(&v7084, (int)&Dst, "linen-hand1-random3.cub");
  v7813 = 1641;
  v3396 = this_4pointer_off((void *)v6, 1449);
  something_database(*(_DWORD *)v3396, v3395, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7084);
  v3397 = (int)std_string_append(&v7082, (int)&Dst, "linen-hand2-random3.cub");
  v7813 = 1642;
  v3398 = this_4pointer_off((void *)v6, 1450);
  something_database(*(_DWORD *)v3398, v3397, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7082);
  v3399 = (int)std_string_append(&v7080, (int)&Dst, "linen-hand3-random3.cub");
  v7813 = 1643;
  v3400 = this_4pointer_off((void *)v6, 1451);
  something_database(*(_DWORD *)v3400, v3399, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7080);
  v3401 = (int)std_string_append(&v7078, (int)&Dst, "linen-hand4-random3.cub");
  v7813 = 1644;
  v3402 = this_4pointer_off((void *)v6, 1452);
  something_database(*(_DWORD *)v3402, v3401, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7078);
  v3403 = (int)std_string_append(&v7076, (int)&Dst, "linen-hand5-random3.cub");
  v7813 = 1645;
  v3404 = this_4pointer_off((void *)v6, 1453);
  something_database(*(_DWORD *)v3404, v3403, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7076);
  v3405 = (int)std_string_append(&v7074, (int)&Dst, "linen-hand1-random4.cub");
  v7813 = 1646;
  v3406 = this_4pointer_off((void *)v6, 1454);
  something_database(*(_DWORD *)v3406, v3405, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7074);
  v3407 = (int)std_string_append(&v7072, (int)&Dst, "linen-hand2-random4.cub");
  v7813 = 1647;
  v3408 = this_4pointer_off((void *)v6, 1455);
  something_database(*(_DWORD *)v3408, v3407, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7072);
  v3409 = (int)std_string_append(&v7070, (int)&Dst, "linen-hand3-random4.cub");
  v7813 = 1648;
  v3410 = this_4pointer_off((void *)v6, 1456);
  something_database(*(_DWORD *)v3410, v3409, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7070);
  v3411 = (int)std_string_append(&v7068, (int)&Dst, "linen-hand4-random4.cub");
  v7813 = 1649;
  v3412 = this_4pointer_off((void *)v6, 1457);
  something_database(*(_DWORD *)v3412, v3411, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7068);
  v3413 = (int)std_string_append(&v7066, (int)&Dst, "linen-hand5-random4.cub");
  v7813 = 1650;
  v3414 = this_4pointer_off((void *)v6, 1458);
  something_database(*(_DWORD *)v3414, v3413, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7066);
  v3415 = (int)std_string_append(&v7064, (int)&Dst, "linen-foot1.cub");
  v7813 = 1651;
  v3416 = this_4pointer_off((void *)v6, 1409);
  something_database(*(_DWORD *)v3416, v3415, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7064);
  v3417 = (int)std_string_append(&v7062, (int)&Dst, "linen-foot2.cub");
  v7813 = 1652;
  v3418 = this_4pointer_off((void *)v6, 1410);
  something_database(*(_DWORD *)v3418, v3417, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7062);
  v3419 = (int)std_string_append(&v7060, (int)&Dst, "linen-foot3.cub");
  v7813 = 1653;
  v3420 = this_4pointer_off((void *)v6, 1411);
  something_database(*(_DWORD *)v3420, v3419, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7060);
  v3421 = (int)std_string_append(&v7058, (int)&Dst, "linen-foot4.cub");
  v7813 = 1654;
  v3422 = this_4pointer_off((void *)v6, 1412);
  something_database(*(_DWORD *)v3422, v3421, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7058);
  v3423 = (int)std_string_append(&v7056, (int)&Dst, "linen-foot5.cub");
  v7813 = 1655;
  v3424 = this_4pointer_off((void *)v6, 1413);
  something_database(*(_DWORD *)v3424, v3423, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7056);
  v3425 = (int)std_string_append(&v7054, (int)&Dst, "linen-foot1-random1.cub");
  v7813 = 1656;
  v3426 = this_4pointer_off((void *)v6, 1414);
  something_database(*(_DWORD *)v3426, v3425, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7054);
  v3427 = (int)std_string_append(&v7052, (int)&Dst, "linen-foot2-random1.cub");
  v7813 = 1657;
  v3428 = this_4pointer_off((void *)v6, 1415);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3427;
  something_database(*(_DWORD *)v3428, v3427, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7052);
  v3429 = (int)std_string_append(&v7050, (int)&Dst, "linen-foot3-random1.cub");
  v7813 = 1658;
  v3430 = this_4pointer_off((void *)v6, 1416);
  something_database(*(_DWORD *)v3430, v3429, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7050);
  v3431 = (int)std_string_append(&v7048, (int)&Dst, "linen-foot4-random1.cub");
  v7813 = 1659;
  v3432 = this_4pointer_off((void *)v6, 1417);
  something_database(*(_DWORD *)v3432, v3431, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7048);
  v3433 = (int)std_string_append(&v7046, (int)&Dst, "linen-foot5-random1.cub");
  v7813 = 1660;
  v3434 = this_4pointer_off((void *)v6, 1418);
  something_database(*(_DWORD *)v3434, v3433, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7046);
  v3435 = (int)std_string_append(&v7044, (int)&Dst, "linen-foot1-random2.cub");
  v7813 = 1661;
  v3436 = this_4pointer_off((void *)v6, 1419);
  something_database(*(_DWORD *)v3436, v3435, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7044);
  v3437 = (int)std_string_append(&v7042, (int)&Dst, "linen-foot2-random2.cub");
  v7813 = 1662;
  v3438 = this_4pointer_off((void *)v6, 1420);
  something_database(*(_DWORD *)v3438, v3437, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7042);
  v3439 = (int)std_string_append(&v7040, (int)&Dst, "linen-foot3-random2.cub");
  v7813 = 1663;
  v3440 = this_4pointer_off((void *)v6, 1421);
  something_database(*(_DWORD *)v3440, v3439, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7040);
  v3441 = (int)std_string_append(&v7038, (int)&Dst, "linen-foot4-random2.cub");
  v7813 = 1664;
  v3442 = this_4pointer_off((void *)v6, 1422);
  something_database(*(_DWORD *)v3442, v3441, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7038);
  v3443 = (int)std_string_append(&v7036, (int)&Dst, "linen-foot5-random2.cub");
  v7813 = 1665;
  v3444 = this_4pointer_off((void *)v6, 1423);
  something_database(*(_DWORD *)v3444, v3443, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7036);
  v3445 = (int)std_string_append(&v7034, (int)&Dst, "linen-foot1-random3.cub");
  v7813 = 1666;
  v3446 = this_4pointer_off((void *)v6, 1424);
  something_database(*(_DWORD *)v3446, v3445, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7034);
  v3447 = (int)std_string_append(&v7032, (int)&Dst, "linen-foot2-random3.cub");
  v7813 = 1667;
  v3448 = this_4pointer_off((void *)v6, 1425);
  something_database(*(_DWORD *)v3448, v3447, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7032);
  v3449 = (int)std_string_append(&v7030, (int)&Dst, "linen-foot3-random3.cub");
  v7813 = 1668;
  v3450 = this_4pointer_off((void *)v6, 1426);
  something_database(*(_DWORD *)v3450, v3449, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7030);
  v3451 = (int)std_string_append(&v7028, (int)&Dst, "linen-foot4-random3.cub");
  v7813 = 1669;
  v3452 = this_4pointer_off((void *)v6, 1427);
  something_database(*(_DWORD *)v3452, v3451, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7028);
  v3453 = (int)std_string_append(&v7026, (int)&Dst, "linen-foot5-random3.cub");
  v7813 = 1670;
  v3454 = this_4pointer_off((void *)v6, 1428);
  something_database(*(_DWORD *)v3454, v3453, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7026);
  v3455 = (int)std_string_append(&v7024, (int)&Dst, "linen-foot1-random4.cub");
  v7813 = 1671;
  v3456 = this_4pointer_off((void *)v6, 1429);
  something_database(*(_DWORD *)v3456, v3455, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7024);
  v3457 = (int)std_string_append(&v7022, (int)&Dst, "linen-foot2-random4.cub");
  v7813 = 1672;
  v3458 = this_4pointer_off((void *)v6, 1430);
  something_database(*(_DWORD *)v3458, v3457, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7022);
  v3459 = (int)std_string_append(&v7020, (int)&Dst, "linen-foot3-random4.cub");
  v7813 = 1673;
  v3460 = this_4pointer_off((void *)v6, 1431);
  something_database(*(_DWORD *)v3460, v3459, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7020);
  v3461 = (int)std_string_append(&v7018, (int)&Dst, "linen-foot4-random4.cub");
  v7813 = 1674;
  v3462 = this_4pointer_off((void *)v6, 1432);
  something_database(*(_DWORD *)v3462, v3461, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7018);
  v3463 = (int)std_string_append(&v7016, (int)&Dst, "linen-foot5-random4.cub");
  v7813 = 1675;
  v3464 = this_4pointer_off((void *)v6, 1433);
  something_database(*(_DWORD *)v3464, v3463, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7016);
  v3465 = (int)std_string_append(&v7014, (int)&Dst, "wool-chest1.cub");
  v7813 = 1676;
  v3466 = this_4pointer_off((void *)v6, 1459);
  something_database(*(_DWORD *)v3466, v3465, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7014);
  v3467 = (int)std_string_append(&v7012, (int)&Dst, "wool-chest2.cub");
  v7813 = 1677;
  v3468 = this_4pointer_off((void *)v6, 1460);
  something_database(*(_DWORD *)v3468, v3467, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7012);
  v3469 = (int)std_string_append(&v7010, (int)&Dst, "wool-chest3.cub");
  v7813 = 1678;
  v3470 = this_4pointer_off((void *)v6, 1461);
  something_database(*(_DWORD *)v3470, v3469, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7010);
  v3471 = (int)std_string_append(&v7008, (int)&Dst, "wool-chest4.cub");
  v7813 = 1679;
  v3472 = this_4pointer_off((void *)v6, 1462);
  something_database(*(_DWORD *)v3472, v3471, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7008);
  v3473 = (int)std_string_append(&v7006, (int)&Dst, "wool-chest5.cub");
  v7813 = 1680;
  v3474 = this_4pointer_off((void *)v6, 1463);
  something_database(*(_DWORD *)v3474, v3473, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7006);
  v3475 = (int)std_string_append(&v7004, (int)&Dst, "wool-chest1-random1.cub");
  v7813 = 1681;
  v3476 = this_4pointer_off((void *)v6, 1464);
  something_database(*(_DWORD *)v3476, v3475, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7004);
  v3477 = (int)std_string_append(&v7002, (int)&Dst, "wool-chest2-random1.cub");
  v7813 = 1682;
  v3478 = this_4pointer_off((void *)v6, 1465);
  something_database(*(_DWORD *)v3478, v3477, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7002);
  v3479 = (int)std_string_append(&v7000, (int)&Dst, "wool-chest3-random1.cub");
  v7813 = 1683;
  v3480 = this_4pointer_off((void *)v6, 1466);
  something_database(*(_DWORD *)v3480, v3479, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v7000);
  v3481 = (int)std_string_append(&v6998, (int)&Dst, "wool-chest4-random1.cub");
  v7813 = 1684;
  v3482 = this_4pointer_off((void *)v6, 1467);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3481;
  something_database(*(_DWORD *)v3482, v3481, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6998);
  v3483 = (int)std_string_append(&v6996, (int)&Dst, "wool-chest5-random1.cub");
  v7813 = 1685;
  v3484 = this_4pointer_off((void *)v6, 1468);
  something_database(*(_DWORD *)v3484, v3483, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6996);
  v3485 = (int)std_string_append(&v6994, (int)&Dst, "wool-chest1-random2.cub");
  v7813 = 1686;
  v3486 = this_4pointer_off((void *)v6, 1469);
  something_database(*(_DWORD *)v3486, v3485, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6994);
  v3487 = (int)std_string_append(&v6992, (int)&Dst, "wool-chest2-random2.cub");
  v7813 = 1687;
  v3488 = this_4pointer_off((void *)v6, 1470);
  something_database(*(_DWORD *)v3488, v3487, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6992);
  v3489 = (int)std_string_append(&v6990, (int)&Dst, "wool-chest3-random2.cub");
  v7813 = 1688;
  v3490 = this_4pointer_off((void *)v6, 1471);
  something_database(*(_DWORD *)v3490, v3489, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6990);
  v3491 = (int)std_string_append(&v6988, (int)&Dst, "wool-chest4-random2.cub");
  v7813 = 1689;
  v3492 = this_4pointer_off((void *)v6, 1472);
  something_database(*(_DWORD *)v3492, v3491, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6988);
  v3493 = (int)std_string_append(&v6986, (int)&Dst, "wool-chest5-random2.cub");
  v7813 = 1690;
  v3494 = this_4pointer_off((void *)v6, 1473);
  something_database(*(_DWORD *)v3494, v3493, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6986);
  v3495 = (int)std_string_append(&v6984, (int)&Dst, "wool-chest1-random3.cub");
  v7813 = 1691;
  v3496 = this_4pointer_off((void *)v6, 1474);
  something_database(*(_DWORD *)v3496, v3495, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6984);
  v3497 = (int)std_string_append(&v6982, (int)&Dst, "wool-chest2-random3.cub");
  v7813 = 1692;
  v3498 = this_4pointer_off((void *)v6, 1475);
  something_database(*(_DWORD *)v3498, v3497, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6982);
  v3499 = (int)std_string_append(&v6980, (int)&Dst, "wool-chest3-random3.cub");
  v7813 = 1693;
  v3500 = this_4pointer_off((void *)v6, 1476);
  something_database(*(_DWORD *)v3500, v3499, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6980);
  v3501 = (int)std_string_append(&v6978, (int)&Dst, "wool-chest4-random3.cub");
  v7813 = 1694;
  v3502 = this_4pointer_off((void *)v6, 1477);
  something_database(*(_DWORD *)v3502, v3501, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6978);
  v3503 = (int)std_string_append(&v6976, (int)&Dst, "wool-chest5-random3.cub");
  v7813 = 1695;
  v3504 = this_4pointer_off((void *)v6, 1478);
  something_database(*(_DWORD *)v3504, v3503, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6976);
  v3505 = (int)std_string_append(&v6974, (int)&Dst, "wool-chest1-random4.cub");
  v7813 = 1696;
  v3506 = this_4pointer_off((void *)v6, 1479);
  something_database(*(_DWORD *)v3506, v3505, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6974);
  v3507 = (int)std_string_append(&v6972, (int)&Dst, "wool-chest2-random4.cub");
  v7813 = 1697;
  v3508 = this_4pointer_off((void *)v6, 1480);
  something_database(*(_DWORD *)v3508, v3507, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6972);
  v3509 = (int)std_string_append(&v6970, (int)&Dst, "wool-chest3-random4.cub");
  v7813 = 1698;
  v3510 = this_4pointer_off((void *)v6, 1481);
  something_database(*(_DWORD *)v3510, v3509, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6970);
  v3511 = (int)std_string_append(&v6968, (int)&Dst, "wool-chest4-random4.cub");
  v7813 = 1699;
  v3512 = this_4pointer_off((void *)v6, 1482);
  something_database(*(_DWORD *)v3512, v3511, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6968);
  v3513 = (int)std_string_append(&v6966, (int)&Dst, "wool-chest5-random4.cub");
  v7813 = 1700;
  v3514 = this_4pointer_off((void *)v6, 1483);
  something_database(*(_DWORD *)v3514, v3513, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6966);
  v3515 = (int)std_string_append(&v6964, (int)&Dst, "wool-shoulder1.cub");
  v7813 = 1701;
  v3516 = this_4pointer_off((void *)v6, 1484);
  something_database(*(_DWORD *)v3516, v3515, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6964);
  v3517 = (int)std_string_append(&v6962, (int)&Dst, "wool-shoulder2.cub");
  v7813 = 1702;
  v3518 = this_4pointer_off((void *)v6, 1485);
  something_database(*(_DWORD *)v3518, v3517, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6962);
  v3519 = (int)std_string_append(&v6960, (int)&Dst, "wool-shoulder3.cub");
  v7813 = 1703;
  v3520 = this_4pointer_off((void *)v6, 1486);
  something_database(*(_DWORD *)v3520, v3519, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6960);
  v3521 = (int)std_string_append(&v6958, (int)&Dst, "wool-shoulder4.cub");
  v7813 = 1704;
  v3522 = this_4pointer_off((void *)v6, 1487);
  something_database(*(_DWORD *)v3522, v3521, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6958);
  v3523 = (int)std_string_append(&v6956, (int)&Dst, "wool-shoulder5.cub");
  v7813 = 1705;
  v3524 = this_4pointer_off((void *)v6, 1488);
  something_database(*(_DWORD *)v3524, v3523, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6956);
  v3525 = (int)std_string_append(&v6954, (int)&Dst, "wool-shoulder1-random1.cub");
  v7813 = 1706;
  v3526 = this_4pointer_off((void *)v6, 1489);
  something_database(*(_DWORD *)v3526, v3525, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6954);
  v3527 = (int)std_string_append(&v6952, (int)&Dst, "wool-shoulder2-random1.cub");
  v7813 = 1707;
  v3528 = this_4pointer_off((void *)v6, 1490);
  something_database(*(_DWORD *)v3528, v3527, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6952);
  v3529 = (int)std_string_append(&v6950, (int)&Dst, "wool-shoulder3-random1.cub");
  v7813 = 1708;
  v3530 = this_4pointer_off((void *)v6, 1491);
  something_database(*(_DWORD *)v3530, v3529, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6950);
  v3531 = (int)std_string_append(&v6948, (int)&Dst, "wool-shoulder4-random1.cub");
  v7813 = 1709;
  v3532 = this_4pointer_off((void *)v6, 1492);
  something_database(*(_DWORD *)v3532, v3531, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6948);
  v3533 = (int)std_string_append(&v6946, (int)&Dst, "wool-shoulder5-random1.cub");
  v7813 = 1710;
  v3534 = this_4pointer_off((void *)v6, 1493);
  something_database(*(_DWORD *)v3534, v3533, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6946);
  v3535 = (int)std_string_append(&v6944, (int)&Dst, "wool-shoulder1-random2.cub");
  v7813 = 1711;
  v3536 = this_4pointer_off((void *)v6, 1494);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3535;
  something_database(*(_DWORD *)v3536, v3535, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6944);
  v3537 = (int)std_string_append(&v6942, (int)&Dst, "wool-shoulder2-random2.cub");
  v7813 = 1712;
  v3538 = this_4pointer_off((void *)v6, 1495);
  something_database(*(_DWORD *)v3538, v3537, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6942);
  v3539 = (int)std_string_append(&v6940, (int)&Dst, "wool-shoulder3-random2.cub");
  v7813 = 1713;
  v3540 = this_4pointer_off((void *)v6, 1496);
  something_database(*(_DWORD *)v3540, v3539, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6940);
  v3541 = (int)std_string_append(&v6938, (int)&Dst, "wool-shoulder4-random2.cub");
  v7813 = 1714;
  v3542 = this_4pointer_off((void *)v6, 1497);
  something_database(*(_DWORD *)v3542, v3541, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6938);
  v3543 = (int)std_string_append(&v6936, (int)&Dst, "wool-shoulder5-random2.cub");
  v7813 = 1715;
  v3544 = this_4pointer_off((void *)v6, 1498);
  something_database(*(_DWORD *)v3544, v3543, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6936);
  v3545 = (int)std_string_append(&v6934, (int)&Dst, "wool-shoulder1-random3.cub");
  v7813 = 1716;
  v3546 = this_4pointer_off((void *)v6, 1499);
  something_database(*(_DWORD *)v3546, v3545, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6934);
  v3547 = (int)std_string_append(&v6932, (int)&Dst, "wool-shoulder2-random3.cub");
  v7813 = 1717;
  v3548 = this_4pointer_off((void *)v6, 1500);
  something_database(*(_DWORD *)v3548, v3547, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6932);
  v3549 = (int)std_string_append(&v6930, (int)&Dst, "wool-shoulder3-random3.cub");
  v7813 = 1718;
  v3550 = this_4pointer_off((void *)v6, 1501);
  something_database(*(_DWORD *)v3550, v3549, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6930);
  v3551 = (int)std_string_append(&v6928, (int)&Dst, "wool-shoulder4-random3.cub");
  v7813 = 1719;
  v3552 = this_4pointer_off((void *)v6, 1502);
  something_database(*(_DWORD *)v3552, v3551, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6928);
  v3553 = (int)std_string_append(&v6926, (int)&Dst, "wool-shoulder5-random3.cub");
  v7813 = 1720;
  v3554 = this_4pointer_off((void *)v6, 1503);
  something_database(*(_DWORD *)v3554, v3553, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6926);
  v3555 = (int)std_string_append(&v6924, (int)&Dst, "wool-shoulder1-random4.cub");
  v7813 = 1721;
  v3556 = this_4pointer_off((void *)v6, 1504);
  something_database(*(_DWORD *)v3556, v3555, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6924);
  v3557 = (int)std_string_append(&v6922, (int)&Dst, "wool-shoulder2-random4.cub");
  v7813 = 1722;
  v3558 = this_4pointer_off((void *)v6, 1505);
  something_database(*(_DWORD *)v3558, v3557, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6922);
  v3559 = (int)std_string_append(&v6920, (int)&Dst, "wool-shoulder3-random4.cub");
  v7813 = 1723;
  v3560 = this_4pointer_off((void *)v6, 1506);
  something_database(*(_DWORD *)v3560, v3559, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6920);
  v3561 = (int)std_string_append(&v6918, (int)&Dst, "wool-shoulder4-random4.cub");
  v7813 = 1724;
  v3562 = this_4pointer_off((void *)v6, 1507);
  something_database(*(_DWORD *)v3562, v3561, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6918);
  v3563 = (int)std_string_append(&v6916, (int)&Dst, "wool-shoulder5-random4.cub");
  v7813 = 1725;
  v3564 = this_4pointer_off((void *)v6, 1508);
  something_database(*(_DWORD *)v3564, v3563, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6916);
  v3565 = (int)std_string_append(&v6914, (int)&Dst, "wool-hand1.cub");
  v7813 = 1726;
  v3566 = this_4pointer_off((void *)v6, 1534);
  something_database(*(_DWORD *)v3566, v3565, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6914);
  v3567 = (int)std_string_append(&v6912, (int)&Dst, "wool-hand2.cub");
  v7813 = 1727;
  v3568 = this_4pointer_off((void *)v6, 1535);
  something_database(*(_DWORD *)v3568, v3567, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6912);
  v3569 = (int)std_string_append(&v6910, (int)&Dst, "wool-hand3.cub");
  v7813 = 1728;
  v3570 = this_4pointer_off((void *)v6, 1536);
  something_database(*(_DWORD *)v3570, v3569, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6910);
  v3571 = (int)std_string_append(&v6908, (int)&Dst, "wool-hand4.cub");
  v7813 = 1729;
  v3572 = this_4pointer_off((void *)v6, 1537);
  something_database(*(_DWORD *)v3572, v3571, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6908);
  v3573 = (int)std_string_append(&v6906, (int)&Dst, "wool-hand5.cub");
  v7813 = 1730;
  v3574 = this_4pointer_off((void *)v6, 1538);
  something_database(*(_DWORD *)v3574, v3573, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6906);
  v3575 = (int)std_string_append(&v6904, (int)&Dst, "wool-hand1-random1.cub");
  v7813 = 1731;
  v3576 = this_4pointer_off((void *)v6, 1539);
  something_database(*(_DWORD *)v3576, v3575, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6904);
  v3577 = (int)std_string_append(&v6902, (int)&Dst, "wool-hand2-random1.cub");
  v7813 = 1732;
  v3578 = this_4pointer_off((void *)v6, 1540);
  something_database(*(_DWORD *)v3578, v3577, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6902);
  v3579 = (int)std_string_append(&v6900, (int)&Dst, "wool-hand3-random1.cub");
  v7813 = 1733;
  v3580 = this_4pointer_off((void *)v6, 1541);
  something_database(*(_DWORD *)v3580, v3579, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6900);
  v3581 = (int)std_string_append(&v6898, (int)&Dst, "wool-hand4-random1.cub");
  v7813 = 1734;
  v3582 = this_4pointer_off((void *)v6, 1542);
  something_database(*(_DWORD *)v3582, v3581, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6898);
  v3583 = (int)std_string_append(&v6896, (int)&Dst, "wool-hand5-random1.cub");
  v7813 = 1735;
  v3584 = this_4pointer_off((void *)v6, 1543);
  something_database(*(_DWORD *)v3584, v3583, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6896);
  v3585 = (int)std_string_append(&v6894, (int)&Dst, "wool-hand1-random2.cub");
  v7813 = 1736;
  v3586 = this_4pointer_off((void *)v6, 1544);
  something_database(*(_DWORD *)v3586, v3585, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6894);
  v3587 = (int)std_string_append(&v6892, (int)&Dst, "wool-hand2-random2.cub");
  v7813 = 1737;
  v3588 = this_4pointer_off((void *)v6, 1545);
  something_database(*(_DWORD *)v3588, v3587, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6892);
  v3589 = (int)std_string_append(&v6890, (int)&Dst, "wool-hand3-random2.cub");
  v7813 = 1738;
  v3590 = this_4pointer_off((void *)v6, 1546);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3589;
  something_database(*(_DWORD *)v3590, v3589, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6890);
  v3591 = (int)std_string_append(&v6888, (int)&Dst, "wool-hand4-random2.cub");
  v7813 = 1739;
  v3592 = this_4pointer_off((void *)v6, 1547);
  something_database(*(_DWORD *)v3592, v3591, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6888);
  v3593 = (int)std_string_append(&v6886, (int)&Dst, "wool-hand5-random2.cub");
  v7813 = 1740;
  v3594 = this_4pointer_off((void *)v6, 1548);
  something_database(*(_DWORD *)v3594, v3593, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6886);
  v3595 = (int)std_string_append(&v6884, (int)&Dst, "wool-hand1-random3.cub");
  v7813 = 1741;
  v3596 = this_4pointer_off((void *)v6, 1549);
  something_database(*(_DWORD *)v3596, v3595, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6884);
  v3597 = (int)std_string_append(&v6882, (int)&Dst, "wool-hand2-random3.cub");
  v7813 = 1742;
  v3598 = this_4pointer_off((void *)v6, 1550);
  something_database(*(_DWORD *)v3598, v3597, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6882);
  v3599 = (int)std_string_append(&v6880, (int)&Dst, "wool-hand3-random3.cub");
  v7813 = 1743;
  v3600 = this_4pointer_off((void *)v6, 1551);
  something_database(*(_DWORD *)v3600, v3599, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6880);
  v3601 = (int)std_string_append(&v6878, (int)&Dst, "wool-hand4-random3.cub");
  v7813 = 1744;
  v3602 = this_4pointer_off((void *)v6, 1552);
  something_database(*(_DWORD *)v3602, v3601, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6878);
  v3603 = (int)std_string_append(&v6876, (int)&Dst, "wool-hand5-random3.cub");
  v7813 = 1745;
  v3604 = this_4pointer_off((void *)v6, 1553);
  something_database(*(_DWORD *)v3604, v3603, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6876);
  v3605 = (int)std_string_append(&v6874, (int)&Dst, "wool-hand1-random4.cub");
  v7813 = 1746;
  v3606 = this_4pointer_off((void *)v6, 1554);
  something_database(*(_DWORD *)v3606, v3605, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6874);
  v3607 = (int)std_string_append(&v6872, (int)&Dst, "wool-hand2-random4.cub");
  v7813 = 1747;
  v3608 = this_4pointer_off((void *)v6, 1555);
  something_database(*(_DWORD *)v3608, v3607, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6872);
  v3609 = (int)std_string_append(&v6870, (int)&Dst, "wool-hand3-random4.cub");
  v7813 = 1748;
  v3610 = this_4pointer_off((void *)v6, 1556);
  something_database(*(_DWORD *)v3610, v3609, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6870);
  v3611 = (int)std_string_append(&v6868, (int)&Dst, "wool-hand4-random4.cub");
  v7813 = 1749;
  v3612 = this_4pointer_off((void *)v6, 1557);
  something_database(*(_DWORD *)v3612, v3611, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6868);
  v3613 = (int)std_string_append(&v6866, (int)&Dst, "wool-hand5-random4.cub");
  v7813 = 1750;
  v3614 = this_4pointer_off((void *)v6, 1558);
  something_database(*(_DWORD *)v3614, v3613, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6866);
  v3615 = (int)std_string_append(&v6864, (int)&Dst, "wool-foot1.cub");
  v7813 = 1751;
  v3616 = this_4pointer_off((void *)v6, 1509);
  something_database(*(_DWORD *)v3616, v3615, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6864);
  v3617 = (int)std_string_append(&v6862, (int)&Dst, "wool-foot2.cub");
  v7813 = 1752;
  v3618 = this_4pointer_off((void *)v6, 1510);
  something_database(*(_DWORD *)v3618, v3617, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6862);
  v3619 = (int)std_string_append(&v6860, (int)&Dst, "wool-foot3.cub");
  v7813 = 1753;
  v3620 = this_4pointer_off((void *)v6, 1511);
  something_database(*(_DWORD *)v3620, v3619, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6860);
  v3621 = (int)std_string_append(&v6858, (int)&Dst, "wool-foot4.cub");
  v7813 = 1754;
  v3622 = this_4pointer_off((void *)v6, 1512);
  something_database(*(_DWORD *)v3622, v3621, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6858);
  v3623 = (int)std_string_append(&v6856, (int)&Dst, "wool-foot5.cub");
  v7813 = 1755;
  v3624 = this_4pointer_off((void *)v6, 1513);
  something_database(*(_DWORD *)v3624, v3623, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6856);
  v3625 = (int)std_string_append(&v6854, (int)&Dst, "wool-foot1-random1.cub");
  v7813 = 1756;
  v3626 = this_4pointer_off((void *)v6, 1514);
  something_database(*(_DWORD *)v3626, v3625, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6854);
  v3627 = (int)std_string_append(&v6852, (int)&Dst, "wool-foot2-random1.cub");
  v7813 = 1757;
  v3628 = this_4pointer_off((void *)v6, 1515);
  something_database(*(_DWORD *)v3628, v3627, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6852);
  v3629 = (int)std_string_append(&v6850, (int)&Dst, "wool-foot3-random1.cub");
  v7813 = 1758;
  v3630 = this_4pointer_off((void *)v6, 1516);
  something_database(*(_DWORD *)v3630, v3629, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6850);
  v3631 = (int)std_string_append(&v6848, (int)&Dst, "wool-foot4-random1.cub");
  v7813 = 1759;
  v3632 = this_4pointer_off((void *)v6, 1517);
  something_database(*(_DWORD *)v3632, v3631, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6848);
  v3633 = (int)std_string_append(&v6846, (int)&Dst, "wool-foot5-random1.cub");
  v7813 = 1760;
  v3634 = this_4pointer_off((void *)v6, 1518);
  something_database(*(_DWORD *)v3634, v3633, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6846);
  v3635 = (int)std_string_append(&v6844, (int)&Dst, "wool-foot1-random2.cub");
  v7813 = 1761;
  v3636 = this_4pointer_off((void *)v6, 1519);
  something_database(*(_DWORD *)v3636, v3635, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6844);
  v3637 = (int)std_string_append(&v6842, (int)&Dst, "wool-foot2-random2.cub");
  v7813 = 1762;
  v3638 = this_4pointer_off((void *)v6, 1520);
  something_database(*(_DWORD *)v3638, v3637, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6842);
  v3639 = (int)std_string_append(&v6840, (int)&Dst, "wool-foot3-random2.cub");
  v7813 = 1763;
  v3640 = this_4pointer_off((void *)v6, 1521);
  something_database(*(_DWORD *)v3640, v3639, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6840);
  v3641 = (int)std_string_append(&v6838, (int)&Dst, "wool-foot4-random2.cub");
  v7813 = 1764;
  v3642 = this_4pointer_off((void *)v6, 1522);
  something_database(*(_DWORD *)v3642, v3641, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6838);
  v3643 = (int)std_string_append(&v6836, (int)&Dst, "wool-foot5-random2.cub");
  v7813 = 1765;
  v3644 = this_4pointer_off((void *)v6, 1523);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3643;
  something_database(*(_DWORD *)v3644, v3643, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6836);
  v3645 = (int)std_string_append(&v6834, (int)&Dst, "wool-foot1-random3.cub");
  v7813 = 1766;
  v3646 = this_4pointer_off((void *)v6, 1524);
  something_database(*(_DWORD *)v3646, v3645, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6834);
  v3647 = (int)std_string_append(&v6832, (int)&Dst, "wool-foot2-random3.cub");
  v7813 = 1767;
  v3648 = this_4pointer_off((void *)v6, 1525);
  something_database(*(_DWORD *)v3648, v3647, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6832);
  v3649 = (int)std_string_append(&v6830, (int)&Dst, "wool-foot3-random3.cub");
  v7813 = 1768;
  v3650 = this_4pointer_off((void *)v6, 1526);
  something_database(*(_DWORD *)v3650, v3649, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6830);
  v3651 = (int)std_string_append(&v6828, (int)&Dst, "wool-foot4-random3.cub");
  v7813 = 1769;
  v3652 = this_4pointer_off((void *)v6, 1527);
  something_database(*(_DWORD *)v3652, v3651, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6828);
  v3653 = (int)std_string_append(&v6826, (int)&Dst, "wool-foot5-random3.cub");
  v7813 = 1770;
  v3654 = this_4pointer_off((void *)v6, 1528);
  something_database(*(_DWORD *)v3654, v3653, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6826);
  v3655 = (int)std_string_append(&v6824, (int)&Dst, "wool-foot1-random4.cub");
  v7813 = 1771;
  v3656 = this_4pointer_off((void *)v6, 1529);
  something_database(*(_DWORD *)v3656, v3655, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6824);
  v3657 = (int)std_string_append(&v6822, (int)&Dst, "wool-foot2-random4.cub");
  v7813 = 1772;
  v3658 = this_4pointer_off((void *)v6, 1530);
  something_database(*(_DWORD *)v3658, v3657, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6822);
  v3659 = (int)std_string_append(&v6820, (int)&Dst, "wool-foot3-random4.cub");
  v7813 = 1773;
  v3660 = this_4pointer_off((void *)v6, 1531);
  something_database(*(_DWORD *)v3660, v3659, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6820);
  v3661 = (int)std_string_append(&v6818, (int)&Dst, "wool-foot4-random4.cub");
  v7813 = 1774;
  v3662 = this_4pointer_off((void *)v6, 1532);
  something_database(*(_DWORD *)v3662, v3661, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6818);
  v3663 = (int)std_string_append(&v6816, (int)&Dst, "wool-foot5-random4.cub");
  v7813 = 1775;
  v3664 = this_4pointer_off((void *)v6, 1533);
  something_database(*(_DWORD *)v3664, v3663, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6816);
  v3665 = (int)std_string_append(&v6814, (int)&Dst, "iron-shield01.cub");
  v7813 = 1776;
  v3666 = this_4pointer_off((void *)v6, 1064);
  something_database(*(_DWORD *)v3666, v3665, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6814);
  v3667 = (int)std_string_append(&v6812, (int)&Dst, "iron-shield02.cub");
  v7813 = 1777;
  v3668 = this_4pointer_off((void *)v6, 1065);
  something_database(*(_DWORD *)v3668, v3667, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6812);
  v3669 = (int)std_string_append(&v6810, (int)&Dst, "iron-shield03.cub");
  v7813 = 1778;
  v3670 = this_4pointer_off((void *)v6, 1066);
  something_database(*(_DWORD *)v3670, v3669, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6810);
  v3671 = (int)std_string_append(&v6808, (int)&Dst, "iron-shield04.cub");
  v7813 = 1779;
  v3672 = this_4pointer_off((void *)v6, 1067);
  something_database(*(_DWORD *)v3672, v3671, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6808);
  v3673 = (int)std_string_append(&v6806, (int)&Dst, "iron-shield05.cub");
  v7813 = 1780;
  v3674 = this_4pointer_off((void *)v6, 1068);
  something_database(*(_DWORD *)v3674, v3673, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6806);
  v3675 = (int)std_string_append(&v6804, (int)&Dst, "iron-shield1-random1.cub");
  v7813 = 1781;
  v3676 = this_4pointer_off((void *)v6, 1069);
  something_database(*(_DWORD *)v3676, v3675, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6804);
  v3677 = (int)std_string_append(&v6802, (int)&Dst, "iron-shield2-random1.cub");
  v7813 = 1782;
  v3678 = this_4pointer_off((void *)v6, 1070);
  something_database(*(_DWORD *)v3678, v3677, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6802);
  v3679 = (int)std_string_append(&v6800, (int)&Dst, "iron-shield3-random1.cub");
  v7813 = 1783;
  v3680 = this_4pointer_off((void *)v6, 1071);
  something_database(*(_DWORD *)v3680, v3679, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6800);
  v3681 = (int)std_string_append(&v6798, (int)&Dst, "iron-shield4-random1.cub");
  v7813 = 1784;
  v3682 = this_4pointer_off((void *)v6, 1072);
  something_database(*(_DWORD *)v3682, v3681, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6798);
  v3683 = (int)std_string_append(&v6796, (int)&Dst, "iron-shield5-random1.cub");
  v7813 = 1785;
  v3684 = this_4pointer_off((void *)v6, 1073);
  something_database(*(_DWORD *)v3684, v3683, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6796);
  v3685 = (int)std_string_append(&v6794, (int)&Dst, "iron-shield1-random2.cub");
  v7813 = 1786;
  v3686 = this_4pointer_off((void *)v6, 1074);
  something_database(*(_DWORD *)v3686, v3685, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6794);
  v3687 = (int)std_string_append(&v6792, (int)&Dst, "iron-shield2-random2.cub");
  v7813 = 1787;
  v3688 = this_4pointer_off((void *)v6, 1075);
  something_database(*(_DWORD *)v3688, v3687, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6792);
  v3689 = (int)std_string_append(&v6790, (int)&Dst, "iron-shield3-random2.cub");
  v7813 = 1788;
  v3690 = this_4pointer_off((void *)v6, 1076);
  something_database(*(_DWORD *)v3690, v3689, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6790);
  v3691 = (int)std_string_append(&v6788, (int)&Dst, "iron-shield4-random2.cub");
  v7813 = 1789;
  v3692 = this_4pointer_off((void *)v6, 1077);
  something_database(*(_DWORD *)v3692, v3691, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6788);
  v3693 = (int)std_string_append(&v6786, (int)&Dst, "iron-shield5-random2.cub");
  v7813 = 1790;
  v3694 = this_4pointer_off((void *)v6, 1078);
  something_database(*(_DWORD *)v3694, v3693, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6786);
  v3695 = (int)std_string_append(&v6784, (int)&Dst, "iron-shield1-random3.cub");
  v7813 = 1791;
  v3696 = this_4pointer_off((void *)v6, 1079);
  something_database(*(_DWORD *)v3696, v3695, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6784);
  v3697 = (int)std_string_append(&v6782, (int)&Dst, "iron-shield2-random3.cub");
  v7813 = 1792;
  v3698 = this_4pointer_off((void *)v6, 1080);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3697;
  something_database(*(_DWORD *)v3698, v3697, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6782);
  v3699 = (int)std_string_append(&v6780, (int)&Dst, "iron-shield3-random3.cub");
  v7813 = 1793;
  v3700 = this_4pointer_off((void *)v6, 1081);
  something_database(*(_DWORD *)v3700, v3699, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6780);
  v3701 = (int)std_string_append(&v6778, (int)&Dst, "iron-shield4-random3.cub");
  v7813 = 1794;
  v3702 = this_4pointer_off((void *)v6, 1082);
  something_database(*(_DWORD *)v3702, v3701, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6778);
  v3703 = (int)std_string_append(&v6776, (int)&Dst, "iron-shield5-random3.cub");
  v7813 = 1795;
  v3704 = this_4pointer_off((void *)v6, 1083);
  something_database(*(_DWORD *)v3704, v3703, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6776);
  v3705 = (int)std_string_append(&v6774, (int)&Dst, "iron-shield1-random4.cub");
  v7813 = 1796;
  v3706 = this_4pointer_off((void *)v6, 1084);
  something_database(*(_DWORD *)v3706, v3705, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6774);
  v3707 = (int)std_string_append(&v6772, (int)&Dst, "iron-shield2-random4.cub");
  v7813 = 1797;
  v3708 = this_4pointer_off((void *)v6, 1085);
  something_database(*(_DWORD *)v3708, v3707, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6772);
  v3709 = (int)std_string_append(&v6770, (int)&Dst, "iron-shield3-random4.cub");
  v7813 = 1798;
  v3710 = this_4pointer_off((void *)v6, 1086);
  something_database(*(_DWORD *)v3710, v3709, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6770);
  v3711 = (int)std_string_append(&v6768, (int)&Dst, "iron-shield4-random4.cub");
  v7813 = 1799;
  v3712 = this_4pointer_off((void *)v6, 1087);
  something_database(*(_DWORD *)v3712, v3711, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6768);
  v3713 = (int)std_string_append(&v6766, (int)&Dst, "iron-shield5-random4.cub");
  v7813 = 1800;
  v3714 = this_4pointer_off((void *)v6, 1088);
  something_database(*(_DWORD *)v3714, v3713, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6766);
  v3715 = (int)std_string_append(&v6764, (int)&Dst, "iron-shield1-random5.cub");
  v7813 = 1801;
  v3716 = this_4pointer_off((void *)v6, 1089);
  something_database(*(_DWORD *)v3716, v3715, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6764);
  v3717 = (int)std_string_append(&v6762, (int)&Dst, "iron-shield2-random5.cub");
  v7813 = 1802;
  v3718 = this_4pointer_off((void *)v6, 1090);
  something_database(*(_DWORD *)v3718, v3717, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6762);
  v3719 = (int)std_string_append(&v6760, (int)&Dst, "iron-shield3-random5.cub");
  v7813 = 1803;
  v3720 = this_4pointer_off((void *)v6, 1091);
  something_database(*(_DWORD *)v3720, v3719, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6760);
  v3721 = (int)std_string_append(&v6758, (int)&Dst, "iron-shield4-random5.cub");
  v7813 = 1804;
  v3722 = this_4pointer_off((void *)v6, 1092);
  something_database(*(_DWORD *)v3722, v3721, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6758);
  v3723 = (int)std_string_append(&v6756, (int)&Dst, "iron-shield5-random5.cub");
  v7813 = 1805;
  v3724 = this_4pointer_off((void *)v6, 1093);
  something_database(*(_DWORD *)v3724, v3723, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6756);
  v3725 = (int)std_string_append(&v6754, (int)&Dst, "iron-shield1-random6.cub");
  v7813 = 1806;
  v3726 = this_4pointer_off((void *)v6, 1094);
  something_database(*(_DWORD *)v3726, v3725, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6754);
  v3727 = (int)std_string_append(&v6752, (int)&Dst, "iron-shield2-random6.cub");
  v7813 = 1807;
  v3728 = this_4pointer_off((void *)v6, 1095);
  something_database(*(_DWORD *)v3728, v3727, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6752);
  v3729 = (int)std_string_append(&v6750, (int)&Dst, "iron-shield3-random6.cub");
  v7813 = 1808;
  v3730 = this_4pointer_off((void *)v6, 1096);
  something_database(*(_DWORD *)v3730, v3729, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6750);
  v3731 = (int)std_string_append(&v6748, (int)&Dst, "iron-shield4-random6.cub");
  v7813 = 1809;
  v3732 = this_4pointer_off((void *)v6, 1097);
  something_database(*(_DWORD *)v3732, v3731, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6748);
  v3733 = (int)std_string_append(&v6746, (int)&Dst, "iron-shield5-random6.cub");
  v7813 = 1810;
  v3734 = this_4pointer_off((void *)v6, 1098);
  something_database(*(_DWORD *)v3734, v3733, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6746);
  v3735 = (int)std_string_append(&v6744, (int)&Dst, "iron-shield1-random7.cub");
  v7813 = 1811;
  v3736 = this_4pointer_off((void *)v6, 1099);
  something_database(*(_DWORD *)v3736, v3735, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6744);
  v3737 = (int)std_string_append(&v6742, (int)&Dst, "iron-shield2-random7.cub");
  v7813 = 1812;
  v3738 = this_4pointer_off((void *)v6, 1100);
  something_database(*(_DWORD *)v3738, v3737, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6742);
  v3739 = (int)std_string_append(&v6740, (int)&Dst, "iron-shield3-random7.cub");
  v7813 = 1813;
  v3740 = this_4pointer_off((void *)v6, 1101);
  something_database(*(_DWORD *)v3740, v3739, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6740);
  v3741 = (int)std_string_append(&v6738, (int)&Dst, "iron-shield4-random7.cub");
  v7813 = 1814;
  v3742 = this_4pointer_off((void *)v6, 1102);
  something_database(*(_DWORD *)v3742, v3741, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6738);
  v3743 = (int)std_string_append(&v6736, (int)&Dst, "iron-shield5-random7.cub");
  v7813 = 1815;
  v3744 = this_4pointer_off((void *)v6, 1103);
  something_database(*(_DWORD *)v3744, v3743, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6736);
  v3745 = (int)std_string_append(&v6734, (int)&Dst, "iron-shield1-random8.cub");
  v7813 = 1816;
  v3746 = this_4pointer_off((void *)v6, 1104);
  something_database(*(_DWORD *)v3746, v3745, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6734);
  v3747 = (int)std_string_append(&v6732, (int)&Dst, "iron-shield2-random8.cub");
  v7813 = 1817;
  v3748 = this_4pointer_off((void *)v6, 1105);
  something_database(*(_DWORD *)v3748, v3747, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6732);
  v3749 = (int)std_string_append(&v6730, (int)&Dst, "iron-shield3-random8.cub");
  v7813 = 1818;
  v3750 = this_4pointer_off((void *)v6, 1106);
  something_database(*(_DWORD *)v3750, v3749, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6730);
  v3751 = (int)std_string_append(&v6728, (int)&Dst, "iron-shield4-random8.cub");
  v7813 = 1819;
  v3752 = this_4pointer_off((void *)v6, 1107);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3751;
  something_database(*(_DWORD *)v3752, v3751, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6728);
  v3753 = (int)std_string_append(&v6726, (int)&Dst, "iron-shield5-random8.cub");
  v7813 = 1820;
  v3754 = this_4pointer_off((void *)v6, 1108);
  something_database(*(_DWORD *)v3754, v3753, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6726);
  v3755 = (int)std_string_append(&v6724, (int)&Dst, "iron-shield1-random9.cub");
  v7813 = 1821;
  v3756 = this_4pointer_off((void *)v6, 1109);
  something_database(*(_DWORD *)v3756, v3755, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6724);
  v3757 = (int)std_string_append(&v6722, (int)&Dst, "iron-shield2-random9.cub");
  v7813 = 1822;
  v3758 = this_4pointer_off((void *)v6, 1110);
  something_database(*(_DWORD *)v3758, v3757, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6722);
  v3759 = (int)std_string_append(&v6720, (int)&Dst, "iron-shield3-random9.cub");
  v7813 = 1823;
  v3760 = this_4pointer_off((void *)v6, 1111);
  something_database(*(_DWORD *)v3760, v3759, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6720);
  v3761 = (int)std_string_append(&v6718, (int)&Dst, "iron-shield4-random9.cub");
  v7813 = 1824;
  v3762 = this_4pointer_off((void *)v6, 1112);
  something_database(*(_DWORD *)v3762, v3761, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6718);
  v3763 = (int)std_string_append(&v6716, (int)&Dst, "iron-shield5-random9.cub");
  v7813 = 1825;
  v3764 = this_4pointer_off((void *)v6, 1113);
  something_database(*(_DWORD *)v3764, v3763, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6716);
  v3765 = (int)std_string_append(&v6714, (int)&Dst, "iron-shield1-random10.cub");
  v7813 = 1826;
  v3766 = this_4pointer_off((void *)v6, 1114);
  something_database(*(_DWORD *)v3766, v3765, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6714);
  v3767 = (int)std_string_append(&v6712, (int)&Dst, (const char *)"iron-shield2-random10.cub");
  v7813 = 1827;
  v3768 = this_4pointer_off((void *)v6, 1115);
  something_database(*(_DWORD *)v3768, v3767, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6712);
  v3769 = (int)std_string_append(&v6710, (int)&Dst, "iron-shield3-random10.cub");
  v7813 = 1828;
  v3770 = this_4pointer_off((void *)v6, 1116);
  something_database(*(_DWORD *)v3770, v3769, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6710);
  v3771 = (int)std_string_append(&v6708, (int)&Dst, "iron-shield4-random10.cub");
  v7813 = 1829;
  v3772 = this_4pointer_off((void *)v6, 1117);
  something_database(*(_DWORD *)v3772, v3771, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6708);
  v3773 = (int)std_string_append(&v6706, (int)&Dst, "iron-shield5-random10.cub");
  v7813 = 1830;
  v3774 = this_4pointer_off((void *)v6, 1118);
  something_database(*(_DWORD *)v3774, v3773, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6706);
  v3775 = (int)std_string_append(&v6704, (int)&Dst, "wood-shield01.cub");
  v7813 = 1831;
  v3776 = this_4pointer_off((void *)v6, 1119);
  something_database(*(_DWORD *)v3776, v3775, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6704);
  v3777 = (int)std_string_append(&v6702, (int)&Dst, "wood-shield02.cub");
  v7813 = 1832;
  v3778 = this_4pointer_off((void *)v6, 1120);
  something_database(*(_DWORD *)v3778, v3777, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6702);
  v3779 = (int)std_string_append(&v6700, (int)&Dst, "wood-shield03.cub");
  v7813 = 1833;
  v3780 = this_4pointer_off((void *)v6, 1121);
  something_database(*(_DWORD *)v3780, v3779, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6700);
  v3781 = (int)std_string_append(&v6698, (int)&Dst, "wood-shield04.cub");
  v7813 = 1834;
  v3782 = this_4pointer_off((void *)v6, 1122);
  something_database(*(_DWORD *)v3782, v3781, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6698);
  v3783 = (int)std_string_append(&v6696, (int)&Dst, "wood-shield05.cub");
  v7813 = 1835;
  v3784 = this_4pointer_off((void *)v6, 1123);
  something_database(*(_DWORD *)v3784, v3783, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6696);
  v3785 = (int)std_string_append(&v6694, (int)&Dst, "iron-axe1.cub");
  v7813 = 1836;
  v3786 = this_4pointer_off((void *)v6, 1770);
  something_database(*(_DWORD *)v3786, v3785, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6694);
  v3787 = (int)std_string_append(&v6692, (int)&Dst, "iron-axe2.cub");
  v7813 = 1837;
  v3788 = this_4pointer_off((void *)v6, 1771);
  something_database(*(_DWORD *)v3788, v3787, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6692);
  v3789 = (int)std_string_append(&v6690, (int)&Dst, "iron-axe3.cub");
  v7813 = 1838;
  v3790 = this_4pointer_off((void *)v6, 1772);
  something_database(*(_DWORD *)v3790, v3789, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6690);
  v3791 = (int)std_string_append(&v6688, (int)&Dst, "iron-axe4.cub");
  v7813 = 1839;
  v3792 = this_4pointer_off((void *)v6, 1773);
  something_database(*(_DWORD *)v3792, v3791, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6688);
  v3793 = (int)std_string_append(&v6686, (int)&Dst, "iron-axe5.cub");
  v7813 = 1840;
  v3794 = this_4pointer_off((void *)v6, 1774);
  something_database(*(_DWORD *)v3794, v3793, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6686);
  v3795 = (int)std_string_append(&v6684, (int)&Dst, "iron-axe1-random1.cub");
  v7813 = 1841;
  v3796 = this_4pointer_off((void *)v6, 1775);
  something_database(*(_DWORD *)v3796, v3795, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6684);
  v3797 = (int)std_string_append(&v6682, (int)&Dst, "iron-axe2-random1.cub");
  v7813 = 1842;
  v3798 = this_4pointer_off((void *)v6, 1776);
  something_database(*(_DWORD *)v3798, v3797, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6682);
  v3799 = (int)std_string_append(&v6680, (int)&Dst, "iron-axe3-random1.cub");
  v7813 = 1843;
  v3800 = this_4pointer_off((void *)v6, 1777);
  something_database(*(_DWORD *)v3800, v3799, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6680);
  v3801 = (int)std_string_append(&v6678, (int)&Dst, "iron-axe4-random1.cub");
  v7813 = 1844;
  v3802 = this_4pointer_off((void *)v6, 1778);
  something_database(*(_DWORD *)v3802, v3801, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6678);
  v3803 = (int)std_string_append(&v6676, (int)&Dst, "iron-axe5-random1.cub");
  v7813 = 1845;
  v3804 = this_4pointer_off((void *)v6, 1779);
  something_database(*(_DWORD *)v3804, v3803, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6676);
  v3805 = (int)std_string_append(&v6674, (int)&Dst, "iron-axe1-random2.cub");
  v7813 = 1846;
  v3806 = this_4pointer_off((void *)v6, 1780);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3805;
  something_database(*(_DWORD *)v3806, v3805, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6674);
  v3807 = (int)std_string_append(&v6672, (int)&Dst, "iron-axe2-random2.cub");
  v7813 = 1847;
  v3808 = this_4pointer_off((void *)v6, 1781);
  something_database(*(_DWORD *)v3808, v3807, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6672);
  v3809 = (int)std_string_append(&v6670, (int)&Dst, "iron-axe3-random2.cub");
  v7813 = 1848;
  v3810 = this_4pointer_off((void *)v6, 1782);
  something_database(*(_DWORD *)v3810, v3809, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6670);
  v3811 = (int)std_string_append(&v6668, (int)&Dst, "iron-axe4-random2.cub");
  v7813 = 1849;
  v3812 = this_4pointer_off((void *)v6, 1783);
  something_database(*(_DWORD *)v3812, v3811, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6668);
  v3813 = (int)std_string_append(&v6666, (int)&Dst, "iron-axe5-random2.cub");
  v7813 = 1850;
  v3814 = this_4pointer_off((void *)v6, 1784);
  something_database(*(_DWORD *)v3814, v3813, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6666);
  v3815 = (int)std_string_append(&v6664, (int)&Dst, "iron-axe1-random3.cub");
  v7813 = 1851;
  v3816 = this_4pointer_off((void *)v6, 1785);
  something_database(*(_DWORD *)v3816, v3815, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6664);
  v3817 = (int)std_string_append(&v6662, (int)&Dst, "iron-axe2-random3.cub");
  v7813 = 1852;
  v3818 = this_4pointer_off((void *)v6, 1786);
  something_database(*(_DWORD *)v3818, v3817, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6662);
  v3819 = (int)std_string_append(&v6660, (int)&Dst, "iron-axe3-random3.cub");
  v7813 = 1853;
  v3820 = this_4pointer_off((void *)v6, 1787);
  something_database(*(_DWORD *)v3820, v3819, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6660);
  v3821 = (int)std_string_append(&v6658, (int)&Dst, "iron-axe4-random3.cub");
  v7813 = 1854;
  v3822 = this_4pointer_off((void *)v6, 1788);
  something_database(*(_DWORD *)v3822, v3821, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6658);
  v3823 = (int)std_string_append(&v6656, (int)&Dst, "iron-axe5-random3.cub");
  v7813 = 1855;
  v3824 = this_4pointer_off((void *)v6, 1789);
  something_database(*(_DWORD *)v3824, v3823, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6656);
  v3825 = (int)std_string_append(&v6654, (int)&Dst, "iron-axe1-random4.cub");
  v7813 = 1856;
  v3826 = this_4pointer_off((void *)v6, 1790);
  something_database(*(_DWORD *)v3826, v3825, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6654);
  v3827 = (int)std_string_append(&v6652, (int)&Dst, "iron-axe2-random4.cub");
  v7813 = 1857;
  v3828 = this_4pointer_off((void *)v6, 1791);
  something_database(*(_DWORD *)v3828, v3827, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6652);
  v3829 = (int)std_string_append(&v6650, (int)&Dst, "iron-axe3-random4.cub");
  v7813 = 1858;
  v3830 = this_4pointer_off((void *)v6, 1792);
  something_database(*(_DWORD *)v3830, v3829, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6650);
  v3831 = (int)std_string_append(&v6648, (int)&Dst, "iron-axe4-random4.cub");
  v7813 = 1859;
  v3832 = this_4pointer_off((void *)v6, 1793);
  something_database(*(_DWORD *)v3832, v3831, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6648);
  v3833 = (int)std_string_append(&v6646, (int)&Dst, "iron-axe5-random4.cub");
  v7813 = 1860;
  v3834 = this_4pointer_off((void *)v6, 1794);
  something_database(*(_DWORD *)v3834, v3833, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6646);
  v3835 = (int)std_string_append(&v6644, (int)&Dst, "iron-axe1-random5.cub");
  v7813 = 1861;
  v3836 = this_4pointer_off((void *)v6, 1795);
  something_database(*(_DWORD *)v3836, v3835, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6644);
  v3837 = (int)std_string_append(&v6642, (int)&Dst, "iron-axe2-random5.cub");
  v7813 = 1862;
  v3838 = this_4pointer_off((void *)v6, 1796);
  something_database(*(_DWORD *)v3838, v3837, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6642);
  v3839 = (int)std_string_append(&v6640, (int)&Dst, "iron-axe3-random5.cub");
  v7813 = 1863;
  v3840 = this_4pointer_off((void *)v6, 1797);
  something_database(*(_DWORD *)v3840, v3839, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6640);
  v3841 = (int)std_string_append(&v6638, (int)&Dst, "iron-axe4-random5.cub");
  v7813 = 1864;
  v3842 = this_4pointer_off((void *)v6, 1798);
  something_database(*(_DWORD *)v3842, v3841, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6638);
  v3843 = (int)std_string_append(&v6636, (int)&Dst, "iron-axe5-random5.cub");
  v7813 = 1865;
  v3844 = this_4pointer_off((void *)v6, 1799);
  something_database(*(_DWORD *)v3844, v3843, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6636);
  v3845 = (int)std_string_append(&v6634, (int)&Dst, "iron-axe1-random6.cub");
  v7813 = 1866;
  v3846 = this_4pointer_off((void *)v6, 1800);
  something_database(*(_DWORD *)v3846, v3845, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6634);
  v3847 = (int)std_string_append(&v6632, (int)&Dst, "iron-axe2-random6.cub");
  v7813 = 1867;
  v3848 = this_4pointer_off((void *)v6, 1801);
  something_database(*(_DWORD *)v3848, v3847, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6632);
  v3849 = (int)std_string_append(&v6630, (int)&Dst, "iron-axe3-random6.cub");
  v7813 = 1868;
  v3850 = this_4pointer_off((void *)v6, 1802);
  something_database(*(_DWORD *)v3850, v3849, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6630);
  v3851 = (int)std_string_append(&v6628, (int)&Dst, "iron-axe4-random6.cub");
  v7813 = 1869;
  v3852 = this_4pointer_off((void *)v6, 1803);
  something_database(*(_DWORD *)v3852, v3851, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6628);
  v3853 = (int)std_string_append(&v6626, (int)&Dst, "iron-axe5-random6.cub");
  v7813 = 1870;
  v3854 = this_4pointer_off((void *)v6, 1804);
  something_database(*(_DWORD *)v3854, v3853, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6626);
  v3855 = (int)std_string_append(&v6624, (int)&Dst, "iron-axe1-random7.cub");
  v7813 = 1871;
  v3856 = this_4pointer_off((void *)v6, 1805);
  something_database(*(_DWORD *)v3856, v3855, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6624);
  v3857 = (int)std_string_append(&v6622, (int)&Dst, "iron-axe2-random7.cub");
  v7813 = 1872;
  v3858 = this_4pointer_off((void *)v6, 1806);
  something_database(*(_DWORD *)v3858, v3857, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6622);
  v3859 = (int)std_string_append(&v6620, (int)&Dst, "iron-axe3-random7.cub");
  v7813 = 1873;
  v3860 = this_4pointer_off((void *)v6, 1807);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3859;
  something_database(*(_DWORD *)v3860, v3859, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6620);
  v3861 = (int)std_string_append(&v6618, (int)&Dst, "iron-axe4-random7.cub");
  v7813 = 1874;
  v3862 = this_4pointer_off((void *)v6, 1808);
  something_database(*(_DWORD *)v3862, v3861, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6618);
  v3863 = (int)std_string_append(&v6616, (int)&Dst, "iron-axe5-random7.cub");
  v7813 = 1875;
  v3864 = this_4pointer_off((void *)v6, 1809);
  something_database(*(_DWORD *)v3864, v3863, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6616);
  v3865 = (int)std_string_append(&v6614, (int)&Dst, "iron-axe1-random8.cub");
  v7813 = 1876;
  v3866 = this_4pointer_off((void *)v6, 1810);
  something_database(*(_DWORD *)v3866, v3865, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6614);
  v3867 = (int)std_string_append(&v6612, (int)&Dst, "iron-axe2-random8.cub");
  v7813 = 1877;
  v3868 = this_4pointer_off((void *)v6, 1811);
  something_database(*(_DWORD *)v3868, v3867, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6612);
  v3869 = (int)std_string_append(&v6610, (int)&Dst, "iron-axe3-random8.cub");
  v7813 = 1878;
  v3870 = this_4pointer_off((void *)v6, 1812);
  something_database(*(_DWORD *)v3870, v3869, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6610);
  v3871 = (int)std_string_append(&v6608, (int)&Dst, "iron-axe4-random8.cub");
  v7813 = 1879;
  v3872 = this_4pointer_off((void *)v6, 1813);
  something_database(*(_DWORD *)v3872, v3871, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6608);
  v3873 = (int)std_string_append(&v6606, (int)&Dst, "iron-axe5-random8.cub");
  v7813 = 1880;
  v3874 = this_4pointer_off((void *)v6, 1814);
  something_database(*(_DWORD *)v3874, v3873, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6606);
  v3875 = (int)std_string_append(&v6604, (int)&Dst, "iron-axe1-random9.cub");
  v7813 = 1881;
  v3876 = this_4pointer_off((void *)v6, 1815);
  something_database(*(_DWORD *)v3876, v3875, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6604);
  v3877 = (int)std_string_append(&v6602, (int)&Dst, "iron-axe2-random9.cub");
  v7813 = 1882;
  v3878 = this_4pointer_off((void *)v6, 1816);
  something_database(*(_DWORD *)v3878, v3877, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6602);
  v3879 = (int)std_string_append(&v6600, (int)&Dst, "iron-axe3-random9.cub");
  v7813 = 1883;
  v3880 = this_4pointer_off((void *)v6, 1817);
  something_database(*(_DWORD *)v3880, v3879, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6600);
  v3881 = (int)std_string_append(&v6598, (int)&Dst, "iron-axe4-random9.cub");
  v7813 = 1884;
  v3882 = this_4pointer_off((void *)v6, 1818);
  something_database(*(_DWORD *)v3882, v3881, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6598);
  v3883 = (int)std_string_append(&v6596, (int)&Dst, "iron-axe5-random9.cub");
  v7813 = 1885;
  v3884 = this_4pointer_off((void *)v6, 1819);
  something_database(*(_DWORD *)v3884, v3883, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6596);
  v3885 = (int)std_string_append(&v6594, (int)&Dst, "iron-axe1-random10.cub");
  v7813 = 1886;
  v3886 = this_4pointer_off((void *)v6, 1820);
  something_database(*(_DWORD *)v3886, v3885, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6594);
  v3887 = (int)std_string_append(&v6592, (int)&Dst, "iron-axe2-random10.cub");
  v7813 = 1887;
  v3888 = this_4pointer_off((void *)v6, 1821);
  something_database(*(_DWORD *)v3888, v3887, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6592);
  v3889 = (int)std_string_append(&v6590, (int)&Dst, "iron-axe3-random10.cub");
  v7813 = 1888;
  v3890 = this_4pointer_off((void *)v6, 1822);
  something_database(*(_DWORD *)v3890, v3889, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6590);
  v3891 = (int)std_string_append(&v6588, (int)&Dst, "iron-axe4-random10.cub");
  v7813 = 1889;
  v3892 = this_4pointer_off((void *)v6, 1823);
  something_database(*(_DWORD *)v3892, v3891, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6588);
  v3893 = (int)std_string_append(&v6586, (int)&Dst, "iron-axe5-random10.cub");
  v7813 = 1890;
  v3894 = this_4pointer_off((void *)v6, 1824);
  something_database(*(_DWORD *)v3894, v3893, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6586);
  v3895 = (int)std_string_append(&v6584, (int)&Dst, "gold-coin.cub");
  v7813 = 1891;
  v3896 = this_4pointer_off((void *)v6, 2086);
  something_database(*(_DWORD *)v3896, v3895, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6584);
  v3897 = (int)std_string_append(&v6582, (int)&Dst, "copper-coin.cub");
  v7813 = 1892;
  v3898 = this_4pointer_off((void *)v6, 2084);
  something_database(*(_DWORD *)v3898, v3897, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6582);
  v3899 = (int)std_string_append(&v6580, (int)&Dst, "silver-coin.cub");
  v7813 = 1893;
  v3900 = this_4pointer_off((void *)v6, 2085);
  something_database(*(_DWORD *)v3900, v3899, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6580);
  v3901 = (int)std_string_append(&v6578, (int)&Dst, "iron-greatsword1.cub");
  v7813 = 1894;
  v3902 = this_4pointer_off((void *)v6, 1825);
  something_database(*(_DWORD *)v3902, v3901, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6578);
  v3903 = (int)std_string_append(&v6576, (int)&Dst, "iron-greatsword2.cub");
  v7813 = 1895;
  v3904 = this_4pointer_off((void *)v6, 1826);
  something_database(*(_DWORD *)v3904, v3903, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6576);
  v3905 = (int)std_string_append(&v6574, (int)&Dst, "iron-greatsword3.cub");
  v7813 = 1896;
  v3906 = this_4pointer_off((void *)v6, 1827);
  something_database(*(_DWORD *)v3906, v3905, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6574);
  v3907 = (int)std_string_append(&v6572, (int)&Dst, "iron-greatsword4.cub");
  v7813 = 1897;
  v3908 = this_4pointer_off((void *)v6, 1828);
  something_database(*(_DWORD *)v3908, v3907, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6572);
  v3909 = (int)std_string_append(&v6570, (int)&Dst, "iron-greatsword5.cub");
  v7813 = 1898;
  v3910 = this_4pointer_off((void *)v6, 1829);
  something_database(*(_DWORD *)v3910, v3909, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6570);
  v3911 = (int)std_string_append(&v6568, (int)&Dst, "iron-greatsword1-random1.cub");
  v7813 = 1899;
  v3912 = this_4pointer_off((void *)v6, 1830);
  something_database(*(_DWORD *)v3912, v3911, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6568);
  v3913 = (int)std_string_append(&v6566, (int)&Dst, "iron-greatsword2-random1.cub");
  v7813 = 1900;
  v3914 = this_4pointer_off((void *)v6, 1831);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3913;
  something_database(*(_DWORD *)v3914, v3913, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6566);
  v3915 = (int)std_string_append(&v6564, (int)&Dst, "iron-greatsword3-random1.cub");
  v7813 = 1901;
  v3916 = this_4pointer_off((void *)v6, 1832);
  something_database(*(_DWORD *)v3916, v3915, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6564);
  v3917 = (int)std_string_append(&v6562, (int)&Dst, "iron-greatsword4-random1.cub");
  v7813 = 1902;
  v3918 = this_4pointer_off((void *)v6, 1833);
  something_database(*(_DWORD *)v3918, v3917, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6562);
  v3919 = (int)std_string_append(&v6560, (int)&Dst, "iron-greatsword5-random1.cub");
  v7813 = 1903;
  v3920 = this_4pointer_off((void *)v6, 1834);
  something_database(*(_DWORD *)v3920, v3919, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6560);
  v3921 = (int)std_string_append(&v6558, (int)&Dst, "iron-greatsword1-random2.cub");
  v7813 = 1904;
  v3922 = this_4pointer_off((void *)v6, 1835);
  something_database(*(_DWORD *)v3922, v3921, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6558);
  v3923 = (int)std_string_append(&v6556, (int)&Dst, "iron-greatsword2-random2.cub");
  v7813 = 1905;
  v3924 = this_4pointer_off((void *)v6, 1836);
  something_database(*(_DWORD *)v3924, v3923, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6556);
  v3925 = (int)std_string_append(&v6554, (int)&Dst, "iron-greatsword3-random2.cub");
  v7813 = 1906;
  v3926 = this_4pointer_off((void *)v6, 1837);
  something_database(*(_DWORD *)v3926, v3925, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6554);
  v3927 = (int)std_string_append(&v6552, (int)&Dst, "iron-greatsword4-random2.cub");
  v7813 = 1907;
  v3928 = this_4pointer_off((void *)v6, 1838);
  something_database(*(_DWORD *)v3928, v3927, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6552);
  v3929 = (int)std_string_append(&v6550, (int)&Dst, "iron-greatsword5-random2.cub");
  v7813 = 1908;
  v3930 = this_4pointer_off((void *)v6, 1839);
  something_database(*(_DWORD *)v3930, v3929, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6550);
  v3931 = (int)std_string_append(&v6548, (int)&Dst, "iron-greatsword1-random3.cub");
  v7813 = 1909;
  v3932 = this_4pointer_off((void *)v6, 1840);
  something_database(*(_DWORD *)v3932, v3931, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6548);
  v3933 = (int)std_string_append(&v6546, (int)&Dst, "iron-greatsword2-random3.cub");
  v7813 = 1910;
  v3934 = this_4pointer_off((void *)v6, 1841);
  something_database(*(_DWORD *)v3934, v3933, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6546);
  v3935 = (int)std_string_append(&v6544, (int)&Dst, "iron-greatsword3-random3.cub");
  v7813 = 1911;
  v3936 = this_4pointer_off((void *)v6, 1842);
  something_database(*(_DWORD *)v3936, v3935, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6544);
  v3937 = (int)std_string_append(&v6542, (int)&Dst, "iron-greatsword4-random3.cub");
  v7813 = 1912;
  v3938 = this_4pointer_off((void *)v6, 1843);
  something_database(*(_DWORD *)v3938, v3937, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6542);
  v3939 = (int)std_string_append(&v6540, (int)&Dst, "iron-greatsword5-random3.cub");
  v7813 = 1913;
  v3940 = this_4pointer_off((void *)v6, 1844);
  something_database(*(_DWORD *)v3940, v3939, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6540);
  v3941 = (int)std_string_append(&v6538, (int)&Dst, "iron-greatsword1-random4.cub");
  v7813 = 1914;
  v3942 = this_4pointer_off((void *)v6, 1845);
  something_database(*(_DWORD *)v3942, v3941, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6538);
  v3943 = (int)std_string_append(&v6536, (int)&Dst, "iron-greatsword2-random4.cub");
  v7813 = 1915;
  v3944 = this_4pointer_off((void *)v6, 1846);
  something_database(*(_DWORD *)v3944, v3943, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6536);
  v3945 = (int)std_string_append(&v6534, (int)&Dst, "iron-greatsword3-random4.cub");
  v7813 = 1916;
  v3946 = this_4pointer_off((void *)v6, 1847);
  something_database(*(_DWORD *)v3946, v3945, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6534);
  v3947 = (int)std_string_append(&v6532, (int)&Dst, "iron-greatsword4-random4.cub");
  v7813 = 1917;
  v3948 = this_4pointer_off((void *)v6, 1848);
  something_database(*(_DWORD *)v3948, v3947, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6532);
  v3949 = (int)std_string_append(&v6530, (int)&Dst, "iron-greatsword5-random4.cub");
  v7813 = 1918;
  v3950 = this_4pointer_off((void *)v6, 1849);
  something_database(*(_DWORD *)v3950, v3949, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6530);
  v3951 = (int)std_string_append(&v6528, (int)&Dst, "iron-greatsword1-random5.cub");
  v7813 = 1919;
  v3952 = this_4pointer_off((void *)v6, 1850);
  something_database(*(_DWORD *)v3952, v3951, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6528);
  v3953 = (int)std_string_append(&v6526, (int)&Dst, "iron-greatsword2-random5.cub");
  v7813 = 1920;
  v3954 = this_4pointer_off((void *)v6, 1851);
  something_database(*(_DWORD *)v3954, v3953, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6526);
  v3955 = (int)std_string_append(&v6524, (int)&Dst, "iron-greatsword3-random5.cub");
  v7813 = 1921;
  v3956 = this_4pointer_off((void *)v6, 1852);
  something_database(*(_DWORD *)v3956, v3955, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6524);
  v3957 = (int)std_string_append(&v6522, (int)&Dst, "iron-greatsword4-random5.cub");
  v7813 = 1922;
  v3958 = this_4pointer_off((void *)v6, 1853);
  something_database(*(_DWORD *)v3958, v3957, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6522);
  v3959 = (int)std_string_append(&v6520, (int)&Dst, "iron-greatsword5-random5.cub");
  v7813 = 1923;
  v3960 = this_4pointer_off((void *)v6, 1854);
  something_database(*(_DWORD *)v3960, v3959, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6520);
  v3961 = (int)std_string_append(&v6518, (int)&Dst, "iron-greatsword1-random6.cub");
  v7813 = 1924;
  v3962 = this_4pointer_off((void *)v6, 1855);
  something_database(*(_DWORD *)v3962, v3961, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6518);
  v3963 = (int)std_string_append(&v6516, (int)&Dst, "iron-greatsword2-random6.cub");
  v7813 = 1925;
  v3964 = this_4pointer_off((void *)v6, 1856);
  something_database(*(_DWORD *)v3964, v3963, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6516);
  v3965 = (int)std_string_append(&v6514, (int)&Dst, "iron-greatsword3-random6.cub");
  v7813 = 1926;
  v3966 = this_4pointer_off((void *)v6, 1857);
  something_database(*(_DWORD *)v3966, v3965, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6514);
  v3967 = (int)std_string_append(&v6512, (int)&Dst, "iron-greatsword4-random6.cub");
  v7813 = 1927;
  v3968 = this_4pointer_off((void *)v6, 1858);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v3967;
  something_database(*(_DWORD *)v3968, v3967, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6512);
  v3969 = (int)std_string_append(&v6510, (int)&Dst, "iron-greatsword5-random6.cub");
  v7813 = 1928;
  v3970 = this_4pointer_off((void *)v6, 1859);
  something_database(*(_DWORD *)v3970, v3969, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6510);
  v3971 = (int)std_string_append(&v6508, (int)&Dst, "iron-greatsword1-random7.cub");
  v7813 = 1929;
  v3972 = this_4pointer_off((void *)v6, 1860);
  something_database(*(_DWORD *)v3972, v3971, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6508);
  v3973 = (int)std_string_append(&v6506, (int)&Dst, "iron-greatsword2-random7.cub");
  v7813 = 1930;
  v3974 = this_4pointer_off((void *)v6, 1861);
  something_database(*(_DWORD *)v3974, v3973, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6506);
  v3975 = (int)std_string_append(&v6504, (int)&Dst, "iron-greatsword3-random7.cub");
  v7813 = 1931;
  v3976 = this_4pointer_off((void *)v6, 1862);
  something_database(*(_DWORD *)v3976, v3975, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6504);
  v3977 = (int)std_string_append(&v6502, (int)&Dst, "iron-greatsword4-random7.cub");
  v7813 = 1932;
  v3978 = this_4pointer_off((void *)v6, 1863);
  something_database(*(_DWORD *)v3978, v3977, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6502);
  v3979 = (int)std_string_append(&v6500, (int)&Dst, "iron-greatsword5-random7.cub");
  v7813 = 1933;
  v3980 = this_4pointer_off((void *)v6, 1864);
  something_database(*(_DWORD *)v3980, v3979, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6500);
  v3981 = (int)std_string_append(&v6498, (int)&Dst, "iron-greatsword1-random8.cub");
  v7813 = 1934;
  v3982 = this_4pointer_off((void *)v6, 1865);
  something_database(*(_DWORD *)v3982, v3981, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6498);
  v3983 = (int)std_string_append(&v6496, (int)&Dst, "iron-greatsword2-random8.cub");
  v7813 = 1935;
  v3984 = this_4pointer_off((void *)v6, 1866);
  something_database(*(_DWORD *)v3984, v3983, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6496);
  v3985 = (int)std_string_append(&v6494, (int)&Dst, "iron-greatsword3-random8.cub");
  v7813 = 1936;
  v3986 = this_4pointer_off((void *)v6, 1867);
  something_database(*(_DWORD *)v3986, v3985, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6494);
  v3987 = (int)std_string_append(&v6492, (int)&Dst, "iron-greatsword4-random8.cub");
  v7813 = 1937;
  v3988 = this_4pointer_off((void *)v6, 1868);
  something_database(*(_DWORD *)v3988, v3987, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6492);
  v3989 = (int)std_string_append(&v6490, (int)&Dst, "iron-greatsword5-random8.cub");
  v7813 = 1938;
  v3990 = this_4pointer_off((void *)v6, 1869);
  something_database(*(_DWORD *)v3990, v3989, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6490);
  v3991 = (int)std_string_append(&v6488, (int)&Dst, "iron-greatsword1-random9.cub");
  v7813 = 1939;
  v3992 = this_4pointer_off((void *)v6, 1870);
  something_database(*(_DWORD *)v3992, v3991, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6488);
  v3993 = (int)std_string_append(&v6486, (int)&Dst, "iron-greatsword2-random9.cub");
  v7813 = 1940;
  v3994 = this_4pointer_off((void *)v6, 1871);
  something_database(*(_DWORD *)v3994, v3993, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6486);
  v3995 = (int)std_string_append(&v6484, (int)&Dst, "iron-greatsword3-random9.cub");
  v7813 = 1941;
  v3996 = this_4pointer_off((void *)v6, 1872);
  something_database(*(_DWORD *)v3996, v3995, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6484);
  v3997 = (int)std_string_append(&v6482, (int)&Dst, "iron-greatsword4-random9.cub");
  v7813 = 1942;
  v3998 = this_4pointer_off((void *)v6, 1873);
  something_database(*(_DWORD *)v3998, v3997, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6482);
  v3999 = (int)std_string_append(&v6480, (int)&Dst, "iron-greatsword5-random9.cub");
  v7813 = 1943;
  v4000 = this_4pointer_off((void *)v6, 1874);
  something_database(*(_DWORD *)v4000, v3999, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6480);
  v4001 = (int)std_string_append(&v6478, (int)&Dst, "iron-greatsword1-random10.cub");
  v7813 = 1944;
  v4002 = this_4pointer_off((void *)v6, 1875);
  something_database(*(_DWORD *)v4002, v4001, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6478);
  v4003 = (int)std_string_append(&v6476, (int)&Dst, "iron-greatsword2-random10.cub");
  v7813 = 1945;
  v4004 = this_4pointer_off((void *)v6, 1876);
  something_database(*(_DWORD *)v4004, v4003, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6476);
  v4005 = (int)std_string_append(&v6474, (int)&Dst, "iron-greatsword3-random10.cub");
  v7813 = 1946;
  v4006 = this_4pointer_off((void *)v6, 1877);
  something_database(*(_DWORD *)v4006, v4005, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6474);
  v4007 = (int)std_string_append(&v6472, (int)&Dst, "iron-greatsword4-random10.cub");
  v7813 = 1947;
  v4008 = this_4pointer_off((void *)v6, 1878);
  something_database(*(_DWORD *)v4008, v4007, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6472);
  v4009 = (int)std_string_append(&v6470, (int)&Dst, "iron-greatsword5-random10.cub");
  v7813 = 1948;
  v4010 = this_4pointer_off((void *)v6, 1879);
  something_database(*(_DWORD *)v4010, v4009, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6470);
  v4011 = (int)std_string_append(&v6468, (int)&Dst, "iron-longsword1.cub");
  v7813 = 1949;
  v4012 = this_4pointer_off((void *)v6, 1880);
  something_database(*(_DWORD *)v4012, v4011, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6468);
  v4013 = (int)std_string_append(&v6466, (int)&Dst, "iron-longsword2.cub");
  v7813 = 1950;
  v4014 = this_4pointer_off((void *)v6, 1881);
  something_database(*(_DWORD *)v4014, v4013, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6466);
  v4015 = (int)std_string_append(&v6464, (int)&Dst, "iron-longsword3.cub");
  v7813 = 1951;
  v4016 = this_4pointer_off((void *)v6, 1882);
  something_database(*(_DWORD *)v4016, v4015, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6464);
  v4017 = (int)std_string_append(&v6462, (int)&Dst, "iron-longsword4.cub");
  v7813 = 1952;
  v4018 = this_4pointer_off((void *)v6, 1883);
  something_database(*(_DWORD *)v4018, v4017, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6462);
  v4019 = (int)std_string_append(&v6460, (int)&Dst, "iron-longsword5.cub");
  v7813 = 1953;
  v4020 = this_4pointer_off((void *)v6, 1884);
  something_database(*(_DWORD *)v4020, v4019, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6460);
  v4021 = (int)std_string_append(&v6458, (int)&Dst, "iron-longsword1-random1.cub");
  v7813 = 1954;
  v4022 = this_4pointer_off((void *)v6, 1885);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4021;
  something_database(*(_DWORD *)v4022, v4021, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6458);
  v4023 = (int)std_string_append(&v6456, (int)&Dst, "iron-longsword2-random1.cub");
  v7813 = 1955;
  v4024 = this_4pointer_off((void *)v6, 1886);
  something_database(*(_DWORD *)v4024, v4023, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6456);
  v4025 = (int)std_string_append(&v6454, (int)&Dst, "iron-longsword3-random1.cub");
  v7813 = 1956;
  v4026 = this_4pointer_off((void *)v6, 1887);
  something_database(*(_DWORD *)v4026, v4025, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6454);
  v4027 = (int)std_string_append(&v6452, (int)&Dst, "iron-longsword4-random1.cub");
  v7813 = 1957;
  v4028 = this_4pointer_off((void *)v6, 1888);
  something_database(*(_DWORD *)v4028, v4027, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6452);
  v4029 = (int)std_string_append(&v6450, (int)&Dst, "iron-longsword5-random1.cub");
  v7813 = 1958;
  v4030 = this_4pointer_off((void *)v6, 1889);
  something_database(*(_DWORD *)v4030, v4029, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6450);
  v4031 = (int)std_string_append(&v6448, (int)&Dst, "iron-longsword1-random2.cub");
  v7813 = 1959;
  v4032 = this_4pointer_off((void *)v6, 1890);
  something_database(*(_DWORD *)v4032, v4031, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6448);
  v4033 = (int)std_string_append(&v6446, (int)&Dst, "iron-longsword2-random2.cub");
  v7813 = 1960;
  v4034 = this_4pointer_off((void *)v6, 1891);
  something_database(*(_DWORD *)v4034, v4033, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6446);
  v4035 = (int)std_string_append(&v6444, (int)&Dst, "iron-longsword3-random2.cub");
  v7813 = 1961;
  v4036 = this_4pointer_off((void *)v6, 1892);
  something_database(*(_DWORD *)v4036, v4035, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6444);
  v4037 = (int)std_string_append(&v6442, (int)&Dst, "iron-longsword4-random2.cub");
  v7813 = 1962;
  v4038 = this_4pointer_off((void *)v6, 1893);
  something_database(*(_DWORD *)v4038, v4037, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6442);
  v4039 = (int)std_string_append(&v6440, (int)&Dst, "iron-longsword5-random2.cub");
  v7813 = 1963;
  v4040 = this_4pointer_off((void *)v6, 1894);
  something_database(*(_DWORD *)v4040, v4039, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6440);
  v4041 = (int)std_string_append(&v6438, (int)&Dst, "iron-longsword1-random3.cub");
  v7813 = 1964;
  v4042 = this_4pointer_off((void *)v6, 1895);
  something_database(*(_DWORD *)v4042, v4041, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6438);
  v4043 = (int)std_string_append(&v6436, (int)&Dst, "iron-longsword2-random3.cub");
  v7813 = 1965;
  v4044 = this_4pointer_off((void *)v6, 1896);
  something_database(*(_DWORD *)v4044, v4043, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6436);
  v4045 = (int)std_string_append(&v6434, (int)&Dst, "iron-longsword3-random3.cub");
  v7813 = 1966;
  v4046 = this_4pointer_off((void *)v6, 1897);
  something_database(*(_DWORD *)v4046, v4045, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6434);
  v4047 = (int)std_string_append(&v6432, (int)&Dst, "iron-longsword4-random3.cub");
  v7813 = 1967;
  v4048 = this_4pointer_off((void *)v6, 1898);
  something_database(*(_DWORD *)v4048, v4047, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6432);
  v4049 = (int)std_string_append(&v6430, (int)&Dst, "iron-longsword5-random3.cub");
  v7813 = 1968;
  v4050 = this_4pointer_off((void *)v6, 1899);
  something_database(*(_DWORD *)v4050, v4049, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6430);
  v4051 = (int)std_string_append(&v6428, (int)&Dst, "iron-longsword1-random4.cub");
  v7813 = 1969;
  v4052 = this_4pointer_off((void *)v6, 1900);
  something_database(*(_DWORD *)v4052, v4051, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6428);
  v4053 = (int)std_string_append(&v6426, (int)&Dst, "iron-longsword2-random4.cub");
  v7813 = 1970;
  v4054 = this_4pointer_off((void *)v6, 1901);
  something_database(*(_DWORD *)v4054, v4053, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6426);
  v4055 = (int)std_string_append(&v6424, (int)&Dst, "iron-longsword3-random4.cub");
  v7813 = 1971;
  v4056 = this_4pointer_off((void *)v6, 1902);
  something_database(*(_DWORD *)v4056, v4055, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6424);
  v4057 = (int)std_string_append(&v6422, (int)&Dst, "iron-longsword4-random4.cub");
  v7813 = 1972;
  v4058 = this_4pointer_off((void *)v6, 1903);
  something_database(*(_DWORD *)v4058, v4057, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6422);
  v4059 = (int)std_string_append(&v6420, (int)&Dst, "iron-longsword5-random4.cub");
  v7813 = 1973;
  v4060 = this_4pointer_off((void *)v6, 1904);
  something_database(*(_DWORD *)v4060, v4059, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6420);
  v4061 = (int)std_string_append(&v6418, (int)&Dst, "iron-longsword1-random5.cub");
  v7813 = 1974;
  v4062 = this_4pointer_off((void *)v6, 1905);
  something_database(*(_DWORD *)v4062, v4061, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6418);
  v4063 = (int)std_string_append(&v6416, (int)&Dst, "iron-longsword2-random5.cub");
  v7813 = 1975;
  v4064 = this_4pointer_off((void *)v6, 1906);
  something_database(*(_DWORD *)v4064, v4063, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6416);
  v4065 = (int)std_string_append(&v6414, (int)&Dst, "iron-longsword3-random5.cub");
  v7813 = 1976;
  v4066 = this_4pointer_off((void *)v6, 1907);
  something_database(*(_DWORD *)v4066, v4065, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6414);
  v4067 = (int)std_string_append(&v6412, (int)&Dst, "iron-longsword4-random5.cub");
  v7813 = 1977;
  v4068 = this_4pointer_off((void *)v6, 1908);
  something_database(*(_DWORD *)v4068, v4067, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6412);
  v4069 = (int)std_string_append(&v6410, (int)&Dst, "iron-longsword5-random5.cub");
  v7813 = 1978;
  v4070 = this_4pointer_off((void *)v6, 1909);
  something_database(*(_DWORD *)v4070, v4069, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6410);
  v4071 = (int)std_string_append(&v6408, (int)&Dst, "iron-longsword1-random6.cub");
  v7813 = 1979;
  v4072 = this_4pointer_off((void *)v6, 1910);
  something_database(*(_DWORD *)v4072, v4071, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6408);
  v4073 = (int)std_string_append(&v6406, (int)&Dst, "iron-longsword2-random6.cub");
  v7813 = 1980;
  v4074 = this_4pointer_off((void *)v6, 1911);
  something_database(*(_DWORD *)v4074, v4073, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6406);
  v4075 = (int)std_string_append(&v6404, (int)&Dst, "iron-longsword3-random6.cub");
  v7813 = 1981;
  v4076 = this_4pointer_off((void *)v6, 1912);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4075;
  something_database(*(_DWORD *)v4076, v4075, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6404);
  v4077 = (int)std_string_append(&v6402, (int)&Dst, "iron-longsword4-random6.cub");
  v7813 = 1982;
  v4078 = this_4pointer_off((void *)v6, 1913);
  something_database(*(_DWORD *)v4078, v4077, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6402);
  v4079 = (int)std_string_append(&v6400, (int)&Dst, "iron-longsword5-random6.cub");
  v7813 = 1983;
  v4080 = this_4pointer_off((void *)v6, 1914);
  something_database(*(_DWORD *)v4080, v4079, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6400);
  v4081 = (int)std_string_append(&v6398, (int)&Dst, "iron-longsword1-random7.cub");
  v7813 = 1984;
  v4082 = this_4pointer_off((void *)v6, 1915);
  something_database(*(_DWORD *)v4082, v4081, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6398);
  v4083 = (int)std_string_append(&v6396, (int)&Dst, "iron-longsword2-random7.cub");
  v7813 = 1985;
  v4084 = this_4pointer_off((void *)v6, 1916);
  something_database(*(_DWORD *)v4084, v4083, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6396);
  v4085 = (int)std_string_append(&v6394, (int)&Dst, (const char *)"iron-longsword3-random7.cub");
  v7813 = 1986;
  v4086 = this_4pointer_off((void *)v6, 1917);
  something_database(*(_DWORD *)v4086, v4085, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6394);
  v4087 = (int)std_string_append(&v6392, (int)&Dst, "iron-longsword4-random7.cub");
  v7813 = 1987;
  v4088 = this_4pointer_off((void *)v6, 1918);
  something_database(*(_DWORD *)v4088, v4087, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6392);
  v4089 = (int)std_string_append(&v6390, (int)&Dst, "iron-longsword5-random7.cub");
  v7813 = 1988;
  v4090 = this_4pointer_off((void *)v6, 1919);
  something_database(*(_DWORD *)v4090, v4089, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6390);
  v4091 = (int)std_string_append(&v6388, (int)&Dst, "iron-longsword1-random8.cub");
  v7813 = 1989;
  v4092 = this_4pointer_off((void *)v6, 1920);
  something_database(*(_DWORD *)v4092, v4091, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6388);
  v4093 = (int)std_string_append(&v6386, (int)&Dst, "iron-longsword2-random8.cub");
  v7813 = 1990;
  v4094 = this_4pointer_off((void *)v6, 1921);
  something_database(*(_DWORD *)v4094, v4093, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6386);
  v4095 = (int)std_string_append(&v6384, (int)&Dst, "iron-longsword3-random8.cub");
  v7813 = 1991;
  v4096 = this_4pointer_off((void *)v6, 1922);
  something_database(*(_DWORD *)v4096, v4095, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6384);
  v4097 = (int)std_string_append(&v6382, (int)&Dst, "iron-longsword4-random8.cub");
  v7813 = 1992;
  v4098 = this_4pointer_off((void *)v6, 1923);
  something_database(*(_DWORD *)v4098, v4097, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6382);
  v4099 = (int)std_string_append(&v6380, (int)&Dst, "iron-longsword5-random8.cub");
  v7813 = 1993;
  v4100 = this_4pointer_off((void *)v6, 1924);
  something_database(*(_DWORD *)v4100, v4099, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6380);
  v4101 = (int)std_string_append(&v6378, (int)&Dst, "iron-longsword1-random9.cub");
  v7813 = 1994;
  v4102 = this_4pointer_off((void *)v6, 1925);
  something_database(*(_DWORD *)v4102, v4101, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6378);
  v4103 = (int)std_string_append(&v6376, (int)&Dst, "iron-longsword2-random9.cub");
  v7813 = 1995;
  v4104 = this_4pointer_off((void *)v6, 1926);
  something_database(*(_DWORD *)v4104, v4103, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6376);
  v4105 = (int)std_string_append(&v6374, (int)&Dst, "iron-longsword3-random9.cub");
  v7813 = 1996;
  v4106 = this_4pointer_off((void *)v6, 1927);
  something_database(*(_DWORD *)v4106, v4105, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6374);
  v4107 = (int)std_string_append(&v6372, (int)&Dst, "iron-longsword4-random9.cub");
  v7813 = 1997;
  v4108 = this_4pointer_off((void *)v6, 1928);
  something_database(*(_DWORD *)v4108, v4107, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6372);
  v4109 = (int)std_string_append(&v6370, (int)&Dst, "iron-longsword5-random9.cub");
  v7813 = 1998;
  v4110 = this_4pointer_off((void *)v6, 1929);
  something_database(*(_DWORD *)v4110, v4109, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6370);
  v4111 = (int)std_string_append(&v6368, (int)&Dst, "iron-longsword1-random10.cub");
  v7813 = 1999;
  v4112 = this_4pointer_off((void *)v6, 1930);
  something_database(*(_DWORD *)v4112, v4111, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6368);
  v4113 = (int)std_string_append(&v6366, (int)&Dst, "iron-longsword2-random10.cub");
  v7813 = 2000;
  v4114 = this_4pointer_off((void *)v6, 1931);
  something_database(*(_DWORD *)v4114, v4113, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6366);
  v4115 = (int)std_string_append(&v6364, (int)&Dst, "iron-longsword3-random10.cub");
  v7813 = 2001;
  v4116 = this_4pointer_off((void *)v6, 1932);
  something_database(*(_DWORD *)v4116, v4115, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6364);
  v4117 = (int)std_string_append(&v6362, (int)&Dst, "iron-longsword4-random10.cub");
  v7813 = 2002;
  v4118 = this_4pointer_off((void *)v6, 1933);
  something_database(*(_DWORD *)v4118, v4117, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6362);
  v4119 = (int)std_string_append(&v6360, (int)&Dst, "iron-longsword5-random10.cub");
  v7813 = 2003;
  v4120 = this_4pointer_off((void *)v6, 1934);
  something_database(*(_DWORD *)v4120, v4119, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6360);
  v4121 = (int)std_string_append(&v6358, (int)&Dst, "bone-greatsword.cub");
  v7813 = 2004;
  v4122 = this_4pointer_off((void *)v6, 1935);
  something_database(*(_DWORD *)v4122, v4121, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6358);
  v4123 = (int)std_string_append(&v6356, (int)&Dst, "obsidian-greatsword.cub");
  v7813 = 2005;
  v4124 = this_4pointer_off((void *)v6, 1936);
  something_database(*(_DWORD *)v4124, v4123, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6356);
  v4125 = (int)std_string_append(&v6354, (int)&Dst, "iron-greataxe1.cub");
  v7813 = 2006;
  v4126 = this_4pointer_off((void *)v6, 1937);
  something_database(*(_DWORD *)v4126, v4125, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6354);
  v4127 = (int)std_string_append(&v6352, (int)&Dst, "iron-greataxe2.cub");
  v7813 = 2007;
  v4128 = this_4pointer_off((void *)v6, 1938);
  something_database(*(_DWORD *)v4128, v4127, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6352);
  v4129 = (int)std_string_append(&v6350, (int)&Dst, "iron-greataxe3.cub");
  v7813 = 2008;
  v4130 = this_4pointer_off((void *)v6, 1939);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4129;
  something_database(*(_DWORD *)v4130, v4129, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6350);
  v4131 = (int)std_string_append(&v6348, (int)&Dst, "iron-greataxe4.cub");
  v7813 = 2009;
  v4132 = this_4pointer_off((void *)v6, 1940);
  something_database(*(_DWORD *)v4132, v4131, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6348);
  v4133 = (int)std_string_append(&v6346, (int)&Dst, "iron-greataxe5.cub");
  v7813 = 2010;
  v4134 = this_4pointer_off((void *)v6, 1941);
  something_database(*(_DWORD *)v4134, v4133, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6346);
  v4135 = (int)std_string_append(&v6344, (int)&Dst, "iron-greataxe1-random1.cub");
  v7813 = 2011;
  v4136 = this_4pointer_off((void *)v6, 1942);
  something_database(*(_DWORD *)v4136, v4135, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6344);
  v4137 = (int)std_string_append(&v6342, (int)&Dst, "iron-greataxe2-random1.cub");
  v7813 = 2012;
  v4138 = this_4pointer_off((void *)v6, 1943);
  something_database(*(_DWORD *)v4138, v4137, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6342);
  v4139 = (int)std_string_append(&v6340, (int)&Dst, "iron-greataxe3-random1.cub");
  v7813 = 2013;
  v4140 = this_4pointer_off((void *)v6, 1944);
  something_database(*(_DWORD *)v4140, v4139, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6340);
  v4141 = (int)std_string_append(&v6338, (int)&Dst, "iron-greataxe4-random1.cub");
  v7813 = 2014;
  v4142 = this_4pointer_off((void *)v6, 1945);
  something_database(*(_DWORD *)v4142, v4141, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6338);
  v4143 = (int)std_string_append(&v6336, (int)&Dst, "iron-greataxe5-random1.cub");
  v7813 = 2015;
  v4144 = this_4pointer_off((void *)v6, 1946);
  something_database(*(_DWORD *)v4144, v4143, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6336);
  v4145 = (int)std_string_append(&v6334, (int)&Dst, "iron-greataxe1-random2.cub");
  v7813 = 2016;
  v4146 = this_4pointer_off((void *)v6, 1947);
  something_database(*(_DWORD *)v4146, v4145, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6334);
  v4147 = (int)std_string_append(&v6332, (int)&Dst, "iron-greataxe2-random2.cub");
  v7813 = 2017;
  v4148 = this_4pointer_off((void *)v6, 1948);
  something_database(*(_DWORD *)v4148, v4147, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6332);
  v4149 = (int)std_string_append(&v6330, (int)&Dst, "iron-greataxe3-random2.cub");
  v7813 = 2018;
  v4150 = this_4pointer_off((void *)v6, 1949);
  something_database(*(_DWORD *)v4150, v4149, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6330);
  v4151 = (int)std_string_append(&v6328, (int)&Dst, "iron-greataxe4-random2.cub");
  v7813 = 2019;
  v4152 = this_4pointer_off((void *)v6, 1950);
  something_database(*(_DWORD *)v4152, v4151, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6328);
  v4153 = (int)std_string_append(&v6326, (int)&Dst, "iron-greataxe5-random2.cub");
  v7813 = 2020;
  v4154 = this_4pointer_off((void *)v6, 1951);
  something_database(*(_DWORD *)v4154, v4153, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6326);
  v4155 = (int)std_string_append(&v6324, (int)&Dst, "iron-greataxe1-random3.cub");
  v7813 = 2021;
  v4156 = this_4pointer_off((void *)v6, 1952);
  something_database(*(_DWORD *)v4156, v4155, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6324);
  v4157 = (int)std_string_append(&v6322, (int)&Dst, "iron-greataxe2-random3.cub");
  v7813 = 2022;
  v4158 = this_4pointer_off((void *)v6, 1953);
  something_database(*(_DWORD *)v4158, v4157, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6322);
  v4159 = (int)std_string_append(&v6320, (int)&Dst, "iron-greataxe3-random3.cub");
  v7813 = 2023;
  v4160 = this_4pointer_off((void *)v6, 1954);
  something_database(*(_DWORD *)v4160, v4159, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6320);
  v4161 = (int)std_string_append(&v6318, (int)&Dst, "iron-greataxe4-random3.cub");
  v7813 = 2024;
  v4162 = this_4pointer_off((void *)v6, 1955);
  something_database(*(_DWORD *)v4162, v4161, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6318);
  v4163 = (int)std_string_append(&v6316, (int)&Dst, "iron-greataxe5-random3.cub");
  v7813 = 2025;
  v4164 = this_4pointer_off((void *)v6, 1956);
  something_database(*(_DWORD *)v4164, v4163, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6316);
  v4165 = (int)std_string_append(&v6314, (int)&Dst, "iron-greataxe1-random4.cub");
  v7813 = 2026;
  v4166 = this_4pointer_off((void *)v6, 1957);
  something_database(*(_DWORD *)v4166, v4165, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6314);
  v4167 = (int)std_string_append(&v6312, (int)&Dst, "iron-greataxe2-random4.cub");
  v7813 = 2027;
  v4168 = this_4pointer_off((void *)v6, 1958);
  something_database(*(_DWORD *)v4168, v4167, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6312);
  v4169 = (int)std_string_append(&v6310, (int)&Dst, "iron-greataxe3-random4.cub");
  v7813 = 2028;
  v4170 = this_4pointer_off((void *)v6, 1959);
  something_database(*(_DWORD *)v4170, v4169, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6310);
  v4171 = (int)std_string_append(&v6308, (int)&Dst, "iron-greataxe4-random4.cub");
  v7813 = 2029;
  v4172 = this_4pointer_off((void *)v6, 1960);
  something_database(*(_DWORD *)v4172, v4171, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6308);
  v4173 = (int)std_string_append(&v6306, (int)&Dst, "iron-greataxe5-random4.cub");
  v7813 = 2030;
  v4174 = this_4pointer_off((void *)v6, 1961);
  something_database(*(_DWORD *)v4174, v4173, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6306);
  v4175 = (int)std_string_append(&v6304, (int)&Dst, "iron-greataxe1-random5.cub");
  v7813 = 2031;
  v4176 = this_4pointer_off((void *)v6, 1962);
  something_database(*(_DWORD *)v4176, v4175, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6304);
  v4177 = (int)std_string_append(&v6302, (int)&Dst, "iron-greataxe2-random5.cub");
  v7813 = 2032;
  v4178 = this_4pointer_off((void *)v6, 1963);
  something_database(*(_DWORD *)v4178, v4177, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6302);
  v4179 = (int)std_string_append(&v6300, (int)&Dst, "iron-greataxe3-random5.cub");
  v7813 = 2033;
  v4180 = this_4pointer_off((void *)v6, 1964);
  something_database(*(_DWORD *)v4180, v4179, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6300);
  v4181 = (int)std_string_append(&v6298, (int)&Dst, "iron-greataxe4-random5.cub");
  v7813 = 2034;
  v4182 = this_4pointer_off((void *)v6, 1965);
  something_database(*(_DWORD *)v4182, v4181, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6298);
  v4183 = (int)std_string_append(&v6296, (int)&Dst, "iron-greataxe5-random5.cub");
  v7813 = 2035;
  v4184 = this_4pointer_off((void *)v6, 1966);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4183;
  something_database(*(_DWORD *)v4184, v4183, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6296);
  v4185 = (int)std_string_append(&v6294, (int)&Dst, "iron-greataxe1-random6.cub");
  v7813 = 2036;
  v4186 = this_4pointer_off((void *)v6, 1967);
  something_database(*(_DWORD *)v4186, v4185, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6294);
  v4187 = (int)std_string_append(&v6292, (int)&Dst, "iron-greataxe2-random6.cub");
  v7813 = 2037;
  v4188 = this_4pointer_off((void *)v6, 1968);
  something_database(*(_DWORD *)v4188, v4187, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6292);
  v4189 = (int)std_string_append(&v6290, (int)&Dst, "iron-greataxe3-random6.cub");
  v7813 = 2038;
  v4190 = this_4pointer_off((void *)v6, 1969);
  something_database(*(_DWORD *)v4190, v4189, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6290);
  v4191 = (int)std_string_append(&v6288, (int)&Dst, "iron-greataxe4-random6.cub");
  v7813 = 2039;
  v4192 = this_4pointer_off((void *)v6, 1970);
  something_database(*(_DWORD *)v4192, v4191, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6288);
  v4193 = (int)std_string_append(&v6286, (int)&Dst, "iron-greataxe5-random6.cub");
  v7813 = 2040;
  v4194 = this_4pointer_off((void *)v6, 1971);
  something_database(*(_DWORD *)v4194, v4193, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6286);
  v4195 = (int)std_string_append(&v6284, (int)&Dst, "iron-greataxe1-random7.cub");
  v7813 = 2041;
  v4196 = this_4pointer_off((void *)v6, 1972);
  something_database(*(_DWORD *)v4196, v4195, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6284);
  v4197 = (int)std_string_append(&v6282, (int)&Dst, "iron-greataxe2-random7.cub");
  v7813 = 2042;
  v4198 = this_4pointer_off((void *)v6, 1973);
  something_database(*(_DWORD *)v4198, v4197, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6282);
  v4199 = (int)std_string_append(&v6280, (int)&Dst, "iron-greataxe3-random7.cub");
  v7813 = 2043;
  v4200 = this_4pointer_off((void *)v6, 1974);
  something_database(*(_DWORD *)v4200, v4199, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6280);
  v4201 = (int)std_string_append(&v6278, (int)&Dst, "iron-greataxe4-random7.cub");
  v7813 = 2044;
  v4202 = this_4pointer_off((void *)v6, 1975);
  something_database(*(_DWORD *)v4202, v4201, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6278);
  v4203 = (int)std_string_append(&v6276, (int)&Dst, "iron-greataxe5-random7.cub");
  v7813 = 2045;
  v4204 = this_4pointer_off((void *)v6, 1976);
  something_database(*(_DWORD *)v4204, v4203, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6276);
  v4205 = (int)std_string_append(&v6274, (int)&Dst, "iron-greataxe1-random8.cub");
  v7813 = 2046;
  v4206 = this_4pointer_off((void *)v6, 1977);
  something_database(*(_DWORD *)v4206, v4205, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6274);
  v4207 = (int)std_string_append(&v6272, (int)&Dst, "iron-greataxe2-random8.cub");
  v7813 = 2047;
  v4208 = this_4pointer_off((void *)v6, 1978);
  something_database(*(_DWORD *)v4208, v4207, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6272);
  v4209 = (int)std_string_append(&v6270, (int)&Dst, "iron-greataxe3-random8.cub");
  v7813 = 2048;
  v4210 = this_4pointer_off((void *)v6, 1979);
  something_database(*(_DWORD *)v4210, v4209, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6270);
  v4211 = (int)std_string_append(&v6268, (int)&Dst, "iron-greataxe4-random8.cub");
  v7813 = 2049;
  v4212 = this_4pointer_off((void *)v6, 1980);
  something_database(*(_DWORD *)v4212, v4211, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6268);
  v4213 = (int)std_string_append(&v6266, (int)&Dst, "iron-greataxe5-random8.cub");
  v7813 = 2050;
  v4214 = this_4pointer_off((void *)v6, 1981);
  something_database(*(_DWORD *)v4214, v4213, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6266);
  v4215 = (int)std_string_append(&v6264, (int)&Dst, "iron-greataxe1-random9.cub");
  v7813 = 2051;
  v4216 = this_4pointer_off((void *)v6, 1982);
  something_database(*(_DWORD *)v4216, v4215, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6264);
  v4217 = (int)std_string_append(&v6262, (int)&Dst, "iron-greataxe2-random9.cub");
  v7813 = 2052;
  v4218 = this_4pointer_off((void *)v6, 1983);
  something_database(*(_DWORD *)v4218, v4217, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6262);
  v4219 = (int)std_string_append(&v6260, (int)&Dst, "iron-greataxe3-random9.cub");
  v7813 = 2053;
  v4220 = this_4pointer_off((void *)v6, 1984);
  something_database(*(_DWORD *)v4220, v4219, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6260);
  v4221 = (int)std_string_append(&v6258, (int)&Dst, (const char *)"iron-greataxe4-random9.cub");
  v7813 = 2054;
  v4222 = this_4pointer_off((void *)v6, 1985);
  something_database(*(_DWORD *)v4222, v4221, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6258);
  v4223 = (int)std_string_append(&v6256, (int)&Dst, "iron-greataxe5-random9.cub");
  v7813 = 2055;
  v4224 = this_4pointer_off((void *)v6, 1986);
  something_database(*(_DWORD *)v4224, v4223, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6256);
  v4225 = (int)std_string_append(&v6254, (int)&Dst, "iron-greataxe1-random10.cub");
  v7813 = 2056;
  v4226 = this_4pointer_off((void *)v6, 1987);
  something_database(*(_DWORD *)v4226, v4225, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6254);
  v4227 = (int)std_string_append(&v6252, (int)&Dst, "iron-greataxe2-random10.cub");
  v7813 = 2057;
  v4228 = this_4pointer_off((void *)v6, 1988);
  something_database(*(_DWORD *)v4228, v4227, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6252);
  v4229 = (int)std_string_append(&v6250, (int)&Dst, "iron-greataxe3-random10.cub");
  v7813 = 2058;
  v4230 = this_4pointer_off((void *)v6, 1989);
  something_database(*(_DWORD *)v4230, v4229, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6250);
  v4231 = (int)std_string_append(&v6248, (int)&Dst, "iron-greataxe4-random10.cub");
  v7813 = 2059;
  v4232 = this_4pointer_off((void *)v6, 1990);
  something_database(*(_DWORD *)v4232, v4231, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6248);
  v4233 = (int)std_string_append(&v6246, (int)&Dst, "iron-greataxe5-random10.cub");
  v7813 = 2060;
  v4234 = this_4pointer_off((void *)v6, 1991);
  something_database(*(_DWORD *)v4234, v4233, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6246);
  v4235 = (int)std_string_append(&v6244, (int)&Dst, "bone-greataxe.cub");
  v7813 = 2061;
  v4236 = this_4pointer_off((void *)v6, 1992);
  something_database(*(_DWORD *)v4236, v4235, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6244);
  v4237 = (int)std_string_append(&v6242, (int)&Dst, "obsidian-greataxe.cub");
  v7813 = 2062;
  v4238 = this_4pointer_off((void *)v6, 1993);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4237;
  something_database(*(_DWORD *)v4238, v4237, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6242);
  v4239 = (int)std_string_append(&v6240, (int)&Dst, "saurian-greataxe.cub");
  v7813 = 2063;
  v4240 = this_4pointer_off((void *)v6, 1994);
  something_database(*(_DWORD *)v4240, v4239, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6240);
  v4241 = (int)std_string_append(&v6238, (int)&Dst, "iron-greatmace1.cub");
  v7813 = 2064;
  v4242 = this_4pointer_off((void *)v6, 1996);
  something_database(*(_DWORD *)v4242, v4241, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6238);
  v4243 = (int)std_string_append(&v6236, (int)&Dst, "iron-greatmace2.cub");
  v7813 = 2065;
  v4244 = this_4pointer_off((void *)v6, 1997);
  something_database(*(_DWORD *)v4244, v4243, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6236);
  v4245 = (int)std_string_append(&v6234, (int)&Dst, "iron-greatmace3.cub");
  v7813 = 2066;
  v4246 = this_4pointer_off((void *)v6, 1998);
  something_database(*(_DWORD *)v4246, v4245, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6234);
  v4247 = (int)std_string_append(&v6232, (int)&Dst, "iron-greatmace4.cub");
  v7813 = 2067;
  v4248 = this_4pointer_off((void *)v6, 1999);
  something_database(*(_DWORD *)v4248, v4247, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6232);
  v4249 = (int)std_string_append(&v6230, (int)&Dst, "iron-greatmace5.cub");
  v7813 = 2068;
  v4250 = this_4pointer_off((void *)v6, 2000);
  something_database(*(_DWORD *)v4250, v4249, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6230);
  v4251 = (int)std_string_append(&v6228, (int)&Dst, "iron-greatmace1-random1.cub");
  v7813 = 2069;
  v4252 = this_4pointer_off((void *)v6, 2001);
  something_database(*(_DWORD *)v4252, v4251, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6228);
  v4253 = (int)std_string_append(&v6226, (int)&Dst, "iron-greatmace2-random1.cub");
  v7813 = 2070;
  v4254 = this_4pointer_off((void *)v6, 2002);
  something_database(*(_DWORD *)v4254, v4253, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6226);
  v4255 = (int)std_string_append(&v6224, (int)&Dst, "iron-greatmace3-random1.cub");
  v7813 = 2071;
  v4256 = this_4pointer_off((void *)v6, 2003);
  something_database(*(_DWORD *)v4256, v4255, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6224);
  v4257 = (int)std_string_append(&v6222, (int)&Dst, "iron-greatmace4-random1.cub");
  v7813 = 2072;
  v4258 = this_4pointer_off((void *)v6, 2004);
  something_database(*(_DWORD *)v4258, v4257, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6222);
  v4259 = (int)std_string_append(&v6220, (int)&Dst, "iron-greatmace5-random1.cub");
  v7813 = 2073;
  v4260 = this_4pointer_off((void *)v6, 2005);
  something_database(*(_DWORD *)v4260, v4259, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6220);
  v4261 = (int)std_string_append(&v6218, (int)&Dst, "iron-greatmace1-random2.cub");
  v7813 = 2074;
  v4262 = this_4pointer_off((void *)v6, 2006);
  something_database(*(_DWORD *)v4262, v4261, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6218);
  v4263 = (int)std_string_append(&v6216, (int)&Dst, "iron-greatmace2-random2.cub");
  v7813 = 2075;
  v4264 = this_4pointer_off((void *)v6, 2007);
  something_database(*(_DWORD *)v4264, v4263, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6216);
  v4265 = (int)std_string_append(&v6214, (int)&Dst, "iron-greatmace3-random2.cub");
  v7813 = 2076;
  v4266 = this_4pointer_off((void *)v6, 2008);
  something_database(*(_DWORD *)v4266, v4265, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6214);
  v4267 = (int)std_string_append(&v6212, (int)&Dst, "iron-greatmace4-random2.cub");
  v7813 = 2077;
  v4268 = this_4pointer_off((void *)v6, 2009);
  something_database(*(_DWORD *)v4268, v4267, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6212);
  v4269 = (int)std_string_append(&v6210, (int)&Dst, "iron-greatmace5-random2.cub");
  v7813 = 2078;
  v4270 = this_4pointer_off((void *)v6, 2010);
  something_database(*(_DWORD *)v4270, v4269, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6210);
  v4271 = (int)std_string_append(&v6208, (int)&Dst, "iron-greatmace1-random3.cub");
  v7813 = 2079;
  v4272 = this_4pointer_off((void *)v6, 2011);
  something_database(*(_DWORD *)v4272, v4271, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6208);
  v4273 = (int)std_string_append(&v6206, (int)&Dst, "iron-greatmace2-random3.cub");
  v7813 = 2080;
  v4274 = this_4pointer_off((void *)v6, 2012);
  something_database(*(_DWORD *)v4274, v4273, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6206);
  v4275 = (int)std_string_append(&v6204, (int)&Dst, "iron-greatmace3-random3.cub");
  v7813 = 2081;
  v4276 = this_4pointer_off((void *)v6, 2013);
  something_database(*(_DWORD *)v4276, v4275, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6204);
  v4277 = (int)std_string_append(&v6202, (int)&Dst, "iron-greatmace4-random3.cub");
  v7813 = 2082;
  v4278 = this_4pointer_off((void *)v6, 2014);
  something_database(*(_DWORD *)v4278, v4277, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6202);
  v4279 = (int)std_string_append(&v6200, (int)&Dst, "iron-greatmace5-random3.cub");
  v7813 = 2083;
  v4280 = this_4pointer_off((void *)v6, 2015);
  something_database(*(_DWORD *)v4280, v4279, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6200);
  v4281 = (int)std_string_append(&v6198, (int)&Dst, (const char *)"iron-greatmace1-random4.cub");
  v7813 = 2084;
  v4282 = this_4pointer_off((void *)v6, 2016);
  something_database(*(_DWORD *)v4282, v4281, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6198);
  v4283 = (int)std_string_append(&v6196, (int)&Dst, "iron-greatmace2-random4.cub");
  v7813 = 2085;
  v4284 = this_4pointer_off((void *)v6, 2017);
  something_database(*(_DWORD *)v4284, v4283, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6196);
  v4285 = (int)std_string_append(&v6194, (int)&Dst, "iron-greatmace3-random4.cub");
  v7813 = 2086;
  v4286 = this_4pointer_off((void *)v6, 2018);
  something_database(*(_DWORD *)v4286, v4285, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6194);
  v4287 = (int)std_string_append(&v6192, (int)&Dst, "iron-greatmace4-random4.cub");
  v7813 = 2087;
  v4288 = this_4pointer_off((void *)v6, 2019);
  something_database(*(_DWORD *)v4288, v4287, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6192);
  v4289 = (int)std_string_append(&v6190, (int)&Dst, "iron-greatmace5-random4.cub");
  v7813 = 2088;
  v4290 = this_4pointer_off((void *)v6, 2020);
  something_database(*(_DWORD *)v4290, v4289, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6190);
  v4291 = (int)std_string_append(&v6188, (int)&Dst, "iron-greatmace1-random5.cub");
  v7813 = 2089;
  v4292 = this_4pointer_off((void *)v6, 2021);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4291;
  something_database(*(_DWORD *)v4292, v4291, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6188);
  v4293 = (int)std_string_append(&v6186, (int)&Dst, "iron-greatmace2-random5.cub");
  v7813 = 2090;
  v4294 = this_4pointer_off((void *)v6, 2022);
  something_database(*(_DWORD *)v4294, v4293, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6186);
  v4295 = (int)std_string_append(&v6184, (int)&Dst, "iron-greatmace3-random5.cub");
  v7813 = 2091;
  v4296 = this_4pointer_off((void *)v6, 2023);
  something_database(*(_DWORD *)v4296, v4295, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6184);
  v4297 = (int)std_string_append(&v6182, (int)&Dst, "iron-greatmace4-random5.cub");
  v7813 = 2092;
  v4298 = this_4pointer_off((void *)v6, 2024);
  something_database(*(_DWORD *)v4298, v4297, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6182);
  v4299 = (int)std_string_append(&v6180, (int)&Dst, "iron-greatmace5-random5.cub");
  v7813 = 2093;
  v4300 = this_4pointer_off((void *)v6, 2025);
  something_database(*(_DWORD *)v4300, v4299, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6180);
  v4301 = (int)std_string_append(&v6178, (int)&Dst, "iron-greatmace1-random6.cub");
  v7813 = 2094;
  v4302 = this_4pointer_off((void *)v6, 2026);
  something_database(*(_DWORD *)v4302, v4301, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6178);
  v4303 = (int)std_string_append(&v6176, (int)&Dst, "iron-greatmace2-random6.cub");
  v7813 = 2095;
  v4304 = this_4pointer_off((void *)v6, 2027);
  something_database(*(_DWORD *)v4304, v4303, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6176);
  v4305 = (int)std_string_append(&v6174, (int)&Dst, "iron-greatmace3-random6.cub");
  v7813 = 2096;
  v4306 = this_4pointer_off((void *)v6, 2028);
  something_database(*(_DWORD *)v4306, v4305, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6174);
  v4307 = (int)std_string_append(&v6172, (int)&Dst, "iron-greatmace4-random6.cub");
  v7813 = 2097;
  v4308 = this_4pointer_off((void *)v6, 2029);
  something_database(*(_DWORD *)v4308, v4307, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6172);
  v4309 = (int)std_string_append(&v6170, (int)&Dst, "iron-greatmace5-random6.cub");
  v7813 = 2098;
  v4310 = this_4pointer_off((void *)v6, 2030);
  something_database(*(_DWORD *)v4310, v4309, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6170);
  v4311 = (int)std_string_append(&v6168, (int)&Dst, "iron-greatmace1-random7.cub");
  v7813 = 2099;
  v4312 = this_4pointer_off((void *)v6, 2031);
  something_database(*(_DWORD *)v4312, v4311, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6168);
  v4313 = (int)std_string_append(&v6166, (int)&Dst, "iron-greatmace2-random7.cub");
  v7813 = 2100;
  v4314 = this_4pointer_off((void *)v6, 2032);
  something_database(*(_DWORD *)v4314, v4313, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6166);
  v4315 = (int)std_string_append(&v6164, (int)&Dst, "iron-greatmace3-random7.cub");
  v7813 = 2101;
  v4316 = this_4pointer_off((void *)v6, 2033);
  something_database(*(_DWORD *)v4316, v4315, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6164);
  v4317 = (int)std_string_append(&v6162, (int)&Dst, "iron-greatmace4-random7.cub");
  v7813 = 2102;
  v4318 = this_4pointer_off((void *)v6, 2034);
  something_database(*(_DWORD *)v4318, v4317, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6162);
  v4319 = (int)std_string_append(&v6160, (int)&Dst, "iron-greatmace5-random7.cub");
  v7813 = 2103;
  v4320 = this_4pointer_off((void *)v6, 2035);
  something_database(*(_DWORD *)v4320, v4319, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6160);
  v4321 = (int)std_string_append(&v6158, (int)&Dst, "iron-greatmace1-random8.cub");
  v7813 = 2104;
  v4322 = this_4pointer_off((void *)v6, 2036);
  something_database(*(_DWORD *)v4322, v4321, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6158);
  v4323 = (int)std_string_append(&v6156, (int)&Dst, "iron-greatmace2-random8.cub");
  v7813 = 2105;
  v4324 = this_4pointer_off((void *)v6, 2037);
  something_database(*(_DWORD *)v4324, v4323, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6156);
  v4325 = (int)std_string_append(&v6154, (int)&Dst, "iron-greatmace3-random8.cub");
  v7813 = 2106;
  v4326 = this_4pointer_off((void *)v6, 2038);
  something_database(*(_DWORD *)v4326, v4325, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6154);
  v4327 = (int)std_string_append(&v6152, (int)&Dst, "iron-greatmace4-random8.cub");
  v7813 = 2107;
  v4328 = this_4pointer_off((void *)v6, 2039);
  something_database(*(_DWORD *)v4328, v4327, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6152);
  v4329 = (int)std_string_append(&v6150, (int)&Dst, "iron-greatmace5-random8.cub");
  v7813 = 2108;
  v4330 = this_4pointer_off((void *)v6, 2040);
  something_database(*(_DWORD *)v4330, v4329, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6150);
  v4331 = (int)std_string_append(&v6148, (int)&Dst, "iron-greatmace1-random9.cub");
  v7813 = 2109;
  v4332 = this_4pointer_off((void *)v6, 2041);
  something_database(*(_DWORD *)v4332, v4331, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6148);
  v4333 = (int)std_string_append(&v6146, (int)&Dst, "iron-greatmace2-random9.cub");
  v7813 = 2110;
  v4334 = this_4pointer_off((void *)v6, 2042);
  something_database(*(_DWORD *)v4334, v4333, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6146);
  v4335 = (int)std_string_append(&v6144, (int)&Dst, "iron-greatmace3-random9.cub");
  v7813 = 2111;
  v4336 = this_4pointer_off((void *)v6, 2043);
  something_database(*(_DWORD *)v4336, v4335, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6144);
  v4337 = (int)std_string_append(&v6142, (int)&Dst, "iron-greatmace4-random9.cub");
  v7813 = 2112;
  v4338 = this_4pointer_off((void *)v6, 2044);
  something_database(*(_DWORD *)v4338, v4337, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6142);
  v4339 = (int)std_string_append(&v6140, (int)&Dst, "iron-greatmace5-random9.cub");
  v7813 = 2113;
  v4340 = this_4pointer_off((void *)v6, 2045);
  something_database(*(_DWORD *)v4340, v4339, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6140);
  v4341 = (int)std_string_append(&v6138, (int)&Dst, "iron-greatmace1-random10.cub");
  v7813 = 2114;
  v4342 = this_4pointer_off((void *)v6, 2046);
  something_database(*(_DWORD *)v4342, v4341, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6138);
  v4343 = (int)std_string_append(&v6136, (int)&Dst, "iron-greatmace2-random10.cub");
  v7813 = 2115;
  v4344 = this_4pointer_off((void *)v6, 2047);
  something_database(*(_DWORD *)v4344, v4343, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6136);
  v4345 = (int)std_string_append(&v6134, (int)&Dst, "iron-greatmace3-random10.cub");
  v7813 = 2116;
  v4346 = this_4pointer_off((void *)v6, 2048);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4345;
  something_database(*(_DWORD *)v4346, v4345, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6134);
  v4347 = (int)std_string_append(&v6132, (int)&Dst, "iron-greatmace4-random10.cub");
  v7813 = 2117;
  v4348 = this_4pointer_off((void *)v6, 2049);
  something_database(*(_DWORD *)v4348, v4347, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6132);
  v4349 = (int)std_string_append(&v6130, (int)&Dst, "iron-greatmace5-random10.cub");
  v7813 = 2118;
  v4350 = this_4pointer_off((void *)v6, 2050);
  something_database(*(_DWORD *)v4350, v4349, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6130);
  v4351 = (int)std_string_append(&v6128, (int)&Dst, "bone-greatmace.cub");
  v7813 = 2119;
  v4352 = this_4pointer_off((void *)v6, 2052);
  something_database(*(_DWORD *)v4352, v4351, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6128);
  v4353 = (int)std_string_append(&v6126, (int)&Dst, "obsidian-greatmace.cub");
  v7813 = 2120;
  v4354 = this_4pointer_off((void *)v6, 2053);
  something_database(*(_DWORD *)v4354, v4353, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6126);
  v4355 = (int)std_string_append(&v6124, (int)&Dst, "wood-greatmace02.cub");
  v7813 = 2121;
  v4356 = this_4pointer_off((void *)v6, 1995);
  something_database(*(_DWORD *)v4356, v4355, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6124);
  v4357 = (int)std_string_append(&v6122, (int)&Dst, "bush.cub");
  v7813 = 2122;
  v4358 = this_4pointer_off((void *)v6, 2087);
  something_database(*(_DWORD *)v4358, v4357, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6122);
  v4359 = (int)std_string_append(&v6120, (int)&Dst, "snow-bush.cub");
  v7813 = 2123;
  v4360 = this_4pointer_off((void *)v6, 2088);
  something_database(*(_DWORD *)v4360, v4359, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6120);
  v4361 = (int)std_string_append(&v6118, (int)&Dst, "cobwebscrub.cub");
  v7813 = 2124;
  v4362 = this_4pointer_off((void *)v6, 2089);
  something_database(*(_DWORD *)v4362, v4361, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6118);
  v4363 = (int)std_string_append(&v6116, (int)&Dst, "berry-bush.cub");
  v7813 = 2125;
  v4364 = this_4pointer_off((void *)v6, 2090);
  something_database(*(_DWORD *)v4364, v4363, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6116);
  v4365 = (int)std_string_append(&v6114, (int)&Dst, "snow-berry.cub");
  v7813 = 2126;
  v4366 = this_4pointer_off((void *)v6, 2091);
  something_database(*(_DWORD *)v4366, v4365, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6114);
  v4367 = (int)std_string_append(&v6112, (int)&Dst, "snow-berry-mash.cub");
  v7813 = 2127;
  v4368 = this_4pointer_off((void *)v6, 2092);
  something_database(*(_DWORD *)v4368, v4367, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6112);
  v4369 = (int)std_string_append(&v6110, (int)&Dst, "cotton-plant.cub");
  v7813 = 2128;
  v4370 = this_4pointer_off((void *)v6, 2159);
  something_database(*(_DWORD *)v4370, v4369, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6110);
  v4371 = (int)std_string_append(&v6108, (int)&Dst, "cotton.cub");
  v7813 = 2129;
  v4372 = this_4pointer_off((void *)v6, 2160);
  something_database(*(_DWORD *)v4372, v4371, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6108);
  v4373 = (int)std_string_append(&v6106, (int)&Dst, "scrub.cub");
  v7813 = 2130;
  v4374 = this_4pointer_off((void *)v6, 2093);
  something_database(*(_DWORD *)v4374, v4373, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6106);
  v4375 = (int)std_string_append(&v6104, (int)&Dst, "scrub-green.cub");
  v7813 = 2131;
  v4376 = this_4pointer_off((void *)v6, 2094);
  something_database(*(_DWORD *)v4376, v4375, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6104);
  v4377 = (int)std_string_append(&v6102, (int)&Dst, "fire-scrub.cub");
  v7813 = 2132;
  v4378 = this_4pointer_off((void *)v6, 2095);
  something_database(*(_DWORD *)v4378, v4377, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6102);
  v4379 = (int)std_string_append(&v6100, (int)&Dst, "fir-tree.cub");
  v7813 = 2133;
  v4380 = this_4pointer_off((void *)v6, 2098);
  something_database(*(_DWORD *)v4380, v4379, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6100);
  v4381 = (int)std_string_append(&v6098, (int)&Dst, "thorn-tree.cub");
  v7813 = 2134;
  v4382 = this_4pointer_off((void *)v6, 2099);
  something_database(*(_DWORD *)v4382, v4381, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6098);
  v4383 = (int)std_string_append(&v6096, (int)&Dst, "tree-leaves.cub");
  v7813 = 2135;
  v4384 = this_4pointer_off((void *)v6, 2112);
  something_database(*(_DWORD *)v4384, v4383, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6096);
  v4385 = (int)std_string_append(&v6094, (int)&Dst, "gold-deposit.cub");
  v7813 = 2136;
  v4386 = this_4pointer_off((void *)v6, 2100);
  something_database(*(_DWORD *)v4386, v4385, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6094);
  v4387 = (int)std_string_append(&v6092, (int)&Dst, "iron-deposit.cub");
  v7813 = 2137;
  v4388 = this_4pointer_off((void *)v6, 2101);
  something_database(*(_DWORD *)v4388, v4387, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6092);
  v4389 = (int)std_string_append(&v6090, (int)&Dst, "silver-deposit.cub");
  v7813 = 2138;
  v4390 = this_4pointer_off((void *)v6, 2102);
  something_database(*(_DWORD *)v4390, v4389, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6090);
  v4391 = (int)std_string_append(&v6088, (int)&Dst, "sandstone-deposit.cub");
  v7813 = 2139;
  v4392 = this_4pointer_off((void *)v6, 2103);
  something_database(*(_DWORD *)v4392, v4391, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6088);
  v4393 = (int)std_string_append(&v6086, (int)&Dst, "emerald-deposit.cub");
  v7813 = 2140;
  v4394 = this_4pointer_off((void *)v6, 2104);
  something_database(*(_DWORD *)v4394, v4393, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6086);
  v4395 = (int)std_string_append(&v6084, (int)&Dst, "ruby-deposit.cub");
  v7813 = 2141;
  v4396 = this_4pointer_off((void *)v6, 2106);
  something_database(*(_DWORD *)v4396, v4395, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6084);
  v4397 = (int)std_string_append(&v6082, (int)&Dst, "diamond-deposit.cub");
  v7813 = 2142;
  v4398 = this_4pointer_off((void *)v6, 2107);
  something_database(*(_DWORD *)v4398, v4397, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6082);
  v4399 = (int)std_string_append(&v6080, (int)&Dst, "sapphire-deposit.cub");
  v7813 = 2143;
  v4400 = this_4pointer_off((void *)v6, 2105);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4399;
  something_database(*(_DWORD *)v4400, v4399, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6080);
  v4401 = (int)std_string_append(&v6078, (int)&Dst, "ice-crystal-deposit.cub");
  v7813 = 2144;
  v4402 = this_4pointer_off((void *)v6, 2108);
  something_database(*(_DWORD *)v4402, v4401, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6078);
  v4403 = (int)std_string_append(&v6076, (int)&Dst, "scarecrow.cub");
  v7813 = 2145;
  v4404 = this_4pointer_off((void *)v6, 2109);
  something_database(*(_DWORD *)v4404, v4403, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6076);
  v4405 = (int)std_string_append(&v6074, (int)&Dst, "dummy.cub");
  v7813 = 2146;
  v4406 = this_4pointer_off((void *)v6, 2111);
  something_database(*(_DWORD *)v4406, v4405, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6074);
  v4407 = (int)std_string_append(&v6072, (int)&Dst, "aim.cub");
  v7813 = 2147;
  v4408 = this_4pointer_off((void *)v6, 2110);
  something_database(*(_DWORD *)v4408, v4407, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6072);
  v4409 = (int)std_string_append(&v6070, (int)&Dst, "vase.cub");
  v7813 = 2148;
  v4410 = this_4pointer_off((void *)v6, 2113);
  something_database(*(_DWORD *)v4410, v4409, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6070);
  v4411 = (int)std_string_append(&v6068, (int)&Dst, "vase2.cub");
  v7813 = 2149;
  v4412 = this_4pointer_off((void *)v6, 2114);
  something_database(*(_DWORD *)v4412, v4411, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6068);
  v4413 = (int)std_string_append(&v6066, (int)&Dst, "vase3.cub");
  v7813 = 2150;
  v4414 = this_4pointer_off((void *)v6, 2115);
  something_database(*(_DWORD *)v4414, v4413, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6066);
  v4415 = (int)std_string_append(&v6064, (int)&Dst, "vase4.cub");
  v7813 = 2151;
  v4416 = this_4pointer_off((void *)v6, 2116);
  something_database(*(_DWORD *)v4416, v4415, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6064);
  v4417 = (int)std_string_append(&v6062, (int)&Dst, "campfire.cub");
  v7813 = 2152;
  v4418 = this_4pointer_off((void *)v6, 2554);
  something_database(*(_DWORD *)v4418, v4417, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6062);
  v4419 = (int)std_string_append(&v6060, (int)&Dst, "tent.cub");
  v7813 = 2153;
  v4420 = this_4pointer_off((void *)v6, 2555);
  something_database(*(_DWORD *)v4420, v4419, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6060);
  v4421 = (int)std_string_append(&v6058, (int)&Dst, "beach-umbrella.cub");
  v7813 = 2154;
  v4422 = this_4pointer_off((void *)v6, 2556);
  something_database(*(_DWORD *)v4422, v4421, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6058);
  v4423 = (int)std_string_append(&v6056, (int)&Dst, "beach-towel.cub");
  v7813 = 2155;
  v4424 = this_4pointer_off((void *)v6, 2557);
  something_database(*(_DWORD *)v4424, v4423, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6056);
  v4425 = (int)std_string_append(&v6054, (int)&Dst, "wood-mat.cub");
  v7813 = 2156;
  v4426 = this_4pointer_off((void *)v6, 2558);
  something_database(*(_DWORD *)v4426, v4425, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6054);
  v4427 = (int)std_string_append(&v6052, (int)&Dst, "candle01.cub");
  v7813 = 2157;
  v4428 = this_4pointer_off((void *)v6, 2117);
  something_database(*(_DWORD *)v4428, v4427, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6052);
  v4429 = (int)std_string_append(&v6050, (int)&Dst, "candle02.cub");
  v7813 = 2158;
  v4430 = this_4pointer_off((void *)v6, 2118);
  something_database(*(_DWORD *)v4430, v4429, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6050);
  v4431 = (int)std_string_append(&v6048, (int)&Dst, "candle03.cub");
  v7813 = 2159;
  v4432 = this_4pointer_off((void *)v6, 2119);
  something_database(*(_DWORD *)v4432, v4431, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6048);
  v4433 = (int)std_string_append(&v6046, (int)&Dst, "compass2.cub");
  v7813 = 2160;
  v4434 = this_4pointer_off((void *)v6, 2559);
  something_database(*(_DWORD *)v4434, v4433, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6046);
  v4435 = (int)std_string_append(&v6044, (int)&Dst, "mission.cub");
  v7813 = 2161;
  v4436 = this_4pointer_off((void *)v6, 2560);
  something_database(*(_DWORD *)v4436, v4435, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6044);
  v4437 = (int)std_string_append(&v6042, (int)&Dst, "city.cub");
  v7813 = 2162;
  v4438 = this_4pointer_off((void *)v6, 2561);
  something_database(*(_DWORD *)v4438, v4437, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6042);
  v4439 = (int)std_string_append(&v6040, (int)&Dst, "skull.cub");
  v7813 = 2163;
  v4440 = this_4pointer_off((void *)v6, 2562);
  something_database(*(_DWORD *)v4440, v4439, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6040);
  v4441 = (int)std_string_append(&v6038, (int)&Dst, "undead-candle1.cub");
  v7813 = 2164;
  v4442 = this_4pointer_off((void *)v6, 2120);
  something_database(*(_DWORD *)v4442, v4441, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6038);
  v4443 = (int)std_string_append(&v6036, (int)&Dst, "undead-candle2.cub");
  v7813 = 2165;
  v4444 = this_4pointer_off((void *)v6, 2121);
  something_database(*(_DWORD *)v4444, v4443, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6036);
  v4445 = (int)std_string_append(&v6034, (int)&Dst, "undead-candle3.cub");
  v7813 = 2166;
  v4446 = this_4pointer_off((void *)v6, 2122);
  something_database(*(_DWORD *)v4446, v4445, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6034);
  v4447 = (int)std_string_append(&v6032, (int)&Dst, "character-platform.cub");
  v7813 = 2167;
  v4448 = this_4pointer_off((void *)v6, 2123);
  something_database(*(_DWORD *)v4448, v4447, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6032);
  v4449 = (int)std_string_append(&v6030, (int)&Dst, "antique-building1.cub");
  v7813 = 2168;
  v4450 = this_4pointer_off((void *)v6, 2124);
  something_database(*(_DWORD *)v4450, v4449, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6030);
  v4451 = (int)std_string_append(&v6028, (int)&Dst, "antique-building2.cub");
  v7813 = 2169;
  v4452 = this_4pointer_off((void *)v6, 2125);
  something_database(*(_DWORD *)v4452, v4451, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6028);
  v4453 = (int)std_string_append(&v6026, (int)&Dst, "antique-building3.cub");
  v7813 = 2170;
  v4454 = this_4pointer_off((void *)v6, 2126);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4453;
  something_database(*(_DWORD *)v4454, v4453, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6026);
  v4455 = (int)std_string_append(&v6024, (int)&Dst, "antique-building4.cub");
  v7813 = 2171;
  v4456 = this_4pointer_off((void *)v6, 2127);
  something_database(*(_DWORD *)v4456, v4455, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6024);
  v4457 = (int)std_string_append(&v6022, (int)&Dst, "entrance-crypt.cub");
  v7813 = 2172;
  v4458 = this_4pointer_off((void *)v6, 2128);
  something_database(*(_DWORD *)v4458, v4457, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6022);
  v4459 = (int)std_string_append(&v6020, (int)&Dst, "entrance-barrow.cub");
  v7813 = 2173;
  v4460 = this_4pointer_off((void *)v6, 2129);
  something_database(*(_DWORD *)v4460, v4459, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6020);
  v4461 = (int)std_string_append(&v6018, (int)&Dst, "entrance-mine.cub");
  v7813 = 2174;
  v4462 = this_4pointer_off((void *)v6, 2130);
  something_database(*(_DWORD *)v4462, v4461, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6018);
  v4463 = (int)std_string_append(&v6016, (int)&Dst, "entrance-antique.cub");
  v7813 = 2175;
  v4464 = this_4pointer_off((void *)v6, 2131);
  something_database(*(_DWORD *)v4464, v4463, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6016);
  v4465 = (int)std_string_append(&v6014, (int)&Dst, "entrance-tomb.cub");
  v7813 = 2176;
  v4466 = this_4pointer_off((void *)v6, 2132);
  something_database(*(_DWORD *)v4466, v4465, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6014);
  v4467 = (int)std_string_append(&v6012, (int)&Dst, "vampire-head.cub");
  v7813 = 2177;
  v4468 = this_4pointer_off((void *)v6, 2171);
  something_database(*(_DWORD *)v4468, v4467, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6012);
  v4469 = (int)std_string_append(&v6010, (int)&Dst, "vampire-hand.cub");
  v7813 = 2178;
  v4470 = this_4pointer_off((void *)v6, 2173);
  something_database(*(_DWORD *)v4470, v4469, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6010);
  v4471 = (int)std_string_append(&v6008, (int)&Dst, "vampire-eyes.cub");
  v7813 = 2179;
  v4472 = this_4pointer_off((void *)v6, 2172);
  something_database(*(_DWORD *)v4472, v4471, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v6008);
  v4473 = (int)std_string_append(&v6006, (int)&Dst, "monster-body-reptile-shell.cub");
  v7813 = 2180;
  v4474 = this_4pointer_off((void *)v6, 2133);
  something_database(*(_DWORD *)v4474, v4473, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6006);
  v4475 = (int)std_string_append(&v6004, (int)&Dst, "monster-body-reptile-shell-spiked.cub");
  v7813 = 2181;
  v4476 = this_4pointer_off((void *)v6, 2134);
  something_database(*(_DWORD *)v4476, v4475, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6004);
  v4477 = (int)std_string_append(&v6002, (int)&Dst, "monster-body-reptile-crest1.cub");
  v7813 = 2182;
  v4478 = this_4pointer_off((void *)v6, 2135);
  something_database(*(_DWORD *)v4478, v4477, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6002);
  v4479 = (int)std_string_append(&v6000, (int)&Dst, "monster-body-reptile-crest2.cub");
  v7813 = 2183;
  v4480 = this_4pointer_off((void *)v6, 2136);
  something_database(*(_DWORD *)v4480, v4479, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v6000);
  v4481 = (int)std_string_append(&v5998, (int)&Dst, "monster-body-reptile-crest3.cub");
  v7813 = 2184;
  v4482 = this_4pointer_off((void *)v6, 2137);
  something_database(*(_DWORD *)v4482, v4481, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5998);
  v4483 = (int)std_string_append(&v5996, (int)&Dst, "monster-body-reptile-crest4.cub");
  v7813 = 2185;
  v4484 = this_4pointer_off((void *)v6, 2138);
  something_database(*(_DWORD *)v4484, v4483, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5996);
  v4485 = (int)std_string_append(&v5994, (int)&Dst, "monster-body-reptile-crest5.cub");
  v7813 = 2186;
  v4486 = this_4pointer_off((void *)v6, 2139);
  something_database(*(_DWORD *)v4486, v4485, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5994);
  v4487 = (int)std_string_append(&v5992, (int)&Dst, "monster-body-reptile-spiked1.cub");
  v7813 = 2187;
  v4488 = this_4pointer_off((void *)v6, 2140);
  something_database(*(_DWORD *)v4488, v4487, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5992);
  v4489 = (int)std_string_append(&v5990, (int)&Dst, "monster-body-reptile-spiked2.cub");
  v7813 = 2188;
  v4490 = this_4pointer_off((void *)v6, 2141);
  something_database(*(_DWORD *)v4490, v4489, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5990);
  v4491 = (int)std_string_append(&v5988, (int)&Dst, "monster-foot-reptile-normal.cub");
  v7813 = 2189;
  v4492 = this_4pointer_off((void *)v6, 2142);
  something_database(*(_DWORD *)v4492, v4491, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5988);
  v4493 = (int)std_string_append(&v5986, (int)&Dst, "monster-foot-reptile-claw1.cub");
  v7813 = 2190;
  v4494 = this_4pointer_off((void *)v6, 2143);
  something_database(*(_DWORD *)v4494, v4493, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5986);
  v4495 = (int)std_string_append(&v5984, (int)&Dst, "monster-foot-reptile-claw2.cub");
  v7813 = 2191;
  v4496 = this_4pointer_off((void *)v6, 2144);
  something_database(*(_DWORD *)v4496, v4495, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5984);
  v4497 = (int)std_string_append(&v5982, (int)&Dst, "monster-head-reptile-lizard.cub");
  v7813 = 2192;
  v4498 = this_4pointer_off((void *)v6, 2145);
  something_database(*(_DWORD *)v4498, v4497, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5982);
  v4499 = (int)std_string_append(&v5980, (int)&Dst, "monster-head-reptile-turtle.cub");
  v7813 = 2193;
  v4500 = this_4pointer_off((void *)v6, 2146);
  something_database(*(_DWORD *)v4500, v4499, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5980);
  v4501 = (int)std_string_append(&v5978, (int)&Dst, "monster-head-reptile-horn1.cub");
  v7813 = 2194;
  v4502 = this_4pointer_off((void *)v6, 2147);
  something_database(*(_DWORD *)v4502, v4501, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5978);
  v4503 = (int)std_string_append(&v5976, (int)&Dst, "monster-head-reptile-horn2.cub");
  v7813 = 2195;
  v4504 = this_4pointer_off((void *)v6, 2148);
  something_database(*(_DWORD *)v4504, v4503, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5976);
  v4505 = (int)std_string_append(&v5974, (int)&Dst, "monster-head-reptile-horn3.cub");
  v7813 = 2196;
  v4506 = this_4pointer_off((void *)v6, 2149);
  something_database(*(_DWORD *)v4506, v4505, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5974);
  v4507 = (int)std_string_append(&v5972, (int)&Dst, "monster-tail-reptile-normal.cub");
  v7813 = 2197;
  v4508 = this_4pointer_off((void *)v6, 2150);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4507;
  something_database(*(_DWORD *)v4508, v4507, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5972);
  v4509 = (int)std_string_append(&v5970, (int)&Dst, "monster-tail-reptile-spike1.cub");
  v7813 = 2198;
  v4510 = this_4pointer_off((void *)v6, 2151);
  something_database(*(_DWORD *)v4510, v4509, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5970);
  v4511 = (int)std_string_append(&v5968, (int)&Dst, "monster-tail-reptile-spike2.cub");
  v7813 = 2199;
  v4512 = this_4pointer_off((void *)v6, 2152);
  something_database(*(_DWORD *)v4512, v4511, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5968);
  v4513 = (int)std_string_append(&v5966, (int)&Dst, "rune-giant-foot01.cub");
  v7813 = 2200;
  v4514 = this_4pointer_off((void *)v6, 2158);
  something_database(*(_DWORD *)v4514, v4513, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5966);
  v4515 = (int)std_string_append(&v5964, (int)&Dst, "rune-giant-head-normal01.cub");
  v7813 = 2201;
  v4516 = this_4pointer_off((void *)v6, 2153);
  something_database(*(_DWORD *)v4516, v4515, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5964);
  v4517 = (int)std_string_append(&v5962, (int)&Dst, "rune-giant-head-laser.cub");
  v7813 = 2202;
  v4518 = this_4pointer_off((void *)v6, 2154);
  something_database(*(_DWORD *)v4518, v4517, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5962);
  v4519 = (int)std_string_append(&v5960, (int)&Dst, "rune-giant-body01.cub");
  v7813 = 2203;
  v4520 = this_4pointer_off((void *)v6, 2155);
  something_database(*(_DWORD *)v4520, v4519, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5960);
  v4521 = (int)std_string_append(&v5958, (int)&Dst, "rune-giant-body02.cub");
  v7813 = 2204;
  v4522 = this_4pointer_off((void *)v6, 2156);
  something_database(*(_DWORD *)v4522, v4521, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5958);
  v4523 = (int)std_string_append(&v5956, (int)&Dst, "rune-giant-hand01.cub");
  v7813 = 2205;
  v4524 = this_4pointer_off((void *)v6, 2157);
  something_database(*(_DWORD *)v4524, v4523, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5956);
  v4525 = (int)std_string_append(&v5954, (int)&Dst, "building-stilt-inn1.cub");
  v7813 = 2206;
  v4526 = this_4pointer_off((void *)v6, 2179);
  something_database(*(_DWORD *)v4526, v4525, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5954);
  v4527 = (int)std_string_append(&v5952, (int)&Dst, "building-stilt-hut2.cub");
  v7813 = 2207;
  v4528 = this_4pointer_off((void *)v6, 2181);
  something_database(*(_DWORD *)v4528, v4527, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5952);
  v4529 = (int)std_string_append(&v5950, (int)&Dst, "building-stilt-hut3.cub");
  v7813 = 2208;
  v4530 = this_4pointer_off((void *)v6, 2180);
  something_database(*(_DWORD *)v4530, v4529, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5950);
  v4531 = (int)std_string_append(&v5948, (int)&Dst, "building-stilt-path.cub");
  v7813 = 2209;
  v4532 = this_4pointer_off((void *)v6, 2182);
  something_database(*(_DWORD *)v4532, v4531, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5948);
  v4533 = (int)std_string_append(&v5946, (int)&Dst, "frame-house01.cub");
  v7813 = 2210;
  v4534 = this_4pointer_off((void *)v6, 2174);
  something_database(*(_DWORD *)v4534, v4533, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5946);
  v4535 = (int)std_string_append(&v5944, (int)&Dst, "frame-inn.cub");
  v7813 = 2211;
  v4536 = this_4pointer_off((void *)v6, 2175);
  something_database(*(_DWORD *)v4536, v4535, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5944);
  v4537 = (int)std_string_append(&v5942, (int)&Dst, "frame-shop.cub");
  v7813 = 2212;
  v4538 = this_4pointer_off((void *)v6, 2176);
  something_database(*(_DWORD *)v4538, v4537, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5942);
  v4539 = (int)std_string_append(&v5940, (int)&Dst, "frame-tower.cub");
  v7813 = 2213;
  v4540 = this_4pointer_off((void *)v6, 2177);
  something_database(*(_DWORD *)v4540, v4539, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5940);
  v4541 = (int)std_string_append(&v5938, (int)&Dst, "building-stone-well.cub");
  v7813 = 2214;
  v4542 = this_4pointer_off((void *)v6, 2178);
  something_database(*(_DWORD *)v4542, v4541, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5938);
  v4543 = (int)std_string_append(&v5936, (int)&Dst, "landingplace.cub");
  v7813 = 2215;
  v4544 = this_4pointer_off((void *)v6, 2183);
  something_database(*(_DWORD *)v4544, v4543, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5936);
  v4545 = (int)std_string_append(&v5934, (int)&Dst, "building-warrior.cub");
  v7813 = 2216;
  v4546 = this_4pointer_off((void *)v6, 2303);
  something_database(*(_DWORD *)v4546, v4545, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5934);
  v4547 = (int)std_string_append(&v5932, (int)&Dst, "building-ranger.cub");
  v7813 = 2217;
  v4548 = this_4pointer_off((void *)v6, 2304);
  something_database(*(_DWORD *)v4548, v4547, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5932);
  v4549 = (int)std_string_append(&v5930, (int)&Dst, "building-rogue.cub");
  v7813 = 2218;
  v4550 = this_4pointer_off((void *)v6, 2305);
  something_database(*(_DWORD *)v4550, v4549, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5930);
  v4551 = (int)std_string_append(&v5928, (int)&Dst, "building-mage.cub");
  v7813 = 2219;
  v4552 = this_4pointer_off((void *)v6, 2306);
  something_database(*(_DWORD *)v4552, v4551, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5928);
  v4553 = (int)std_string_append(&v5926, (int)&Dst, "building-smithy.cub");
  v7813 = 2220;
  v4554 = this_4pointer_off((void *)v6, 2307);
  something_database(*(_DWORD *)v4554, v4553, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5926);
  v4555 = (int)std_string_append(&v5924, (int)&Dst, "building-carpentersshop.cub");
  v7813 = 2221;
  v4556 = this_4pointer_off((void *)v6, 2308);
  something_database(*(_DWORD *)v4556, v4555, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5924);
  v4557 = (int)std_string_append(&v5922, (int)&Dst, "building-weavingmill.cub");
  v7813 = 2222;
  v4558 = this_4pointer_off((void *)v6, 2309);
  something_database(*(_DWORD *)v4558, v4557, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5922);
  v4559 = (int)std_string_append(&v5920, (int)&Dst, "palm-leaf.cub");
  v7813 = 2223;
  v4560 = this_4pointer_off((void *)v6, 2300);
  something_database(*(_DWORD *)v4560, v4559, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5920);
  v4561 = (int)std_string_append(&v5918, (int)&Dst, "palm-leaf-diagonal.cub");
  v7813 = 2224;
  v4562 = this_4pointer_off((void *)v6, 2301);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4561;
  something_database(*(_DWORD *)v4562, v4561, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5918);
  v4563 = (int)std_string_append(&v5916, (int)&Dst, "white-castle-round-tower.cub");
  v7813 = 2225;
  v4564 = this_4pointer_off((void *)v6, 2302);
  something_database(*(_DWORD *)v4564, v4563, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5916);
  v4565 = (int)std_string_append(&v5914, (int)&Dst, "painting01.cub");
  v7813 = 2226;
  v4566 = this_4pointer_off((void *)v6, 2313);
  something_database(*(_DWORD *)v4566, v4565, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5914);
  v4567 = (int)std_string_append(&v5912, (int)&Dst, "painting02.cub");
  v7813 = 2227;
  v4568 = this_4pointer_off((void *)v6, 2314);
  something_database(*(_DWORD *)v4568, v4567, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5912);
  v4569 = (int)std_string_append(&v5910, (int)&Dst, "digested-leftovers01.cub");
  v7813 = 2228;
  v4570 = this_4pointer_off((void *)v6, 2318);
  something_database(*(_DWORD *)v4570, v4569, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5910);
  v4571 = (int)std_string_append(&v5908, (int)&Dst, "digested-leftovers02.cub");
  v7813 = 2229;
  v4572 = this_4pointer_off((void *)v6, 2319);
  something_database(*(_DWORD *)v4572, v4571, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5908);
  v4573 = (int)std_string_append(&v5906, (int)&Dst, "digested-leftovers03.cub");
  v7813 = 2230;
  v4574 = this_4pointer_off((void *)v6, 2320);
  something_database(*(_DWORD *)v4574, v4573, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5906);
  v4575 = (int)std_string_append(&v5904, (int)&Dst, "digested-leftovers04.cub");
  v7813 = 2231;
  v4576 = this_4pointer_off((void *)v6, 2321);
  something_database(*(_DWORD *)v4576, v4575, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5904);
  v4577 = (int)std_string_append(&v5902, (int)&Dst, "icon-talk.cub");
  v7813 = 2232;
  v4578 = this_4pointer_off((void *)v6, 2315);
  something_database(*(_DWORD *)v4578, v4577, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5902);
  v4579 = (int)std_string_append(&v5900, (int)&Dst, "icon-analyze.cub");
  v7813 = 2233;
  v4580 = this_4pointer_off((void *)v6, 2316);
  something_database(*(_DWORD *)v4580, v4579, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5900);
  v4581 = (int)std_string_append(&v5898, (int)&Dst, "icon-vendor.cub");
  v7813 = 2234;
  v4582 = this_4pointer_off((void *)v6, 2317);
  something_database(*(_DWORD *)v4582, v4581, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5898);
  v4583 = (int)std_string_append(&v5896, (int)&Dst, "flower-vase1.cub");
  v7813 = 2235;
  v4584 = this_4pointer_off((void *)v6, 2322);
  something_database(*(_DWORD *)v4584, v4583, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5896);
  v4585 = (int)std_string_append(&v5894, (int)&Dst, "flower-vase2.cub");
  v7813 = 2236;
  v4586 = this_4pointer_off((void *)v6, 2323);
  something_database(*(_DWORD *)v4586, v4585, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5894);
  v4587 = (int)std_string_append(&v5892, (int)&Dst, "flower-vase3.cub");
  v7813 = 2237;
  v4588 = this_4pointer_off((void *)v6, 2324);
  something_database(*(_DWORD *)v4588, v4587, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5892);
  v4589 = (int)std_string_append(&v5890, (int)&Dst, "flower-vase4.cub");
  v7813 = 2238;
  v4590 = this_4pointer_off((void *)v6, 2325);
  something_database(*(_DWORD *)v4590, v4589, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5890);
  v4591 = (int)std_string_append(&v5888, (int)&Dst, "flower-vase5.cub");
  v7813 = 2239;
  v4592 = this_4pointer_off((void *)v6, 2326);
  something_database(*(_DWORD *)v4592, v4591, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5888);
  v4593 = (int)std_string_append(&v5886, (int)&Dst, "flower-vase6.cub");
  v7813 = 2240;
  v4594 = this_4pointer_off((void *)v6, 2327);
  something_database(*(_DWORD *)v4594, v4593, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5886);
  v4595 = (int)std_string_append(&v5884, (int)&Dst, "flower-vase7.cub");
  v7813 = 2241;
  v4596 = this_4pointer_off((void *)v6, 2328);
  something_database(*(_DWORD *)v4596, v4595, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5884);
  v4597 = (int)std_string_append(&v5882, (int)&Dst, "flower-vase8.cub");
  v7813 = 2242;
  v4598 = this_4pointer_off((void *)v6, 2329);
  something_database(*(_DWORD *)v4598, v4597, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5882);
  v4599 = (int)std_string_append(&v5880, (int)&Dst, "flower-vase9.cub");
  v7813 = 2243;
  v4600 = this_4pointer_off((void *)v6, 2330);
  something_database(*(_DWORD *)v4600, v4599, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5880);
  v4601 = (int)std_string_append(&v5878, (int)&Dst, "pitchfork.cub");
  v7813 = 2244;
  v4602 = this_4pointer_off((void *)v6, 2331);
  something_database(*(_DWORD *)v4602, v4601, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5878);
  v4603 = (int)std_string_append(&v5876, (int)&Dst, "cactus1.cub");
  v7813 = 2245;
  v4604 = this_4pointer_off((void *)v6, 2310);
  something_database(*(_DWORD *)v4604, v4603, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5876);
  v4605 = (int)std_string_append(&v5874, (int)&Dst, "cactus2.cub");
  v7813 = 2246;
  v4606 = this_4pointer_off((void *)v6, 2311);
  something_database(*(_DWORD *)v4606, v4605, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5874);
  v4607 = (int)std_string_append(&v5872, (int)&Dst, "pumpkin.cub");
  v7813 = 2247;
  v4608 = this_4pointer_off((void *)v6, 2332);
  something_database(*(_DWORD *)v4608, v4607, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5872);
  v4609 = (int)std_string_append(&v5870, (int)&Dst, "pumpkin-muffin.cub");
  v7813 = 2248;
  v4610 = this_4pointer_off((void *)v6, 2333);
  something_database(*(_DWORD *)v4610, v4609, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5870);
  v4611 = (int)std_string_append(&v5868, (int)&Dst, "pineapple.cub");
  v7813 = 2249;
  v4612 = this_4pointer_off((void *)v6, 2334);
  something_database(*(_DWORD *)v4612, v4611, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5868);
  v4613 = (int)std_string_append(&v5866, (int)&Dst, "pineapple-slice.cub");
  v7813 = 2250;
  v4614 = this_4pointer_off((void *)v6, 2335);
  something_database(*(_DWORD *)v4614, v4613, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5866);
  v4615 = (int)std_string_append(&v5864, (int)&Dst, "iron-nugget.cub");
  v7813 = 2251;
  v4616 = this_4pointer_off((void *)v6, 2337);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4615;
  something_database(*(_DWORD *)v4616, v4615, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5864);
  v4617 = (int)std_string_append(&v5862, (int)&Dst, "gold-nugget.cub");
  v7813 = 2252;
  v4618 = this_4pointer_off((void *)v6, 2339);
  something_database(*(_DWORD *)v4618, v4617, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5862);
  v4619 = (int)std_string_append(&v5860, (int)&Dst, "silver-nugget.cub");
  v7813 = 2253;
  v4620 = this_4pointer_off((void *)v6, 2338);
  something_database(*(_DWORD *)v4620, v4619, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5860);
  v4621 = (int)std_string_append(&v5858, (int)&Dst, "emerald-nugget.cub");
  v7813 = 2254;
  v4622 = this_4pointer_off((void *)v6, 2340);
  something_database(*(_DWORD *)v4622, v4621, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5858);
  v4623 = (int)std_string_append(&v5856, (int)&Dst, "sapphire-nugget.cub");
  v7813 = 2255;
  v4624 = this_4pointer_off((void *)v6, 2341);
  something_database(*(_DWORD *)v4624, v4623, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5856);
  v4625 = (int)std_string_append(&v5854, (int)&Dst, "ruby-nugget.cub");
  v7813 = 2256;
  v4626 = this_4pointer_off((void *)v6, 2342);
  something_database(*(_DWORD *)v4626, v4625, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5854);
  v4627 = (int)std_string_append(&v5852, (int)&Dst, "diamond-nugget.cub");
  v7813 = 2257;
  v4628 = this_4pointer_off((void *)v6, 2343);
  something_database(*(_DWORD *)v4628, v4627, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5852);
  v4629 = (int)std_string_append(&v5850, (int)&Dst, "ice-crystal.cub");
  v7813 = 2258;
  v4630 = this_4pointer_off((void *)v6, 2357);
  something_database(*(_DWORD *)v4630, v4629, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5850);
  v4631 = (int)std_string_append(&v5848, (int)&Dst, "ice-coated-yarn.cub");
  v7813 = 2259;
  v4632 = this_4pointer_off((void *)v6, 2363);
  something_database(*(_DWORD *)v4632, v4631, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5848);
  v4633 = (int)std_string_append(&v5846, (int)&Dst, "iron-cube.cub");
  v7813 = 2260;
  v4634 = this_4pointer_off((void *)v6, 2344);
  something_database(*(_DWORD *)v4634, v4633, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5846);
  v4635 = (int)std_string_append(&v5844, (int)&Dst, "gold-cube.cub");
  v7813 = 2261;
  v4636 = this_4pointer_off((void *)v6, 2346);
  something_database(*(_DWORD *)v4636, v4635, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5844);
  v4637 = (int)std_string_append(&v5842, (int)&Dst, "silver-cube.cub");
  v7813 = 2262;
  v4638 = this_4pointer_off((void *)v6, 2345);
  something_database(*(_DWORD *)v4638, v4637, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5842);
  v4639 = (int)std_string_append(&v5840, (int)&Dst, "wood-cube.cub");
  v7813 = 2263;
  v4640 = this_4pointer_off((void *)v6, 2347);
  something_database(*(_DWORD *)v4640, v4639, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5840);
  v4641 = (int)std_string_append(&v5838, (int)&Dst, "fire-cube.cub");
  v7813 = 2264;
  v4642 = this_4pointer_off((void *)v6, 2348);
  something_database(*(_DWORD *)v4642, v4641, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5838);
  v4643 = (int)std_string_append(&v5836, (int)&Dst, "ice-cube.cub");
  v7813 = 2265;
  v4644 = this_4pointer_off((void *)v6, 2349);
  something_database(*(_DWORD *)v4644, v4643, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5836);
  v4645 = (int)std_string_append(&v5834, (int)&Dst, "unholy-cube.cub");
  v7813 = 2266;
  v4646 = this_4pointer_off((void *)v6, 2350);
  something_database(*(_DWORD *)v4646, v4645, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5834);
  v4647 = (int)std_string_append(&v5832, (int)&Dst, "wind-cube.cub");
  v7813 = 2267;
  v4648 = this_4pointer_off((void *)v6, 2351);
  something_database(*(_DWORD *)v4648, v4647, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5832);
  v4649 = (int)std_string_append(&v5830, (int)&Dst, "cobweb.cub");
  v7813 = 2268;
  v4650 = this_4pointer_off((void *)v6, 2352);
  something_database(*(_DWORD *)v4650, v4649, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5830);
  v4651 = (int)std_string_append(&v5828, (int)&Dst, "sandstone.cub");
  v7813 = 2269;
  v4652 = this_4pointer_off((void *)v6, 2364);
  something_database(*(_DWORD *)v4652, v4651, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5828);
  v4653 = (int)std_string_append(&v5826, (int)&Dst, "wood-log.cub");
  v7813 = 2270;
  v4654 = this_4pointer_off((void *)v6, 2365);
  something_database(*(_DWORD *)v4654, v4653, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5826);
  v4655 = (int)std_string_append(&v5824, (int)&Dst, "desert-rib.cub");
  v7813 = 2271;
  v4656 = this_4pointer_off((void *)v6, 2397);
  something_database(*(_DWORD *)v4656, v4655, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5824);
  v4657 = (int)std_string_append(&v5822, (int)&Dst, "desert-skull.cub");
  v7813 = 2272;
  v4658 = this_4pointer_off((void *)v6, 2398);
  something_database(*(_DWORD *)v4658, v4657, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5822);
  v4659 = (int)std_string_append(&v5820, (int)&Dst, "iron-pickaxe.cub");
  v7813 = 2273;
  v4660 = this_4pointer_off((void *)v6, 2051);
  something_database(*(_DWORD *)v4660, v4659, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5820);
  v4661 = (int)std_string_append(&v5818, (int)&Dst, "slime-green.cub");
  v7813 = 2274;
  v4662 = this_4pointer_off((void *)v6, 2399);
  something_database(*(_DWORD *)v4662, v4661, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5818);
  v4663 = (int)std_string_append(&v5816, (int)&Dst, "slime-yellow.cub");
  v7813 = 2275;
  v4664 = this_4pointer_off((void *)v6, 2401);
  something_database(*(_DWORD *)v4664, v4663, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5816);
  v4665 = (int)std_string_append(&v5814, (int)&Dst, "slime-pink.cub");
  v7813 = 2276;
  v4666 = this_4pointer_off((void *)v6, 2400);
  something_database(*(_DWORD *)v4666, v4665, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5814);
  v4667 = (int)std_string_append(&v5812, (int)&Dst, "slime-blue.cub");
  v7813 = 2277;
  v4668 = this_4pointer_off((void *)v6, 2402);
  something_database(*(_DWORD *)v4668, v4667, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5812);
  v4669 = (int)std_string_append(&v5810, (int)&Dst, "frightener-head.cub");
  v7813 = 2278;
  v4670 = this_4pointer_off((void *)v6, 2403);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4669;
  something_database(*(_DWORD *)v4670, v4669, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5810);
  v4671 = (int)std_string_append(&v5808, (int)&Dst, "frightener-eyes.cub");
  v7813 = 2279;
  v4672 = this_4pointer_off((void *)v6, 2404);
  something_database(*(_DWORD *)v4672, v4671, v5247, 0);
  v7813 = 1;
  delete_std_string((int)&v5808);
  v4673 = (int)std_string_append(&v5806, (int)&Dst, "sand-horror-head.cub");
  v7813 = 2280;
  v4674 = this_4pointer_off((void *)v6, 2405);
  something_database(*(_DWORD *)v4674, v4673, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5806);
  v4675 = (int)std_string_append(&v5804, (int)&Dst, "sand-horror-hand.cub");
  v7813 = 2281;
  v4676 = this_4pointer_off((void *)v6, 2406);
  something_database(*(_DWORD *)v4676, v4675, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5804);
  v4677 = (int)std_string_append(&v5802, (int)&Dst, "bunny-body.cub");
  v7813 = 2282;
  v4678 = this_4pointer_off((void *)v6, 154);
  something_database(*(_DWORD *)v4678, v4677, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5802);
  v4679 = (int)std_string_append(&v5800, (int)&Dst, "bunny-foot.cub");
  v7813 = 2283;
  v4680 = this_4pointer_off((void *)v6, 155);
  something_database(*(_DWORD *)v4680, v4679, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5800);
  v4681 = (int)std_string_append(&v5798, (int)&Dst, "porcupine-body.cub");
  v7813 = 2284;
  v4682 = this_4pointer_off((void *)v6, 156);
  something_database(*(_DWORD *)v4682, v4681, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5798);
  v4683 = (int)std_string_append(&v5796, (int)&Dst, "porcupine-foot.cub");
  v7813 = 2285;
  v4684 = this_4pointer_off((void *)v6, 157);
  something_database(*(_DWORD *)v4684, v4683, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5796);
  v4685 = (int)std_string_append(&v5794, (int)&Dst, "pig-body.cub");
  v7813 = 2286;
  v4686 = this_4pointer_off((void *)v6, 412);
  something_database(*(_DWORD *)v4686, v4685, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5794);
  v4687 = (int)std_string_append(&v5792, (int)&Dst, "pig-foot.cub");
  v7813 = 2287;
  v4688 = this_4pointer_off((void *)v6, 414);
  something_database(*(_DWORD *)v4688, v4687, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5792);
  v4689 = (int)std_string_append(&v5790, (int)&Dst, "pig-head.cub");
  v7813 = 2288;
  v4690 = this_4pointer_off((void *)v6, 413);
  something_database(*(_DWORD *)v4690, v4689, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5790);
  v4691 = (int)std_string_append(&v5788, (int)&Dst, "sheep-body.cub");
  v7813 = 2289;
  v4692 = this_4pointer_off((void *)v6, 415);
  something_database(*(_DWORD *)v4692, v4691, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5788);
  v4693 = (int)std_string_append(&v5786, (int)&Dst, "sheep-foot.cub");
  v7813 = 2290;
  v4694 = this_4pointer_off((void *)v6, 417);
  something_database(*(_DWORD *)v4694, v4693, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5786);
  v4695 = (int)std_string_append(&v5784, (int)&Dst, "sheep-head.cub");
  v7813 = 2291;
  v4696 = this_4pointer_off((void *)v6, 416);
  something_database(*(_DWORD *)v4696, v4695, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5784);
  v4697 = (int)std_string_append(&v5782, (int)&Dst, "duckbill-body.cub");
  v7813 = 2292;
  v4698 = this_4pointer_off((void *)v6, 418);
  something_database(*(_DWORD *)v4698, v4697, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5782);
  v4699 = (int)std_string_append(&v5780, (int)&Dst, "duckbill-foot.cub");
  v7813 = 2293;
  v4700 = this_4pointer_off((void *)v6, 420);
  something_database(*(_DWORD *)v4700, v4699, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5780);
  v4701 = (int)std_string_append(&v5778, (int)&Dst, "duckbill-head.cub");
  v7813 = 2294;
  v4702 = this_4pointer_off((void *)v6, 419);
  something_database(*(_DWORD *)v4702, v4701, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5778);
  v4703 = (int)std_string_append(&v5776, (int)&Dst, "duckbill-tail.cub");
  v7813 = 2295;
  v4704 = this_4pointer_off((void *)v6, 421);
  something_database(*(_DWORD *)v4704, v4703, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5776);
  v4705 = (int)std_string_append(&v5774, (int)&Dst, "crocodile-body.cub");
  v7813 = 2296;
  v4706 = this_4pointer_off((void *)v6, 422);
  something_database(*(_DWORD *)v4706, v4705, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5774);
  v4707 = (int)std_string_append(&v5772, (int)&Dst, "crocodile-foot.cub");
  v7813 = 2297;
  v4708 = this_4pointer_off((void *)v6, 424);
  something_database(*(_DWORD *)v4708, v4707, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5772);
  v4709 = (int)std_string_append(&v5770, (int)&Dst, "crocodile-head.cub");
  v7813 = 2298;
  v4710 = this_4pointer_off((void *)v6, 423);
  something_database(*(_DWORD *)v4710, v4709, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5770);
  v4711 = (int)std_string_append(&v5768, (int)&Dst, "fish1.cub");
  v7813 = 2299;
  v4712 = this_4pointer_off((void *)v6, 2410);
  something_database(*(_DWORD *)v4712, v4711, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5768);
  v4713 = (int)std_string_append(&v5766, (int)&Dst, "fish2.cub");
  v7813 = 2300;
  v4714 = this_4pointer_off((void *)v6, 2411);
  something_database(*(_DWORD *)v4714, v4713, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5766);
  v4715 = (int)std_string_append(&v5764, (int)&Dst, "shark.cub");
  v7813 = 2301;
  v4716 = this_4pointer_off((void *)v6, 2412);
  something_database(*(_DWORD *)v4716, v4715, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5764);
  v4717 = (int)std_string_append(&v5762, (int)&Dst, "seahorse.cub");
  v7813 = 2302;
  v4718 = this_4pointer_off((void *)v6, 2418);
  something_database(*(_DWORD *)v4718, v4717, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5762);
  v4719 = (int)std_string_append(&v5760, (int)&Dst, "lantern-fish.cub");
  v7813 = 2303;
  v4720 = this_4pointer_off((void *)v6, 2413);
  something_database(*(_DWORD *)v4720, v4719, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5760);
  v4721 = (int)std_string_append(&v5758, (int)&Dst, "lantern-fish-eyes.cub");
  v7813 = 2304;
  v4722 = this_4pointer_off((void *)v6, 2414);
  something_database(*(_DWORD *)v4722, v4721, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5758);
  v4723 = (int)std_string_append(&v5756, (int)&Dst, "mawfish.cub");
  v7813 = 2305;
  v4724 = this_4pointer_off((void *)v6, 2415);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4723;
  something_database(*(_DWORD *)v4724, v4723, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5756);
  v4725 = (int)std_string_append(&v5754, (int)&Dst, "piranha.cub");
  v7813 = 2306;
  v4726 = this_4pointer_off((void *)v6, 2416);
  something_database(*(_DWORD *)v4726, v4725, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5754);
  v4727 = (int)std_string_append(&v5752, (int)&Dst, "blowfish.cub");
  v7813 = 2307;
  v4728 = this_4pointer_off((void *)v6, 2417);
  something_database(*(_DWORD *)v4728, v4727, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5752);
  v4729 = (int)std_string_append(&v5750, (int)&Dst, "seastar.cub");
  v7813 = 2308;
  v4730 = this_4pointer_off((void *)v6, 2407);
  something_database(*(_DWORD *)v4730, v4729, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5750);
  v4731 = (int)std_string_append(&v5748, (int)&Dst, "bread.cub");
  v7813 = 2309;
  v4732 = this_4pointer_off((void *)v6, 2408);
  something_database(*(_DWORD *)v4732, v4731, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5748);
  v4733 = (int)std_string_append(&v5746, (int)&Dst, "sandwich.cub");
  v7813 = 2310;
  v4734 = this_4pointer_off((void *)v6, 2409);
  something_database(*(_DWORD *)v4734, v4733, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5746);
  v4735 = (int)std_string_append(&v5744, (int)&Dst, "unknown.cub");
  v7813 = 2311;
  v4736 = this_4pointer_off((void *)v6, 2396);
  something_database(*(_DWORD *)v4736, v4735, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5744);
  v4737 = (int)std_string_append(&v5742, (int)&Dst, "key1.cub");
  v7813 = 2312;
  v4738 = this_4pointer_off((void *)v6, 2422);
  something_database(*(_DWORD *)v4738, v4737, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5742);
  v4739 = (int)std_string_append(&v5740, (int)&Dst, "flowers2.cub");
  v7813 = 2313;
  v4740 = this_4pointer_off((void *)v6, 2423);
  something_database(*(_DWORD *)v4740, v4739, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5740);
  v4741 = (int)std_string_append(&v5738, (int)&Dst, "flowers.cub");
  v7813 = 2314;
  v4742 = this_4pointer_off((void *)v6, 2424);
  something_database(*(_DWORD *)v4742, v4741, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5738);
  v4743 = (int)std_string_append(&v5736, (int)&Dst, "grass.cub");
  v7813 = 2315;
  v4744 = this_4pointer_off((void *)v6, 2425);
  something_database(*(_DWORD *)v4744, v4743, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5736);
  v4745 = (int)std_string_append(&v5734, (int)&Dst, "grass2.cub");
  v7813 = 2316;
  v4746 = this_4pointer_off((void *)v6, 2426);
  something_database(*(_DWORD *)v4746, v4745, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5734);
  v4747 = (int)std_string_append(&v5732, (int)&Dst, "grass3.cub");
  v7813 = 2317;
  v4748 = this_4pointer_off((void *)v6, 2427);
  something_database(*(_DWORD *)v4748, v4747, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5732);
  v4749 = (int)std_string_append(&v5730, (int)&Dst, "lava-flower.cub");
  v7813 = 2318;
  v4750 = this_4pointer_off((void *)v6, 2428);
  something_database(*(_DWORD *)v4750, v4749, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5730);
  v4751 = (int)std_string_append(&v5728, (int)&Dst, "lava-grass.cub");
  v7813 = 2319;
  v4752 = this_4pointer_off((void *)v6, 2429);
  something_database(*(_DWORD *)v4752, v4751, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5728);
  v4753 = (int)std_string_append(&v5726, (int)&Dst, "thorn-plant.cub");
  v7813 = 2320;
  v4754 = this_4pointer_off((void *)v6, 2430);
  something_database(*(_DWORD *)v4754, v4753, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5726);
  v4755 = (int)std_string_append(&v5724, (int)&Dst, "echinacea2.cub");
  v7813 = 2321;
  v4756 = this_4pointer_off((void *)v6, 2431);
  something_database(*(_DWORD *)v4756, v4755, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5724);
  v4757 = (int)std_string_append(&v5722, (int)&Dst, "leaf.cub");
  v7813 = 2322;
  v4758 = this_4pointer_off((void *)v6, 2432);
  something_database(*(_DWORD *)v4758, v4757, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5722);
  v4759 = (int)std_string_append(&v5720, (int)&Dst, "lantern02.cub");
  v7813 = 2323;
  v4760 = this_4pointer_off((void *)v6, 2433);
  something_database(*(_DWORD *)v4760, v4759, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5720);
  v4761 = (int)std_string_append(&v5718, (int)&Dst, "torch.cub");
  v7813 = 2324;
  v4762 = this_4pointer_off((void *)v6, 2434);
  something_database(*(_DWORD *)v4762, v4761, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5718);
  v4763 = (int)std_string_append(&v5716, (int)&Dst, "stone.cub");
  v7813 = 2325;
  v4764 = this_4pointer_off((void *)v6, 2435);
  something_database(*(_DWORD *)v4764, v4763, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5716);
  v4765 = (int)std_string_append(&v5714, (int)&Dst, "stone2.cub");
  v7813 = 2326;
  v4766 = this_4pointer_off((void *)v6, 2436);
  something_database(*(_DWORD *)v4766, v4765, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5714);
  v4767 = (int)std_string_append(&v5712, (int)&Dst, "tendril.cub");
  v7813 = 2327;
  v4768 = this_4pointer_off((void *)v6, 2437);
  something_database(*(_DWORD *)v4768, v4767, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5712);
  v4769 = (int)std_string_append(&v5710, (int)&Dst, (const char *)"tulips-colorful.cub");
  v7813 = 2328;
  v4770 = this_4pointer_off((void *)v6, 2438);
  something_database(*(_DWORD *)v4770, v4769, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5710);
  v4771 = (int)std_string_append(&v5708, (int)&Dst, "cornflower.cub");
  v7813 = 2329;
  v4772 = this_4pointer_off((void *)v6, 2439);
  something_database(*(_DWORD *)v4772, v4771, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5708);
  v4773 = (int)std_string_append(&v5706, (int)&Dst, "reed.cub");
  v7813 = 2330;
  v4774 = this_4pointer_off((void *)v6, 2440);
  something_database(*(_DWORD *)v4774, v4773, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5706);
  v4775 = (int)std_string_append(&v5704, (int)&Dst, "pumpkin-leaves.cub");
  v7813 = 2331;
  v4776 = this_4pointer_off((void *)v6, 2441);
  something_database(*(_DWORD *)v4776, v4775, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5704);
  v4777 = (int)std_string_append(&v5702, (int)&Dst, "pineapple-leaves.cub");
  v7813 = 2332;
  v4778 = this_4pointer_off((void *)v6, 2442);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4777;
  something_database(*(_DWORD *)v4778, v4777, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5702);
  v4779 = (int)std_string_append(&v5700, (int)&Dst, "sunflower.cub");
  v7813 = 2333;
  v4780 = this_4pointer_off((void *)v6, 2443);
  something_database(*(_DWORD *)v4780, v4779, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5700);
  v4781 = (int)std_string_append(&v5698, (int)&Dst, "bean-tendril.cub");
  v7813 = 2334;
  v4782 = this_4pointer_off((void *)v6, 2444);
  something_database(*(_DWORD *)v4782, v4781, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5698);
  v4783 = (int)std_string_append(&v5696, (int)&Dst, "desert-flower01.cub");
  v7813 = 2335;
  v4784 = this_4pointer_off((void *)v6, 2445);
  something_database(*(_DWORD *)v4784, v4783, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5696);
  v4785 = (int)std_string_append(&v5694, (int)&Dst, "desert-flower02.cub");
  v7813 = 2336;
  v4786 = this_4pointer_off((void *)v6, 2446);
  something_database(*(_DWORD *)v4786, v4785, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5694);
  v4787 = (int)std_string_append(&v5692, (int)&Dst, "wheat.cub");
  v7813 = 2337;
  v4788 = this_4pointer_off((void *)v6, 2447);
  something_database(*(_DWORD *)v4788, v4787, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5692);
  v4789 = (int)std_string_append(&v5690, (int)&Dst, "corn.cub");
  v7813 = 2338;
  v4790 = this_4pointer_off((void *)v6, 2448);
  something_database(*(_DWORD *)v4790, v4789, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5690);
  v4791 = (int)std_string_append(&v5688, (int)&Dst, "water-lily01.cub");
  v7813 = 2339;
  v4792 = this_4pointer_off((void *)v6, 2449);
  something_database(*(_DWORD *)v4792, v4791, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5688);
  v4793 = (int)std_string_append(&v5686, (int)&Dst, "water-lily02.cub");
  v7813 = 2340;
  v4794 = this_4pointer_off((void *)v6, 2450);
  something_database(*(_DWORD *)v4794, v4793, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5686);
  v4795 = (int)std_string_append(&v5684, (int)&Dst, "inn-sign.cub");
  v7813 = 2341;
  v4796 = this_4pointer_off((void *)v6, 2451);
  something_database(*(_DWORD *)v4796, v4795, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5684);
  v4797 = (int)std_string_append(&v5682, (int)&Dst, "identifier-sign.cub");
  v7813 = 2342;
  v4798 = this_4pointer_off((void *)v6, 2455);
  something_database(*(_DWORD *)v4798, v4797, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5682);
  v4799 = (int)std_string_append(&v5680, (int)&Dst, "shop-sign.cub");
  v7813 = 2343;
  v4800 = this_4pointer_off((void *)v6, 2452);
  something_database(*(_DWORD *)v4800, v4799, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5680);
  v4801 = (int)std_string_append(&v5678, (int)&Dst, "weapon-shop-sign.cub");
  v7813 = 2344;
  v4802 = this_4pointer_off((void *)v6, 2453);
  something_database(*(_DWORD *)v4802, v4801, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5678);
  v4803 = (int)std_string_append(&v5676, (int)&Dst, "armor-shop-sign.cub");
  v7813 = 2345;
  v4804 = this_4pointer_off((void *)v6, 2454);
  something_database(*(_DWORD *)v4804, v4803, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5676);
  v4805 = (int)std_string_append(&v5674, (int)&Dst, "smithy-sign.cub");
  v7813 = 2346;
  v4806 = this_4pointer_off((void *)v6, 2456);
  something_database(*(_DWORD *)v4806, v4805, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5674);
  v4807 = (int)std_string_append(&v5672, (int)&Dst, "carpentersshop-sign.cub");
  v7813 = 2347;
  v4808 = this_4pointer_off((void *)v6, 2457);
  something_database(*(_DWORD *)v4808, v4807, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5672);
  v4809 = (int)std_string_append(&v5670, (int)&Dst, "weavingmill-sign.cub");
  v7813 = 2348;
  v4810 = this_4pointer_off((void *)v6, 2458);
  something_database(*(_DWORD *)v4810, v4809, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5670);
  v4811 = (int)std_string_append(&v5668, (int)&Dst, "ivy.cub");
  v7813 = 2349;
  v4812 = this_4pointer_off((void *)v6, 2459);
  something_database(*(_DWORD *)v4812, v4811, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5668);
  v4813 = (int)std_string_append(&v5666, (int)&Dst, "wall-roses-white.cub");
  v7813 = 2350;
  v4814 = this_4pointer_off((void *)v6, 2461);
  something_database(*(_DWORD *)v4814, v4813, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5666);
  v4815 = (int)std_string_append(&v5664, (int)&Dst, "wall-roses-red.cub");
  v7813 = 2351;
  v4816 = this_4pointer_off((void *)v6, 2460);
  something_database(*(_DWORD *)v4816, v4815, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5664);
  v4817 = (int)std_string_append(&v5662, (int)&Dst, "christmas-tree.cub");
  v7813 = 2352;
  v4818 = this_4pointer_off((void *)v6, 2462);
  something_database(*(_DWORD *)v4818, v4817, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5662);
  v4819 = (int)std_string_append(&v5660, (int)&Dst, "coral.cub");
  v7813 = 2353;
  v4820 = this_4pointer_off((void *)v6, 2465);
  something_database(*(_DWORD *)v4820, v4819, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5660);
  v4821 = (int)std_string_append(&v5658, (int)&Dst, "underwater-plant.cub");
  v7813 = 2354;
  v4822 = this_4pointer_off((void *)v6, 2463);
  something_database(*(_DWORD *)v4822, v4821, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5658);
  v4823 = (int)std_string_append(&v5656, (int)&Dst, "alga.cub");
  v7813 = 2355;
  v4824 = this_4pointer_off((void *)v6, 2464);
  something_database(*(_DWORD *)v4824, v4823, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5656);
  v4825 = (int)std_string_append(&v5654, (int)&Dst, "inca-art1.cub");
  v7813 = 2356;
  v4826 = this_4pointer_off((void *)v6, 2466);
  something_database(*(_DWORD *)v4826, v4825, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5654);
  v4827 = (int)std_string_append(&v5652, (int)&Dst, "inca-art2.cub");
  v7813 = 2357;
  v4828 = this_4pointer_off((void *)v6, 2467);
  something_database(*(_DWORD *)v4828, v4827, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5652);
  v4829 = (int)std_string_append(&v5650, (int)&Dst, "inca-art3.cub");
  v7813 = 2358;
  v4830 = this_4pointer_off((void *)v6, 2468);
  something_database(*(_DWORD *)v4830, v4829, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5650);
  v4831 = (int)std_string_append(&v5648, (int)&Dst, "inca-art4.cub");
  v7813 = 2359;
  v4832 = this_4pointer_off((void *)v6, 2469);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4831;
  something_database(*(_DWORD *)v4832, v4831, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5648);
  v4833 = (int)std_string_append(&v5646, (int)&Dst, "liana.cub");
  v7813 = 2360;
  v4834 = this_4pointer_off((void *)v6, 2477);
  something_database(*(_DWORD *)v4834, v4833, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5646);
  v4835 = (int)std_string_append(&v5644, (int)&Dst, "crest1.cub");
  v7813 = 2361;
  v4836 = this_4pointer_off((void *)v6, 2470);
  something_database(*(_DWORD *)v4836, v4835, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5644);
  v4837 = (int)std_string_append(&v5642, (int)&Dst, "castle-chain.cub");
  v7813 = 2362;
  v4838 = this_4pointer_off((void *)v6, 2471);
  something_database(*(_DWORD *)v4838, v4837, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5642);
  v4839 = (int)std_string_append(&v5640, (int)&Dst, "wall-skull.cub");
  v7813 = 2363;
  v4840 = this_4pointer_off((void *)v6, 2472);
  something_database(*(_DWORD *)v4840, v4839, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5640);
  v4841 = (int)std_string_append(&v5638, (int)&Dst, "torch-read.cub");
  v7813 = 2364;
  v4842 = this_4pointer_off((void *)v6, 2473);
  something_database(*(_DWORD *)v4842, v4841, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5638);
  v4843 = (int)std_string_append(&v5636, (int)&Dst, "torch-green.cub");
  v7813 = 2365;
  v4844 = this_4pointer_off((void *)v6, 2474);
  something_database(*(_DWORD *)v4844, v4843, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5636);
  v4845 = (int)std_string_append(&v5634, (int)&Dst, "torch-blue.cub");
  v7813 = 2366;
  v4846 = this_4pointer_off((void *)v6, 2475);
  something_database(*(_DWORD *)v4846, v4845, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5634);
  v4847 = (int)std_string_append(&v5632, (int)&Dst, "torch-yellow.cub");
  v7813 = 2367;
  v4848 = this_4pointer_off((void *)v6, 2476);
  something_database(*(_DWORD *)v4848, v4847, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5632);
  v4849 = (int)std_string_append(&v5630, (int)&Dst, "chandelier.cub");
  v7813 = 2368;
  v4850 = this_4pointer_off((void *)v6, 2478);
  something_database(*(_DWORD *)v4850, v4849, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5630);
  v4851 = (int)std_string_append(&v5628, (int)&Dst, "cobwebs.cub");
  v7813 = 2369;
  v4852 = this_4pointer_off((void *)v6, 2479);
  something_database(*(_DWORD *)v4852, v4851, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5628);
  v4853 = (int)std_string_append(&v5626, (int)&Dst, "cobwebs2.cub");
  v7813 = 2370;
  v4854 = this_4pointer_off((void *)v6, 2480);
  something_database(*(_DWORD *)v4854, v4853, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5626);
  v4855 = (int)std_string_append(&v5624, (int)&Dst, "goddess2.cub");
  v7813 = 2371;
  v4856 = this_4pointer_off((void *)v6, 2481);
  something_database(*(_DWORD *)v4856, v4855, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5624);
  v4857 = (int)std_string_append(&v5622, (int)&Dst, "door.cub");
  v7813 = 2372;
  v4858 = this_4pointer_off((void *)v6, 2482);
  something_database(*(_DWORD *)v4858, v4857, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5622);
  v4859 = (int)std_string_append(&v5620, (int)&Dst, "big-door.cub");
  v7813 = 2373;
  v4860 = this_4pointer_off((void *)v6, 2483);
  something_database(*(_DWORD *)v4860, v4859, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5620);
  v4861 = (int)std_string_append(&v5618, (int)&Dst, "window.cub");
  v7813 = 2374;
  v4862 = this_4pointer_off((void *)v6, 2484);
  something_database(*(_DWORD *)v4862, v4861, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5618);
  v4863 = (int)std_string_append(&v5616, (int)&Dst, "castle-window.cub");
  v7813 = 2375;
  v4864 = this_4pointer_off((void *)v6, 2485);
  something_database(*(_DWORD *)v4864, v4863, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5616);
  v4865 = (int)std_string_append(&v5614, (int)&Dst, "gate.cub");
  v7813 = 2376;
  v4866 = this_4pointer_off((void *)v6, 2486);
  something_database(*(_DWORD *)v4866, v4865, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5614);
  v4867 = (int)std_string_append(&v5612, (int)&Dst, "spike-trap.cub");
  v7813 = 2377;
  v4868 = this_4pointer_off((void *)v6, 2487);
  something_database(*(_DWORD *)v4868, v4867, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5612);
  v4869 = (int)std_string_append(&v5610, (int)&Dst, "stomp-trap.cub");
  v7813 = 2378;
  v4870 = this_4pointer_off((void *)v6, 2488);
  something_database(*(_DWORD *)v4870, v4869, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5610);
  v4871 = (int)std_string_append(&v5608, (int)&Dst, "lever.cub");
  v7813 = 2379;
  v4872 = this_4pointer_off((void *)v6, 2489);
  something_database(*(_DWORD *)v4872, v4871, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5608);
  v4873 = (int)std_string_append(&v5606, (int)&Dst, "chest-base02.cub");
  v7813 = 2380;
  v4874 = this_4pointer_off((void *)v6, 2490);
  something_database(*(_DWORD *)v4874, v4873, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5606);
  v4875 = (int)std_string_append(&v5604, (int)&Dst, "chest-top02.cub");
  v7813 = 2381;
  v4876 = this_4pointer_off((void *)v6, 2491);
  something_database(*(_DWORD *)v4876, v4875, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5604);
  v4877 = (int)std_string_append(&v5602, (int)&Dst, "table.cub");
  v7813 = 2382;
  v4878 = this_4pointer_off((void *)v6, 2492);
  something_database(*(_DWORD *)v4878, v4877, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5602);
  v4879 = (int)std_string_append(&v5600, (int)&Dst, "stone-table.cub");
  v7813 = 2383;
  v4880 = this_4pointer_off((void *)v6, 2493);
  something_database(*(_DWORD *)v4880, v4879, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5600);
  v4881 = (int)std_string_append(&v5598, (int)&Dst, "sandstone-table.cub");
  v7813 = 2384;
  v4882 = this_4pointer_off((void *)v6, 2494);
  something_database(*(_DWORD *)v4882, v4881, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5598);
  v4883 = (int)std_string_append(&v5596, (int)&Dst, "stone-stool.cub");
  v7813 = 2385;
  v4884 = this_4pointer_off((void *)v6, 2495);
  something_database(*(_DWORD *)v4884, v4883, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5596);
  v4885 = (int)std_string_append(&v5594, (int)&Dst, "sandstone-stool.cub");
  v7813 = 2386;
  v4886 = this_4pointer_off((void *)v6, 2496);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4885;
  something_database(*(_DWORD *)v4886, v4885, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5594);
  v4887 = (int)std_string_append(&v5592, (int)&Dst, "stool.cub");
  v7813 = 2387;
  v4888 = this_4pointer_off((void *)v6, 2497);
  something_database(*(_DWORD *)v4888, v4887, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5592);
  v4889 = (int)std_string_append(&v5590, (int)&Dst, "bench.cub");
  v7813 = 2388;
  v4890 = this_4pointer_off((void *)v6, 2498);
  something_database(*(_DWORD *)v4890, v4889, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5590);
  v4891 = (int)std_string_append(&v5588, (int)&Dst, "bed.cub");
  v7813 = 2389;
  v4892 = this_4pointer_off((void *)v6, 2499);
  something_database(*(_DWORD *)v4892, v4891, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5588);
  v4893 = (int)std_string_append(&v5586, (int)&Dst, "bedtable.cub");
  v7813 = 2390;
  v4894 = this_4pointer_off((void *)v6, 2500);
  something_database(*(_DWORD *)v4894, v4893, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5586);
  v4895 = (int)std_string_append(&v5584, (int)&Dst, "crate.cub");
  v7813 = 2391;
  v4896 = this_4pointer_off((void *)v6, 2506);
  something_database(*(_DWORD *)v4896, v4895, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5584);
  v4897 = (int)std_string_append(&v5582, (int)&Dst, "open-crate.cub");
  v7813 = 2392;
  v4898 = this_4pointer_off((void *)v6, 2507);
  something_database(*(_DWORD *)v4898, v4897, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5582);
  v4899 = (int)std_string_append(&v5580, (int)&Dst, "sack.cub");
  v7813 = 2393;
  v4900 = this_4pointer_off((void *)v6, 2508);
  something_database(*(_DWORD *)v4900, v4899, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5580);
  v4901 = (int)std_string_append(&v5578, (int)&Dst, "market-stand1.cub");
  v7813 = 2394;
  v4902 = this_4pointer_off((void *)v6, 2502);
  something_database(*(_DWORD *)v4902, v4901, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5578);
  v4903 = (int)std_string_append(&v5576, (int)&Dst, "market-stand2.cub");
  v7813 = 2395;
  v4904 = this_4pointer_off((void *)v6, 2503);
  something_database(*(_DWORD *)v4904, v4903, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5576);
  v4905 = (int)std_string_append(&v5574, (int)&Dst, "market-stand3.cub");
  v7813 = 2396;
  v4906 = this_4pointer_off((void *)v6, 2504);
  something_database(*(_DWORD *)v4906, v4905, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5574);
  v4907 = (int)std_string_append(&v5572, (int)&Dst, "barrel.cub");
  v7813 = 2397;
  v4908 = this_4pointer_off((void *)v6, 2505);
  something_database(*(_DWORD *)v4908, v4907, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5572);
  v4909 = (int)std_string_append(&v5570, (int)&Dst, "shelter.cub");
  v7813 = 2398;
  v4910 = this_4pointer_off((void *)v6, 2509);
  something_database(*(_DWORD *)v4910, v4909, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5570);
  v4911 = (int)std_string_append(&v5568, (int)&Dst, "cupboard.cub");
  v7813 = 2399;
  v4912 = this_4pointer_off((void *)v6, 2501);
  something_database(*(_DWORD *)v4912, v4911, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5568);
  v4913 = (int)std_string_append(&v5566, (int)&Dst, "desktop.cub");
  v7813 = 2400;
  v4914 = this_4pointer_off((void *)v6, 2510);
  something_database(*(_DWORD *)v4914, v4913, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5566);
  v4915 = (int)std_string_append(&v5564, (int)&Dst, "counter.cub");
  v7813 = 2401;
  v4916 = this_4pointer_off((void *)v6, 2511);
  something_database(*(_DWORD *)v4916, v4915, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5564);
  v4917 = (int)std_string_append(&v5562, (int)&Dst, "shelf1.cub");
  v7813 = 2402;
  v4918 = this_4pointer_off((void *)v6, 2512);
  something_database(*(_DWORD *)v4918, v4917, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5562);
  v4919 = (int)std_string_append(&v5560, (int)&Dst, "shelf2.cub");
  v7813 = 2403;
  v4920 = this_4pointer_off((void *)v6, 2513);
  something_database(*(_DWORD *)v4920, v4919, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5560);
  v4921 = (int)std_string_append(&v5558, (int)&Dst, "shelf3.cub");
  v7813 = 2404;
  v4922 = this_4pointer_off((void *)v6, 2514);
  something_database(*(_DWORD *)v4922, v4921, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5558);
  v4923 = (int)std_string_append(&v5556, (int)&Dst, "castle-shelf1.cub");
  v7813 = 2405;
  v4924 = this_4pointer_off((void *)v6, 2515);
  something_database(*(_DWORD *)v4924, v4923, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5556);
  v4925 = (int)std_string_append(&v5554, (int)&Dst, "castle-shelf2.cub");
  v7813 = 2406;
  v4926 = this_4pointer_off((void *)v6, 2516);
  something_database(*(_DWORD *)v4926, v4925, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5554);
  v4927 = (int)std_string_append(&v5552, (int)&Dst, "castle-shelf3.cub");
  v7813 = 2407;
  v4928 = this_4pointer_off((void *)v6, 2517);
  something_database(*(_DWORD *)v4928, v4927, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5552);
  v4929 = (int)std_string_append(&v5550, (int)&Dst, "stone-shelf1.cub");
  v7813 = 2408;
  v4930 = this_4pointer_off((void *)v6, 2518);
  something_database(*(_DWORD *)v4930, v4929, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5550);
  v4931 = (int)std_string_append(&v5548, (int)&Dst, "stone-shelf2.cub");
  v7813 = 2409;
  v4932 = this_4pointer_off((void *)v6, 2519);
  something_database(*(_DWORD *)v4932, v4931, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5548);
  v4933 = (int)std_string_append(&v5546, (int)&Dst, "stone-shelf3.cub");
  v7813 = 2410;
  v4934 = this_4pointer_off((void *)v6, 2520);
  something_database(*(_DWORD *)v4934, v4933, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5546);
  v4935 = (int)std_string_append(&v5544, (int)&Dst, "sandstone-shelf1.cub");
  v7813 = 2411;
  v4936 = this_4pointer_off((void *)v6, 2521);
  something_database(*(_DWORD *)v4936, v4935, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5544);
  v4937 = (int)std_string_append(&v5542, (int)&Dst, "sandstone-shelf2.cub");
  v7813 = 2412;
  v4938 = this_4pointer_off((void *)v6, 2522);
  something_database(*(_DWORD *)v4938, v4937, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5542);
  v4939 = (int)std_string_append(&v5540, (int)&Dst, "sandstone-shelf3.cub");
  v7813 = 2413;
  v4940 = this_4pointer_off((void *)v6, 2523);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4939;
  something_database(*(_DWORD *)v4940, v4939, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5540);
  v4941 = (int)std_string_append(&v5538, (int)&Dst, "corpse.cub");
  v7813 = 2414;
  v4942 = this_4pointer_off((void *)v6, 2524);
  something_database(*(_DWORD *)v4942, v4941, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5538);
  v4943 = (int)std_string_append(&v5536, (int)&Dst, "runestone.cub");
  v7813 = 2415;
  v4944 = this_4pointer_off((void *)v6, 2525);
  something_database(*(_DWORD *)v4944, v4943, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5536);
  v4945 = (int)std_string_append(&v5534, (int)&Dst, "flower-box01.cub");
  v7813 = 2416;
  v4946 = this_4pointer_off((void *)v6, 2526);
  something_database(*(_DWORD *)v4946, v4945, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5534);
  v4947 = (int)std_string_append(&v5532, (int)&Dst, "flower-box02.cub");
  v7813 = 2417;
  v4948 = this_4pointer_off((void *)v6, 2527);
  something_database(*(_DWORD *)v4948, v4947, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5532);
  v4949 = (int)std_string_append(&v5530, (int)&Dst, "flower-box03.cub");
  v7813 = 2418;
  v4950 = this_4pointer_off((void *)v6, 2528);
  something_database(*(_DWORD *)v4950, v4949, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5530);
  v4951 = (int)std_string_append(&v5528, (int)&Dst, "street-light02.cub");
  v7813 = 2419;
  v4952 = this_4pointer_off((void *)v6, 2529);
  something_database(*(_DWORD *)v4952, v4951, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5528);
  v4953 = (int)std_string_append(&v5526, (int)&Dst, "street-light01.cub");
  v7813 = 2420;
  v4954 = this_4pointer_off((void *)v6, 2530);
  something_database(*(_DWORD *)v4954, v4953, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5526);
  v4955 = (int)std_string_append(&v5524, (int)&Dst, "fence01.cub");
  v7813 = 2421;
  v4956 = this_4pointer_off((void *)v6, 2531);
  something_database(*(_DWORD *)v4956, v4955, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5524);
  v4957 = (int)std_string_append(&v5522, (int)&Dst, "fence02.cub");
  v7813 = 2422;
  v4958 = this_4pointer_off((void *)v6, 2532);
  something_database(*(_DWORD *)v4958, v4957, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5522);
  v4959 = (int)std_string_append(&v5520, (int)&Dst, "fence03.cub");
  v7813 = 2423;
  v4960 = this_4pointer_off((void *)v6, 2533);
  something_database(*(_DWORD *)v4960, v4959, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5520);
  v4961 = (int)std_string_append(&v5518, (int)&Dst, "fence04.cub");
  v7813 = 2424;
  v4962 = this_4pointer_off((void *)v6, 2534);
  something_database(*(_DWORD *)v4962, v4961, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5518);
  v4963 = (int)std_string_append(&v5516, (int)&Dst, "furnace.cub");
  v7813 = 2425;
  v4964 = this_4pointer_off((void *)v6, 2535);
  something_database(*(_DWORD *)v4964, v4963, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5516);
  v4965 = (int)std_string_append(&v5514, (int)&Dst, "anvil.cub");
  v7813 = 2426;
  v4966 = this_4pointer_off((void *)v6, 2536);
  something_database(*(_DWORD *)v4966, v4965, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5514);
  v4967 = (int)std_string_append(&v5512, (int)&Dst, "spinningwheel.cub");
  v7813 = 2427;
  v4968 = this_4pointer_off((void *)v6, 2540);
  something_database(*(_DWORD *)v4968, v4967, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5512);
  v4969 = (int)std_string_append(&v5510, (int)&Dst, "loom.cub");
  v7813 = 2428;
  v4970 = this_4pointer_off((void *)v6, 2541);
  something_database(*(_DWORD *)v4970, v4969, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5510);
  v4971 = (int)std_string_append(&v5508, (int)&Dst, "sawbench.cub");
  v7813 = 2429;
  v4972 = this_4pointer_off((void *)v6, 2537);
  something_database(*(_DWORD *)v4972, v4971, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5508);
  v4973 = (int)std_string_append(&v5506, (int)&Dst, "workbench.cub");
  v7813 = 2430;
  v4974 = this_4pointer_off((void *)v6, 2538);
  something_database(*(_DWORD *)v4974, v4973, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5506);
  v4975 = (int)std_string_append(&v5504, (int)&Dst, "customization-bench.cub");
  v7813 = 2431;
  v4976 = this_4pointer_off((void *)v6, 2539);
  something_database(*(_DWORD *)v4976, v4975, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5504);
  v4977 = (int)std_string_append(&v5502, (int)&Dst, "overground-dungeon01.cub");
  v7813 = 2432;
  v4978 = this_4pointer_off((void *)v6, 2542);
  something_database(*(_DWORD *)v4978, v4977, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5502);
  v4979 = (int)std_string_append(&v5500, (int)&Dst, "underground-dungeon01.cub");
  v7813 = 2433;
  v4980 = this_4pointer_off((void *)v6, 2543);
  something_database(*(_DWORD *)v4980, v4979, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5500);
  v4981 = (int)std_string_append(&v5498, (int)&Dst, "castle-arc.cub");
  v7813 = 2434;
  v4982 = this_4pointer_off((void *)v6, 2544);
  something_database(*(_DWORD *)v4982, v4981, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5498);
  v4983 = (int)std_string_append(&v5496, (int)&Dst, "temple-arc.cub");
  v7813 = 2435;
  v4984 = this_4pointer_off((void *)v6, 2545);
  something_database(*(_DWORD *)v4984, v4983, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5496);
  v4985 = (int)std_string_append(&v5494, (int)&Dst, "bomb1.cub");
  v7813 = 2436;
  v4986 = this_4pointer_off((void *)v6, 2546);
  something_database(*(_DWORD *)v4986, v4985, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5494);
  v4987 = (int)std_string_append(&v5492, (int)&Dst, "glider.cub");
  v7813 = 2437;
  v4988 = this_4pointer_off((void *)v6, 2547);
  something_database(*(_DWORD *)v4988, v4987, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5492);
  v4989 = (int)std_string_append(&v5490, (int)&Dst, "boat2.cub");
  v7813 = 2438;
  v4990 = this_4pointer_off((void *)v6, 2548);
  something_database(*(_DWORD *)v4990, v4989, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5490);
  v4991 = (int)std_string_append(&v5488, (int)&Dst, "stone-bridge.cub");
  v7813 = 2439;
  v4992 = this_4pointer_off((void *)v6, 2184);
  something_database(*(_DWORD *)v4992, v4991, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5488);
  v4993 = (int)std_string_append(&v5486, (int)&Dst, "entrance-stairs.cub");
  v7813 = 2440;
  v4994 = this_4pointer_off((void *)v6, 2185);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v4993;
  something_database(*(_DWORD *)v4994, v4993, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5486);
  v4995 = (int)std_string_append(&v5484, (int)&Dst, "carpet1.cub");
  v7813 = 2441;
  v4996 = this_4pointer_off((void *)v6, 2186);
  something_database(*(_DWORD *)v4996, v4995, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5484);
  v4997 = (int)std_string_append(&v5482, (int)&Dst, "carpet2.cub");
  v7813 = 2442;
  v4998 = this_4pointer_off((void *)v6, 2187);
  something_database(*(_DWORD *)v4998, v4997, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5482);
  v4999 = (int)std_string_append(&v5480, (int)&Dst, "carpet3.cub");
  v7813 = 2443;
  v5000 = this_4pointer_off((void *)v6, 2188);
  something_database(*(_DWORD *)v5000, v4999, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5480);
  v5001 = (int)std_string_append(&v5478, (int)&Dst, "framework-base.cub");
  v7813 = 2444;
  v5002 = this_4pointer_off((void *)v6, 2189);
  something_database(*(_DWORD *)v5002, v5001, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5478);
  v5003 = (int)std_string_append(&v5476, (int)&Dst, "framework-floor.cub");
  v7813 = 2445;
  v5004 = this_4pointer_off((void *)v6, 2190);
  something_database(*(_DWORD *)v5004, v5003, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5476);
  v5005 = (int)std_string_append(&v5474, (int)&Dst, "framework-floor-stairs.cub");
  v7813 = 2446;
  v5006 = this_4pointer_off((void *)v6, 2191);
  something_database(*(_DWORD *)v5006, v5005, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5474);
  v5007 = (int)std_string_append(&v5472, (int)&Dst, "framework-wall.cub");
  v7813 = 2447;
  v5008 = this_4pointer_off((void *)v6, 2192);
  something_database(*(_DWORD *)v5008, v5007, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5472);
  v5009 = (int)std_string_append(&v5470, (int)&Dst, "framework-wall-window.cub");
  v7813 = 2448;
  v5010 = this_4pointer_off((void *)v6, 2193);
  something_database(*(_DWORD *)v5010, v5009, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5470);
  v5011 = (int)std_string_append(&v5468, (int)&Dst, "framework-wall-door.cub");
  v7813 = 2449;
  v5012 = this_4pointer_off((void *)v6, 2194);
  something_database(*(_DWORD *)v5012, v5011, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5468);
  v5013 = (int)std_string_append(&v5466, (int)&Dst, "framework-wall-indoor.cub");
  v7813 = 2450;
  v5014 = this_4pointer_off((void *)v6, 2195);
  something_database(*(_DWORD *)v5014, v5013, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5466);
  v5015 = (int)std_string_append(&v5464, (int)&Dst, "framework-wall-balcony.cub");
  v7813 = 2451;
  v5016 = this_4pointer_off((void *)v6, 2196);
  something_database(*(_DWORD *)v5016, v5015, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5464);
  v5017 = (int)std_string_append(&v5462, (int)&Dst, "framework-wall-lamp.cub");
  v7813 = 2452;
  v5018 = this_4pointer_off((void *)v6, 2197);
  something_database(*(_DWORD *)v5018, v5017, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5462);
  v5019 = (int)std_string_append(&v5460, (int)&Dst, "framework-roof1.cub");
  v7813 = 2453;
  v5020 = this_4pointer_off((void *)v6, 2198);
  something_database(*(_DWORD *)v5020, v5019, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5460);
  v5021 = (int)std_string_append(&v5458, (int)&Dst, "framework-roof2.cub");
  v7813 = 2454;
  v5022 = this_4pointer_off((void *)v6, 2199);
  something_database(*(_DWORD *)v5022, v5021, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5458);
  v5023 = (int)std_string_append(&v5456, (int)&Dst, "framework-roof3.cub");
  v7813 = 2455;
  v5024 = this_4pointer_off((void *)v6, 2200);
  something_database(*(_DWORD *)v5024, v5023, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5456);
  v5025 = (int)std_string_append(&v5454, (int)&Dst, "framework-arc.cub");
  v7813 = 2456;
  v5026 = this_4pointer_off((void *)v6, 2201);
  something_database(*(_DWORD *)v5026, v5025, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5454);
  v5027 = (int)std_string_append(&v5452, (int)&Dst, "stone-base.cub");
  v7813 = 2457;
  v5028 = this_4pointer_off((void *)v6, 2202);
  something_database(*(_DWORD *)v5028, v5027, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5452);
  v5029 = (int)std_string_append(&v5450, (int)&Dst, "stone-floor.cub");
  v7813 = 2458;
  v5030 = this_4pointer_off((void *)v6, 2203);
  something_database(*(_DWORD *)v5030, v5029, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5450);
  v5031 = (int)std_string_append(&v5448, (int)&Dst, "stone-floor-stairs.cub");
  v7813 = 2459;
  v5032 = this_4pointer_off((void *)v6, 2204);
  something_database(*(_DWORD *)v5032, v5031, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5448);
  v5033 = (int)std_string_append(&v5446, (int)&Dst, "stone-wall.cub");
  v7813 = 2460;
  v5034 = this_4pointer_off((void *)v6, 2205);
  something_database(*(_DWORD *)v5034, v5033, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5446);
  v5035 = (int)std_string_append(&v5444, (int)&Dst, "stone-wall-window.cub");
  v7813 = 2461;
  v5036 = this_4pointer_off((void *)v6, 2206);
  something_database(*(_DWORD *)v5036, v5035, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5444);
  v5037 = (int)std_string_append(&v5442, (int)&Dst, "stone-wall-door.cub");
  v7813 = 2462;
  v5038 = this_4pointer_off((void *)v6, 2207);
  something_database(*(_DWORD *)v5038, v5037, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5442);
  v5039 = (int)std_string_append(&v5440, (int)&Dst, "stone-wall-indoor.cub");
  v7813 = 2463;
  v5040 = this_4pointer_off((void *)v6, 2208);
  something_database(*(_DWORD *)v5040, v5039, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5440);
  v5041 = (int)std_string_append(&v5438, (int)&Dst, "stone-wall-balcony.cub");
  v7813 = 2464;
  v5042 = this_4pointer_off((void *)v6, 2209);
  something_database(*(_DWORD *)v5042, v5041, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5438);
  v5043 = (int)std_string_append(&v5436, (int)&Dst, "stone-wall-lamp.cub");
  v7813 = 2465;
  v5044 = this_4pointer_off((void *)v6, 2210);
  something_database(*(_DWORD *)v5044, v5043, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5436);
  v5045 = (int)std_string_append(&v5434, (int)&Dst, "stone-roof1.cub");
  v7813 = 2466;
  v5046 = this_4pointer_off((void *)v6, 2211);
  something_database(*(_DWORD *)v5046, v5045, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5434);
  v5047 = (int)std_string_append(&v5432, (int)&Dst, "stone-roof2.cub");
  v7813 = 2467;
  v5048 = this_4pointer_off((void *)v6, 2212);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v5047;
  something_database(*(_DWORD *)v5048, v5047, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5432);
  v5049 = (int)std_string_append(&v5430, (int)&Dst, "stone-roof3.cub");
  v7813 = 2468;
  v5050 = this_4pointer_off((void *)v6, 2213);
  something_database(*(_DWORD *)v5050, v5049, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5430);
  v5051 = (int)std_string_append(&v5428, (int)&Dst, "stone-arc.cub");
  v7813 = 2469;
  v5052 = this_4pointer_off((void *)v6, 2214);
  something_database(*(_DWORD *)v5052, v5051, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5428);
  v5053 = (int)std_string_append(&v5426, (int)&Dst, "whitewood-base.cub");
  v7813 = 2470;
  v5054 = this_4pointer_off((void *)v6, 2215);
  something_database(*(_DWORD *)v5054, v5053, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5426);
  v5055 = (int)std_string_append(&v5424, (int)&Dst, "whitewood-floor.cub");
  v7813 = 2471;
  v5056 = this_4pointer_off((void *)v6, 2216);
  something_database(*(_DWORD *)v5056, v5055, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5424);
  v5057 = (int)std_string_append(&v5422, (int)&Dst, "whitewood-floor-stairs.cub");
  v7813 = 2472;
  v5058 = this_4pointer_off((void *)v6, 2217);
  something_database(*(_DWORD *)v5058, v5057, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5422);
  v5059 = (int)std_string_append(&v5420, (int)&Dst, "whitewood-wall.cub");
  v7813 = 2473;
  v5060 = this_4pointer_off((void *)v6, 2218);
  something_database(*(_DWORD *)v5060, v5059, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5420);
  v5061 = (int)std_string_append(&v5418, (int)&Dst, "whitewood-wall-window.cub");
  v7813 = 2474;
  v5062 = this_4pointer_off((void *)v6, 2219);
  something_database(*(_DWORD *)v5062, v5061, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5418);
  v5063 = (int)std_string_append(&v5416, (int)&Dst, "whitewood-wall-door.cub");
  v7813 = 2475;
  v5064 = this_4pointer_off((void *)v6, 2220);
  something_database(*(_DWORD *)v5064, v5063, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5416);
  v5065 = (int)std_string_append(&v5414, (int)&Dst, "whitewood-wall-indoor.cub");
  v7813 = 2476;
  v5066 = this_4pointer_off((void *)v6, 2221);
  something_database(*(_DWORD *)v5066, v5065, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5414);
  v5067 = (int)std_string_append(&v5412, (int)&Dst, "whitewood-wall-balcony.cub");
  v7813 = 2477;
  v5068 = this_4pointer_off((void *)v6, 2222);
  something_database(*(_DWORD *)v5068, v5067, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5412);
  v5069 = (int)std_string_append(&v5410, (int)&Dst, "whitewood-wall-lamp.cub");
  v7813 = 2478;
  v5070 = this_4pointer_off((void *)v6, 2223);
  something_database(*(_DWORD *)v5070, v5069, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5410);
  v5071 = (int)std_string_append(&v5408, (int)&Dst, "whitewood-roof1.cub");
  v7813 = 2479;
  v5072 = this_4pointer_off((void *)v6, 2224);
  something_database(*(_DWORD *)v5072, v5071, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5408);
  v5073 = (int)std_string_append(&v5406, (int)&Dst, "whitewood-roof2.cub");
  v7813 = 2480;
  v5074 = this_4pointer_off((void *)v6, 2225);
  something_database(*(_DWORD *)v5074, v5073, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5406);
  v5075 = (int)std_string_append(&v5404, (int)&Dst, "whitewood-roof3.cub");
  v7813 = 2481;
  v5076 = this_4pointer_off((void *)v6, 2226);
  something_database(*(_DWORD *)v5076, v5075, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5404);
  v5077 = (int)std_string_append(&v5402, (int)&Dst, "whitewood-arc.cub");
  v7813 = 2482;
  v5078 = this_4pointer_off((void *)v6, 2227);
  something_database(*(_DWORD *)v5078, v5077, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5402);
  v5079 = (int)std_string_append(&v5400, (int)&Dst, "wood-base.cub");
  v7813 = 2483;
  v5080 = this_4pointer_off((void *)v6, 2287);
  something_database(*(_DWORD *)v5080, v5079, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5400);
  v5081 = (int)std_string_append(&v5398, (int)&Dst, "wood-floor.cub");
  v7813 = 2484;
  v5082 = this_4pointer_off((void *)v6, 2288);
  something_database(*(_DWORD *)v5082, v5081, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5398);
  v5083 = (int)std_string_append(&v5396, (int)&Dst, "wood-floor-stairs.cub");
  v7813 = 2485;
  v5084 = this_4pointer_off((void *)v6, 2289);
  something_database(*(_DWORD *)v5084, v5083, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5396);
  v5085 = (int)std_string_append(&v5394, (int)&Dst, "wood-wall.cub");
  v7813 = 2486;
  v5086 = this_4pointer_off((void *)v6, 2290);
  something_database(*(_DWORD *)v5086, v5085, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5394);
  v5087 = (int)std_string_append(&v5392, (int)&Dst, "wood-wall-window.cub");
  v7813 = 2487;
  v5088 = this_4pointer_off((void *)v6, 2291);
  something_database(*(_DWORD *)v5088, v5087, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5392);
  v5089 = (int)std_string_append(&v5390, (int)&Dst, "wood-wall-door.cub");
  v7813 = 2488;
  v5090 = this_4pointer_off((void *)v6, 2292);
  something_database(*(_DWORD *)v5090, v5089, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5390);
  v5091 = (int)std_string_append(&v5388, (int)&Dst, "wood-wall-indoor.cub");
  v7813 = 2489;
  v5092 = this_4pointer_off((void *)v6, 2293);
  something_database(*(_DWORD *)v5092, v5091, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5388);
  v5093 = (int)std_string_append(&v5386, (int)&Dst, "wood-wall-balcony.cub");
  v7813 = 2490;
  v5094 = this_4pointer_off((void *)v6, 2294);
  something_database(*(_DWORD *)v5094, v5093, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5386);
  v5095 = (int)std_string_append(&v5384, (int)&Dst, "wood-wall-lamp.cub");
  v7813 = 2491;
  v5096 = this_4pointer_off((void *)v6, 2295);
  something_database(*(_DWORD *)v5096, v5095, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5384);
  v5097 = (int)std_string_append(&v5382, (int)&Dst, "wood-roof1.cub");
  v7813 = 2492;
  v5098 = this_4pointer_off((void *)v6, 2296);
  something_database(*(_DWORD *)v5098, v5097, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5382);
  v5099 = (int)std_string_append(&v5380, (int)&Dst, "wood-roof2.cub");
  v7813 = 2493;
  v5100 = this_4pointer_off((void *)v6, 2297);
  something_database(*(_DWORD *)v5100, v5099, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5380);
  v5101 = (int)std_string_append(&v5378, (int)&Dst, "wood-roof3.cub");
  v7813 = 2494;
  v5102 = this_4pointer_off((void *)v6, 2298);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v5101;
  something_database(*(_DWORD *)v5102, v5101, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5378);
  v5103 = (int)std_string_append(&v5376, (int)&Dst, "wood-arc.cub");
  v7813 = 2495;
  v5104 = this_4pointer_off((void *)v6, 2299);
  something_database(*(_DWORD *)v5104, v5103, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5376);
  v5105 = (int)std_string_append(&v5374, (int)&Dst, "clay-entrance-stairs.cub");
  v7813 = 2496;
  v5106 = this_4pointer_off((void *)v6, 2241);
  something_database(*(_DWORD *)v5106, v5105, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5374);
  v5107 = (int)std_string_append(&v5372, (int)&Dst, "clay-base.cub");
  v7813 = 2497;
  v5108 = this_4pointer_off((void *)v6, 2228);
  something_database(*(_DWORD *)v5108, v5107, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5372);
  v5109 = (int)std_string_append(&v5370, (int)&Dst, "clay-floor.cub");
  v7813 = 2498;
  v5110 = this_4pointer_off((void *)v6, 2229);
  something_database(*(_DWORD *)v5110, v5109, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5370);
  v5111 = (int)std_string_append(&v5368, (int)&Dst, "clay-floor-stairs.cub");
  v7813 = 2499;
  v5112 = this_4pointer_off((void *)v6, 2230);
  something_database(*(_DWORD *)v5112, v5111, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5368);
  v5113 = (int)std_string_append(&v5366, (int)&Dst, "clay-wall.cub");
  v7813 = 2500;
  v5114 = this_4pointer_off((void *)v6, 2231);
  something_database(*(_DWORD *)v5114, v5113, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5366);
  v5115 = (int)std_string_append(&v5364, (int)&Dst, "clay-wall-window.cub");
  v7813 = 2501;
  v5116 = this_4pointer_off((void *)v6, 2232);
  something_database(*(_DWORD *)v5116, v5115, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5364);
  v5117 = (int)std_string_append(&v5362, (int)&Dst, "clay-wall-door.cub");
  v7813 = 2502;
  v5118 = this_4pointer_off((void *)v6, 2233);
  something_database(*(_DWORD *)v5118, v5117, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5362);
  v5119 = (int)std_string_append(&v5360, (int)&Dst, "clay-wall-indoor.cub");
  v7813 = 2503;
  v5120 = this_4pointer_off((void *)v6, 2234);
  something_database(*(_DWORD *)v5120, v5119, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5360);
  v5121 = (int)std_string_append(&v5358, (int)&Dst, "clay-wall-balcony.cub");
  v7813 = 2504;
  v5122 = this_4pointer_off((void *)v6, 2235);
  something_database(*(_DWORD *)v5122, v5121, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5358);
  v5123 = (int)std_string_append(&v5356, (int)&Dst, "clay-wall-lamp.cub");
  v7813 = 2505;
  v5124 = this_4pointer_off((void *)v6, 2236);
  something_database(*(_DWORD *)v5124, v5123, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5356);
  v5125 = (int)std_string_append(&v5354, (int)&Dst, "clay-roof1.cub");
  v7813 = 2506;
  v5126 = this_4pointer_off((void *)v6, 2237);
  something_database(*(_DWORD *)v5126, v5125, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5354);
  v5127 = (int)std_string_append(&v5352, (int)&Dst, "clay-roof2.cub");
  v7813 = 2507;
  v5128 = this_4pointer_off((void *)v6, 2238);
  something_database(*(_DWORD *)v5128, v5127, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5352);
  v5129 = (int)std_string_append(&v5350, (int)&Dst, "clay-roof3.cub");
  v7813 = 2508;
  v5130 = this_4pointer_off((void *)v6, 2239);
  something_database(*(_DWORD *)v5130, v5129, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5350);
  v5131 = (int)std_string_append(&v5348, (int)&Dst, "clay-arc.cub");
  v7813 = 2509;
  v5132 = this_4pointer_off((void *)v6, 2240);
  something_database(*(_DWORD *)v5132, v5131, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5348);
  v5133 = (int)std_string_append(&v5346, (int)&Dst, "whiteclay-entrance-stairs.cub");
  v7813 = 2510;
  v5134 = this_4pointer_off((void *)v6, 2242);
  something_database(*(_DWORD *)v5134, v5133, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5346);
  v5135 = (int)std_string_append(&v5344, (int)&Dst, "whiteclay-base.cub");
  v7813 = 2511;
  v5136 = this_4pointer_off((void *)v6, 2243);
  something_database(*(_DWORD *)v5136, v5135, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5344);
  v5137 = (int)std_string_append(&v5342, (int)&Dst, "whiteclay-floor.cub");
  v7813 = 2512;
  v5138 = this_4pointer_off((void *)v6, 2244);
  something_database(*(_DWORD *)v5138, v5137, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5342);
  v5139 = (int)std_string_append(&v5340, (int)&Dst, "whiteclay-floor-stairs.cub");
  v7813 = 2513;
  v5140 = this_4pointer_off((void *)v6, 2245);
  something_database(*(_DWORD *)v5140, v5139, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5340);
  v5141 = (int)std_string_append(&v5338, (int)&Dst, "whiteclay-wall.cub");
  v7813 = 2514;
  v5142 = this_4pointer_off((void *)v6, 2246);
  something_database(*(_DWORD *)v5142, v5141, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5338);
  v5143 = (int)std_string_append(&v5336, (int)&Dst, "whiteclay-wall-window.cub");
  v7813 = 2515;
  v5144 = this_4pointer_off((void *)v6, 2247);
  something_database(*(_DWORD *)v5144, v5143, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5336);
  v5145 = (int)std_string_append(&v5334, (int)&Dst, "whiteclay-wall-door.cub");
  v7813 = 2516;
  v5146 = this_4pointer_off((void *)v6, 2248);
  something_database(*(_DWORD *)v5146, v5145, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5334);
  v5147 = (int)std_string_append(&v5332, (int)&Dst, "whiteclay-wall-indoor.cub");
  v7813 = 2517;
  v5148 = this_4pointer_off((void *)v6, 2249);
  something_database(*(_DWORD *)v5148, v5147, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5332);
  v5149 = (int)std_string_append(&v5330, (int)&Dst, "whiteclay-wall-balcony.cub");
  v7813 = 2518;
  v5150 = this_4pointer_off((void *)v6, 2250);
  something_database(*(_DWORD *)v5150, v5149, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5330);
  v5151 = (int)std_string_append(&v5328, (int)&Dst, "whiteclay-wall-lamp.cub");
  v7813 = 2519;
  v5152 = this_4pointer_off((void *)v6, 2251);
  something_database(*(_DWORD *)v5152, v5151, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5328);
  v5153 = (int)std_string_append(&v5326, (int)&Dst, "whiteclay-roof1.cub");
  v7813 = 2520;
  v5154 = this_4pointer_off((void *)v6, 2252);
  something_database(*(_DWORD *)v5154, v5153, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5326);
  v5155 = (int)std_string_append(&v5324, (int)&Dst, "whiteclay-roof2.cub");
  v7813 = 2521;
  v5156 = this_4pointer_off((void *)v6, 2253);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v5155;
  something_database(*(_DWORD *)v5156, v5155, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5324);
  v5157 = (int)std_string_append(&v5322, (int)&Dst, "whiteclay-roof3.cub");
  v7813 = 2522;
  v5158 = this_4pointer_off((void *)v6, 2254);
  something_database(*(_DWORD *)v5158, v5157, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5322);
  v5159 = (int)std_string_append(&v5320, (int)&Dst, "whiteclay-arc.cub");
  v7813 = 2523;
  v5160 = this_4pointer_off((void *)v6, 2255);
  something_database(*(_DWORD *)v5160, v5159, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5320);
  v5161 = (int)std_string_append(&v5318, (int)&Dst, "antiqueruin-entrance-stairs.cub");
  v7813 = 2524;
  v5162 = this_4pointer_off((void *)v6, 2256);
  something_database(*(_DWORD *)v5162, v5161, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5318);
  v5163 = (int)std_string_append(&v5316, (int)&Dst, "antiqueruin-base.cub");
  v7813 = 2525;
  v5164 = this_4pointer_off((void *)v6, 2257);
  something_database(*(_DWORD *)v5164, v5163, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5316);
  v5165 = (int)std_string_append(&v5314, (int)&Dst, "antiqueruin-floor.cub");
  v7813 = 2526;
  v5166 = this_4pointer_off((void *)v6, 2258);
  something_database(*(_DWORD *)v5166, v5165, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5314);
  v5167 = (int)std_string_append(&v5312, (int)&Dst, "antiqueruin-floor-stairs.cub");
  v7813 = 2527;
  v5168 = this_4pointer_off((void *)v6, 2259);
  something_database(*(_DWORD *)v5168, v5167, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5312);
  v5169 = (int)std_string_append(&v5310, (int)&Dst, "antiqueruin-wall.cub");
  v7813 = 2528;
  v5170 = this_4pointer_off((void *)v6, 2260);
  something_database(*(_DWORD *)v5170, v5169, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5310);
  v5171 = (int)std_string_append(&v5308, (int)&Dst, "antiqueruin-roof1.cub");
  v7813 = 2529;
  v5172 = this_4pointer_off((void *)v6, 2261);
  something_database(*(_DWORD *)v5172, v5171, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5308);
  v5173 = (int)std_string_append(&v5306, (int)&Dst, "antiqueruin-roof2.cub");
  v7813 = 2530;
  v5174 = this_4pointer_off((void *)v6, 2262);
  something_database(*(_DWORD *)v5174, v5173, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5306);
  v5175 = (int)std_string_append(&v5304, (int)&Dst, "antiqueruin-roof3.cub");
  v7813 = 2531;
  v5176 = this_4pointer_off((void *)v6, 2263);
  something_database(*(_DWORD *)v5176, v5175, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5304);
  v5177 = (int)std_string_append(&v5302, (int)&Dst, "antiqueruin-arc.cub");
  v7813 = 2532;
  v5178 = this_4pointer_off((void *)v6, 2264);
  something_database(*(_DWORD *)v5178, v5177, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5302);
  v5179 = (int)std_string_append(&v5300, (int)&Dst, "jungleruin-entrance-stairs.cub");
  v7813 = 2533;
  v5180 = this_4pointer_off((void *)v6, 2265);
  something_database(*(_DWORD *)v5180, v5179, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5300);
  v5181 = (int)std_string_append(&v5298, (int)&Dst, "jungleruin-base.cub");
  v7813 = 2534;
  v5182 = this_4pointer_off((void *)v6, 2266);
  something_database(*(_DWORD *)v5182, v5181, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5298);
  v5183 = (int)std_string_append(&v5296, (int)&Dst, "jungleruin-floor.cub");
  v7813 = 2535;
  v5184 = this_4pointer_off((void *)v6, 2267);
  something_database(*(_DWORD *)v5184, v5183, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5296);
  v5185 = (int)std_string_append(&v5294, (int)&Dst, "jungleruin-floor-stairs.cub");
  v7813 = 2536;
  v5186 = this_4pointer_off((void *)v6, 2268);
  something_database(*(_DWORD *)v5186, v5185, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5294);
  v5187 = (int)std_string_append(&v5292, (int)&Dst, "jungleruin-wall.cub");
  v7813 = 2537;
  v5188 = this_4pointer_off((void *)v6, 2269);
  something_database(*(_DWORD *)v5188, v5187, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5292);
  v5189 = (int)std_string_append(&v5290, (int)&Dst, "jungleruin-wall-door.cub");
  v7813 = 2538;
  v5190 = this_4pointer_off((void *)v6, 2270);
  something_database(*(_DWORD *)v5190, v5189, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5290);
  v5191 = (int)std_string_append(&v5288, (int)&Dst, "jungleruin-wall-indoor.cub");
  v7813 = 2539;
  v5192 = this_4pointer_off((void *)v6, 2271);
  something_database(*(_DWORD *)v5192, v5191, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5288);
  v5193 = (int)std_string_append(&v5286, (int)&Dst, "jungleruin-roof1.cub");
  v7813 = 2540;
  v5194 = this_4pointer_off((void *)v6, 2272);
  something_database(*(_DWORD *)v5194, v5193, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5286);
  v5195 = (int)std_string_append(&v5284, (int)&Dst, "jungleruin-roof2.cub");
  v7813 = 2541;
  v5196 = this_4pointer_off((void *)v6, 2273);
  something_database(*(_DWORD *)v5196, v5195, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5284);
  v5197 = (int)std_string_append(&v5282, (int)&Dst, "jungleruin-roof3.cub");
  v7813 = 2542;
  v5198 = this_4pointer_off((void *)v6, 2274);
  something_database(*(_DWORD *)v5198, v5197, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5282);
  v5199 = (int)std_string_append(&v5280, (int)&Dst, "jungleruin-arc.cub");
  v7813 = 2543;
  v5200 = this_4pointer_off((void *)v6, 2275);
  something_database(*(_DWORD *)v5200, v5199, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5280);
  v5201 = (int)std_string_append(&v5278, (int)&Dst, "desertruin-entrance-stairs.cub");
  v7813 = 2544;
  v5202 = this_4pointer_off((void *)v6, 2276);
  something_database(*(_DWORD *)v5202, v5201, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5278);
  v5203 = (int)std_string_append(&v5276, (int)&Dst, "desertruin-base.cub");
  v7813 = 2545;
  v5204 = this_4pointer_off((void *)v6, 2277);
  something_database(*(_DWORD *)v5204, v5203, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5276);
  v5205 = (int)std_string_append(&v5274, (int)&Dst, "desertruin-floor.cub");
  v7813 = 2546;
  v5206 = this_4pointer_off((void *)v6, 2278);
  something_database(*(_DWORD *)v5206, v5205, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5274);
  v5207 = (int)std_string_append(&v5272, (int)&Dst, "desertruin-floor-stairs.cub");
  v7813 = 2547;
  v5208 = this_4pointer_off((void *)v6, 2279);
  something_database(*(_DWORD *)v5208, v5207, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5272);
  v5209 = (int)std_string_append(&v5270, (int)&Dst, "desertruin-wall.cub");
  v7813 = 2548;
  v5210 = this_4pointer_off((void *)v6, 2280);
  v7809 = 1;
  v7808 = v5247;
  *(_DWORD *)&Dst = v5209;
  something_database(*(_DWORD *)v5210, v5209, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5270);
  v5211 = (int)std_string_append(&v5268, (int)&Dst, "desertruin-wall-door.cub");
  v7813 = 2549;
  v5212 = this_4pointer_off((void *)v6, 2281);
  something_database(*(_DWORD *)v5212, v5211, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5268);
  v5213 = (int)std_string_append(&v5266, (int)&Dst, "desertruin-wall-indoor.cub");
  v7813 = 2550;
  v5214 = this_4pointer_off((void *)v6, 2282);
  something_database(*(_DWORD *)v5214, v5213, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5266);
  v5215 = (int)std_string_append(&v5264, (int)&Dst, "desertruin-roof1.cub");
  v7813 = 2551;
  v5216 = this_4pointer_off((void *)v6, 2283);
  something_database(*(_DWORD *)v5216, v5215, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5264);
  v5217 = (int)std_string_append(&v5262, (int)&Dst, "desertruin-roof2.cub");
  v7813 = 2552;
  v5218 = this_4pointer_off((void *)v6, 2284);
  something_database(*(_DWORD *)v5218, v5217, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5262);
  v5219 = (int)std_string_append(&v5260, (int)&Dst, "desertruin-roof3.cub");
  v7813 = 2553;
  v5220 = this_4pointer_off((void *)v6, 2285);
  something_database(*(_DWORD *)v5220, v5219, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5260);
  v5221 = (int)std_string_append(&v5258, (int)&Dst, "desertruin-arc.cub");
  v7813 = 2554;
  v5222 = this_4pointer_off((void *)v6, 2286);
  something_database(*(_DWORD *)v5222, v5221, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5258);
  v5223 = (int)std_string_append(&v5256, (int)&Dst, "airship.cub");
  v7813 = 2555;
  v5224 = this_4pointer_off((void *)v6, 2563);
  something_database(*(_DWORD *)v5224, v5223, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5256);
  v5225 = 0;
  v5246 = 0;
  v5226 = this_4pointer_off((void *)v6, 2563);
  if ( sub_1202120(*(_DWORD *)v5226) > 0 )
  {
    do
    {
      v5227 = 0;
      v5245 = 0;
      v5228 = this_4pointer_off((void *)v6, 2563);
      if ( sub_1202130(*(_DWORD *)v5228) > 0 )
      {
        do
        {
          v5229 = 0;
          v5230 = this_4pointer_off((void *)v6, 2563);
          if ( sub_1202140(*(_DWORD *)v5230) > 0 )
          {
            do
            {
              this_4pointer_off((void *)v6, 2563);
              v7809 = sub_1201040(-1, 0, 0);
              sub_1230BA0(v5246, v5245, v5229);
              if ( (unsigned __int8)sub_122F2E0(v7809) )
              {
                this_4pointer_off((void *)v6, 2563);
                v7809 = sub_1201040(0, 0, 0);
                sub_1230BA0(v5246, v5245, v5229);
                sub_1201020(v7809);
                v5244 = 0;
                this_4pointer_off((void *)v6, 2563);
                v7809 = set_ivec3_or_vec3(v5246, v5245, v5229);
                sub_1231490(&v5244);
                sub_125F4B0(v7809);
              }
              ++v5229;
              v5231 = this_4pointer_off((void *)v6, 2563);
            }
            while ( v5229 < sub_1202140(*(_DWORD *)v5231) );
            v5227 = v5245;
          }
          ++v5227;
          v5245 = v5227;
          v5232 = this_4pointer_off((void *)v6, 2563);
        }
        while ( v5227 < sub_1202130(*(_DWORD *)v5232) );
        v5225 = v5246;
      }
      ++v5225;
      v5246 = v5225;
      v5233 = this_4pointer_off((void *)v6, 2563);
    }
    while ( v5225 < sub_1202120(*(_DWORD *)v5233) );
  }
  v5234 = (int)std_string_append(&v5254, (int)&Dst, "sphinx01.cub");
  v7813 = 2556;
  v5235 = this_4pointer_off((void *)v6, 2564);
  something_database(*(_DWORD *)v5235, v5234, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5254);
  v5236 = (int)std_string_append(&v5252, (int)&Dst, "obelisk.cub");
  v7813 = 2557;
  v5237 = this_4pointer_off((void *)v6, 2565);
  something_database(*(_DWORD *)v5237, v5236, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5252);
  v5238 = (int)std_string_append(&v5250, (int)&Dst, "manacube.cub");
  v7813 = 2558;
  v5239 = this_4pointer_off((void *)v6, 2566);
  something_database(*(_DWORD *)v5239, v5238, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5250);
  v5240 = (int)std_string_append(&v5248, (int)&Dst, "maptile.cub");
  v7813 = 2559;
  v5241 = this_4pointer_off((void *)v6, 2567);
  something_database(*(_DWORD *)v5241, v5240, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5248);
  v5242 = (int)std_string_append(&v5887, (int)&Dst, "cloud02.cub");
  v7813 = 2560;
  v5243 = this_4pointer_off((void *)v6, 2568);
  something_database(*(_DWORD *)v5243, v5242, v5247, 1);
  v7813 = 1;
  delete_std_string((int)&v5887);
  if ( v5247 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5247)(v5247, 1);
  delete_std_string((int)&Dst);
}