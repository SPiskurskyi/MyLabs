<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3a" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="CLOCK" />
        <signal name="XLXN_5" />
        <signal name="CNT_BUS(15:0)" />
        <signal name="CNT_BUS(5)" />
        <signal name="XLXN_12" />
        <signal name="MODE" />
        <signal name="CNT_BUS(4)" />
        <signal name="SPEED" />
        <signal name="OUT_BUS(7:0)" />
        <signal name="OUT_BUS(0)" />
        <signal name="OUT_BUS(1)" />
        <signal name="OUT_BUS(2)" />
        <signal name="OUT_BUS(3)" />
        <signal name="OUT_BUS(4)" />
        <signal name="OUT_BUS(5)" />
        <signal name="OUT_BUS(6)" />
        <signal name="OUT_BUS(7)" />
        <signal name="XLXN_23" />
        <signal name="XLXN_24" />
        <signal name="RST" />
        <signal name="TEST" />
        <port polarity="Input" name="CLOCK" />
        <port polarity="Input" name="MODE" />
        <port polarity="Input" name="SPEED" />
        <port polarity="Output" name="OUT_BUS(0)" />
        <port polarity="Output" name="OUT_BUS(1)" />
        <port polarity="Output" name="OUT_BUS(2)" />
        <port polarity="Output" name="OUT_BUS(3)" />
        <port polarity="Output" name="OUT_BUS(4)" />
        <port polarity="Output" name="OUT_BUS(5)" />
        <port polarity="Output" name="OUT_BUS(6)" />
        <port polarity="Output" name="OUT_BUS(7)" />
        <port polarity="Input" name="RST" />
        <port polarity="Input" name="TEST" />
        <blockdef name="cc16re">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="256" x="64" y="-320" height="256" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-32" y2="-32" x1="192" />
            <line x2="192" y1="-64" y2="-32" x1="192" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <rect width="64" x="320" y="-268" height="24" />
            <line x2="320" y1="-192" y2="-192" x1="384" />
            <line x2="320" y1="-128" y2="-128" x1="384" />
        </blockdef>
        <blockdef name="constant">
            <timestamp>2006-1-1T10:10:10</timestamp>
            <rect width="112" x="0" y="0" height="64" />
            <line x2="112" y1="32" y2="32" x1="144" />
        </blockdef>
        <blockdef name="LightController">
            <timestamp>2023-5-1T15:0:5</timestamp>
            <line x2="0" y1="32" y2="32" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-172" height="24" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <rect width="256" x="64" y="-192" height="256" />
        </blockdef>
        <blockdef name="muxcy">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="192" y1="0" y2="-64" x1="192" />
            <line x2="192" y1="-224" y2="-160" x1="192" />
            <line x2="32" y1="-160" y2="-64" x1="96" />
            <line x2="96" y1="-160" y2="-160" x1="224" />
            <line x2="224" y1="-64" y2="-160" x1="288" />
            <line x2="288" y1="-64" y2="-64" x1="32" />
            <line x2="128" y1="0" y2="-64" x1="128" />
            <line x2="56" y1="-96" y2="-96" x1="0" />
        </blockdef>
        <blockdef name="fd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="256" x="64" y="-320" height="256" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
        </blockdef>
        <block symbolname="cc16re" name="XLXI_2">
            <blockpin signalname="CLOCK" name="C" />
            <blockpin signalname="XLXN_12" name="CE" />
            <blockpin signalname="XLXN_5" name="R" />
            <blockpin name="CEO" />
            <blockpin name="Q(15:0)" />
            <blockpin signalname="XLXN_1" name="TC" />
        </block>
        <block symbolname="cc16re" name="XLXI_3">
            <blockpin signalname="XLXN_1" name="C" />
            <blockpin signalname="XLXN_12" name="CE" />
            <blockpin signalname="XLXN_5" name="R" />
            <blockpin name="CEO" />
            <blockpin signalname="CNT_BUS(15:0)" name="Q(15:0)" />
            <blockpin name="TC" />
        </block>
        <block symbolname="constant" name="XLXI_6">
            <attr value="1" name="CValue">
                <trait delete="all:1 sym:0" />
                <trait editname="all:1 sch:0" />
                <trait valuetype="BitVector 32 Hexadecimal" />
            </attr>
            <blockpin signalname="XLXN_12" name="O" />
        </block>
        <block symbolname="constant" name="XLXI_7">
            <attr value="0" name="CValue">
                <trait delete="all:1 sym:0" />
                <trait editname="all:1 sch:0" />
                <trait valuetype="BitVector 32 Hexadecimal" />
            </attr>
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="muxcy" name="XLXI_10">
            <blockpin signalname="CNT_BUS(4)" name="CI" />
            <blockpin signalname="CNT_BUS(5)" name="DI" />
            <blockpin signalname="SPEED" name="S" />
            <blockpin signalname="XLXN_23" name="O" />
        </block>
        <block symbolname="fd" name="XLXI_12">
            <blockpin signalname="XLXN_23" name="C" />
            <blockpin signalname="RST" name="D" />
            <blockpin signalname="XLXN_24" name="Q" />
        </block>
        <block symbolname="LightController" name="XLXI_13">
            <blockpin signalname="MODE" name="MODE" />
            <blockpin signalname="XLXN_23" name="CLK" />
            <blockpin signalname="XLXN_24" name="RST" />
            <blockpin signalname="OUT_BUS(7:0)" name="OUT_BUS(7:0)" />
            <blockpin signalname="TEST" name="TEST" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="736" y="1424" name="XLXI_2" orien="R0" />
        <instance x="1200" y="1424" name="XLXI_3" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="1200" y1="1296" y2="1296" x1="1120" />
        </branch>
        <branch name="CLOCK">
            <wire x2="736" y1="1296" y2="1296" x1="592" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="688" y1="1488" y2="1488" x1="592" />
            <wire x2="1200" y1="1488" y2="1488" x1="688" />
            <wire x2="736" y1="1392" y2="1392" x1="688" />
            <wire x2="688" y1="1392" y2="1488" x1="688" />
            <wire x2="1200" y1="1392" y2="1488" x1="1200" />
        </branch>
        <branch name="CNT_BUS(15:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1696" y="1168" type="branch" />
            <wire x2="1696" y1="1168" y2="1168" x1="1584" />
            <wire x2="1696" y1="1168" y2="1200" x1="1696" />
            <wire x2="1696" y1="1200" y2="1264" x1="1696" />
            <wire x2="1696" y1="1264" y2="1440" x1="1696" />
        </branch>
        <bustap x2="1792" y1="1200" y2="1200" x1="1696" />
        <branch name="CNT_BUS(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1936" y="1200" type="branch" />
            <wire x2="1936" y1="1200" y2="1200" x1="1792" />
            <wire x2="2000" y1="1200" y2="1200" x1="1936" />
        </branch>
        <instance x="448" y="1456" name="XLXI_7" orien="R0">
        </instance>
        <instance x="448" y="1200" name="XLXI_6" orien="R0">
        </instance>
        <branch name="XLXN_12">
            <wire x2="656" y1="1232" y2="1232" x1="592" />
            <wire x2="736" y1="1232" y2="1232" x1="656" />
            <wire x2="656" y1="1040" y2="1232" x1="656" />
            <wire x2="1184" y1="1040" y2="1040" x1="656" />
            <wire x2="1184" y1="1040" y2="1232" x1="1184" />
            <wire x2="1200" y1="1232" y2="1232" x1="1184" />
        </branch>
        <iomarker fontsize="28" x="592" y="1296" name="CLOCK" orien="R180" />
        <branch name="MODE">
            <wire x2="2336" y1="1056" y2="1056" x1="2272" />
        </branch>
        <iomarker fontsize="28" x="2272" y="1056" name="MODE" orien="R180" />
        <bustap x2="1792" y1="1264" y2="1264" x1="1696" />
        <instance x="2000" y="1072" name="XLXI_10" orien="R90" />
        <branch name="CNT_BUS(4)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="1901" y="1264" type="branch" />
            <wire x2="1904" y1="1264" y2="1264" x1="1792" />
            <wire x2="2000" y1="1264" y2="1264" x1="1904" />
        </branch>
        <branch name="SPEED">
            <wire x2="2096" y1="1056" y2="1072" x1="2096" />
        </branch>
        <branch name="OUT_BUS(7:0)">
            <wire x2="2832" y1="1056" y2="1056" x1="2720" />
            <wire x2="2928" y1="1056" y2="1056" x1="2832" />
            <wire x2="2928" y1="1056" y2="1312" x1="2928" />
            <wire x2="2928" y1="1312" y2="1376" x1="2928" />
            <wire x2="2928" y1="1376" y2="1440" x1="2928" />
            <wire x2="2928" y1="1440" y2="1504" x1="2928" />
            <wire x2="2928" y1="1504" y2="1600" x1="2928" />
            <wire x2="2928" y1="1600" y2="1664" x1="2928" />
            <wire x2="2928" y1="1664" y2="1728" x1="2928" />
            <wire x2="2928" y1="1728" y2="1792" x1="2928" />
            <wire x2="2928" y1="1792" y2="1936" x1="2928" />
        </branch>
        <bustap x2="3024" y1="1792" y2="1792" x1="2928" />
        <bustap x2="3024" y1="1728" y2="1728" x1="2928" />
        <bustap x2="3024" y1="1664" y2="1664" x1="2928" />
        <bustap x2="3024" y1="1600" y2="1600" x1="2928" />
        <bustap x2="3024" y1="1504" y2="1504" x1="2928" />
        <bustap x2="3024" y1="1440" y2="1440" x1="2928" />
        <bustap x2="3024" y1="1376" y2="1376" x1="2928" />
        <bustap x2="3024" y1="1312" y2="1312" x1="2928" />
        <branch name="OUT_BUS(0)">
            <wire x2="3072" y1="1792" y2="1792" x1="3024" />
        </branch>
        <branch name="OUT_BUS(1)">
            <wire x2="3072" y1="1728" y2="1728" x1="3024" />
        </branch>
        <branch name="OUT_BUS(2)">
            <wire x2="3072" y1="1664" y2="1664" x1="3024" />
        </branch>
        <branch name="OUT_BUS(3)">
            <wire x2="3072" y1="1600" y2="1600" x1="3024" />
        </branch>
        <branch name="OUT_BUS(4)">
            <wire x2="3072" y1="1504" y2="1504" x1="3024" />
        </branch>
        <branch name="OUT_BUS(5)">
            <wire x2="3040" y1="1440" y2="1440" x1="3024" />
            <wire x2="3072" y1="1440" y2="1440" x1="3040" />
        </branch>
        <branch name="OUT_BUS(6)">
            <wire x2="3072" y1="1376" y2="1376" x1="3024" />
        </branch>
        <branch name="OUT_BUS(7)">
            <wire x2="3072" y1="1312" y2="1312" x1="3024" />
        </branch>
        <iomarker fontsize="28" x="3072" y="1312" name="OUT_BUS(7)" orien="R0" />
        <iomarker fontsize="28" x="3072" y="1376" name="OUT_BUS(6)" orien="R0" />
        <iomarker fontsize="28" x="3072" y="1504" name="OUT_BUS(4)" orien="R0" />
        <iomarker fontsize="28" x="3072" y="1600" name="OUT_BUS(3)" orien="R0" />
        <iomarker fontsize="28" x="3072" y="1664" name="OUT_BUS(2)" orien="R0" />
        <iomarker fontsize="28" x="3072" y="1728" name="OUT_BUS(1)" orien="R0" />
        <iomarker fontsize="28" x="3072" y="1792" name="OUT_BUS(0)" orien="R0" />
        <iomarker fontsize="28" x="3072" y="1440" name="OUT_BUS(5)" orien="R0" />
        <iomarker fontsize="28" x="2096" y="1056" name="SPEED" orien="R270" />
        <instance x="1712" y="1008" name="XLXI_12" orien="R0" />
        <branch name="XLXN_23">
            <wire x2="1712" y1="880" y2="880" x1="1616" />
            <wire x2="1616" y1="880" y2="1424" x1="1616" />
            <wire x2="2240" y1="1424" y2="1424" x1="1616" />
            <wire x2="2272" y1="1264" y2="1264" x1="2224" />
            <wire x2="2240" y1="1184" y2="1424" x1="2240" />
            <wire x2="2272" y1="1184" y2="1184" x1="2240" />
            <wire x2="2272" y1="1184" y2="1264" x1="2272" />
            <wire x2="2336" y1="1184" y2="1184" x1="2272" />
        </branch>
        <branch name="XLXN_24">
            <wire x2="2288" y1="752" y2="752" x1="2096" />
            <wire x2="2288" y1="752" y2="1120" x1="2288" />
            <wire x2="2336" y1="1120" y2="1120" x1="2288" />
        </branch>
        <branch name="RST">
            <wire x2="1712" y1="752" y2="752" x1="1680" />
        </branch>
        <iomarker fontsize="28" x="1680" y="752" name="RST" orien="R180" />
        <instance x="2336" y="1216" name="XLXI_13" orien="R0">
        </instance>
        <branch name="TEST">
            <wire x2="2336" y1="1248" y2="1248" x1="2320" />
            <wire x2="2320" y1="1248" y2="1328" x1="2320" />
            <wire x2="2336" y1="1328" y2="1328" x1="2320" />
        </branch>
        <iomarker fontsize="28" x="2336" y="1328" name="TEST" orien="R0" />
    </sheet>
</drawing>