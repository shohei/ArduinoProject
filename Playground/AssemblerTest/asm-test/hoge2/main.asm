;-------------------------------------------------------;
; アセンブラ関数 sum
; 
; プロトタイプ: int16_t sum (int16_t a, int16_t b)
; 機能: a に b を足した値を戻す

.global sum			;シンボルsumを他のモジュールに公開
.func sum			;関数sum()の開始(.func/.endfuncは無くても可)
sum:				;シンボルsumの定義
	add	r24, r22	;a(r25:r24)にb(r23:r22)を足す
	adc	r25, r23	;/
	ret			;戻り値をr25:r24に入れて戻る
.endfunc


;-------------------------------------------------------;
; アセンブラ関数 タイマ0 オーバーフロー割り込み
; (シンボル名はデバイスにより異なるので注意)
;
; プロトタイプ: なし
; 機能: 100カウント毎に割り込み発生

.global TIMER0_OVF_vect
.func TIMER0_OVF_vect
TIMER0_OVF_vect:
	push	r0			;フラグと使用するレジスタを待避
	in	r0, _SFR_IO_ADDR(SREG);
	push	r24			;/

	ldi	r24, -100		;次の割り込みは100カウント後
	out	_SFR_IO_ADDR(TCNT0), r24;/

	pop	r24			;フラグと使用したレジスタ類を復帰
    out	_SFR_IO_ADDR(SREG), r0
	pop	r0			;/
	reti
.endfunc
