<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3a" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="NEXT_STATE(2:0)" />
        <signal name="NEXT_STATE(2)" />
        <signal name="NEXT_STATE(1)" />
        <signal name="CUR_STATE(2:0)" />
        <signal name="CUR_STATE(2)" />
        <signal name="CUR_STATE(1)" />
        <signal name="MODE" />
        <signal name="OUT_BUS(7:0)" />
        <signal name="CLK" />
        <signal name="NEXT_STATE(0)" />
        <signal name="CUR_STATE(0)" />
        <signal name="OUT_BUS(7)" />
        <signal name="OUT_BUS(6)" />
        <signal name="OUT_BUS(5)" />
        <signal name="OUT_BUS(4)" />
        <signal name="OUT_BUS(0)" />
        <signal name="OUT_BUS(1)" />
        <signal name="OUT_BUS(2)" />
        <signal name="OUT_BUS(3)" />
        <signal name="RST" />
        <signal name="TEST" />
        <port polarity="Input" name="MODE" />
        <port polarity="Input" name="CLK" />
        <port polarity="Output" name="OUT_BUS(7)" />
        <port polarity="Output" name="OUT_BUS(6)" />
        <port polarity="Output" name="OUT_BUS(5)" />
        <port polarity="Output" name="OUT_BUS(4)" />
        <port polarity="Output" name="OUT_BUS(0)" />
        <port polarity="Output" name="OUT_BUS(1)" />
        <port polarity="Output" name="OUT_BUS(2)" />
        <port polarity="Output" name="OUT_BUS(3)" />
        <port polarity="Input" name="RST" />
        <port polarity="Input" name="TEST" />
        <blockdef name="transition_logic_intf">
            <timestamp>2023-5-1T14:49:35</timestamp>
            <line x2="0" y1="32" y2="32" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="448" y="-108" height="24" />
            <line x2="512" y1="-96" y2="-96" x1="448" />
            <rect width="384" x="64" y="-128" height="192" />
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
        <blockdef name="out_logic_intf">
            <timestamp>2023-5-1T14:59:21</timestamp>
            <line x2="0" y1="32" y2="32" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="368" y="-44" height="24" />
            <line x2="432" y1="-32" y2="-32" x1="368" />
            <rect width="304" x="64" y="-64" height="128" />
        </blockdef>
        <block symbolname="fd" name="XLXI_17">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="NEXT_STATE(0)" name="D" />
            <blockpin signalname="CUR_STATE(0)" name="Q" />
        </block>
        <block symbolname="fd" name="XLXI_18">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="NEXT_STATE(1)" name="D" />
            <blockpin signalname="CUR_STATE(1)" name="Q" />
        </block>
        <block symbolname="fd" name="XLXI_19">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="NEXT_STATE(2)" name="D" />
            <blockpin signalname="CUR_STATE(2)" name="Q" />
        </block>
        <block symbolname="transition_logic_intf" name="XLXI_20">
            <blockpin signalname="MODE" name="MODE" />
            <blockpin signalname="CUR_STATE(2:0)" name="CUR_STATE(2:0)" />
            <blockpin signalname="NEXT_STATE(2:0)" name="NEXT_STATE(2:0)" />
            <blockpin signalname="RST" name="RST" />
        </block>
        <block symbolname="out_logic_intf" name="XLXI_21">
            <blockpin signalname="TEST" name="TEST" />
            <blockpin signalname="CUR_STATE(2:0)" name="IN_BUS(2:0)" />
            <blockpin signalname="OUT_BUS(7:0)" name="OUT_BUS(7:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="NEXT_STATE(2:0)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="976" y="1472" type="branch" />
            <wire x2="976" y1="1120" y2="1120" x1="848" />
            <wire x2="976" y1="1120" y2="1184" x1="976" />
            <wire x2="976" y1="1184" y2="1472" x1="976" />
            <wire x2="976" y1="1472" y2="1504" x1="976" />
            <wire x2="976" y1="1504" y2="1664" x1="976" />
            <wire x2="976" y1="1664" y2="2128" x1="976" />
            <wire x2="976" y1="2128" y2="2224" x1="976" />
        </branch>
        <bustap x2="1072" y1="1664" y2="1664" x1="976" />
        <bustap x2="1072" y1="1184" y2="1184" x1="976" />
        <branch name="NEXT_STATE(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1120" y="1184" type="branch" />
            <wire x2="1120" y1="1184" y2="1184" x1="1072" />
            <wire x2="1232" y1="1184" y2="1184" x1="1120" />
        </branch>
        <branch name="NEXT_STATE(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1088" y="1664" type="branch" />
            <wire x2="1088" y1="1664" y2="1664" x1="1072" />
            <wire x2="1232" y1="1664" y2="1664" x1="1088" />
        </branch>
        <branch name="CUR_STATE(2:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="976" y="2592" type="branch" />
            <wire x2="336" y1="1184" y2="1184" x1="288" />
            <wire x2="288" y1="1184" y2="2592" x1="288" />
            <wire x2="976" y1="2592" y2="2592" x1="288" />
            <wire x2="1936" y1="2592" y2="2592" x1="976" />
            <wire x2="1936" y1="1088" y2="1184" x1="1936" />
            <wire x2="1936" y1="1184" y2="1424" x1="1936" />
            <wire x2="1936" y1="1424" y2="1664" x1="1936" />
            <wire x2="1936" y1="1664" y2="2128" x1="1936" />
            <wire x2="1936" y1="2128" y2="2592" x1="1936" />
            <wire x2="2160" y1="1424" y2="1424" x1="1936" />
        </branch>
        <bustap x2="1840" y1="1184" y2="1184" x1="1936" />
        <bustap x2="1840" y1="1664" y2="1664" x1="1936" />
        <branch name="CUR_STATE(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1744" y="1184" type="branch" />
            <wire x2="1744" y1="1184" y2="1184" x1="1616" />
            <wire x2="1840" y1="1184" y2="1184" x1="1744" />
        </branch>
        <branch name="CUR_STATE(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1760" y="1664" type="branch" />
            <wire x2="1760" y1="1664" y2="1664" x1="1616" />
            <wire x2="1840" y1="1664" y2="1664" x1="1760" />
        </branch>
        <branch name="MODE">
            <wire x2="336" y1="1120" y2="1120" x1="304" />
        </branch>
        <branch name="OUT_BUS(7:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2672" y="1424" type="branch" />
            <wire x2="2672" y1="1424" y2="1424" x1="2592" />
            <wire x2="2784" y1="1424" y2="1424" x1="2672" />
            <wire x2="2784" y1="1424" y2="1520" x1="2784" />
            <wire x2="2784" y1="1520" y2="1616" x1="2784" />
            <wire x2="2784" y1="1616" y2="1712" x1="2784" />
            <wire x2="2784" y1="1712" y2="1808" x1="2784" />
            <wire x2="2784" y1="1808" y2="1920" x1="2784" />
            <wire x2="2784" y1="1920" y2="2032" x1="2784" />
            <wire x2="2784" y1="2032" y2="2144" x1="2784" />
            <wire x2="2784" y1="2144" y2="2256" x1="2784" />
            <wire x2="2784" y1="2256" y2="2496" x1="2784" />
        </branch>
        <bustap x2="2880" y1="1520" y2="1520" x1="2784" />
        <bustap x2="2880" y1="1616" y2="1616" x1="2784" />
        <bustap x2="2880" y1="1712" y2="1712" x1="2784" />
        <bustap x2="2880" y1="1808" y2="1808" x1="2784" />
        <iomarker fontsize="28" x="304" y="1120" name="MODE" orien="R180" />
        <iomarker fontsize="28" x="736" y="2304" name="CLK" orien="R180" />
        <branch name="CLK">
            <wire x2="1088" y1="2304" y2="2304" x1="736" />
            <wire x2="1088" y1="1312" y2="1792" x1="1088" />
            <wire x2="1232" y1="1792" y2="1792" x1="1088" />
            <wire x2="1088" y1="1792" y2="2256" x1="1088" />
            <wire x2="1088" y1="2256" y2="2304" x1="1088" />
            <wire x2="1232" y1="2256" y2="2256" x1="1088" />
            <wire x2="1232" y1="1312" y2="1312" x1="1088" />
        </branch>
        <branch name="NEXT_STATE(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1120" y="2128" type="branch" />
            <wire x2="1120" y1="2128" y2="2128" x1="1072" />
            <wire x2="1232" y1="2128" y2="2128" x1="1120" />
        </branch>
        <bustap x2="1072" y1="2128" y2="2128" x1="976" />
        <bustap x2="1840" y1="2128" y2="2128" x1="1936" />
        <branch name="CUR_STATE(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1744" y="2128" type="branch" />
            <wire x2="1744" y1="2128" y2="2128" x1="1616" />
            <wire x2="1840" y1="2128" y2="2128" x1="1744" />
        </branch>
        <bustap x2="2880" y1="1920" y2="1920" x1="2784" />
        <bustap x2="2880" y1="2032" y2="2032" x1="2784" />
        <bustap x2="2880" y1="2144" y2="2144" x1="2784" />
        <bustap x2="2880" y1="2256" y2="2256" x1="2784" />
        <branch name="OUT_BUS(7)">
            <wire x2="3200" y1="1520" y2="1520" x1="2880" />
        </branch>
        <branch name="OUT_BUS(6)">
            <wire x2="3200" y1="1616" y2="1616" x1="2880" />
        </branch>
        <branch name="OUT_BUS(5)">
            <wire x2="3200" y1="1712" y2="1712" x1="2880" />
        </branch>
        <branch name="OUT_BUS(4)">
            <wire x2="3200" y1="1808" y2="1808" x1="2880" />
        </branch>
        <branch name="OUT_BUS(0)">
            <wire x2="3200" y1="2256" y2="2256" x1="2880" />
        </branch>
        <branch name="OUT_BUS(1)">
            <wire x2="3200" y1="2144" y2="2144" x1="2880" />
        </branch>
        <branch name="OUT_BUS(2)">
            <wire x2="3200" y1="2032" y2="2032" x1="2880" />
        </branch>
        <branch name="OUT_BUS(3)">
            <wire x2="2928" y1="1920" y2="1920" x1="2880" />
            <wire x2="3024" y1="1920" y2="1920" x1="2928" />
            <wire x2="3200" y1="1920" y2="1920" x1="3024" />
        </branch>
        <iomarker fontsize="28" x="3200" y="2256" name="OUT_BUS(0)" orien="R0" />
        <iomarker fontsize="28" x="3200" y="2144" name="OUT_BUS(1)" orien="R0" />
        <iomarker fontsize="28" x="3200" y="2032" name="OUT_BUS(2)" orien="R0" />
        <iomarker fontsize="28" x="3200" y="1920" name="OUT_BUS(3)" orien="R0" />
        <iomarker fontsize="28" x="3200" y="1808" name="OUT_BUS(4)" orien="R0" />
        <iomarker fontsize="28" x="3200" y="1712" name="OUT_BUS(5)" orien="R0" />
        <iomarker fontsize="28" x="3200" y="1616" name="OUT_BUS(6)" orien="R0" />
        <iomarker fontsize="28" x="3200" y="1520" name="OUT_BUS(7)" orien="R0" />
        <instance x="1232" y="2384" name="XLXI_17" orien="R0" />
        <instance x="1232" y="1920" name="XLXI_18" orien="R0" />
        <instance x="1232" y="1440" name="XLXI_19" orien="R0" />
        <branch name="RST">
            <wire x2="336" y1="1248" y2="1248" x1="256" />
        </branch>
        <iomarker fontsize="28" x="256" y="1248" name="RST" orien="R180" />
        <instance x="336" y="1216" name="XLXI_20" orien="R0">
        </instance>
        <instance x="2160" y="1456" name="XLXI_21" orien="R0">
        </instance>
        <branch name="TEST">
            <wire x2="2160" y1="1488" y2="1488" x1="2128" />
        </branch>
        <iomarker fontsize="28" x="2128" y="1488" name="TEST" orien="R180" />
    </sheet>
</drawing>