import { RRule, RRuleSet, rrulestr} from 'rrule';

const rule = new RRule({
    freq: RRule.WEEKLY,
    interval: 2,
    byweekday: [RRule.MO, RRule.WE, RRule.FR],
    dtstart: new Date(2022, 9, 2, 9, 0),
    until: new Date(2022, 9, 2, 9, 0)
})

console.log(rule.toString());

console.log(rule.all());

console.log(rule.toText());