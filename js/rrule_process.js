// import { RRule, RRuleSet, rrulestr} from 'rrule';

import pkg from 'rrule';
const { RRule, RRuleSet, rrulestr} = pkg;

const rule = new RRule({
    freq: RRule.WEEKLY,
    interval: 2,
    byweekday: [RRule.MO, RRule.WE, RRule.FR],
    dtstart: new Date(2022, 9, 2, 9, 0),
    until: new Date(2022, 9, 2, 9, 0)
})

console.log("rrule string:" + rule.toString());

console.log("rrule:" + rule.all());

console.log("rrule text:" + rule.toText());