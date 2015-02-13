.include "tn2313def.inc"
;リセット・ベクタの設定  全割り込みを列記するが使用しないものはresetラベルへ
.cseg
    rjmp reset                ;各種ﾘｾｯﾄ  下の reset: ラベルへジャンプする
    rjmp reset                ;ext_int0  ;外部割り込み要求0
    rjmp reset                ;ext_int1  ;外部割り込み要求1
    rjmp reset                ;tim1_capt  ;ﾀｲﾏ/ｶｳﾝﾀ1捕獲(ｷｬﾌﾟﾁｬ)発生
    rjmp reset                ;tim1_compa  ;ﾀｲﾏ/ｶｳﾝﾀ1比較A一致
    rjmp reset                ;tim1_ovf  ;ﾀｲﾏ/ｶｳﾝﾀ1ｵｰﾊﾞｰﾌﾛｰ
    rjmp reset                ;tim0_ovf  ;ﾀｲﾏ/ｶｳﾝﾀ0ｵｰﾊﾞｰﾌﾛｰ
    rjmp reset                ;usart_rxc  ;USART受信完了
    rjmp reset                ;usart_udre  ;USART送信ﾊﾞｯﾌｧ空き
    rjmp reset                ;usart_tx  ;USART送信完了
    rjmp reset                ;ana_comp  ;ｱﾅﾛｸﾞ比較器出力遷移
    rjmp reset                ;pcint  ;ﾋﾟﾝ変化割り込み要求
    rjmp reset                ;tim1_compb  ;ﾀｲﾏ/ｶｳﾝﾀ1比較B一致
    rjmp reset                ;tim0_compa  ;ﾀｲﾏ/ｶｳﾝﾀ0比較A一致
    rjmp reset                ;tim0_compb  ;ﾀｲﾏ/ｶｳﾝﾀ0比較B一致
    rjmp reset                ;usi_strt  ;USI開始条件検出
    rjmp reset                ;usi_ovf  ;USIｶｳﾝﾀｵｰﾊﾞｰﾌﾛｰ
    rjmp reset                ;ee_rdy  ;EEPROM操作可
    rjmp reset                ;wdt_ovf  ;ｳｫｯﾁﾄﾞｯｸﾞ計時完了

;プログラム本体
.org $100                     ;100番地から次のﾌﾟﾛｸﾞﾗﾑが始まる（今は意味がない）
reset:
    ldi  r16,low(ramend)      ;RAM最終ｱﾄﾞﾚｽ下位を取得
    out  spl,r16              ;ｽﾀｯｸﾎﾟｲﾝﾀ(下位)を初期化
    ;以下、I/O初期化など
    ; PORTBの設定
    ldi  r16, 0b11111111      ;LEDポートのみ出力ポートに設定 sed r16 も同じ
    out  DDRB, r16            ;DDRBに直接書けない
    ldi  r16, 0               ;clr  r16 も同じ
    out  DDRD, r16            ;PORTDの全ビット入力設定
    ldi  r16, 0b0000_0100     ;
    out  PORTD, r16           ;PD2ﾌﾟﾙｱｯﾌﾟ  入力のPORTxに１を書くとﾌﾟﾙｱｯﾌﾟ

main:
    ldi  r16, 0b1111_1011     ;
    out  PORTB, r16           ;PB2以外は点灯
    clr  r3                   ;フラッグ初期化
    
loop:
    ldi  r16, 1               ;チャタリング防止の10msルーチン
    rcall delay10ms           ;

    ;スイッチの判定
    lsl  r3                   ;logical shift left
    sbic PIND, 2              ;押されていたらスキップ skip bit I/O clear?
    inc  r3                   ;押されたらINCされない
    sbrs r3, 1                ;r3が0bxxxx_xx10のときswが押されたと判断 skip bit register set?
    rjmp conti                ;bit1が1でなければcontiへ跳ぶ
    sbrc r3, 0                ;bit0が0でなければcontiへ跳ぶ
    rjmp conti                ;
    inc  r4                   ;r4のbit0が反転するのでトグルになる

conti:    
    sbrc r4, 0                ;r4=0ならスキップ
    rjmp led7654on_off        ;
    rjmp led7654on            ;

led7654on:                    ;連続点灯
    ldi  r16, 0xff            ;
    out  PORTB, r16           ;
    clr  r4                   ;
    rjmp loop                 ;
led7654on_off:                ;上位４ビット交互点滅 0b0101_1111と0b1010_1111
    ldi  r16, 0x5f            ;
    out  PORTB, r16           ;
    ldi  r16, 10              ;100msウエイト
    rcall delay10ms           ;
    ldi  r16, 0xaf            ;
    out  PORTB, r16           ;
    ldi  r16, 10              ;100msウエイト
    rcall delay10ms           ;
    clr  r4                   ;r4はイミディエイトを扱えないので
    inc  r4                   ;clrとincでbit1をHにしている
    rjmp loop                 ;


delay10ms:                    ;10ミリ秒待ちサブルーチン
    mov  r2,  r16             ;r16から引数を得る  r16=1の時10ms
dly2:
    ldi  r16, 100
    mov  r1,  r16
dly1:
    ldi  r16, 200
    mov  r0,  r16
dly0:
    nop                       ;1クロック
    dec  r0                   ;1クロック
    brne dly0                 ;2クロック  合計４クロック
    dec  r1                   ;
    brne dly1                 ;
    dec  r2                   ;
    brne dly2                 ;
    ret                       ;サブルーチンの終了＝呼び出しルーチンへ復帰
